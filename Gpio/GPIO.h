#ifndef GPIO_H
#define GPIO_H

// for initializing the GPIO
#define LED_PORT_ID 1
#define LED_PIN_ID  3


void GPIO_Init(void);
void GPIO_Write(unsigned char PinId, unsigned char PinData);
#endif
