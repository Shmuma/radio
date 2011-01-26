#include "lcd.h"
#include "common.h"

#include <delays.h>


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
    
    /* display off, cursor off, blink off */
    WriteLCDByte (0x8);
    WaitForBusyFlag ();
    /* display on, cursor on, blink on */
    WriteLCDByte (0xF);

    ClearLCD ();
    WaitForBusyFlag ();
    WriteLCDByte (0x6);
}


void WriteLCDByte (unsigned char v)
{
    bitclr (PORTB, LCD_RS_PIN);
    bitclr (PORTB, LCD_RW_PIN);
    
    /* if pins are changed, rewrite here */
    PORTA &= ~0x3F;
    PORTA |= v & 0x3F;
    PORTB &= ~0x18;
    if (v & 0xC0)
        PORTB |= (v & 0xC0) >> 3;

    Delay10TCYx (2);
    bitset (PORTB, LCD_E_PIN);
    Delay10TCYx (2);
    
    bitclr (PORTB, LCD_E_PIN);
}


void WaitForBusyFlag ()
{
    bitclr (PORTB, LCD_DB7_PIN);
    bitset (TRISB, LCD_DB7_PIN); /* DB7 -> input mode */
    bitclr (PORTB, LCD_RS_PIN);
    bitset (PORTB, LCD_RW_PIN);
    Delay10TCYx (4);

    do {
        bitset (PORTB, LCD_E_PIN);
        Delay10TCYx (4);
        bitclr (PORTB, LCD_E_PIN);
        Delay10TCYx (4);
    }
    while (! (PORTB & 0x10));
}


void ClearLCD ()
{
    WriteLCDByte (1);
}
