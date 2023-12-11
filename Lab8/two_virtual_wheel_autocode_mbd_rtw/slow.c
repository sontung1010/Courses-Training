/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: slow.c
 *
 * Code generated for Simulink model 'two_virtual_wheel_autocode'.
 *
 * Model version                   : 6.5
 * Simulink Coder version          : 9.8 (R2022b) 13-May-2022
 * MBDT for S32K1xx Series Version : 4.3.0 (R2016a-R2022a) 13-Sep-2022
 * C/C++ source code generated on  : Thu Nov  9 16:25:47 2023
 *
 * Target selection: mbd_s32k.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objective: Traceability
 * Validation result: Not run
 */

#include "slow.h"
#include "rtwtypes.h"
#include "two_virtual_wheel_autocode.h"

/* System initialize for function-call system: '<Root>/Subsystem1' */
void slow_Init(RT_MODEL_two_virtual_wheel_au_T * const
               two_virtual_wheel_autocode_M, DW_slow_T *localDW)
{
  localDW->Subsystem1_PREV_T = two_virtual_wheel_autocode_M->Timing.clockTick1;
}

/* Output and update for function-call system: '<Root>/Subsystem1' */
void slow(RT_MODEL_two_virtual_wheel_au_T * const two_virtual_wheel_autocode_M,
          real32_T rtu_In1, real32_T *rty_Out1, DW_slow_T *localDW)
{
  real32_T DiscreteTimeIntegrator1_DSTATE_;
  uint32_T Subsystem1_ELAPS_T;
  uint32_T Subsystem1_ELAPS_T_tmp;
  Subsystem1_ELAPS_T_tmp = two_virtual_wheel_autocode_M->Timing.clockTick1;
  Subsystem1_ELAPS_T = Subsystem1_ELAPS_T_tmp - localDW->Subsystem1_PREV_T;
  localDW->Subsystem1_PREV_T = Subsystem1_ELAPS_T_tmp;

  /* Sum: '<S3>/Sum2' incorporates:
   *  DiscreteIntegrator: '<S3>/Discrete-Time Integrator'
   *  DiscreteIntegrator: '<S3>/Discrete-Time Integrator1'
   *  Gain: '<S3>/damping1'
   *  Gain: '<S3>/spring  constant1'
   *  Sum: '<S3>/Sum5'
   */
  *rty_Out1 = (rtu_In1 - localDW->DiscreteTimeIntegrator1_DSTATE) * 7.5F - 0.15F
    * localDW->DiscreteTimeIntegrator_DSTATE;

  /* Update for DiscreteIntegrator: '<S3>/Discrete-Time Integrator1' incorporates:
   *  DiscreteIntegrator: '<S3>/Discrete-Time Integrator'
   * */
  DiscreteTimeIntegrator1_DSTATE_ = 0.02F * (real32_T)Subsystem1_ELAPS_T;
  localDW->DiscreteTimeIntegrator1_DSTATE += DiscreteTimeIntegrator1_DSTATE_ *
    localDW->DiscreteTimeIntegrator_DSTATE;

  /* Update for DiscreteIntegrator: '<S3>/Discrete-Time Integrator' incorporates:
   *  Gain: '<S3>/1//virtual inertia1'
   */
  localDW->DiscreteTimeIntegrator_DSTATE += 5.26378918F * *rty_Out1 *
    DiscreteTimeIntegrator1_DSTATE_;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
