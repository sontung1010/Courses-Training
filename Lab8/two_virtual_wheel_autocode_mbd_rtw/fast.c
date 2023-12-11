/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: fast.c
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

#include "fast.h"
#include "rtwtypes.h"
#include "two_virtual_wheel_autocode.h"

/* System initialize for function-call system: '<Root>/Subsystem' */
void fast_Init(RT_MODEL_two_virtual_wheel_au_T * const
               two_virtual_wheel_autocode_M, DW_fast_T *localDW)
{
  localDW->Subsystem_PREV_T = two_virtual_wheel_autocode_M->Timing.clockTick0;
}

/* Output and update for function-call system: '<Root>/Subsystem' */
void fast(RT_MODEL_two_virtual_wheel_au_T * const two_virtual_wheel_autocode_M,
          real32_T rtu_outPos, real32_T *rty_Out1, DW_fast_T *localDW)
{
  real32_T DiscreteTimeIntegrator2_DSTATE_;
  uint32_T Subsystem_ELAPS_T;
  uint32_T Subsystem_ELAPS_T_tmp;
  Subsystem_ELAPS_T_tmp = two_virtual_wheel_autocode_M->Timing.clockTick0;
  Subsystem_ELAPS_T = Subsystem_ELAPS_T_tmp - localDW->Subsystem_PREV_T;
  localDW->Subsystem_PREV_T = Subsystem_ELAPS_T_tmp;

  /* Sum: '<S2>/Sum3' incorporates:
   *  DiscreteIntegrator: '<S2>/Discrete-Time Integrator2'
   *  DiscreteIntegrator: '<S2>/Discrete-Time Integrator3'
   *  Gain: '<S2>/damping4'
   *  Gain: '<S2>/spring  constant2'
   *  Sum: '<S2>/Sum1'
   */
  *rty_Out1 = (rtu_outPos - localDW->DiscreteTimeIntegrator2_DSTATE) * 7.5F -
    0.015F * localDW->DiscreteTimeIntegrator3_DSTATE;

  /* Update for DiscreteIntegrator: '<S2>/Discrete-Time Integrator2' incorporates:
   *  DiscreteIntegrator: '<S2>/Discrete-Time Integrator3'
   * */
  DiscreteTimeIntegrator2_DSTATE_ = 0.002F * (real32_T)Subsystem_ELAPS_T;
  localDW->DiscreteTimeIntegrator2_DSTATE += DiscreteTimeIntegrator2_DSTATE_ *
    localDW->DiscreteTimeIntegrator3_DSTATE;

  /* Update for DiscreteIntegrator: '<S2>/Discrete-Time Integrator3' incorporates:
   *  Gain: '<S2>/1//virtual inertia2'
   */
  localDW->DiscreteTimeIntegrator3_DSTATE += 6.84082031F * *rty_Out1 *
    DiscreteTimeIntegrator2_DSTATE_;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
