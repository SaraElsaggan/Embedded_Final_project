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
#include "stm32f4xx.h" // Include the appropriate header file for your STM32 series




extern last_execution_time;



void WDGDrv_Init(void)
{
        WDG->CR |= (1 << 7); // set bit 7 to enable Watchdog
        WDG->CR |= (1 << 6); //set bit 6 to avoid generating an immediate reset.

        WDG->CR &= ~(0x3F);  // clear the t[5:0] bits 0011 1111
        WDG->CR |= (((16 *1000 * 50) / (4096 * 8) - 1 ) & 0x3F  ) ;//   


        WDG->CFR |= 0x7F; // set bits 0 to 6 to maxmizw the window value to disable window mode
        WDG->CFR |= (1 << 7) | (1 << 8);//  WDGTB = 3
        WDG->CFR &= ~(1 << 9);  // enable EWI

        Nvic_EnableInterrupt(0);
}
/*




//     WWDG->CFR = (WWDG_CFR_WDGTB_0 | // Set the prescaler to 8 (assuming 42 MHz APB1 clock)
//                  WWDG_CFR_EWI);     // Enable early wakeup interrupt

// //     // Set the window value to the maximum (0x7F)
//         WWDG->CFR |= 0x7F;

// //     // Set the counter value to the maximum (0x7F)
//     WWDG->CR = WWDG_CR_T;

// //     // Enable the WWDG
//     WWDG->CR |= WWDG_CR_WDGA;
//         NVIC_EnableIRQ(WWDG_IRQn);


      // Set the Maximum timeout value to 50ms
    // IWDG->KR = 0x5555; // Enable register access
    // IWDG->PR = 0x00;   // Set prescaler to 4
    // IWDG->RLR = 1;    // Set reload value for 50ms timeout

    // // Disable the window mode (assuming window mode disable is default)

    // // Enable the early interrupt feature (assuming using WWDG)
    // WWDG->CFR |= 0x3ff; // Enable early wakeup interrupt

    // // Activate the watchdog
    // IWDG->KR = 0xAAAA; // Reload the watchdog timer
    // IWDG->KR = 0xCCCC; // Start the watchdog timer

//     __HAL_RCC_WWDG_CLK_ENABLE();
//     WDG->CR |= (1<<7); // set bit 7 to enable Watchdog
//     WDG->CR |= (1<<6); // set bit 6 to avoid generating an immediate reset.

//     // //set max timeout to be 50
//     // uint32 APB1_freq = HAL_RCC_GetPCLK1Freq(); 
//     // WDG->CR |= (((30 *1000 * 50) / (4096 * 8) - 1 )  );   //tWWDG = tPCLK1 × 4096 × 2WDGTB[1:0] × (T[5:0] + 1) 
//                                                           // 30 is from  Table 64 in data sheet till we find the APB1_freq
//     uint32 PCLK1 = HAL_RCC_GetPCLK1Freq();
//     WDG->CR |= 0x3f;  // this is just to debug why the reset keep happening
//     // WDG->CR &= ~(0x3F);  // clear the t[5:0] bits 0011 1111
//     // WDG->CR |= (((PCLK1*1000 * 50) / (4096 * 8) - 1 ) & 0x3F );  


//     // // WDG->CR |=(0xff);


//     // //enable the early interupt , make the WDGTB to 3 (look at table 64) , Disable window maode by making the window val = upper limit

//     // WDG->CFR |=(0x3ff);
    
//     WDG->CFR |= 0x7F; // 0x7F in binary is 0111 1111, which sets bits 0 to 6

//     // Set bits 7 and 8
//     WDG->CFR |= (1 << 7) | (1 << 8);
//     WDG->CFR |= (1 << 9);

//     // WDG->SR &= ~(1<<0);

//     // WDG->CR |= (1<<7); // set bit 7 to activate the WDG  should be last step



// // WDG->CR |= (1 << 7); // set WDGA bit
// //     WDG->CR |= (1 << 6); // set T[6]

// //     // Set the counter reload value to 0x7F
// //     WDG->CR &= ~(0x7F);  // clear the T[6:0] bits
// //     WDG->CR |= 0x7F;     // set T[6:0] bits to maximum

// //     // Set the window value to maximum and enable the early interrupt
// //     WDG->CFR &= ~(0x7F); // clear the W[6:0] bits
// //     WDG->CFR |= 0x7F;    // set W[6:0] bits to maximum
// //     WDG->CFR |= (1 << 9); // set EWI bit to enable early wakeup interrupt

// //     // Set the prescaler (WDGTB) to 8 (0b11)
// //     WDG->CFR &= ~(0x3 << 7); // clear WDGTB[1:0] bits
// //     WDG->CFR |= (0x3 << 7);  // set WDGTB[1:0] to 0b11 (prescaler of 8)

// //     Nvic_EnableInterrupt(0);






    // DBGMCU->APB1FZ |= DBGMCU_APB1_FZ_DBG_WWDG_STOP; // Make Watchdog stop when debugger halt!
    // RCC->APB1ENR |= RCC_APB1ENR_WWDGEN; // Enable the clock for the thing, before giving it commands
 
    // WWDG->SR &= ~ WWDG_SR_EWIF;
    // NVIC_SetPriority(WWDG_IRQn, 0);
    // NVIC_ClearPendingIRQ(WWDG_IRQn);
    // NVIC_EnableIRQ(WWDG_IRQn);
    // // Window is configured same as T, to effectively disable the lower bound
    // WWDG->CFR = WWDG_CFR_EWI | (63u << WWDG_CFR_W_Pos) | (3u << WWDG_CFR_WDGTB_Pos);
    // WWDG->CR  = WWDG_CR_WDGA | (63u << WWDG_CR_T_Pos)  | WWDG_CR_T6 ;











}*/



void WWDG_IRQHandler(void){
    
        
        GPIOB_MODER &= ~(0x03 << 6 * 2); // clear bin 6
        GPIOB_MODER |= 1 << (6 * 2);     // set this pin to be in output mode
        GPIOB_OTYPER &= ~(1 << 6);       // output type to be push-pull
        GPIOB_ODR |= (1 << 6);           // set pin high

        WDG->CR |= (((16 *1000 * 50) / (4096 * 8) - 1 )  & 0x3f) ;// refill the ocunter
        WDG->SR &= ~(1<<0);





    //uint32 current_time = HAL_GetTick();

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

    // if ( 1) // Check if the early wakeup interrupt flag is set
    // {
        // WDG->CR |= 0x3f;  // this is just to debug why the reset keep happening


        // WDG->SR &= ~(1 << 0); // Clear the early wakeup interrupt flag

        // Your ISR code here (e.g., refresh the watchdog, handle the event)
        // WWDG->SR = 0x00;
    
    // }else{
    //     return;
    // }
}
// void refresh(void){
//     WDG->CR |= 0x7F;  
    
// }



void watchdog_refresh()
{
    uint32 PCLK1 = HAL_RCC_GetPCLK1Freq();
    WDG->CR &= ~(0x3F);  // clear the t[5:0] bits 0011 1111
    // WDG->CR |= (((PCLK1*1000 * 50) / (4096 * 8) - 1 ) & 0x3F );  
    WDG->CR |= 0x7f;  // this is just to debug why the reset keep happening
    }


// void WDGDrv_Init(void) {
//     // Enable the clock for WWDG (Window Watchdog)
//     RCC->APB1ENR |= RCC_APB1ENR_WWDGEN;

//     // Configure WWDG: Set the prescaler to 8 and enable early wakeup interrupt
//     WWDG->CFR = (WWDG_CFR_WDGTB_1 | WWDG_CFR_EWI); // WDGTB set to 0x1 for prescaler of 8

//     // Set the window value to the maximum (0x7F)
//     WWDG->CFR |= 0x7F;

//     // Set the counter value to the maximum (0x7F)
//     WWDG->CR = 0x7F;

//     // Enable the WWDG
//     WWDG->CR |= WWDG_CR_WDGA;

//     // Enable WWDG interrupt in NVIC
//     NVIC_EnableIRQ(WWDG_IRQn);
// }

// void WWDG_IRQHandler(void) {
//     // Clear the Early Wakeup Interrupt flag
//     WWDG->SR = 0x00;

//     // Refresh the WWDG counter
//     WWDG->CR = (WWDG_CR_WDGA | 0x7F);

//     // Configure GPIOB pin 6 for output
//     RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN; // Enable GPIOB clock

//     GPIOB->MODER &= ~(0x03 << (6 * 2)); // Clear pin 6 mode
//     GPIOB->MODER |= (0x01 << (6 * 2));  // Set pin 6 as output mode
//     GPIOB->OTYPER &= ~(0x01 << 6);      // Set output type to push-pull
//     GPIOB->ODR |= (0x01 << 6);          // Set pin 6 high
// }
