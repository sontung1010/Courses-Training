/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: twofourbit_adder.h
 *
 * Code generated for Simulink model 'twofourbit_adder'.
 *
 * Model version                   : 6.0
 * Simulink Coder version          : 9.8 (R2022b) 13-May-2022
 * MBDT for S32K1xx Series Version : 4.3.0 (R2016a-R2022a) 13-Sep-2022
 * C/C++ source code generated on  : Thu Nov  9 14:29:10 2023
 *
 * Target selection: mbd_s32k.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_twofourbit_adder_h_
#define RTW_HEADER_twofourbit_adder_h_
#ifndef twofourbit_adder_COMMON_INCLUDES_
#define twofourbit_adder_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "pcc_hw_access.h"
#include "pins_driver.h"
#endif                                 /* twofourbit_adder_COMMON_INCLUDES_ */

#include "twofourbit_adder_types.h"
#include <stddef.h>
#include <string.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  boolean_T Digital_Input;             /* '<S3>/Digital_Input' */
  boolean_T Digital_Input1;            /* '<S3>/Digital_Input1' */
  boolean_T Digital_Input2;            /* '<S3>/Digital_Input2' */
  boolean_T Digital_Input3;            /* '<S3>/Digital_Input3' */
  boolean_T Digital_Input_e;           /* '<S2>/Digital_Input' */
  boolean_T Digital_Input1_g;          /* '<S2>/Digital_Input1' */
  boolean_T Digital_Input2_h;          /* '<S2>/Digital_Input2' */
  boolean_T Digital_Input3_p;          /* '<S2>/Digital_Input3' */
  boolean_T DataTypeConversion;        /* '<S4>/Data Type Conversion' */
  boolean_T DataTypeConversion1;       /* '<S4>/Data Type Conversion1' */
  boolean_T DataTypeConversion2;       /* '<S4>/Data Type Conversion2' */
  boolean_T DataTypeConversion3;       /* '<S4>/Data Type Conversion3' */
  boolean_T DataTypeConversion4;       /* '<S4>/Data Type Conversion4' */
} B_twofourbit_adder_T;

/* Real-time Model Data Structure */
struct tag_RTM_twofourbit_adder_T {
  const char_T * volatile errorStatus;
};

/* Block signals (default storage) */
extern B_twofourbit_adder_T twofourbit_adder_B;

/* Model entry point functions */
extern void twofourbit_adder_initialize(void);
extern void twofourbit_adder_step(void);
extern void twofourbit_adder_terminate(void);

/* Real-time Model object */
extern RT_MODEL_twofourbit_adder_T *const twofourbit_adder_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S2>/Shift Arithmetic' : Eliminated trivial shift
 * Block '<S3>/Shift Arithmetic' : Eliminated trivial shift
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
 * '<Root>' : 'twofourbit_adder'
 * '<S1>'   : 'twofourbit_adder/Adder Task'
 * '<S2>'   : 'twofourbit_adder/Adder Task/Read DIP 10-13'
 * '<S3>'   : 'twofourbit_adder/Adder Task/Read DIP 6-9'
 * '<S4>'   : 'twofourbit_adder/Adder Task/Write 5 Bits'
 */
#endif                                 /* RTW_HEADER_twofourbit_adder_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
