#include <stdio.h>
#include "stm32f7xx.h"
#include "uart.h"
#include "led.h"

static void uart_tx_callback(void);

int main(void)
{
  user_leds_init();
  uart3_tx_interrupt_init();

  while(1){

  }
}

static void uart_tx_callback(void){
  // Write value into transmit data register
  USART3->TDR = 'A';
}

void USART3_IRQHandler(void){
  // Check if TXE interrupt occurred
  if((USART3->ISR & ISR_TXE) == ISR_TXE){
    // Do something
    uart_tx_callback();
  }
}
