#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#include <time.h>
#include <string.h>

#include <libusb.h>

struct libusb_context* ctx;

#define GTP_VENDOR  0x04D8
#define GTP_PRODUCT 0xD001


/* commands table */
unsigned char cmd_get_version[] = {
    "Hello, Mouse!"
};

void lcd_update_time (struct libusb_device_handle* handle)
{
    static unsigned char buf[256];

    int r, gone;
    time_t t = time (NULL);
    struct tm* tm = localtime (&t);
    
    sprintf (buf, "%d:%02d:%02d", tm->tm_hour, tm->tm_min, tm->tm_sec);

    r = libusb_bulk_transfer (handle, 1 | LIBUSB_ENDPOINT_OUT, buf, strlen (buf), &gone, 1000);
    /* if (r < 0) { */
    /*     printf ("Send error %d\n", r); */
    /*     return; */
    /* } */
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
        printf ("LCD-USB device not found\n");
    else {
        libusb_claim_interface (handle, 0);

        while (1) {
            lcd_update_time (handle);
            /* sleep for 0.1 seconds */
            usleep (100000);
        }
    }

    libusb_close (handle);
    libusb_exit (ctx);
    return 0;
}
