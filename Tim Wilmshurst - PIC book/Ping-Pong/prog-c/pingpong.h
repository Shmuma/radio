#include <16F84A.h>

#FUSES NOWDT                 	//No Watch Dog Timer
#FUSES RC                    	//Resistor/Capacitor Osc with CLKOUT
#FUSES NOPUT                 	//No Power Up Timer
#FUSES NOPROTECT             	//Code not protected from reading

#use delay(clock=600000)

#define LED_OUT		PIN_A2
#define LED_A		PIN_A1
#define LED_B		PIN_A0

/* inputs are inverted */
#define BTN_A PIN_A4
#define BTN_B PIN_A3
