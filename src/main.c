#include <avr/io.h>
#include <avr/interrupt.h>

int x = 0;
ISR(WDT_vect) {
    x = 1;
    PORTB |= (1 << PB0); // Set PB0 high
    WDTCSR = (1 << WDIE);
}

void WDGDrv_Init(void) {
    // Disable global interrupts
    cli();
    //Interrupt and System Reset Mode
    WDTCSR = (1 << WDCE) | (1 << WDE);// Set the Watchdog change enable bit and Watchdog system reset enable bit in one operation
    WDTCSR =  (1 << WDE)|(1 << WDIE) | (1 << WDP1);    // Set the prescaler to 64 seconds and enable the Watchdog interrupt
    sei(); // Enable global interrupts
}

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
