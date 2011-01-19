#include <p18f2550.h>
#include "xlcd/xlcd.h"
#include <delays.h>

#pragma config WDT = OFF, FOSC=HS, CPUDIV=OSC1_PLL2, PLLDIV=3
#pragma config DEBUG = OFF


void DelayFor18TCY(void)
{
    Delay10TCYx (2);
}

void DelayPORXLCD(void)
{
    /* 15 ms */
    Delay1KTCYx (45);
}

void DelayXLCD(void)
{
    /* 5 ms */
    Delay1KTCYx (15);
}

void main (void)
{
    OpenXLCD (FOUR_BIT & LINES_5X7);
    while (BusyXLCD ());

    putrsXLCD ("Hello, World!");
}
