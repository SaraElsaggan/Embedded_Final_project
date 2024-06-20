//#include <avr/io.h>
// #include <avr/interrupt.h>
// #include <avr/wdt.h>
#include "WDGDRV.h"

static void delay(uint32 time){
    volatile uint32 i;
    time *= 1000;
    for ( i = 0 ; i<time;i++){}
}

<<<<<<< HEAD
int main(void){

    Rcc_Init();
    HAL_Init();
	Rcc_Enable(RCC_GPIOB);
	Rcc_Enable(RCC_WWDG);

//    initialization.
    LEDM_Init();
    WDGDrv_Init();
    WDGM_Init();


    while (1) {
        // Call LEDM_Manage every 10ms
//    	delay(10);
    	HAL_Delay(10);
        LEDM_Manage();

        // Call WDGM_MainFunction every 20ms
//        delay(20);
    	HAL_Delay(20);
        WDGM_MainFunction();
=======
int main(void) {
    // Set PB0 as output for the LED
    DDRB |= (1 << 0);
    PORTB &= ~(1 << 0);  // Ensure the LED is initially off
    WDGDrv_Init();
    // LEDM_Init();
    // WDGM_Init();
    // Main loop
    while (1) {
        // delay(10);
        // LEDM_Manage();
>>>>>>> d2c87f4818c04e781775bf922690406f29322ed3

        // // Call WDGM_MainFunction every 20ms
        // delay(20);
        // WDGM_MainFunction();
    }

    return 0;
}
