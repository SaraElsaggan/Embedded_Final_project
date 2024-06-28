#include "WDGM.h"
#include "WDGDrv.h"
#include "Std_Types.h"
#include <avr/wdt.h>

static WDGM_StatusType status;
static uint32 wdg_call_count_within_100_ms;
static volatile uint32 led_no_calls;
uint32 stuck;

void WDGM_Init(void)
{
    WDGDrv_Init();
    status = OK;
    led_no_calls = 0;
    stuck = 1;
    wdg_call_count_within_100_ms = 0;
}

void WDGM_MainFunction(void)
{
    stuck = 1;
    wdg_call_count_within_100_ms++;
    PORTB ^= (1 << 3);  // to indicate the perodicity of the function (20ms)
    if(wdg_call_count_within_100_ms >= 5) // 5 * 20 == 100 ms
    {
        PORTB ^= (1 << 6); // to indicate the perodicity of the function(within 100ms)
        if (((led_no_calls >= 8) && (led_no_calls <= 12))) // check no. of calls is between 8 and 12 or not
        {
            status = OK;
        }
        else
        {
            status = NOK;
        }
        led_no_calls = 0; // Reset the led_no_calls for the next 100ms period
        wdg_call_count_within_100_ms = 0;   // return the wdg_call_count_within_100_ms for the next 100ms period
    }
    
    stuck = 0;

}


WDGM_StatusType WDGM_PovideSuppervisionStatus(void)
{
    return status; // The WDGM state
}


void WDGM_AlivenessIndication(void)
{
    led_no_calls++; // increment correct calls counter each time LEDM_Manage is called this
}
