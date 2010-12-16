#include <stdio.h>
#include <stdlib.h>

#include <libusb.h>

struct libusb_context* ctx;


void find_gtp_device ()
{
    ssize_t count;

    count = libusb_get_device_list ()
}


int main (int argc, char *argv[])
{
    int err;

    if ((err = libusb_init (&ctx)) != 0) {
        printf ("libusb_init failed with code %d\n", err);
        return 1;
    }

    libusb_set_debug (ctx, 3);

    find_gtp_device ();

    libusb_exit (ctx);
    return 0;
}
