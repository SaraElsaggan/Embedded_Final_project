#ifndef WDDRV_H
#define WDDRV_H


#define WDTCSR (*(unsigned long *)( 0x60))
#define SREG (*(unsigned long *)( 0x3F))
#define PORTB *((volatile uint8_t*) 0x38) 
#define DDRB *((volatile uint8_t*) 0x37) 
#define PINB *((volatile uint8_t*) 0x36) 

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