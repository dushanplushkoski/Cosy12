/*
 * Cosy12_Model4_private.h
 *
 * Code generation for model "Cosy12_Model4".
 *
 * Model version              : 13.182
 * Simulink Coder version : 24.2 (R2024b) 21-Jun-2024
 * C++ source code generated on : Thu Mar 20 15:45:57 2025
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef Cosy12_Model4_private_h_
#define Cosy12_Model4_private_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#include "Cosy12_Model4.h"
#include "Cosy12_Model4_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmSetTFinal
#define rtmSetTFinal(rtm, val)         ((rtm)->Timing.tFinal = (val))
#endif

extern void Cos_CompressorSuctionMassgsRPM5(real_T rtu_temp,
  B_CompressorSuctionMassgsRPM5_T *localB);

#endif                                 /* Cosy12_Model4_private_h_ */
