#include "stm32f7xx.h"


#define GPIOB_CLK_EN 		(1U<<1) 	// 0000 0000 0000 0000 0000 0000 0000 0010

#define USER_LED1_MODER		(1U<<0)		// 0000 0000 0000 0000 0000 0000 0000 0001
#define USER_LED2_MODER 	(1U<<14)
#define USER_LED3_MODER 	(1U<<28)

#define USER_LED1 			(1U<<0)		// Green Led
#define USER_LED2			(1U<<7)		// Blue Led
#define USER_LED3 			(1U<<14)	// Red Led

int main(void)
{
	/*Enable clock access to Port B*/

	RCC->AHB1ENR |= GPIOB_CLK_EN;

	// Configure led pins as output pins

	GPIOB->MODER |= USER_LED1_MODER | USER_LED2_MODER | USER_LED3_MODER;

	while(1)
	{

		// Experiment 2: toggle

		GPIOB->ODR ^= USER_LED1 | USER_LED2 | USER_LED3;
		for(int i=0;i<1000000;i++){}
	}
}
