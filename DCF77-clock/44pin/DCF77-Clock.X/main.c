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

#pragma config WDTE=OFF, LVP=OFF, FOSC=INTRC_NOCLKOUT
#pragma config WRT=OFF

#ifndef _XTAS_FREQ
#define _XTAL_FREQ 4000000
#endif

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

/*
 * 
 */

int main(int argc, char** argv) {

    // DCF is on RB1
    TRISB1 = 1;
    ANS10 = 0;
    WPUB1 = 0;

    // 44-pin leds
    TRISD = 0;
    PORTD = 0;

    // LCD
    TRISC = 0;
    TRISA = 0;
    ANSEL = 0;

    OpenXLCD (FOUR_BIT & LINES_5X7);
/*    while (BusyXLCD());
    WriteCmdXLCD(0x111);
    while (BusyXLCD());
    WriteCmdXLCD(CURSOR_ON & BLINK_OFF);
    while (BusyXLCD());
    SetDDRamAddr(0x10);
*/
//    putsXLCD("DCF77...");

    int i = 0;

    unsigned char buf[21];
    buf[20] = 0;

    while (1) {
        for (i = 0; i < 20; i++) {
            RD0 = RB1;
            if (RB1)
                buf[i] = '1';
            else
                buf[i] = '0';
            __delay_ms(50);
        }
        putsXLCD(buf);
        SetDDRamAddr(0x0);
        while (BusyXLCD());
    }
    return (EXIT_SUCCESS);
}

