#include <stdio.h>
#include <stdlib.h>

#include <libusb.h>

struct libusb_context* ctx;

#define GTP_VENDOR  0x04D8
#define GTP_PRODUCT 0x5200


/* Commands table */
/* 16F84A:  0x60, 0x05, 0x65 */
/* 18F2550: 0xff, 0x3f, 0xc0 */
/* 18F452:  0xff, 0x3f, 0xc0 */
unsigned char gtp_cmd_detect_pic[] = {
    0x3e, 0x34, 0x00, 0x00, 0x08, 0x00, 0x03, 0x00,
};


/* ALL:  0xff, 0x3f, 0xc0 */
unsigned char gtp_cmd_detect_pic_1[] = {
    0x3e, 0x34, 0x00, 0x00, 0x08, 0x01, 0x03, 0x00,
};


/* ALL: 0xff, 0xff, 0x00 */
unsigned char gtp_cmd_detect_pic2[] = {
    0x3e, 0x35, 0x00, 0x00, 0x08, 0x00, 0x03, 0x00,
};

/* 16F84A:  0xff, 0xff, 0x00 */
/* 18F2550: 0x47, 0x12, 0x55 */
/* 18F452:  0x27, 0x04, 0x23 */
unsigned char gtp_cmd_detect_pic2_1[] = {
    0x3e, 0x35, 0x00, 0x00, 0x08, 0x01, 0x03, 0x00,
};


/* ALL: 0xff, 0xff, 0x00 */
unsigned char gtp_cmd_detect_pic3[] = {
    0x3e, 0x43, 0x00, 0x00, 0x08, 0x00, 0x03, 0x00,
};


/* ALL: 0xff, 0xff, 0x00 */
unsigned char gtp_cmd_detect_pic3_1[] = {
    0x3e, 0x43, 0x00, 0x00, 0x08, 0x01, 0x03, 0x00,
};


/* ALL: 0x4f, 0x6b, 0x00 */
unsigned char gtp_cmd_detect_pic4[] = {
    0x3e, 0x38, 0x00, 0x00, 0x08, 0x03, 0x03, 0x00,
};


/* 16F84A:  0x60, 0x05, 0x65 */
/* 18F2550: 0xff, 0x3f, 0xc0 */
/* 18F452:  0xff, 0x3f, 0xc0 */
unsigned char gtp_cmd_detect_pic5[] = {
    0x3e, 0x34, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};


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


int usb_send_bytes (struct libusb_device_handle* handle, unsigned char* data, int len)
{
    int r, gone, done = 0;

    while (len > 0) {
        gone = 0;
        r = libusb_interrupt_transfer (handle, 1 | LIBUSB_ENDPOINT_OUT, data, len, &gone, 1000);
        if (r < 0) {
            printf ("Send error %d\n", r);
            return gone;
        }
        len -= gone;
        data += gone;
        done += gone;
    }

    return done;
}


int usb_get_bytes (struct libusb_device_handle* handle, unsigned char* buf, int len)
{
    int r, got;

    got = 0;
    r = libusb_interrupt_transfer (handle, 1 | LIBUSB_ENDPOINT_IN, buf, len, &got, 1000);
    if (r != LIBUSB_SUCCESS && r != LIBUSB_ERROR_TIMEOUT) {
        printf ("Get error: %d\n", r);
        return got;
    }

    return got;
}


void gtp_detect_chip (struct libusb_device_handle* handle)
{
    int done;
    unsigned char buf[128];

    done = usb_send_bytes (handle, gtp_cmd_detect_pic5, sizeof (gtp_cmd_detect_pic2));

    if (done != sizeof (gtp_cmd_detect_pic)) {
        printf ("PIC detect error\n");
        return;
    }
        
    done = usb_get_bytes (handle, buf, sizeof (buf));
    printf ("Get %d bytes\n", done);
    if (done == 3)
        printf ("0x%02x, 0x%02x, 0x%02x\n", buf[0], buf[1], buf[2]);
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
//        gtp_read_chip (handle);
        /* detect chip model */
        gtp_detect_chip (handle);
    }

    libusb_close (handle);
    libusb_exit (ctx);
    return 0;
}
