#define __USB_PIC_PERIF__ 1

#include <18F2550.h>
#FUSES NOWDT, WDT128, PLL3, CPUDIV4, USBDIV, HSPLL, FCMEN, IESO, NOPUT, NOBROWNOUT, BORV20, VREGEN, NOPBADEN, LPT1OSC, NOMCLR, STVREN, NOLVP, NOXINST, NODEBUG, NOPROTECT, NOCPB, NOCPD, NOWRT, NOWRTC, NOWRTB, NOWRTD, NOEBTR, NOEBTRB
//#fuses HSPLL,NOWDT,NOPROTECT,NOLVP,NODEBUG,USBDIV,PLL3,CPUDIV1,VREGEN

#use delay(clock=48000000)

/* USB */
#define USB_HID_DEVICE FALSE

#include <pic18_usb.h>
#include "usb_desc.h"
#include <usb.c>

/* LCD */
#define LCD_EXTENDED_NEWLINE TRUE

#define LCD_ENABLE_PIN PIN_B2
#define LCD_RS_PIN PIN_B0
#define LCD_RW_PIN PIN_B1
#define LCD_DATA4 PIN_A4
#define LCD_DATA5 PIN_A5
#define LCD_DATA6 PIN_B3
#define LCD_DATA7 PIN_B4
#include <lcd.c>


void main()
{
    setup_timer_3 (T3_DISABLED|T3_DIV_BY_1);
    enable_interrupts (GLOBAL);
    usb_init ();
    lcd_init ();
    delay_ms (1);
    while (TRUE) {
        usb_task ();
        lcd_putc ('\f');
        if (usb_enumerated ())
            lcd_putc ("Enum: 1, ");
        else
            lcd_putc ("Enum: 0, ");
        if (usb_attached ())
            lcd_putc ("Att: 1");
        else
            lcd_putc ("Att: 0");
        delay_ms (100);
    }
}
