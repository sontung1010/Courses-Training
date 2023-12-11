/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: twofourbit_adder.c
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

#include "twofourbit_adder.h"
#include "rtwtypes.h"
#include "twofourbit_adder_private.h"

/* Block signals (default storage) */
B_twofourbit_adder_T twofourbit_adder_B;

/* Real-time model */
static RT_MODEL_twofourbit_adder_T twofourbit_adder_M_;
RT_MODEL_twofourbit_adder_T *const twofourbit_adder_M = &twofourbit_adder_M_;

/* Model step function */
void twofourbit_adder_step(void)
{
  uint8_T rtb_Sum;

  /* S-Function (fcgen): '<Root>/Function-Call Generator' incorporates:
   *  SubSystem: '<Root>/Adder Task'
   */
  /* S-Function (gpio_s32k_input): '<S3>/Digital_Input' */

  /* GPIPORTE6 signal update */
  twofourbit_adder_B.Digital_Input = (PINS_DRV_ReadPins(PTE) >> 6) & 0x01;

  /* S-Function (gpio_s32k_input): '<S3>/Digital_Input1' */

  /* GPIPORTE7 signal update */
  twofourbit_adder_B.Digital_Input1 = (PINS_DRV_ReadPins(PTE) >> 7) & 0x01;

  /* S-Function (gpio_s32k_input): '<S3>/Digital_Input2' */

  /* GPIPORTE8 signal update */
  twofourbit_adder_B.Digital_Input2 = (PINS_DRV_ReadPins(PTE) >> 8) & 0x01;

  /* S-Function (gpio_s32k_input): '<S3>/Digital_Input3' */

  /* GPIPORTE9 signal update */
  twofourbit_adder_B.Digital_Input3 = (PINS_DRV_ReadPins(PTE) >> 9) & 0x01;

  /* S-Function (gpio_s32k_input): '<S2>/Digital_Input' */

  /* GPIPORTE10 signal update */
  twofourbit_adder_B.Digital_Input_e = (PINS_DRV_ReadPins(PTE) >> 10) & 0x01;

  /* S-Function (gpio_s32k_input): '<S2>/Digital_Input1' */

  /* GPIPORTE11 signal update */
  twofourbit_adder_B.Digital_Input1_g = (PINS_DRV_ReadPins(PTE) >> 11) & 0x01;

  /* S-Function (gpio_s32k_input): '<S2>/Digital_Input2' */

  /* GPIPORTE12 signal update */
  twofourbit_adder_B.Digital_Input2_h = (PINS_DRV_ReadPins(PTE) >> 12) & 0x01;

  /* S-Function (gpio_s32k_input): '<S2>/Digital_Input3' */

  /* GPIPORTE13 signal update */
  twofourbit_adder_B.Digital_Input3_p = (PINS_DRV_ReadPins(PTE) >> 13) & 0x01;

  /* Sum: '<S1>/Sum' incorporates:
   *  ArithShift: '<S2>/Shift Arithmetic1'
   *  ArithShift: '<S2>/Shift Arithmetic2'
   *  ArithShift: '<S2>/Shift Arithmetic3'
   *  ArithShift: '<S3>/Shift Arithmetic1'
   *  ArithShift: '<S3>/Shift Arithmetic2'
   *  ArithShift: '<S3>/Shift Arithmetic3'
   *  DataTypeConversion: '<S2>/Data Type Conversion'
   *  DataTypeConversion: '<S2>/Data Type Conversion1'
   *  DataTypeConversion: '<S2>/Data Type Conversion2'
   *  DataTypeConversion: '<S2>/Data Type Conversion3'
   *  DataTypeConversion: '<S3>/Data Type Conversion'
   *  DataTypeConversion: '<S3>/Data Type Conversion1'
   *  DataTypeConversion: '<S3>/Data Type Conversion2'
   *  DataTypeConversion: '<S3>/Data Type Conversion3'
   *  Sum: '<S2>/Add'
   *  Sum: '<S3>/Add'
   */
  rtb_Sum = (uint8_T)((((((((uint32_T)(twofourbit_adder_B.Digital_Input1 << 1) +
    twofourbit_adder_B.Digital_Input) + (uint32_T)
    (twofourbit_adder_B.Digital_Input2 << 2)) + (uint32_T)
    (twofourbit_adder_B.Digital_Input3 << 3)) +
    twofourbit_adder_B.Digital_Input_e) + (uint32_T)
                        (twofourbit_adder_B.Digital_Input1_g << 1)) + (uint32_T)
                       (twofourbit_adder_B.Digital_Input2_h << 2)) + (uint32_T)
                      (twofourbit_adder_B.Digital_Input3_p << 3));

  /* DataTypeConversion: '<S4>/Data Type Conversion' incorporates:
   *  S-Function (sfix_bitop): '<S4>/Bitwise AND'
   */
  twofourbit_adder_B.DataTypeConversion = ((rtb_Sum & 1U) != 0U);

  /* S-Function (gpio_s32k_output): '<S4>/Digital_Output' */

  /* GPOPORTD0 Data Signal Update */
  if (twofourbit_adder_B.DataTypeConversion) {
    PINS_DRV_SetPins(PTD, 1UL<<0);
  } else {
    PINS_DRV_ClearPins(PTD, 1UL<<0);
  }

  /* DataTypeConversion: '<S4>/Data Type Conversion1' incorporates:
   *  S-Function (sfix_bitop): '<S4>/Bitwise AND1'
   */
  twofourbit_adder_B.DataTypeConversion1 = ((rtb_Sum & 2U) != 0U);

  /* S-Function (gpio_s32k_output): '<S4>/Digital_Output1' */

  /* GPOPORTD1 Data Signal Update */
  if (twofourbit_adder_B.DataTypeConversion1) {
    PINS_DRV_SetPins(PTD, 1UL<<1);
  } else {
    PINS_DRV_ClearPins(PTD, 1UL<<1);
  }

  /* DataTypeConversion: '<S4>/Data Type Conversion2' incorporates:
   *  S-Function (sfix_bitop): '<S4>/Bitwise AND2'
   */
  twofourbit_adder_B.DataTypeConversion2 = ((rtb_Sum & 4U) != 0U);

  /* S-Function (gpio_s32k_output): '<S4>/Digital_Output2' */

  /* GPOPORTD2 Data Signal Update */
  if (twofourbit_adder_B.DataTypeConversion2) {
    PINS_DRV_SetPins(PTD, 1UL<<2);
  } else {
    PINS_DRV_ClearPins(PTD, 1UL<<2);
  }

  /* DataTypeConversion: '<S4>/Data Type Conversion3' incorporates:
   *  S-Function (sfix_bitop): '<S4>/Bitwise AND3'
   */
  twofourbit_adder_B.DataTypeConversion3 = ((rtb_Sum & 8U) != 0U);

  /* S-Function (gpio_s32k_output): '<S4>/Digital_Output3' */

  /* GPOPORTD3 Data Signal Update */
  if (twofourbit_adder_B.DataTypeConversion3) {
    PINS_DRV_SetPins(PTD, 1UL<<3);
  } else {
    PINS_DRV_ClearPins(PTD, 1UL<<3);
  }

  /* DataTypeConversion: '<S4>/Data Type Conversion4' incorporates:
   *  S-Function (sfix_bitop): '<S4>/Bitwise AND5'
   */
  twofourbit_adder_B.DataTypeConversion4 = ((rtb_Sum & 16U) != 0U);

  /* S-Function (gpio_s32k_output): '<S4>/Digital_Output4' */

  /* GPOPORTD4 Data Signal Update */
  if (twofourbit_adder_B.DataTypeConversion4) {
    PINS_DRV_SetPins(PTD, 1UL<<4);
  } else {
    PINS_DRV_ClearPins(PTD, 1UL<<4);
  }

  /* End of Outputs for S-Function (fcgen): '<Root>/Function-Call Generator' */
}

/* Model initialize function */
void twofourbit_adder_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(twofourbit_adder_M, (NULL));

  /* block I/O */
  (void) memset(((void *) &twofourbit_adder_B), 0,
                sizeof(B_twofourbit_adder_T));

  /* SystemInitialize for S-Function (fcgen): '<Root>/Function-Call Generator' incorporates:
   *  SubSystem: '<Root>/Adder Task'
   */

  /* Start for S-Function (gpio_s32k_input): '<S3>/Digital_Input' */
  {
    /* Enable clock for PORTE */
    PCC_SetClockMode(PCC, PCC_PORTE_CLOCK, true);

    /* Configure the input port init structure. */
    const pin_settings_config_t gpioPORTEPin6 = {
      .base = PORTE,
      .pinPortIdx = 6,
      .pullConfig = PORT_INTERNAL_PULL_NOT_ENABLED,
      .passiveFilter = false,
      .driveSelect = PORT_LOW_DRIVE_STRENGTH,
      .mux = PORT_MUX_AS_GPIO,
      .pinLock = false,
      .intConfig = PORT_DMA_INT_DISABLED,
      .clearIntFlag = true,
      .gpioBase = PTE,
      .direction = GPIO_INPUT_DIRECTION,
    };

    /* Initialize GPIPORTE6. */
    PINS_DRV_Init(1, &gpioPORTEPin6);
  }

  /* Start for S-Function (gpio_s32k_input): '<S3>/Digital_Input1' */
  {
    /* Enable clock for PORTE */
    PCC_SetClockMode(PCC, PCC_PORTE_CLOCK, true);

    /* Configure the input port init structure. */
    const pin_settings_config_t gpioPORTEPin7 = {
      .base = PORTE,
      .pinPortIdx = 7,
      .pullConfig = PORT_INTERNAL_PULL_NOT_ENABLED,
      .passiveFilter = false,
      .driveSelect = PORT_LOW_DRIVE_STRENGTH,
      .mux = PORT_MUX_AS_GPIO,
      .pinLock = false,
      .intConfig = PORT_DMA_INT_DISABLED,
      .clearIntFlag = true,
      .gpioBase = PTE,
      .direction = GPIO_INPUT_DIRECTION,
    };

    /* Initialize GPIPORTE7. */
    PINS_DRV_Init(1, &gpioPORTEPin7);
  }

  /* Start for S-Function (gpio_s32k_input): '<S3>/Digital_Input2' */
  {
    /* Enable clock for PORTE */
    PCC_SetClockMode(PCC, PCC_PORTE_CLOCK, true);

    /* Configure the input port init structure. */
    const pin_settings_config_t gpioPORTEPin8 = {
      .base = PORTE,
      .pinPortIdx = 8,
      .pullConfig = PORT_INTERNAL_PULL_NOT_ENABLED,
      .passiveFilter = false,
      .driveSelect = PORT_LOW_DRIVE_STRENGTH,
      .mux = PORT_MUX_AS_GPIO,
      .pinLock = false,
      .intConfig = PORT_DMA_INT_DISABLED,
      .clearIntFlag = true,
      .gpioBase = PTE,
      .direction = GPIO_INPUT_DIRECTION,
    };

    /* Initialize GPIPORTE8. */
    PINS_DRV_Init(1, &gpioPORTEPin8);
  }

  /* Start for S-Function (gpio_s32k_input): '<S3>/Digital_Input3' */
  {
    /* Enable clock for PORTE */
    PCC_SetClockMode(PCC, PCC_PORTE_CLOCK, true);

    /* Configure the input port init structure. */
    const pin_settings_config_t gpioPORTEPin9 = {
      .base = PORTE,
      .pinPortIdx = 9,
      .pullConfig = PORT_INTERNAL_PULL_NOT_ENABLED,
      .passiveFilter = false,
      .driveSelect = PORT_LOW_DRIVE_STRENGTH,
      .mux = PORT_MUX_AS_GPIO,
      .pinLock = false,
      .intConfig = PORT_DMA_INT_DISABLED,
      .clearIntFlag = true,
      .gpioBase = PTE,
      .direction = GPIO_INPUT_DIRECTION,
    };

    /* Initialize GPIPORTE9. */
    PINS_DRV_Init(1, &gpioPORTEPin9);
  }

  /* Start for S-Function (gpio_s32k_input): '<S2>/Digital_Input' */
  {
    /* Enable clock for PORTE */
    PCC_SetClockMode(PCC, PCC_PORTE_CLOCK, true);

    /* Configure the input port init structure. */
    const pin_settings_config_t gpioPORTEPin10 = {
      .base = PORTE,
      .pinPortIdx = 10,
      .pullConfig = PORT_INTERNAL_PULL_NOT_ENABLED,
      .passiveFilter = false,
      .driveSelect = PORT_LOW_DRIVE_STRENGTH,
      .mux = PORT_MUX_AS_GPIO,
      .pinLock = false,
      .intConfig = PORT_DMA_INT_DISABLED,
      .clearIntFlag = true,
      .gpioBase = PTE,
      .direction = GPIO_INPUT_DIRECTION,
    };

    /* Initialize GPIPORTE10. */
    PINS_DRV_Init(1, &gpioPORTEPin10);
  }

  /* Start for S-Function (gpio_s32k_input): '<S2>/Digital_Input1' */
  {
    /* Enable clock for PORTE */
    PCC_SetClockMode(PCC, PCC_PORTE_CLOCK, true);

    /* Configure the input port init structure. */
    const pin_settings_config_t gpioPORTEPin11 = {
      .base = PORTE,
      .pinPortIdx = 11,
      .pullConfig = PORT_INTERNAL_PULL_NOT_ENABLED,
      .passiveFilter = false,
      .driveSelect = PORT_LOW_DRIVE_STRENGTH,
      .mux = PORT_MUX_AS_GPIO,
      .pinLock = false,
      .intConfig = PORT_DMA_INT_DISABLED,
      .clearIntFlag = true,
      .gpioBase = PTE,
      .direction = GPIO_INPUT_DIRECTION,
    };

    /* Initialize GPIPORTE11. */
    PINS_DRV_Init(1, &gpioPORTEPin11);
  }

  /* Start for S-Function (gpio_s32k_input): '<S2>/Digital_Input2' */
  {
    /* Enable clock for PORTE */
    PCC_SetClockMode(PCC, PCC_PORTE_CLOCK, true);

    /* Configure the input port init structure. */
    const pin_settings_config_t gpioPORTEPin12 = {
      .base = PORTE,
      .pinPortIdx = 12,
      .pullConfig = PORT_INTERNAL_PULL_NOT_ENABLED,
      .passiveFilter = false,
      .driveSelect = PORT_LOW_DRIVE_STRENGTH,
      .mux = PORT_MUX_AS_GPIO,
      .pinLock = false,
      .intConfig = PORT_DMA_INT_DISABLED,
      .clearIntFlag = true,
      .gpioBase = PTE,
      .direction = GPIO_INPUT_DIRECTION,
    };

    /* Initialize GPIPORTE12. */
    PINS_DRV_Init(1, &gpioPORTEPin12);
  }

  /* Start for S-Function (gpio_s32k_input): '<S2>/Digital_Input3' */
  {
    /* Enable clock for PORTE */
    PCC_SetClockMode(PCC, PCC_PORTE_CLOCK, true);

    /* Configure the input port init structure. */
    const pin_settings_config_t gpioPORTEPin13 = {
      .base = PORTE,
      .pinPortIdx = 13,
      .pullConfig = PORT_INTERNAL_PULL_NOT_ENABLED,
      .passiveFilter = false,
      .driveSelect = PORT_LOW_DRIVE_STRENGTH,
      .mux = PORT_MUX_AS_GPIO,
      .pinLock = false,
      .intConfig = PORT_DMA_INT_DISABLED,
      .clearIntFlag = true,
      .gpioBase = PTE,
      .direction = GPIO_INPUT_DIRECTION,
    };

    /* Initialize GPIPORTE13. */
    PINS_DRV_Init(1, &gpioPORTEPin13);
  }

  /* Start for S-Function (gpio_s32k_output): '<S4>/Digital_Output' */
  {
    /* Enable clock for PORTD */
    PCC_SetClockMode(PCC, PCC_PORTD_CLOCK, true);

    /* Configure the output port init structure. */
    const pin_settings_config_t gpioPORTDPin0 = {
      .base = PORTD,
      .pinPortIdx = 0,
      .pullConfig = PORT_INTERNAL_PULL_NOT_ENABLED,
      .passiveFilter = false,
      .driveSelect = PORT_LOW_DRIVE_STRENGTH,
      .mux = PORT_MUX_AS_GPIO,
      .pinLock = false,
      .intConfig = PORT_DMA_INT_DISABLED,
      .clearIntFlag = true,
      .gpioBase = PTD,
      .direction = GPIO_OUTPUT_DIRECTION,
      .initValue = 0U
    };

    /* Initialize GPIPORTD0. */
    PINS_DRV_Init(1, &gpioPORTDPin0);
  }

  /* Start for S-Function (gpio_s32k_output): '<S4>/Digital_Output1' */
  {
    /* Enable clock for PORTD */
    PCC_SetClockMode(PCC, PCC_PORTD_CLOCK, true);

    /* Configure the output port init structure. */
    const pin_settings_config_t gpioPORTDPin1 = {
      .base = PORTD,
      .pinPortIdx = 1,
      .pullConfig = PORT_INTERNAL_PULL_NOT_ENABLED,
      .passiveFilter = false,
      .driveSelect = PORT_LOW_DRIVE_STRENGTH,
      .mux = PORT_MUX_AS_GPIO,
      .pinLock = false,
      .intConfig = PORT_DMA_INT_DISABLED,
      .clearIntFlag = true,
      .gpioBase = PTD,
      .direction = GPIO_OUTPUT_DIRECTION,
      .initValue = 0U
    };

    /* Initialize GPIPORTD1. */
    PINS_DRV_Init(1, &gpioPORTDPin1);
  }

  /* Start for S-Function (gpio_s32k_output): '<S4>/Digital_Output2' */
  {
    /* Enable clock for PORTD */
    PCC_SetClockMode(PCC, PCC_PORTD_CLOCK, true);

    /* Configure the output port init structure. */
    const pin_settings_config_t gpioPORTDPin2 = {
      .base = PORTD,
      .pinPortIdx = 2,
      .pullConfig = PORT_INTERNAL_PULL_NOT_ENABLED,
      .passiveFilter = false,
      .driveSelect = PORT_LOW_DRIVE_STRENGTH,
      .mux = PORT_MUX_AS_GPIO,
      .pinLock = false,
      .intConfig = PORT_DMA_INT_DISABLED,
      .clearIntFlag = true,
      .gpioBase = PTD,
      .direction = GPIO_OUTPUT_DIRECTION,
      .initValue = 0U
    };

    /* Initialize GPIPORTD2. */
    PINS_DRV_Init(1, &gpioPORTDPin2);
  }

  /* Start for S-Function (gpio_s32k_output): '<S4>/Digital_Output3' */
  {
    /* Enable clock for PORTD */
    PCC_SetClockMode(PCC, PCC_PORTD_CLOCK, true);

    /* Configure the output port init structure. */
    const pin_settings_config_t gpioPORTDPin3 = {
      .base = PORTD,
      .pinPortIdx = 3,
      .pullConfig = PORT_INTERNAL_PULL_NOT_ENABLED,
      .passiveFilter = false,
      .driveSelect = PORT_LOW_DRIVE_STRENGTH,
      .mux = PORT_MUX_AS_GPIO,
      .pinLock = false,
      .intConfig = PORT_DMA_INT_DISABLED,
      .clearIntFlag = true,
      .gpioBase = PTD,
      .direction = GPIO_OUTPUT_DIRECTION,
      .initValue = 0U
    };

    /* Initialize GPIPORTD3. */
    PINS_DRV_Init(1, &gpioPORTDPin3);
  }

  /* Start for S-Function (gpio_s32k_output): '<S4>/Digital_Output4' */
  {
    /* Enable clock for PORTD */
    PCC_SetClockMode(PCC, PCC_PORTD_CLOCK, true);

    /* Configure the output port init structure. */
    const pin_settings_config_t gpioPORTDPin4 = {
      .base = PORTD,
      .pinPortIdx = 4,
      .pullConfig = PORT_INTERNAL_PULL_NOT_ENABLED,
      .passiveFilter = false,
      .driveSelect = PORT_LOW_DRIVE_STRENGTH,
      .mux = PORT_MUX_AS_GPIO,
      .pinLock = false,
      .intConfig = PORT_DMA_INT_DISABLED,
      .clearIntFlag = true,
      .gpioBase = PTD,
      .direction = GPIO_OUTPUT_DIRECTION,
      .initValue = 0U
    };

    /* Initialize GPIPORTD4. */
    PINS_DRV_Init(1, &gpioPORTDPin4);
  }

  /* End of SystemInitialize for S-Function (fcgen): '<Root>/Function-Call Generator' */
}

/* Model terminate function */
void twofourbit_adder_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
