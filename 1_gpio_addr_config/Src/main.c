// Where is the LED connected?
// - Pin ? 		green LED = 0	|	blue LED = 7 	| red RED = 14
// - Port ?		green LED = B	|	blue LED = B	| red RED = B
// -> Search the user manual because this related to the nucleo board

#define PERIPH_BASE 		0x40000000UL
#define AHB1_OFFSET 		0x00020000UL
#define AHB1PERIPH_BASE		PERIPH_BASE + AHB1_OFFSET
#define GPIOB_OFFSET		0x400UL
#define GPIOB_BASE 			AHB1PERIPH_BASE + GPIOB_OFFSET

#define RCC_OFFSET 			0x3800UL
#define RCC_BASE 			AHB1PERIPH_BASE + RCC_OFFSET
#define AHB1EN_R_OFFSET		0x30UL

#define RCC_AHB1EN_R 		(*(volatile unsigned int *)(RCC_BASE + AHB1EN_R_OFFSET))

#define MODER_OFFSET 		0x000UL
#define GPIOB_MODE_R 		(*(volatile unsigned int *)(GPIOB_BASE + MODER_OFFSET))

#define ODR_OFFSET 			0x14UL
#define GPIOB_OD_R			(*(volatile unsigned int *)(GPIOB_BASE + ODR_OFFSET))

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
	RCC_AHB1EN_R |= GPIOB_CLK_EN;

	// Configure led pins as output pins
	GPIOB_MODE_R |= USER_LED1_MODER | USER_LED2_MODER | USER_LED3_MODER;

	while(1)
	{
		// Turn on all LEDs
		// GPIOB_OD_R |= USER_LED1 | USER_LED2 | USER_LED3;

		// Experiment 2: toggle
		GPIOB_OD_R ^= USER_LED1 | USER_LED2 | USER_LED3;
		for(int i=0;i<1000000;i++){}
	}
}
