#include <stdio.h>
#include "stm32f7xx.h"
#include "uart.h"
#include "led.h"
#include "spi.h"


uint8_t tx_buff[] = "Hello from SPI";
uint8_t tx_size = sizeof(tx_buff);
volatile uint8_t tx_idx = 0;

uint8_t rx_buff[sizeof(tx_buff)];
uint8_t rx_size = sizeof(tx_buff);
volatile uint8_t rx_idx = 0;

int main(void)
{
  // Configure master device
  spi1_config();

  // Configure slave device
  spi3_config();

  // Enable slave (RX) device
  spi3_activate();

  // Enable master (TX) device
  spi1_activate();




	while(1)
	{

	}
}


void spi1_callback(void){
  volatile uint8_t *spidr = ((volatile uint8_t *)&SPI1->DR);
  *spidr = tx_buff[tx_idx++];
}

void SPI1_IRQHandler(void){
  // Check TXE flag value in SR register
  if((SPI1->SR & (1U<<1))){
    // Do something
    spi1_callback();
  }
}

void spi3_callback(void){
  rx_buff[rx_idx++] = SPI3->DR;
}

void SPI3_IRQHandler(void){
  // Check RXNE flag value in SR register
  if((SPI3->SR & (1U<<0))){
    // Do something
    spi3_callback();
  }
}
