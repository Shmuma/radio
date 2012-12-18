/* 
 * File:   main.c
 * Author: Shmuma
 */
#define _PLIB=1

#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include <xlcd.h>
#include <delays.h>
#include <string.h>

#define DCF77_PIN_DATA RB1

#include "dcf77.h"


#pragma config WDTE=OFF, LVP=OFF, FOSC=INTRC_NOCLKOUT
#pragma config WRT=OFF

#ifndef _XTAS_FREQ
#define _XTAL_FREQ 4000000
#endif

#define TMR1_1MS (65535 - (_XTAL_FREQ) / 4000)

// XLCD routines
void DelayFor18TCY () {
    _delay(18);
}

void DelayPORXLCD () {
    __delay_ms(15);
}

void DelayXLCD () {
    __delay_ms(5);
}

interrupt void isr ()
{
    // T1 overflowed, count time
    if (TMR1IF) {
        TMR1 = TMR1_1MS;
        TMR1IF = 0;
        dcf77_1ms_task ();
        return;
    }

    // B1 changed
    if (RBIF) {
        unsigned char dcf = RB1;

        if (!dcf) {
            // falling edge - reset counter of ms
        } else {
        }
        RD7 = RB1;
        RBIF = 0;
    }
}

void uart_str (const char* s)
{
    while (*s) {
        if (!TXIF) {
            __delay_ms (1);
            continue;
        }
        TXREG = *s;
        s++;
    }
}


int main(int argc, char** argv) {

    // DCF is on RB1
    TRISB1 = 1;
    ANS10 = 0;
    WPUB1 = 0;

    // setup timer1 for 1ms overflow
/*    TMR1 = TMR1_1MS;
    TMR1CS = 0;
    T1CKPS0 = 0;
    T1CKPS1 = 0;
    TMR1ON = 1;
*/
    // LCD
    TRISD = 0;
    TRISA = 0;
    ANSEL = 0;
    PORTD = 0;

    OpenXLCD (FOUR_BIT & LINES_5X7);

    // handle interrupts on B1 change
    IOCB1 = 1;

    // Interrupts
    RBIE = 1;
    TMR1IE = 1;
    PEIE = 1;
    GIE = 1;

    // EUSART - async mode
    TXEN = 1;
    SYNC = 0;
    BRGH = 0;
    SPBRG = 25; // 2400
    SPEN = 1;

    unsigned char buf[22];
    unsigned char buf_pos = 0;

    buf[0] = 0;
    unsigned char v = 0;

    while (1) {
        uart_str ("Hello, from MCU!\n\r");
        /*        if (dcf77_newdata()) {
            sprintf (buf, "+%02d:%02d", dcf77_get_hrs(), dcf77_get_min());
            putsXLCD(buf);
            SetDDRamAddr(0x0);
            while (BusyXLCD());
            RD6 = !RD6;
        }
        else {
            sprintf(buf, "-%d", dcf77_sync_u8);
            putsXLCD(buf);
            SetDDRamAddr(0x0);
            while (BusyXLCD());
        }
 */
        __delay_ms(100);
    }
    return (EXIT_SUCCESS);
}

