#include <stdio.h>
#include "stm32f7xx.h"
#include "uart.h"
#include "led.h"
#include "adc.h"
#include "systick.h"
#include "tim.h"


int sensor_value;

int main(void){
  uart3_tx_init();
  tim1_1hz_init();

  while(1){
    // Wait for UIF
    while(!(TIM1->SR & SR_UIF)){}

    // Clear UIF
    TIM1->SR &=~ SR_UIF;

    printf("A second just passed \n\r");
  }
}

