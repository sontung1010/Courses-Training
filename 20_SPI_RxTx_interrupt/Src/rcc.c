/*
 * rcc.c
 *
 *  Created on: Jul 1, 2023
 *      Author: st
 */
#include "rcc.h"

void set_ahb1_periph_clock(uint32_t periphs)
{
	SET_BIT(RCC->AHB1ENR, periphs);
}

void set_ahb2_periph_clock(uint32_t periphs)
{
	SET_BIT(RCC->AHB2ENR, periphs);
}

void set_apb1_periph_clock(uint32_t periphs)
{
	SET_BIT(RCC->APB1ENR, periphs);
}

void set_apb2_periph_clock(uint32_t periphs)
{
	SET_BIT(RCC->APB1ENR, periphs);
}
