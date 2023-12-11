/*
 * lab5.c
 *
 *  Created on: Jan 21, 2018
 *      Author: domanico
 
    Revision History:
    2020-09-27  jfr
    2021-01-12  jfr
    2021-09-30  jfr
    2022-08-12  jfr
    2023-08-18  jfr
 */

#include "S32K144.h"
#include "eecs461.h"

#include "pwm.h"
#include "LPIT.h"
#include "adc.h"
#include "gpio.h"
#include "math.h"

#define LPIT0_CHANNEL  0


int sineIndex = 0;
const float PI = 3.14159;
double sineTable[10] = {0, sin(2*3.14159*2/10), sin(2*3.14159*3/10),sin(2*3.14159*4/10),sin(2*3.14159*5/10),sin(2*3.14159*6/10),sin(2*3.14159*7/10),sin(2*3.14159*8/10),sin(2*3.14159*9/10),sin(2*3.14159*10/10)}; // Ten samples/period


void IsrA(void){
  float DC;
  int freq;
 	/* Turn on LED */
	/* fill in here */
	writeGPIO(3, 1, 0b1);

	/* Read sine value */
	/* fill in here */
	uint32_t s = read_ADC0_single(0);

	/* Calculate PWM duty cycle */
	/* fill in here */
	if (readGPIO(4, 7) == 1){
		DC = 0.8*s/5000 + 0.1;
	}
	else {
		DC = 0.2*s/5000 + 0.4;
	}
	
	/* Set PWM frequency based on dipswitch */
	/* fill in here */
	if (readGPIO(4,6) == 1){
		freq = 60000;
	}
	else {
		freq = 20000;
	}

	/* Set PWM duty cycle and frequency */
	/* fill in here */
	setPWM(MOTOR_SUBMODULE , 0, freq, DC);
	//setPWM(FILTER_SUBMODULE , FILTER_CHANNEL, freq, DC);

	/* Turn off LED */
	/* fill in here */
	writeGPIO(3,1,0b0);

	/* Clear interrupt flag */
	/* fill in here */
	clearFlagLPIT(LPIT0_CHANNEL);


}

void IsrB(void){

	/* Turn on LED */
	/* fill in here */
	writeGPIO(3, 1, 0b1);

	/* Calculate and set PWM duty cycle */
	/* fill in here */
	static int i = 0;
	float DC;
	float theta;

	theta = 2*PI*i/10;
	i = (i+1)%10;
	DC = 0.5 + 0.4*sinf(theta);
	setPWM(MOTOR_SUBMODULE , 0, 60000, DC);

	/* Turn off LED */
	/* fill in here */
	writeGPIO(3, 1, 0b0);

	/* Clear interrupt flag */
	/* fill in here */
	clearFlagLPIT(LPIT0_CHANNEL);
	
}

void IsrC(void){

	/* Turn on LED */
	/* fill in here */
	writeGPIO(3, 1, 0b1);

	/* Calculate and set PWM duty cycle */
	/* fill in here */
	setPWM(MOTOR_SUBMODULE , 0, 60000, 0.4*sineTable[sineIndex] + 0.5);
	sineIndex = (sineIndex+1)%10;

	/* Turn off LED */
	/* fill in here */
	writeGPIO(3, 1, 0b0);

	/* Clear interrupt flag */
	/* fill in here */
	clearFlagLPIT(LPIT0_CHANNEL);

}

int main(){

  initEECS461();
  enableLPIT();
  init_ADC0_single();

  /* Initialize PWMs  */
  /* fill in */
  initPWMPCRs();
  initPWM(MOTOR_SUBMODULE , MOTOR_CHANNEL, 10000, FILTER_DUTY_CYCLE);
  initPWM(FILTER_SUBMODULE , FILTER_CHANNEL, FILTER_FREQUENCY, FILTER_DUTY_CYCLE);

  /* Initialize GPIO  */
  /*   fill in    */
  initGPDI(4, 6);
  initGPDI(4, 7);
  initGPDO(3, 1);

  initLPIT(LPIT0_CHANNEL, 500, &IsrC, 0xC);

  while(1){
    /*Loop forever */
  };
}

