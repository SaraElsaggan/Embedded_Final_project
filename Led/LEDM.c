
#include "LEDM.h"
#include "Std_Types.h"
#include "GPIO.h"
#include "WDGM.h" 
#include <stdlib.h>
#include <avr/wdt.h>

uint32 time_counter;

static uint8 led_state;


void LEDM_Init(void)
{
    GPIO_Init();
    led_state = 0;
	GPIO_Write(LED_PIN_ID, led_state);
    time_counter = 0;
}

void LEDM_Manage(void)
{   
    PORTB ^= (1 << 2); // to indicate the perodicity of the function
	// time_counter += 10;
	time_counter += 5;

	if (time_counter >= 500)
    {
		led_state = ~led_state;
		GPIO_Write(LED_PIN_ID, led_state);
		time_counter = 0;
    }
  WDGM_AlivenessIndication(); // to count the number of function calls
}
