/*
   worlds.c
   University of Michigan
   EECS 461, Embedded Control Systems
   Virtual Worlds

   Revision History
     2011-12-01  Jay Patel
     2014-02-24  Scott Kenyon
     2017-03-14  RMC
     2020-09-23  jfr
     2021-01-12  jfr
     2022-08-12  jfr
     2023-08-18  jfr
 */

#include "worlds.h"
#include "gpio.h"

extern float k;
extern float J;
//====================LAB 4================================
/***************************************************************************
 * Virtual Wall
 ***************************************************************************/
float virtualWall(float angle)
{
  if (angle > 0)
  {
    return -200 * angle;
  }
  else
  {
    return 0;
  }
}

/***************************************************************************
 * Virtual Spring
 ***************************************************************************/
float virtualSpring(float angle)
{
  return -10 * angle;
}

//====================LAB 6================================
/***************************************************************************
 * Virtual Spring Damper
 ***************************************************************************/
float virtualSpringDamper(float angle, float velocity)
{
  float b = 0.5;
  //float b = 0.64749;
  return -10 * angle - b * velocity;
}

/***************************************************************************
 * Virtual Wall Damper
 ***************************************************************************/
float virtualWallDamper(float angle, float velocity)
{
  float b = 0;
  float k = 500;
  if (readGPIO(4, 6) == 1)
  {
    b = .25;
  }
  if (angle > 0)
  {
    return -k * angle - b * velocity;
  }
  else
  {
    return 0;
  }
}

/***************************************************************************
 * Virtual Spring Mass
 ***************************************************************************/
float virtualSpringMass(float angle)
{
  static float angle2 = 0;
  static float velocity2 = 0;
  float k = 160 / 9;
  float J = 0.450316;
  float tempAng = angle2;
  angle2 += TIMESTEP * velocity2;
  velocity2 += -k * TIMESTEP / J * tempAng + k * TIMESTEP / J * angle;
  return k * (tempAng - angle);
}

/***************************************************************************
 * Virtual Spring Mass Damper
 ***************************************************************************/
float virtualSpringMassDamper(float angle, float velocity)
{
  static float angle2 = 0.0;
  static float velocity2 = 0.0;
  //float k = 160.0 / 9.0;
  //float J = 0.450316;
  float b = 4.0 / 225.0;
  float tempAng = angle2;
  float tempVel = velocity2;
  angle2 += TIMESTEP * velocity2;
  velocity2 = -k * TIMESTEP / J * tempAng + (1 - b * TIMESTEP / J) * velocity2 + k * TIMESTEP / J * angle + b * TIMESTEP / J * velocity;
  return (k * (tempAng - angle) + b * (tempVel - velocity));
}

/***************************************************************************
 * Virtual Knob
 ***************************************************************************/
float virtualKnob(float angle, float velocity)
{
  static float spot = 0.0;
  float gap = 45.0; // angle between detents
  float k = 70.0;
  float b = 1;
    if (angle - spot > gap / 2)
    {
      spot += gap;
    }

    if (angle - spot < -gap / 2)
    {
      spot -= gap;

  }
  return -k * (angle - spot) - b * velocity;
}
