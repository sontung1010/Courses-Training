#ifndef UART_H_
#define UART_H_

#include "stm32f7xx.h"
#include <stdint.h>

void uart3_tx_init(void);

uint8_t uart_read(USART_TypeDef *USARTx);
void uart3_rxtx_init(void);

void uart3_rx_interrupt_init(void);

#define ISR_RXNE      (1U<<5)

#endif /* UART_H_ */
