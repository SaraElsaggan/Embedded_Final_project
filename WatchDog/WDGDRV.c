#include "WDGDRV.h"
#include "WDGM.h"
#include "Std_Types.h"
#include <avr/wdt.h>
#include <avr/interrupt.h>

extern stuck;

ISR(TIMER1_COMPA_vect) {
    PORTB ^= (1 << 0); // Set PB0 high
    WDGDrv_IsrNotification();
}

void WDGDrv_Init(void) {

    //configure the timer
    TCCR1B |= (1 << WGM12);
    OCR1A = 779;
    // Set the prescaler to 64
    TCCR1B |= (1 << CS11) | (1 << CS10);
    // Enable Timer Compare Interrupt
    TIMSK1 |= (1 << OCIE1A);

    WDTCSR = (1 << WDCE) | (1 << WDE);// Set the Watchdog change enable bit and Watchdog system reset enable bit in one operation
    WDTCSR =  (1 << WDE) | (1 << WDP1)     ;    // Set the prescaler to 64 seconds and enable the Watchdog interrupt
    sei(); // Enable global interrupts
}


void WDGDrv_IsrNotification(void){
    if(WDGM_PovideSuppervisionStatus()== OK  && (!stuck)){
        wdt_reset();
    }else{
        return;
    }
}


