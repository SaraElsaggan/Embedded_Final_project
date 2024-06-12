#include <stdio.h>
#include <stdlib.h>
#include "stm32f4xx_hal.h"
#include "RCC.h"
#include "GPIO.h"
#include "WDGDRV.h"
#include "WDGM.h"
#include "LEDM.h"
#include <stdint.h>


static void delay(uint32 time){

    volatile uint32 i;
    time *= 1000;
    // watchdog_refresh();
    for ( i = 0 ; i<time;i++){
    // refresh();
    // WDG->CR |= 0xFF;



    }
    // watchdog_refresh();
}

int main(void){


    Rcc_Init();
    HAL_Init();
	Rcc_Enable(RCC_GPIOB);
	Rcc_Enable(RCC_WWDG);

//    initialization.
    LEDM_Init();
    WDGM_Init();
    // WDGDrv_Init();

    uint32 counter;

    while (1) {
        // Call LEDM_Manage every 10ms
        // counter = WDG->CR & 0x7F;
        //printf("WWDG Counter Value: %lu\n", counter);

    	delay(10);
    	// HAL_Delay(10);  
        LEDM_Manage();

        // Call WDGM_MainFunction every 20ms
        delay(20);
        // HAL_Delay(20);
        WDGM_MainFunction();

    }
    return 0;
}
