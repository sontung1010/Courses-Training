#include <stdio.h>
#include "stm32f7xx.h"
#include "uart.h"
#include "led.h"
#include "adc.h"
#include "systick.h"


static void systick_callback(void);


int main(void){
  uart3_tx_init();
  systick_1hz_interrupt();

  while(1){

  }
}


static void systick_callback(void){
  printf("A second just passed \n\r");
}

void SysTick_Handler(void){
  // Do something
  systick_callback();
}
