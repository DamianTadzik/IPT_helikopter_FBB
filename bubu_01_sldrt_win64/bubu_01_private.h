/*
 * bubu_01_private.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "bubu_01".
 *
 * Model version              : 10.34
 * Simulink Coder version : 9.6 (R2021b) 14-May-2021
 * C source code generated on : Wed Jan 10 12:29:00 2024
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_bubu_01_private_h_
#define RTW_HEADER_bubu_01_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"

extern real_T rt_urand_Upu32_Yd_f_pw_snf(uint32_T *u);
extern real_T rt_nrand_Upu32_Yd_f_pw_snf(uint32_T *u);
extern void TRAS_AnalogInput(SimStruct *rts);
extern void TRAS_Encoder(SimStruct *rts);
extern void TRAS_PWM(SimStruct *rts);
extern void TRAS_ResetEncoder(SimStruct *rts);
extern void TRAS_BitstreamVersion(SimStruct *rts);
extern void TRAS_PWMTherm(SimStruct *rts);
extern void TRAS_PWMPrescaler(SimStruct *rts);
extern void TRAS_ThermFlag(SimStruct *rts);

#endif                                 /* RTW_HEADER_bubu_01_private_h_ */
