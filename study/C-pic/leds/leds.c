//#include <pic1687x.h>
#include <htc.h>

__CONFIG (PWRTEN);


void main ()
{
    TRISD = 0;
    while (1) {
        PORTD = 0;
        _delay (10000);
        PORTD = 0xFF;
        _delay (10000);
    }
}
