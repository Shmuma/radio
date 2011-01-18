#include <p18f2550.h>

#pragma config WDT = OFF

void delay ()
{
	overlay unsigned char a, b;

	for (a = 0; a < 100; a++)
		for (b = 0; b < 10; b++) {}
}

void main (void)
{
	int lp;

	TRISB = 0x00;
	while (1) {
		PORTB = 0x00;
		delay ();
		PORTB = 0xFF;
		delay ();
	}
}