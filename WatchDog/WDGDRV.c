#include "WDGDRV.h"
#include "WDGM.h"
#include "Std_Types.h"
#include <avr/wdt.h>
#include <avr/interrupt.h>
#include <avr/io.h>

extern stuck;
extern wdg_call_count_within_50_ms;
uint32 is_reset = 0;

ISR(TIMER1_COMPA_vect)
{
    WDGDrv_IsrNotification();
    PORTB ^= (1 << 5);

}

// void WDGDrv_Init(void)
// {
//     // cli();                             // Enable global interrupts
//     // configure the timer
//     TCCR1B |= (1 << WGM12);
//     // OCR1A = 780;
//     OCR1A = 815;
//     // Set the prescaler to 64
//     TCCR1B |= (1 << CS11) | (1 << CS10);
//     // Enable Timer Compare Interrupt
//     TIMSK1 |= (1 << OCIE1A);

//     // wdt_reset();
//     // MCUSR &= ~(1<<3);
//     // WDTCSR = 0x00;
//     WDTCSR = (1 << WDCE) | (1 << WDE); // Set the Watchdog change enable bit and Watchdog system reset enable bit in one operation
//     WDTCSR = (1 << WDE) | (1 << WDP1)  ; // Set the prescaler to 64 seconds and enable the Watchdog interrupt
//     // WDTCSR = (1 << WDIE) ; // Set the prescaler to 64 seconds and enable the Watchdog interrupt
//     // sei();                             // Enable global interrupts
//         // WDTCSR = (1 << WDE) | (1 << WDP2) | (1 << WDP1); // Set the watchdog to approximately 0.5 seconds
//     SREG |= (1 << I);
// }


void WDGDrv_Init(void)
{
	/*Disable global interrupts*/
	SREG &= ~(1 << I);

	/*reset the timer*/
	wdt_reset();

	// Clear the watchdog reset flag
	MCUSR &= (~(1 << WDRF));

	/*set the watchdog change enable and system reset enable to 1 in the same instruction before making any changes, page 44*/
	WDTCSR |= (1 << WDCE) | (1 << WDE);

	/*enable system reset mode
	 * Set maximum time-out value = 8K cycles (~64 ms) by seting the watchdog timer prescale pins to 0010
	 */
	WDTCSR = (1 << WDE) | (1 << WDP1);

	/*Normal port operation, OC1A/OC1B disconnected
	 * CTC mode*/
	TCCR1A = 0;

	/*CTC mode
	 * 64ms prescale*/
	TCCR1B = (1 << WGM12) | (1 << CS11) | (1 << CS10);

	/* Set the compare value which achieves 50 ms timer
	 * compare value (no of pulses needed to reach the timeout) = (desired time/ time of one pulse) -1
	 * time of one pulse= ( prescale)/ freq of the clock
	 * */
	OCR1A = 815;

	// Enable timer1 output compare A match interrupt
	TIMSK1 = (1 << OCIE1A);

	/*enable global interrupts by setting pinI in the AVR status register to 1*/
	SREG |= (1 << I);

}


void WDGDrv_IsrNotification(void)
{

		WDGM_StatusType wdgmStatus = WDGM_PovideSuppervisionStatus();
		uint8 check  = ((!wdgmStatus) && (!stuck)); 

        if (check)
        {
            wdt_reset();
            PORTB ^= (1 << 4); // to indicate the perodicity refreshment of the wdt
			is_reset++;
        }
        else{
            wdt_enable(WDTO_15MS);
        }


}
