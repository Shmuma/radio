#include "lcd.h"
#include "common.h"

#include <delays.h>
#include <stdio.h>

/*
 * Performs LCD initialization and display clear
 */
void InitLCD ()
{
    Delay1KTCYx (15);
    WriteLCDByte (0x30);
    Delay1KTCYx (15);
    WriteLCDByte (0x30);
    Delay1KTCYx (3);
    WriteLCDByte (0x32);

    WaitForBusyFlag ();

    /* 8 bit, 2 lines, 8x5 dot */
    WriteLCDByte (0x38);
    WaitForBusyFlag ();
    
    /* display off, cursor off, blink off */
    WriteLCDByte (0x8);
    WaitForBusyFlag ();
    /* display on, cursor off, blink off */
    WriteLCDByte (0xC);

    LCDClear ();
    Delay1KTCYx (3);
    WriteLCDByte (0x6);
    Delay1KTCYx (3);
}


static void WriteLCD (unsigned char v)
{
    LCD_RW_PIN = 0;
    
    /* if pins are changed, rewrite here */
    PORTA &= ~0x3F;
    PORTA |= v & 0x3F;
    PORTB &= ~0x18;
    if (v & 0xC0)
        PORTB |= (v & 0xC0) >> 3;

    Delay10TCYx (2);
    LCD_E_PIN = 1;
    Delay10TCYx (2);
    LCD_E_PIN = 0;
}


void WriteLCDByte (unsigned char c)
{
    LCD_RS_PIN = 0;
    WriteLCD (c);
}


void WriteLCDChar (unsigned char c)
{
    LCD_RS_PIN = 1;
    WriteLCD (c);
    WaitForBusyFlag ();
}


void WaitForBusyFlag ()
{
    bitclr (PORTB, LCD_DB7_PIN);
    bitset (TRISB, LCD_DB7_PIN); /* DB7 -> input mode */
    LCD_RS_PIN = 0;
    LCD_RW_PIN = 1;

    Delay10TCYx (10);

    do {
        LCD_E_PIN = 1;
        Delay10TCYx (10);
        LCD_E_PIN = 0;
        Delay10TCYx (10);
    }
    while (! (PORTB & 0x10));

    bitclr (TRISB, LCD_DB7_PIN);
    PORTB = 0;
}


void LCDClear (void)
{
    WriteLCDByte (1);
    WaitForBusyFlag ();
}


void LCDHome (void)
{
    WriteLCDByte (2);
    WaitForBusyFlag ();
}

void putStr (const char* s)
{
    while (*s) {
        WriteLCDChar (*s);
        s++;
    }
}


void putStrRom (const rom char* s)
{
    while (*s) {
        WriteLCDChar (*s);
        s++;
    }
}


void putNumber (unsigned int n)
{
    static char buf[10];
    sprintf (buf, "%u", n);
    putStr (buf);
}
