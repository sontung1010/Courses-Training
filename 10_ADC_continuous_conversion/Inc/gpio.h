/*
 * gpio.h
 *
 *  Created on: Jul 1, 2023
 *      Author: st
 */

#ifndef GPIO_H_
#define GPIO_H_

#include "stm32f7xx.h"
#include <stdint.h>

void set_pin_mode(GPIO_TypeDef *GPIOx, uint32_t Pin, uint32_t Mode);

#endif /* GPIO_H_ */
