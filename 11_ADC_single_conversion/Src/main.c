#include <stdio.h>
#include "stm32f7xx.h"
#include "uart.h"
#include "led.h"
#include "adc.h"


int sensor_value;

int main(void){
  uart3_tx_init();
  pa4_adc1_init();

  while(1){
    start_conversion();
    sensor_value = adc_get_data();
    printf("Sensor value: %d \n\r", sensor_value);
  }
}

