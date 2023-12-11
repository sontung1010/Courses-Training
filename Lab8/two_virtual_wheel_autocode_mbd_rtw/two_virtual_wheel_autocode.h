/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: two_virtual_wheel_autocode.h
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

#ifndef RTW_HEADER_two_virtual_wheel_autocode_h_
#define RTW_HEADER_two_virtual_wheel_autocode_h_
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
#include "fast.h"
#include "slow.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmStepTask
#define rtmStepTask(rtm, idx)          ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmTaskCounter
#define rtmTaskCounter(rtm, idx)       ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

/* Block signals (default storage) */
typedef struct {
  real32_T RateTransition1;            /* '<Root>/Rate Transition1' */
  real32_T Saturation;                 /* '<S6>/Saturation' */
  real32_T outPos;                     /* '<Root>/Chart' */
  uint16_T Quadrature_Decoder_o1;      /* '<Root>/Quadrature_Decoder' */
  boolean_T Quadrature_Decoder_o2;     /* '<Root>/Quadrature_Decoder' */
  boolean_T Quadrature_Decoder_o3;     /* '<Root>/Quadrature_Decoder' */
  boolean_T Quadrature_Decoder_o4;     /* '<Root>/Quadrature_Decoder' */
} B_two_virtual_wheel_autocode_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real32_T UnitDelay1_DSTATE;          /* '<S5>/Unit Delay1' */
  real32_T RateTransition1_Buffer0;    /* '<Root>/Rate Transition1' */
  real32_T RateTransition_Buffer;      /* '<Root>/Rate Transition' */
  uint16_T UnitDelay_DSTATE;           /* '<S5>/Unit Delay' */
  uint8_T is_c3_two_virtual_wheel_autocod;/* '<Root>/Chart' */
  uint8_T is_active_c3_two_virtual_wheel_;/* '<Root>/Chart' */
  DW_fast_T Subsystem;                 /* '<Root>/Subsystem' */
  DW_slow_T Subsystem1;                /* '<Root>/Subsystem1' */
} DW_two_virtual_wheel_autocode_T;

/* Real-time Model Data Structure */
struct tag_RTM_two_virtual_wheel_aut_T {
  const char_T * volatile errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    uint32_T clockTick1;
    struct {
      uint8_T TID[2];
    } TaskCounters;

    struct {
      boolean_T TID0_1;
    } RateInteraction;
  } Timing;
};

/* Block signals (default storage) */
extern B_two_virtual_wheel_autocode_T two_virtual_wheel_autocode_B;

/* Block states (default storage) */
extern DW_two_virtual_wheel_autocode_T two_virtual_wheel_autocode_DW;

/* External function called from main */
extern void two_virtual_wheel_autocode_SetEventsForThisBaseStep(boolean_T
  *eventFlags);

/* Model entry point functions */
extern void two_virtual_wheel_autocode_initialize(void);
extern void two_virtual_wheel_autocode_step0(void);
extern void two_virtual_wheel_autocode_step1(void);
extern void two_virtual_wheel_autocode_terminate(void);

/* Real-time Model object */
extern RT_MODEL_two_virtual_wheel_au_T *const two_virtual_wheel_autocode_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S5>/Data Type Conversion' : Eliminate redundant data type conversion
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'two_virtual_wheel_autocode'
 * '<S1>'   : 'two_virtual_wheel_autocode/Chart'
 * '<S2>'   : 'two_virtual_wheel_autocode/Subsystem'
 * '<S3>'   : 'two_virtual_wheel_autocode/Subsystem1'
 * '<S4>'   : 'two_virtual_wheel_autocode/Subsystem2'
 * '<S5>'   : 'two_virtual_wheel_autocode/Subsystem3'
 * '<S6>'   : 'two_virtual_wheel_autocode/Subsystem4'
 */
#endif                            /* RTW_HEADER_two_virtual_wheel_autocode_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
