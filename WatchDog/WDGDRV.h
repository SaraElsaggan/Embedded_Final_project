#ifndef WDDRV_H
#define WDDRV_H
#include "Std_Types.h"

// #define WDG ((Wwdg_Type*) 0x40002C00)

// typedef struct {
//     uint32 CR;    // Control Register
//     uint32 CFR;   // Configuration Register
//     uint32 SR;    // Status Register
// } Wwdg_Type;

#define WWDG_BASE_ADDRESS (0x40002C00U)
#define WWDG_CR   (*(unsigned long *)(WWDG_BASE_ADDRESS + 0x00)) // mode register to specify the mode of the pin
#define WWDG_CFR  (*(unsigned long *)(WWDG_BASE_ADDRESS + 0x04)) // output type to choose push-pull or open drain
#define WWDG_SR   (*(unsigned long *)(WWDG_BASE_ADDRESS + 0x08)) //to read the content of the pin

#define GPIOB_BASE_ADDR 0x40020400								   // this is the base addres of the gpio

#define GPIOB_MODER   (*(unsigned long *)(GPIOB_BASE_ADDR + 0x00)) // mode regestor to spscfiy the mode of the pin
#define GPIOB_OTYPER  (*(unsigned long *)(GPIOB_BASE_ADDR + 0x04)) //output type to chose push_pull or open drain
#define GPIOB_ODR     (*(unsigned long *)(GPIOB_BASE_ADDR + 0x14)) //to read the content of the pin
#define RCC_AHB1ENR   (*(unsigned long *)(0x40023800 + 0x30))



void watchdog_refresh();
// void refresh(void);
void WDGDrv_Init(void);
void WWDG_IRQHandler(void);
#endif
