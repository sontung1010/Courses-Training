/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: fast.h
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

#ifndef RTW_HEADER_fast_h_
#define RTW_HEADER_fast_h_
#ifndef two_virtual_wheel_autocode_COMMON_INCLUDES_
#define two_virtual_wheel_autocode_COMMON_INCLUDES_
#include <string.h>
#include "rtwtypes.h"
#include "ftm_qd_driver.h"
#include "clock_manager.h"
#include "pcc_hw_access.h"
#include "ftm_hw_access.h"
#include "pins_port_hw_access.h"
#include "ftm_pwm_driver.h"
#include "ftm3_pwm_params.h"
#include "ftm0_pwm_params.h"
#endif                         /* two_virtual_wheel_autocode_COMMON_INCLUDES_ */

#include "two_virtual_wheel_autocode_types.h"

/* Block states (default storage) for system '<Root>/Subsystem' */
typedef struct {
  real32_T DiscreteTimeIntegrator2_DSTATE;/* '<S2>/Discrete-Time Integrator2' */
  real32_T DiscreteTimeIntegrator3_DSTATE;/* '<S2>/Discrete-Time Integrator3' */
  uint32_T Subsystem_PREV_T;           /* '<Root>/Subsystem' */
} DW_fast_T;

extern void fast_Init(RT_MODEL_two_virtual_wheel_au_T * const
                      two_virtual_wheel_autocode_M, DW_fast_T *localDW);
extern void fast(RT_MODEL_two_virtual_wheel_au_T * const
                 two_virtual_wheel_autocode_M, real32_T rtu_outPos, real32_T
                 *rty_Out1, DW_fast_T *localDW);

#endif                                 /* RTW_HEADER_fast_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
