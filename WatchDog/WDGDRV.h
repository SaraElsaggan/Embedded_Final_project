#ifndef WDDRV_H
#define WDDRV_H
#include "Std_Types.h"

typedef struct {
    uint32 CR;    // Control Register
    uint32 CFR;   // Configuration Register
    uint32 SR;    // Status Register
} Wwdg_Type;

#define WWDG ((Wwdg_Type*) 0x40002C00)

void WDGDrv_Init(void);
void WDGDrv_IsrNotification(void);
#endif
