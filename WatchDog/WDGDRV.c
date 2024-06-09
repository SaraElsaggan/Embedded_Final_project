#include "WDGDRV.h"
#include "WDGM.h"
#include "WDGM.h"
#include "Rcc.h"
#include <stdint.h>

#include "Std_Types.h"



// #define REG32(BASE_ADDR, OFFSET)  (*(volatile uint32 *)((BASE_ADDR) + (OFFSET)))

// #define WWDG_BASE_ADDRESS 0x40002C00
// #define WWDG_CTRL_REG REG32(WWDG_BASE_ADDRESS, 0x00)
// #define CONGIG_REG REG32(WWDG_BASE_ADDRESS, 0x04)

void WDGDrv_Init(void)
{
    // Rcc_Init(); // but this in the main
    Rcc_Enable(RCC_WWDG); 


    //set max timeout to be 50
    // uint32_t APB1_freq = HAL_RCC_GetPCLK1Freq();

    WWDG->CR &=~(0x3f);  // clear the t[5:0] bits 0011 1111
    // WWDG->CR |= (((APB1_freq*1000 * 50) / (4096 * 8) - 1 ) & 0x3F );  
    WWDG->CR |= (((30 *1000 * 50) / (4096 * 8) - 1 ) & 0x3F );  


    WWDG->CR |= (1<<7); // set bit 7 to activate the WWDG
    WWDG->CR |= (1<<6); // set bit 6 


    //enable the early interupt , make the WDGTB to 3 (look at table 64) , Disable window maode by making the window val = upper limit
    WWDG->CFR |=(0x3ff);

    /*t[5:0]*/
    //to disable window mode make the window value to be equal to the upper limit
    // WWDG->CFR &=~(0x7f);
    // WWDG->CFR |= (0x7f);
    // //enable early interupt
    // WWDG->CFR |= (1<<9);
    // //activate watchdog
    // WWDG->CR |= (1<<7);



}


void WDGDrv_IsrNotification(void){
    uint32 current_time = HAL_GetTick();

    if(WDGM_PovideSuppervisionStatus()==NOK && (current_time - last_execution_time) < 100 /*&& the WDGM_MainFunction_is_not_STUCK*/){
       
        // WWDG->CR &=~(0x3f);
        // refresh the watchdog

        // WWDG->CR |= ((30*1000 * 50) / (4096 * 2) - 1 );
        WWDG->CR |= 0x7F;
    }else{
        return;
    }
}