#include "GPIO.h"
#include "Gpio_Private.h"

GpioType* const GPIO_Addresses[3] = { (GpioType*)GPIOB_BASE_ADDR, (GpioType*)GPIOC_BASE_ADDR, (GpioType*)GPIOD_BASE_ADDR };

void GPIO_Init(void)
{
    GpioType* gpioReg = GPIO_Addresses[LED_PORT_ID];
	gpioReg->DDR |= (1 << LED_PIN_ID);

}

void GPIO_Write(unsigned char PinId, unsigned char PinData) {
    GpioType* gpioReg = GPIO_Addresses[LED_PORT_ID];
    if (PinData) {
        gpioReg->PORT |= (1 << PinId); // Set the pin
    } else {
        gpioReg->PORT &= ~(1 << PinId); // Clear the pin
    }
}
