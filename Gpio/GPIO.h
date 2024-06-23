#ifndef GPIO_H
#define GPIO_H

// for initializing the GPIO
#define LED_PORT_ID 0 // port B
#define LED_PIN_ID  4
#define PORTB (*(volatile uint8_t *)0x25)


void GPIO_Init(void);
void GPIO_Write(unsigned char PinId, unsigned char PinData);
#endif