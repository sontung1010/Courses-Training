/*
   gpio.c
   University of Michigan
   EECS 461, Embedded Control Systems
   General-Purpose Input/Output module
   Read Chapter 11&12 in S32K144 User's Manual

   Revision History
     2014-02-08  Yitian Chen
     2014-07-04  GPCz
     2017-03-14  RMC
     2018-03-30  Paul Domanico
     2021-01-12 jfr
 */

#include "gpio.h"

const uint8_t LED[16] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
const uint8_t LED_BASE[16] = {3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3};
const uint8_t DIP[16] = {6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 0, 1, 2, 3, 17};
const uint8_t DIP_BASE[16] = {4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 3};

/* base: 0-4 corresponding to gpio/port groups A-E */
static GPIO_Type * gpio_base_ptrs[5] = GPIO_BASE_PTRS;
static PORT_Type * port_base_ptrs[5] = PORT_BASE_PTRS;


/******************************************************************************
 * Function:    initGPDI
 * Description: Initialize a general purpose input based on port base and pin
 ******************************************************************************/
void initGPDI(const uint8_t base, const uint8_t pin){
  /* Set the pin direction to input */
  gpio_base_ptrs[base]->PDDR |= 0b0 << pin;
      /* Set the direction to input */
  port_base_ptrs[base]->PCR[pin] = PORT_PCR_MUX(0b001);

  /* Set the pin configuration register */
                                              /* Pin Mux Alt1 for GPIO */
  /* All other bitfields to 0 */
  /* Internal pulldown or input filter are optional */
}


/******************************************************************************
 * Function:    initGPDO
 * Description: Initialize a general purpose output based on port base and pin
 ******************************************************************************/
void initGPDO(const uint8_t base, const uint8_t pin){
  /* Set the pin direction to output */
  gpio_base_ptrs[base]->PDDR |= 0b1 << pin;

  /* Pin Mux Alt1 for GPIO */
  port_base_ptrs[base]->PCR[pin] = PORT_PCR_MUX(0b001);
                                                 /* Pin Mux Alt1 for GPIO */
  /* All other bitfields to 0 */
}


/******************************************************************************
 * Function:    readGPIO
 * Description: Read the digital 1/0 from GPIO input register
 ******************************************************************************/
uint8_t readGPIO(const uint8_t base, const uint8_t pin){
  return (gpio_base_ptrs[base]->PDIR >> pin) & 0b1;
}


/******************************************************************************
 * Function:    writeGPIO
 * Description: Write a digital 1/0 to a GPIO output
 ******************************************************************************/
void writeGPIO(const uint8_t base, const uint8_t pin, const uint8_t val){
/*  make sure that 
 (1) your function can be called multiple times in succession to correctly set 
     multiple bits in the PDOR register
 (2) if a PDOR bit already has the desired setting, 
     then do not toggle the bit before returning it to this setting */
  if (val == 1){
  gpio_base_ptrs[base]->PDOR = gpio_base_ptrs[base]->PDOR | (0b1 << pin);
  }
  else {
    gpio_base_ptrs[base]->PDOR = gpio_base_ptrs[base]->PDOR & ~(0b1 << pin);
  }
  return;
}
