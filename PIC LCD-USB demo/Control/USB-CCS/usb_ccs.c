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

unsigned int8 rxdata[64];
unsigned int8 rxdata_len;

static char buf[21];

unsigned int8 lcd_tick;
char lcd_ticks[] = {0xEF, 0xEE, 0x20, 0xEE};


void lcd_refresh ();

void main()
{
    setup_timer_3 (T3_DISABLED|T3_DIV_BY_1);
    usb_init ();
    lcd_init ();
    lcd_putc ('\f');
    delay_ms (1);
    while (TRUE) {
        lcd_refresh ();
        usb_task ();
        if (usb_enumerated ()) {
            if (usb_kbhit (1))
                rxdata_len = usb_get_packet (1, rxdata, sizeof (rxdata));
//            usb_puts (1, lcd_ticks, sizeof (lcd_ticks), 10000);
        }
        delay_ms (100);
    }
}



void lcd_refresh ()
{
    char* p = buf;
    int8 i;

    lcd_gotoxy (1, 1);
    if (usb_enumerated ()) {
        lcd_putc ("EN: 1");
        sprintf (buf, ", Dat: %d", rxdata_len);
        
        while (*p)
            lcd_putc (*(p++));
    }
    else
        lcd_putc ("EN: 0");

    /* dump data if any */
    lcd_gotoxy (1, 2);
    for (i = 0; i < rxdata_len; i++)
        if (rxdata[i])
            lcd_putc (rxdata[i]);
    lcd_putc ('\n');

    /* display live status */
    lcd_gotoxy (20, 1);
    lcd_putc (lcd_ticks[lcd_tick]);
    lcd_tick = (lcd_tick + 1) % sizeof (lcd_ticks);
}
