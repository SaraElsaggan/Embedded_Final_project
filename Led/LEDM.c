
#include "LEDM.h"
#include "Std_Types.h"
#include "GPIO.h"
#include "stm32f4xx_hal.h"
#include "WDGM.h"

static uint8 led_state;

void LEDM_Init(void)
{
    GPIO_Init();
    led_state = 0;
}

void LEDM_Manage(void)
{
    HAL_Delay(500);
    led_state = ~led_state;
    GPIO_Write(LED_PIN_ID, led_state);
    WDGM_AlivenessIndication(); // to count the number of function calls
}
