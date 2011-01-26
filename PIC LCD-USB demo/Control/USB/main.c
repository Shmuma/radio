#include <p18f2550.h>
#include <delays.h>

#include "common.h"
#include "lcd.h"

#include "USB/usb.h"
#include "USB/usb_common.h"
#include "USB/usb_function_generic.h"

/*
__CONFIG (1, HS & CPUDIV2 & PLLDIV12);
__CONFIG (2, PWRTDIS);
__CONFIG (3, PBDIGITAL & MCLREN);
__CONFIG (4, DEBUGDIS);
__CONFIG (5, UNPROTECT);
__CONFIG (6, UNPROTECT);
__CONFIG (7, UNPROTECT);
*/


#pragma config WDT = OFF, FOSC=HS, CPUDIV=OSC1_PLL2, PLLDIV=3, MCLRE=ON, USBDIV=2, BOR=ON, BORV=3, VREGEN=ON
#pragma config DEBUG = OFF

#define E_PORT 2

unsigned char OUTPacket[64];
unsigned char INPacket[64];

#pragma udata
USB_HANDLE USBGenericOutHandle;
USB_HANDLE USBGenericInHandle;
#pragma udata


void InitDevice ();
int InitializeUSB ();

void USBCBInitEP ();


void main ()
{
    InitDevice ();
    InitLCD ();
//    if (InitializeUSB ())
//        return;

//    USBDeviceAttach ();
    putStrRom ("Hello, World!!!!");
    
    while (1) {
    }
//        if (USBDeviceState < CONFIGURED_STATE)
//            continue;

//        bitset (PORTB, E_PORT);
//        Delay10TCYx (10);
//        ClearLCD ();
//        bitclr (PORTB, E_PORT);
//        Delay10TCYx (10);
//    }
}

void InitDevice ()
{
    /* set 4 lower bits -> switch all IO into digital */
    ADCON1 |= 0x0F;

    /* output */
    TRISA = TRISB = 0;
    PORTA = PORTB = 0;
}

int InitializeUSB ()
{
    USBGenericInHandle = USBGenericOutHandle = 0;
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
    USBEnableEndpoint(USBGEN_EP_NUM, USB_IN_ENABLED | USB_OUT_ENABLED | USB_HANDSHAKE_ENABLED | USB_DISALLOW_SETUP);
    USBGenericOutHandle = USBGenRead (USBGEN_EP_NUM, (BYTE*)&OUTPacket, USBGEN_EP_SIZE);
}
