/*
  EECS461
  Lab 4
   Revision History
     2020-09-23  jfr
     2021-01-12  jfr
     2022-08-12  jfr
     2023-08-18  jfr
*/
#include "eecs461.h"
#include "qd.h"
#include "pwm.h"
#include "worlds.h"
#include "adc.h"


int main(void)
{
  int section = 6;
  initEECS461();
  
  // Initialize QD and ADC
  /* fill in */
  initQD();
  init_ADC0_single();
  // Initialize PWMs
  initPWMPCRs();
  uint32_t iAnalog;
  double test;
  float angle;
  float t;
  int32_t enc;
  initPWM(MOTOR_SUBMODULE , MOTOR_CHANNEL, MOTOR_FREQUENCY, .5);
  initPWM(FILTER_SUBMODULE , FILTER_CHANNEL, FILTER_FREQUENCY, FILTER_DUTY_CYCLE);
  init_ADC0_single();
  initGPDO(3, 2);

  while(1)
  {
    switch(section)
    {
	case 1: // 0 Torque
	  outputTorque(0);
	  break;
    case 2: //Analog Input Control of PWM
      iAnalog = read_ADC0_single(0);
      test = iAnalog*(.76-.24)/5000+.24;
      setPWM(MOTOR_SUBMODULE , MOTOR_CHANNEL, MOTOR_FREQUENCY, iAnalog*(.76-.24)/5000+.24);
      break;
    case 3: //Change PWM Frequency to 1 kHz torque = 0 N-mm
      outputTorque(0);
      break;
    case 4: //Set torque to 200 N-mm
      outputTorque(-200);
      break;
    case 5: //Virtual Spring
      writeGPIO(3, 2, 0b1);
      angle = updateAngle();
      t = virtualSpring(angle);
      outputTorque(t);
      writeGPIO(3, 2, 0b0);
      break;
    case 6: // Virtual Wall

      angle = updateAngle();
      t = virtualWall(angle);
      outputTorque(t);
      break;
    }
  }
}
