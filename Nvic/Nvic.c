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

// #define NVIC_BASE (0xE000E100)

// #define NVIC_ISER0 (*(uint32 *)(0xE000E100 + (0x04 * 0)))
// #define NVIC_ISER1 (*(uint32 *)(0xE000E100 + (0x04 * 1)))
// #define NVIC_ISER2 (*(uint32 *)(0xE000E100 + (0x04 * 2)))

// #define NVIC_ICER0 (*(uint32 *)0xE000E180)
// #define NVIC_ICER1 (*(uint32 *)0xE000E184)
// #define NVIC_ICER2 (*(uint32 *)0xE000E188)

// void Nvic_EnableInterrupt(uint8 IRQn) {
//   // TODO: use arrays and pointers to remove this if else statement
//   if (IRQn>=0 && IRQn < 32) {
//     SET_BIT(NVIC_ISER0, IRQn);
//   } else if (IRQn >= 32 &&IRQn < 64) {
//      SET_BIT(NVIC_ISER1, IRQn - 32);
//   } else if (IRQn >= 64 && IRQn < 96) {
//     SET_BIT(NVIC_ISER2, IRQn - 64);
//   }
// }

// void Nvic_DisableInterrupt(uint8 IRQn) {
//   // TODO: use arrays and pointers to remove this if else statement
//   if (IRQn < 32) {
//     SET_BIT(NVIC_ICER0, IRQn);
//   } else if (IRQn < 64) {
//     SET_BIT(NVIC_ICER1, IRQn - 32);
//   } else if (IRQn < 96) {
//     SET_BIT(NVIC_ICER2, IRQn - 64);
//   }
// }


