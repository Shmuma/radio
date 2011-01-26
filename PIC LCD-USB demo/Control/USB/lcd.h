#ifndef __LCD_H__
#define __LCD_H__

#include "common.h"

/* control pins */
/* PORTB */
#define LCD_RS_PIN 0
#define LCD_RW_PIN 1
#define LCD_E_PIN  2

#define LCD_DB6_PIN 3
#define LCD_DB7_PIN 4

/* PORTA */
#define LCD_DB0_PIN 0
#define LCD_DB1_PIN 1
#define LCD_DB2_PIN 2
#define LCD_DB3_PIN 3
#define LCD_DB4_PIN 4
#define LCD_DB5_PIN 5


void InitLCD ();
void WriteLCDByte (unsigned char v);
void WriteLCDChar (unsigned char v);
void WaitForBusyFlag ();

void ClearLCD ();

void putStr (const char* s);
void putStrRom (const rom char* s);

#endif /* __LCD_H__ */
