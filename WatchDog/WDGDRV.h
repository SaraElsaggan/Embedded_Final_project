#include "Std_Types.h"

#ifndef WDDRV_H
#define WDDRV_H


#define WDTCSR (*(volatile uint8 *)( 0x60))
#define MCUSR (*(volatile uint8 *)( 0x34))


#define TCCR1B (*(volatile uint8 *)( 0x81))
#define OCR1A (*(volatile uint8 *)( 0x88))
#define TIMSK1 (*(volatile uint8 *)( 0x6F))

#define ICNC1  7
#define ICES1  6
#define WGM13  4
#define WGM12  3
#define CS12  2
#define CS11  1
#define CS10  0

#define TCCR0A (*(volatile uint8 *)(0x24))
#define OCR0A (*(volatile uint8 *)(0x27))
#define TIMSK0 (*(volatile uint8 *)(0x6E))
#define TCCR0B (*(volatile uint8 *)(0x25))

#define OCIE0A 1


#define ICIE1  5
#define OCIE1B  2
#define OCIE1A  1
#define TOIE1  0

#define SREG (*(volatile uint8 *)( 0x5F))
#define DDRB  (*(volatile uint8_t *)0x24)
#define PORTB (*(volatile uint8_t *)0x25)
#define PINB  (*(volatile uint8_t *)0x23)


#define WDP0  0
#define WDP1  1
#define WDP2  2
#define WDE   3
#define WDCE  4
#define WDP3  5
#define WDIE  6
#define WDIF  7


#define I  7

void WDGDrv_Init(void);
void WDGDrv_IsrNotification(void);
#endif