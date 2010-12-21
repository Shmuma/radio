#include <stdio.h>
#include <stdlib.h>

#include <libusb.h>

struct libusb_context* ctx;

#define GTP_VENDOR  0x04D8
#define GTP_PRODUCT 0x5200


const char* gtp_get_version (struct libusb_device_handle* handle)
{
    unsigned char data[] = {
        0x3e, 0x30, 0, 0, 8, 3, 3, 0,
    };
    static unsigned char buf[256];

    int r, gone;

    r = libusb_interrupt_transfer (handle, 1 | LIBUSB_ENDPOINT_OUT, data, sizeof (data), &gone, 1000);
    if (r < 0) {
        printf ("Send error %d\n", r);
        return NULL;
    }
//    printf ("%d bytes sent\n", gone);

    r = libusb_interrupt_transfer (handle, 1 | LIBUSB_ENDPOINT_IN, buf, sizeof (buf), &gone, 1000);
    if (r < 0) {
        printf ("Receive error %d\n", r);
        return NULL;
    }
//    printf ("%d bytes got\n", gone);
    buf[gone] = 0;
    return buf+2;
}


void gtp_read_chip (struct libusb_device_handle* handle)
{
    unsigned char read_cmd[] = {
        0x3e, 0x31, 0xff, 0x03, 0x00, 0x00, 0x04, 0x00,
    };

    static unsigned char buf[512*1024];

    int r, gone;
    FILE* f = fopen ("data.dat", "w+");

    r = libusb_interrupt_transfer (handle, 1 | LIBUSB_ENDPOINT_OUT, read_cmd, sizeof (read_cmd), &gone, 1000);
    if (r < 0) {
        printf ("Send error %d\n", r);
        return;
    }
    printf ("%d bytes sent\n", gone);

    while (1) {
	gone = 0;    
        r = libusb_interrupt_transfer (handle, 1 | LIBUSB_ENDPOINT_IN, buf, sizeof (buf), &gone, 1000);
        printf ("%d bytes got\n", gone);
	if (gone > 0)
	    fwrite (buf, 1, gone, f);
        if (r < 0) {
            printf ("Receive error %d\n", r);
            break;;
        }
    }
    fclose (f);
}


int main (int argc, char *argv[])
{
    int err;
    struct libusb_device_handle* handle;

    if ((err = libusb_init (&ctx)) != 0) {
        printf ("libusb_init failed with code %d\n", err);
        return 1;
    }

    libusb_set_debug (ctx, 3);

    handle = libusb_open_device_with_vid_pid (ctx, GTP_VENDOR, GTP_PRODUCT);

    if (!handle)
        printf ("GTP-USB device not found\n");
    else {
        libusb_claim_interface (handle, 0);
        printf ("GTP-USB device found, version = %s\n", gtp_get_version (handle));

        /* try to read chip contents */
        gtp_read_chip (handle);
    }

    libusb_close (handle);
    libusb_exit (ctx);
    return 0;
}
