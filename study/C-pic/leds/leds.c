//#include <pic1687x.h>
#include <htc.h>

__CONFIG (PWRTEN);


void main ()
{
    int i;

    TRISD = 0;
    while (1) {
        PORTD = 0;
        for (i = 0; i < 10000; i++) {};
        PORTD = 0xFF;
        for (i = 0; i < 10000; i++) {};
    }
}
