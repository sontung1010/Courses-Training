#include <stdio.h>
#include "stm32f7xx.h"
#include "uart.h"
#include "led.h"
#include "adc.h"

static void adc_conv_complt_callback(void);

int sensor_value;

int main(void){
  uart3_tx_init();
  pa4_adc1_interrupt_init();

  while(1){

  }
}

static void adc_conv_complt_callback(void){
  sensor_value = ADC1->DR;
  printf("Sensor value: %d \n\r", sensor_value);
}

void ADC_IRQHandler(void){
  // Check if end-of-conversion interrupt occured
  if((ADC1->SR & SR_EOC) == SR_EOC){
    // Clear the EOC flag
    ADC1->SR &=~ SR_EOC;

    // Do something
    adc_conv_complt_callback();
  }
}
