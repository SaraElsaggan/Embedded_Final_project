// #include "WDGDRV.h"
#include <GPIO.h>
#include <LEDM.h>
#include <WDGM.h>
#include "WDGDRV.h"
#include <avr/interrupt.h>
#include <avr/io.h>
#include "Std_Types.h"

uint32 wdg_call_count_within_100_ms = 0;
uint32 wdg_call_count_within_50_ms = 0;
volatile unsigned long current_time = 0;
volatile unsigned long time_at_last_10ms = 0;
uint32 stuck;

static uint8 WDGCounter = 0;


void Timer0_Init(void)
{
    // Config the timer 
    TCCR0A = (1 << WGM01);

    // Set compare value for 1ms interrupt
    OCR0A = 15;

    // Enable Timer Compare Interrupt
    TIMSK0 = (1 << OCIE0A);

    // Set prescaler to 64 and start Timer0 
    TCCR0B = (1 << CS01) | (1 << CS00);

    SREG |= (1 << I);
}

ISR(TIMER0_COMPA_vect)
{
	current_time++; // Increment the time variable every 1ms
}


void SysInit(void) {
    DDRB |= (1 << 0);  //reset
    DDRB |= (1 << 2);  // ledmange
    DDRB |= (1 << 3);  //WDG_main
    DDRB |= (1 << 4);  //refresh
    DDRB |= (1 << 5);  // timer
    DDRB |= (1 << 6);  // evey100ms
    DDRB |= (1 << 7);  // evey100ms
    PORTB &= ~(1 << 0);
    GPIO_Init();
    LEDM_Init();
    WDGM_Init();
    WDGDrv_Init();
    Timer0_Init();
}

int main(void) {    
    SysInit();
    PORTB |= (1 << 0); // to monitor the system reset     
    
    while (1) {

        if ((current_time - time_at_last_10ms) >= 5)
        {
            time_at_last_10ms = current_time;
            LEDM_Manage(); 
             WDGCounter+=5;

          if (WDGCounter >= 20) {
            // wdg_call_count_within_50_ms++;
            wdg_call_count_within_100_ms++;
            WDGCounter = 0; // Reset count after calling WDGM_MainFunction()
            stuck = 1;
            WDGM_MainFunction();  // Call watchdog management every 20ms
            }
        }


        // if ((current_time - time_at_last_10ms) >= 10)
        // {
        //     time_at_last_10ms = current_time;
        //     LEDM_Manage(); 
        //      WDGCounter++;

        //   if (WDGCounter >= 2) {
        //     // wdg_call_count_within_50_ms++;
        //     wdg_call_count_within_100_ms++;
        //     WDGCounter = 0; // Reset count after calling WDGM_MainFunction()
        //     stuck = 1;
        //     WDGM_MainFunction();  // Call watchdog management every 20ms
        //     }
        // }

        }

    return 0;
}
