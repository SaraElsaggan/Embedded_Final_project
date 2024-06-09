#include "WDGM.h"
#include "Std_Types.h"
#include "stm32f4xx_hal.h"

static WDGM_StatusType status;
static uint32 led_no_calls;
static uint32 start_time;
uint32 last_execution_time;

void WDGM_Init(void)
{
    status = NOK ;
    led_no_calls = 0;
    start_time = HAL_GetTick();
    start_time = 0;
    last_execution_time = HAL_GetTick(); 

}

void WDGM_MainFunction(void)
{
    uint32 current_time = HAL_GetTick(); // get current time value using hal lib in stm32f4xx_hal
    if ((current_time - start_time) <= 100) // check if it's within 100ms
    {
        if (led_no_calls >= 8 && led_no_calls <= 12) { // check no. of calls is between 8 and 12 or not
            status = OK;
        } else {
            status = NOK;
        }
        led_no_calls = 0; // Reset the call counter for the next 100ms period
        start_time = current_time; // update start time for the next 100ms period
    }
    last_execution_time = current_time;
}

WDGM_StatusType WDGM_PovideSuppervisionStatus(void)
{
    return status; // The WDGM state
}

void WDGM_AlivenessIndication(void)
{
	led_no_calls++; // increment correct calls counter each time LEDM_Manage is called this
}
