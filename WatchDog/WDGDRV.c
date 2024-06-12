#include "WDGDRV.h"
#include "WDGM.h"
#include "Rcc.h"
#include <stdint.h>
#include "Gpio.h"
#include "stm32f4xx_hal.h"
#include "Nvic.h"
#include "Std_Types.h"



extern last_execution_time;



void WDGDrv_Init(void)
{

    WDG->CR |= (1<<7); // set bit 7 to activate the WDG
    WDG->CR |= (1<<6); // set bit 6 

    // //set max timeout to be 50
    WDG->CR &= ~(0x3F);  // clear the t[5:0] bits 0011 1111
    // // WDG->CR |= (((APB1_freq*1000 * 50) / (4096 * 8) - 1 ) & 0x3F );  
    // // WDG->CR |= (((30 *1000 * 50) / (4096 * 8) - 1 )  );  
    WDG->CR |= 0x7f;


    // // WDG->CR |=(0xff);


    // //enable the early interupt , make the WDGTB to 3 (look at table 64) , Disable window maode by making the window val = upper limit
    Nvic_EnableInterrupt(0);

    // WDG->CFR |=(0x3ff);

    // WDG->SR &= ~(1<<0);




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

}

// void refresh(void){
//     WDG->CR |= 0x7F;  
    
// }

void WDGDrv_IsrNotification(void){
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

    if (1) // Check if the early wakeup interrupt flag is set
    {
        WDG->SR &= ~(1 << 0); // Clear the early wakeup interrupt flag

        // Your ISR code here (e.g., refresh the watchdog, handle the event)
        GPIOB_MODER &= ~(0x03 << 6 * 2); // clear bin 6
        GPIOB_MODER |= 1 << (6 * 2);     // set this pin to be in output mode
        GPIOB_OTYPER &= ~(1 << 6);       // output type to be push-pull
        GPIOB_ODR |= (1 << 6);           // set pin high
    
    }else{
        return;
    }
}
