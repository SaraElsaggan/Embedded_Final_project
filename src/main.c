#include <avr/io.h>
#include <avr/interrupt.h>

void setup() {
    // Set CTC mode
    TCCR1A = 0; // Clear Timer/Counter Control Register A
    TCCR1B = 0; // Clear Timer/Counter Control Register B
    TCCR1B |= (1 << WGM12); // Set CTC mode (WGM12: Waveform Generation Mode bit 12)
    
    // Set the compare match value for 50ms
    OCR1A = 12499; // Compare match register value (16MHz / (64 * (12499 + 1)) = 50Hz)
    
    // Set the prescaler to 64
    TCCR1B |= (1 << CS11) | (1 << CS10); // CS11 and CS10 bits set to 1: Prescaler = 64
    
    // Enable the Timer1 compare match interrupt
    TIMSK1 |= (1 << OCIE1A); // Output Compare A Match Interrupt Enable
    
    // Set PB0 as an output pin
    DDRB |= (1 << DDB0);
    
    // Enable global interrupts
    sei();
}

// ISR to be called every 50ms
ISR(TIMER1_COMPA_vect) {
    // Toggle the LED on PB0
    PORTB ^= (1 << PORTB0);
}

int main(void) {
    setup(); // Call the setup function
    
    while (1) {
        // Main loop does nothing, all work is done in ISR
    }
    
    return 0; // Although this line will never be reached
}
