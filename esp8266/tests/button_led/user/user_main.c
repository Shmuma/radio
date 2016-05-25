#include "ets_sys.h"
#include "osapi.h"
#include "gpio.h"
#include "os_type.h"
#include "user_interface.h"

#define user_procTaskPrio        0
#define user_procTaskQueueLen    1
os_event_t    user_procTaskQueue[user_procTaskQueueLen];

// gpio interrupt handler. See below
LOCAL void  gpio_intr_handler(int * dummy);

//-------------------------------------------------------------------------------------------------
//Init function
void ICACHE_FLASH_ATTR  user_init()
{

    uart_div_modify(0, UART_CLK_FREQ / 9600);

    os_printf("GPIO Interrupt ESP8266 test\r\n"
              "---------------------------\r\n"
              "  This program drives led on GPIO2 according to button on GPIO0\r\n");

    gpio_init();

    PIN_FUNC_SELECT(PERIPHS_IO_MUX_GPIO0_U, FUNC_GPIO0);
    PIN_FUNC_SELECT(PERIPHS_IO_MUX_GPIO2_U, FUNC_GPIO2);

    PIN_PULLUP_EN(PERIPHS_IO_MUX_GPIO0_U);
    PIN_PULLUP_DIS(PERIPHS_IO_MUX_GPIO2_U);

    gpio_output_set(0, GPIO_ID_PIN(2), GPIO_ID_PIN(2), GPIO_ID_PIN(0)); // set gpio 2 as output and low. set gpio 0 as input

    ETS_GPIO_INTR_DISABLE();
    ETS_GPIO_INTR_ATTACH(gpio_intr_handler, NULL);

    gpio_register_set(GPIO_PIN_ADDR(0),
                      GPIO_PIN_INT_TYPE_SET(GPIO_PIN_INTR_DISABLE)  |
                      GPIO_PIN_PAD_DRIVER_SET(GPIO_PAD_DRIVER_DISABLE) |
                      GPIO_PIN_SOURCE_SET(GPIO_AS_PIN_SOURCE));

    GPIO_REG_WRITE(GPIO_STATUS_W1TC_ADDRESS, BIT(0));
    gpio_pin_intr_state_set(GPIO_ID_PIN(0), GPIO_PIN_INTR_POSEDGE);
    ETS_GPIO_INTR_ENABLE();
}

//-------------------------------------------------------------------------------------------------
// interrupt handler
// this function will be executed on any edge of GPIO0
LOCAL void  gpio_intr_handler(int * dummy)
{
    uint32 gpio_status = GPIO_REG_READ(GPIO_STATUS_ADDRESS);

    if (gpio_status & BIT(0))
    {
        static int level = 0;

        GPIO_OUTPUT_SET(GPIO_ID_PIN(2), ((level) ? 1 : 0));
        level = !level;

        // clear interrput status
        gpio_pin_intr_state_set(GPIO_ID_PIN(0), GPIO_PIN_INTR_DISABLE);
        GPIO_REG_WRITE(GPIO_STATUS_W1TC_ADDRESS, gpio_status & BIT(0));
        gpio_pin_intr_state_set(GPIO_ID_PIN(0), GPIO_PIN_INTR_POSEDGE);
        os_printf("Interrupt, level=%d\r\n", level);
    }
}

