/*
 * heli_q8.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "heli_q8".
 *
 * Model version              : 1.98
 * Simulink Coder version : 8.9 (R2015b) 13-Aug-2015
 * C source code generated on : Sat Nov 14 14:44:50 2020
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "heli_q8.h"
#include "heli_q8_private.h"
#include "heli_q8_dt.h"

t_stream heli_q8_rtZt_stream = NULL;

/* Block signals (auto storage) */
B_heli_q8_T heli_q8_B;

/* Continuous states */
X_heli_q8_T heli_q8_X;

/* Block states (auto storage) */
DW_heli_q8_T heli_q8_DW;

/* Real-time model */
RT_MODEL_heli_q8_T heli_q8_M_;
RT_MODEL_heli_q8_T *const heli_q8_M = &heli_q8_M_;

/* Forward declaration for local functions */
static void heli_q8_mrdivide(real_T A[30], const real_T B[25]);
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
  rtmSampleHitPtr[1] = rtmStepTask(heli_q8_M, 1);
  rtmSampleHitPtr[2] = rtmStepTask(heli_q8_M, 2);
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
  if (heli_q8_M->Timing.TaskCounters.TID[1] == 0) {
    heli_q8_M->Timing.RateInteraction.TID1_2 =
      (heli_q8_M->Timing.TaskCounters.TID[2] == 0);

    /* update PerTaskSampleHits matrix for non-inline sfcn */
    heli_q8_M->Timing.perTaskSampleHits[5] =
      heli_q8_M->Timing.RateInteraction.TID1_2;
  }

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (heli_q8_M->Timing.TaskCounters.TID[2])++;
  if ((heli_q8_M->Timing.TaskCounters.TID[2]) > 4) {/* Sample time: [0.01s, 0.0s] */
    heli_q8_M->Timing.TaskCounters.TID[2] = 0;
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
  int_T nXc = 5;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  heli_q8_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; ++i) {
    x[i] += h * f0[i];
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/*
 * Output and update for action system:
 *    '<S9>/If Action Subsystem1'
 *    '<S9>/If Action Subsystem3'
 */
void heli_q8_IfActionSubsystem1(real_T rtu_In1, real_T *rty_Out1)
{
  /* Inport: '<S13>/In1' */
  *rty_Out1 = rtu_In1;
}

/*
 * Output and update for action system:
 *    '<S9>/If Action Subsystem'
 *    '<S9>/If Action Subsystem2'
 */
void heli_q8_IfActionSubsystem(real_T rtu_In1, B_IfActionSubsystem_heli_q8_T
  *localB)
{
  /* Inport: '<S12>/In1' */
  localB->In1 = rtu_In1;
}

/* Function for MATLAB Function: '<S8>/MATLAB Function1' */
static void heli_q8_mrdivide(real_T A[30], const real_T B[25])
{
  int32_T jp;
  real_T temp;
  real_T b_A[25];
  int8_T ipiv[5];
  int32_T j;
  int32_T ix;
  real_T s;
  int32_T c_ix;
  int32_T d;
  int32_T ijA;
  int32_T b_jAcol;
  int32_T b_kBcol;
  memcpy(&b_A[0], &B[0], 25U * sizeof(real_T));
  for (j = 0; j < 5; j++) {
    ipiv[j] = (int8_T)(1 + j);
  }

  for (j = 0; j < 4; j++) {
    jp = j * 6;
    b_jAcol = 0;
    ix = jp;
    temp = fabs(b_A[jp]);
    for (b_kBcol = 2; b_kBcol <= 5 - j; b_kBcol++) {
      ix++;
      s = fabs(b_A[ix]);
      if (s > temp) {
        b_jAcol = b_kBcol - 1;
        temp = s;
      }
    }

    if (b_A[jp + b_jAcol] != 0.0) {
      if (b_jAcol != 0) {
        ipiv[j] = (int8_T)((j + b_jAcol) + 1);
        ix = j;
        b_jAcol += j;
        for (b_kBcol = 0; b_kBcol < 5; b_kBcol++) {
          temp = b_A[ix];
          b_A[ix] = b_A[b_jAcol];
          b_A[b_jAcol] = temp;
          ix += 5;
          b_jAcol += 5;
        }
      }

      b_jAcol = (jp - j) + 5;
      for (ix = jp + 1; ix + 1 <= b_jAcol; ix++) {
        b_A[ix] /= b_A[jp];
      }
    }

    b_jAcol = jp;
    ix = jp + 5;
    for (b_kBcol = 1; b_kBcol <= 4 - j; b_kBcol++) {
      temp = b_A[ix];
      if (b_A[ix] != 0.0) {
        c_ix = jp + 1;
        d = (b_jAcol - j) + 10;
        for (ijA = 6 + b_jAcol; ijA + 1 <= d; ijA++) {
          b_A[ijA] += b_A[c_ix] * -temp;
          c_ix++;
        }
      }

      ix += 5;
      b_jAcol += 5;
    }
  }

  for (j = 0; j < 5; j++) {
    jp = 6 * j;
    b_jAcol = 5 * j;
    for (ix = 1; ix <= j; ix++) {
      b_kBcol = (ix - 1) * 6;
      if (b_A[(ix + b_jAcol) - 1] != 0.0) {
        for (c_ix = 0; c_ix < 6; c_ix++) {
          A[c_ix + jp] -= b_A[(ix + b_jAcol) - 1] * A[c_ix + b_kBcol];
        }
      }
    }

    temp = 1.0 / b_A[j + b_jAcol];
    for (b_jAcol = 0; b_jAcol < 6; b_jAcol++) {
      A[b_jAcol + jp] *= temp;
    }
  }

  for (j = 4; j >= 0; j += -1) {
    jp = 6 * j;
    b_jAcol = 5 * j - 1;
    for (ix = j + 2; ix < 6; ix++) {
      b_kBcol = (ix - 1) * 6;
      if (b_A[ix + b_jAcol] != 0.0) {
        for (c_ix = 0; c_ix < 6; c_ix++) {
          A[c_ix + jp] -= b_A[ix + b_jAcol] * A[c_ix + b_kBcol];
        }
      }
    }
  }

  for (j = 3; j >= 0; j += -1) {
    if (j + 1 != ipiv[j]) {
      jp = ipiv[j] - 1;
      for (b_jAcol = 0; b_jAcol < 6; b_jAcol++) {
        temp = A[6 * j + b_jAcol];
        A[b_jAcol + 6 * j] = A[6 * jp + b_jAcol];
        A[b_jAcol + 6 * jp] = temp;
      }
    }
  }
}

/* Model output function for TID0 */
void heli_q8_output0(void)             /* Sample time: [0.0s, 0.0s] */
{
  /* local block i/o variables */
  real_T rtb_Gain2[3];
  real_T rtb_Sqrt;
  real_T rtb_HILReadEncoderTimebase_o1;
  real_T rtb_HILReadEncoderTimebase_o2;
  real_T rtb_TmpSignalConversionAtToFile[3];
  real_T rtb_DeadZoney;
  t_stream_ptr rtb_StreamCall1_o1;
  t_stream_ptr rtb_StreamFormattedWrite_o1;
  real32_T rtb_StreamRead1_o2[10];
  int32_T rtb_StreamFormattedWrite_o2;
  int32_T rtb_StreamCall1_o3;
  int32_T rtb_StreamRead1_o5;
  boolean_T rtb_StreamRead1_o3;
  real_T K[30];
  static const int8_T I[36] = { 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0,
    0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1 };

  int8_T rtAction;
  real_T rtb_Sum[2];
  real_T rtb_UnitDelay[6];
  real_T rtb_ManualSwitch;
  real_T rtb_Merge[5];
  real_T rtb_UnitDelay1[36];
  real_T euler_rates[3];
  int32_T i;
  real_T tmp[25];
  real_T tmp_0[9];
  real_T tmp_1[3];
  real_T rtb_Merge_0[5];
  real_T I_0[36];
  real_T I_1[36];
  real_T I_2[36];
  real_T K_0[30];
  real_T tmp_2[5];
  real_T tmp_3[6];
  int32_T i_0;
  int32_T i_1;
  if (rtmIsMajorTimeStep(heli_q8_M)) {
    /* set solver stop time */
    if (!(heli_q8_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&heli_q8_M->solverInfo,
                            ((heli_q8_M->Timing.clockTickH0 + 1) *
        heli_q8_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&heli_q8_M->solverInfo,
                            ((heli_q8_M->Timing.clockTick0 + 1) *
        heli_q8_M->Timing.stepSize0 + heli_q8_M->Timing.clockTickH0 *
        heli_q8_M->Timing.stepSize0 * 4294967296.0));
    }

    {                                  /* Sample time: [0.0s, 0.0s] */
      rate_monotonic_scheduler();
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(heli_q8_M)) {
    heli_q8_M->Timing.t[0] = rtsiGetT(&heli_q8_M->solverInfo);
  }

  /* Reset subsysRan breadcrumbs */
  srClearBC(heli_q8_DW.IfActionSubsystem1_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(heli_q8_DW.IfActionSubsystem2_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(heli_q8_DW.IfActionSubsystem1.IfActionSubsystem1_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(heli_q8_DW.IfActionSubsystem.IfActionSubsystem_SubsysRanBC);
  if (rtmIsMajorTimeStep(heli_q8_M)) {
    /* S-Function (hil_read_encoder_timebase_block): '<S3>/HIL Read Encoder Timebase' */

    /* S-Function Block: heli_q8/Heli 3D/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
    {
      t_error result;
      result = hil_task_read_encoder(heli_q8_DW.HILReadEncoderTimebase_Task, 1,
        &heli_q8_DW.HILReadEncoderTimebase_Buffer[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_M, _rt_error_message);
      } else {
        rtb_HILReadEncoderTimebase_o1 =
          heli_q8_DW.HILReadEncoderTimebase_Buffer[0];
        rtb_HILReadEncoderTimebase_o2 =
          heli_q8_DW.HILReadEncoderTimebase_Buffer[1];
        rtb_DeadZoney = heli_q8_DW.HILReadEncoderTimebase_Buffer[2];
      }
    }

    /* Sum: '<S3>/Add' incorporates:
     *  Constant: '<S3>/Constant'
     *  Gain: '<S3>/Elevation: Count to rad'
     */
    heli_q8_B.Add = heli_q8_P.ElevationCounttorad_Gain * rtb_DeadZoney +
      heli_q8_P.Constant_Value;

    /* UnitDelay: '<S8>/Unit Delay' */
    for (i = 0; i < 6; i++) {
      rtb_UnitDelay[i] = heli_q8_DW.UnitDelay_DSTATE[i];
    }

    /* End of UnitDelay: '<S8>/Unit Delay' */

    /* UnitDelay: '<S8>/Unit Delay1' */
    memcpy(&rtb_UnitDelay1[0], &heli_q8_DW.UnitDelay1_DSTATE[0], 36U * sizeof
           (real_T));

    /* S-Function (stream_call_block): '<S4>/Stream Call1' */

    /* S-Function Block: heli_q8/IMU/Stream Call1 (stream_call_block) */
    {
      t_error result = 0;
      t_boolean close_flag = (heli_q8_P.Constant_Value_i != 0);
      rtb_StreamCall1_o1 = NULL;
      switch (heli_q8_DW.StreamCall1_State) {
       case STREAM_CALL_STATE_NOT_CONNECTED:
        {
          if (!close_flag) {
            /* Make sure URI is null-terminated */
            if (string_length((char *) heli_q8_P.StringConstant_Value, 255) ==
                255) {
              rtmSetErrorStatus(heli_q8_M,
                                "URI passed to Stream Call block is not null-terminated!");
              result = -QERR_STRING_NOT_TERMINATED;
            } else {
              result = stream_connect((char *) heli_q8_P.StringConstant_Value,
                true, heli_q8_P.StreamCall1_SendBufferSize,
                heli_q8_P.StreamCall1_ReceiveBufferSize,
                &heli_q8_DW.StreamCall1_Stream);
              if (result == 0) {
                heli_q8_DW.StreamCall1_State = STREAM_CALL_STATE_CONNECTED;
                stream_set_byte_order(heli_q8_DW.StreamCall1_Stream,
                                      (t_stream_byte_order)
                                      heli_q8_P.StreamCall1_Endian);
                rtb_StreamCall1_o1 = &heli_q8_DW.StreamCall1_Stream;
              } else if (result == -QERR_WOULD_BLOCK) {
                heli_q8_DW.StreamCall1_State = STREAM_CALL_STATE_CONNECTING;
                result = 0;
              }
            }
          }
          break;
        }

       case STREAM_CALL_STATE_CONNECTING:
        {
          if (!close_flag) {
            const t_timeout timeout = { 0, 0, false };/* zero seconds */

            result = stream_poll(heli_q8_DW.StreamCall1_Stream, &timeout,
                                 STREAM_POLL_CONNECT);
            if (result > 0) {
              heli_q8_DW.StreamCall1_State = STREAM_CALL_STATE_CONNECTED;
              stream_set_byte_order(heli_q8_DW.StreamCall1_Stream,
                                    (t_stream_byte_order)
                                    heli_q8_P.StreamCall1_Endian);
              rtb_StreamCall1_o1 = &heli_q8_DW.StreamCall1_Stream;
              result = 0;
              break;
            } else if (result == 0) {
              break;
            }
          }

          /* Fall through deliberately */
        }

       case STREAM_CALL_STATE_CONNECTED:
        {
          rtb_StreamCall1_o1 = &heli_q8_DW.StreamCall1_Stream;
          if (!close_flag) {
            break;
          }

          /* Fall through deliberately */
        }

       default:
        {
          t_error close_result = stream_close(heli_q8_DW.StreamCall1_Stream);
          if (close_result == 0) {
            heli_q8_DW.StreamCall1_State = STREAM_CALL_STATE_NOT_CONNECTED;
            heli_q8_DW.StreamCall1_Stream = NULL;
            rtb_StreamCall1_o1 = NULL;
          } else if (result == 0) {
            result = close_result;
          }
          break;
        }
      }

      heli_q8_B.StreamCall1_o2 = heli_q8_DW.StreamCall1_State;
      rtb_StreamCall1_o3 = (int32_T) result;
    }

    /* S-Function (stream_formatted_write_block): '<S4>/Stream Formatted Write' */
    {
      t_error result;
      if (rtb_StreamCall1_o1 != NULL) {
        result = stream_print_utf8_char_array(*rtb_StreamCall1_o1,
          heli_q8_P.StreamFormattedWrite_MaxUnits, &rtb_StreamFormattedWrite_o2,
          "%c\n"
          , (char) heli_q8_P.Constant1_Value
          );
        if (result > 0) {
          result = stream_flush(*rtb_StreamCall1_o1);
        }

        if (result == -QERR_WOULD_BLOCK) {
          result = 0;
        }
      }

      rtb_StreamFormattedWrite_o1 = rtb_StreamCall1_o1;
    }

    /* S-Function (stream_read_block): '<S4>/Stream Read1' */
    /* S-Function Block: heli_q8/IMU/Stream Read1 (stream_read_block) */
    {
      t_error result;
      memset(&rtb_StreamRead1_o2[0], 0, 10 * sizeof(real32_T));
      if (rtb_StreamFormattedWrite_o1 != NULL) {
        result = stream_receive_unit_array(*rtb_StreamFormattedWrite_o1,
          &rtb_StreamRead1_o2[0], sizeof(real32_T), 10);
        rtb_StreamRead1_o3 = (result > 0);
        if (result > 0 || result == -QERR_WOULD_BLOCK) {
          result = 0;
        }
      } else {
        rtb_StreamRead1_o3 = false;
        result = 0;
      }

      rtb_StreamRead1_o5 = (int32_T) result;
    }

    /* ManualSwitch: '<Root>/Manual Switch' incorporates:
     *  Constant: '<Root>/Constant2'
     */
    if (heli_q8_P.ManualSwitch_CurrentSetting == 1) {
      rtb_ManualSwitch = heli_q8_P.Constant2_Value;
    } else {
      rtb_ManualSwitch = rtb_StreamRead1_o3;
    }

    /* End of ManualSwitch: '<Root>/Manual Switch' */

    /* Switch: '<S4>/Switch' incorporates:
     *  DataTypeConversion: '<S4>/Data Type Conversion'
     *  Memory: '<S4>/Memory'
     */
    for (i = 0; i < 10; i++) {
      if (rtb_StreamRead1_o3) {
        heli_q8_B.Switch[i] = rtb_StreamRead1_o2[i];
      } else {
        heli_q8_B.Switch[i] = heli_q8_DW.Memory_PreviousInput[i];
      }
    }

    /* End of Switch: '<S4>/Switch' */

    /* Gain: '<S4>/Gain2' */
    for (i = 0; i < 3; i++) {
      rtb_Gain2[i] = 0.0;
      rtb_Gain2[i] += heli_q8_P.Gain2_Gain[i] * heli_q8_B.Switch[0];
      rtb_Gain2[i] += heli_q8_P.Gain2_Gain[i + 3] * heli_q8_B.Switch[1];
      rtb_Gain2[i] += heli_q8_P.Gain2_Gain[i + 6] * heli_q8_B.Switch[2];
    }

    /* End of Gain: '<S4>/Gain2' */

    /* If: '<S9>/If1' incorporates:
     *  Constant: '<S9>/Constant1'
     */
    if (rtmIsMajorTimeStep(heli_q8_M)) {
      rtAction = (int8_T)!(rtb_Gain2[2] == 0.0);
      heli_q8_DW.If1_ActiveSubsystem = rtAction;
    } else {
      rtAction = heli_q8_DW.If1_ActiveSubsystem;
    }

    switch (rtAction) {
     case 0:
      /* Outputs for IfAction SubSystem: '<S9>/If Action Subsystem3' incorporates:
       *  ActionPort: '<S15>/Action Port'
       */
      heli_q8_IfActionSubsystem1(heli_q8_P.Constant1_Value_j, &heli_q8_B.Merge);
      if (rtmIsMajorTimeStep(heli_q8_M)) {
        srUpdateBC(heli_q8_DW.IfActionSubsystem3.IfActionSubsystem1_SubsysRanBC);
      }

      /* End of Outputs for SubSystem: '<S9>/If Action Subsystem3' */
      break;

     case 1:
      /* Outputs for IfAction SubSystem: '<S9>/If Action Subsystem2' incorporates:
       *  ActionPort: '<S14>/Action Port'
       */
      heli_q8_IfActionSubsystem(rtb_Gain2[2], &heli_q8_B.IfActionSubsystem2);
      if (rtmIsMajorTimeStep(heli_q8_M)) {
        srUpdateBC(heli_q8_DW.IfActionSubsystem2.IfActionSubsystem_SubsysRanBC);
      }

      /* End of Outputs for SubSystem: '<S9>/If Action Subsystem2' */
      break;
    }

    /* End of If: '<S9>/If1' */

    /* Trigonometry: '<S9>/Trigonometric Function' incorporates:
     *  Product: '<S9>/Divide'
     */
    heli_q8_B.Merge = atan(rtb_Gain2[1] / heli_q8_B.IfActionSubsystem2.In1);

    /* Sum: '<S9>/Add' incorporates:
     *  Product: '<S9>/Product'
     *  Product: '<S9>/Product1'
     */
    rtb_DeadZoney = rtb_Gain2[1] * rtb_Gain2[1] + rtb_Gain2[2] * rtb_Gain2[2];

    /* Sqrt: '<S9>/Sqrt' */
    rtb_Sqrt = sqrt(rtb_DeadZoney);

    /* If: '<S9>/If' incorporates:
     *  Constant: '<S9>/Constant'
     */
    if (rtmIsMajorTimeStep(heli_q8_M)) {
      rtAction = (int8_T)!(rtb_Sqrt == 0.0);
      heli_q8_DW.If_ActiveSubsystem = rtAction;
    } else {
      rtAction = heli_q8_DW.If_ActiveSubsystem;
    }

    switch (rtAction) {
     case 0:
      /* Outputs for IfAction SubSystem: '<S9>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S13>/Action Port'
       */
      heli_q8_IfActionSubsystem1(heli_q8_P.Constant_Value_f, &heli_q8_B.Merge1);
      if (rtmIsMajorTimeStep(heli_q8_M)) {
        srUpdateBC(heli_q8_DW.IfActionSubsystem1.IfActionSubsystem1_SubsysRanBC);
      }

      /* End of Outputs for SubSystem: '<S9>/If Action Subsystem1' */
      break;

     case 1:
      /* Outputs for IfAction SubSystem: '<S9>/If Action Subsystem' incorporates:
       *  ActionPort: '<S12>/Action Port'
       */
      heli_q8_IfActionSubsystem(rtb_Sqrt, &heli_q8_B.IfActionSubsystem);
      if (rtmIsMajorTimeStep(heli_q8_M)) {
        srUpdateBC(heli_q8_DW.IfActionSubsystem.IfActionSubsystem_SubsysRanBC);
      }

      /* End of Outputs for SubSystem: '<S9>/If Action Subsystem' */
      break;
    }

    /* End of If: '<S9>/If' */

    /* Trigonometry: '<S9>/Trigonometric Function1' incorporates:
     *  Product: '<S9>/Divide1'
     */
    heli_q8_B.Merge1 = atan(rtb_Gain2[0] / heli_q8_B.IfActionSubsystem.In1);

    /* Gain: '<S3>/Pitch: Count to rad' */
    heli_q8_B.PitchCounttorad = heli_q8_P.PitchCounttorad_Gain *
      rtb_HILReadEncoderTimebase_o2;

    /* Gain: '<S3>/Travel: Count to rad' */
    heli_q8_B.TravelCounttorad = heli_q8_P.TravelCounttorad_Gain *
      rtb_HILReadEncoderTimebase_o1;

    /* MATLAB Function: '<Root>/Gyro vector to [pitch rate, elevation rate, travle rate]' incorporates:
     *  SignalConversion: '<S2>/TmpSignal ConversionAt SFunction Inport2'
     */
    /* MATLAB Function 'Gyro vector to [pitch rate, elevation rate, travle rate]': '<S2>:1' */
    /* '<S2>:1:3' */
    /* '<S2>:1:4' */
    /* psi = euler_angles(3); */
    /* '<S2>:1:8' */
    /* '<S2>:1:11' */
    tmp_0[0] = 1.0;
    tmp_0[3] = sin(heli_q8_B.PitchCounttorad) * tan(heli_q8_B.Add);
    tmp_0[6] = cos(heli_q8_B.PitchCounttorad) * tan(heli_q8_B.Add);
    tmp_0[1] = 0.0;
    tmp_0[4] = cos(heli_q8_B.PitchCounttorad);
    tmp_0[7] = -sin(heli_q8_B.PitchCounttorad);
    tmp_0[2] = 0.0;
    tmp_0[5] = sin(heli_q8_B.PitchCounttorad) / cos(heli_q8_B.Add);
    tmp_0[8] = cos(heli_q8_B.PitchCounttorad) / cos(heli_q8_B.Add);

    /* Gain: '<S4>/Gain1' incorporates:
     *  MATLAB Function: '<Root>/Gyro vector to [pitch rate, elevation rate, travle rate]'
     */
    for (i = 0; i < 3; i++) {
      tmp_1[i] = heli_q8_P.Gain1_Gain[i + 6] * heli_q8_B.Switch[5] +
        (heli_q8_P.Gain1_Gain[i + 3] * heli_q8_B.Switch[4] +
         heli_q8_P.Gain1_Gain[i] * heli_q8_B.Switch[3]);
    }

    /* End of Gain: '<S4>/Gain1' */

    /* MATLAB Function: '<Root>/Gyro vector to [pitch rate, elevation rate, travle rate]' */
    for (i = 0; i < 3; i++) {
      euler_rates[i] = tmp_0[i + 6] * tmp_1[2] + (tmp_0[i + 3] * tmp_1[1] +
        tmp_0[i] * tmp_1[0]);
    }

    /* If: '<Root>/If1' incorporates:
     *  Constant: '<Root>/Constant1'
     *  Inport: '<S5>/In1'
     *  Inport: '<S6>/In1'
     */
    if (rtmIsMajorTimeStep(heli_q8_M)) {
      rtAction = (int8_T)!rtb_StreamRead1_o3;
      heli_q8_DW.If1_ActiveSubsystem_f = rtAction;
    } else {
      rtAction = heli_q8_DW.If1_ActiveSubsystem_f;
    }

    switch (rtAction) {
     case 0:
      /* Outputs for IfAction SubSystem: '<Root>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S5>/Action Port'
       */
      rtb_Merge[0] = heli_q8_B.Merge;
      rtb_Merge[1] = euler_rates[0];
      rtb_Merge[2] = heli_q8_B.Merge1;
      rtb_Merge[3] = euler_rates[1];
      rtb_Merge[4] = euler_rates[2];
      if (rtmIsMajorTimeStep(heli_q8_M)) {
        srUpdateBC(heli_q8_DW.IfActionSubsystem1_SubsysRanBC);
      }

      /* End of Outputs for SubSystem: '<Root>/If Action Subsystem1' */
      break;

     case 1:
      /* Outputs for IfAction SubSystem: '<Root>/If Action Subsystem2' incorporates:
       *  ActionPort: '<S6>/Action Port'
       */
      for (i = 0; i < 5; i++) {
        rtb_Merge[i] = heli_q8_P.Constant1_Value_c[i];
      }

      if (rtmIsMajorTimeStep(heli_q8_M)) {
        srUpdateBC(heli_q8_DW.IfActionSubsystem2_SubsysRanBC);
      }

      /* End of Outputs for SubSystem: '<Root>/If Action Subsystem2' */
      break;
    }

    /* End of If: '<Root>/If1' */

    /* MATLAB Function: '<S8>/MATLAB Function1' incorporates:
     *  Constant: '<S8>/Constant3'
     *  Constant: '<S8>/Constant4'
     */
    /* MATLAB Function 'Kalman filter/MATLAB Function1': '<S11>:1' */
    if (rtb_ManualSwitch != 0.0) {
      /* '<S11>:1:4' */
      /* '<S11>:1:5' */
      for (i = 0; i < 6; i++) {
        for (i_0 = 0; i_0 < 5; i_0++) {
          K[i + 6 * i_0] = 0.0;
          for (i_1 = 0; i_1 < 6; i_1++) {
            K[i + 6 * i_0] += rtb_UnitDelay1[6 * i_1 + i] * heli_q8_P.Cd[5 * i_1
              + i_0];
          }
        }
      }

      for (i = 0; i < 5; i++) {
        for (i_0 = 0; i_0 < 6; i_0++) {
          K_0[i + 5 * i_0] = 0.0;
          for (i_1 = 0; i_1 < 6; i_1++) {
            K_0[i + 5 * i_0] += heli_q8_P.Cd[5 * i_1 + i] * rtb_UnitDelay1[6 *
              i_0 + i_1];
          }
        }
      }

      for (i = 0; i < 5; i++) {
        for (i_0 = 0; i_0 < 5; i_0++) {
          rtb_ManualSwitch = 0.0;
          for (i_1 = 0; i_1 < 6; i_1++) {
            rtb_ManualSwitch += K_0[5 * i_1 + i] * heli_q8_P.Cd[5 * i_1 + i_0];
          }

          tmp[i + 5 * i_0] = heli_q8_P.Rd[5 * i_0 + i] + rtb_ManualSwitch;
        }
      }

      heli_q8_mrdivide(K, tmp);

      /* '<S11>:1:6' */
      for (i = 0; i < 5; i++) {
        rtb_ManualSwitch = 0.0;
        for (i_0 = 0; i_0 < 6; i_0++) {
          rtb_ManualSwitch += heli_q8_P.Cd[5 * i_0 + i] * rtb_UnitDelay[i_0];
        }

        rtb_Merge_0[i] = rtb_Merge[i] - rtb_ManualSwitch;
      }

      /* '<S11>:1:7' */
      for (i = 0; i < 6; i++) {
        rtb_ManualSwitch = 0.0;
        for (i_0 = 0; i_0 < 5; i_0++) {
          rtb_ManualSwitch += K[6 * i_0 + i] * rtb_Merge_0[i_0];
        }

        heli_q8_B.x_estimated[i] = rtb_UnitDelay[i] + rtb_ManualSwitch;
        for (i_0 = 0; i_0 < 6; i_0++) {
          rtb_ManualSwitch = 0.0;
          for (i_1 = 0; i_1 < 5; i_1++) {
            rtb_ManualSwitch += K[6 * i_1 + i] * heli_q8_P.Cd[5 * i_0 + i_1];
          }

          I_0[i + 6 * i_0] = (real_T)I[6 * i_0 + i] - rtb_ManualSwitch;
        }
      }

      for (i = 0; i < 6; i++) {
        for (i_0 = 0; i_0 < 6; i_0++) {
          I_1[i + 6 * i_0] = 0.0;
          for (i_1 = 0; i_1 < 6; i_1++) {
            I_1[i + 6 * i_0] += I_0[6 * i_1 + i] * rtb_UnitDelay1[6 * i_0 + i_1];
          }

          rtb_ManualSwitch = 0.0;
          for (i_1 = 0; i_1 < 5; i_1++) {
            rtb_ManualSwitch += K[6 * i_1 + i_0] * heli_q8_P.Cd[5 * i + i_1];
          }

          I_2[i + 6 * i_0] = (real_T)I[6 * i + i_0] - rtb_ManualSwitch;
        }

        for (i_0 = 0; i_0 < 5; i_0++) {
          K_0[i + 6 * i_0] = 0.0;
          for (i_1 = 0; i_1 < 5; i_1++) {
            K_0[i + 6 * i_0] += K[6 * i_1 + i] * heli_q8_P.Rd[5 * i_0 + i_1];
          }
        }
      }

      for (i = 0; i < 6; i++) {
        for (i_0 = 0; i_0 < 6; i_0++) {
          I_0[i + 6 * i_0] = 0.0;
          for (i_1 = 0; i_1 < 6; i_1++) {
            I_0[i + 6 * i_0] += I_1[6 * i_1 + i] * I_2[6 * i_0 + i_1];
          }

          rtb_UnitDelay1[i + 6 * i_0] = 0.0;
          for (i_1 = 0; i_1 < 5; i_1++) {
            rtb_UnitDelay1[i + 6 * i_0] += K_0[6 * i_1 + i] * K[6 * i_1 + i_0];
          }
        }
      }

      for (i = 0; i < 6; i++) {
        for (i_0 = 0; i_0 < 6; i_0++) {
          heli_q8_B.P_estimated[i_0 + 6 * i] = I_0[6 * i + i_0] +
            rtb_UnitDelay1[6 * i + i_0];
        }
      }
    } else {
      /* '<S11>:1:9' */
      for (i = 0; i < 6; i++) {
        heli_q8_B.x_estimated[i] = rtb_UnitDelay[i];
      }

      /* '<S11>:1:10' */
      memcpy(&heli_q8_B.P_estimated[0], &rtb_UnitDelay1[0], 36U * sizeof(real_T));
    }

    /* End of MATLAB Function: '<S8>/MATLAB Function1' */
  }

  /* TransferFcn: '<S3>/Elevation: Transfer Fcn' */
  heli_q8_B.ElevationTransferFcn = 0.0;
  heli_q8_B.ElevationTransferFcn += heli_q8_P.ElevationTransferFcn_C *
    heli_q8_X.ElevationTransferFcn_CSTATE;
  heli_q8_B.ElevationTransferFcn += heli_q8_P.ElevationTransferFcn_D *
    heli_q8_B.Add;
  if (rtmIsMajorTimeStep(heli_q8_M)) {
  }

  /* TransferFcn: '<S3>/Pitch: Transfer Fcn' */
  heli_q8_B.PitchTransferFcn = 0.0;
  heli_q8_B.PitchTransferFcn += heli_q8_P.PitchTransferFcn_C *
    heli_q8_X.PitchTransferFcn_CSTATE;
  heli_q8_B.PitchTransferFcn += heli_q8_P.PitchTransferFcn_D *
    heli_q8_B.PitchCounttorad;
  if (rtmIsMajorTimeStep(heli_q8_M)) {
    /* SignalConversion: '<Root>/TmpSignal ConversionAtTo FileInport1' */
    rtb_TmpSignalConversionAtToFile[0] = heli_q8_B.x_estimated[0];
    rtb_TmpSignalConversionAtToFile[1] = heli_q8_B.Merge;
    rtb_TmpSignalConversionAtToFile[2] = heli_q8_B.PitchCounttorad;

    /* ToFile: '<Root>/To File' */
    if (rtmIsMajorTimeStep(heli_q8_M)) {
      {
        if (!(++heli_q8_DW.ToFile_IWORK.Decimation % 1) &&
            (heli_q8_DW.ToFile_IWORK.Count*4)+1 < 100000000 ) {
          FILE *fp = (FILE *) heli_q8_DW.ToFile_PWORK.FilePtr;
          if (fp != (NULL)) {
            real_T u[4];
            heli_q8_DW.ToFile_IWORK.Decimation = 0;
            u[0] = heli_q8_M->Timing.t[1];
            u[1] = rtb_TmpSignalConversionAtToFile[0];
            u[2] = rtb_TmpSignalConversionAtToFile[1];
            u[3] = rtb_TmpSignalConversionAtToFile[2];
            if (fwrite(u, sizeof(real_T), 4, fp) != 4) {
              rtmSetErrorStatus(heli_q8_M,
                                "Error writing to MAT-file KalmanPitchZero.mat");
              return;
            }

            if (((++heli_q8_DW.ToFile_IWORK.Count)*4)+1 >= 100000000) {
              (void)fprintf(stdout,
                            "*** The ToFile block will stop logging data before\n"
                            "    the simulation has ended, because it has reached\n"
                            "    the maximum number of elements (100000000)\n"
                            "    allowed in MAT-file KalmanPitchZero.mat.\n");
            }
          }
        }
      }
    }
  }

  /* TransferFcn: '<S3>/Travel: Transfer Fcn' */
  heli_q8_B.TravelTransferFcn = 0.0;
  heli_q8_B.TravelTransferFcn += heli_q8_P.TravelTransferFcn_C *
    heli_q8_X.TravelTransferFcn_CSTATE;
  heli_q8_B.TravelTransferFcn += heli_q8_P.TravelTransferFcn_D *
    heli_q8_B.TravelCounttorad;
  if (rtmIsMajorTimeStep(heli_q8_M)) {
    /* RateTransition: '<S7>/Rate Transition: x' */
    if (heli_q8_M->Timing.RateInteraction.TID1_2) {
      heli_q8_B.RateTransitionx = heli_q8_DW.RateTransitionx_Buffer0;
    }

    /* End of RateTransition: '<S7>/Rate Transition: x' */

    /* DeadZone: '<S7>/Dead Zone: x' */
    if (heli_q8_B.RateTransitionx > heli_q8_P.DeadZonex_End) {
      rtb_DeadZoney = heli_q8_B.RateTransitionx - heli_q8_P.DeadZonex_End;
    } else if (heli_q8_B.RateTransitionx >= heli_q8_P.DeadZonex_Start) {
      rtb_DeadZoney = 0.0;
    } else {
      rtb_DeadZoney = heli_q8_B.RateTransitionx - heli_q8_P.DeadZonex_Start;
    }

    /* End of DeadZone: '<S7>/Dead Zone: x' */

    /* Gain: '<S7>/Joystick_gain_x' incorporates:
     *  Gain: '<S7>/Gain: x'
     */
    heli_q8_B.Joystick_gain_x = heli_q8_P.Gainx_Gain * rtb_DeadZoney *
      heli_q8_P.Joystick_gain_x;

    /* RateTransition: '<S7>/Rate Transition: y' */
    if (heli_q8_M->Timing.RateInteraction.TID1_2) {
      heli_q8_B.RateTransitiony = heli_q8_DW.RateTransitiony_Buffer0;
    }

    /* End of RateTransition: '<S7>/Rate Transition: y' */

    /* DeadZone: '<S7>/Dead Zone: y' */
    if (heli_q8_B.RateTransitiony > heli_q8_P.DeadZoney_End) {
      rtb_DeadZoney = heli_q8_B.RateTransitiony - heli_q8_P.DeadZoney_End;
    } else if (heli_q8_B.RateTransitiony >= heli_q8_P.DeadZoney_Start) {
      rtb_DeadZoney = 0.0;
    } else {
      rtb_DeadZoney = heli_q8_B.RateTransitiony - heli_q8_P.DeadZoney_Start;
    }

    /* End of DeadZone: '<S7>/Dead Zone: y' */

    /* Gain: '<S7>/Joystick_gain_y' incorporates:
     *  Gain: '<S7>/Gain: y'
     */
    heli_q8_B.Joystick_gain_y = heli_q8_P.Gainy_Gain * rtb_DeadZoney *
      heli_q8_P.Joystick_gain_y;

    /* Gain: '<Root>/Gain1' incorporates:
     *  SignalConversion: '<Root>/TmpSignal ConversionAtGain1Inport1'
     */
    heli_q8_B.Gain1[0] = 0.0;
    heli_q8_B.Gain1[0] += heli_q8_P.F[0] * heli_q8_B.Joystick_gain_x;
    heli_q8_B.Gain1[0] += heli_q8_P.F[2] * heli_q8_B.Joystick_gain_y;
    heli_q8_B.Gain1[1] = 0.0;
    heli_q8_B.Gain1[1] += heli_q8_P.F[1] * heli_q8_B.Joystick_gain_x;
    heli_q8_B.Gain1[1] += heli_q8_P.F[3] * heli_q8_B.Joystick_gain_y;
  }

  /* SignalConversion: '<Root>/TmpSignal ConversionAtGainInport1' incorporates:
   *  Gain: '<Root>/Gain'
   *  Integrator: '<Root>/Integrator'
   *  Integrator: '<Root>/Integrator1'
   */
  tmp_2[0] = heli_q8_B.x_estimated[0];
  tmp_2[1] = heli_q8_B.x_estimated[1];
  tmp_2[2] = heli_q8_B.x_estimated[3];
  tmp_2[3] = heli_q8_X.Integrator1_CSTATE;
  tmp_2[4] = heli_q8_X.Integrator_CSTATE;

  /* Sum: '<Root>/Sum' incorporates:
   *  Gain: '<Root>/Gain'
   */
  for (i = 0; i < 2; i++) {
    rtb_ManualSwitch = 0.0;
    for (i_0 = 0; i_0 < 5; i_0++) {
      rtb_ManualSwitch += heli_q8_P.K[(i_0 << 1) + i] * tmp_2[i_0];
    }

    rtb_Sum[i] = heli_q8_B.Gain1[i] - rtb_ManualSwitch;
  }

  /* End of Sum: '<Root>/Sum' */
  if (rtmIsMajorTimeStep(heli_q8_M)) {
    /* Constant: '<Root>/Constant' */
    heli_q8_B.Constant = heli_q8_P.Vs_o;
  }

  /* Sum: '<Root>/Add' */
  heli_q8_B.Add_h = rtb_Sum[0] + heli_q8_B.Constant;
  if (rtmIsMajorTimeStep(heli_q8_M)) {
  }

  /* Gain: '<S1>/Front gain' incorporates:
   *  Sum: '<S1>/Add'
   */
  rtb_ManualSwitch = (heli_q8_B.Add_h - rtb_Sum[1]) * heli_q8_P.Frontgain_Gain;

  /* Saturate: '<S3>/Front motor: Saturation' */
  if (rtb_ManualSwitch > heli_q8_P.FrontmotorSaturation_UpperSat) {
    heli_q8_B.FrontmotorSaturation = heli_q8_P.FrontmotorSaturation_UpperSat;
  } else if (rtb_ManualSwitch < heli_q8_P.FrontmotorSaturation_LowerSat) {
    heli_q8_B.FrontmotorSaturation = heli_q8_P.FrontmotorSaturation_LowerSat;
  } else {
    heli_q8_B.FrontmotorSaturation = rtb_ManualSwitch;
  }

  /* End of Saturate: '<S3>/Front motor: Saturation' */

  /* Gain: '<S1>/Back gain' incorporates:
   *  Sum: '<S1>/Subtract'
   */
  rtb_ManualSwitch = (heli_q8_B.Add_h + rtb_Sum[1]) * heli_q8_P.Backgain_Gain;

  /* Saturate: '<S3>/Back motor: Saturation' */
  if (rtb_ManualSwitch > heli_q8_P.BackmotorSaturation_UpperSat) {
    heli_q8_B.BackmotorSaturation = heli_q8_P.BackmotorSaturation_UpperSat;
  } else if (rtb_ManualSwitch < heli_q8_P.BackmotorSaturation_LowerSat) {
    heli_q8_B.BackmotorSaturation = heli_q8_P.BackmotorSaturation_LowerSat;
  } else {
    heli_q8_B.BackmotorSaturation = rtb_ManualSwitch;
  }

  /* End of Saturate: '<S3>/Back motor: Saturation' */
  if (rtmIsMajorTimeStep(heli_q8_M)) {
    /* S-Function (hil_write_analog_block): '<S3>/HIL Write Analog' */

    /* S-Function Block: heli_q8/Heli 3D/HIL Write Analog (hil_write_analog_block) */
    {
      t_error result;
      heli_q8_DW.HILWriteAnalog_Buffer[0] = heli_q8_B.FrontmotorSaturation;
      heli_q8_DW.HILWriteAnalog_Buffer[1] = heli_q8_B.BackmotorSaturation;
      result = hil_write_analog(heli_q8_DW.HILInitialize_Card,
        heli_q8_P.HILWriteAnalog_channels, 2, &heli_q8_DW.HILWriteAnalog_Buffer
        [0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_M, _rt_error_message);
      }
    }

    /* S-Function (stop_with_error_block): '<S4>/Stop with Call Error' */

    /* S-Function Block: heli_q8/IMU/Stop with Call Error (stop_with_error_block) */
    {
      if (rtb_StreamCall1_o3 < 0) {
        msg_get_error_messageA(NULL, rtb_StreamCall1_o3, _rt_error_message,
          sizeof(_rt_error_message));
        rtmSetErrorStatus(heli_q8_M, _rt_error_message);
        return;
      }
    }

    /* S-Function (stop_with_error_block): '<S4>/Stop with Read Error' */

    /* S-Function Block: heli_q8/IMU/Stop with Read Error (stop_with_error_block) */
    {
      if (rtb_StreamRead1_o5 < 0) {
        msg_get_error_messageA(NULL, rtb_StreamRead1_o5, _rt_error_message,
          sizeof(_rt_error_message));
        rtmSetErrorStatus(heli_q8_M, _rt_error_message);
        return;
      }
    }

    /* Constant: '<S8>/Constant' */
    memcpy(&heli_q8_B.Constant_e[0], &heli_q8_P.Ad[0], 36U * sizeof(real_T));

    /* Constant: '<S8>/Constant1' */
    memcpy(&heli_q8_B.Constant1[0], &heli_q8_P.Bd[0], 12U * sizeof(real_T));

    /* Constant: '<S8>/Constant2' */
    memcpy(&heli_q8_B.Constant2[0], &heli_q8_P.Qd[0], 36U * sizeof(real_T));
  }

  /* MATLAB Function: '<S8>/MATLAB Function' */
  /* MATLAB Function 'Kalman filter/MATLAB Function': '<S10>:1' */
  /*  Update state estimate */
  /* '<S10>:1:4' */
  /*  Update estimate error covariance */
  /* '<S10>:1:6' */
  for (i = 0; i < 6; i++) {
    rtb_UnitDelay[i] = 0.0;
    tmp_3[i] = 0.0;
    tmp_3[i] += heli_q8_B.Constant1[i] * rtb_Sum[0];
    tmp_3[i] += heli_q8_B.Constant1[i + 6] * rtb_Sum[1];
    for (i_0 = 0; i_0 < 6; i_0++) {
      rtb_UnitDelay[i] += heli_q8_B.Constant_e[6 * i_0 + i] *
        heli_q8_B.x_estimated[i_0];
      I_0[i + 6 * i_0] = 0.0;
      for (i_1 = 0; i_1 < 6; i_1++) {
        I_0[i + 6 * i_0] += heli_q8_B.Constant_e[6 * i_1 + i] *
          heli_q8_B.P_estimated[6 * i_0 + i_1];
      }
    }

    heli_q8_B.x_prior[i] = rtb_UnitDelay[i] + tmp_3[i];
  }

  for (i = 0; i < 6; i++) {
    for (i_0 = 0; i_0 < 6; i_0++) {
      rtb_ManualSwitch = 0.0;
      for (i_1 = 0; i_1 < 6; i_1++) {
        rtb_ManualSwitch += I_0[6 * i_1 + i] * heli_q8_B.Constant_e[6 * i_1 +
          i_0];
      }

      heli_q8_B.P_prior[i + 6 * i_0] = heli_q8_B.Constant2[6 * i_0 + i] +
        rtb_ManualSwitch;
    }
  }

  /* End of MATLAB Function: '<S8>/MATLAB Function' */
  if (rtmIsMajorTimeStep(heli_q8_M)) {
    /* Sum: '<Root>/Sum1' */
    heli_q8_B.Sum1 = heli_q8_B.x_estimated[3] - heli_q8_B.Joystick_gain_y;

    /* Sum: '<Root>/Sum2' */
    heli_q8_B.Sum2 = heli_q8_B.x_estimated[0] - heli_q8_B.Joystick_gain_x;
  }
}

/* Model update function for TID0 */
void heli_q8_update0(void)             /* Sample time: [0.0s, 0.0s] */
{
  int32_T i;
  if (rtmIsMajorTimeStep(heli_q8_M)) {
    /* Update for UnitDelay: '<S8>/Unit Delay' */
    for (i = 0; i < 6; i++) {
      heli_q8_DW.UnitDelay_DSTATE[i] = heli_q8_B.x_prior[i];
    }

    /* End of Update for UnitDelay: '<S8>/Unit Delay' */

    /* Update for UnitDelay: '<S8>/Unit Delay1' */
    memcpy(&heli_q8_DW.UnitDelay1_DSTATE[0], &heli_q8_B.P_prior[0], 36U * sizeof
           (real_T));

    /* Update for Memory: '<S4>/Memory' */
    memcpy(&heli_q8_DW.Memory_PreviousInput[0], &heli_q8_B.Switch[0], 10U *
           sizeof(real_T));
  }

  if (rtmIsMajorTimeStep(heli_q8_M)) {
    rt_ertODEUpdateContinuousStates(&heli_q8_M->solverInfo);
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
  if (!(++heli_q8_M->Timing.clockTick0)) {
    ++heli_q8_M->Timing.clockTickH0;
  }

  heli_q8_M->Timing.t[0] = rtsiGetSolverStopTime(&heli_q8_M->solverInfo);

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick1"
   * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick1 and the high bits
   * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++heli_q8_M->Timing.clockTick1)) {
    ++heli_q8_M->Timing.clockTickH1;
  }

  heli_q8_M->Timing.t[1] = heli_q8_M->Timing.clockTick1 *
    heli_q8_M->Timing.stepSize1 + heli_q8_M->Timing.clockTickH1 *
    heli_q8_M->Timing.stepSize1 * 4294967296.0;
}

/* Derivatives for root system: '<Root>' */
void heli_q8_derivatives(void)
{
  XDot_heli_q8_T *_rtXdot;
  _rtXdot = ((XDot_heli_q8_T *) heli_q8_M->ModelData.derivs);

  /* Derivatives for TransferFcn: '<S3>/Elevation: Transfer Fcn' */
  _rtXdot->ElevationTransferFcn_CSTATE = 0.0;
  _rtXdot->ElevationTransferFcn_CSTATE += heli_q8_P.ElevationTransferFcn_A *
    heli_q8_X.ElevationTransferFcn_CSTATE;
  _rtXdot->ElevationTransferFcn_CSTATE += heli_q8_B.Add;

  /* Derivatives for TransferFcn: '<S3>/Pitch: Transfer Fcn' */
  _rtXdot->PitchTransferFcn_CSTATE = 0.0;
  _rtXdot->PitchTransferFcn_CSTATE += heli_q8_P.PitchTransferFcn_A *
    heli_q8_X.PitchTransferFcn_CSTATE;
  _rtXdot->PitchTransferFcn_CSTATE += heli_q8_B.PitchCounttorad;

  /* Derivatives for TransferFcn: '<S3>/Travel: Transfer Fcn' */
  _rtXdot->TravelTransferFcn_CSTATE = 0.0;
  _rtXdot->TravelTransferFcn_CSTATE += heli_q8_P.TravelTransferFcn_A *
    heli_q8_X.TravelTransferFcn_CSTATE;
  _rtXdot->TravelTransferFcn_CSTATE += heli_q8_B.TravelCounttorad;

  /* Derivatives for Integrator: '<Root>/Integrator1' */
  _rtXdot->Integrator1_CSTATE = heli_q8_B.Sum2;

  /* Derivatives for Integrator: '<Root>/Integrator' */
  _rtXdot->Integrator_CSTATE = heli_q8_B.Sum1;
}

/* Model output function for TID2 */
void heli_q8_output2(void)             /* Sample time: [0.01s, 0.0s] */
{
  /* S-Function (game_controller_block): '<S7>/Game Controller' */

  /* S-Function Block: heli_q8/Joystick/Game Controller (game_controller_block) */
  {
    if (heli_q8_P.GameController_Enabled) {
      t_game_controller_states state;
      t_boolean new_data;
      t_error result;
      result = game_controller_poll(heli_q8_DW.GameController_Controller, &state,
        &new_data);
      if (result == 0) {
        heli_q8_B.GameController_o4 = state.x;
        heli_q8_B.GameController_o5 = state.y;
      }
    } else {
      heli_q8_B.GameController_o4 = 0;
      heli_q8_B.GameController_o5 = 0;
    }
  }
}

/* Model update function for TID2 */
void heli_q8_update2(void)             /* Sample time: [0.01s, 0.0s] */
{
  /* Update for RateTransition: '<S7>/Rate Transition: x' */
  heli_q8_DW.RateTransitionx_Buffer0 = heli_q8_B.GameController_o4;

  /* Update for RateTransition: '<S7>/Rate Transition: y' */
  heli_q8_DW.RateTransitiony_Buffer0 = heli_q8_B.GameController_o5;

  /* Update absolute time */
  /* The "clockTick2" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick2"
   * and "Timing.stepSize2". Size of "clockTick2" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick2 and the high bits
   * Timing.clockTickH2. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++heli_q8_M->Timing.clockTick2)) {
    ++heli_q8_M->Timing.clockTickH2;
  }

  heli_q8_M->Timing.t[2] = heli_q8_M->Timing.clockTick2 *
    heli_q8_M->Timing.stepSize2 + heli_q8_M->Timing.clockTickH2 *
    heli_q8_M->Timing.stepSize2 * 4294967296.0;
}

/* Model output wrapper function for compatibility with a static main program */
void heli_q8_output(int_T tid)
{
  switch (tid) {
   case 0 :
    heli_q8_output0();
    break;

   case 2 :
    heli_q8_output2();
    break;

   default :
    break;
  }
}

/* Model update wrapper function for compatibility with a static main program */
void heli_q8_update(int_T tid)
{
  switch (tid) {
   case 0 :
    heli_q8_update0();
    break;

   case 2 :
    heli_q8_update2();
    break;

   default :
    break;
  }
}

/* Model initialize function */
void heli_q8_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: heli_q8/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("q8_usb", "0", &heli_q8_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(heli_q8_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options(heli_q8_DW.HILInitialize_Card,
      "update_rate=normal;decimation=1", 32);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(heli_q8_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(heli_q8_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(heli_q8_M, _rt_error_message);
      return;
    }

    if ((heli_q8_P.HILInitialize_set_analog_input_ && !is_switching) ||
        (heli_q8_P.HILInitialize_set_analog_inpu_m && is_switching)) {
      {
        int_T i1;
        real_T *dw_AIMinimums = &heli_q8_DW.HILInitialize_AIMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMinimums[i1] = heli_q8_P.HILInitialize_analog_input_mini;
        }
      }

      {
        int_T i1;
        real_T *dw_AIMaximums = &heli_q8_DW.HILInitialize_AIMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMaximums[i1] = heli_q8_P.HILInitialize_analog_input_maxi;
        }
      }

      result = hil_set_analog_input_ranges(heli_q8_DW.HILInitialize_Card,
        heli_q8_P.HILInitialize_analog_input_chan, 8U,
        &heli_q8_DW.HILInitialize_AIMinimums[0],
        &heli_q8_DW.HILInitialize_AIMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_M, _rt_error_message);
        return;
      }
    }

    if ((heli_q8_P.HILInitialize_set_analog_output && !is_switching) ||
        (heli_q8_P.HILInitialize_set_analog_outp_b && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOMinimums = &heli_q8_DW.HILInitialize_AOMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMinimums[i1] = heli_q8_P.HILInitialize_analog_output_min;
        }
      }

      {
        int_T i1;
        real_T *dw_AOMaximums = &heli_q8_DW.HILInitialize_AOMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMaximums[i1] = heli_q8_P.HILInitialize_analog_output_max;
        }
      }

      result = hil_set_analog_output_ranges(heli_q8_DW.HILInitialize_Card,
        heli_q8_P.HILInitialize_analog_output_cha, 8U,
        &heli_q8_DW.HILInitialize_AOMinimums[0],
        &heli_q8_DW.HILInitialize_AOMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_M, _rt_error_message);
        return;
      }
    }

    if ((heli_q8_P.HILInitialize_set_analog_outp_e && !is_switching) ||
        (heli_q8_P.HILInitialize_set_analog_outp_j && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &heli_q8_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = heli_q8_P.HILInitialize_initial_analog_ou;
        }
      }

      result = hil_write_analog(heli_q8_DW.HILInitialize_Card,
        heli_q8_P.HILInitialize_analog_output_cha, 8U,
        &heli_q8_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_M, _rt_error_message);
        return;
      }
    }

    if (heli_q8_P.HILInitialize_set_analog_outp_p) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &heli_q8_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = heli_q8_P.HILInitialize_watchdog_analog_o;
        }
      }

      result = hil_watchdog_set_analog_expiration_state
        (heli_q8_DW.HILInitialize_Card,
         heli_q8_P.HILInitialize_analog_output_cha, 8U,
         &heli_q8_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_M, _rt_error_message);
        return;
      }
    }

    if ((heli_q8_P.HILInitialize_set_encoder_param && !is_switching) ||
        (heli_q8_P.HILInitialize_set_encoder_par_m && is_switching)) {
      {
        int_T i1;
        int32_T *dw_QuadratureModes = &heli_q8_DW.HILInitialize_QuadratureModes
          [0];
        for (i1=0; i1 < 8; i1++) {
          dw_QuadratureModes[i1] = heli_q8_P.HILInitialize_quadrature;
        }
      }

      result = hil_set_encoder_quadrature_mode(heli_q8_DW.HILInitialize_Card,
        heli_q8_P.HILInitialize_encoder_channels, 8U, (t_encoder_quadrature_mode
        *) &heli_q8_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_M, _rt_error_message);
        return;
      }
    }

    if ((heli_q8_P.HILInitialize_set_encoder_count && !is_switching) ||
        (heli_q8_P.HILInitialize_set_encoder_cou_k && is_switching)) {
      {
        int_T i1;
        int32_T *dw_InitialEICounts = &heli_q8_DW.HILInitialize_InitialEICounts
          [0];
        for (i1=0; i1 < 8; i1++) {
          dw_InitialEICounts[i1] = heli_q8_P.HILInitialize_initial_encoder_c;
        }
      }

      result = hil_set_encoder_counts(heli_q8_DW.HILInitialize_Card,
        heli_q8_P.HILInitialize_encoder_channels, 8U,
        &heli_q8_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_M, _rt_error_message);
        return;
      }
    }

    if ((heli_q8_P.HILInitialize_set_pwm_params_at && !is_switching) ||
        (heli_q8_P.HILInitialize_set_pwm_params__f && is_switching)) {
      uint32_T num_duty_cycle_modes = 0;
      uint32_T num_frequency_modes = 0;

      {
        int_T i1;
        int32_T *dw_POModeValues = &heli_q8_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] = heli_q8_P.HILInitialize_pwm_modes;
        }
      }

      result = hil_set_pwm_mode(heli_q8_DW.HILInitialize_Card,
        heli_q8_P.HILInitialize_pwm_channels, 8U, (t_pwm_mode *)
        &heli_q8_DW.HILInitialize_POModeValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        const uint32_T *p_HILInitialize_pwm_channels =
          heli_q8_P.HILInitialize_pwm_channels;
        int32_T *dw_POModeValues = &heli_q8_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          if (dw_POModeValues[i1] == PWM_DUTY_CYCLE_MODE || dw_POModeValues[i1] ==
              PWM_ONE_SHOT_MODE || dw_POModeValues[i1] == PWM_TIME_MODE) {
            heli_q8_DW.HILInitialize_POSortedChans[num_duty_cycle_modes] =
              p_HILInitialize_pwm_channels[i1];
            heli_q8_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes] =
              heli_q8_P.HILInitialize_pwm_frequency;
            num_duty_cycle_modes++;
          } else {
            heli_q8_DW.HILInitialize_POSortedChans[7U - num_frequency_modes] =
              p_HILInitialize_pwm_channels[i1];
            heli_q8_DW.HILInitialize_POSortedFreqs[7U - num_frequency_modes] =
              heli_q8_P.HILInitialize_pwm_frequency;
            num_frequency_modes++;
          }
        }
      }

      if (num_duty_cycle_modes > 0) {
        result = hil_set_pwm_frequency(heli_q8_DW.HILInitialize_Card,
          &heli_q8_DW.HILInitialize_POSortedChans[0], num_duty_cycle_modes,
          &heli_q8_DW.HILInitialize_POSortedFreqs[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(heli_q8_M, _rt_error_message);
          return;
        }
      }

      if (num_frequency_modes > 0) {
        result = hil_set_pwm_duty_cycle(heli_q8_DW.HILInitialize_Card,
          &heli_q8_DW.HILInitialize_POSortedChans[num_duty_cycle_modes],
          num_frequency_modes,
          &heli_q8_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(heli_q8_M, _rt_error_message);
          return;
        }
      }

      {
        int_T i1;
        int32_T *dw_POModeValues = &heli_q8_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] = heli_q8_P.HILInitialize_pwm_configuration;
        }
      }

      {
        int_T i1;
        int32_T *dw_POAlignValues = &heli_q8_DW.HILInitialize_POAlignValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POAlignValues[i1] = heli_q8_P.HILInitialize_pwm_alignment;
        }
      }

      {
        int_T i1;
        int32_T *dw_POPolarityVals = &heli_q8_DW.HILInitialize_POPolarityVals[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POPolarityVals[i1] = heli_q8_P.HILInitialize_pwm_polarity;
        }
      }

      result = hil_set_pwm_configuration(heli_q8_DW.HILInitialize_Card,
        heli_q8_P.HILInitialize_pwm_channels, 8U,
        (t_pwm_configuration *) &heli_q8_DW.HILInitialize_POModeValues[0],
        (t_pwm_alignment *) &heli_q8_DW.HILInitialize_POAlignValues[0],
        (t_pwm_polarity *) &heli_q8_DW.HILInitialize_POPolarityVals[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        real_T *dw_POSortedFreqs = &heli_q8_DW.HILInitialize_POSortedFreqs[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POSortedFreqs[i1] = heli_q8_P.HILInitialize_pwm_leading_deadb;
        }
      }

      {
        int_T i1;
        real_T *dw_POValues = &heli_q8_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = heli_q8_P.HILInitialize_pwm_trailing_dead;
        }
      }

      result = hil_set_pwm_deadband(heli_q8_DW.HILInitialize_Card,
        heli_q8_P.HILInitialize_pwm_channels, 8U,
        &heli_q8_DW.HILInitialize_POSortedFreqs[0],
        &heli_q8_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_M, _rt_error_message);
        return;
      }
    }

    if ((heli_q8_P.HILInitialize_set_pwm_outputs_a && !is_switching) ||
        (heli_q8_P.HILInitialize_set_pwm_outputs_g && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &heli_q8_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = heli_q8_P.HILInitialize_initial_pwm_outpu;
        }
      }

      result = hil_write_pwm(heli_q8_DW.HILInitialize_Card,
        heli_q8_P.HILInitialize_pwm_channels, 8U,
        &heli_q8_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_M, _rt_error_message);
        return;
      }
    }

    if (heli_q8_P.HILInitialize_set_pwm_outputs_o) {
      {
        int_T i1;
        real_T *dw_POValues = &heli_q8_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = heli_q8_P.HILInitialize_watchdog_pwm_outp;
        }
      }

      result = hil_watchdog_set_pwm_expiration_state
        (heli_q8_DW.HILInitialize_Card, heli_q8_P.HILInitialize_pwm_channels, 8U,
         &heli_q8_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for S-Function (hil_read_encoder_timebase_block): '<S3>/HIL Read Encoder Timebase' */

  /* S-Function Block: heli_q8/Heli 3D/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
  {
    t_error result;
    result = hil_task_create_encoder_reader(heli_q8_DW.HILInitialize_Card,
      heli_q8_P.HILReadEncoderTimebase_samples_,
      heli_q8_P.HILReadEncoderTimebase_channels, 3,
      &heli_q8_DW.HILReadEncoderTimebase_Task);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(heli_q8_M, _rt_error_message);
    }
  }

  /* Start for S-Function (stream_call_block): '<S4>/Stream Call1' */

  /* S-Function Block: heli_q8/IMU/Stream Call1 (stream_call_block) */
  {
    heli_q8_DW.StreamCall1_State = STREAM_CALL_STATE_NOT_CONNECTED;
    heli_q8_DW.StreamCall1_Stream = NULL;
  }

  /* Start for If: '<S9>/If1' */
  heli_q8_DW.If1_ActiveSubsystem = -1;

  /* Start for If: '<S9>/If' */
  heli_q8_DW.If_ActiveSubsystem = -1;

  /* Start for If: '<Root>/If1' */
  heli_q8_DW.If1_ActiveSubsystem_f = -1;

  /* Start for ToFile: '<Root>/To File' */
  {
    FILE *fp = (NULL);
    char fileName[509] = "KalmanPitchZero.mat";
    if ((fp = fopen(fileName, "wb")) == (NULL)) {
      rtmSetErrorStatus(heli_q8_M,
                        "Error creating .mat file KalmanPitchZero.mat");
      return;
    }

    if (rt_WriteMat4FileHeader(fp,4,0,"ans")) {
      rtmSetErrorStatus(heli_q8_M,
                        "Error writing mat file header to file KalmanPitchZero.mat");
      return;
    }

    heli_q8_DW.ToFile_IWORK.Count = 0;
    heli_q8_DW.ToFile_IWORK.Decimation = -1;
    heli_q8_DW.ToFile_PWORK.FilePtr = fp;
  }

  /* Start for RateTransition: '<S7>/Rate Transition: x' */
  heli_q8_B.RateTransitionx = heli_q8_P.RateTransitionx_X0;

  /* Start for RateTransition: '<S7>/Rate Transition: y' */
  heli_q8_B.RateTransitiony = heli_q8_P.RateTransitiony_X0;

  /* Start for S-Function (game_controller_block): '<S7>/Game Controller' */

  /* S-Function Block: heli_q8/Joystick/Game Controller (game_controller_block) */
  {
    if (heli_q8_P.GameController_Enabled) {
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

      result = game_controller_open(heli_q8_P.GameController_ControllerNumber,
        heli_q8_P.GameController_BufferSize, deadzone, saturation,
        heli_q8_P.GameController_AutoCenter, 0, 1.0,
        &heli_q8_DW.GameController_Controller);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_M, _rt_error_message);
      }
    }
  }

  /* Start for Constant: '<S8>/Constant' */
  memcpy(&heli_q8_B.Constant_e[0], &heli_q8_P.Ad[0], 36U * sizeof(real_T));

  /* Start for Constant: '<S8>/Constant1' */
  memcpy(&heli_q8_B.Constant1[0], &heli_q8_P.Bd[0], 12U * sizeof(real_T));

  /* Start for Constant: '<S8>/Constant2' */
  memcpy(&heli_q8_B.Constant2[0], &heli_q8_P.Qd[0], 36U * sizeof(real_T));

  {
    int32_T i;

    /* InitializeConditions for UnitDelay: '<S8>/Unit Delay' */
    for (i = 0; i < 6; i++) {
      heli_q8_DW.UnitDelay_DSTATE[i] = heli_q8_P.x0[i];
    }

    /* End of InitializeConditions for UnitDelay: '<S8>/Unit Delay' */

    /* InitializeConditions for UnitDelay: '<S8>/Unit Delay1' */
    memcpy(&heli_q8_DW.UnitDelay1_DSTATE[0], &heli_q8_P.P0[0], 36U * sizeof
           (real_T));

    /* InitializeConditions for Memory: '<S4>/Memory' */
    memcpy(&heli_q8_DW.Memory_PreviousInput[0], &heli_q8_P.Memory_X0[0], 10U *
           sizeof(real_T));

    /* InitializeConditions for TransferFcn: '<S3>/Elevation: Transfer Fcn' */
    heli_q8_X.ElevationTransferFcn_CSTATE = 0.0;

    /* InitializeConditions for TransferFcn: '<S3>/Pitch: Transfer Fcn' */
    heli_q8_X.PitchTransferFcn_CSTATE = 0.0;

    /* InitializeConditions for TransferFcn: '<S3>/Travel: Transfer Fcn' */
    heli_q8_X.TravelTransferFcn_CSTATE = 0.0;

    /* InitializeConditions for RateTransition: '<S7>/Rate Transition: x' */
    heli_q8_DW.RateTransitionx_Buffer0 = heli_q8_P.RateTransitionx_X0;

    /* InitializeConditions for RateTransition: '<S7>/Rate Transition: y' */
    heli_q8_DW.RateTransitiony_Buffer0 = heli_q8_P.RateTransitiony_X0;

    /* InitializeConditions for Integrator: '<Root>/Integrator1' */
    heli_q8_X.Integrator1_CSTATE = heli_q8_P.Integrator1_IC;

    /* InitializeConditions for Integrator: '<Root>/Integrator' */
    heli_q8_X.Integrator_CSTATE = heli_q8_P.Integrator_IC;
  }
}

/* Model terminate function */
void heli_q8_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: heli_q8/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    t_uint32 num_final_pwm_outputs = 0;
    hil_task_stop_all(heli_q8_DW.HILInitialize_Card);
    hil_monitor_stop_all(heli_q8_DW.HILInitialize_Card);
    is_switching = false;
    if ((heli_q8_P.HILInitialize_set_analog_out_ex && !is_switching) ||
        (heli_q8_P.HILInitialize_set_analog_outp_c && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &heli_q8_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = heli_q8_P.HILInitialize_final_analog_outp;
        }
      }

      num_final_analog_outputs = 8U;
    }

    if ((heli_q8_P.HILInitialize_set_pwm_output_ap && !is_switching) ||
        (heli_q8_P.HILInitialize_set_pwm_outputs_p && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &heli_q8_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = heli_q8_P.HILInitialize_final_pwm_outputs;
        }
      }

      num_final_pwm_outputs = 8U;
    }

    if (0
        || num_final_analog_outputs > 0
        || num_final_pwm_outputs > 0
        ) {
      /* Attempt to write the final outputs atomically (due to firmware issue in old Q2-USB). Otherwise write channels individually */
      result = hil_write(heli_q8_DW.HILInitialize_Card
                         , heli_q8_P.HILInitialize_analog_output_cha,
                         num_final_analog_outputs
                         , heli_q8_P.HILInitialize_pwm_channels,
                         num_final_pwm_outputs
                         , NULL, 0
                         , NULL, 0
                         , &heli_q8_DW.HILInitialize_AOVoltages[0]
                         , &heli_q8_DW.HILInitialize_POValues[0]
                         , (t_boolean *) NULL
                         , NULL
                         );
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED) {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_analog_outputs > 0) {
          local_result = hil_write_analog(heli_q8_DW.HILInitialize_Card,
            heli_q8_P.HILInitialize_analog_output_cha, num_final_analog_outputs,
            &heli_q8_DW.HILInitialize_AOVoltages[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_pwm_outputs > 0) {
          local_result = hil_write_pwm(heli_q8_DW.HILInitialize_Card,
            heli_q8_P.HILInitialize_pwm_channels, num_final_pwm_outputs,
            &heli_q8_DW.HILInitialize_POValues[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(heli_q8_M, _rt_error_message);
        }
      }
    }

    hil_task_delete_all(heli_q8_DW.HILInitialize_Card);
    hil_monitor_delete_all(heli_q8_DW.HILInitialize_Card);
    hil_close(heli_q8_DW.HILInitialize_Card);
    heli_q8_DW.HILInitialize_Card = NULL;
  }

  /* Terminate for S-Function (stream_call_block): '<S4>/Stream Call1' */

  /* S-Function Block: heli_q8/IMU/Stream Call1 (stream_call_block) */
  {
    if (heli_q8_DW.StreamCall1_Stream != NULL) {
      stream_close(heli_q8_DW.StreamCall1_Stream);
      heli_q8_DW.StreamCall1_Stream = NULL;
    }
  }

  /* Terminate for ToFile: '<Root>/To File' */
  {
    FILE *fp = (FILE *) heli_q8_DW.ToFile_PWORK.FilePtr;
    if (fp != (NULL)) {
      char fileName[509] = "KalmanPitchZero.mat";
      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(heli_q8_M,
                          "Error closing MAT-file KalmanPitchZero.mat");
        return;
      }

      if ((fp = fopen(fileName, "r+b")) == (NULL)) {
        rtmSetErrorStatus(heli_q8_M,
                          "Error reopening MAT-file KalmanPitchZero.mat");
        return;
      }

      if (rt_WriteMat4FileHeader(fp, 4, heli_q8_DW.ToFile_IWORK.Count, "ans")) {
        rtmSetErrorStatus(heli_q8_M,
                          "Error writing header for ans to MAT-file KalmanPitchZero.mat");
      }

      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(heli_q8_M,
                          "Error closing MAT-file KalmanPitchZero.mat");
        return;
      }

      heli_q8_DW.ToFile_PWORK.FilePtr = (NULL);
    }
  }

  /* Terminate for S-Function (game_controller_block): '<S7>/Game Controller' */

  /* S-Function Block: heli_q8/Joystick/Game Controller (game_controller_block) */
  {
    if (heli_q8_P.GameController_Enabled) {
      game_controller_close(heli_q8_DW.GameController_Controller);
      heli_q8_DW.GameController_Controller = NULL;
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
  heli_q8_output(tid);
}

void MdlUpdate(int_T tid)
{
  if (tid == 1)
    tid = 0;
  heli_q8_update(tid);
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
  heli_q8_initialize();
}

void MdlTerminate(void)
{
  heli_q8_terminate();
}

/* Registration function */
RT_MODEL_heli_q8_T *heli_q8(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)heli_q8_M, 0,
                sizeof(RT_MODEL_heli_q8_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&heli_q8_M->solverInfo, &heli_q8_M->Timing.simTimeStep);
    rtsiSetTPtr(&heli_q8_M->solverInfo, &rtmGetTPtr(heli_q8_M));
    rtsiSetStepSizePtr(&heli_q8_M->solverInfo, &heli_q8_M->Timing.stepSize0);
    rtsiSetdXPtr(&heli_q8_M->solverInfo, &heli_q8_M->ModelData.derivs);
    rtsiSetContStatesPtr(&heli_q8_M->solverInfo, (real_T **)
                         &heli_q8_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&heli_q8_M->solverInfo,
      &heli_q8_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&heli_q8_M->solverInfo,
      &heli_q8_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&heli_q8_M->solverInfo,
      &heli_q8_M->ModelData.periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&heli_q8_M->solverInfo,
      &heli_q8_M->ModelData.periodicContStateRanges);
    rtsiSetErrorStatusPtr(&heli_q8_M->solverInfo, (&rtmGetErrorStatus(heli_q8_M)));
    rtsiSetRTModelPtr(&heli_q8_M->solverInfo, heli_q8_M);
  }

  rtsiSetSimTimeStep(&heli_q8_M->solverInfo, MAJOR_TIME_STEP);
  heli_q8_M->ModelData.intgData.f[0] = heli_q8_M->ModelData.odeF[0];
  heli_q8_M->ModelData.contStates = ((real_T *) &heli_q8_X);
  rtsiSetSolverData(&heli_q8_M->solverInfo, (void *)
                    &heli_q8_M->ModelData.intgData);
  rtsiSetSolverName(&heli_q8_M->solverInfo,"ode1");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = heli_q8_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    mdlTsMap[2] = 2;
    heli_q8_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    heli_q8_M->Timing.sampleTimes = (&heli_q8_M->Timing.sampleTimesArray[0]);
    heli_q8_M->Timing.offsetTimes = (&heli_q8_M->Timing.offsetTimesArray[0]);

    /* task periods */
    heli_q8_M->Timing.sampleTimes[0] = (0.0);
    heli_q8_M->Timing.sampleTimes[1] = (0.002);
    heli_q8_M->Timing.sampleTimes[2] = (0.01);

    /* task offsets */
    heli_q8_M->Timing.offsetTimes[0] = (0.0);
    heli_q8_M->Timing.offsetTimes[1] = (0.0);
    heli_q8_M->Timing.offsetTimes[2] = (0.0);
  }

  rtmSetTPtr(heli_q8_M, &heli_q8_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = heli_q8_M->Timing.sampleHitArray;
    int_T *mdlPerTaskSampleHits = heli_q8_M->Timing.perTaskSampleHitsArray;
    heli_q8_M->Timing.perTaskSampleHits = (&mdlPerTaskSampleHits[0]);
    mdlSampleHits[0] = 1;
    heli_q8_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(heli_q8_M, -1);
  heli_q8_M->Timing.stepSize0 = 0.002;
  heli_q8_M->Timing.stepSize1 = 0.002;
  heli_q8_M->Timing.stepSize2 = 0.01;

  /* External mode info */
  heli_q8_M->Sizes.checksums[0] = (3080259123U);
  heli_q8_M->Sizes.checksums[1] = (1643102659U);
  heli_q8_M->Sizes.checksums[2] = (2790163790U);
  heli_q8_M->Sizes.checksums[3] = (3812032698U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[12];
    heli_q8_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = (sysRanDType *)&heli_q8_DW.IfActionSubsystem1_SubsysRanBC;
    systemRan[5] = (sysRanDType *)&heli_q8_DW.IfActionSubsystem2_SubsysRanBC;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = &rtAlwaysEnabled;
    systemRan[8] = (sysRanDType *)
      &heli_q8_DW.IfActionSubsystem.IfActionSubsystem_SubsysRanBC;
    systemRan[9] = (sysRanDType *)
      &heli_q8_DW.IfActionSubsystem1.IfActionSubsystem1_SubsysRanBC;
    systemRan[10] = (sysRanDType *)
      &heli_q8_DW.IfActionSubsystem2.IfActionSubsystem_SubsysRanBC;
    systemRan[11] = (sysRanDType *)
      &heli_q8_DW.IfActionSubsystem3.IfActionSubsystem1_SubsysRanBC;
    rteiSetModelMappingInfoPtr(heli_q8_M->extModeInfo,
      &heli_q8_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(heli_q8_M->extModeInfo, heli_q8_M->Sizes.checksums);
    rteiSetTPtr(heli_q8_M->extModeInfo, rtmGetTPtr(heli_q8_M));
  }

  heli_q8_M->solverInfoPtr = (&heli_q8_M->solverInfo);
  heli_q8_M->Timing.stepSize = (0.002);
  rtsiSetFixedStepSize(&heli_q8_M->solverInfo, 0.002);
  rtsiSetSolverMode(&heli_q8_M->solverInfo, SOLVER_MODE_MULTITASKING);

  /* block I/O */
  heli_q8_M->ModelData.blockIO = ((void *) &heli_q8_B);
  (void) memset(((void *) &heli_q8_B), 0,
                sizeof(B_heli_q8_T));

  {
    int32_T i;
    for (i = 0; i < 10; i++) {
      heli_q8_B.Switch[i] = 0.0;
    }

    for (i = 0; i < 36; i++) {
      heli_q8_B.Constant_e[i] = 0.0;
    }

    for (i = 0; i < 12; i++) {
      heli_q8_B.Constant1[i] = 0.0;
    }

    for (i = 0; i < 36; i++) {
      heli_q8_B.Constant2[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      heli_q8_B.x_estimated[i] = 0.0;
    }

    for (i = 0; i < 36; i++) {
      heli_q8_B.P_estimated[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      heli_q8_B.x_prior[i] = 0.0;
    }

    for (i = 0; i < 36; i++) {
      heli_q8_B.P_prior[i] = 0.0;
    }

    heli_q8_B.Add = 0.0;
    heli_q8_B.PitchCounttorad = 0.0;
    heli_q8_B.TravelCounttorad = 0.0;
    heli_q8_B.Merge = 0.0;
    heli_q8_B.Merge1 = 0.0;
    heli_q8_B.ElevationTransferFcn = 0.0;
    heli_q8_B.PitchTransferFcn = 0.0;
    heli_q8_B.TravelTransferFcn = 0.0;
    heli_q8_B.RateTransitionx = 0.0;
    heli_q8_B.Joystick_gain_x = 0.0;
    heli_q8_B.RateTransitiony = 0.0;
    heli_q8_B.Joystick_gain_y = 0.0;
    heli_q8_B.Gain1[0] = 0.0;
    heli_q8_B.Gain1[1] = 0.0;
    heli_q8_B.Constant = 0.0;
    heli_q8_B.Add_h = 0.0;
    heli_q8_B.FrontmotorSaturation = 0.0;
    heli_q8_B.BackmotorSaturation = 0.0;
    heli_q8_B.GameController_o4 = 0.0;
    heli_q8_B.GameController_o5 = 0.0;
    heli_q8_B.Sum1 = 0.0;
    heli_q8_B.Sum2 = 0.0;
    heli_q8_B.IfActionSubsystem2.In1 = 0.0;
    heli_q8_B.IfActionSubsystem.In1 = 0.0;
  }

  /* parameters */
  heli_q8_M->ModelData.defaultParam = ((real_T *)&heli_q8_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &heli_q8_X;
    heli_q8_M->ModelData.contStates = (x);
    (void) memset((void *)&heli_q8_X, 0,
                  sizeof(X_heli_q8_T));
  }

  /* states (dwork) */
  heli_q8_M->ModelData.dwork = ((void *) &heli_q8_DW);
  (void) memset((void *)&heli_q8_DW, 0,
                sizeof(DW_heli_q8_T));

  {
    int32_T i;
    for (i = 0; i < 6; i++) {
      heli_q8_DW.UnitDelay_DSTATE[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 36; i++) {
      heli_q8_DW.UnitDelay1_DSTATE[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_q8_DW.HILInitialize_AIMinimums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_q8_DW.HILInitialize_AIMaximums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_q8_DW.HILInitialize_AOMinimums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_q8_DW.HILInitialize_AOMaximums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_q8_DW.HILInitialize_AOVoltages[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_q8_DW.HILInitialize_FilterFrequency[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_q8_DW.HILInitialize_POSortedFreqs[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_q8_DW.HILInitialize_POValues[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 10; i++) {
      heli_q8_DW.Memory_PreviousInput[i] = 0.0;
    }
  }

  heli_q8_DW.RateTransitionx_Buffer0 = 0.0;
  heli_q8_DW.RateTransitiony_Buffer0 = 0.0;
  heli_q8_DW.HILWriteAnalog_Buffer[0] = 0.0;
  heli_q8_DW.HILWriteAnalog_Buffer[1] = 0.0;

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    heli_q8_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 25;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Initialize Sizes */
  heli_q8_M->Sizes.numContStates = (5);/* Number of continuous states */
  heli_q8_M->Sizes.numPeriodicContStates = (0);/* Number of periodic continuous states */
  heli_q8_M->Sizes.numY = (0);         /* Number of model outputs */
  heli_q8_M->Sizes.numU = (0);         /* Number of model inputs */
  heli_q8_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  heli_q8_M->Sizes.numSampTimes = (3); /* Number of sample times */
  heli_q8_M->Sizes.numBlocks = (113);  /* Number of blocks */
  heli_q8_M->Sizes.numBlockIO = (33);  /* Number of block outputs */
  heli_q8_M->Sizes.numBlockPrms = (634);/* Sum of parameter "widths" */
  return heli_q8_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
