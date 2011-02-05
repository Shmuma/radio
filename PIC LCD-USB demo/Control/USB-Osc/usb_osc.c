////////////////////////////////////////////////////////////////////////////////
//                 PIC18F2550 USB HID Oscilloscope
//
// Filename     : 18F2550 USB HID CRC Oscilloscope.c
// Programmer   : Steven Cholewiak, www.semifluid.com
// Version      : Version 1.0 - 03/27/2006
// Remarks      : More information on the circuit can be found at:
//                http://www.semifluid.com/PIC18F2550_usb_hid_oscilloscope.html
////////////////////////////////////////////////////////////////////////////////

#define __USB_PIC_PERIF__ 1

#include <18F2550.h>
#device ADC=8
#fuses HSPLL,NOWDT,NOPROTECT,NOLVP,NODEBUG,USBDIV,PLL3,CPUDIV1,VREGEN
#use delay(clock=48000000)

#build(reset=0x1, interrupt=0x8)          // Necessary for Bootloader
#ORG 0x0F00,0x0FFF {}                     // Necessary for Bootloader

#use rs232(stream=PC, baud=115200, xmit=PIN_C6, rcv=PIN_C7, ERRORS)

// CCS Library dynamic defines
#DEFINE USB_HID_DEVICE  TRUE //Tells the CCS PIC USB firmware to include HID handling code.
#define USB_EP1_TX_ENABLE  USB_ENABLE_INTERRUPT   //turn on EP1 for IN bulk/interrupt transfers
#define USB_EP1_TX_SIZE    64  //allocate 64 bytes in the hardware for transmission
#define USB_EP1_RX_ENABLE  USB_ENABLE_INTERRUPT   //turn on EP1 for OUT bulk/interrupt transfers
#define USB_EP1_RX_SIZE    64  //allocate 64 bytes in the hardware for reception

// CCS USB Libraries
#include <pic18_usb.h>   //Microchip 18Fxx5x hardware layer for usb.c
#include "usb_desc_hid.h"   //USB Configuration and Device descriptors for this UBS device
#include <usb.c>        //handles usb setup tokens and get descriptor reports

void usb_debug_task(void) {
   static int8 last_connected;
   static int8 last_enumerated;
   int8 new_connected;
   int8 new_enumerated;

   new_connected=usb_attached();
   new_enumerated=usb_enumerated();

   if (new_connected && !last_connected) {
      printf("\r\n\nUSB connected, waiting for enumaration...");}
   if (!new_connected && last_connected) {
      printf("\r\n\nUSB disconnected, waiting for connection...");}
   if (new_enumerated && !last_enumerated) {
      printf("\r\n\nUSB enumerated by PC/HOST");}
   if (!new_enumerated && last_enumerated) {
      printf("\r\n\nUSB unenumerated by PC/HOST, waiting for enumeration...");}

   last_connected=new_connected;
   last_enumerated=new_enumerated;
}

#INT_RDA
void serial_isr()                         // Serial Interrupt
{
   int8 uReceive;

   disable_interrupts(GLOBAL);            // Disable Global Interrupts

   uReceive = fgetc(PC);

   switch (uReceive) {
      case 0x12: {
            if (fgetc(PC) == 0x34 & fgetc(PC) == 0x56 & fgetc(PC) == 0x78 & fgetc(PC) == 0x90) #asm reset #endasm
         }
         break;
   }

   enable_interrupts(GLOBAL);                // Enable Global Interrupts
}

int calc_crc(int oldcrc, int newbyte) {
   // Please see: http://pdfserv.maxim-ic.com/arpdf/AppNotes/app27.pdf

   int shift_reg, data_bit, sr_lsb, fb_bit, j;
   shift_reg=oldcrc;
   for(j=0; j<8; j++) {   // for each bit
      data_bit = (newbyte >> j) & 0x01;
      sr_lsb = shift_reg & 0x01;
      fb_bit = (data_bit ^ sr_lsb) & 0x01;
      shift_reg = shift_reg >> 1;
      if (fb_bit)
         shift_reg = shift_reg ^ 0x8c;
      }
   return(shift_reg);
}

#define theSampleSize            512

#define usbConfirmAction         0
#define usbCheckStatus           1
#define usbReadRam               2
#define usbWriteRam              3
#define usbReadADC               4
#define usbReadADCnTimes         5
#define usbReadADCPeriod         6
#define usbReadADCnTimesMS       7
#define usbClearRam              8
#define usbSetRamByte            9
#define usbSetUseCRC             10
#define usbClearUseCRC           11
#define usbReadADCnTimesUS       12
#define usbError                 66

void main() {
   int1 useCRC;
   int8 in_data[8];
   int8 out_data[8];
   int8 adcData[theSampleSize];
   int8 theCRC, tempADC;
   int16 n, approxUS, approxMS, period;

   SETUP_ADC_PORTS(AN0);
   SETUP_ADC(ADC_CLOCK_DIV_64);
   SETUP_TIMER_0(RTCC_INTERNAL|RTCC_DIV_1);
   SETUP_TIMER_1(T1_DISABLED);
   SETUP_TIMER_2(T2_DISABLED, 127, 1);
   SETUP_TIMER_3(T3_INTERNAL | T3_DIV_BY_8);
   SETUP_CCP1(CCP_OFF);
   SETUP_CCP2(CCP_OFF);
   enable_interrupts(INT_RDA);
   enable_interrupts(GLOBAL);

   usb_init();
   useCRC = true;
   set_adc_channel(0);
   delay_ms(1);

   while (TRUE) {
      usb_task();
      usb_debug_task();
      if (usb_enumerated()) {
         if (usb_kbhit(1)) {
            usb_get_packet(1, in_data, 8);

            if (useCRC) {
               theCRC = 0;
               theCRC = calc_crc(theCRC,in_data[0]);
               theCRC = calc_crc(theCRC,in_data[1]);
               theCRC = calc_crc(theCRC,in_data[2]);
               theCRC = calc_crc(theCRC,in_data[3]);
               theCRC = calc_crc(theCRC,in_data[4]);
               theCRC = calc_crc(theCRC,in_data[5]);
               theCRC = calc_crc(theCRC,in_data[6]);
            }
            else {
               theCRC = in_data[7];
            }

            if (theCRC = in_data[7]) {
               out_data[0] = 255;
               out_data[1] = 255;
               out_data[2] = 255;
               out_data[3] = 255;
               out_data[4] = 255;
               out_data[5] = 255;
               out_data[6] = 255;

               switch (in_data[0]) {
                  case usbReadRam: {
                        if (make16(in_data[1],in_data[2]) <= theSampleSize) {
                           out_data[0] = usbConfirmAction;
                           out_data[1] = usbReadRam;
                           out_data[2] = in_data[1];
                           out_data[3] = in_data[2];
                           out_data[4] = adcData[make16(in_data[1],in_data[2])];
                        }
                        else {
                           out_data[0] = usbError;
                           out_data[1] = usbReadRam;
                           out_data[2] = in_data[1];
                           out_data[3] = in_data[2];
                        }
                     }
                     break;
                  case usbWriteRam: {
                        if (make16(in_data[1],in_data[2]) <= theSampleSize) {
                           adcData[make16(in_data[1],in_data[2])] = in_data[3];
                           out_data[0] = usbConfirmAction;
                           out_data[1] = usbWriteRam;
                           out_data[2] = in_data[1];
                           out_data[3] = in_data[2];
                           out_data[4] = in_data[3];
                        }
                        else {
                           out_data[0] = usbError;
                           out_data[1] = usbWriteRam;
                           out_data[2] = in_data[1];
                           out_data[3] = in_data[2];
                           out_data[4] = in_data[3];
                        }
                     }
                     break;
                  case usbReadADC: {
                        tempADC = READ_ADC();
                        out_data[0] = usbConfirmAction;
                        out_data[1] = usbReadADC;
                        out_data[2] = tempADC;
                     }
                     break;
                  case usbReadADCnTimes: {
                        if (make16(in_data[1],in_data[2]) <= theSampleSize) {
                           set_timer3(0);
                           for (n=0;n<make16(in_data[1],in_data[2]);n++)
                           {
                              adcData[n] = READ_ADC();
                           }
                           period = get_timer3();   // 1000/((clock/4)/8) for ms
                           out_data[0] = usbConfirmAction;
                           out_data[1] = usbReadADCnTimes;
                           out_data[2] = in_data[1];
                           out_data[3] = in_data[2];
                        }
                        else {
                           out_data[0] = usbError;
                           out_data[1] = usbReadADCnTimes;
                           out_data[2] = in_data[1];
                           out_data[3] = in_data[2];
                        }
                     }
                     break;
                  case usbReadADCPeriod: {
                        out_data[0] = usbConfirmAction;
                        out_data[1] = usbReadADCPeriod;
                        out_data[2] = make8(period,1);
                        out_data[3] = make8(period,0);
                     }
                     break;
                  case usbReadADCnTimesUS: {
                        if (make16(in_data[1],in_data[2]) <= theSampleSize) {
                           approxUS = make16(in_data[3],in_data[4]);
                           for (n=0;n<make16(in_data[1],in_data[2]);n++)
                           {
                              set_timer3(0);
                              adcData[n] = READ_ADC();
                              while (get_timer3() * 2/3 < approxUS);   // 1000000/((clock/4)/8)
                           }
                           out_data[0] = usbConfirmAction;
                           out_data[1] = usbReadADCnTimesUS;
                           out_data[2] = in_data[1];
                           out_data[3] = in_data[2];
                           out_data[4] = in_data[3];
                           out_data[5] = in_data[4];
                        }
                        else {
                           out_data[0] = usbError;
                           out_data[1] = usbReadADCnTimesUS;
                           out_data[2] = in_data[1];
                           out_data[3] = in_data[2];
                           out_data[4] = in_data[3];
                           out_data[5] = in_data[4];
                        }
                     }
                     break;
                  case usbReadADCnTimesMS: {
                        if (make16(in_data[1],in_data[2]) <= theSampleSize) {
                           approxMS = make16(in_data[3],in_data[4]);
                           for (n=0;n<make16(in_data[1],in_data[2]);n++)
                           {
                              set_timer3(0);
                              adcData[n] = READ_ADC();
                              while (get_timer3() * 1/1500 < approxMS);   // 1000/((clock/4)/8)
                           }
                           out_data[0] = usbConfirmAction;
                           out_data[1] = usbReadADCnTimesMS;
                           out_data[2] = in_data[1];
                           out_data[3] = in_data[2];
                           out_data[4] = in_data[3];
                           out_data[5] = in_data[4];
                        }
                        else {
                           out_data[0] = usbError;
                           out_data[1] = usbReadADCnTimesMS;
                           out_data[2] = in_data[1];
                           out_data[3] = in_data[2];
                           out_data[4] = in_data[3];
                           out_data[5] = in_data[4];
                        }
                     }
                     break;
                  case usbClearRam: {
                        for (n=0;n<512;n++)
                        {
                           adcData[n] = 0;
                        }
                        out_data[0] = usbConfirmAction;
                        out_data[1] = usbClearRam;
                     }
                     break;
                  case usbSetRamByte: {
                        for (n=0;n<512;n++)
                        {
                           adcData[n] = in_data[1];
                        }
                        out_data[0] = usbConfirmAction;
                        out_data[1] = usbSetRamByte;
                        out_data[2] = in_data[1];
                     }
                     break;
                  case usbSetUseCRC: {
                        useCRC = true;
                        out_data[0] = usbConfirmAction;
                        out_data[1] = usbSetUseCRC;
                     }
                     break;
                  case usbClearUseCRC: {
                        useCRC = false;
                        out_data[0] = usbConfirmAction;
                        out_data[1] = usbClearUseCRC;
                     }
                     break;
               }
               if (useCRC) {
                  theCRC = 0;
                  theCRC = calc_crc(theCRC,out_data[0]);
                  theCRC = calc_crc(theCRC,out_data[1]);
                  theCRC = calc_crc(theCRC,out_data[2]);
                  theCRC = calc_crc(theCRC,out_data[3]);
                  theCRC = calc_crc(theCRC,out_data[4]);
                  theCRC = calc_crc(theCRC,out_data[5]);
                  theCRC = calc_crc(theCRC,out_data[6]);
                  out_data[7] = theCRC;
               }

               usb_put_packet(1, out_data, 8, USB_DTS_TOGGLE);
            }

            delay_ms(1);
         }
      }
   }
}

