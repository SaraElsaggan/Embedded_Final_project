#include "WDGDRV.h"
#include <util/delay.h>
#include <GPIO.h>
#include <LEDM.h>
#include <WDGM.h>
#include <avr/io.h>




int main(void) {
    // Set PB0 as output for the LED
	GPIO_Init();

    WDGDrv_Init();
    LEDM_Init();
    WDGM_Init();

    int counter = 1;
    LEDM_Manage();
    WDGM_MainFunction();
    while (1) {
         _delay_ms(10);         // Wait for 10 milliseconds
         LEDM_Manage();
         if (counter == 2)
         {
           WDGM_MainFunction();
           counter = 1;
         }
         counter++;

    }
    return 0;
}
