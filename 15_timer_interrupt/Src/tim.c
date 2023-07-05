/*
 * tim.c
 *
 *  Created on: Jul 3, 2023
 *      Author: st
 */

#include "stm32f7xx.h"


#define TIM1EN      (1U<<0)
#define CR1_EN      (1U<<0)
#define DIER_UIF    (1U<<0)
#define EGR_UG      (1U<<0)


void tim1_1hz_init(void){
  // Enable clock access to TIM1
  RCC->APB2ENR |= TIM1EN;

  // Set the prescaler
  TIM1->PSC = 1600 -1;    // 16000000/1600 = 10000

  // Set auto-reload value
  TIM1->ARR = 10000 -1;   // 10000/100000 = 1

  // Enable timer
  TIM1->CR1 |= CR1_EN;
}


void tim1_1hz_interrupt_init(void){
  // Enable clock access to TIM1
  RCC->APB2ENR |= TIM1EN;

  // Set the prescaler
  TIM1->PSC = 1600 -1;    // 16000000/1600 = 10000

  // Set auto-reload value
  TIM1->ARR = 10000 -1;   // 10000/100000 = 1

  // Enable TIM1 update interrupt
  TIM1->DIER = DIER_UIF;

  // Enable TIM1 update interrupt in NVIC
  NVIC_EnableIRQ(TIM1_UP_TIM10_IRQn);

// Enable timer
  TIM1->CR1 |= CR1_EN;

  // Force update generation
  TIM1->EGR |= EGR_UG;
}
