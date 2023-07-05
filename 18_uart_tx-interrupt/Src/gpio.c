/*
 * gpio.c
 *
 *  Created on: Jul 1, 2023
 *      Author: st
 */
#include "gpio.h"

void set_pin_mode(GPIO_TypeDef *GPIOx, uint32_t Pin, uint32_t Mode)
{
	/* 0x3 = 0b11
	 *
	 * (1U<<8) = 0000 0000 0000 0000 0000 0001 0000 0000
	 * rbit = 0000 0000 1000 0000 0000 0000 0000 0000
	 * clz = 8
	 * POSITION_VAL(1U<<8) *2 = 16
	 * 0x3 << 16 = (1U<<16) | (1U<<17)
	 * CLEAR((1U<<16) | (1U<<17)) ==> bit16 = 0, bit17 = 0
	 *
	 * Mode = 0b10 = 0x2
	 * 2 << 16 ==> bit16 = 0, bit17 = 1
	 * */

	MODIFY_REG(GPIOx->MODER, (0x3<<(POSITION_VAL(Pin)*2U)), (Mode<<(POSITION_VAL(Pin)*2U)));
}

