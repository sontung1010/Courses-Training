/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: two_virtual_wheel_autocode.c
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

#include "two_virtual_wheel_autocode.h"
#include "rtwtypes.h"
#include <math.h>
#include "fast.h"
#include "slow.h"
#include "two_virtual_wheel_autocode_private.h"

/* Named constants for Chart: '<Root>/Chart' */
#define two_virtual_wheel_autoc_IN_Less ((uint8_T)1U)
#define two_virtual_wheel_autoc_IN_More ((uint8_T)2U)

/* Block signals (default storage) */
B_two_virtual_wheel_autocode_T two_virtual_wheel_autocode_B;

/* Block states (default storage) */
DW_two_virtual_wheel_autocode_T two_virtual_wheel_autocode_DW;

/* Real-time model */
static RT_MODEL_two_virtual_wheel_au_T two_virtual_wheel_autocode_M_;
RT_MODEL_two_virtual_wheel_au_T *const two_virtual_wheel_autocode_M =
  &two_virtual_wheel_autocode_M_;
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to remember which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void two_virtual_wheel_autocode_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(two_virtual_wheel_autocode_M, 1));
}

/*
 *         This function updates active task flag for each subrate
 *         and rate transition flags for tasks that exchange data.
 *         The function assumes rate-monotonic multitasking scheduler.
 *         The function must be called at model base rate so that
 *         the generated code self-manages all its subrates and rate
 *         transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* To ensure a deterministic data transfer between two rates,
   * data is transferred at the priority of a fast task and the frequency
   * of the slow task.  The following flags indicate when the data transfer
   * happens.  That is, a rate interaction flag is set true when both rates
   * will run, and false otherwise.
   */

  /* tid 0 shares data with slower tid rate: 1 */
  two_virtual_wheel_autocode_M->Timing.RateInteraction.TID0_1 =
    (two_virtual_wheel_autocode_M->Timing.TaskCounters.TID[1] == 0);

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (two_virtual_wheel_autocode_M->Timing.TaskCounters.TID[1])++;
  if ((two_virtual_wheel_autocode_M->Timing.TaskCounters.TID[1]) > 9) {/* Sample time: [0.02s, 0.0s] */
    two_virtual_wheel_autocode_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/* Model step function for TID0 */
void two_virtual_wheel_autocode_step0(void) /* Sample time: [0.002s, 0.0s] */
{
  real32_T Sum3;

  {                                    /* Sample time: [0.002s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* RateTransition: '<Root>/Rate Transition1' */
  if (two_virtual_wheel_autocode_M->Timing.RateInteraction.TID0_1) {
    /* RateTransition: '<Root>/Rate Transition1' */
    two_virtual_wheel_autocode_B.RateTransition1 =
      two_virtual_wheel_autocode_DW.RateTransition1_Buffer0;
  }

  /* End of RateTransition: '<Root>/Rate Transition1' */

  /* S-Function (ftm_s32k_quadrature_decoder): '<Root>/Quadrature_Decoder' */

  /* FTM2: get counter value */
  two_virtual_wheel_autocode_B.Quadrature_Decoder_o2 = FTM_DRV_GetQuadDir(FTM2);
  two_virtual_wheel_autocode_B.Quadrature_Decoder_o4 =
    FTM_DRV_GetQuadTimerOverflowDir(FTM2);
  two_virtual_wheel_autocode_B.Quadrature_Decoder_o3 =
    FTM_DRV_HasTimerOverflowed(FTM2);
  two_virtual_wheel_autocode_B.Quadrature_Decoder_o1 = FTM_DRV_GetCounter(FTM2);
  FTM_DRV_ClearTimerOverflow(FTM2);

  /* Sum: '<S5>/Sum1' incorporates:
   *  DataTypeConversion: '<S5>/Data Type Conversion1'
   *  DataTypeConversion: '<S5>/Data Type Conversion2'
   *  Gain: '<S5>/Gain'
   *  Sum: '<S5>/Sum'
   *  UnitDelay: '<S5>/Unit Delay'
   *  UnitDelay: '<S5>/Unit Delay1'
   */
  two_virtual_wheel_autocode_DW.UnitDelay1_DSTATE += (real32_T)(int16_T)
    (two_virtual_wheel_autocode_B.Quadrature_Decoder_o1 -
     two_virtual_wheel_autocode_DW.UnitDelay_DSTATE) * 0.09F;

  /* Chart: '<Root>/Chart' incorporates:
   *  UnitDelay: '<S5>/Unit Delay1'
   */
  if (two_virtual_wheel_autocode_DW.is_active_c3_two_virtual_wheel_ == 0U) {
    two_virtual_wheel_autocode_DW.is_active_c3_two_virtual_wheel_ = 1U;
    two_virtual_wheel_autocode_DW.is_c3_two_virtual_wheel_autocod =
      two_virtual_wheel_autoc_IN_Less;
  } else if (two_virtual_wheel_autocode_DW.is_c3_two_virtual_wheel_autocod ==
             two_virtual_wheel_autoc_IN_Less) {
    if ((real32_T)fabs(two_virtual_wheel_autocode_DW.UnitDelay1_DSTATE) >= 45.0F)
    {
      two_virtual_wheel_autocode_DW.is_c3_two_virtual_wheel_autocod =
        two_virtual_wheel_autoc_IN_More;
    } else {
      two_virtual_wheel_autocode_B.outPos = 0.0F;
    }

    /* case IN_More: */
  } else if ((real32_T)fabs(two_virtual_wheel_autocode_DW.UnitDelay1_DSTATE) <
             45.0F) {
    two_virtual_wheel_autocode_DW.is_c3_two_virtual_wheel_autocod =
      two_virtual_wheel_autoc_IN_Less;
  } else {
    two_virtual_wheel_autocode_B.outPos = 45.0F;
  }

  /* End of Chart: '<Root>/Chart' */

  /* S-Function (fcgen): '<Root>/Function-Call Generator1' incorporates:
   *  SubSystem: '<Root>/Subsystem'
   */
  fast(two_virtual_wheel_autocode_M, two_virtual_wheel_autocode_B.outPos, &Sum3,
       &two_virtual_wheel_autocode_DW.Subsystem);

  /* End of Outputs for S-Function (fcgen): '<Root>/Function-Call Generator1' */

  /* Sum: '<S6>/Sum' incorporates:
   *  Constant: '<S6>/Constant'
   *  Gain: '<S6>/Gain'
   *  Sum: '<Root>/Sum4'
   */
  two_virtual_wheel_autocode_B.Saturation = ((0.0F -
    two_virtual_wheel_autocode_B.RateTransition1) - Sum3) * 0.0003162F + 0.5F;

  /* Saturate: '<S6>/Saturation' */
  if (two_virtual_wheel_autocode_B.Saturation > 0.76F) {
    /* Sum: '<S6>/Sum' incorporates:
     *  Saturate: '<S6>/Saturation'
     */
    two_virtual_wheel_autocode_B.Saturation = 0.76F;
  } else if (two_virtual_wheel_autocode_B.Saturation < 0.24F) {
    /* Sum: '<S6>/Sum' incorporates:
     *  Saturate: '<S6>/Saturation'
     */
    two_virtual_wheel_autocode_B.Saturation = 0.24F;
  }

  /* End of Saturate: '<S6>/Saturation' */

  /* S-Function (ftm_s32k_pwm_config): '<S6>/FTM_PWM_Config' */
  {
    uint16_t dutyA = FTM_MAX_DUTY_CYCLE *
      two_virtual_wheel_autocode_B.Saturation;
    FTM_DRV_UpdatePwmChannel(FTM_PWM0, 0U, FTM_PWM_UPDATE_IN_DUTY_CYCLE, dutyA,
      0, true);
  }

  /* RateTransition: '<Root>/Rate Transition' */
  if (two_virtual_wheel_autocode_M->Timing.RateInteraction.TID0_1) {
    two_virtual_wheel_autocode_DW.RateTransition_Buffer =
      two_virtual_wheel_autocode_B.outPos;
  }

  /* End of RateTransition: '<Root>/Rate Transition' */

  /* S-Function (ftm_s32k_pwm_config): '<S4>/FTM_PWM_Config' incorporates:
   *  Constant: '<S4>/Constant'
   */
  {
    uint16_t dutyA = FTM_MAX_DUTY_CYCLE * 0.5F;
    FTM_DRV_UpdatePwmChannel(FTM_PWM3, 0U, FTM_PWM_UPDATE_IN_DUTY_CYCLE, dutyA,
      0, true);
  }

  /* Update for UnitDelay: '<S5>/Unit Delay' */
  two_virtual_wheel_autocode_DW.UnitDelay_DSTATE =
    two_virtual_wheel_autocode_B.Quadrature_Decoder_o1;

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.002, which is the step size
   * of the task. Size of "clockTick0" ensures timer will not overflow during the
   * application lifespan selected.
   */
  two_virtual_wheel_autocode_M->Timing.clockTick0++;
}

/* Model step function for TID1 */
void two_virtual_wheel_autocode_step1(void) /* Sample time: [0.02s, 0.0s] */
{
  real32_T rtb_RateTransition;

  /* RateTransition: '<Root>/Rate Transition' */
  rtb_RateTransition = two_virtual_wheel_autocode_DW.RateTransition_Buffer;

  /* S-Function (fcgen): '<Root>/Function-Call Generator' incorporates:
   *  SubSystem: '<Root>/Subsystem1'
   */

  /* RateTransition: '<Root>/Rate Transition1' */
  slow(two_virtual_wheel_autocode_M, rtb_RateTransition,
       &two_virtual_wheel_autocode_DW.RateTransition1_Buffer0,
       &two_virtual_wheel_autocode_DW.Subsystem1);

  /* End of Outputs for S-Function (fcgen): '<Root>/Function-Call Generator' */

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.02, which is the step size
   * of the task. Size of "clockTick1" ensures timer will not overflow during the
   * application lifespan selected.
   */
  two_virtual_wheel_autocode_M->Timing.clockTick1++;
}

/* Model initialize function */
void two_virtual_wheel_autocode_initialize(void)
{
  /* Start for S-Function (ftm_s32k_quadrature_decoder): '<Root>/Quadrature_Decoder' */
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

  /* Start for S-Function (ftm_s32k_pwm_config): '<S6>/FTM_PWM_Config' */

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

  /* Start for S-Function (ftm_s32k_pwm_config): '<S4>/FTM_PWM_Config' incorporates:
   *  Constant: '<S4>/Constant'
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
   *  SubSystem: '<Root>/Subsystem1'
   */
  slow_Init(two_virtual_wheel_autocode_M,
            &two_virtual_wheel_autocode_DW.Subsystem1);

  /* End of SystemInitialize for S-Function (fcgen): '<Root>/Function-Call Generator' */

  /* SystemInitialize for S-Function (fcgen): '<Root>/Function-Call Generator1' incorporates:
   *  SubSystem: '<Root>/Subsystem'
   */
  fast_Init(two_virtual_wheel_autocode_M,
            &two_virtual_wheel_autocode_DW.Subsystem);

  /* End of SystemInitialize for S-Function (fcgen): '<Root>/Function-Call Generator1' */
}

/* Model terminate function */
void two_virtual_wheel_autocode_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
