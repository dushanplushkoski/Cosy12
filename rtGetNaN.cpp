/*
 * rtGetNaN.cpp
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

#include "rtwtypes.h"

extern "C"
{

#include "rtGetNaN.h"

}

extern "C"
{
  /* Return rtNaN needed by the generated code. */
  real_T rtGetNaN(void)
  {
    return rtNaN;
  }

  /* Return rtNaNF needed by the generated code. */
  real32_T rtGetNaNF(void)
  {
    return rtNaNF;
  }
}
