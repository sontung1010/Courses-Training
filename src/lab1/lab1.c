/*
  EECS461
  Lab 1
  Read Chapter 11&12 in S32K144 User's Manual
  Updated: March 17th, 2014 by Scott Kenyon
           14 Jun 2014 by GPCz
           19 Jun 2014 by GPCz
           2017-03 RMC
           2018-03 Paul Domanico
           15 Nov 2018 jfr
           12 Jan 2021 jfr
           29 Aug 2021 jfr
           12 Aug 2022 jfr
           18 Aug 2023 jfr
 
*/

#include "eecs461.h"
#include <stdint.h>
#include "mylab1header.h"
/* Change section number to match the section (1-3) being tested */
#define SECTION 3

#if SECTION == 1



/******************************************************************************
 * Function:    section1
 * Description: read and write to the GPIO registers using your header file
 ******************************************************************************/
void section1(){
  /* code for section 1 */
  volatile uint32_t * const portD_PCR = (uint32_t *)(BASE_PORTD);
  volatile uint32_t * const portE_PCR = (uint32_t *)(BASE_PORTE);
  GPIO_mem * const gpioD = (GPIO_mem *)(BASE_GPIO + GPIOD_OFFSET);
  GPIO_mem * const gpioE = (GPIO_mem *)(BASE_GPIO + GPIOE_OFFSET);

  uint16_t sum, value1, value2;
  uint32_t regReadVal;
  int index, carry;

  /* Configure the LED pins */
  for (index = 0; index < 16; index++){
    /* Configure pin mux to gpio */
    portD_PCR[index] = 0b001 << 8;    // Set bit 8 (MUX field) = 1 for each Port D PCR
    /* Set the direction to output */
    gpioD->PDDR |= 0b1 << index;      // Set data direction bits for output
  }

  /* Configure the DIP pins */
  for (index = 6; index < 14; index++){
    /* Configure pin mux to gpio */
    portE_PCR[index] = 0b001 << 8;
    /* Set the direction to input */
    gpioE->PDDR &= ~(1 << index);
  }

  while (1){
    value1 = 0;
    value2 = 0;
    sum = 0;

    /* Read the GPIOE input register, extract the two 4-bit numbers set on dipswitches 1-4 and 5-8 */
    /* Calculate the sum and write to the GPIOD output register to display the results on LED1-5 */
    /*for (index = 6; index < 14; index++){
      gpioD->PDOR |= (gpioE->PDIR >> (index-6)) << index;

      //gpioE->PDIR |= 0b1 << index;
    }*/
    //gpioD->PDOR
    value1 = (gpioE->PDIR >> 6) & 0b0000001111;
    //gpioD->PDOR = value1;
    value2 = (gpioE->PDIR >> 10) & 0b0000001111;
    sum = 0b0000;

//    for (index = 0; index < 4; index++){
//      carry = 0;
//      if (((value1 & (0b1 << index)) == 0b1 << index) ^ ((value2 & (0b1 << index)) == 0b1 << index ^ carry == 1)){
//        if (carry == 1){
//          carry = 1;
//        }
//        else {
//        sum |= 0b1 << index;
//        }
//      }
//      else if ((value1 & (0b1 << index)) == 0b1 << index & (value2 & (0b1 << index)) == 0b1 << index){
//        if (carry ==1){
//          carry = 1;
//          sum |= 0b1 << index;
//        }
//        else {
//           carry = 1;
//        }
//      }
//    }
//    if (carry = 1){
//      sum |= 0b1 << 5;
//    }
//
    gpioD->PDOR = value1 + value2;




  }

}


#elif SECTION == 2
#include "S32K144.h"
#include "gpio.h"
/******************************************************************************
 * Function:    section2
 * Description: Use the provided S32K144.h header file
 ******************************************************************************/
void section2(){
  /* code for section 2 */
//  initEECS461();
  uint16_t sum, value1, value2;
  int index;

  for (index = 0; index < 16; index++) {
    initGPDI(4, index);
    initGPDO(3, index);
  }

  while (1){
      value1 = 0;
      value2 = 0;
      sum = 0;
      for (index = 6; index < 10; index++){
        value1 |= readGPIO(4, index) << (index - 6);
      }
      for (index = 10; index < 14; index++){
        value2 |= readGPIO(4, index) << (index - 10);
      }

      sum = value1 + value2;
      for (index = 0; index < 5; index++) {
        writeGPIO(3, index, (sum >> index) & 0b1);
      }

  }
}


#elif SECTION == 3
#include "LPUART.h"
#include "gpio.h"
/******************************************************************************
 * Function:    section3
 * Description: Communicate with the computer using the keyboard interface
 ******************************************************************************/
void section3(){
  /* code for section 3 */
  char byte_in, old_byte_in;
  uint16_t sum, value1, value2;
   int index;

   for (index = 0; index < 16; index++) {
     initGPDI(4, index);
     initGPDO(3, index);
   }

  /* LPUART functions for sending and receiving serial data */
  LPUART1_init();
  LPUART1_transmit_string("\n\rSerial Output Enable...........");
  while(1) {
    old_byte_in = byte_in;
    byte_in = LPUART1_receive_char(); // returns ASCII representation
    //value1 = 0;
    //value2 = 0;
    sum = 0;

    if (byte_in <= 0b111001 && byte_in >= 0b110000){
    value1 = byte_in & 0xF;
    value2 = old_byte_in & 0xF;

    sum = value1 + value2;
    for (index = 0; index < 5; index++) {
      writeGPIO(3, index, (sum >> index) & 0b1);
    }
  }
  }
}
#endif

int main(){
  /* Always call initEECS461() before doing anything else */
  initEECS461();
  #if(SECTION == 1)
  section1();
  #elif(SECTION == 2)
  section2();
  #elif(SECTION == 3)
  section3();
  #endif

  /* Should never reach this point */
  return 0;
}
