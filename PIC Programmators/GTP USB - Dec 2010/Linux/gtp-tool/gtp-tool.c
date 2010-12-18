#include <stdio.h>
#include <stdlib.h>

#include <libusb.h>

struct libusb_context* ctx;

#define GTP_VENDOR  0x04D8
#define GTP_PRODUCT 0x5200


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
        printf ("GTP-USB device found\n");
    }

    libusb_close (handle);
    libusb_exit (ctx);
    return 0;
}
