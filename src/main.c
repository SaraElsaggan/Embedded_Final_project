#include <stdio.h>
#include <stdlib.h>
#include "stm32f4xx_hal.h"
#include "RCC.h"


int main(void){

    Rcc_Init();
    HAL_Init();
	Rcc_Enable(RCC_GPIOB);
	Rcc_Enable(RCC_WWDG);

    //initialization.
    LEDM_Init();
    WDGDrv_Init();
    WDGM_Init();

    while (1) {
        // Call LEDM_Manage every 10ms
        HAL_Delay(10);
        LEDM_Manage();

        // Call WDGM_MainFunction every 20ms
        HAL_Delay(20);        
        WDGM_MainFunction();

    }
    return 0;
}
