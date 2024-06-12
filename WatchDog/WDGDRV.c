// #include "stm32l0xx.h" 
#include "WDGDRV.h"
#include "WDGM.h"
#include "Rcc.h"
#include <stdint.h>
#include "Gpio.h"
#include "stm32f4xx_hal.h"
// #include "stm32f4xx_hal.h"

#include "stm32f401xe.h"
#include "Nvic.h"
#include "Std_Types.h"



extern last_execution_time;



void WDGDrv_Init(void)
{

    WDG->CR |= (1<<7); // set bit 7 to enable Watchdog
    WDG->CR |= (1<<6); // set bit 6 to avoid generating an immediate reset.

    // //set max timeout to be 50
    // WDG->CR &= ~(0x3F);  // clear the t[5:0] bits 0011 1111
    // uint32 APB1_freq = HAL_RCC_GetPCLK1Freq(); 
    // WDG->CR |= (((APB1_freq*1000 * 50) / (4096 * 8) - 1 ) & 0x3F );  
    // WDG->CR |= (((30 *1000 * 50) / (4096 * 8) - 1 )  );   //tWWDG = tPCLK1 × 4096 × 2WDGTB[1:0] × (T[5:0] + 1) 
                                                          // 30 is from  Table 64 in data sheet till we find the APB1_freq
    WDG->CR |= 0x3f;  // this is just to debug why the reset keep happening
    Nvic_EnableInterrupt(0);


    // // WDG->CR |=(0xff);


    // //enable the early interupt , make the WDGTB to 3 (look at table 64) , Disable window maode by making the window val = upper limit

    // WDG->CFR |=(0x3ff);
    
    WDG->CFR |= 0x7F; // 0x7F in binary is 0111 1111, which sets bits 0 to 6

    // Set bits 7 and 8
    WDG->CFR |= (1 << 7) | (1 << 8);
    WDG->CFR |= (1 << 9);

    // WDG->SR &= ~(1<<0);

    // WDG->CR |= (1<<7); // set bit 7 to activate the WDG  should be last step



// WDG->CR |= (1 << 7); // set WDGA bit
//     WDG->CR |= (1 << 6); // set T[6]

//     // Set the counter reload value to 0x7F
//     WDG->CR &= ~(0x7F);  // clear the T[6:0] bits
//     WDG->CR |= 0x7F;     // set T[6:0] bits to maximum

//     // Set the window value to maximum and enable the early interrupt
//     WDG->CFR &= ~(0x7F); // clear the W[6:0] bits
//     WDG->CFR |= 0x7F;    // set W[6:0] bits to maximum
//     WDG->CFR |= (1 << 9); // set EWI bit to enable early wakeup interrupt

//     // Set the prescaler (WDGTB) to 8 (0b11)
//     WDG->CFR &= ~(0x3 << 7); // clear WDGTB[1:0] bits
//     WDG->CFR |= (0x3 << 7);  // set WDGTB[1:0] to 0b11 (prescaler of 8)

//     Nvic_EnableInterrupt(0);






    // DBGMCU->APB1FZ |= DBGMCU_APB1_FZ_DBG_WWDG_STOP; // Make Watchdog stop when debugger halt!
    // RCC->APB1ENR |= RCC_APB1ENR_WWDGEN; // Enable the clock for the thing, before giving it commands
 
    // WWDG->SR &= ~ WWDG_SR_EWIF;
    // NVIC_SetPriority(WWDG_IRQn, 0);
    // NVIC_ClearPendingIRQ(WWDG_IRQn);
    // NVIC_EnableIRQ(WWDG_IRQn);
    // // Window is configured same as T, to effectively disable the lower bound
    // WWDG->CFR = WWDG_CFR_EWI | (63u << WWDG_CFR_W_Pos) | (3u << WWDG_CFR_WDGTB_Pos);
    // WWDG->CR  = WWDG_CR_WDGA | (63u << WWDG_CR_T_Pos)  | WWDG_CR_T6 ;











}

// void refresh(void){
//     WDG->CR |= 0x7F;  
    
// }



// void watchdog_refresh()
// {
//     WDG->CR = (0x40UL << 0U) | (63u << 0U);
// }


void WWDG_IRQHandler(void){
    //uint32 current_time = HAL_GetTick();
    // WDG->SR &= ~(1<<0);

    // if(1){
    // // if(WDGM_PovideSuppervisionStatus()==OK && (current_time - last_execution_time) < 100 /*&& the WDGM_MainFunction_is_not_STUCK*/){

       
    //     // refresh the watchdog
    //     // WDG->CR |= (((30*1000 * 50) / (4096 * 8) - 1) );
    //     // GPIO_Write(LED_PIN_ID_, 1);

    //     GPIOB_MODER &= ~(0x03 << 6 * 2);   // clear bin 6
    //     GPIOB_MODER |= 1 << (6 * 2); // set this pin to be in output mode

    //     GPIOB_OTYPER &= ~(1 << 6); //output type to be push pull

    //     GPIOB_ODR |= (1 << 6);
    //     // WDG->CR |= 0x7F;

    if ( 1) // Check if the early wakeup interrupt flag is set
    {
        WDG->CR |= 0x3f;  // this is just to debug why the reset keep happening


        // WDG->SR &= ~(1 << 0); // Clear the early wakeup interrupt flag

        // Your ISR code here (e.g., refresh the watchdog, handle the event)
        GPIOB_MODER &= ~(0x03 << 6 * 2); // clear bin 6
        GPIOB_MODER |= 1 << (6 * 2);     // set this pin to be in output mode
        GPIOB_OTYPER &= ~(1 << 6);       // output type to be push-pull
        GPIOB_ODR |= (1 << 6);           // set pin high
    
    }else{
        return;
    }
}
