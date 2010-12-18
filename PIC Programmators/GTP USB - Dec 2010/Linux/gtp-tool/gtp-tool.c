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
    }

    libusb_close (handle);
    libusb_exit (ctx);
    return 0;
}
