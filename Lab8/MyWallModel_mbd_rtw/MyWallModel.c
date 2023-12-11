/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: MyWallModel.c
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

#include "MyWallModel.h"
#include "rtwtypes.h"
#include "MyWallModel_private.h"

/* Named constants for Chart: '<S3>/Chart' */
#define MyWallModel_IN_InsideWall      ((uint8_T)1U)
#define MyWallModel_IN_OutsideWall     ((uint8_T)2U)

/* Block signals (default storage) */
B_MyWallModel_T MyWallModel_B;

/* Block states (default storage) */
DW_MyWallModel_T MyWallModel_DW;

/* Real-time model */
static RT_MODEL_MyWallModel_T MyWallModel_M_;
RT_MODEL_MyWallModel_T *const MyWallModel_M = &MyWallModel_M_;

/* Model step function */
void MyWallModel_step(void)
{
  real32_T tmp;

  /* S-Function (fcgen): '<Root>/Function-Call Generator' incorporates:
   *  SubSystem: '<Root>/Triggered Subsystem'
   */
  /* S-Function (ftm_s32k_quadrature_decoder): '<S2>/Quadrature_Decoder' */

  /* FTM2: get counter value */
  MyWallModel_B.Quadrature_Decoder_o2 = FTM_DRV_GetQuadDir(FTM2);
  MyWallModel_B.Quadrature_Decoder_o4 = FTM_DRV_GetQuadTimerOverflowDir(FTM2);
  MyWallModel_B.Quadrature_Decoder_o3 = FTM_DRV_HasTimerOverflowed(FTM2);
  MyWallModel_B.Quadrature_Decoder_o1 = FTM_DRV_GetCounter(FTM2);
  FTM_DRV_ClearTimerOverflow(FTM2);

  /* Sum: '<S5>/Sum1' incorporates:
   *  DataTypeConversion: '<S5>/Data Type Conversion1'
   *  DataTypeConversion: '<S5>/Data Type Conversion2'
   *  Gain: '<S5>/Gain'
   *  Sum: '<S5>/Sum'
   *  UnitDelay: '<S5>/Unit Delay'
   *  UnitDelay: '<S5>/Unit Delay1'
   */
  MyWallModel_DW.UnitDelay1_DSTATE += (real32_T)(int16_T)
    (MyWallModel_B.Quadrature_Decoder_o1 - MyWallModel_DW.UnitDelay_DSTATE) *
    0.09F;

  /* Chart: '<S3>/Chart' incorporates:
   *  UnitDelay: '<S5>/Unit Delay1'
   */
  if (MyWallModel_DW.is_active_c3_MyWallModel == 0U) {
    MyWallModel_DW.is_active_c3_MyWallModel = 1U;
    MyWallModel_DW.is_c3_MyWallModel = MyWallModel_IN_OutsideWall;
  } else if (MyWallModel_DW.is_c3_MyWallModel == MyWallModel_IN_InsideWall) {
    if (MyWallModel_DW.UnitDelay1_DSTATE < 0.0F) {
      MyWallModel_DW.is_c3_MyWallModel = MyWallModel_IN_OutsideWall;
    } else {
      MyWallModel_B.torque = 500.0F * MyWallModel_DW.UnitDelay1_DSTATE;
    }

    /* case IN_OutsideWall: */
  } else if (MyWallModel_DW.UnitDelay1_DSTATE >= 0.0F) {
    MyWallModel_DW.is_c3_MyWallModel = MyWallModel_IN_InsideWall;
  } else {
    MyWallModel_B.torque = 0.0F;
  }

  /* End of Chart: '<S3>/Chart' */

  /* Saturate: '<S3>/Saturation' */
  if (MyWallModel_B.torque > 822.0F) {
    tmp = 822.0F;
  } else if (MyWallModel_B.torque < -822.0F) {
    tmp = -822.0F;
  } else {
    tmp = MyWallModel_B.torque;
  }

  /* Saturate: '<S4>/Saturation' incorporates:
   *  Constant: '<S4>/Constant'
   *  Gain: '<S4>/Gain'
   *  Saturate: '<S3>/Saturation'
   *  Sum: '<S4>/Sum'
   */
  MyWallModel_B.Saturation = 0.0003162F * tmp + 0.5F;

  /* S-Function (ftm_s32k_pwm_config): '<S4>/FTM_PWM_Config' */
  {
    uint16_t dutyA = FTM_MAX_DUTY_CYCLE * MyWallModel_B.Saturation;
    FTM_DRV_UpdatePwmChannel(FTM_PWM0, 0U, FTM_PWM_UPDATE_IN_DUTY_CYCLE, dutyA,
      0, true);
  }

  /* Update for UnitDelay: '<S5>/Unit Delay' */
  MyWallModel_DW.UnitDelay_DSTATE = MyWallModel_B.Quadrature_Decoder_o1;

  /* End of Outputs for S-Function (fcgen): '<Root>/Function-Call Generator' */

  /* S-Function (ftm_s32k_pwm_config): '<S1>/FTM_PWM_Config' incorporates:
   *  Constant: '<S1>/Constant'
   */
  {
    uint16_t dutyA = FTM_MAX_DUTY_CYCLE * 0.5F;
    FTM_DRV_UpdatePwmChannel(FTM_PWM3, 0U, FTM_PWM_UPDATE_IN_DUTY_CYCLE, dutyA,
      0, true);
  }
}

/* Model initialize function */
void MyWallModel_initialize(void)
{
  /* Start for S-Function (ftm_s32k_pwm_config): '<S1>/FTM_PWM_Config' incorporates:
   *  Constant: '<S1>/Constant'
   */

  /* Enable clock for PORTB */
  PCC_SetClockMode (PCC, PCC_PORTB_CLOCK, true);

  /* Pin is configured for FTM function */
  PINS_SetMuxModeSel (PORTB, 8, PORT_MUX_ALT2);

  /* Set FTM_3 clock source */
  PCC_SetPeripheralClockControl (PCC, FTM3_CLK, true, CLK_SRC_SPLL, 0, 0);

  /* Enable clock for FTM_3 */
  PCC_SetClockMode (PCC, FTM3_CLK, true);

  /* PWM3 initialization */
  FTM_DRV_Init (FTM_PWM3, &flexTimer_pwm3_InitConfig, &ftmStateStruct3);
  FTM_DRV_InitPwm (FTM_PWM3, &flexTimer_pwm3_PwmConfig);
  FTM_DRV_SetChnTriggerCmd(FTM3, 1, false);

  /* SystemInitialize for S-Function (fcgen): '<Root>/Function-Call Generator' incorporates:
   *  SubSystem: '<Root>/Triggered Subsystem'
   */

  /* Start for S-Function (ftm_s32k_quadrature_decoder): '<S2>/Quadrature_Decoder' */
  {
    ftm_user_config_t ftm2_qd_InitConfig = {
      {
        true,                          /* Software trigger state */
        false,                         /* Hardware trigger 1 state */
        false,                         /* Hardware trigger 2 state */
        false,                         /* Hardware trigger 3 state */
        false,                         /* Max loading point state */
        false,                         /* Min loading point state */
        FTM_SYSTEM_CLOCK,              /* Update mode for INVCTRL register */
        FTM_SYSTEM_CLOCK,              /* Update mode for SWOCTRL register */
        FTM_SYSTEM_CLOCK,              /* Update mode for OUTMASK register */
        FTM_SYSTEM_CLOCK,              /* Update mode for CNTIN register */
        false,                         /* Automatic clear of the trigger*/
        FTM_UPDATE_NOW,                /* Synchronization point */
      },
      FTM_MODE_QUADRATURE_DECODER,     /* Mode of operation for FTM */
      FTM_CLOCK_DIVID_BY_1,            /* FTM clock prescaler */
      FTM_CLOCK_SOURCE_SYSTEMCLK,      /* FTM clock source */
      FTM_BDM_MODE_00,                 /* FTM debug mode */
      false,                           /* Interrupt state */
      false                            /* Initialization trigger */
    };

    ftm_quad_decode_config_t ftm2_qd_Params = {
      FTM_QUAD_PHASE_ENCODE,           /* Quadrature decoder mode */
      0,                               /* Initial counter value */
      65535,                           /* Maximum counter value */

      {
        false,                         /* Filter state */
        0,                             /* Filter value */
        FTM_QUAD_PHASE_NORMAL          /* Phase polarity */
      },

      {
        false,                         /* Filter state */
        0,                             /* Filter value */
        FTM_QUAD_PHASE_NORMAL          /* Phase polarity */
      }
    };

    /* Enable clock for PORTA */
    PCC_SetClockMode(PCC, PCC_PORTA_CLOCK, true);

    /* Pin is configured for FTM function */
    PINS_SetMuxModeSel(PORTA, 13, PORT_MUX_ALT6);

    /* Enable clock for PORTA */
    PCC_SetClockMode(PCC, PCC_PORTA_CLOCK, true);

    /* Pin is configured for FTM function */
    PINS_SetMuxModeSel(PORTA, 12, PORT_MUX_ALT6);

    /* Set FTM_2 clock source */
    PCC_SetPeripheralClockControl (PCC, FTM2_CLK, true, CLK_SRC_SPLL, 0, 0);

    /* Enable clock for FTM_2 */
    PCC_SetClockMode (PCC, FTM2_CLK, true);

    /* Initialize FTM instance QD decoder*/
    static ftm_state_t ftm2StateStruct;
    FTM_DRV_Init(2, &ftm2_qd_InitConfig, &ftm2StateStruct);

    /* Start QD decoder*/
    FTM_DRV_QuadDecodeStart(2, &ftm2_qd_Params);
  }

  /* Start for S-Function (ftm_s32k_pwm_config): '<S4>/FTM_PWM_Config' */

  /* Enable clock for PORTB */
  PCC_SetClockMode (PCC, PCC_PORTB_CLOCK, true);

  /* Pin is configured for FTM function */
  PINS_SetMuxModeSel (PORTB, 12, PORT_MUX_ALT2);

  /* Set FTM_0 clock source */
  PCC_SetPeripheralClockControl (PCC, FTM0_CLK, true, CLK_SRC_SPLL, 0, 0);

  /* Enable clock for FTM_0 */
  PCC_SetClockMode (PCC, FTM0_CLK, true);

  /* PWM0 initialization */
  FTM_DRV_Init (FTM_PWM0, &flexTimer_pwm0_InitConfig, &ftmStateStruct0);
  FTM_DRV_InitPwm (FTM_PWM0, &flexTimer_pwm0_PwmConfig);
  FTM_DRV_SetChnTriggerCmd(FTM0, 1, false);

  /* End of SystemInitialize for S-Function (fcgen): '<Root>/Function-Call Generator' */
}

/* Model terminate function */
void MyWallModel_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
