/*
 * rcc.h
 *
 *  Created on: Jul 1, 2023
 *      Author: st
 */

#ifndef RCC_H_
#define RCC_H_

#include "stm32f7xx.h"
#include <stdint.h>

void set_ahb1_periph_clock(uint32_t periphs);
void set_ahb2_periph_clock(uint32_t periphs);
void set_apb1_periph_clock(uint32_t periphs);
void set_apb2_periph_clock(uint32_t periphs);

#endif /* RCC_H_ */
