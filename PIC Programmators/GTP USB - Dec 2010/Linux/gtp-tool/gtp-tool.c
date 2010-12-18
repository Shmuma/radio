#include <stdio.h>
#include <stdlib.h>

#include <libusb.h>

struct libusb_context* ctx;

#define GTP_VENDOR  0x04D8
#define GTP_PRODUCT 0x5200


struct libusb_device* find_gtp_device ()
{
    ssize_t count, i;
    libusb_device** dev;
    struct libusb_device_descriptor descr;

    count = libusb_get_device_list (ctx, &dev);

    for (i = 0; i < count; i++)
        if (!libusb_get_device_descriptor (dev[i], &descr))
            if (descr.idVendor == GTP_VENDOR && descr.idProduct == GTP_PRODUCT)
                return dev[i];
    return NULL;
}


int main (int argc, char *argv[])
{
    int err;
    struct libusb_device* dev;

    if ((err = libusb_init (&ctx)) != 0) {
        printf ("libusb_init failed with code %d\n", err);
        return 1;
    }

    libusb_set_debug (ctx, 3);

    dev = find_gtp_device ();
    if (!dev)
        printf ("GTP-USB device not found\n");
    else {
        printf ("GTP-USB device found\n");
    }

    libusb_exit (ctx);
    return 0;
}
