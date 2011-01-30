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


#pragma config WDT=OFF, FOSC=HSPLL_HS, CPUDIV=OSC4_PLL6, PLLDIV=3, MCLRE=ON, USBDIV=2, BOR=OFF, BORV=3, VREGEN=ON, FCMEN=ON, IESO=OFF
#pragma config PWRT=OFF, WDTPS=1, CCP2MX=OFF, PBADEN=OFF, STVREN=OFF, LVP=OFF, XINST=OFF
#pragma config CP0=OFF, CP1=OFF, CP2=OFF, CP3=OFF, CPB=OFF, CPD=OFF, WRT0=OFF
#pragma config DEBUG=OFF

#define E_PORT 2

unsigned char OUTPacket[64];
unsigned char INPacket[64];

#pragma udata
USB_HANDLE USBGenericOutHandle;
USB_HANDLE USBGenericInHandle;
#pragma udata


void InitDevice (void);
void InitializeUSB (void);

void USBCBInitEP (void);


void main (void)
{
    int cnt = 0;

    InitDevice ();
    Delay10KTCYx (250);
    InitializeUSB ();
    InitLCD ();

    /* UCONbits.USBEN = 0; */
    /* UCFGbits.UTRDIS = 0; */
    /* UCFGbits.UPUEN = 1; */
    /* UCFGbits.FSEN = 1; */
    USBDeviceAttach ();

    while (1) {
        WriteLCDChar (UCONbits.USBEN ? '0' : '1');
        WriteLCDChar (UCFGbits.FSEN  ? '0' : '1');
        WriteLCDChar (UCFGbits.UTRDIS ? '0' : '1');
        WriteLCDChar (UCFGbits.UPUEN ? '0' : '1');
        WriteLCDChar ('0' + UCFGbits.PPB);
        WriteLCDChar ('-');
        WriteLCDChar ('0' + USTATbits.ENDP);
        WriteLCDChar ('0' + USTATbits.DIR);
        WriteLCDChar ('0' + USTATbits.PPBI);
        WriteLCDChar ('-');
        putNumber (USBDeviceState);
        WriteLCDChar ('-');
        putNumber (cnt++);
//        if (USBDeviceState == DETACHED_STATE)
//            USBDeviceAttach ();
        Delay10KTCYx (1000);
        LCDHome ();
        Delay10KTCYx (10);
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

void InitDevice (void)
{
    /* set 4 lower bits -> switch all IO into digital */
    ADCON1 |= 0x0F;

    /* output */
    TRISA = TRISB = 0;
    PORTA = PORTB = 0;
}


void MyUSBDeviceInit (void)
{
    UCFGbits.FSEN = 1;
    UCFGbits.UTRDIS = 0;
    UCFGbits.UPUEN = 1;
    UCONbits.USBEN = 1;
}


void InitializeUSB (void)
{
    USBGenericInHandle = USBGenericOutHandle = 0;
    USBDeviceInit ();
//    MyUSBDeviceInit ();
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


void USBCBInitEP (void)
{
    USBEnableEndpoint(USBGEN_EP_NUM, USB_IN_ENABLED | USB_OUT_ENABLED | USB_HANDSHAKE_ENABLED | USB_DISALLOW_SETUP);
    USBGenericOutHandle = USBGenRead (USBGEN_EP_NUM, (BYTE*)&OUTPacket, USBGEN_EP_SIZE);
}
