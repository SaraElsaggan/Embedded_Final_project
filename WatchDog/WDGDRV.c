#include "WDGDRV.h"
#include "WDGM.h"
#include "Std_Types.h"
#include <avr/wdt.h>
#include <avr/interrupt.h>
#include <avr/io.h>

extern stuck;
uint32 is_reset = 0;

ISR(TIMER1_COMPA_vect)
{
    WDGDrv_IsrNotification();
    PORTB ^= (1 << 5); // to indicate the timer => 50ms
}

void WDGDrv_Init(void)
{
	SREG &= ~(1 << I); //Disable global interrupts
    WDTCSR |= (1 << WDCE) | (1 << WDE); // Set the Watchdog change enable bit and Watchdog system reset enable bit in one operation
    WDTCSR = (1 << WDE) | (1 << WDP1)  ; // Set the prescaler to 64 seconds and enable the Watchdog interrupt

    // CONFIG THE TIMER :
    TCCR1B |= (1 << WGM12); //CTC mode
	TCCR1B |= (1 << CS11) | (1 << CS10); // Set the prescaler to 64

	// to achieve 50 ms timer => f_OCnA = f_clk_I/O / (2 * N * (1 + OCRnA)) 
	
	OCR1A = 815; // realize it from proteus
	// OCR1A = 780; //datasheet

	TIMSK1 |= (1 << OCIE1A); // Enable Timer Compare Interrupt
    SREG |= (1 << I); //enable global interrupts 
}

void WDGDrv_IsrNotification(void)
{

		WDGM_StatusType wdgmStatus = WDGM_PovideSuppervisionStatus();
		uint8 check  = ((!wdgmStatus) && (!stuck)); 

        if (check)
        {
            wdt_reset();
            PORTB ^= (1 <<1); // to indicate the perodicity refreshment of the wdt
			is_reset++;
        }
        else{
			// leave it to reset
            wdt_enable(WDTO_15MS);
        }


}
