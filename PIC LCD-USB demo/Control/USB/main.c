#include <p18f2550.h>
#include <delays.h>

#include "USB/usb.h"
#include "USB/usb_common.h"

/*
__CONFIG (1, HS & CPUDIV2 & PLLDIV12);
__CONFIG (2, PWRTDIS);
__CONFIG (3, PBDIGITAL & MCLREN);
__CONFIG (4, DEBUGDIS);
__CONFIG (5, UNPROTECT);
__CONFIG (6, UNPROTECT);
__CONFIG (7, UNPROTECT);
*/

#define bitset(var, bitno) ((var) |= 1UL << (bitno))
#define bitclr(var, bitno) ((var) &= ~(1UL << (bitno)))

#pragma config WDT = OFF, FOSC=HS, CPUDIV=OSC1_PLL2, PLLDIV=3, MCLRE=ON
#pragma config DEBUG = OFF

#define E_PORT 2


void InitDevice ();
int InitializeUSB ();

void USBCBInitEP ();


void main ()
{
    InitDevice ();

    if (InitializeUSB ())
        return;

    USBDeviceAttach ();

    while (1) {
        USBDeviceTasks ();
        if (USBDeviceState < CONFIGURED_STATE)
            continue;
        bitset (PORTB, E_PORT);
        Delay10TCYx (10);
        bitclr (PORTB, E_PORT);
        Delay10TCYx (10);
    }
}

void InitDevice ()
{
    /* clear 4 lower bits -> switch all IO into digital */
    ADCON1 &= 0xF0;

    /* output */
    TRISA = TRISB = 0;
    PORTA = PORTB = 0;
}

int InitializeUSB ()
{
    USBDeviceInit ();
    return (0);
}


BOOL USER_USB_CALLBACK_EVENT_HANDLER (USB_EVENT event, void *pdata, WORD size)
{
    switch (event) {
        case EVENT_CONFIGURED: 
            USBCBInitEP();
            break;
    }
    
    return TRUE;
}


void USBCBInitEP ()
{
    USBEnableEndpoint(HID_EP,USB_IN_ENABLED|USB_OUT_ENABLED|USB_HANDSHAKE_ENABLED|USB_DISALLOW_SETUP);
}
