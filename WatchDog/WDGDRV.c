#include "WDGDRV.h"
#include "WDGM.h"
#include "Std_Types.h"
#include <avr/wdt.h>
#include <avr/interrupt.h>
#include <avr/io.h>

extern stuck;
extern call_count_50_ms;
uint32 tgrbaa = 0;

ISR(TIMER1_COMPA_vect)
{
    WDGDrv_IsrNotification();
}

void WDGDrv_Init(void)
{
    cli();                             // Enable global interrupts
    // configure the timer
    TCCR1B |= (1 << WGM12);
    OCR1A = 779;
    // Set the prescaler to 64
    TCCR1B |= (1 << CS11) | (1 << CS10);
    // Enable Timer Compare Interrupt
    TIMSK1 |= (1 << OCIE1A);

    // wdt_reset();
    // MCUSR &= ~(1<<3);
    // WDTCSR = 0x00;
    WDTCSR = (1 << WDCE) | (1 << WDE); // Set the Watchdog change enable bit and Watchdog system reset enable bit in one operation
    WDTCSR = (1 << WDE) | (1 << WDP1)  ; // Set the prescaler to 64 seconds and enable the Watchdog interrupt
    // WDTCSR = (1 << WDIE) ; // Set the prescaler to 64 seconds and enable the Watchdog interrupt
    // sei();                             // Enable global interrupts
        // WDTCSR = (1 << WDE) | (1 << WDP2) | (1 << WDP1); // Set the watchdog to approximately 0.5 seconds
    SREG |= (1 << I);
}


void WDGDrv_IsrNotification(void)
{
        // check call_count(times WDGM_MainFunction is called) is 2 or more
        if (call_count_50_ms >= 2)
        {
            stuck = 0;            // The function is not stuck
            call_count_50_ms = 0; // Reset for the next 50ms period
        }
        else
        {
            stuck = 1; // The function might be stuck
        }
        if (WDGM_PovideSuppervisionStatus() == OK && (!stuck))
        {
            wdt_reset();
            PORTB ^= (1 << 0); // to indicate the perodicity refreshment of the wdt
        }
        else
        {
            tgrbaa = 2;
            // leave the wdt to reset 
            return;
        }
}