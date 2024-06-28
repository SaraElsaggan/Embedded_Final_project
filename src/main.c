// // #include "WDGDRV.h"
// #include <GPIO.h>
// #include <LEDM.h>
// #include <WDGM.h>
// #include "WDGDRV.h"
// #include <avr/interrupt.h>
// #include <avr/io.h>
// #include "Std_Types.h"

// volatile unsigned long current_time = 0;
// volatile unsigned long time_at_last_10ms = 0;
// static uint8 WDGCounter = 0;

// #define DDRB  (*(volatile uint8_t *)0x24)

// void Timer0_Init(void)
// {
//         TCCR0A = (1 << WGM01);              // Config the timer
//         OCR0A = 15;                         // Set compare value for 1ms interrupt
//         TIMSK0 = (1 << OCIE0A);             // Enable Timer Compare Interrupt
//         TCCR0B = (1 << CS01) | (1 << CS00); // Set prescaler to 64 and start Timer0
//         SREG |= (1 << I);
//     }

// ISR(TIMER0_COMPA_vect)
// {
//     current_time++; // Increment the time variable every 1ms
// }

// void SysInit(void)
// {    
//     // PORTB &= ~(1 << 0);
//     LEDM_Init();
//     WDGM_Init();
//     Timer0_Init();
// }

// int main(void)
// {
//     DDRB |= (1 << 0); // reset

//     PORTB |= (1 << 0); // to monitor the system reset
//     SysInit();
//     while (1)
//     {
// //         if ((current_time - time_at_last_10ms) >= 5)
//         if ((current_time - time_at_last_10ms) >= 10)
//         {
//             time_at_last_10ms = current_time;
//             LEDM_Manage();
//             WDGCounter += 10;
//              WDGCounter += 5;
//             if (WDGCounter >= 20)
//             {
//                 WDGCounter = 0;      // Reset count after calling WDGM_MainFunction()
//                WDGM_MainFunction(); // Call watchdog management every 20ms
//             }
//         }
//     }

//     return 0;
// }


#include <util/delay.h>
#include <GPIO.h>
#include <LEDM.h>
#include <WDGM.h>
#include "WDGDRV.h"

//  #include <avr/io.h>
 #include "Std_Types.h"
//  #include "Gpio_Private.h"
#define DDRB  (*(volatile uint8_t *)0x24)



void SysInit(void)
{    
    // PORTB &= ~(1 << 0);
    LEDM_Init();
    WDGM_Init();
    // Timer0_Init();
}



int main(void) {    
     DDRB |= (1 << 0); // reset

    PORTB |= (1 << 0); // to monitor the system reset
    SysInit();
    static uint8 WDGCounter = 0;

    // Main loop
    while (1) {
        _delay_ms(10);
        // _delay_ms(5);
        LEDM_Manage();          // wait for 10ms to call LEDM_Manage again 

        // wait until 20ms timing for WDGM_MainFunction (even iterations) 
        // WDGCounter += 5; // Increment by the delay amount (5ms)
        WDGCounter += 10; // Increment by the delay amount (10ms)
        if (WDGCounter >= 20) {
            WDGM_MainFunction();  // Call watchdog management every 20ms
            WDGCounter = 0; // Reset count after calling WDGM_MainFunction()
        }
    }
    return 0;
}