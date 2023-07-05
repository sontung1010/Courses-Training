#include <stdio.h>
#include "stm32f7xx.h"


#define GPIODEN 				(1U<<3)
#define UART3_TX 				(1U<<8)
#define GPIO_ALTERNATE_MODE 	0x2 	// 0b10

#define USART3EN 				(1U<<18)
#define UART_DATAWIDTH_8B		0x00000000U 		// 8 bits word length : Start bit, 8 data bits, n stop bits
#define UART_PARITY_NONE 		0x00000000U 		// Parity control disabled
#define UART_STOPBITS_1			0x00000000U			// 1 stop bit


void set_ahb1_periph_clock(uint32_t periphs);
void set_pin_mode(GPIO_TypeDef *GPIOx, uint32_t Pin, uint32_t Mode);
void set_apb1_periph_clock(uint32_t periphs);
void config_uart_parameters(USART_TypeDef *USARTx, uint32_t DataWidth, uint32_t Parity, uint32_t StopBits);
uint16_t compute_uart_div(uint32_t PeriphClk, uint32_t BaudRate);
void uart_set_baudrate(USART_TypeDef *USARTx, uint32_t PeriphClk, uint32_t BaudRate);
void uart_enable(USART_TypeDef *USARTx);
void uart_write(USART_TypeDef *USARTx, uint8_t value);
void uart3_tx_init(void);
void set_uart_transfer_direction(USART_TypeDef *USARTx, uint32_t TransferDirection);

int __io_putchar(int ch)
{
  uart_write(USART3, ch);
  return ch;
}

int main(void)
{
  int x;
  uart3_tx_init();


	while(1)
	{
    printf("Hello from STM32F7.....\n\r");
    for(int i=0;i<9000;i++)
    {
      x++;
    }


	}
}



void uart_write(USART_TypeDef *USARTx, uint8_t value)
{
  // Make sure transmit data register is empty
  while (!((USARTx->ISR & USART_ISR_TXE) == USART_ISR_TXE)){}
  /*while (!(USARTx->ISR & USART_ISR_TXE)){}*/

  // Write value into transmit data register
  USARTx->TDR = value;
}

void uart3_tx_init(void)
{
	// 1.Enable clock access to GPIOD
	set_ahb1_periph_clock(GPIODEN);

	// 2.Set PD8 to mode to alternate function
	set_pin_mode(GPIOD, UART3_TX, GPIO_ALTERNATE_MODE);

	// 3. Set alternate function to USART
	GPIOD->AFR[1] |= (1U<<0);
	GPIOD->AFR[1] |= (1U<<1);
	GPIOD->AFR[1] |= (1U<<2);
	GPIOD->AFR[1] &=~ (1U<<3);

	// Enable clock to the USART3 module
	set_apb1_periph_clock(USART3EN);

	// Configure USART parameters
	config_uart_parameters(USART3, UART_DATAWIDTH_8B, UART_PARITY_NONE, UART_STOPBITS_1);
  set_uart_transfer_direction(USART3, USART_CR1_TE);

	// Set baudrate
  uart_set_baudrate(USART3, 16000000, 115200);

	// Enable USART
  /*USART3->CR1 |= USART_CR1_UE;*/
  // SET_BIT(USART3->CR1, USART_CR1_UE);
  uart_enable(USART3);
}


void uart_enable(USART_TypeDef *USARTx)
{
  SET_BIT(USARTx->CR1, USART_CR1_UE);
}

void set_uart_transfer_direction(USART_TypeDef *USARTx, uint32_t TransferDirection)
{
  MODIFY_REG(USARTx->CR1, USART_CR1_RE | USART_CR1_TE, TransferDirection);
}

void uart_set_baudrate(USART_TypeDef *USARTx, uint32_t PeriphClk, uint32_t BaudRate)
{
  USARTx->BRR = compute_uart_div(PeriphClk, BaudRate);
}

void config_uart_parameters(USART_TypeDef *USARTx, uint32_t DataWidth, uint32_t Parity, uint32_t StopBits)
{
	MODIFY_REG(USARTx->CR1, USART_CR1_PS | USART_CR1_PCE | USART_CR1_M, Parity | DataWidth);

	MODIFY_REG(USARTx->CR2, USART_CR2_STOP, StopBits);
}

void set_ahb1_periph_clock(uint32_t periphs)
{
	SET_BIT(RCC->AHB1ENR, periphs);
}

void set_ahb2_periph_clock(uint32_t periphs)
{
	SET_BIT(RCC->AHB2ENR, periphs);
}

void set_apb1_periph_clock(uint32_t periphs)
{
	SET_BIT(RCC->APB1ENR, periphs);
}

void set_apb2_periph_clock(uint32_t periphs)
{
	SET_BIT(RCC->APB1ENR, periphs);
}

void set_pin_mode(GPIO_TypeDef *GPIOx, uint32_t Pin, uint32_t Mode)
{
	/* 0x3 = 0b11
	 *
	 * (1U<<8) = 0000 0000 0000 0000 0000 0001 0000 0000
	 * rbit = 0000 0000 1000 0000 0000 0000 0000 0000
	 * clz = 8
	 * POSITION_VAL(1U<<8) *2 = 16
	 * 0x3 << 16 = (1U<<16) | (1U<<17)
	 * CLEAR((1U<<16) | (1U<<17)) ==> bit16 = 0, bit17 = 0
	 *
	 * Mode = 0b10 = 0x2
	 * 2 << 16 ==> bit16 = 0, bit17 = 1
	 * */

	MODIFY_REG(GPIOx->MODER, (0x3<<(POSITION_VAL(Pin)*2U)), (Mode<<(POSITION_VAL(Pin)*2U)));
}

uint16_t compute_uart_div(uint32_t PeriphClk, uint32_t BaudRate)
{
  return ((PeriphClk + (BaudRate/2U))/BaudRate);
}
