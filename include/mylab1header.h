/*
 * mylab1header.h
 *
 *  Created on: Sep 14, 2023
 *      Author: adamlake
 */

#ifndef MYLAB1HEADER_H_
#define MYLAB1HEADER_H_
#define BASE_PORTD   0x4004C000
#define BASE_PORTE   0x4004D000
#define BASE_GPIO    0x400FF000
#define GPIOD_OFFSET 0xC0
#define GPIOE_OFFSET 0x100
typedef struct {
  volatile uint32_t PDOR;
  volatile uint32_t PSOR;
  volatile uint32_t PCOR;
  volatile uint32_t PTOR;
  volatile uint32_t PDIR;
  volatile uint32_t PDDR;
  volatile uint32_t PIOR;
} GPIO_mem;



#endif /* MYLAB1HEADER_H_ */
