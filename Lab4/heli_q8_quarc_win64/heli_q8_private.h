/*
 * heli_q8_private.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "heli_q8".
 *
 * Model version              : 1.98
 * Simulink Coder version : 8.9 (R2015b) 13-Aug-2015
 * C source code generated on : Sat Nov 14 14:56:19 2020
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_heli_q8_private_h_
#define RTW_HEADER_heli_q8_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"

extern t_stream heli_q8_rtZt_stream;

/* A global buffer for storing error messages (defined in quanser_common library) */
EXTERN char _rt_error_message[512];
extern void heli_q8_IfActionSubsystem1(real_T rtu_In1, real_T *rty_Out1);
extern void heli_q8_IfActionSubsystem(real_T rtu_In1,
  B_IfActionSubsystem_heli_q8_T *localB);
void heli_q8_output0(void);
void heli_q8_update0(void);
void heli_q8_output2(void);
void heli_q8_update2(void);            /* private model entry point functions */
extern void heli_q8_derivatives(void);

#endif                                 /* RTW_HEADER_heli_q8_private_h_ */
