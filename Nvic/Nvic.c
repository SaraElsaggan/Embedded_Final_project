/**
 * Nvic.c
 *
 *
 *  Author    : Hager Samir / Youssef Ahmed
 */

#include "Nvic.h"

#include "Bit_Operations.h"
#define NUM_OF_BITS_PER_REGISTER 32
#define NVIC_BASE (0xE000E100)

#define NVIC_ISER_OFFSET(index) (*(uint32 *)(NVIC_BASE + (0x04 * index)))
#define NVIC_ICER_OFFSET(index) (*(uint32 *)(NVIC_BASE + 0x180 + (0x04 * index)))

volatile uint32 *NVIC_ISER[3] = {&NVIC_ISER_OFFSET(0), &NVIC_ISER_OFFSET(1), &NVIC_ISER_OFFSET(2)};
volatile uint32 *NVIC_ICER[3] = {&NVIC_ICER_OFFSET(0), &NVIC_ICER_OFFSET(1), &NVIC_ICER_OFFSET(2)};

void Nvic_EnableInterrupt(uint8 IRQn)
{
  if (IRQn < 96)
  {
    uint8 index = IRQn / NUM_OF_BITS_PER_REGISTER;
    uint8 bit = IRQn % NUM_OF_BITS_PER_REGISTER;
    SET_BIT(*NVIC_ISER[index], bit);
  }
}

void Nvic_DisableInterrupt(uint8 IRQn)
{
  if (IRQn < 96)
  {
    uint8 index = IRQn / NUM_OF_BITS_PER_REGISTER;
    uint8 bit = IRQn % NUM_OF_BITS_PER_REGISTER;
    SET_BIT(*NVIC_ICER[index], bit);
  }
}


