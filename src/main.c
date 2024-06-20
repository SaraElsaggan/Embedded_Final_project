//#include <avr/io.h>
// #include <avr/interrupt.h>
// #include <avr/wdt.h>
#include <util/delay.h>
#include "WDGDRV.h"
#include <avr/wdt.h>
#include <avr/interrupt.h>

int x = 0;

ISR(WDT_vect) {
    x = 1;
    PORTB |= (1 << 0); // Set PB0 high
    for ( volatile uint32 i = 0; i < 10000000000; i++) {/* Delay loop*/}
    // _delay_ms(1000); 
    WDTCSR = (1 << WDIE); 
}

void WDGDrv_Init(void) {
    DDRB |= (1 << 0);
    PORTB &= ~(1 << 0);
    cli();// Disable global interrupts
    // SREG &= ~(1 << I);
    // wdt_enable(2);
    WDTCSR = (1 << WDCE) | (1 << WDE);// Set the Watchdog change enable bit and Watchdog system reset enable bit in one operation
    WDTCSR =  (1 << WDE)|(1 << WDIE) | (1 << WDP1);    // Set the prescaler to 64 seconds and enable the Watchdog interrupt
    sei(); // Enable global interrupts
    // SREG |= (1 << I);
}

int main(void) {
    DDRB |= (1 << 0);    // Set PB0 as output for the LED
    PORTB &= ~(1 << 0);  // Ensure the LED is initially off
    WDGDrv_Init();
    // Main loop
    while (1) {
    }

    return 0;
}
