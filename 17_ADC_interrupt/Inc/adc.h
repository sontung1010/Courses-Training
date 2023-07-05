/*
 * adc.h
 *
 *  Created on: Jul 2, 2023
 *      Author: st
 */

#ifndef ADC_H_
#define ADC_H_

#include "stm32f7xx.h"
#include <stdint.h>


void pa4_adc1_init(void);
uint32_t adc_get_data(void);
void pa4_adc1_interrupt_init(void);

#define SR_EOC    (1U<<1)

#endif /* ADC_H_ */
