
#include "LEDM.h"
#include "Std_Types.h"
#include "GPIO.h"
#include "stm32f4xx_hal.h"
#include "WDGM.h" 
#include <stdlib.h>

uint32 starting_time;
uint32 current_time;


static uint8 led_state;


void LEDM_Init(void)
{
    GPIO_Init();
    led_state = 0;
    starting_time = HAL_GetTick();
}

void LEDM_Manage(void)
{
	current_time = HAL_GetTick();

	if (abs(current_time - starting_time) >= 500)
    {
    starting_time = HAL_GetTick(); // the start time from the last toggling of state
    led_state = ~led_state;
    GPIO_Write(LED_PIN_ID, led_state);
    }
    WDGM_AlivenessIndication(); // to count the number of function calls
}
