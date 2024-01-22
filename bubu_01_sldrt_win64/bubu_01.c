/*
 * bubu_01.c
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

#include "bubu_01.h"
#include "bubu_01_private.h"
#include "bubu_01_dt.h"

/* list of Simulink Desktop Real-Time timers */
const int SLDRTTimerCount = 1;
const double SLDRTTimers[2] = {
  0.01, 0.0,
};

/* Block signals (default storage) */
B_bubu_01_T bubu_01_B;

/* Block states (default storage) */
DW_bubu_01_T bubu_01_DW;

/* Real-time model */
static RT_MODEL_bubu_01_T bubu_01_M_;
RT_MODEL_bubu_01_T *const bubu_01_M = &bubu_01_M_;
static void rate_scheduler(void);

/*
 *         This function updates active task flag for each subrate.
 *         The function is called at model base rate, hence the
 *         generated code self-manages all its subrates.
 */
static void rate_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (bubu_01_M->Timing.TaskCounters.TID[1])++;
  if ((bubu_01_M->Timing.TaskCounters.TID[1]) > 49) {/* Sample time: [0.5s, 0.0s] */
    bubu_01_M->Timing.TaskCounters.TID[1] = 0;
  }

  bubu_01_M->Timing.sampleHits[1] = (bubu_01_M->Timing.TaskCounters.TID[1] == 0)
    ? 1 : 0;
}

real_T rt_urand_Upu32_Yd_f_pw_snf(uint32_T *u)
{
  uint32_T hi;
  uint32_T lo;

  /* Uniform random number generator (random number between 0 and 1)

     #define IA      16807                      magic multiplier = 7^5
     #define IM      2147483647                 modulus = 2^31-1
     #define IQ      127773                     IM div IA
     #define IR      2836                       IM modulo IA
     #define S       4.656612875245797e-10      reciprocal of 2^31-1
     test = IA * (seed % IQ) - IR * (seed/IQ)
     seed = test < 0 ? (test + IM) : test
     return (seed*S)
   */
  lo = *u % 127773U * 16807U;
  hi = *u / 127773U * 2836U;
  if (lo < hi) {
    *u = 2147483647U - (hi - lo);
  } else {
    *u = lo - hi;
  }

  return (real_T)*u * 4.6566128752457969E-10;
}

real_T rt_nrand_Upu32_Yd_f_pw_snf(uint32_T *u)
{
  real_T si;
  real_T sr;
  real_T y;

  /* Normal (Gaussian) random number generator */
  do {
    sr = 2.0 * rt_urand_Upu32_Yd_f_pw_snf(u) - 1.0;
    si = 2.0 * rt_urand_Upu32_Yd_f_pw_snf(u) - 1.0;
    si = sr * sr + si * si;
  } while (si > 1.0);

  y = sqrt(-2.0 * log(si) / si) * sr;
  return y;
}

/* Model output function */
void bubu_01_output(void)
{
  real_T u0;

  /* S-Function (TRAS_AnalogInput): '<S2>/Analog Input' */

  /* Level2 S-Function Block: '<S2>/Analog Input' (TRAS_AnalogInput) */
  {
    SimStruct *rts = bubu_01_M->childSfunctions[0];
    sfcnOutputs(rts,0);
  }

  /* Gain: '<S2>/Convert to RPM' */
  bubu_01_B.ConverttoRPM[0] = bubu_01_P.ConverttoRPM_Gain *
    bubu_01_B.AnalogInput[0];
  bubu_01_B.ConverttoRPM[1] = bubu_01_P.ConverttoRPM_Gain *
    bubu_01_B.AnalogInput[1];
  if (bubu_01_M->Timing.TaskCounters.TID[1] == 0) {
    /* Gain: '<S1>/Output' incorporates:
     *  RandomNumber: '<S1>/White Noise'
     */
    u0 = sqrt(bubu_01_P.BandLimitedWhiteNoise_Cov) / 0.70710678118654757 *
      bubu_01_DW.NextOutput;

    /* Saturate: '<Root>/Sat1' */
    if (u0 > bubu_01_P.Sat1_UpperSat) {
      /* Saturate: '<Root>/Sat1' */
      bubu_01_B.Sat1 = bubu_01_P.Sat1_UpperSat;
    } else if (u0 < bubu_01_P.Sat1_LowerSat) {
      /* Saturate: '<Root>/Sat1' */
      bubu_01_B.Sat1 = bubu_01_P.Sat1_LowerSat;
    } else {
      /* Saturate: '<Root>/Sat1' */
      bubu_01_B.Sat1 = u0;
    }

    /* End of Saturate: '<Root>/Sat1' */
  }

  /* S-Function (TRAS_Encoder): '<S2>/Encoder' */

  /* Level2 S-Function Block: '<S2>/Encoder' (TRAS_Encoder) */
  {
    SimStruct *rts = bubu_01_M->childSfunctions[1];
    sfcnOutputs(rts,0);
  }

  /* Gain: '<S2>/Convert to rad' incorporates:
   *  Gain: '<S2>/Encoder 1024 PPR'
   */
  bubu_01_B.Converttorad[0] = bubu_01_P.Encoder1024PPR_Gain[0] *
    bubu_01_B.Encoder[0] * bubu_01_P.Converttorad_Gain;
  bubu_01_B.Converttorad[1] = bubu_01_P.Encoder1024PPR_Gain[1] *
    bubu_01_B.Encoder[1] * bubu_01_P.Converttorad_Gain;

  /* ManualSwitch: '<Root>/Reset Encoders' */
  if (bubu_01_P.ResetEncoders_CurrentSetting == 1) {
    /* ManualSwitch: '<Root>/Reset Encoders' incorporates:
     *  Constant: '<Root>/Reset'
     */
    bubu_01_B.ResetEncoders = bubu_01_P.Reset_Value;
  } else {
    /* ManualSwitch: '<Root>/Reset Encoders' incorporates:
     *  Constant: '<Root>/Normal'
     */
    bubu_01_B.ResetEncoders = bubu_01_P.Normal_Value;
  }

  /* End of ManualSwitch: '<Root>/Reset Encoders' */
  if (bubu_01_M->Timing.TaskCounters.TID[1] == 0) {
    /* Saturate: '<Root>/Sat' incorporates:
     *  Constant: '<Root>/Constant'
     */
    if (bubu_01_P.Constant_Value > bubu_01_P.Sat_UpperSat) {
      u0 = bubu_01_P.Sat_UpperSat;
    } else if (bubu_01_P.Constant_Value < bubu_01_P.Sat_LowerSat) {
      u0 = bubu_01_P.Sat_LowerSat;
    } else {
      u0 = bubu_01_P.Constant_Value;
    }

    /* End of Saturate: '<Root>/Sat' */

    /* Gain: '<S2>/PWM_corr' */
    u0 *= bubu_01_P.PWM_corr_Gain;

    /* Saturate: '<S2>/Saturation' */
    if (u0 > bubu_01_P.Saturation_UpperSat) {
      /* Saturate: '<S2>/Saturation' */
      bubu_01_B.Saturation[0] = bubu_01_P.Saturation_UpperSat;
    } else if (u0 < bubu_01_P.Saturation_LowerSat) {
      /* Saturate: '<S2>/Saturation' */
      bubu_01_B.Saturation[0] = bubu_01_P.Saturation_LowerSat;
    } else {
      /* Saturate: '<S2>/Saturation' */
      bubu_01_B.Saturation[0] = u0;
    }

    /* Gain: '<S2>/PWM_corr1' */
    u0 = bubu_01_P.PWM_corr1_Gain * bubu_01_B.Sat1;

    /* Saturate: '<S2>/Saturation' */
    if (u0 > bubu_01_P.Saturation_UpperSat) {
      /* Saturate: '<S2>/Saturation' */
      bubu_01_B.Saturation[1] = bubu_01_P.Saturation_UpperSat;
    } else if (u0 < bubu_01_P.Saturation_LowerSat) {
      /* Saturate: '<S2>/Saturation' */
      bubu_01_B.Saturation[1] = bubu_01_P.Saturation_LowerSat;
    } else {
      /* Saturate: '<S2>/Saturation' */
      bubu_01_B.Saturation[1] = u0;
    }
  }

  /* S-Function (TRAS_PWM): '<S2>/PWM' */

  /* Level2 S-Function Block: '<S2>/PWM' (TRAS_PWM) */
  {
    SimStruct *rts = bubu_01_M->childSfunctions[2];
    sfcnOutputs(rts,0);
  }

  /* S-Function (TRAS_ResetEncoder): '<S2>/ResetEncoder' */

  /* Level2 S-Function Block: '<S2>/ResetEncoder' (TRAS_ResetEncoder) */
  {
    SimStruct *rts = bubu_01_M->childSfunctions[3];
    sfcnOutputs(rts,0);
  }

  /* S-Function (TRAS_BitstreamVersion): '<S2>/Bitstream Version' */

  /* Level2 S-Function Block: '<S2>/Bitstream Version' (TRAS_BitstreamVersion) */
  {
    SimStruct *rts = bubu_01_M->childSfunctions[4];
    sfcnOutputs(rts,0);
  }

  /* S-Function (TRAS_PWMTherm): '<S2>/Therm Status' */

  /* Level2 S-Function Block: '<S2>/Therm Status' (TRAS_PWMTherm) */
  {
    SimStruct *rts = bubu_01_M->childSfunctions[5];
    sfcnOutputs(rts,0);
  }

  /* Constant: '<S2>/PWMPrescalerSource' */
  bubu_01_B.PWMPrescalerSource[0] = bubu_01_P.PWMPrescalerSource_Value[0];
  bubu_01_B.PWMPrescalerSource[1] = bubu_01_P.PWMPrescalerSource_Value[1];

  /* S-Function (TRAS_PWMPrescaler): '<S2>/PWMPrescaler' */

  /* Level2 S-Function Block: '<S2>/PWMPrescaler' (TRAS_PWMPrescaler) */
  {
    SimStruct *rts = bubu_01_M->childSfunctions[6];
    sfcnOutputs(rts,0);
  }

  /* Constant: '<S2>/ThermFlagSource' */
  bubu_01_B.ThermFlagSource[0] = bubu_01_P.ThermFlagSource_Value[0];
  bubu_01_B.ThermFlagSource[1] = bubu_01_P.ThermFlagSource_Value[1];

  /* S-Function (TRAS_ThermFlag): '<S2>/ThermFlag ' */

  /* Level2 S-Function Block: '<S2>/ThermFlag ' (TRAS_ThermFlag) */
  {
    SimStruct *rts = bubu_01_M->childSfunctions[7];
    sfcnOutputs(rts,0);
  }
}

/* Model update function */
void bubu_01_update(void)
{
  if (bubu_01_M->Timing.TaskCounters.TID[1] == 0) {
    /* Update for RandomNumber: '<S1>/White Noise' */
    bubu_01_DW.NextOutput = rt_nrand_Upu32_Yd_f_pw_snf(&bubu_01_DW.RandSeed) *
      bubu_01_P.WhiteNoise_StdDev + bubu_01_P.WhiteNoise_Mean;
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++bubu_01_M->Timing.clockTick0)) {
    ++bubu_01_M->Timing.clockTickH0;
  }

  bubu_01_M->Timing.t[0] = bubu_01_M->Timing.clockTick0 *
    bubu_01_M->Timing.stepSize0 + bubu_01_M->Timing.clockTickH0 *
    bubu_01_M->Timing.stepSize0 * 4294967296.0;
  if (bubu_01_M->Timing.TaskCounters.TID[1] == 0) {
    /* Update absolute timer for sample time: [0.5s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++bubu_01_M->Timing.clockTick1)) {
      ++bubu_01_M->Timing.clockTickH1;
    }

    bubu_01_M->Timing.t[1] = bubu_01_M->Timing.clockTick1 *
      bubu_01_M->Timing.stepSize1 + bubu_01_M->Timing.clockTickH1 *
      bubu_01_M->Timing.stepSize1 * 4294967296.0;
  }

  rate_scheduler();
}

/* Model initialize function */
void bubu_01_initialize(void)
{
  /* Start for Constant: '<S2>/PWMPrescalerSource' */
  bubu_01_B.PWMPrescalerSource[0] = bubu_01_P.PWMPrescalerSource_Value[0];
  bubu_01_B.PWMPrescalerSource[1] = bubu_01_P.PWMPrescalerSource_Value[1];

  /* Start for Constant: '<S2>/ThermFlagSource' */
  bubu_01_B.ThermFlagSource[0] = bubu_01_P.ThermFlagSource_Value[0];
  bubu_01_B.ThermFlagSource[1] = bubu_01_P.ThermFlagSource_Value[1];

  {
    real_T tmp;
    int32_T r;
    int32_T t;
    uint32_T tseed;

    /* InitializeConditions for RandomNumber: '<S1>/White Noise' */
    tmp = floor(bubu_01_P.BandLimitedWhiteNoise_seed);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? (uint32_T)-(int32_T)(uint32_T)-tmp : (uint32_T)tmp;
    r = (int32_T)(tseed >> 16U);
    t = (int32_T)(tseed & 32768U);
    tseed = ((((tseed - ((uint32_T)r << 16U)) + t) << 16U) + t) + r;
    if (tseed < 1U) {
      tseed = 1144108930U;
    } else if (tseed > 2147483646U) {
      tseed = 2147483646U;
    }

    bubu_01_DW.RandSeed = tseed;
    bubu_01_DW.NextOutput = rt_nrand_Upu32_Yd_f_pw_snf(&bubu_01_DW.RandSeed) *
      bubu_01_P.WhiteNoise_StdDev + bubu_01_P.WhiteNoise_Mean;

    /* End of InitializeConditions for RandomNumber: '<S1>/White Noise' */
  }
}

/* Model terminate function */
void bubu_01_terminate(void)
{
  /* Terminate for S-Function (TRAS_AnalogInput): '<S2>/Analog Input' */
  /* Level2 S-Function Block: '<S2>/Analog Input' (TRAS_AnalogInput) */
  {
    SimStruct *rts = bubu_01_M->childSfunctions[0];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (TRAS_Encoder): '<S2>/Encoder' */
  /* Level2 S-Function Block: '<S2>/Encoder' (TRAS_Encoder) */
  {
    SimStruct *rts = bubu_01_M->childSfunctions[1];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (TRAS_PWM): '<S2>/PWM' */
  /* Level2 S-Function Block: '<S2>/PWM' (TRAS_PWM) */
  {
    SimStruct *rts = bubu_01_M->childSfunctions[2];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (TRAS_ResetEncoder): '<S2>/ResetEncoder' */
  /* Level2 S-Function Block: '<S2>/ResetEncoder' (TRAS_ResetEncoder) */
  {
    SimStruct *rts = bubu_01_M->childSfunctions[3];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (TRAS_BitstreamVersion): '<S2>/Bitstream Version' */
  /* Level2 S-Function Block: '<S2>/Bitstream Version' (TRAS_BitstreamVersion) */
  {
    SimStruct *rts = bubu_01_M->childSfunctions[4];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (TRAS_PWMTherm): '<S2>/Therm Status' */
  /* Level2 S-Function Block: '<S2>/Therm Status' (TRAS_PWMTherm) */
  {
    SimStruct *rts = bubu_01_M->childSfunctions[5];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (TRAS_PWMPrescaler): '<S2>/PWMPrescaler' */
  /* Level2 S-Function Block: '<S2>/PWMPrescaler' (TRAS_PWMPrescaler) */
  {
    SimStruct *rts = bubu_01_M->childSfunctions[6];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (TRAS_ThermFlag): '<S2>/ThermFlag ' */
  /* Level2 S-Function Block: '<S2>/ThermFlag ' (TRAS_ThermFlag) */
  {
    SimStruct *rts = bubu_01_M->childSfunctions[7];
    sfcnTerminate(rts);
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  bubu_01_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  bubu_01_update();
  UNUSED_PARAMETER(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  bubu_01_initialize();
}

void MdlTerminate(void)
{
  bubu_01_terminate();
}

/* Registration function */
RT_MODEL_bubu_01_T *bubu_01(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)bubu_01_M, 0,
                sizeof(RT_MODEL_bubu_01_T));
  rtsiSetSolverName(&bubu_01_M->solverInfo,"FixedStepDiscrete");
  bubu_01_M->solverInfoPtr = (&bubu_01_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = bubu_01_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;

    /* polyspace +2 MISRA2012:D4.1 [Justified:Low] "bubu_01_M points to
       static memory which is guaranteed to be non-NULL" */
    bubu_01_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    bubu_01_M->Timing.sampleTimes = (&bubu_01_M->Timing.sampleTimesArray[0]);
    bubu_01_M->Timing.offsetTimes = (&bubu_01_M->Timing.offsetTimesArray[0]);

    /* task periods */
    bubu_01_M->Timing.sampleTimes[0] = (0.01);
    bubu_01_M->Timing.sampleTimes[1] = (0.5);

    /* task offsets */
    bubu_01_M->Timing.offsetTimes[0] = (0.0);
    bubu_01_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(bubu_01_M, &bubu_01_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = bubu_01_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    bubu_01_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(bubu_01_M, 80.0);
  bubu_01_M->Timing.stepSize0 = 0.01;
  bubu_01_M->Timing.stepSize1 = 0.5;

  /* External mode info */
  bubu_01_M->Sizes.checksums[0] = (2082066111U);
  bubu_01_M->Sizes.checksums[1] = (2911731541U);
  bubu_01_M->Sizes.checksums[2] = (1824131142U);
  bubu_01_M->Sizes.checksums[3] = (1065996129U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[3];
    bubu_01_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(bubu_01_M->extModeInfo,
      &bubu_01_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(bubu_01_M->extModeInfo, bubu_01_M->Sizes.checksums);
    rteiSetTPtr(bubu_01_M->extModeInfo, rtmGetTPtr(bubu_01_M));
  }

  bubu_01_M->solverInfoPtr = (&bubu_01_M->solverInfo);
  bubu_01_M->Timing.stepSize = (0.01);
  rtsiSetFixedStepSize(&bubu_01_M->solverInfo, 0.01);
  rtsiSetSolverMode(&bubu_01_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  bubu_01_M->blockIO = ((void *) &bubu_01_B);

  {
    bubu_01_B.AnalogInput[0] = 0.0;
    bubu_01_B.AnalogInput[1] = 0.0;
    bubu_01_B.ConverttoRPM[0] = 0.0;
    bubu_01_B.ConverttoRPM[1] = 0.0;
    bubu_01_B.Sat1 = 0.0;
    bubu_01_B.Encoder[0] = 0.0;
    bubu_01_B.Encoder[1] = 0.0;
    bubu_01_B.Converttorad[0] = 0.0;
    bubu_01_B.Converttorad[1] = 0.0;
    bubu_01_B.ResetEncoders = 0.0;
    bubu_01_B.Saturation[0] = 0.0;
    bubu_01_B.Saturation[1] = 0.0;
    bubu_01_B.PWM[0] = 0.0;
    bubu_01_B.PWM[1] = 0.0;
    bubu_01_B.ResetEncoder[0] = 0.0;
    bubu_01_B.ResetEncoder[1] = 0.0;
    bubu_01_B.BitstreamVersion = 0.0;
    bubu_01_B.ThermStatus[0] = 0.0;
    bubu_01_B.ThermStatus[1] = 0.0;
    bubu_01_B.PWMPrescalerSource[0] = 0.0;
    bubu_01_B.PWMPrescalerSource[1] = 0.0;
    bubu_01_B.PWMPrescaler[0] = 0.0;
    bubu_01_B.PWMPrescaler[1] = 0.0;
    bubu_01_B.ThermFlagSource[0] = 0.0;
    bubu_01_B.ThermFlagSource[1] = 0.0;
    bubu_01_B.ThermFlag[0] = 0.0;
    bubu_01_B.ThermFlag[1] = 0.0;
  }

  /* parameters */
  bubu_01_M->defaultParam = ((real_T *)&bubu_01_P);

  /* states (dwork) */
  bubu_01_M->dwork = ((void *) &bubu_01_DW);
  (void) memset((void *)&bubu_01_DW, 0,
                sizeof(DW_bubu_01_T));
  bubu_01_DW.NextOutput = 0.0;

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    bubu_01_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 18;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* child S-Function registration */
  {
    RTWSfcnInfo *sfcnInfo = &bubu_01_M->NonInlinedSFcns.sfcnInfo;
    bubu_01_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus(bubu_01_M)));
    bubu_01_M->Sizes.numSampTimes = (2);
    rtssSetNumRootSampTimesPtr(sfcnInfo, &bubu_01_M->Sizes.numSampTimes);
    bubu_01_M->NonInlinedSFcns.taskTimePtrs[0] = &(rtmGetTPtr(bubu_01_M)[0]);
    bubu_01_M->NonInlinedSFcns.taskTimePtrs[1] = &(rtmGetTPtr(bubu_01_M)[1]);
    rtssSetTPtrPtr(sfcnInfo,bubu_01_M->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(bubu_01_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(bubu_01_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput(bubu_01_M));
    rtssSetStepSizePtr(sfcnInfo, &bubu_01_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested(bubu_01_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo, &bubu_01_M->derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo, &bubu_01_M->zCCacheNeedsReset);
    rtssSetContTimeOutputInconsistentWithStateAtMajorStepPtr(sfcnInfo,
      &bubu_01_M->CTOutputIncnstWithState);
    rtssSetSampleHitsPtr(sfcnInfo, &bubu_01_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo, &bubu_01_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &bubu_01_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &bubu_01_M->solverInfoPtr);
  }

  bubu_01_M->Sizes.numSFcns = (8);

  /* register each child */
  {
    (void) memset((void *)&bubu_01_M->NonInlinedSFcns.childSFunctions[0], 0,
                  8*sizeof(SimStruct));
    bubu_01_M->childSfunctions = (&bubu_01_M->
      NonInlinedSFcns.childSFunctionPtrs[0]);

    {
      int_T i;
      for (i = 0; i < 8; i++) {
        bubu_01_M->childSfunctions[i] =
          (&bubu_01_M->NonInlinedSFcns.childSFunctions[i]);
      }
    }

    /* Level2 S-Function Block: bubu_01/<S2>/Analog Input (TRAS_AnalogInput) */
    {
      SimStruct *rts = bubu_01_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod = bubu_01_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset = bubu_01_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap = bubu_01_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &bubu_01_M->NonInlinedSFcns.blkInfo2[0]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &bubu_01_M->NonInlinedSFcns.inputOutputPortInfo2[0]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, bubu_01_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &bubu_01_M->NonInlinedSFcns.methods2[0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &bubu_01_M->NonInlinedSFcns.methods3[0]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &bubu_01_M->NonInlinedSFcns.methods4[0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &bubu_01_M->NonInlinedSFcns.statesInfo2[0]);
        ssSetPeriodicStatesInfo(rts,
          &bubu_01_M->NonInlinedSFcns.periodicStatesInfo[0]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &bubu_01_M->NonInlinedSFcns.Sfcn0.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &bubu_01_M->NonInlinedSFcns.Sfcn0.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &bubu_01_M->NonInlinedSFcns.Sfcn0.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 2);
          ssSetOutputPortSignal(rts, 0, ((real_T *) bubu_01_B.AnalogInput));
        }
      }

      /* path info */
      ssSetModelName(rts, "Analog Input");
      ssSetPath(rts, "bubu_01/TRAS/Analog Input");
      ssSetRTModel(rts,bubu_01_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &bubu_01_M->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 4);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)bubu_01_P.AnalogInput_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)bubu_01_P.AnalogInput_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)bubu_01_P.AnalogInput_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)bubu_01_P.AnalogInput_P4_Size);
      }

      /* registration */
      TRAS_AnalogInput(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: bubu_01/<S2>/Encoder (TRAS_Encoder) */
    {
      SimStruct *rts = bubu_01_M->childSfunctions[1];

      /* timing info */
      time_T *sfcnPeriod = bubu_01_M->NonInlinedSFcns.Sfcn1.sfcnPeriod;
      time_T *sfcnOffset = bubu_01_M->NonInlinedSFcns.Sfcn1.sfcnOffset;
      int_T *sfcnTsMap = bubu_01_M->NonInlinedSFcns.Sfcn1.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &bubu_01_M->NonInlinedSFcns.blkInfo2[1]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &bubu_01_M->NonInlinedSFcns.inputOutputPortInfo2[1]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, bubu_01_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &bubu_01_M->NonInlinedSFcns.methods2[1]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &bubu_01_M->NonInlinedSFcns.methods3[1]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &bubu_01_M->NonInlinedSFcns.methods4[1]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &bubu_01_M->NonInlinedSFcns.statesInfo2[1]);
        ssSetPeriodicStatesInfo(rts,
          &bubu_01_M->NonInlinedSFcns.periodicStatesInfo[1]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &bubu_01_M->NonInlinedSFcns.Sfcn1.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &bubu_01_M->NonInlinedSFcns.Sfcn1.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &bubu_01_M->NonInlinedSFcns.Sfcn1.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 2);
          ssSetOutputPortSignal(rts, 0, ((real_T *) bubu_01_B.Encoder));
        }
      }

      /* path info */
      ssSetModelName(rts, "Encoder");
      ssSetPath(rts, "bubu_01/TRAS/Encoder");
      ssSetRTModel(rts,bubu_01_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &bubu_01_M->NonInlinedSFcns.Sfcn1.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)bubu_01_P.Encoder_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)bubu_01_P.Encoder_P2_Size);
      }

      /* registration */
      TRAS_Encoder(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: bubu_01/<S2>/PWM (TRAS_PWM) */
    {
      SimStruct *rts = bubu_01_M->childSfunctions[2];

      /* timing info */
      time_T *sfcnPeriod = bubu_01_M->NonInlinedSFcns.Sfcn2.sfcnPeriod;
      time_T *sfcnOffset = bubu_01_M->NonInlinedSFcns.Sfcn2.sfcnOffset;
      int_T *sfcnTsMap = bubu_01_M->NonInlinedSFcns.Sfcn2.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &bubu_01_M->NonInlinedSFcns.blkInfo2[2]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &bubu_01_M->NonInlinedSFcns.inputOutputPortInfo2[2]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, bubu_01_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &bubu_01_M->NonInlinedSFcns.methods2[2]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &bubu_01_M->NonInlinedSFcns.methods3[2]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &bubu_01_M->NonInlinedSFcns.methods4[2]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &bubu_01_M->NonInlinedSFcns.statesInfo2[2]);
        ssSetPeriodicStatesInfo(rts,
          &bubu_01_M->NonInlinedSFcns.periodicStatesInfo[2]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &bubu_01_M->NonInlinedSFcns.Sfcn2.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &bubu_01_M->NonInlinedSFcns.Sfcn2.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &bubu_01_M->NonInlinedSFcns.Sfcn2.inputPortCoSimAttribute[0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &bubu_01_M->NonInlinedSFcns.Sfcn2.UPtrs0;
          sfcnUPtrs[0] = bubu_01_B.Saturation;
          sfcnUPtrs[1] = &bubu_01_B.Saturation[1];
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 2);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &bubu_01_M->NonInlinedSFcns.Sfcn2.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &bubu_01_M->NonInlinedSFcns.Sfcn2.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &bubu_01_M->NonInlinedSFcns.Sfcn2.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 2);
          ssSetOutputPortSignal(rts, 0, ((real_T *) bubu_01_B.PWM));
        }
      }

      /* path info */
      ssSetModelName(rts, "PWM");
      ssSetPath(rts, "bubu_01/TRAS/PWM");
      ssSetRTModel(rts,bubu_01_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &bubu_01_M->NonInlinedSFcns.Sfcn2.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)bubu_01_P.PWM_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)bubu_01_P.PWM_P2_Size);
      }

      /* registration */
      TRAS_PWM(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: bubu_01/<S2>/ResetEncoder (TRAS_ResetEncoder) */
    {
      SimStruct *rts = bubu_01_M->childSfunctions[3];

      /* timing info */
      time_T *sfcnPeriod = bubu_01_M->NonInlinedSFcns.Sfcn3.sfcnPeriod;
      time_T *sfcnOffset = bubu_01_M->NonInlinedSFcns.Sfcn3.sfcnOffset;
      int_T *sfcnTsMap = bubu_01_M->NonInlinedSFcns.Sfcn3.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &bubu_01_M->NonInlinedSFcns.blkInfo2[3]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &bubu_01_M->NonInlinedSFcns.inputOutputPortInfo2[3]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, bubu_01_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &bubu_01_M->NonInlinedSFcns.methods2[3]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &bubu_01_M->NonInlinedSFcns.methods3[3]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &bubu_01_M->NonInlinedSFcns.methods4[3]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &bubu_01_M->NonInlinedSFcns.statesInfo2[3]);
        ssSetPeriodicStatesInfo(rts,
          &bubu_01_M->NonInlinedSFcns.periodicStatesInfo[3]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &bubu_01_M->NonInlinedSFcns.Sfcn3.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &bubu_01_M->NonInlinedSFcns.Sfcn3.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &bubu_01_M->NonInlinedSFcns.Sfcn3.inputPortCoSimAttribute[0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &bubu_01_M->NonInlinedSFcns.Sfcn3.UPtrs0;
          sfcnUPtrs[0] = &bubu_01_B.ResetEncoders;
          sfcnUPtrs[1] = &bubu_01_B.ResetEncoders;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 2);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &bubu_01_M->NonInlinedSFcns.Sfcn3.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &bubu_01_M->NonInlinedSFcns.Sfcn3.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &bubu_01_M->NonInlinedSFcns.Sfcn3.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 2);
          ssSetOutputPortSignal(rts, 0, ((real_T *) bubu_01_B.ResetEncoder));
        }
      }

      /* path info */
      ssSetModelName(rts, "ResetEncoder");
      ssSetPath(rts, "bubu_01/TRAS/ResetEncoder");
      ssSetRTModel(rts,bubu_01_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &bubu_01_M->NonInlinedSFcns.Sfcn3.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)bubu_01_P.ResetEncoder_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)bubu_01_P.ResetEncoder_P2_Size);
      }

      /* registration */
      TRAS_ResetEncoder(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: bubu_01/<S2>/Bitstream Version (TRAS_BitstreamVersion) */
    {
      SimStruct *rts = bubu_01_M->childSfunctions[4];

      /* timing info */
      time_T *sfcnPeriod = bubu_01_M->NonInlinedSFcns.Sfcn4.sfcnPeriod;
      time_T *sfcnOffset = bubu_01_M->NonInlinedSFcns.Sfcn4.sfcnOffset;
      int_T *sfcnTsMap = bubu_01_M->NonInlinedSFcns.Sfcn4.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &bubu_01_M->NonInlinedSFcns.blkInfo2[4]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &bubu_01_M->NonInlinedSFcns.inputOutputPortInfo2[4]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, bubu_01_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &bubu_01_M->NonInlinedSFcns.methods2[4]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &bubu_01_M->NonInlinedSFcns.methods3[4]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &bubu_01_M->NonInlinedSFcns.methods4[4]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &bubu_01_M->NonInlinedSFcns.statesInfo2[4]);
        ssSetPeriodicStatesInfo(rts,
          &bubu_01_M->NonInlinedSFcns.periodicStatesInfo[4]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &bubu_01_M->NonInlinedSFcns.Sfcn4.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &bubu_01_M->NonInlinedSFcns.Sfcn4.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &bubu_01_M->NonInlinedSFcns.Sfcn4.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &bubu_01_B.BitstreamVersion));
        }
      }

      /* path info */
      ssSetModelName(rts, "Bitstream Version");
      ssSetPath(rts, "bubu_01/TRAS/Bitstream Version");
      ssSetRTModel(rts,bubu_01_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &bubu_01_M->NonInlinedSFcns.Sfcn4.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)bubu_01_P.BitstreamVersion_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)bubu_01_P.BitstreamVersion_P2_Size);
      }

      /* registration */
      TRAS_BitstreamVersion(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: bubu_01/<S2>/Therm Status (TRAS_PWMTherm) */
    {
      SimStruct *rts = bubu_01_M->childSfunctions[5];

      /* timing info */
      time_T *sfcnPeriod = bubu_01_M->NonInlinedSFcns.Sfcn5.sfcnPeriod;
      time_T *sfcnOffset = bubu_01_M->NonInlinedSFcns.Sfcn5.sfcnOffset;
      int_T *sfcnTsMap = bubu_01_M->NonInlinedSFcns.Sfcn5.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &bubu_01_M->NonInlinedSFcns.blkInfo2[5]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &bubu_01_M->NonInlinedSFcns.inputOutputPortInfo2[5]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, bubu_01_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &bubu_01_M->NonInlinedSFcns.methods2[5]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &bubu_01_M->NonInlinedSFcns.methods3[5]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &bubu_01_M->NonInlinedSFcns.methods4[5]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &bubu_01_M->NonInlinedSFcns.statesInfo2[5]);
        ssSetPeriodicStatesInfo(rts,
          &bubu_01_M->NonInlinedSFcns.periodicStatesInfo[5]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &bubu_01_M->NonInlinedSFcns.Sfcn5.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &bubu_01_M->NonInlinedSFcns.Sfcn5.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &bubu_01_M->NonInlinedSFcns.Sfcn5.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 2);
          ssSetOutputPortSignal(rts, 0, ((real_T *) bubu_01_B.ThermStatus));
        }
      }

      /* path info */
      ssSetModelName(rts, "Therm Status");
      ssSetPath(rts, "bubu_01/TRAS/Therm Status");
      ssSetRTModel(rts,bubu_01_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &bubu_01_M->NonInlinedSFcns.Sfcn5.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)bubu_01_P.ThermStatus_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)bubu_01_P.ThermStatus_P2_Size);
      }

      /* registration */
      TRAS_PWMTherm(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: bubu_01/<S2>/PWMPrescaler (TRAS_PWMPrescaler) */
    {
      SimStruct *rts = bubu_01_M->childSfunctions[6];

      /* timing info */
      time_T *sfcnPeriod = bubu_01_M->NonInlinedSFcns.Sfcn6.sfcnPeriod;
      time_T *sfcnOffset = bubu_01_M->NonInlinedSFcns.Sfcn6.sfcnOffset;
      int_T *sfcnTsMap = bubu_01_M->NonInlinedSFcns.Sfcn6.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &bubu_01_M->NonInlinedSFcns.blkInfo2[6]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &bubu_01_M->NonInlinedSFcns.inputOutputPortInfo2[6]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, bubu_01_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &bubu_01_M->NonInlinedSFcns.methods2[6]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &bubu_01_M->NonInlinedSFcns.methods3[6]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &bubu_01_M->NonInlinedSFcns.methods4[6]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &bubu_01_M->NonInlinedSFcns.statesInfo2[6]);
        ssSetPeriodicStatesInfo(rts,
          &bubu_01_M->NonInlinedSFcns.periodicStatesInfo[6]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &bubu_01_M->NonInlinedSFcns.Sfcn6.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &bubu_01_M->NonInlinedSFcns.Sfcn6.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &bubu_01_M->NonInlinedSFcns.Sfcn6.inputPortCoSimAttribute[0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &bubu_01_M->NonInlinedSFcns.Sfcn6.UPtrs0;
          sfcnUPtrs[0] = bubu_01_B.PWMPrescalerSource;
          sfcnUPtrs[1] = &bubu_01_B.PWMPrescalerSource[1];
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 2);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &bubu_01_M->NonInlinedSFcns.Sfcn6.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &bubu_01_M->NonInlinedSFcns.Sfcn6.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &bubu_01_M->NonInlinedSFcns.Sfcn6.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 2);
          ssSetOutputPortSignal(rts, 0, ((real_T *) bubu_01_B.PWMPrescaler));
        }
      }

      /* path info */
      ssSetModelName(rts, "PWMPrescaler");
      ssSetPath(rts, "bubu_01/TRAS/PWMPrescaler");
      ssSetRTModel(rts,bubu_01_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &bubu_01_M->NonInlinedSFcns.Sfcn6.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)bubu_01_P.PWMPrescaler_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)bubu_01_P.PWMPrescaler_P2_Size);
      }

      /* registration */
      TRAS_PWMPrescaler(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: bubu_01/<S2>/ThermFlag  (TRAS_ThermFlag) */
    {
      SimStruct *rts = bubu_01_M->childSfunctions[7];

      /* timing info */
      time_T *sfcnPeriod = bubu_01_M->NonInlinedSFcns.Sfcn7.sfcnPeriod;
      time_T *sfcnOffset = bubu_01_M->NonInlinedSFcns.Sfcn7.sfcnOffset;
      int_T *sfcnTsMap = bubu_01_M->NonInlinedSFcns.Sfcn7.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &bubu_01_M->NonInlinedSFcns.blkInfo2[7]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &bubu_01_M->NonInlinedSFcns.inputOutputPortInfo2[7]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, bubu_01_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &bubu_01_M->NonInlinedSFcns.methods2[7]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &bubu_01_M->NonInlinedSFcns.methods3[7]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &bubu_01_M->NonInlinedSFcns.methods4[7]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &bubu_01_M->NonInlinedSFcns.statesInfo2[7]);
        ssSetPeriodicStatesInfo(rts,
          &bubu_01_M->NonInlinedSFcns.periodicStatesInfo[7]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &bubu_01_M->NonInlinedSFcns.Sfcn7.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &bubu_01_M->NonInlinedSFcns.Sfcn7.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &bubu_01_M->NonInlinedSFcns.Sfcn7.inputPortCoSimAttribute[0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &bubu_01_M->NonInlinedSFcns.Sfcn7.UPtrs0;
          sfcnUPtrs[0] = bubu_01_B.ThermFlagSource;
          sfcnUPtrs[1] = &bubu_01_B.ThermFlagSource[1];
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 2);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &bubu_01_M->NonInlinedSFcns.Sfcn7.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &bubu_01_M->NonInlinedSFcns.Sfcn7.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &bubu_01_M->NonInlinedSFcns.Sfcn7.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 2);
          ssSetOutputPortSignal(rts, 0, ((real_T *) bubu_01_B.ThermFlag));
        }
      }

      /* path info */
      ssSetModelName(rts, "ThermFlag ");
      ssSetPath(rts, "bubu_01/TRAS/ThermFlag ");
      ssSetRTModel(rts,bubu_01_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &bubu_01_M->NonInlinedSFcns.Sfcn7.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)bubu_01_P.ThermFlag_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)bubu_01_P.ThermFlag_P2_Size);
      }

      /* registration */
      TRAS_ThermFlag(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }
  }

  /* Initialize Sizes */
  bubu_01_M->Sizes.numContStates = (0);/* Number of continuous states */
  bubu_01_M->Sizes.numY = (0);         /* Number of model outputs */
  bubu_01_M->Sizes.numU = (0);         /* Number of model inputs */
  bubu_01_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  bubu_01_M->Sizes.numSampTimes = (2); /* Number of sample times */
  bubu_01_M->Sizes.numBlocks = (29);   /* Number of blocks */
  bubu_01_M->Sizes.numBlockIO = (15);  /* Number of block outputs */
  bubu_01_M->Sizes.numBlockPrms = (80);/* Sum of parameter "widths" */
  return bubu_01_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
