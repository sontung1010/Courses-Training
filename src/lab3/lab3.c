/*
 * lab3.c
 *
 *  Created on: Sep 28, 2023
 *      Author: adamlake
 */

#include "eecs461.h"
#include "S32K144.h"
#include "adc.h"
#include "gpio.h"
#include "LPUART.h"
#include "s32_core_cm4.h"
#include "interrupt_manager.h"

int main(){
  /*//Part 1
  initEECS461();
  uint32_t iAnalog;
  init_ADC0_single();
  initGPDO(3, 2);
  while(1){//
    writeGPIO(3, 2, 0b1); //850ns
    iAnalog = read_ADC0_single(0);
    writeGPIO(3, 2, 0b0);//11.85 microsec
    //12.65 microsec next turn on
    //Tread = 11 microsec
    //Tlab = 12.65-850ns

  }
  */
//Part 2
  initEECS461();
  uint32_t iAnalog;
  init_ADC0_single();
  initGPDO(3, 2);
  initGPDO(3, 3);

  while(1){//
    writeGPIO(3, 3, 0b1);
    iAnalog = read_ADC0_single(0);
    writeGPIO(3, 3, 0b0); //fs = 78.56kHz
    if (iAnalog > 2500){
    writeGPIO(3, 2, 0b1);
    }
    else {
      writeGPIO(3, 2, 0b0);
    }//for f = 300Hz - f = 300hz, for f = 85kHz - f = 6.53kHz
  }
  return 0;
}//fs = 10kHz
