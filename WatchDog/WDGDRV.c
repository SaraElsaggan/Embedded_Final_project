// #include "stm32l0xx.h" 
#include "WDGDRV.h"
#include "WDGM.h"
#include "Std_Types.h"
// #include <util/delay.h>
#include <avr/wdt.h>
#include <avr/interrupt.h>
#include <avr/io.h>






ISR(TIMER1_COMPA_vect) {
    PORTB ^= (1 << 0); // Set PB0 high
    wdt_reset(); // Reset the watchdog timer

    // for ( volatile uint32 i = 0; i < 10000000000; i++) {/* Delay loop*/}
    // _delay_ms(1000); 
    // WDTCSR = (1 << WDIE);
}

void WDGDrv_Init(void) {

    // cli();
    //configure the timer
    TCCR1B |= (1 << WGM12);

    // Set the value for a 50ms interval
    // Using a prescaler of 64: (16e6 / 64) = 250000 Hz Timer Frequency
    // 50ms = 0.05s, so OCR1A = 0.05 * 250000 = 12500 - 1 (subtract 1 because it starts from 0)
    OCR1A = 779;

    // Set the prescaler to 1024
    TCCR1B |= (1 << CS11) | (1 << CS10);

    // Enable Timer Compare Interrupt
    TIMSK1 |= (1 << OCIE1A);



    DDRB |= (1 << 0);
    PORTB &= ~(1 << 0);
    // Disable global interrupts
    // SREG &= ~(1 << I);
    //Interrupt and System Reset Mode
    // wdt_enable(2);
    WDTCSR = (1 << WDCE) | (1 << WDE);// Set the Watchdog change enable bit and Watchdog system reset enable bit in one operation
    WDTCSR =  (1 << WDE) | (1 << WDP1)     ;    // Set the prescaler to 64 seconds and enable the Watchdog interrupt
    sei(); // Enable global interrupts
    // SREG |= (1 << I);
// 
}


void WDGDrv_IsrNotification(void){
    // uint32 current_time = HAL_GetTick();

    if(WDGM_PovideSuppervisionStatus()==OK  /*&& the WDGM_MainFunction_is_not_STUCK*/){
       //refresh 
    }else{
        return;
    }
}


