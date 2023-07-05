/*
 * tim.c
 *
 *  Created on: Jul 3, 2023
 *      Author: st
 */

#include "stm32f7xx.h"


#define TIM1EN      (1U<<0)
#define CR1_EN      (1U<<0)


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
