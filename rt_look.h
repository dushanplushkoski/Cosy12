/*
 * rt_look.h
 *
 * Code generation for model "Cosy12_Model4".
 *
 * Model version              : 13.149
 * Simulink Coder version : 24.2 (R2024b) 21-Jun-2024
 * C++ source code generated on : Mon Mar 17 14:37:55 2025
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef rt_look_h_
#define rt_look_h_
#include "rtwtypes.h"
#ifdef DOINTERPSEARCH
#include <float.h>
#endif

#ifdef __cplusplus

extern "C"
{

#endif

#ifndef INTERP
#define INTERP(x,x1,x2,y1,y2)          ( (y1)+(((y2) - (y1))/((x2) - (x1)))*((x)-(x1)) )
#endif

#ifndef ZEROTECHNIQUE
#define ZEROTECHNIQUE

  enum class ZeroTechnique : int_T {
    NORMAL_INTERP,
    AVERAGE_VALUE,
    MIDDLE_VALUE
  };

#endif

  extern int_T rt_GetLookupIndex(const real_T *x, int_T xlen, real_T u) ;

#ifdef __cplusplus

}                                      /* extern "C" */

#endif
#endif                                 /* rt_look_h_ */
