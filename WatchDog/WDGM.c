#include "WDGM.h"
#include "Std_Types.h"

static WDGM_StatusType status;
static stuckType stuck;
static volatile uint32 led_no_calls;
// uint8 stuck;
extern call_count;

void WDGM_Init(void)
{
    status = OK ;
    led_no_calls = 0;
    stuck = m4_eshta;
}

void WDGM_MainFunction(void)
{
    // call_count ++;
    // Check LEDM calls periodicity every 100ms (5 * 20ms = 100ms) first call-> time = 0ms 
    stuck = eshta;
    if (call_count <= 5) {
        // Check number of LEDM calls within 100ms
        if (led_no_calls >= 8 && led_no_calls <= 12) // check no. of calls is between 8 and 12 or not
        { 
            status = OK;
        } else {
            status = NOK;
        }
    }else{
        led_no_calls = 0; // Reset the call counter for the next 100ms period
        call_count = 1;
    }
 
    stuck = m4_eshta;
}



WDGM_StatusType WDGM_PovideSuppervisionStatus(void)
{
    return status; // The WDGM state
}



void WDGM_AlivenessIndication(void)
{
	led_no_calls++; // increment correct calls counter each time LEDM_Manage is called this
}