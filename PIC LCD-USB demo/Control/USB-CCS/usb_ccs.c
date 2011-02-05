#define __USB_PIC_PERIF__ 1

#include <18F2550.h>
#FUSES NOWDT, WDT128, PLL3, CPUDIV4, USBDIV, HSPLL, FCMEN, IESO, NOPUT, NOBROWNOUT, BORV20, VREGEN, NOPBADEN, LPT1OSC, NOMCLR, STVREN, NOLVP, NOXINST, NODEBUG, NOPROTECT, NOCPB, NOCPD, NOWRT, NOWRTC, NOWRTB, NOWRTD, NOEBTR, NOEBTRB
//#fuses HSPLL,NOWDT,NOPROTECT,NOLVP,NODEBUG,USBDIV,PLL3,CPUDIV1,VREGEN

#use delay(clock=48000000)

#define USB_HID_DEVICE TRUE

#include <pic18_usb.h>
#include "usb_desc.h"
#include <usb.c>

void main()
{
    setup_timer_3(T3_DISABLED|T3_DIV_BY_1);
    enable_interrupts (GLOBAL);
    usb_init ();
    delay_ms (1);
    while (TRUE) {
        usb_task ();
        delay_ms (1);
    }
}
