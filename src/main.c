#include <avr/io.h>
// #include <avr/interrupt.h>
// #include <avr/wdt.h>
#include "WDGDRV.h"



int main(void) {
    // Set PB0 as output for the LED
    DDRB |= (1 << PB0);
    PORTB &= ~(1 << PB0);  // Ensure the LED is initially off
    WDGDrv_Init();

    // Main loop
    while (1) {
    }

    return 0;
}
