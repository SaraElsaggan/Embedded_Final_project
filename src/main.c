//#include <avr/io.h>
// #include <avr/interrupt.h>
// #include <avr/wdt.h>
#include "WDGDRV.h"

static void delay(uint32 time){
    volatile uint32 i;
    time *= 1000;
    for ( i = 0 ; i<time;i++){}
}

int main(void) {
    // Set PB0 as output for the LED
    DDRB |= (1 << 0);
    PORTB &= ~(1 << 0);  // Ensure the LED is initially off
    WDGDrv_Init();
    // LEDM_Init();
    // WDGM_Init();
    // Main loop
    while (1) {
        // delay(10);
        // LEDM_Manage();

        // // Call WDGM_MainFunction every 20ms
        // delay(20);
        // WDGM_MainFunction();
    }

    return 0;
}
