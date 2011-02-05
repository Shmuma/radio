#include <18F2550.h>

#FUSES NOWDT                 	//No Watch Dog Timer
#FUSES WDT128                	//Watch Dog Timer uses 1:128 Postscale
#FUSES PLL3                  	//Divide By 3(12MHz oscillator input)
#FUSES CPUDIV4               	//System Clock by 4
#FUSES USBDIV                	//USB clock source comes from PLL divide by 2
#FUSES HSPLL                 	//High Speed Crystal/Resonator with PLL enabled
#FUSES FCMEN                 	//Fail-safe clock monitor enabled
#FUSES IESO                  	//Internal External Switch Over mode enabled
#FUSES NOPUT                 	//No Power Up Timer
#FUSES NOBROWNOUT            	//No brownout reset
#FUSES BORV20                	//Brownout reset at 2.0V
#FUSES VREGEN                	//USB voltage regulator enabled
#FUSES NOPBADEN              	//PORTB pins are configured as digital I/O on RESET
#FUSES NOLPT1OSC             	//Timer1 configured for higher power operation
#FUSES NOMCLR                	//Master Clear pin used for I/O
#FUSES STVREN                	//Stack full/underflow will cause reset
#FUSES NOLVP                 	//No low voltage prgming, B3(PIC16) or B5(PIC18) used for I/O
#FUSES NOXINST               	//Extended set extension and Indexed Addressing mode disabled (Legacy mode)
#FUSES NODEBUG               	//No Debug mode for ICD
#FUSES NOPROTECT             	//Code not protected from reading
#FUSES NOCPB                 	//No Boot Block code protection
#FUSES NOCPD                 	//No EE protection
#FUSES NOWRT                 	//Program memory not write protected
#FUSES NOWRTC                	//configuration not registers write protected
#FUSES NOWRTB                	//Boot block not write protected
#FUSES NOWRTD                	//Data EEPROM not write protected
#FUSES NOEBTR                	//Memory not protected from table reads
#FUSES NOEBTRB               	//Boot block not protected from table reads

#use delay(crystal=12000000,  clock=48000000)

