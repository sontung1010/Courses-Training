#include <stdio.h>
#include "stm32f7xx.h"
#include "uart.h"
#include "led.h"
#include "adc.h"
#include "systick.h"


int sensor_value;

int main(void){
  uart3_tx_init();

  while(1){
    printf("A second just passed \n\r");
    systickDelayMs(1000);
  }
}

