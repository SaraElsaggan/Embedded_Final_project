#include "WDGDRV.h"
#include <util/delay.h>
#include <GPIO.h>
#include <LEDM.h>
#include <WDGM.h>


uint32 call_count_100_ms = 0;
uint32 call_count_50_ms = 0;

int SysInit(void) {
    DDRB |= (1 << 0);
    // DDRB |= (1 << 0);
    DDRB |= (1 << 2);
    DDRB |= (1 << 3);
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
    LEDM_Manage();
    WDGM_MainFunction();
    // Main loop
    while (1) {
        _delay_ms(10);
        LEDM_Manage();          // wait for 10ms to call LEDM_Manage again 

        // wait until 20ms timing for WDGM_MainFunction (even iterations) 
        WDGCounter += 10; // Increment by the delay amount (10ms)
        if (WDGCounter >= 20) {
            WDGM_MainFunction();  // Call watchdog management every 20ms
            call_count_100_ms ++;
            call_count_50_ms ++;
            WDGCounter = 0; // Reset count after calling WDGM_MainFunction()
        }
    }
    return 0;
}