// #include "WDGDRV.h"
#include <util/delay.h>
#include <GPIO.h>
#include <LEDM.h>
#include <WDGM.h>
#include "WDGDRV.h"

//  #include <avr/io.h>
 #include "Std_Types.h"
//  #include "Gpio_Private.h"

uint32 call_count_100_ms = 0;
uint32 call_count_50_ms = 0;

int SysInit(void) {
    DDRB |= (1 << 0);
    DDRB |= (1 << 3);
    DDRB |= (1 << 2);
    PORTB &= ~(1 << 0);
    GPIO_Init();
    LEDM_Init();
    WDGM_Init();
    WDGDrv_Init();
    
}

static uint8 isFirstIteration = 1;
int main(void) {    
    SysInit();
    // PORTB |= (1 <<0);
    static uint8 WDGCounter = 0;
    // Main loop
    while (1) {
        _delay_ms(10); // wait for 10ms to call LEDM_Manage again 
        // _delay_ms(5); // wait for 5ms to call LEDM_Manage again 
        LEDM_Manage();          
        // wait until 20ms timing for WDGM_MainFunction (even iterations) 
        // WDGCounter += 5; // Increment by the delay amount (5ms)
        WDGCounter += 10; // Increment by the delay amount (10ms)
        if (WDGCounter >= 20) {
            WDGM_MainFunction();  // Call watchdog management every 20ms
            call_count_100_ms +=20;
            call_count_50_ms ++;
            WDGCounter = 0; // Reset count after calling WDGM_MainFunction()
        }
    }
    return 0;
}
