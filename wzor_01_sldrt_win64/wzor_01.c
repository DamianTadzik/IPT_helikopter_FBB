/*
 * wzor_01.c
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
#include "wzor_01_dt.h"

/* list of Simulink Desktop Real-Time timers */
const int SLDRTTimerCount = 1;
const double SLDRTTimers[2] = {
  0.01, 0.0,
};

/* Block signals (default storage) */
B_wzor_01_T wzor_01_B;

/* Block states (default storage) */
DW_wzor_01_T wzor_01_DW;

/* Real-time model */
static RT_MODEL_wzor_01_T wzor_01_M_;
RT_MODEL_wzor_01_T *const wzor_01_M = &wzor_01_M_;

/* Model output function */
void wzor_01_output(void)
{
  /* local block i/o variables */
  real_T rtb_FromWs[3];
  real_T u0;

  /* S-Function (TRAS_AnalogInput): '<S2>/Analog Input' */

  /* Level2 S-Function Block: '<S2>/Analog Input' (TRAS_AnalogInput) */
  {
    SimStruct *rts = wzor_01_M->childSfunctions[0];
    sfcnOutputs(rts,0);
  }

  /* Gain: '<S2>/Convert to RPM' */
  wzor_01_B.ConverttoRPM[0] = wzor_01_P.ConverttoRPM_Gain *
    wzor_01_B.AnalogInput[0];
  wzor_01_B.ConverttoRPM[1] = wzor_01_P.ConverttoRPM_Gain *
    wzor_01_B.AnalogInput[1];

  /* FromWorkspace: '<S1>/FromWs' */
  {
    real_T *pDataValues = (real_T *) wzor_01_DW.FromWs_PWORK.DataPtr;
    real_T *pTimeValues = (real_T *) wzor_01_DW.FromWs_PWORK.TimePtr;
    int_T currTimeIndex = wzor_01_DW.FromWs_IWORK.PrevIndex;
    real_T t = wzor_01_M->Timing.t[0];

    /* Get index */
    if (t <= pTimeValues[0]) {
      currTimeIndex = 0;
    } else if (t >= pTimeValues[31]) {
      currTimeIndex = 30;
    } else {
      if (t < pTimeValues[currTimeIndex]) {
        while (t < pTimeValues[currTimeIndex]) {
          currTimeIndex--;
        }
      } else {
        while (t >= pTimeValues[currTimeIndex + 1]) {
          currTimeIndex++;
        }
      }
    }

    wzor_01_DW.FromWs_IWORK.PrevIndex = currTimeIndex;

    /* Post output */
    {
      real_T t1 = pTimeValues[currTimeIndex];
      real_T t2 = pTimeValues[currTimeIndex + 1];
      if (t1 == t2) {
        if (t < t1) {
          {
            int_T elIdx;
            for (elIdx = 0; elIdx < 3; ++elIdx) {
              (&rtb_FromWs[0])[elIdx] = pDataValues[currTimeIndex];
              pDataValues += 32;
            }
          }
        } else {
          {
            int_T elIdx;
            for (elIdx = 0; elIdx < 3; ++elIdx) {
              (&rtb_FromWs[0])[elIdx] = pDataValues[currTimeIndex + 1];
              pDataValues += 32;
            }
          }
        }
      } else {
        real_T f1 = (t2 - t) / (t2 - t1);
        real_T f2 = 1.0 - f1;
        real_T d1;
        real_T d2;
        int_T TimeIndex = currTimeIndex;

        {
          int_T elIdx;
          for (elIdx = 0; elIdx < 3; ++elIdx) {
            d1 = pDataValues[TimeIndex];
            d2 = pDataValues[TimeIndex + 1];
            (&rtb_FromWs[0])[elIdx] = (real_T) rtInterpolate(d1, d2, f1, f2);
            pDataValues += 32;
          }
        }
      }
    }
  }

  /* Saturate: '<Root>/Sat1' */
  if (rtb_FromWs[2] > wzor_01_P.Sat1_UpperSat) {
    /* Saturate: '<Root>/Sat1' */
    wzor_01_B.Sat1 = wzor_01_P.Sat1_UpperSat;
  } else if (rtb_FromWs[2] < wzor_01_P.Sat1_LowerSat) {
    /* Saturate: '<Root>/Sat1' */
    wzor_01_B.Sat1 = wzor_01_P.Sat1_LowerSat;
  } else {
    /* Saturate: '<Root>/Sat1' */
    wzor_01_B.Sat1 = rtb_FromWs[2];
  }

  /* End of Saturate: '<Root>/Sat1' */

  /* S-Function (TRAS_Encoder): '<S2>/Encoder' */

  /* Level2 S-Function Block: '<S2>/Encoder' (TRAS_Encoder) */
  {
    SimStruct *rts = wzor_01_M->childSfunctions[1];
    sfcnOutputs(rts,0);
  }

  /* Gain: '<S2>/Convert to rad' incorporates:
   *  Gain: '<S2>/Encoder 1024 PPR'
   */
  wzor_01_B.Converttorad[0] = wzor_01_P.Encoder1024PPR_Gain[0] *
    wzor_01_B.Encoder[0] * wzor_01_P.Converttorad_Gain;
  wzor_01_B.Converttorad[1] = wzor_01_P.Encoder1024PPR_Gain[1] *
    wzor_01_B.Encoder[1] * wzor_01_P.Converttorad_Gain;

  /* ManualSwitch: '<Root>/Reset Encoders' */
  if (wzor_01_P.ResetEncoders_CurrentSetting == 1) {
    /* ManualSwitch: '<Root>/Reset Encoders' incorporates:
     *  Constant: '<Root>/Reset'
     */
    wzor_01_B.ResetEncoders = wzor_01_P.Reset_Value;
  } else {
    /* ManualSwitch: '<Root>/Reset Encoders' incorporates:
     *  Constant: '<Root>/Normal'
     */
    wzor_01_B.ResetEncoders = wzor_01_P.Normal_Value;
  }

  /* End of ManualSwitch: '<Root>/Reset Encoders' */

  /* Saturate: '<Root>/Sat' incorporates:
   *  Constant: '<Root>/Constant'
   */
  if (wzor_01_P.Constant_Value > wzor_01_P.Sat_UpperSat) {
    u0 = wzor_01_P.Sat_UpperSat;
  } else if (wzor_01_P.Constant_Value < wzor_01_P.Sat_LowerSat) {
    u0 = wzor_01_P.Sat_LowerSat;
  } else {
    u0 = wzor_01_P.Constant_Value;
  }

  /* End of Saturate: '<Root>/Sat' */

  /* Gain: '<S2>/PWM_corr' */
  wzor_01_B.PWM_corr = wzor_01_P.PWM_corr_Gain * u0;

  /* Saturate: '<S2>/Saturation' */
  if (wzor_01_B.PWM_corr > wzor_01_P.Saturation_UpperSat) {
    /* Saturate: '<S2>/Saturation' */
    wzor_01_B.Saturation[0] = wzor_01_P.Saturation_UpperSat;
  } else if (wzor_01_B.PWM_corr < wzor_01_P.Saturation_LowerSat) {
    /* Saturate: '<S2>/Saturation' */
    wzor_01_B.Saturation[0] = wzor_01_P.Saturation_LowerSat;
  } else {
    /* Saturate: '<S2>/Saturation' */
    wzor_01_B.Saturation[0] = wzor_01_B.PWM_corr;
  }

  /* Gain: '<S2>/PWM_corr1' */
  u0 = wzor_01_P.PWM_corr1_Gain * wzor_01_B.Sat1;

  /* Saturate: '<S2>/Saturation' */
  if (u0 > wzor_01_P.Saturation_UpperSat) {
    /* Saturate: '<S2>/Saturation' */
    wzor_01_B.Saturation[1] = wzor_01_P.Saturation_UpperSat;
  } else if (u0 < wzor_01_P.Saturation_LowerSat) {
    /* Saturate: '<S2>/Saturation' */
    wzor_01_B.Saturation[1] = wzor_01_P.Saturation_LowerSat;
  } else {
    /* Saturate: '<S2>/Saturation' */
    wzor_01_B.Saturation[1] = u0;
  }

  /* S-Function (TRAS_PWM): '<S2>/PWM' */

  /* Level2 S-Function Block: '<S2>/PWM' (TRAS_PWM) */
  {
    SimStruct *rts = wzor_01_M->childSfunctions[2];
    sfcnOutputs(rts,0);
  }

  /* S-Function (TRAS_ResetEncoder): '<S2>/ResetEncoder' */

  /* Level2 S-Function Block: '<S2>/ResetEncoder' (TRAS_ResetEncoder) */
  {
    SimStruct *rts = wzor_01_M->childSfunctions[3];
    sfcnOutputs(rts,0);
  }

  /* S-Function (TRAS_BitstreamVersion): '<S2>/Bitstream Version' */

  /* Level2 S-Function Block: '<S2>/Bitstream Version' (TRAS_BitstreamVersion) */
  {
    SimStruct *rts = wzor_01_M->childSfunctions[4];
    sfcnOutputs(rts,0);
  }

  /* S-Function (TRAS_PWMTherm): '<S2>/Therm Status' */

  /* Level2 S-Function Block: '<S2>/Therm Status' (TRAS_PWMTherm) */
  {
    SimStruct *rts = wzor_01_M->childSfunctions[5];
    sfcnOutputs(rts,0);
  }

  /* Constant: '<S2>/PWMPrescalerSource' */
  wzor_01_B.PWMPrescalerSource[0] = wzor_01_P.PWMPrescalerSource_Value[0];
  wzor_01_B.PWMPrescalerSource[1] = wzor_01_P.PWMPrescalerSource_Value[1];

  /* S-Function (TRAS_PWMPrescaler): '<S2>/PWMPrescaler' */

  /* Level2 S-Function Block: '<S2>/PWMPrescaler' (TRAS_PWMPrescaler) */
  {
    SimStruct *rts = wzor_01_M->childSfunctions[6];
    sfcnOutputs(rts,0);
  }

  /* Constant: '<S2>/ThermFlagSource' */
  wzor_01_B.ThermFlagSource[0] = wzor_01_P.ThermFlagSource_Value[0];
  wzor_01_B.ThermFlagSource[1] = wzor_01_P.ThermFlagSource_Value[1];

  /* S-Function (TRAS_ThermFlag): '<S2>/ThermFlag ' */

  /* Level2 S-Function Block: '<S2>/ThermFlag ' (TRAS_ThermFlag) */
  {
    SimStruct *rts = wzor_01_M->childSfunctions[7];
    sfcnOutputs(rts,0);
  }
}

/* Model update function */
void wzor_01_update(void)
{
  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++wzor_01_M->Timing.clockTick0)) {
    ++wzor_01_M->Timing.clockTickH0;
  }

  wzor_01_M->Timing.t[0] = wzor_01_M->Timing.clockTick0 *
    wzor_01_M->Timing.stepSize0 + wzor_01_M->Timing.clockTickH0 *
    wzor_01_M->Timing.stepSize0 * 4294967296.0;

  {
    /* Update absolute timer for sample time: [0.01s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++wzor_01_M->Timing.clockTick1)) {
      ++wzor_01_M->Timing.clockTickH1;
    }

    wzor_01_M->Timing.t[1] = wzor_01_M->Timing.clockTick1 *
      wzor_01_M->Timing.stepSize1 + wzor_01_M->Timing.clockTickH1 *
      wzor_01_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Model initialize function */
void wzor_01_initialize(void)
{
  /* Start for FromWorkspace: '<S1>/FromWs' */
  {
    static real_T pTimeValues0[] = { 0.0, 5.0, 5.0, 10.0, 10.0, 15.0, 15.0, 20.0,
      20.0, 25.0, 25.0, 30.0, 30.0, 35.0, 35.0, 40.0, 40.0, 45.0, 45.0, 50.0,
      50.0, 55.0, 55.0, 60.0, 60.0, 65.0, 65.0, 70.0, 70.0, 75.0, 75.0, 80.0 } ;

    static real_T pDataValues0[] = { 0.1, 0.1, -0.1, -0.1, 0.2, 0.2, -0.2, -0.2,
      0.30000000000000004, 0.30000000000000004, -0.30000000000000004,
      -0.30000000000000004, 0.4, 0.4, -0.4, -0.4, 0.5, 0.5, -0.5, -0.5,
      0.60000000000000009, 0.60000000000000009, -0.60000000000000009,
      -0.60000000000000009, 0.70000000000000007, 0.70000000000000007,
      -0.70000000000000007, -0.70000000000000007, 0.8, 0.8, -0.8, -0.8, 0.0, 0.1,
      0.0, -0.1, 0.0, 0.2, 0.0, -0.2, 0.0, 0.30000000000000004, 0.0,
      -0.30000000000000004, 0.0, 0.4, 0.0, -0.4, 0.0, 0.5, 0.0, -0.5, 0.0,
      0.60000000000000009, 0.0, -0.60000000000000009, 0.0, 0.70000000000000007,
      0.0, -0.70000000000000007, 0.0, 0.8, 0.0, -0.8, 0.1, 0.1, 0.1, 0.1, -0.1,
      -0.1, -0.1, -0.1, 0.2, 0.2, 0.2, 0.2, -0.2, -0.2, -0.2, -0.2,
      0.30000000000000004, 0.30000000000000004, 0.30000000000000004,
      0.30000000000000004, -0.30000000000000004, -0.30000000000000004,
      -0.30000000000000004, -0.30000000000000004, 0.4, 0.4, 0.4, 0.4, -0.4, -0.4,
      -0.4, -0.4 } ;

    wzor_01_DW.FromWs_PWORK.TimePtr = (void *) pTimeValues0;
    wzor_01_DW.FromWs_PWORK.DataPtr = (void *) pDataValues0;
    wzor_01_DW.FromWs_IWORK.PrevIndex = 0;
  }

  /* Start for Constant: '<S2>/PWMPrescalerSource' */
  wzor_01_B.PWMPrescalerSource[0] = wzor_01_P.PWMPrescalerSource_Value[0];
  wzor_01_B.PWMPrescalerSource[1] = wzor_01_P.PWMPrescalerSource_Value[1];

  /* Start for Constant: '<S2>/ThermFlagSource' */
  wzor_01_B.ThermFlagSource[0] = wzor_01_P.ThermFlagSource_Value[0];
  wzor_01_B.ThermFlagSource[1] = wzor_01_P.ThermFlagSource_Value[1];
}

/* Model terminate function */
void wzor_01_terminate(void)
{
  /* Terminate for S-Function (TRAS_AnalogInput): '<S2>/Analog Input' */
  /* Level2 S-Function Block: '<S2>/Analog Input' (TRAS_AnalogInput) */
  {
    SimStruct *rts = wzor_01_M->childSfunctions[0];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (TRAS_Encoder): '<S2>/Encoder' */
  /* Level2 S-Function Block: '<S2>/Encoder' (TRAS_Encoder) */
  {
    SimStruct *rts = wzor_01_M->childSfunctions[1];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (TRAS_PWM): '<S2>/PWM' */
  /* Level2 S-Function Block: '<S2>/PWM' (TRAS_PWM) */
  {
    SimStruct *rts = wzor_01_M->childSfunctions[2];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (TRAS_ResetEncoder): '<S2>/ResetEncoder' */
  /* Level2 S-Function Block: '<S2>/ResetEncoder' (TRAS_ResetEncoder) */
  {
    SimStruct *rts = wzor_01_M->childSfunctions[3];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (TRAS_BitstreamVersion): '<S2>/Bitstream Version' */
  /* Level2 S-Function Block: '<S2>/Bitstream Version' (TRAS_BitstreamVersion) */
  {
    SimStruct *rts = wzor_01_M->childSfunctions[4];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (TRAS_PWMTherm): '<S2>/Therm Status' */
  /* Level2 S-Function Block: '<S2>/Therm Status' (TRAS_PWMTherm) */
  {
    SimStruct *rts = wzor_01_M->childSfunctions[5];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (TRAS_PWMPrescaler): '<S2>/PWMPrescaler' */
  /* Level2 S-Function Block: '<S2>/PWMPrescaler' (TRAS_PWMPrescaler) */
  {
    SimStruct *rts = wzor_01_M->childSfunctions[6];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (TRAS_ThermFlag): '<S2>/ThermFlag ' */
  /* Level2 S-Function Block: '<S2>/ThermFlag ' (TRAS_ThermFlag) */
  {
    SimStruct *rts = wzor_01_M->childSfunctions[7];
    sfcnTerminate(rts);
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  wzor_01_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  wzor_01_update();
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
  wzor_01_initialize();
}

void MdlTerminate(void)
{
  wzor_01_terminate();
}

/* Registration function */
RT_MODEL_wzor_01_T *wzor_01(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)wzor_01_M, 0,
                sizeof(RT_MODEL_wzor_01_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&wzor_01_M->solverInfo, &wzor_01_M->Timing.simTimeStep);
    rtsiSetTPtr(&wzor_01_M->solverInfo, &rtmGetTPtr(wzor_01_M));
    rtsiSetStepSizePtr(&wzor_01_M->solverInfo, &wzor_01_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&wzor_01_M->solverInfo, (&rtmGetErrorStatus(wzor_01_M)));
    rtsiSetRTModelPtr(&wzor_01_M->solverInfo, wzor_01_M);
  }

  rtsiSetSimTimeStep(&wzor_01_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&wzor_01_M->solverInfo,"FixedStepDiscrete");
  wzor_01_M->solverInfoPtr = (&wzor_01_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = wzor_01_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;

    /* polyspace +2 MISRA2012:D4.1 [Justified:Low] "wzor_01_M points to
       static memory which is guaranteed to be non-NULL" */
    wzor_01_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    wzor_01_M->Timing.sampleTimes = (&wzor_01_M->Timing.sampleTimesArray[0]);
    wzor_01_M->Timing.offsetTimes = (&wzor_01_M->Timing.offsetTimesArray[0]);

    /* task periods */
    wzor_01_M->Timing.sampleTimes[0] = (0.0);
    wzor_01_M->Timing.sampleTimes[1] = (0.01);

    /* task offsets */
    wzor_01_M->Timing.offsetTimes[0] = (0.0);
    wzor_01_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(wzor_01_M, &wzor_01_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = wzor_01_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    wzor_01_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(wzor_01_M, 80.0);
  wzor_01_M->Timing.stepSize0 = 0.01;
  wzor_01_M->Timing.stepSize1 = 0.01;

  /* External mode info */
  wzor_01_M->Sizes.checksums[0] = (2264348576U);
  wzor_01_M->Sizes.checksums[1] = (771763416U);
  wzor_01_M->Sizes.checksums[2] = (1626469818U);
  wzor_01_M->Sizes.checksums[3] = (3955398561U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[3];
    wzor_01_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(wzor_01_M->extModeInfo,
      &wzor_01_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(wzor_01_M->extModeInfo, wzor_01_M->Sizes.checksums);
    rteiSetTPtr(wzor_01_M->extModeInfo, rtmGetTPtr(wzor_01_M));
  }

  wzor_01_M->solverInfoPtr = (&wzor_01_M->solverInfo);
  wzor_01_M->Timing.stepSize = (0.01);
  rtsiSetFixedStepSize(&wzor_01_M->solverInfo, 0.01);
  rtsiSetSolverMode(&wzor_01_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  wzor_01_M->blockIO = ((void *) &wzor_01_B);

  {
    wzor_01_B.AnalogInput[0] = 0.0;
    wzor_01_B.AnalogInput[1] = 0.0;
    wzor_01_B.ConverttoRPM[0] = 0.0;
    wzor_01_B.ConverttoRPM[1] = 0.0;
    wzor_01_B.Sat1 = 0.0;
    wzor_01_B.Encoder[0] = 0.0;
    wzor_01_B.Encoder[1] = 0.0;
    wzor_01_B.Converttorad[0] = 0.0;
    wzor_01_B.Converttorad[1] = 0.0;
    wzor_01_B.ResetEncoders = 0.0;
    wzor_01_B.PWM_corr = 0.0;
    wzor_01_B.Saturation[0] = 0.0;
    wzor_01_B.Saturation[1] = 0.0;
    wzor_01_B.PWM[0] = 0.0;
    wzor_01_B.PWM[1] = 0.0;
    wzor_01_B.ResetEncoder[0] = 0.0;
    wzor_01_B.ResetEncoder[1] = 0.0;
    wzor_01_B.BitstreamVersion = 0.0;
    wzor_01_B.ThermStatus[0] = 0.0;
    wzor_01_B.ThermStatus[1] = 0.0;
    wzor_01_B.PWMPrescalerSource[0] = 0.0;
    wzor_01_B.PWMPrescalerSource[1] = 0.0;
    wzor_01_B.PWMPrescaler[0] = 0.0;
    wzor_01_B.PWMPrescaler[1] = 0.0;
    wzor_01_B.ThermFlagSource[0] = 0.0;
    wzor_01_B.ThermFlagSource[1] = 0.0;
    wzor_01_B.ThermFlag[0] = 0.0;
    wzor_01_B.ThermFlag[1] = 0.0;
  }

  /* parameters */
  wzor_01_M->defaultParam = ((real_T *)&wzor_01_P);

  /* states (dwork) */
  wzor_01_M->dwork = ((void *) &wzor_01_DW);
  (void) memset((void *)&wzor_01_DW, 0,
                sizeof(DW_wzor_01_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    wzor_01_M->SpecialInfo.mappingInfo = (&dtInfo);
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
    RTWSfcnInfo *sfcnInfo = &wzor_01_M->NonInlinedSFcns.sfcnInfo;
    wzor_01_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus(wzor_01_M)));
    wzor_01_M->Sizes.numSampTimes = (2);
    rtssSetNumRootSampTimesPtr(sfcnInfo, &wzor_01_M->Sizes.numSampTimes);
    wzor_01_M->NonInlinedSFcns.taskTimePtrs[0] = &(rtmGetTPtr(wzor_01_M)[0]);
    wzor_01_M->NonInlinedSFcns.taskTimePtrs[1] = &(rtmGetTPtr(wzor_01_M)[1]);
    rtssSetTPtrPtr(sfcnInfo,wzor_01_M->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(wzor_01_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(wzor_01_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput(wzor_01_M));
    rtssSetStepSizePtr(sfcnInfo, &wzor_01_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested(wzor_01_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo, &wzor_01_M->derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo, &wzor_01_M->zCCacheNeedsReset);
    rtssSetContTimeOutputInconsistentWithStateAtMajorStepPtr(sfcnInfo,
      &wzor_01_M->CTOutputIncnstWithState);
    rtssSetSampleHitsPtr(sfcnInfo, &wzor_01_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo, &wzor_01_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &wzor_01_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &wzor_01_M->solverInfoPtr);
  }

  wzor_01_M->Sizes.numSFcns = (8);

  /* register each child */
  {
    (void) memset((void *)&wzor_01_M->NonInlinedSFcns.childSFunctions[0], 0,
                  8*sizeof(SimStruct));
    wzor_01_M->childSfunctions = (&wzor_01_M->
      NonInlinedSFcns.childSFunctionPtrs[0]);

    {
      int_T i;
      for (i = 0; i < 8; i++) {
        wzor_01_M->childSfunctions[i] =
          (&wzor_01_M->NonInlinedSFcns.childSFunctions[i]);
      }
    }

    /* Level2 S-Function Block: wzor_01/<S2>/Analog Input (TRAS_AnalogInput) */
    {
      SimStruct *rts = wzor_01_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod = wzor_01_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset = wzor_01_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap = wzor_01_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &wzor_01_M->NonInlinedSFcns.blkInfo2[0]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &wzor_01_M->NonInlinedSFcns.inputOutputPortInfo2[0]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, wzor_01_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &wzor_01_M->NonInlinedSFcns.methods2[0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &wzor_01_M->NonInlinedSFcns.methods3[0]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &wzor_01_M->NonInlinedSFcns.methods4[0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &wzor_01_M->NonInlinedSFcns.statesInfo2[0]);
        ssSetPeriodicStatesInfo(rts,
          &wzor_01_M->NonInlinedSFcns.periodicStatesInfo[0]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &wzor_01_M->NonInlinedSFcns.Sfcn0.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &wzor_01_M->NonInlinedSFcns.Sfcn0.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &wzor_01_M->NonInlinedSFcns.Sfcn0.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 2);
          ssSetOutputPortSignal(rts, 0, ((real_T *) wzor_01_B.AnalogInput));
        }
      }

      /* path info */
      ssSetModelName(rts, "Analog Input");
      ssSetPath(rts, "wzor_01/TRAS/Analog Input");
      ssSetRTModel(rts,wzor_01_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &wzor_01_M->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 4);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)wzor_01_P.AnalogInput_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)wzor_01_P.AnalogInput_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)wzor_01_P.AnalogInput_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)wzor_01_P.AnalogInput_P4_Size);
      }

      /* registration */
      TRAS_AnalogInput(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: wzor_01/<S2>/Encoder (TRAS_Encoder) */
    {
      SimStruct *rts = wzor_01_M->childSfunctions[1];

      /* timing info */
      time_T *sfcnPeriod = wzor_01_M->NonInlinedSFcns.Sfcn1.sfcnPeriod;
      time_T *sfcnOffset = wzor_01_M->NonInlinedSFcns.Sfcn1.sfcnOffset;
      int_T *sfcnTsMap = wzor_01_M->NonInlinedSFcns.Sfcn1.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &wzor_01_M->NonInlinedSFcns.blkInfo2[1]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &wzor_01_M->NonInlinedSFcns.inputOutputPortInfo2[1]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, wzor_01_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &wzor_01_M->NonInlinedSFcns.methods2[1]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &wzor_01_M->NonInlinedSFcns.methods3[1]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &wzor_01_M->NonInlinedSFcns.methods4[1]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &wzor_01_M->NonInlinedSFcns.statesInfo2[1]);
        ssSetPeriodicStatesInfo(rts,
          &wzor_01_M->NonInlinedSFcns.periodicStatesInfo[1]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &wzor_01_M->NonInlinedSFcns.Sfcn1.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &wzor_01_M->NonInlinedSFcns.Sfcn1.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &wzor_01_M->NonInlinedSFcns.Sfcn1.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 2);
          ssSetOutputPortSignal(rts, 0, ((real_T *) wzor_01_B.Encoder));
        }
      }

      /* path info */
      ssSetModelName(rts, "Encoder");
      ssSetPath(rts, "wzor_01/TRAS/Encoder");
      ssSetRTModel(rts,wzor_01_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &wzor_01_M->NonInlinedSFcns.Sfcn1.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)wzor_01_P.Encoder_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)wzor_01_P.Encoder_P2_Size);
      }

      /* registration */
      TRAS_Encoder(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: wzor_01/<S2>/PWM (TRAS_PWM) */
    {
      SimStruct *rts = wzor_01_M->childSfunctions[2];

      /* timing info */
      time_T *sfcnPeriod = wzor_01_M->NonInlinedSFcns.Sfcn2.sfcnPeriod;
      time_T *sfcnOffset = wzor_01_M->NonInlinedSFcns.Sfcn2.sfcnOffset;
      int_T *sfcnTsMap = wzor_01_M->NonInlinedSFcns.Sfcn2.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &wzor_01_M->NonInlinedSFcns.blkInfo2[2]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &wzor_01_M->NonInlinedSFcns.inputOutputPortInfo2[2]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, wzor_01_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &wzor_01_M->NonInlinedSFcns.methods2[2]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &wzor_01_M->NonInlinedSFcns.methods3[2]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &wzor_01_M->NonInlinedSFcns.methods4[2]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &wzor_01_M->NonInlinedSFcns.statesInfo2[2]);
        ssSetPeriodicStatesInfo(rts,
          &wzor_01_M->NonInlinedSFcns.periodicStatesInfo[2]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &wzor_01_M->NonInlinedSFcns.Sfcn2.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &wzor_01_M->NonInlinedSFcns.Sfcn2.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &wzor_01_M->NonInlinedSFcns.Sfcn2.inputPortCoSimAttribute[0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &wzor_01_M->NonInlinedSFcns.Sfcn2.UPtrs0;
          sfcnUPtrs[0] = wzor_01_B.Saturation;
          sfcnUPtrs[1] = &wzor_01_B.Saturation[1];
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 2);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &wzor_01_M->NonInlinedSFcns.Sfcn2.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &wzor_01_M->NonInlinedSFcns.Sfcn2.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &wzor_01_M->NonInlinedSFcns.Sfcn2.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 2);
          ssSetOutputPortSignal(rts, 0, ((real_T *) wzor_01_B.PWM));
        }
      }

      /* path info */
      ssSetModelName(rts, "PWM");
      ssSetPath(rts, "wzor_01/TRAS/PWM");
      ssSetRTModel(rts,wzor_01_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &wzor_01_M->NonInlinedSFcns.Sfcn2.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)wzor_01_P.PWM_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)wzor_01_P.PWM_P2_Size);
      }

      /* registration */
      TRAS_PWM(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: wzor_01/<S2>/ResetEncoder (TRAS_ResetEncoder) */
    {
      SimStruct *rts = wzor_01_M->childSfunctions[3];

      /* timing info */
      time_T *sfcnPeriod = wzor_01_M->NonInlinedSFcns.Sfcn3.sfcnPeriod;
      time_T *sfcnOffset = wzor_01_M->NonInlinedSFcns.Sfcn3.sfcnOffset;
      int_T *sfcnTsMap = wzor_01_M->NonInlinedSFcns.Sfcn3.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &wzor_01_M->NonInlinedSFcns.blkInfo2[3]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &wzor_01_M->NonInlinedSFcns.inputOutputPortInfo2[3]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, wzor_01_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &wzor_01_M->NonInlinedSFcns.methods2[3]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &wzor_01_M->NonInlinedSFcns.methods3[3]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &wzor_01_M->NonInlinedSFcns.methods4[3]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &wzor_01_M->NonInlinedSFcns.statesInfo2[3]);
        ssSetPeriodicStatesInfo(rts,
          &wzor_01_M->NonInlinedSFcns.periodicStatesInfo[3]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &wzor_01_M->NonInlinedSFcns.Sfcn3.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &wzor_01_M->NonInlinedSFcns.Sfcn3.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &wzor_01_M->NonInlinedSFcns.Sfcn3.inputPortCoSimAttribute[0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &wzor_01_M->NonInlinedSFcns.Sfcn3.UPtrs0;
          sfcnUPtrs[0] = &wzor_01_B.ResetEncoders;
          sfcnUPtrs[1] = &wzor_01_B.ResetEncoders;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 2);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &wzor_01_M->NonInlinedSFcns.Sfcn3.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &wzor_01_M->NonInlinedSFcns.Sfcn3.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &wzor_01_M->NonInlinedSFcns.Sfcn3.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 2);
          ssSetOutputPortSignal(rts, 0, ((real_T *) wzor_01_B.ResetEncoder));
        }
      }

      /* path info */
      ssSetModelName(rts, "ResetEncoder");
      ssSetPath(rts, "wzor_01/TRAS/ResetEncoder");
      ssSetRTModel(rts,wzor_01_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &wzor_01_M->NonInlinedSFcns.Sfcn3.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)wzor_01_P.ResetEncoder_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)wzor_01_P.ResetEncoder_P2_Size);
      }

      /* registration */
      TRAS_ResetEncoder(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: wzor_01/<S2>/Bitstream Version (TRAS_BitstreamVersion) */
    {
      SimStruct *rts = wzor_01_M->childSfunctions[4];

      /* timing info */
      time_T *sfcnPeriod = wzor_01_M->NonInlinedSFcns.Sfcn4.sfcnPeriod;
      time_T *sfcnOffset = wzor_01_M->NonInlinedSFcns.Sfcn4.sfcnOffset;
      int_T *sfcnTsMap = wzor_01_M->NonInlinedSFcns.Sfcn4.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &wzor_01_M->NonInlinedSFcns.blkInfo2[4]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &wzor_01_M->NonInlinedSFcns.inputOutputPortInfo2[4]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, wzor_01_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &wzor_01_M->NonInlinedSFcns.methods2[4]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &wzor_01_M->NonInlinedSFcns.methods3[4]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &wzor_01_M->NonInlinedSFcns.methods4[4]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &wzor_01_M->NonInlinedSFcns.statesInfo2[4]);
        ssSetPeriodicStatesInfo(rts,
          &wzor_01_M->NonInlinedSFcns.periodicStatesInfo[4]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &wzor_01_M->NonInlinedSFcns.Sfcn4.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &wzor_01_M->NonInlinedSFcns.Sfcn4.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &wzor_01_M->NonInlinedSFcns.Sfcn4.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &wzor_01_B.BitstreamVersion));
        }
      }

      /* path info */
      ssSetModelName(rts, "Bitstream Version");
      ssSetPath(rts, "wzor_01/TRAS/Bitstream Version");
      ssSetRTModel(rts,wzor_01_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &wzor_01_M->NonInlinedSFcns.Sfcn4.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)wzor_01_P.BitstreamVersion_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)wzor_01_P.BitstreamVersion_P2_Size);
      }

      /* registration */
      TRAS_BitstreamVersion(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: wzor_01/<S2>/Therm Status (TRAS_PWMTherm) */
    {
      SimStruct *rts = wzor_01_M->childSfunctions[5];

      /* timing info */
      time_T *sfcnPeriod = wzor_01_M->NonInlinedSFcns.Sfcn5.sfcnPeriod;
      time_T *sfcnOffset = wzor_01_M->NonInlinedSFcns.Sfcn5.sfcnOffset;
      int_T *sfcnTsMap = wzor_01_M->NonInlinedSFcns.Sfcn5.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &wzor_01_M->NonInlinedSFcns.blkInfo2[5]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &wzor_01_M->NonInlinedSFcns.inputOutputPortInfo2[5]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, wzor_01_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &wzor_01_M->NonInlinedSFcns.methods2[5]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &wzor_01_M->NonInlinedSFcns.methods3[5]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &wzor_01_M->NonInlinedSFcns.methods4[5]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &wzor_01_M->NonInlinedSFcns.statesInfo2[5]);
        ssSetPeriodicStatesInfo(rts,
          &wzor_01_M->NonInlinedSFcns.periodicStatesInfo[5]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &wzor_01_M->NonInlinedSFcns.Sfcn5.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &wzor_01_M->NonInlinedSFcns.Sfcn5.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &wzor_01_M->NonInlinedSFcns.Sfcn5.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 2);
          ssSetOutputPortSignal(rts, 0, ((real_T *) wzor_01_B.ThermStatus));
        }
      }

      /* path info */
      ssSetModelName(rts, "Therm Status");
      ssSetPath(rts, "wzor_01/TRAS/Therm Status");
      ssSetRTModel(rts,wzor_01_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &wzor_01_M->NonInlinedSFcns.Sfcn5.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)wzor_01_P.ThermStatus_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)wzor_01_P.ThermStatus_P2_Size);
      }

      /* registration */
      TRAS_PWMTherm(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: wzor_01/<S2>/PWMPrescaler (TRAS_PWMPrescaler) */
    {
      SimStruct *rts = wzor_01_M->childSfunctions[6];

      /* timing info */
      time_T *sfcnPeriod = wzor_01_M->NonInlinedSFcns.Sfcn6.sfcnPeriod;
      time_T *sfcnOffset = wzor_01_M->NonInlinedSFcns.Sfcn6.sfcnOffset;
      int_T *sfcnTsMap = wzor_01_M->NonInlinedSFcns.Sfcn6.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &wzor_01_M->NonInlinedSFcns.blkInfo2[6]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &wzor_01_M->NonInlinedSFcns.inputOutputPortInfo2[6]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, wzor_01_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &wzor_01_M->NonInlinedSFcns.methods2[6]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &wzor_01_M->NonInlinedSFcns.methods3[6]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &wzor_01_M->NonInlinedSFcns.methods4[6]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &wzor_01_M->NonInlinedSFcns.statesInfo2[6]);
        ssSetPeriodicStatesInfo(rts,
          &wzor_01_M->NonInlinedSFcns.periodicStatesInfo[6]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &wzor_01_M->NonInlinedSFcns.Sfcn6.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &wzor_01_M->NonInlinedSFcns.Sfcn6.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &wzor_01_M->NonInlinedSFcns.Sfcn6.inputPortCoSimAttribute[0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &wzor_01_M->NonInlinedSFcns.Sfcn6.UPtrs0;
          sfcnUPtrs[0] = wzor_01_B.PWMPrescalerSource;
          sfcnUPtrs[1] = &wzor_01_B.PWMPrescalerSource[1];
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 2);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &wzor_01_M->NonInlinedSFcns.Sfcn6.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &wzor_01_M->NonInlinedSFcns.Sfcn6.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &wzor_01_M->NonInlinedSFcns.Sfcn6.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 2);
          ssSetOutputPortSignal(rts, 0, ((real_T *) wzor_01_B.PWMPrescaler));
        }
      }

      /* path info */
      ssSetModelName(rts, "PWMPrescaler");
      ssSetPath(rts, "wzor_01/TRAS/PWMPrescaler");
      ssSetRTModel(rts,wzor_01_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &wzor_01_M->NonInlinedSFcns.Sfcn6.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)wzor_01_P.PWMPrescaler_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)wzor_01_P.PWMPrescaler_P2_Size);
      }

      /* registration */
      TRAS_PWMPrescaler(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: wzor_01/<S2>/ThermFlag  (TRAS_ThermFlag) */
    {
      SimStruct *rts = wzor_01_M->childSfunctions[7];

      /* timing info */
      time_T *sfcnPeriod = wzor_01_M->NonInlinedSFcns.Sfcn7.sfcnPeriod;
      time_T *sfcnOffset = wzor_01_M->NonInlinedSFcns.Sfcn7.sfcnOffset;
      int_T *sfcnTsMap = wzor_01_M->NonInlinedSFcns.Sfcn7.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &wzor_01_M->NonInlinedSFcns.blkInfo2[7]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &wzor_01_M->NonInlinedSFcns.inputOutputPortInfo2[7]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, wzor_01_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &wzor_01_M->NonInlinedSFcns.methods2[7]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &wzor_01_M->NonInlinedSFcns.methods3[7]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &wzor_01_M->NonInlinedSFcns.methods4[7]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &wzor_01_M->NonInlinedSFcns.statesInfo2[7]);
        ssSetPeriodicStatesInfo(rts,
          &wzor_01_M->NonInlinedSFcns.periodicStatesInfo[7]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &wzor_01_M->NonInlinedSFcns.Sfcn7.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &wzor_01_M->NonInlinedSFcns.Sfcn7.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &wzor_01_M->NonInlinedSFcns.Sfcn7.inputPortCoSimAttribute[0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &wzor_01_M->NonInlinedSFcns.Sfcn7.UPtrs0;
          sfcnUPtrs[0] = wzor_01_B.ThermFlagSource;
          sfcnUPtrs[1] = &wzor_01_B.ThermFlagSource[1];
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 2);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &wzor_01_M->NonInlinedSFcns.Sfcn7.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &wzor_01_M->NonInlinedSFcns.Sfcn7.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &wzor_01_M->NonInlinedSFcns.Sfcn7.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 2);
          ssSetOutputPortSignal(rts, 0, ((real_T *) wzor_01_B.ThermFlag));
        }
      }

      /* path info */
      ssSetModelName(rts, "ThermFlag ");
      ssSetPath(rts, "wzor_01/TRAS/ThermFlag ");
      ssSetRTModel(rts,wzor_01_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &wzor_01_M->NonInlinedSFcns.Sfcn7.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)wzor_01_P.ThermFlag_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)wzor_01_P.ThermFlag_P2_Size);
      }

      /* registration */
      TRAS_ThermFlag(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

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
  wzor_01_M->Sizes.numContStates = (0);/* Number of continuous states */
  wzor_01_M->Sizes.numY = (0);         /* Number of model outputs */
  wzor_01_M->Sizes.numU = (0);         /* Number of model inputs */
  wzor_01_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  wzor_01_M->Sizes.numSampTimes = (2); /* Number of sample times */
  wzor_01_M->Sizes.numBlocks = (28);   /* Number of blocks */
  wzor_01_M->Sizes.numBlockIO = (16);  /* Number of block outputs */
  wzor_01_M->Sizes.numBlockPrms = (76);/* Sum of parameter "widths" */
  return wzor_01_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
