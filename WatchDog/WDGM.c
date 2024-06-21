#include "WDGM.h"
#include "Std_Types.h"
#include <avr/wdt.h>

static WDGM_StatusType status;
extern call_count_100_ms;
static volatile uint32 led_no_calls;
uint32 stuck;

void WDGM_Init(void)
{
    status = NOK;
    led_no_calls = 0;
    stuck = 0;
}

void WDGM_MainFunction(void)
{
    PORTB ^= (1 << 3); // to indicate the perodicity of the function
    // Check LEDM calls periodicity every 100ms (5 * 20ms = 100ms) first call-> time = 0ms
    if (call_count_100_ms <= 5)
    {
        // Check number of LEDM calls within 100ms
        if (led_no_calls >= 8 && led_no_calls <= 12) // check no. of calls is between 8 and 12 or not
        {
            status = OK;
        }
        else
        {
            status = NOK;
        }
    }
    else
    {
        led_no_calls = 0; // Reset the call counter for the next 100ms period
        call_count_100_ms = 1;   // return the call count for the next 100ms period
    }
}


WDGM_StatusType WDGM_PovideSuppervisionStatus(void)
{
    return status; // The WDGM state
}


void WDGM_AlivenessIndication(void)
{
    led_no_calls++; // increment correct calls counter each time LEDM_Manage is called this
}