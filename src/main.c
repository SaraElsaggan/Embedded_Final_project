#include "WDGDRV.h"
#include <util/delay.h>

#include <GPIO.h>
#include <LEDM.h>
#include <WDGM.h>


int main(void) {
    // Set PB0 as output for the LED
    DDRB |= (1 << 0);
    PORTB &= ~(1 << 0);  // Ensure the LED is initially off
    // WDGDrv_Init();
    LEDM_Init();
    WDGM_Init();

    // Call WDGM_MainFunction for the first time
    WDGM_MainFunction();
    static uint8 WDGCounter = 0;
    // Main loop
    while (1) {
        LEDM_Manage();
        _delay_ms(10); // wait for 10ms to call LEDM_Manage again 

        // wait until 20ms timing for WDGM_MainFunction (even iterations) 
        WDGCounter += 10; // Increment by the delay amount (10ms)
        if (WDGCounter >= 20) {
            WDGM_MainFunction();  // Call watchdog management every 20ms
            WDGCounter = 0; // Reset count after calling WDGM_MainFunction()
        }
    }
    return 0;
}
