# MPLAB IDE generated this makefile for use with GNU make.
# Project: base_lcd.mcp
# Date: Wed Jan 19 23:51:40 2011

AS = MPASMWIN.exe
CC = 
LD = mplink.exe
AR = mplib.exe
RM = del

base_lcd.cof : base_lcd.o
	$(CC) /p18F2550 "base_lcd.o" /u_DEBUG /z__MPLAB_BUILD=1 /z__MPLAB_DEBUG=1 /o"base_lcd.cof" /M"base_lcd.map" /W /x

base_lcd.o : base_lcd.asm ../../../../../../../Program\ Files/Microchip/MPASM\ Suite/p18f2550.inc
	$(AS) /q /p18F2550 "base_lcd.asm" /l"base_lcd.lst" /e"base_lcd.err" /d__DEBUG=1

clean : 
	$(CC) "base_lcd.o" "base_lcd.hex" "base_lcd.err" "base_lcd.lst" "base_lcd.cof"

