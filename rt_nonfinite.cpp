/*
 * rt_nonfinite.cpp
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

#include "rt_nonfinite.h"

}

#include "limits"
#include "cmath"

extern "C"
{
  real_T rtNaN { -std::numeric_limits<real_T>::quiet_NaN() };

  real_T rtInf { std::numeric_limits<real_T>::infinity() };

  real_T rtMinusInf { -std::numeric_limits<real_T>::infinity() };

  real32_T rtNaNF { -std::numeric_limits<real32_T>::quiet_NaN() };

  real32_T rtInfF { std::numeric_limits<real32_T>::infinity() };

  real32_T rtMinusInfF { -std::numeric_limits<real32_T>::infinity() };
}

extern "C"
{
  /* Test if value is infinite */
  boolean_T rtIsInf(real_T value)
  {
    return std::isinf(value);
  }

  /* Test if single-precision value is infinite */
  boolean_T rtIsInfF(real32_T value)
  {
    return std::isinf(value);
  }

  /* Test if value is not a number */
  boolean_T rtIsNaN(real_T value)
  {
    return std::isnan(value);
  }

  /* Test if single-precision value is not a number */
  boolean_T rtIsNaNF(real32_T value)
  {
    return std::isnan(value);
  }
}
