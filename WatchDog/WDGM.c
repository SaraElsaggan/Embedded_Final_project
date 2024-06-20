#include "WDGM.h"
#include "Std_Types.h"


#define MF_Delay_Period 20
#define MF_Duration_Period 100
static uint8 call_count;

static WDGM_StatusType status;
static uint32 led_no_calls;
static uint32 check_time ;
// uint32 last_execution_time;

void WDGM_Init(void)
{
    status = NOK ;
    led_no_calls = 0;
    call_count = 0;
    //last_execution_time = currenttime;
}

void WDGM_MainFunction(void)
{
    call_count ++;
    // Check LEDM calls periodicity every 100ms (5 * 20ms = 100ms)
    if (call_count <= 6) {
        call_count = 0; // Reset count for next period
        // Check number of LEDM calls in last 100ms
        if (led_no_calls >= 8 && led_no_calls <= 12) // check no. of calls is between 8 and 12 or not
        { 
            status = OK;
        } else {
            status = NOK;
        }
        led_no_calls = 0; // Reset the call counter for the next 100ms period
    }
    
    // last_execution_time = current_time;
}




WDGM_StatusType WDGM_PovideSuppervisionStatus(void)
{
    return status; // The WDGM state
}




void WDGM_AlivenessIndication(void)
{
	led_no_calls++; // increment correct calls counter each time LEDM_Manage is called this
}
