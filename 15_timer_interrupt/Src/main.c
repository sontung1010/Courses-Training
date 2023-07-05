#include <stdio.h>
#include "stm32f7xx.h"
#include "uart.h"
#include "led.h"
#include "adc.h"
#include "systick.h"
#include "tim.h"
#include "exti.h"

static void tim1_update_callback(void);

int main(void){
  uart3_tx_init();
  user_leds_init();
  tim1_1hz_interrupt_init();

  while(1){


  }
}

static void tim1_update_callback(void){
  all_leds_toggle();
  printf("A second just passed \n\r");
}

void TIM1_UP_TIM10_IRQHandler(void){
  // Check whether update interrupt is pending
  if((TIM1->SR & SR_UIF) != 0){
    // Clear the update interrupt flag
    TIM1->SR &=~ SR_UIF;

    // Do something
    tim1_update_callback();
  }


}
