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

#pragma config WDTE=OFF, LVP=OFF, FOSC=INTRC_NOCLKOUT, MCLRE=OFF
#pragma config WRT=OFF

#ifndef _XTAL_FREQ
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

unsigned short buf = 0;
unsigned char buf_bits = 0;

unsigned short buf_out = 0;
unsigned char buf_ready = 0;
unsigned char overflows = 0;

interrupt void isr ()
{
    // T1 overflowed, count time
    if (TMR1IF) {
        TMR1 = TMR1_1MS;
        TMR1IF = 0;

        // place data ready to be sent
        if (buf_bits == 16) {
            if (buf_ready) {
                RD7 = !RD7;
                overflows++;
            }
            buf_out = buf;
            buf_ready = 1;
            buf_bits = 0;
        }

        buf <<= 1;
        if (DCF77_PIN_DATA)
            buf |= 1;
        buf_bits++;
        return;
    }

    // B1 changed
/*    if (RBIF) {
        unsigned char dcf = RB1;

        if (!dcf) {
            // falling edge - reset counter of ms
            high_time = ms_passed;
            ms_passed = 0;
            ready = TRUE;
        } else {
            // rising edge
            low_time = ms_passed;
            ms_passed = 0;
        }
        RD7 = RB1;
        RBIF = 0;
    }
 */
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
    WPUB1 = 1;

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
//    IOCB1 = 1;

    // Interrupts
    RBIE = 1;
    TMR1IE = 1;
    PEIE = 1;
    GIE = 1;

    // EUSART - async mode
    TXEN = 1;
    SYNC = 0;
    BRGH = 1;
    SPBRG = 12; // 19200
    SPEN = 1;

    unsigned char buf[22];
    unsigned char wrap = 32;

    while (1) {
        if (buf_ready) {
            sprintf (buf, "%04X ", buf_out);
            buf_ready = 0;
            uart_str (buf);
            if (!--wrap) {
                uart_str ("\n");
                wrap = 32;
            }

        }
//        __delay_ms(10);
    }
    return (EXIT_SUCCESS);
}

