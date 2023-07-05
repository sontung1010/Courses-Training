/*
 * exti.c
 *
 *  Created on: Jul 3, 2023
 *      Author: st
 */

#include "stm32f7xx.h"

#define GPIOCEN     (1U<<2)
#define SYSCFGEN    (1U<<14)

void pc13_exti_init(void){
  // Enable clock access to PORT C
  RCC->AHB1ENR |= GPIOCEN;

  // Set PC13 to input
  GPIOC->MODER &=~ (1U<<26);
  GPIOC->MODER &=~ (1U<<27);

  // Enable clock access to SYSCFG module
  RCC->APB2ENR |= SYSCFGEN;

  // Clear port selection for EXTI13
  SYSCFG->EXTICR[3] &=~ (1U<<4);
  SYSCFG->EXTICR[3] &=~ (1U<<5);
  SYSCFG->EXTICR[3] &=~ (1U<<6);
  SYSCFG->EXTICR[3] &=~ (1U<<7);

  // Select PORT C for EXTI13
  SYSCFG->EXTICR[3] |= (1U<<5);

  // Unmask EXTI13
  EXTI->IMR |= (1U<<13);

  // Select falling edge trigger
  EXTI->FTSR |= (1U<<13);

  // Enable EXTI13 in NVIC
  NVIC_EnableIRQ(EXTI15_10_IRQn);
}
