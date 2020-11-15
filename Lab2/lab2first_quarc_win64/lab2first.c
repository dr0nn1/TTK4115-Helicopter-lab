/*
 * lab2first.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "lab2first".
 *
 * Model version              : 1.81
 * Simulink Coder version : 8.9 (R2015b) 13-Aug-2015
 * C source code generated on : Sat Nov 14 12:08:50 2020
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "lab2first.h"
#include "lab2first_private.h"
#include "lab2first_dt.h"

/* Block signals (auto storage) */
B_lab2first_T lab2first_B;

/* Continuous states */
X_lab2first_T lab2first_X;

/* Block states (auto storage) */
DW_lab2first_T lab2first_DW;

/* Real-time model */
RT_MODEL_lab2first_T lab2first_M_;
RT_MODEL_lab2first_T *const lab2first_M = &lab2first_M_;
static void rate_monotonic_scheduler(void);

/*
 * Writes out MAT-file header.  Returns success or failure.
 * Returns:
 *      0 - success
 *      1 - failure
 */
int_T rt_WriteMat4FileHeader(FILE *fp, int32_T m, int32_T n, const char *name)
{
  typedef enum { ELITTLE_ENDIAN, EBIG_ENDIAN } ByteOrder;

  int16_T one = 1;
  ByteOrder byteOrder = (*((int8_T *)&one)==1) ? ELITTLE_ENDIAN : EBIG_ENDIAN;
  int32_T type = (byteOrder == ELITTLE_ENDIAN) ? 0: 1000;
  int32_T imagf = 0;
  int32_T name_len = (int32_T)strlen(name) + 1;
  if ((fwrite(&type, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(&m, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(&n, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(&imagf, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(&name_len, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(name, sizeof(char), name_len, fp) == 0)) {
    return(1);
  } else {
    return(0);
  }
}                                      /* end rt_WriteMat4FileHeader */

time_T rt_SimUpdateDiscreteEvents(
  int_T rtmNumSampTimes, void *rtmTimingData, int_T *rtmSampleHitPtr, int_T
  *rtmPerTaskSampleHits )
{
  rtmSampleHitPtr[1] = rtmStepTask(lab2first_M, 1);
  rtmSampleHitPtr[2] = rtmStepTask(lab2first_M, 2);
  UNUSED_PARAMETER(rtmNumSampTimes);
  UNUSED_PARAMETER(rtmTimingData);
  UNUSED_PARAMETER(rtmPerTaskSampleHits);
  return(-1);
}

/*
 *   This function updates active task flag for each subrate
 * and rate transition flags for tasks that exchange data.
 * The function assumes rate-monotonic multitasking scheduler.
 * The function must be called at model base rate so that
 * the generated code self-manages all its subrates and rate
 * transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* To ensure a deterministic data transfer between two rates,
   * data is transferred at the priority of a fast task and the frequency
   * of the slow task.  The following flags indicate when the data transfer
   * happens.  That is, a rate interaction flag is set true when both rates
   * will run, and false otherwise.
   */

  /* tid 1 shares data with slower tid rate: 2 */
  if (lab2first_M->Timing.TaskCounters.TID[1] == 0) {
    lab2first_M->Timing.RateInteraction.TID1_2 =
      (lab2first_M->Timing.TaskCounters.TID[2] == 0);

    /* update PerTaskSampleHits matrix for non-inline sfcn */
    lab2first_M->Timing.perTaskSampleHits[5] =
      lab2first_M->Timing.RateInteraction.TID1_2;
  }

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (lab2first_M->Timing.TaskCounters.TID[2])++;
  if ((lab2first_M->Timing.TaskCounters.TID[2]) > 4) {/* Sample time: [0.01s, 0.0s] */
    lab2first_M->Timing.TaskCounters.TID[2] = 0;
  }
}

/*
 * This function updates continuous states using the ODE1 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE1_IntgData *id = (ODE1_IntgData *)rtsiGetSolverData(si);
  real_T *f0 = id->f[0];
  int_T i;
  int_T nXc = 3;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  lab2first_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; ++i) {
    x[i] += h * f0[i];
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function for TID0 */
void lab2first_output0(void)           /* Sample time: [0.0s, 0.0s] */
{
  /* local block i/o variables */
  real_T rtb_HILReadEncoderTimebase_o1;
  real_T rtb_HILReadEncoderTimebase_o2;
  real_T rtb_TmpSignalConversionAtGain1I[2];
  real_T rtb_DeadZoney;
  real_T rtb_Sum[2];
  int32_T i;
  real_T u0;
  if (rtmIsMajorTimeStep(lab2first_M)) {
    /* set solver stop time */
    if (!(lab2first_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&lab2first_M->solverInfo,
                            ((lab2first_M->Timing.clockTickH0 + 1) *
        lab2first_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&lab2first_M->solverInfo,
                            ((lab2first_M->Timing.clockTick0 + 1) *
        lab2first_M->Timing.stepSize0 + lab2first_M->Timing.clockTickH0 *
        lab2first_M->Timing.stepSize0 * 4294967296.0));
    }

    {                                  /* Sample time: [0.0s, 0.0s] */
      rate_monotonic_scheduler();
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(lab2first_M)) {
    lab2first_M->Timing.t[0] = rtsiGetT(&lab2first_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(lab2first_M)) {
    /* S-Function (hil_read_encoder_timebase_block): '<S2>/HIL Read Encoder Timebase' */

    /* S-Function Block: lab2first/Heli 3D/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
    {
      t_error result;
      result = hil_task_read_encoder(lab2first_DW.HILReadEncoderTimebase_Task, 1,
        &lab2first_DW.HILReadEncoderTimebase_Buffer[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab2first_M, _rt_error_message);
      } else {
        rtb_HILReadEncoderTimebase_o1 =
          lab2first_DW.HILReadEncoderTimebase_Buffer[0];
        rtb_HILReadEncoderTimebase_o2 =
          lab2first_DW.HILReadEncoderTimebase_Buffer[1];
        rtb_DeadZoney = lab2first_DW.HILReadEncoderTimebase_Buffer[2];
      }
    }

    /* Sum: '<S2>/Add' incorporates:
     *  Constant: '<S2>/Constant'
     *  Gain: '<S2>/Elevation: Count to rad'
     */
    lab2first_B.Add = lab2first_P.ElevationCounttorad_Gain * rtb_DeadZoney +
      lab2first_P.Constant_Value;
  }

  /* TransferFcn: '<S2>/Elevation: Transfer Fcn' */
  lab2first_B.ElevationTransferFcn = 0.0;
  lab2first_B.ElevationTransferFcn += lab2first_P.ElevationTransferFcn_C *
    lab2first_X.ElevationTransferFcn_CSTATE;
  lab2first_B.ElevationTransferFcn += lab2first_P.ElevationTransferFcn_D *
    lab2first_B.Add;
  if (rtmIsMajorTimeStep(lab2first_M)) {
    /* DiscretePulseGenerator: '<Root>/Pulse Generator' */
    lab2first_B.PulseGenerator = (lab2first_DW.clockTickCounter <
      lab2first_P.PulseGenerator_Duty) && (lab2first_DW.clockTickCounter >= 0) ?
      lab2first_P.PulseGenerator_Amp : 0.0;
    if (lab2first_DW.clockTickCounter >= lab2first_P.PulseGenerator_Period - 1.0)
    {
      lab2first_DW.clockTickCounter = 0;
    } else {
      lab2first_DW.clockTickCounter++;
    }

    /* End of DiscretePulseGenerator: '<Root>/Pulse Generator' */

    /* Gain: '<S2>/Pitch: Count to rad' */
    lab2first_B.PitchCounttorad = lab2first_P.PitchCounttorad_Gain *
      rtb_HILReadEncoderTimebase_o2;

    /* SignalConversion: '<Root>/TmpSignal ConversionAtTo FileInport1' */
    rtb_TmpSignalConversionAtGain1I[0] = lab2first_B.PulseGenerator;
    rtb_TmpSignalConversionAtGain1I[1] = lab2first_B.PitchCounttorad;

    /* ToFile: '<Root>/To File' */
    if (rtmIsMajorTimeStep(lab2first_M)) {
      {
        if (!(++lab2first_DW.ToFile_IWORK.Decimation % 1) &&
            (lab2first_DW.ToFile_IWORK.Count*3)+1 < 100000000 ) {
          FILE *fp = (FILE *) lab2first_DW.ToFile_PWORK.FilePtr;
          if (fp != (NULL)) {
            real_T u[3];
            lab2first_DW.ToFile_IWORK.Decimation = 0;
            u[0] = lab2first_M->Timing.t[1];
            u[1] = rtb_TmpSignalConversionAtGain1I[0];
            u[2] = rtb_TmpSignalConversionAtGain1I[1];
            if (fwrite(u, sizeof(real_T), 3, fp) != 3) {
              rtmSetErrorStatus(lab2first_M,
                                "Error writing to MAT-file Pitch3.mat");
              return;
            }

            if (((++lab2first_DW.ToFile_IWORK.Count)*3)+1 >= 100000000) {
              (void)fprintf(stdout,
                            "*** The ToFile block will stop logging data before\n"
                            "    the simulation has ended, because it has reached\n"
                            "    the maximum number of elements (100000000)\n"
                            "    allowed in MAT-file Pitch3.mat.\n");
            }
          }
        }
      }
    }

    /* SignalConversion: '<Root>/TmpSignal ConversionAtGain1Inport1' */
    rtb_TmpSignalConversionAtGain1I[0] = lab2first_B.PulseGenerator;
    rtb_TmpSignalConversionAtGain1I[1] = 0.0;

    /* Gain: '<Root>/Gain1' */
    lab2first_B.Gain1[0] = 0.0;
    lab2first_B.Gain1[0] += lab2first_P.F[0] * rtb_TmpSignalConversionAtGain1I[0];
    lab2first_B.Gain1[0] += lab2first_P.F[2] * rtb_TmpSignalConversionAtGain1I[1];
    lab2first_B.Gain1[1] = 0.0;
    lab2first_B.Gain1[1] += lab2first_P.F[1] * rtb_TmpSignalConversionAtGain1I[0];
    lab2first_B.Gain1[1] += lab2first_P.F[3] * rtb_TmpSignalConversionAtGain1I[1];
  }

  /* TransferFcn: '<S2>/Pitch: Transfer Fcn' */
  lab2first_B.PitchTransferFcn = 0.0;
  lab2first_B.PitchTransferFcn += lab2first_P.PitchTransferFcn_C *
    lab2first_X.PitchTransferFcn_CSTATE;
  lab2first_B.PitchTransferFcn += lab2first_P.PitchTransferFcn_D *
    lab2first_B.PitchCounttorad;

  /* Sum: '<Root>/Sum' incorporates:
   *  Gain: '<Root>/Gain'
   *  SignalConversion: '<Root>/TmpSignal ConversionAtGainInport1'
   */
  for (i = 0; i < 2; i++) {
    rtb_Sum[i] = lab2first_B.Gain1[i] - ((lab2first_P.K[i + 2] *
      lab2first_B.PitchTransferFcn + lab2first_P.K[i] *
      lab2first_B.PitchCounttorad) + lab2first_P.K[i + 4] *
      lab2first_B.ElevationTransferFcn);
  }

  /* End of Sum: '<Root>/Sum' */
  if (rtmIsMajorTimeStep(lab2first_M)) {
    /* Constant: '<Root>/Constant' */
    lab2first_B.Constant = lab2first_P.Vs_o;
  }

  /* Sum: '<Root>/Add' */
  lab2first_B.Add_h = rtb_Sum[0] + lab2first_B.Constant;
  if (rtmIsMajorTimeStep(lab2first_M)) {
    /* Gain: '<S2>/Travel: Count to rad' */
    lab2first_B.TravelCounttorad = lab2first_P.TravelCounttorad_Gain *
      rtb_HILReadEncoderTimebase_o1;
  }

  /* TransferFcn: '<S2>/Travel: Transfer Fcn' */
  lab2first_B.TravelTransferFcn = 0.0;
  lab2first_B.TravelTransferFcn += lab2first_P.TravelTransferFcn_C *
    lab2first_X.TravelTransferFcn_CSTATE;
  lab2first_B.TravelTransferFcn += lab2first_P.TravelTransferFcn_D *
    lab2first_B.TravelCounttorad;
  if (rtmIsMajorTimeStep(lab2first_M)) {
  }

  /* Gain: '<S1>/Front gain' incorporates:
   *  Sum: '<S1>/Add'
   */
  u0 = (lab2first_B.Add_h - rtb_Sum[1]) * lab2first_P.Frontgain_Gain;

  /* Saturate: '<S2>/Front motor: Saturation' */
  if (u0 > lab2first_P.FrontmotorSaturation_UpperSat) {
    lab2first_B.FrontmotorSaturation = lab2first_P.FrontmotorSaturation_UpperSat;
  } else if (u0 < lab2first_P.FrontmotorSaturation_LowerSat) {
    lab2first_B.FrontmotorSaturation = lab2first_P.FrontmotorSaturation_LowerSat;
  } else {
    lab2first_B.FrontmotorSaturation = u0;
  }

  /* End of Saturate: '<S2>/Front motor: Saturation' */

  /* Gain: '<S1>/Back gain' incorporates:
   *  Sum: '<S1>/Subtract'
   */
  u0 = (lab2first_B.Add_h + rtb_Sum[1]) * lab2first_P.Backgain_Gain;

  /* Saturate: '<S2>/Back motor: Saturation' */
  if (u0 > lab2first_P.BackmotorSaturation_UpperSat) {
    lab2first_B.BackmotorSaturation = lab2first_P.BackmotorSaturation_UpperSat;
  } else if (u0 < lab2first_P.BackmotorSaturation_LowerSat) {
    lab2first_B.BackmotorSaturation = lab2first_P.BackmotorSaturation_LowerSat;
  } else {
    lab2first_B.BackmotorSaturation = u0;
  }

  /* End of Saturate: '<S2>/Back motor: Saturation' */
  if (rtmIsMajorTimeStep(lab2first_M)) {
    /* S-Function (hil_write_analog_block): '<S2>/HIL Write Analog' */

    /* S-Function Block: lab2first/Heli 3D/HIL Write Analog (hil_write_analog_block) */
    {
      t_error result;
      lab2first_DW.HILWriteAnalog_Buffer[0] = lab2first_B.FrontmotorSaturation;
      lab2first_DW.HILWriteAnalog_Buffer[1] = lab2first_B.BackmotorSaturation;
      result = hil_write_analog(lab2first_DW.HILInitialize_Card,
        lab2first_P.HILWriteAnalog_channels, 2,
        &lab2first_DW.HILWriteAnalog_Buffer[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab2first_M, _rt_error_message);
      }
    }

    /* RateTransition: '<S3>/Rate Transition: x' */
    if (lab2first_M->Timing.RateInteraction.TID1_2) {
      lab2first_B.RateTransitionx = lab2first_DW.RateTransitionx_Buffer0;
    }

    /* End of RateTransition: '<S3>/Rate Transition: x' */

    /* DeadZone: '<S3>/Dead Zone: x' */
    if (lab2first_B.RateTransitionx > lab2first_P.DeadZonex_End) {
      rtb_DeadZoney = lab2first_B.RateTransitionx - lab2first_P.DeadZonex_End;
    } else if (lab2first_B.RateTransitionx >= lab2first_P.DeadZonex_Start) {
      rtb_DeadZoney = 0.0;
    } else {
      rtb_DeadZoney = lab2first_B.RateTransitionx - lab2first_P.DeadZonex_Start;
    }

    /* End of DeadZone: '<S3>/Dead Zone: x' */

    /* Gain: '<S3>/Joystick_gain_x' incorporates:
     *  Gain: '<S3>/Gain: x'
     */
    lab2first_B.Joystick_gain_x = lab2first_P.Gainx_Gain * rtb_DeadZoney *
      lab2first_P.Joystick_gain_x;

    /* RateTransition: '<S3>/Rate Transition: y' */
    if (lab2first_M->Timing.RateInteraction.TID1_2) {
      lab2first_B.RateTransitiony = lab2first_DW.RateTransitiony_Buffer0;
    }

    /* End of RateTransition: '<S3>/Rate Transition: y' */

    /* DeadZone: '<S3>/Dead Zone: y' */
    if (lab2first_B.RateTransitiony > lab2first_P.DeadZoney_End) {
      rtb_DeadZoney = lab2first_B.RateTransitiony - lab2first_P.DeadZoney_End;
    } else if (lab2first_B.RateTransitiony >= lab2first_P.DeadZoney_Start) {
      rtb_DeadZoney = 0.0;
    } else {
      rtb_DeadZoney = lab2first_B.RateTransitiony - lab2first_P.DeadZoney_Start;
    }

    /* End of DeadZone: '<S3>/Dead Zone: y' */

    /* Gain: '<S3>/Joystick_gain_y' incorporates:
     *  Gain: '<S3>/Gain: y'
     */
    lab2first_B.Joystick_gain_y = lab2first_P.Gainy_Gain * rtb_DeadZoney *
      lab2first_P.Joystick_gain_y;
  }
}

/* Model update function for TID0 */
void lab2first_update0(void)           /* Sample time: [0.0s, 0.0s] */
{
  if (rtmIsMajorTimeStep(lab2first_M)) {
    rt_ertODEUpdateContinuousStates(&lab2first_M->solverInfo);
  }

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++lab2first_M->Timing.clockTick0)) {
    ++lab2first_M->Timing.clockTickH0;
  }

  lab2first_M->Timing.t[0] = rtsiGetSolverStopTime(&lab2first_M->solverInfo);

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick1"
   * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick1 and the high bits
   * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++lab2first_M->Timing.clockTick1)) {
    ++lab2first_M->Timing.clockTickH1;
  }

  lab2first_M->Timing.t[1] = lab2first_M->Timing.clockTick1 *
    lab2first_M->Timing.stepSize1 + lab2first_M->Timing.clockTickH1 *
    lab2first_M->Timing.stepSize1 * 4294967296.0;
}

/* Derivatives for root system: '<Root>' */
void lab2first_derivatives(void)
{
  XDot_lab2first_T *_rtXdot;
  _rtXdot = ((XDot_lab2first_T *) lab2first_M->ModelData.derivs);

  /* Derivatives for TransferFcn: '<S2>/Elevation: Transfer Fcn' */
  _rtXdot->ElevationTransferFcn_CSTATE = 0.0;
  _rtXdot->ElevationTransferFcn_CSTATE += lab2first_P.ElevationTransferFcn_A *
    lab2first_X.ElevationTransferFcn_CSTATE;
  _rtXdot->ElevationTransferFcn_CSTATE += lab2first_B.Add;

  /* Derivatives for TransferFcn: '<S2>/Pitch: Transfer Fcn' */
  _rtXdot->PitchTransferFcn_CSTATE = 0.0;
  _rtXdot->PitchTransferFcn_CSTATE += lab2first_P.PitchTransferFcn_A *
    lab2first_X.PitchTransferFcn_CSTATE;
  _rtXdot->PitchTransferFcn_CSTATE += lab2first_B.PitchCounttorad;

  /* Derivatives for TransferFcn: '<S2>/Travel: Transfer Fcn' */
  _rtXdot->TravelTransferFcn_CSTATE = 0.0;
  _rtXdot->TravelTransferFcn_CSTATE += lab2first_P.TravelTransferFcn_A *
    lab2first_X.TravelTransferFcn_CSTATE;
  _rtXdot->TravelTransferFcn_CSTATE += lab2first_B.TravelCounttorad;
}

/* Model output function for TID2 */
void lab2first_output2(void)           /* Sample time: [0.01s, 0.0s] */
{
  /* S-Function (game_controller_block): '<S3>/Game Controller' */

  /* S-Function Block: lab2first/Joystick/Game Controller (game_controller_block) */
  {
    if (lab2first_P.GameController_Enabled) {
      t_game_controller_states state;
      t_boolean new_data;
      t_error result;
      result = game_controller_poll(lab2first_DW.GameController_Controller,
        &state, &new_data);
      if (result == 0) {
        lab2first_B.GameController_o4 = state.x;
        lab2first_B.GameController_o5 = state.y;
      }
    } else {
      lab2first_B.GameController_o4 = 0;
      lab2first_B.GameController_o5 = 0;
    }
  }
}

/* Model update function for TID2 */
void lab2first_update2(void)           /* Sample time: [0.01s, 0.0s] */
{
  /* Update for RateTransition: '<S3>/Rate Transition: x' */
  lab2first_DW.RateTransitionx_Buffer0 = lab2first_B.GameController_o4;

  /* Update for RateTransition: '<S3>/Rate Transition: y' */
  lab2first_DW.RateTransitiony_Buffer0 = lab2first_B.GameController_o5;

  /* Update absolute time */
  /* The "clockTick2" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick2"
   * and "Timing.stepSize2". Size of "clockTick2" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick2 and the high bits
   * Timing.clockTickH2. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++lab2first_M->Timing.clockTick2)) {
    ++lab2first_M->Timing.clockTickH2;
  }

  lab2first_M->Timing.t[2] = lab2first_M->Timing.clockTick2 *
    lab2first_M->Timing.stepSize2 + lab2first_M->Timing.clockTickH2 *
    lab2first_M->Timing.stepSize2 * 4294967296.0;
}

/* Model output wrapper function for compatibility with a static main program */
void lab2first_output(int_T tid)
{
  switch (tid) {
   case 0 :
    lab2first_output0();
    break;

   case 2 :
    lab2first_output2();
    break;

   default :
    break;
  }
}

/* Model update wrapper function for compatibility with a static main program */
void lab2first_update(int_T tid)
{
  switch (tid) {
   case 0 :
    lab2first_update0();
    break;

   case 2 :
    lab2first_update2();
    break;

   default :
    break;
  }
}

/* Model initialize function */
void lab2first_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: lab2first/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("q8_usb", "0", &lab2first_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(lab2first_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options(lab2first_DW.HILInitialize_Card,
      "update_rate=normal;decimation=1", 32);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(lab2first_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(lab2first_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(lab2first_M, _rt_error_message);
      return;
    }

    if ((lab2first_P.HILInitialize_set_analog_input_ && !is_switching) ||
        (lab2first_P.HILInitialize_set_analog_inpu_m && is_switching)) {
      {
        int_T i1;
        real_T *dw_AIMinimums = &lab2first_DW.HILInitialize_AIMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMinimums[i1] = lab2first_P.HILInitialize_analog_input_mini;
        }
      }

      {
        int_T i1;
        real_T *dw_AIMaximums = &lab2first_DW.HILInitialize_AIMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMaximums[i1] = lab2first_P.HILInitialize_analog_input_maxi;
        }
      }

      result = hil_set_analog_input_ranges(lab2first_DW.HILInitialize_Card,
        lab2first_P.HILInitialize_analog_input_chan, 8U,
        &lab2first_DW.HILInitialize_AIMinimums[0],
        &lab2first_DW.HILInitialize_AIMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab2first_M, _rt_error_message);
        return;
      }
    }

    if ((lab2first_P.HILInitialize_set_analog_output && !is_switching) ||
        (lab2first_P.HILInitialize_set_analog_outp_b && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOMinimums = &lab2first_DW.HILInitialize_AOMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMinimums[i1] = lab2first_P.HILInitialize_analog_output_min;
        }
      }

      {
        int_T i1;
        real_T *dw_AOMaximums = &lab2first_DW.HILInitialize_AOMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMaximums[i1] = lab2first_P.HILInitialize_analog_output_max;
        }
      }

      result = hil_set_analog_output_ranges(lab2first_DW.HILInitialize_Card,
        lab2first_P.HILInitialize_analog_output_cha, 8U,
        &lab2first_DW.HILInitialize_AOMinimums[0],
        &lab2first_DW.HILInitialize_AOMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab2first_M, _rt_error_message);
        return;
      }
    }

    if ((lab2first_P.HILInitialize_set_analog_outp_e && !is_switching) ||
        (lab2first_P.HILInitialize_set_analog_outp_j && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &lab2first_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = lab2first_P.HILInitialize_initial_analog_ou;
        }
      }

      result = hil_write_analog(lab2first_DW.HILInitialize_Card,
        lab2first_P.HILInitialize_analog_output_cha, 8U,
        &lab2first_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab2first_M, _rt_error_message);
        return;
      }
    }

    if (lab2first_P.HILInitialize_set_analog_outp_p) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &lab2first_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = lab2first_P.HILInitialize_watchdog_analog_o;
        }
      }

      result = hil_watchdog_set_analog_expiration_state
        (lab2first_DW.HILInitialize_Card,
         lab2first_P.HILInitialize_analog_output_cha, 8U,
         &lab2first_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab2first_M, _rt_error_message);
        return;
      }
    }

    if ((lab2first_P.HILInitialize_set_encoder_param && !is_switching) ||
        (lab2first_P.HILInitialize_set_encoder_par_m && is_switching)) {
      {
        int_T i1;
        int32_T *dw_QuadratureModes =
          &lab2first_DW.HILInitialize_QuadratureModes[0];
        for (i1=0; i1 < 8; i1++) {
          dw_QuadratureModes[i1] = lab2first_P.HILInitialize_quadrature;
        }
      }

      result = hil_set_encoder_quadrature_mode(lab2first_DW.HILInitialize_Card,
        lab2first_P.HILInitialize_encoder_channels, 8U,
        (t_encoder_quadrature_mode *)
        &lab2first_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab2first_M, _rt_error_message);
        return;
      }
    }

    if ((lab2first_P.HILInitialize_set_encoder_count && !is_switching) ||
        (lab2first_P.HILInitialize_set_encoder_cou_k && is_switching)) {
      {
        int_T i1;
        int32_T *dw_InitialEICounts =
          &lab2first_DW.HILInitialize_InitialEICounts[0];
        for (i1=0; i1 < 8; i1++) {
          dw_InitialEICounts[i1] = lab2first_P.HILInitialize_initial_encoder_c;
        }
      }

      result = hil_set_encoder_counts(lab2first_DW.HILInitialize_Card,
        lab2first_P.HILInitialize_encoder_channels, 8U,
        &lab2first_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab2first_M, _rt_error_message);
        return;
      }
    }

    if ((lab2first_P.HILInitialize_set_pwm_params_at && !is_switching) ||
        (lab2first_P.HILInitialize_set_pwm_params__f && is_switching)) {
      uint32_T num_duty_cycle_modes = 0;
      uint32_T num_frequency_modes = 0;

      {
        int_T i1;
        int32_T *dw_POModeValues = &lab2first_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] = lab2first_P.HILInitialize_pwm_modes;
        }
      }

      result = hil_set_pwm_mode(lab2first_DW.HILInitialize_Card,
        lab2first_P.HILInitialize_pwm_channels, 8U, (t_pwm_mode *)
        &lab2first_DW.HILInitialize_POModeValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab2first_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        const uint32_T *p_HILInitialize_pwm_channels =
          lab2first_P.HILInitialize_pwm_channels;
        int32_T *dw_POModeValues = &lab2first_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          if (dw_POModeValues[i1] == PWM_DUTY_CYCLE_MODE || dw_POModeValues[i1] ==
              PWM_ONE_SHOT_MODE || dw_POModeValues[i1] == PWM_TIME_MODE) {
            lab2first_DW.HILInitialize_POSortedChans[num_duty_cycle_modes] =
              p_HILInitialize_pwm_channels[i1];
            lab2first_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes] =
              lab2first_P.HILInitialize_pwm_frequency;
            num_duty_cycle_modes++;
          } else {
            lab2first_DW.HILInitialize_POSortedChans[7U - num_frequency_modes] =
              p_HILInitialize_pwm_channels[i1];
            lab2first_DW.HILInitialize_POSortedFreqs[7U - num_frequency_modes] =
              lab2first_P.HILInitialize_pwm_frequency;
            num_frequency_modes++;
          }
        }
      }

      if (num_duty_cycle_modes > 0) {
        result = hil_set_pwm_frequency(lab2first_DW.HILInitialize_Card,
          &lab2first_DW.HILInitialize_POSortedChans[0], num_duty_cycle_modes,
          &lab2first_DW.HILInitialize_POSortedFreqs[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(lab2first_M, _rt_error_message);
          return;
        }
      }

      if (num_frequency_modes > 0) {
        result = hil_set_pwm_duty_cycle(lab2first_DW.HILInitialize_Card,
          &lab2first_DW.HILInitialize_POSortedChans[num_duty_cycle_modes],
          num_frequency_modes,
          &lab2first_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(lab2first_M, _rt_error_message);
          return;
        }
      }

      {
        int_T i1;
        int32_T *dw_POModeValues = &lab2first_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] = lab2first_P.HILInitialize_pwm_configuration;
        }
      }

      {
        int_T i1;
        int32_T *dw_POAlignValues = &lab2first_DW.HILInitialize_POAlignValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POAlignValues[i1] = lab2first_P.HILInitialize_pwm_alignment;
        }
      }

      {
        int_T i1;
        int32_T *dw_POPolarityVals = &lab2first_DW.HILInitialize_POPolarityVals
          [0];
        for (i1=0; i1 < 8; i1++) {
          dw_POPolarityVals[i1] = lab2first_P.HILInitialize_pwm_polarity;
        }
      }

      result = hil_set_pwm_configuration(lab2first_DW.HILInitialize_Card,
        lab2first_P.HILInitialize_pwm_channels, 8U,
        (t_pwm_configuration *) &lab2first_DW.HILInitialize_POModeValues[0],
        (t_pwm_alignment *) &lab2first_DW.HILInitialize_POAlignValues[0],
        (t_pwm_polarity *) &lab2first_DW.HILInitialize_POPolarityVals[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab2first_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        real_T *dw_POSortedFreqs = &lab2first_DW.HILInitialize_POSortedFreqs[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POSortedFreqs[i1] = lab2first_P.HILInitialize_pwm_leading_deadb;
        }
      }

      {
        int_T i1;
        real_T *dw_POValues = &lab2first_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = lab2first_P.HILInitialize_pwm_trailing_dead;
        }
      }

      result = hil_set_pwm_deadband(lab2first_DW.HILInitialize_Card,
        lab2first_P.HILInitialize_pwm_channels, 8U,
        &lab2first_DW.HILInitialize_POSortedFreqs[0],
        &lab2first_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab2first_M, _rt_error_message);
        return;
      }
    }

    if ((lab2first_P.HILInitialize_set_pwm_outputs_a && !is_switching) ||
        (lab2first_P.HILInitialize_set_pwm_outputs_g && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &lab2first_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = lab2first_P.HILInitialize_initial_pwm_outpu;
        }
      }

      result = hil_write_pwm(lab2first_DW.HILInitialize_Card,
        lab2first_P.HILInitialize_pwm_channels, 8U,
        &lab2first_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab2first_M, _rt_error_message);
        return;
      }
    }

    if (lab2first_P.HILInitialize_set_pwm_outputs_o) {
      {
        int_T i1;
        real_T *dw_POValues = &lab2first_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = lab2first_P.HILInitialize_watchdog_pwm_outp;
        }
      }

      result = hil_watchdog_set_pwm_expiration_state
        (lab2first_DW.HILInitialize_Card, lab2first_P.HILInitialize_pwm_channels,
         8U, &lab2first_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab2first_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for S-Function (hil_read_encoder_timebase_block): '<S2>/HIL Read Encoder Timebase' */

  /* S-Function Block: lab2first/Heli 3D/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
  {
    t_error result;
    result = hil_task_create_encoder_reader(lab2first_DW.HILInitialize_Card,
      lab2first_P.HILReadEncoderTimebase_samples_,
      lab2first_P.HILReadEncoderTimebase_channels, 3,
      &lab2first_DW.HILReadEncoderTimebase_Task);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(lab2first_M, _rt_error_message);
    }
  }

  /* Start for DiscretePulseGenerator: '<Root>/Pulse Generator' */
  lab2first_DW.clockTickCounter = -2500;

  /* Start for ToFile: '<Root>/To File' */
  {
    FILE *fp = (NULL);
    char fileName[509] = "Pitch3.mat";
    if ((fp = fopen(fileName, "wb")) == (NULL)) {
      rtmSetErrorStatus(lab2first_M, "Error creating .mat file Pitch3.mat");
      return;
    }

    if (rt_WriteMat4FileHeader(fp,3,0,"ans")) {
      rtmSetErrorStatus(lab2first_M,
                        "Error writing mat file header to file Pitch3.mat");
      return;
    }

    lab2first_DW.ToFile_IWORK.Count = 0;
    lab2first_DW.ToFile_IWORK.Decimation = -1;
    lab2first_DW.ToFile_PWORK.FilePtr = fp;
  }

  /* Start for RateTransition: '<S3>/Rate Transition: x' */
  lab2first_B.RateTransitionx = lab2first_P.RateTransitionx_X0;

  /* Start for RateTransition: '<S3>/Rate Transition: y' */
  lab2first_B.RateTransitiony = lab2first_P.RateTransitiony_X0;

  /* Start for S-Function (game_controller_block): '<S3>/Game Controller' */

  /* S-Function Block: lab2first/Joystick/Game Controller (game_controller_block) */
  {
    if (lab2first_P.GameController_Enabled) {
      t_double deadzone[6];
      t_double saturation[6];
      t_int index;
      t_error result;
      for (index = 0; index < 6; index++) {
        deadzone[index] = -1;
      }

      for (index = 0; index < 6; index++) {
        saturation[index] = -1;
      }

      result = game_controller_open(lab2first_P.GameController_ControllerNumber,
        lab2first_P.GameController_BufferSize, deadzone, saturation,
        lab2first_P.GameController_AutoCenter, 0, 1.0,
        &lab2first_DW.GameController_Controller);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab2first_M, _rt_error_message);
      }
    }
  }

  /* InitializeConditions for TransferFcn: '<S2>/Elevation: Transfer Fcn' */
  lab2first_X.ElevationTransferFcn_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<S2>/Pitch: Transfer Fcn' */
  lab2first_X.PitchTransferFcn_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<S2>/Travel: Transfer Fcn' */
  lab2first_X.TravelTransferFcn_CSTATE = 0.0;

  /* InitializeConditions for RateTransition: '<S3>/Rate Transition: x' */
  lab2first_DW.RateTransitionx_Buffer0 = lab2first_P.RateTransitionx_X0;

  /* InitializeConditions for RateTransition: '<S3>/Rate Transition: y' */
  lab2first_DW.RateTransitiony_Buffer0 = lab2first_P.RateTransitiony_X0;
}

/* Model terminate function */
void lab2first_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: lab2first/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    t_uint32 num_final_pwm_outputs = 0;
    hil_task_stop_all(lab2first_DW.HILInitialize_Card);
    hil_monitor_stop_all(lab2first_DW.HILInitialize_Card);
    is_switching = false;
    if ((lab2first_P.HILInitialize_set_analog_out_ex && !is_switching) ||
        (lab2first_P.HILInitialize_set_analog_outp_c && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &lab2first_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = lab2first_P.HILInitialize_final_analog_outp;
        }
      }

      num_final_analog_outputs = 8U;
    }

    if ((lab2first_P.HILInitialize_set_pwm_output_ap && !is_switching) ||
        (lab2first_P.HILInitialize_set_pwm_outputs_p && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &lab2first_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = lab2first_P.HILInitialize_final_pwm_outputs;
        }
      }

      num_final_pwm_outputs = 8U;
    }

    if (0
        || num_final_analog_outputs > 0
        || num_final_pwm_outputs > 0
        ) {
      /* Attempt to write the final outputs atomically (due to firmware issue in old Q2-USB). Otherwise write channels individually */
      result = hil_write(lab2first_DW.HILInitialize_Card
                         , lab2first_P.HILInitialize_analog_output_cha,
                         num_final_analog_outputs
                         , lab2first_P.HILInitialize_pwm_channels,
                         num_final_pwm_outputs
                         , NULL, 0
                         , NULL, 0
                         , &lab2first_DW.HILInitialize_AOVoltages[0]
                         , &lab2first_DW.HILInitialize_POValues[0]
                         , (t_boolean *) NULL
                         , NULL
                         );
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED) {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_analog_outputs > 0) {
          local_result = hil_write_analog(lab2first_DW.HILInitialize_Card,
            lab2first_P.HILInitialize_analog_output_cha,
            num_final_analog_outputs, &lab2first_DW.HILInitialize_AOVoltages[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_pwm_outputs > 0) {
          local_result = hil_write_pwm(lab2first_DW.HILInitialize_Card,
            lab2first_P.HILInitialize_pwm_channels, num_final_pwm_outputs,
            &lab2first_DW.HILInitialize_POValues[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(lab2first_M, _rt_error_message);
        }
      }
    }

    hil_task_delete_all(lab2first_DW.HILInitialize_Card);
    hil_monitor_delete_all(lab2first_DW.HILInitialize_Card);
    hil_close(lab2first_DW.HILInitialize_Card);
    lab2first_DW.HILInitialize_Card = NULL;
  }

  /* Terminate for ToFile: '<Root>/To File' */
  {
    FILE *fp = (FILE *) lab2first_DW.ToFile_PWORK.FilePtr;
    if (fp != (NULL)) {
      char fileName[509] = "Pitch3.mat";
      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(lab2first_M, "Error closing MAT-file Pitch3.mat");
        return;
      }

      if ((fp = fopen(fileName, "r+b")) == (NULL)) {
        rtmSetErrorStatus(lab2first_M, "Error reopening MAT-file Pitch3.mat");
        return;
      }

      if (rt_WriteMat4FileHeader(fp, 3, lab2first_DW.ToFile_IWORK.Count, "ans"))
      {
        rtmSetErrorStatus(lab2first_M,
                          "Error writing header for ans to MAT-file Pitch3.mat");
      }

      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(lab2first_M, "Error closing MAT-file Pitch3.mat");
        return;
      }

      lab2first_DW.ToFile_PWORK.FilePtr = (NULL);
    }
  }

  /* Terminate for S-Function (game_controller_block): '<S3>/Game Controller' */

  /* S-Function Block: lab2first/Joystick/Game Controller (game_controller_block) */
  {
    if (lab2first_P.GameController_Enabled) {
      game_controller_close(lab2first_DW.GameController_Controller);
      lab2first_DW.GameController_Controller = NULL;
    }
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/

/* Solver interface called by GRT_Main */
#ifndef USE_GENERATED_SOLVER

void rt_ODECreateIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEDestroyIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEUpdateContinuousStates(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

#endif

void MdlOutputs(int_T tid)
{
  if (tid == 1)
    tid = 0;
  lab2first_output(tid);
}

void MdlUpdate(int_T tid)
{
  if (tid == 1)
    tid = 0;
  lab2first_update(tid);
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
  lab2first_initialize();
}

void MdlTerminate(void)
{
  lab2first_terminate();
}

/* Registration function */
RT_MODEL_lab2first_T *lab2first(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)lab2first_M, 0,
                sizeof(RT_MODEL_lab2first_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&lab2first_M->solverInfo,
                          &lab2first_M->Timing.simTimeStep);
    rtsiSetTPtr(&lab2first_M->solverInfo, &rtmGetTPtr(lab2first_M));
    rtsiSetStepSizePtr(&lab2first_M->solverInfo, &lab2first_M->Timing.stepSize0);
    rtsiSetdXPtr(&lab2first_M->solverInfo, &lab2first_M->ModelData.derivs);
    rtsiSetContStatesPtr(&lab2first_M->solverInfo, (real_T **)
                         &lab2first_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&lab2first_M->solverInfo,
      &lab2first_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&lab2first_M->solverInfo,
      &lab2first_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&lab2first_M->solverInfo,
      &lab2first_M->ModelData.periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&lab2first_M->solverInfo,
      &lab2first_M->ModelData.periodicContStateRanges);
    rtsiSetErrorStatusPtr(&lab2first_M->solverInfo, (&rtmGetErrorStatus
      (lab2first_M)));
    rtsiSetRTModelPtr(&lab2first_M->solverInfo, lab2first_M);
  }

  rtsiSetSimTimeStep(&lab2first_M->solverInfo, MAJOR_TIME_STEP);
  lab2first_M->ModelData.intgData.f[0] = lab2first_M->ModelData.odeF[0];
  lab2first_M->ModelData.contStates = ((real_T *) &lab2first_X);
  rtsiSetSolverData(&lab2first_M->solverInfo, (void *)
                    &lab2first_M->ModelData.intgData);
  rtsiSetSolverName(&lab2first_M->solverInfo,"ode1");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = lab2first_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    mdlTsMap[2] = 2;
    lab2first_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    lab2first_M->Timing.sampleTimes = (&lab2first_M->Timing.sampleTimesArray[0]);
    lab2first_M->Timing.offsetTimes = (&lab2first_M->Timing.offsetTimesArray[0]);

    /* task periods */
    lab2first_M->Timing.sampleTimes[0] = (0.0);
    lab2first_M->Timing.sampleTimes[1] = (0.002);
    lab2first_M->Timing.sampleTimes[2] = (0.01);

    /* task offsets */
    lab2first_M->Timing.offsetTimes[0] = (0.0);
    lab2first_M->Timing.offsetTimes[1] = (0.0);
    lab2first_M->Timing.offsetTimes[2] = (0.0);
  }

  rtmSetTPtr(lab2first_M, &lab2first_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = lab2first_M->Timing.sampleHitArray;
    int_T *mdlPerTaskSampleHits = lab2first_M->Timing.perTaskSampleHitsArray;
    lab2first_M->Timing.perTaskSampleHits = (&mdlPerTaskSampleHits[0]);
    mdlSampleHits[0] = 1;
    lab2first_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(lab2first_M, 17.0);
  lab2first_M->Timing.stepSize0 = 0.002;
  lab2first_M->Timing.stepSize1 = 0.002;
  lab2first_M->Timing.stepSize2 = 0.01;

  /* External mode info */
  lab2first_M->Sizes.checksums[0] = (1016751152U);
  lab2first_M->Sizes.checksums[1] = (1877939804U);
  lab2first_M->Sizes.checksums[2] = (1251457737U);
  lab2first_M->Sizes.checksums[3] = (3270716140U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    lab2first_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(lab2first_M->extModeInfo,
      &lab2first_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(lab2first_M->extModeInfo, lab2first_M->Sizes.checksums);
    rteiSetTPtr(lab2first_M->extModeInfo, rtmGetTPtr(lab2first_M));
  }

  lab2first_M->solverInfoPtr = (&lab2first_M->solverInfo);
  lab2first_M->Timing.stepSize = (0.002);
  rtsiSetFixedStepSize(&lab2first_M->solverInfo, 0.002);
  rtsiSetSolverMode(&lab2first_M->solverInfo, SOLVER_MODE_MULTITASKING);

  /* block I/O */
  lab2first_M->ModelData.blockIO = ((void *) &lab2first_B);

  {
    lab2first_B.Add = 0.0;
    lab2first_B.ElevationTransferFcn = 0.0;
    lab2first_B.PulseGenerator = 0.0;
    lab2first_B.PitchCounttorad = 0.0;
    lab2first_B.Gain1[0] = 0.0;
    lab2first_B.Gain1[1] = 0.0;
    lab2first_B.PitchTransferFcn = 0.0;
    lab2first_B.Constant = 0.0;
    lab2first_B.Add_h = 0.0;
    lab2first_B.TravelCounttorad = 0.0;
    lab2first_B.TravelTransferFcn = 0.0;
    lab2first_B.FrontmotorSaturation = 0.0;
    lab2first_B.BackmotorSaturation = 0.0;
    lab2first_B.RateTransitionx = 0.0;
    lab2first_B.Joystick_gain_x = 0.0;
    lab2first_B.RateTransitiony = 0.0;
    lab2first_B.Joystick_gain_y = 0.0;
    lab2first_B.GameController_o4 = 0.0;
    lab2first_B.GameController_o5 = 0.0;
  }

  /* parameters */
  lab2first_M->ModelData.defaultParam = ((real_T *)&lab2first_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &lab2first_X;
    lab2first_M->ModelData.contStates = (x);
    (void) memset((void *)&lab2first_X, 0,
                  sizeof(X_lab2first_T));
  }

  /* states (dwork) */
  lab2first_M->ModelData.dwork = ((void *) &lab2first_DW);
  (void) memset((void *)&lab2first_DW, 0,
                sizeof(DW_lab2first_T));

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      lab2first_DW.HILInitialize_AIMinimums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      lab2first_DW.HILInitialize_AIMaximums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      lab2first_DW.HILInitialize_AOMinimums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      lab2first_DW.HILInitialize_AOMaximums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      lab2first_DW.HILInitialize_AOVoltages[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      lab2first_DW.HILInitialize_FilterFrequency[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      lab2first_DW.HILInitialize_POSortedFreqs[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      lab2first_DW.HILInitialize_POValues[i] = 0.0;
    }
  }

  lab2first_DW.HILWriteAnalog_Buffer[0] = 0.0;
  lab2first_DW.HILWriteAnalog_Buffer[1] = 0.0;
  lab2first_DW.RateTransitionx_Buffer0 = 0.0;
  lab2first_DW.RateTransitiony_Buffer0 = 0.0;

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    lab2first_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 17;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Initialize Sizes */
  lab2first_M->Sizes.numContStates = (3);/* Number of continuous states */
  lab2first_M->Sizes.numPeriodicContStates = (0);/* Number of periodic continuous states */
  lab2first_M->Sizes.numY = (0);       /* Number of model outputs */
  lab2first_M->Sizes.numU = (0);       /* Number of model inputs */
  lab2first_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  lab2first_M->Sizes.numSampTimes = (3);/* Number of sample times */
  lab2first_M->Sizes.numBlocks = (48); /* Number of blocks */
  lab2first_M->Sizes.numBlockIO = (18);/* Number of block outputs */
  lab2first_M->Sizes.numBlockPrms = (151);/* Sum of parameter "widths" */
  return lab2first_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
