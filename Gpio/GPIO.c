#include "GPIO.h"
#include "Gpio_Private.h"
#include "Rcc.h"

uint32 GPIO_Addresses[2] = { 0x40020000, 0x40020400}; // for port A and B only

void GPIO_Init(void)
{
    GpioType * gpioReg =  GPIO_Addresses[LED_PORT_ID];
	gpioReg->GPIO_MODER &= ~(0x3 << (2 * LED_PIN_ID));
	gpioReg->GPIO_MODER |= (0x01 << (2 * LED_PIN_ID));
	gpioReg->GPIO_OTYPER  &= ~(0x01 << LED_PIN_ID);
	gpioReg->GPIO_OTYPER |= (0x00 << LED_PIN_ID);
	// gpioReg->GPIO_PUPDR &= ~(0x3 << (2 * LED_PIN_ID));
}

void GPIO_Write(unsigned char PinId, unsigned char PinData)
{
	GpioType * gpioReg =  GPIO_Addresses[LED_PORT_ID];
	gpioReg->GPIO_ODR &= ~(0x01 << PinId);
	gpioReg->GPIO_ODR |= (PinData << PinId);
}
