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

unsigned int passed, changes;

interrupt void isr ()
{
    // T1 overflowed, count time
    if (TMR1IF) {
        passed++;
        TMR1 = TMR1_1MS;
        TMR1IF = 0;
        return;
    }

    // B1 changed
    if (RBIF) {
        unsigned char dcf = RB1;

        if (!dcf) {
            changes++;
            // falling edge - reset overflow counter
//            t0_overflows = 0;
        } else {
            // raising edge
//            delays[delays_index++] = t0_overflows;
//            delays_index %= 10;
//            pulse_delay = t0_overflows;
        }
        RD7 = RB1;
        RBIF = 0;
    }
}


int main(int argc, char** argv) {

    // DCF is on RB1
    TRISB1 = 1;
    ANS10 = 0;
    WPUB1 = 0;

    // setup timer1 for 1ms overflow
    TMR1 = TMR1_1MS;
    TMR1CS = 0;
    T1CKPS0 = 0;
    T1CKPS1 = 0;
    TMR1ON = 1;

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

    unsigned char buf[40];

    while (1) {
        sprintf (buf, "t = %u, c = %u  ", passed, changes);
        putsXLCD(buf);
        SetDDRamAddr(0x0);
        while (BusyXLCD());
        changes = passed = 0;
        __delay_ms (1000);
        RD6 = !RD6;
    }
    return (EXIT_SUCCESS);
}

