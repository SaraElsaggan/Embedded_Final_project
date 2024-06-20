#ifndef GPIO_PRIVATE_H
#define GPIO_PRIVATE_H
#include "Utils.h"

#define GPIOB_BASE_ADDR    0x23
#define GPIOC_BASE_ADDR    0x26
#define GPIOD_BASE_ADDR    0x29

typedef struct {
	uint8 PIN;
	uint8 DDR;
	uint8 PORT;

} GpioType;

#endif
