#ifndef WDDRV_H
#define WDDRV_H

typedef struct {
    volatile uint32 CR;    // Control Register
    volatile uint32 CFR;   // Configuration Register
    volatile uint32 SR;    // Status Register
} WWDG_TypeDef;

#define WWDG ((WWDG_TypeDef *) 0x40002C00)

void WDGDrv_Init(void);
void WDGDrv_IsrNotification(void);
#endif