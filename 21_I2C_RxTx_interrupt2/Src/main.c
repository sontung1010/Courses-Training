#include <stdio.h>
#include "stm32f7xx.h"
#include "uart.h"
#include "led.h"
#include "spi.h"
#include "i2c.h"


// Buffer used for transmission
const uint8_t msg[] = "HELLO";

uint8_t* p_tx_buff = (uint8_t*)msg;
uint8_t tx_size = sizeof(msg);
volatile uint8_t tx_idx = 0;


// Buffer used for reception
uint8_t rx_buff[sizeof(msg)];
uint8_t rx_size = sizeof(msg);
volatile uint8_t rx_idx = 0;

static void handle_i2c_master(void);

// Connect jumper
// SCL on PB10, SDA on PB11
// SCL on PB6, SDA on PB9

int main(void)
{
  uart3_tx_init();
  i2c2_slave_config();
  i2c1_master_config();
  handle_i2c_master();



	while(1)
	{

	}
}



static void handle_i2c_master(void){
  // Set slave address
  I2C1->CR2 |= SLAVE_OWN_ADDRESS;

  // Set 7-bits address mode
  I2C1->CR2 &=~ (1U<<11);

  // Set transfer size
  I2C1->CR2 |= (tx_size<<16);

  // Set automatic end mode
  I2C1->CR2 |= (1U<<25);

  // Generate start condition
  I2C1->CR2 |= (1U<<13);

  // Loop until STOP flag is raised
  while(!(I2C1->ISR & (1U<<5))){
    // Write data in Transmit Data register
    // TXIS flag is cleared by writing data in TXDR register
    I2C1->TXDR = (*p_tx_buff++);
  }

  // Clear stop flag
  I2C1->ICR |= (1U<<5);
}


void slave_reception_callback(void){
  // Read character in Receive Data register
  // RXNE flag is cleared by reading data in RXDR register

  // Read first 8 bits
  rx_buff[rx_idx++] = (I2C2->RXDR & 0xFF);
}

void slave_complete_callback(void){
  printf("Transmission complete ..\n\r");
}

void I2C2_EV_IRQHandler(void){
  // Check ADDR flag value in ISR register
  if(I2C2->ISR & (1U<<3)){
    // Verify the Address Match with the OWN Slave address
    if(i2c2_get_address_matchcode() == SLAVE_OWN_ADDRESS){
      // Clear ADDR flag value in ISR register
      I2C2->ICR |= (1U<<3);

      // Enable Receive Interrupt
      I2C2->CR1 |= (1U<<2);
    }
  }

  // Check RXNE flag value in ISR register
  else if(I2C2->ISR & (1U<<2)){
    // Do something
    slave_reception_callback();
  }

  // Check STOP flag value in ISR register
  else if(I2C2->ISR & (1U<<5)){
    I2C2->ICR |= (1U<<5);

    // Do something
    slave_complete_callback();
  }

  else{
    // Implement error
  }
}
