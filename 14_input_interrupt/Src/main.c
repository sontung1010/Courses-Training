#include <stdio.h>
#include "stm32f7xx.h"
#include "uart.h"
#include "led.h"
#include "adc.h"
#include "systick.h"
#include "tim.h"
#include "exti.h"

int sensor_value;
static void user_btn_callback(void);


int main(void){
  uart3_tx_init();
  pc13_exti_init();
  user_leds_init();

  while(1){


  }
}


static void user_btn_callback(void){
  all_leds_toggle();
  printf("BTN Pressed... \n\r");
}

void EXTI15_10_IRQHandler(void){
  if((EXTI->PR & PIN13) != 0){
    // Clear PR flag
    EXTI->PR |= PIN13;

    // Do something
    user_btn_callback();
  }
}
