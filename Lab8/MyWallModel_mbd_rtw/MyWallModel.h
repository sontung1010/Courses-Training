/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: MyWallModel.h
 *
 * Code generated for Simulink model 'MyWallModel'.
 *
 * Model version                   : 1.8
 * Simulink Coder version          : 9.8 (R2022b) 13-May-2022
 * MBDT for S32K1xx Series Version : 4.3.0 (R2016a-R2022a) 13-Sep-2022
 * C/C++ source code generated on  : Thu Nov  9 15:35:02 2023
 *
 * Target selection: mbd_s32k.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_MyWallModel_h_
#define RTW_HEADER_MyWallModel_h_
#ifndef MyWallModel_COMMON_INCLUDES_
#define MyWallModel_COMMON_INCLUDES_
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
#endif                                 /* MyWallModel_COMMON_INCLUDES_ */

#include "MyWallModel_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  real32_T Saturation;                 /* '<S4>/Saturation' */
  real32_T torque;                     /* '<S3>/Chart' */
  uint16_T Quadrature_Decoder_o1;      /* '<S2>/Quadrature_Decoder' */
  boolean_T Quadrature_Decoder_o2;     /* '<S2>/Quadrature_Decoder' */
  boolean_T Quadrature_Decoder_o3;     /* '<S2>/Quadrature_Decoder' */
  boolean_T Quadrature_Decoder_o4;     /* '<S2>/Quadrature_Decoder' */
} B_MyWallModel_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real32_T UnitDelay1_DSTATE;          /* '<S5>/Unit Delay1' */
  uint16_T UnitDelay_DSTATE;           /* '<S5>/Unit Delay' */
  uint8_T is_c3_MyWallModel;           /* '<S3>/Chart' */
  uint8_T is_active_c3_MyWallModel;    /* '<S3>/Chart' */
} DW_MyWallModel_T;

/* Real-time Model Data Structure */
struct tag_RTM_MyWallModel_T {
  const char_T * volatile errorStatus;
};

/* Block signals (default storage) */
extern B_MyWallModel_T MyWallModel_B;

/* Block states (default storage) */
extern DW_MyWallModel_T MyWallModel_DW;

/* Model entry point functions */
extern void MyWallModel_initialize(void);
extern void MyWallModel_step(void);
extern void MyWallModel_terminate(void);

/* Real-time Model object */
extern RT_MODEL_MyWallModel_T *const MyWallModel_M;

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
 * '<Root>' : 'MyWallModel'
 * '<S1>'   : 'MyWallModel/Subsystem'
 * '<S2>'   : 'MyWallModel/Triggered Subsystem'
 * '<S3>'   : 'MyWallModel/Triggered Subsystem/Subsystem'
 * '<S4>'   : 'MyWallModel/Triggered Subsystem/Subsystem1'
 * '<S5>'   : 'MyWallModel/Triggered Subsystem/Subsystem2'
 * '<S6>'   : 'MyWallModel/Triggered Subsystem/Subsystem/Chart'
 */
#endif                                 /* RTW_HEADER_MyWallModel_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
