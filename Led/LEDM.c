
#include "LEDM.h"
#include "Std_Types.h"
#include "GPIO.h"

unsigned char PinId; // put port used for led here
unsigned char PinData; 

void LEDM_Init(void)
{
    GPIO_Init();
    GPIO_Write(PinId,PinData);
}

void LEDM_Manage(void)
{
}

