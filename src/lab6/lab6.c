/*
  EECS461
  Lab 6

  Revision history:
  2020-10-4  jfr
  2021-01-12 jfr
  2021-10-10 jfr
  2022-08-12 jfr
  2023-08-18 jfr

 */

#include "S32K144.h"
#include "eecs461.h"
#include "LPIT.h"
#include "LPUART.h"
#include "qd.h"
#include "pwm.h"
#include "worlds.h"

#define LPIT0_CHANNEL 0
#define ENABLE_INTERRUPTS() __asm volatile ("cpsie i" : : : "memory");
#define DISABLE_INTERRUPTS() __asm volatile ("cpsid i" : : : "memory");
float k = 160.0 / 9.0;
float J = 0.450316;
void wallDamper(void)
{
  /* ISR for the wall-damper system */

  // writeGPIO(3, 2, 0b1);
  static float angle = 0;
  float velocity = (updateAngle() - angle) / TIMESTEP;
  angle = updateAngle();
  outputTorque(virtualWallDamper(angle, velocity));
  /* Make sure to clear interrupt flag */
  clearFlagLPIT(LPIT0_CHANNEL);
}

void springDamper(void)
{
  /* ISR for the spring-damper system */
  static float angle = 0;
  float velocity = (updateAngle() - angle) / TIMESTEP;
  angle = updateAngle();
  outputTorque(virtualSpringDamper(angle, velocity));
  /* Make sure to clear interrupt flag */
  clearFlagLPIT(LPIT0_CHANNEL);
}

void springMass(void)
{
  /* ISR for the spring-mass system */
  outputTorque(virtualSpringMass(updateAngle()));
  /* Make sure to clear interrupt flag */
  clearFlagLPIT(LPIT0_CHANNEL);
}

void springMassDamper(void)
{
  /* ISR for the spring-mass-damper system */
  static float angle = 0;
  float velocity = (updateAngle() - angle) / TIMESTEP;
  angle = updateAngle();
  outputTorque(virtualSpringMassDamper(angle, velocity));
  /* Make sure to clear interrupt flag */
  clearFlagLPIT(LPIT0_CHANNEL);
}

void knobIndents(void)
{
  /* ISR for the virtual knob system */
  static float angle = 0;
  float velocity = (updateAngle() - angle) / TIMESTEP;
  angle = updateAngle();
  outputTorque(virtualKnob(angle, velocity));
  /* Make sure to clear interrupt flag */
  clearFlagLPIT(LPIT0_CHANNEL);
}

int main(void)
{
  char byte_in = 0;
  void (*interrupt)(void);
  int section = 6;
  //k =  160.0 / 9.0;
  //J =  0.450316;

  initEECS461();
  initQD();
  initGPDI(4, 6);
  enableLPIT();


  // Initialize PWMs
  initPWMPCRs();

  initPWM(MOTOR_SUBMODULE, MOTOR_CHANNEL, MOTOR_FREQUENCY, 0.5f);
  initPWM(FILTER_SUBMODULE, FILTER_CHANNEL, FILTER_FREQUENCY, 0.5f);



  if (section == 5)
  {
    LPUART1_init();
    LPUART1_transmit_string("\n\n\n\n\n\n\n\rSerial Output Enabled.");
  }
  switch (section)
  {
  case 1:
    interrupt = &wallDamper;
    break;

  case 2:
    interrupt = &springDamper;
    break;

  case 3:
    interrupt = &springMass;
    break;

  case 4:
    interrupt = &springMassDamper;
    break;

  case 5:
    interrupt = &springMassDamper;
    break;

  case 6:
    interrupt = &knobIndents;
    break;
  }

  // Fill in the arguments to initialize the appropriate interrupt routine for
  // each part of the lab. Be sure to use the correct channel specified in worlds.h
  initLPIT(LPIT0_CHANNEL, WORLDISR_FREQUENCY, interrupt, 0xC);
  while (1)
  {
    if (section == 5)
    {
      byte_in = LPUART1_receive_char();
      /* adjust K and M from the keyboard. Must be a critical section. */
      if (byte_in == 0b01110111)
      { // type w, increase k
        DISABLE_INTERRUPTS();
       k = k * 1.1;
       float testk = k;
        ENABLE_INTERRUPTS();
      }
      else if (byte_in == 0b01110011)
      { // type s decrease k
        DISABLE_INTERRUPTS();
        k = k * 0.9;
        float testk = k;
        ENABLE_INTERRUPTS();
      }
      else if (byte_in == 0b01100100)
      { // type d increase J
        DISABLE_INTERRUPTS();
        J = J * 1.1;
        float testJ = J;
        ENABLE_INTERRUPTS();
      }
      else if (byte_in == 0b01100001)
      { // type a decrease J
        DISABLE_INTERRUPTS();
        J = J * 0.9;
        float testJ = J;
        ENABLE_INTERRUPTS();
      }
    }
  }
}
