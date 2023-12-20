/*
 * wzor_01_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "wzor_01".
 *
 * Model version              : 10.23
 * Simulink Coder version : 9.6 (R2021b) 14-May-2021
 * C source code generated on : Wed Dec  6 12:10:18 2023
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "wzor_01.h"
#include "wzor_01_private.h"

/* Block parameters (default storage) */
P_wzor_01_T wzor_01_P = {
  /* Expression: 1
   * Referenced by: '<Root>/Reset'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<Root>/Normal'
   */
  0.0,

  /* Computed Parameter: AnalogInput_P1_Size
   * Referenced by: '<S2>/Analog Input'
   */
  { 1.0, 1.0 },

  /* Expression: BaseAddress
   * Referenced by: '<S2>/Analog Input'
   */
  57088.0,

  /* Computed Parameter: AnalogInput_P2_Size
   * Referenced by: '<S2>/Analog Input'
   */
  { 1.0, 2.0 },

  /* Expression: [1 0]
   * Referenced by: '<S2>/Analog Input'
   */
  { 1.0, 0.0 },

  /* Computed Parameter: AnalogInput_P3_Size
   * Referenced by: '<S2>/Analog Input'
   */
  { 1.0, 2.0 },

  /* Expression: [1 1]
   * Referenced by: '<S2>/Analog Input'
   */
  { 1.0, 1.0 },

  /* Computed Parameter: AnalogInput_P4_Size
   * Referenced by: '<S2>/Analog Input'
   */
  { 1.0, 1.0 },

  /* Expression: T0
   * Referenced by: '<S2>/Analog Input'
   */
  0.01,

  /* Expression: 1000/0.52/2
   * Referenced by: '<S2>/Convert to RPM'
   */
  961.53846153846155,

  /* Expression: 0.8
   * Referenced by: '<Root>/Sat1'
   */
  0.8,

  /* Expression: -.8
   * Referenced by: '<Root>/Sat1'
   */
  -0.8,

  /* Computed Parameter: Encoder_P1_Size
   * Referenced by: '<S2>/Encoder'
   */
  { 1.0, 1.0 },

  /* Expression: BaseAddress
   * Referenced by: '<S2>/Encoder'
   */
  57088.0,

  /* Computed Parameter: Encoder_P2_Size
   * Referenced by: '<S2>/Encoder'
   */
  { 1.0, 1.0 },

  /* Expression: T0
   * Referenced by: '<S2>/Encoder'
   */
  0.01,

  /* Expression: [1 -1]
   * Referenced by: '<S2>/Encoder 1024 PPR'
   */
  { 1.0, -1.0 },

  /* Expression: 2*pi/4096
   * Referenced by: '<S2>/Convert to rad'
   */
  0.0015339807878856412,

  /* Expression: 0
   * Referenced by: '<Root>/Constant'
   */
  0.0,

  /* Expression: 0.8
   * Referenced by: '<Root>/Sat'
   */
  0.8,

  /* Expression: -0.3
   * Referenced by: '<Root>/Sat'
   */
  -0.3,

  /* Expression: 1
   * Referenced by: '<S2>/PWM_corr'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S2>/PWM_corr1'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S2>/Saturation'
   */
  1.0,

  /* Expression: -1
   * Referenced by: '<S2>/Saturation'
   */
  -1.0,

  /* Computed Parameter: PWM_P1_Size
   * Referenced by: '<S2>/PWM'
   */
  { 1.0, 1.0 },

  /* Expression: BaseAddress
   * Referenced by: '<S2>/PWM'
   */
  57088.0,

  /* Computed Parameter: PWM_P2_Size
   * Referenced by: '<S2>/PWM'
   */
  { 1.0, 1.0 },

  /* Expression: T0
   * Referenced by: '<S2>/PWM'
   */
  0.01,

  /* Computed Parameter: ResetEncoder_P1_Size
   * Referenced by: '<S2>/ResetEncoder'
   */
  { 1.0, 1.0 },

  /* Expression: BaseAddress
   * Referenced by: '<S2>/ResetEncoder'
   */
  57088.0,

  /* Computed Parameter: ResetEncoder_P2_Size
   * Referenced by: '<S2>/ResetEncoder'
   */
  { 1.0, 1.0 },

  /* Expression: T0
   * Referenced by: '<S2>/ResetEncoder'
   */
  0.01,

  /* Computed Parameter: BitstreamVersion_P1_Size
   * Referenced by: '<S2>/Bitstream Version'
   */
  { 1.0, 1.0 },

  /* Expression: BaseAddress
   * Referenced by: '<S2>/Bitstream Version'
   */
  57088.0,

  /* Computed Parameter: BitstreamVersion_P2_Size
   * Referenced by: '<S2>/Bitstream Version'
   */
  { 1.0, 1.0 },

  /* Expression: T0
   * Referenced by: '<S2>/Bitstream Version'
   */
  0.01,

  /* Computed Parameter: ThermStatus_P1_Size
   * Referenced by: '<S2>/Therm Status'
   */
  { 1.0, 1.0 },

  /* Expression: BaseAddress
   * Referenced by: '<S2>/Therm Status'
   */
  57088.0,

  /* Computed Parameter: ThermStatus_P2_Size
   * Referenced by: '<S2>/Therm Status'
   */
  { 1.0, 1.0 },

  /* Expression: T0
   * Referenced by: '<S2>/Therm Status'
   */
  0.01,

  /* Expression: [1 1]
   * Referenced by: '<S2>/PWMPrescalerSource'
   */
  { 1.0, 1.0 },

  /* Computed Parameter: PWMPrescaler_P1_Size
   * Referenced by: '<S2>/PWMPrescaler'
   */
  { 1.0, 1.0 },

  /* Expression: BaseAddress
   * Referenced by: '<S2>/PWMPrescaler'
   */
  57088.0,

  /* Computed Parameter: PWMPrescaler_P2_Size
   * Referenced by: '<S2>/PWMPrescaler'
   */
  { 1.0, 1.0 },

  /* Expression: T0
   * Referenced by: '<S2>/PWMPrescaler'
   */
  0.01,

  /* Expression: [1 1]
   * Referenced by: '<S2>/ThermFlagSource'
   */
  { 1.0, 1.0 },

  /* Computed Parameter: ThermFlag_P1_Size
   * Referenced by: '<S2>/ThermFlag '
   */
  { 1.0, 1.0 },

  /* Expression: BaseAddress
   * Referenced by: '<S2>/ThermFlag '
   */
  57088.0,

  /* Computed Parameter: ThermFlag_P2_Size
   * Referenced by: '<S2>/ThermFlag '
   */
  { 1.0, 1.0 },

  /* Expression: T0
   * Referenced by: '<S2>/ThermFlag '
   */
  0.01,

  /* Computed Parameter: ResetEncoders_CurrentSetting
   * Referenced by: '<Root>/Reset Encoders'
   */
  0U
};
