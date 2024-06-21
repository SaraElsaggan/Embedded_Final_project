#include "WDGDRV.h"
#include <util/delay.h>
#include <GPIO.h>
#include <LEDM.h>
#include <WDGM.h>


uint32 call_count = 0;

int SysInit(void) {
    DDRB |= (1 << 0);
    PORTB &= ~(1 << 0);
    GPIO_Init();
    LEDM_Init();
    WDGM_Init();
    WDGDrv_Init();
}

int main(void) {
    SysInit();
    static uint8 WDGCounter = 0;

    // Call WDGM_MainFunction for the first time
    WDGM_MainFunction();
    // Main loop
    while (1) {
        LEDM_Manage();
        _delay_ms(10); // wait for 10ms to call LEDM_Manage again 

        // wait until 20ms timing for WDGM_MainFunction (even iterations) 
        WDGCounter += 10; // Increment by the delay amount (10ms)
        if (WDGCounter >= 20) {
            WDGM_MainFunction();  // Call watchdog management every 20ms
            call_count ++;
            WDGCounter = 0; // Reset count after calling WDGM_MainFunction()
        }
    }
    return 0;
}