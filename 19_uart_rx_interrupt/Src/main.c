#include <stdio.h>
#include "stm32f7xx.h"
#include "uart.h"
#include "led.h"


char ch;

static void uart_rx_callback(void);

int main(void)
{
  user_leds_init();
  uart3_rx_interrupt_init();


	while(1)
	{

    switch(ch){
      case '0':
        all_leds_off();
        break;
      case 'a':
        all_leds_on();
        break;
      case 'b':
        led_on(BLUE_LED);
        break;
      case 'g':
        led_on(GREEN_LED);
        break;
      case 'r':
        led_on(RED_LED);
        break;
      default:
        break;
    }

	}
}

static void uart_rx_callback(void){
  ch = (READ_BIT(USART3->RDR, USART_RDR_RDR)& 0xFFU);
}


void USART3_IRQHandler(void){
  // Check if rxne interrupt occured
  if((USART3->ISR & ISR_RXNE) == ISR_RXNE){
    // Do something
    uart_rx_callback();
  }

}
