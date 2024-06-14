
#include "LEDM.h"
#include "Std_Types.h"
#include "GPIO.h"
#include "stm32f4xx_hal.h"
#include "WDGM.h"
#include "WDGDrv.h"

static uint8 led_state;

static void delay(uint32 time){
    volatile uint32 i;
    time *= 1000;
    //  watchdog_refresh();
    for ( i = 0 ; i<time;i++){
    // WDG->CR |= 0xFF; //0111 1111
    //  watchdog_refresh();
    }
}


void LEDM_Init(void)
{
    GPIO_Init();
    led_state = 0;
}

void LEDM_Manage(void)
{

    //HAL_Delay(500);
	delay(50);
    led_state = ~led_state;
    GPIO_Write(LED_PIN_ID, led_state);
    WDGM_AlivenessIndication(); // to count the number of function calls
}
