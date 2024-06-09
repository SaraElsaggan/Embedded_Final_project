#include "WDGDRV.h"
#include "WDGM.h"
#include "WDGM.h"
#include "Rcc.h"
#include <stdint.h>

#include "Std_Types.h"



void WDGDrv_Init(void)
{
    // Rcc_Init(); // but this in the main
    Rcc_Enable(RCC_WWDG); 


    //set max timeout to be 50
    WWDG->CR &=~(0x3f);  // clear the t[5:0] bits 0011 1111
    // WWDG->CR |= (((APB1_freq*1000 * 50) / (4096 * 8) - 1 ) & 0x3F );  
    WWDG->CR |= (((30 *1000 * 50) / (4096 * 8) - 1 ) & 0x3F );  


    WWDG->CR |= (1<<7); // set bit 7 to activate the WWDG
    WWDG->CR |= (1<<6); // set bit 6 


    //enable the early interupt , make the WDGTB to 3 (look at table 64) , Disable window maode by making the window val = upper limit
    WWDG->CFR |=(0x3ff);

}


void WDGDrv_IsrNotification(void){
    uint32 current_time = HAL_GetTick();

    if(WDGM_PovideSuppervisionStatus()==NOK && (current_time - last_execution_time) < 100 /*&& the WDGM_MainFunction_is_not_STUCK*/){
       
        // refresh the watchdog
        // WWDG->CR |= ((30*1000 * 50) / (4096 * 2) - 1 );
        WWDG->CR |= 0x7F;
    }else{
        return;
    }
}