#ifndef __USB_DESCRIPTORS__
#define __USB_DESCRIPTORS__

#include <usb.h>

#define USB_USE_FULL_SPEED TRUE

const char USB_CLASS_SPECIFIC_DESC[] = {
    6, 0, 255,    // Usage Page = Vendor Defined
    9, 1,            // Usage = IO device
    0xa1, 1,       // Collection = Application
    0x19, 1,        // Usage minimum
    0x29, 8,        // Usage maximum

    0x15, 0x80,        // Logical minimum (-128)
    0x25, 0x7F,        // Logical maximum (127)

    0x75, 8,        // Report size = 8 (bits)
    0x95, 8,        // Report count = 8 bytes
    0x81, 2,        // Input (Data, Var, Abs)
    0x19, 1,        // Usage minimum
    0x29, 8,        // Usage maximum
    0x75, 8,        // Report size = 8 (bits)
    0x95, 8,        // Report count = 8 bytes
    0x91, 2,        // Output (Data, Var, Abs)
    0xc0            // End Collection
};


const int16 USB_CLASS_SPECIFIC_DESC_LOOKUP[USB_NUM_CONFIGURATIONS][1] =
{
    //config 1
    //interface 0
    0
};

const int16 USB_CLASS_SPECIFIC_DESC_LOOKUP_SIZE[USB_NUM_CONFIGURATIONS][1] =
{
    //config 1
    //interface 0
    32
};


#define USB_CONFIG_PID       0xd001   //changing this value may make the driver incompatible
#define USB_CONFIG_VID       0x04d8   //changing this value may make the driver incompatible
#define USB_CONFIG_VERSION   0x0100      //01.00  //range is 00.00 to 99.99

#define USB_CONFIG_BUS_POWER 500


   #DEFINE USB_TOTAL_CONFIG_LEN      32  //config+interface+class+endpoint

   const char USB_CONFIG_DESC[] = {
   //IN ORDER TO COMPLY WITH WINDOWS HOSTS, THE ORDER OF THIS ARRAY MUST BE:
      //    config(s)
      //    interface(s)
      //    class(es)
      //    endpoint(s)

   //config_descriptor for config index 1
         USB_DESC_CONFIG_LEN, //length of descriptor size          ==1
         USB_DESC_CONFIG_TYPE, //constant CONFIGURATION (CONFIGURATION 0x02)     ==2
         USB_TOTAL_CONFIG_LEN,0, //size of all data returned for this config      ==3,4
         1, //number of interfaces this device supports       ==5
         0x01, //identifier for this configuration.  (IF we had more than one configurations)      ==6
         0x00, //index of string descriptor for this configuration      ==7
         0x80, //bit 6=1 if self powered, bit 5=1 if supports remote wakeup (we don't), bits 0-4 unused and bit7=1         ==8
         USB_CONFIG_BUS_POWER/2, //maximum bus power required (maximum milliamperes/2)  (0x32 = 100mA)

   //interface descriptor 1
         USB_DESC_INTERFACE_LEN, //length of descriptor      =10
         USB_DESC_INTERFACE_TYPE, //constant INTERFACE (INTERFACE 0x04)       =11
         0x00, //number defining this interface (IF we had more than one interface)    ==12
         0x00, //alternate setting     ==13
         2, //number of endpoins, except 0 (pic167xx has 3, but we dont have to use all).       ==14
         0xFF, //class code, FF - vendor defined     ==15
         0xFF, //subclass code FF - vendor     ==16
         0xFF, //protocol code      ==17
         0x00, //index of string descriptor for interface      ==18

   //endpoint descriptor
         USB_DESC_ENDPOINT_LEN, //length of descriptor                   ==28
         USB_DESC_ENDPOINT_TYPE, //constant ENDPOINT (ENDPOINT 0x05)          ==29
         0x81, //endpoint number and direction (0x81 = EP1 IN)       ==30
         USB_ENABLE_INTERRUPT, //transfer type supported (0x03 is interrupt)         ==31
         USB_EP1_TX_SIZE,0x00, //maximum packet size supported                  ==32,33
      #if USB_USE_FULL_SPEED
         1,  //polling interval, in ms.  (cant be smaller than 10)      ==34
      #else
         10,  //polling interval, in ms.  (cant be smaller than 10)      ==34
      #endif

   //endpoint descriptor
         USB_DESC_ENDPOINT_LEN, //length of descriptor                   ==35
         USB_DESC_ENDPOINT_TYPE, //constant ENDPOINT (ENDPOINT 0x05)          ==36
         0x01, //endpoint number and direction (0x01 = EP1 OUT)      ==37
         0x03, //transfer type supported (0x03 is interrupt)         ==38
         USB_EP1_RX_SIZE & 0xFF,USB_EP1_RX_SIZE >> 8, //maximum packet size supported                  ==39,40
      #if USB_USE_FULL_SPEED
         1
      #else
         10 //polling interval, in ms.  (cant be smaller than 10)    ==41
      #endif
   };


   #define USB_NUM_HID_INTERFACES   0

   //the maximum number of interfaces seen on any config
   //for example, if config 1 has 1 interface and config 2 has 2 interfaces you must define this as 2
   #define USB_MAX_NUM_INTERFACES   1

   //define how many interfaces there are per config.  [0] is the first config, etc.
   const char USB_NUM_INTERFACES[USB_NUM_CONFIGURATIONS]={1};

   #if (sizeof(USB_CONFIG_DESC) != USB_TOTAL_CONFIG_LEN)
      #error USB_TOTAL_CONFIG_LEN not defined correctly
   #endif


   const char USB_DEVICE_DESC[USB_DESC_DEVICE_LEN] ={
      //starts of with device configuration. only one possible
         USB_DESC_DEVICE_LEN, //the length of this report   ==1
         0x01, //the constant DEVICE (DEVICE 0x01)  ==2
         0x10,0x01, //usb version in bcd (pic167xx is 1.1) ==3,4
         0x00, //class code ==5
         0x00, //subclass code ==6
         0x00, //protocol code ==7
         USB_MAX_EP0_PACKET_LENGTH, //max packet size for endpoint 0. (SLOW SPEED SPECIFIES 8) ==8
         USB_CONFIG_VID & 0xFF, ((USB_CONFIG_VID >> 8) & 0xFF), //vendor id       ==9, 10
         USB_CONFIG_PID & 0xFF, ((USB_CONFIG_PID >> 8) & 0xFF), //product id, don't use 0xffff       ==11, 12
         USB_CONFIG_VERSION & 0xFF, ((USB_CONFIG_VERSION >> 8) & 0xFF), //device release number  ==13,14
         0x01, //index of string description of manufacturer. therefore we point to string_1 array (see below)  ==15
         0x02, //index of string descriptor of the product  ==16
         0x00, //index of string descriptor of serial number  ==17
         USB_NUM_CONFIGURATIONS  //number of possible configurations  ==18
   };


char USB_STRING_DESC_OFFSET[]={0,4,12};

char const USB_STRING_DESC[]={
   //string 0
         4, //length of string index
         USB_DESC_STRING_TYPE, //descriptor type 0x03 (STRING)
         0x09,0x04,   //Microsoft Defined for US-English
   //string 1
         8, //length of string index
         USB_DESC_STRING_TYPE, //descriptor type 0x03 (STRING)
         'S',0,
         'H',0,
         'M',0,
   //string 2
         28, //length of string index
         USB_DESC_STRING_TYPE, //descriptor type 0x03 (STRING)
         'S',0,
         'h',0,
         'm',0,
         'u',0,
         'm',0,
         'a',0,
         ' ',0,
         'L',0,
         'C',0,
         'D',0,
         '-',0,
         'U',0,
         'S',0,
};


#endif /* __USB_DESCRIPTORS__ */
