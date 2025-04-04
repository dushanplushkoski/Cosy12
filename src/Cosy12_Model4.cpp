/*
 * Cosy12_Model4.cpp
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

 #include "Cosy12_Model4.h"
 #include "rtwtypes.h"
 #include "Cosy12_Model4_private.h"
 #include <cmath>
 #include <cstring>
 #include "Cosy12_Model4_capi.h"
 #include "cmath"
 #include <iostream>
 
  
 /* Block signals (default storage) */
B_Cosy12_Model4_T Cosy12_Model4_B;

/* External inputs (root inport signals with default storage) */
ExtU_Cosy12_Model4_T Cosy12_Model4_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_Cosy12_Model4_T Cosy12_Model4_Y;

/* Real-time model */
RT_MODEL_Cosy12_Model4_T Cosy12_Model4_M_{ };

RT_MODEL_Cosy12_Model4_T *const Cosy12_Model4_M{ &Cosy12_Model4_M_ };

/*
 * Output and update for atomic system:
 *    '<Root>/Compressor Suction Mass(g//s) //RPM5'
 *    '<Root>/Compressor Suction Mass(g//s) //RPM6'
 */
void Cos_CompressorSuctionMassgsRPM5(real_T rtu_temp,
  B_CompressorSuctionMassgsRPM5_T *localB)
{
  static const real_T b[101]{ 2.445, 2.534, 2.626, 2.72, 2.817, 2.916, 3.018,
    3.123, 3.23, 3.34, 3.453, 3.568, 3.687, 3.809, 3.933, 4.06, 4.191, 4.325,
    4.461, 4.601, 4.745, 4.891, 5.041, 5.194, 5.351, 5.511, 5.675, 5.842, 6.013,
    6.188, 6.366, 6.548, 6.734, 6.924, 7.118, 7.315, 7.517, 7.723, 7.932, 8.146,
    8.365, 8.587, 8.814, 9.045, 9.281, 9.521, 9.765, 10.01, 10.27, 10.53, 10.79,
    11.06, 11.33, 11.61, 11.89, 12.18, 12.47, 12.77, 13.07, 13.38, 13.69, 14.01,
    14.34, 14.67, 15.0, 15.34, 15.69, 16.04, 16.4, 16.76, 17.13, 17.51, 17.89,
    18.28, 18.67, 19.07, 19.48, 19.89, 20.31, 20.74, 21.17, 21.61, 22.05, 22.5,
    22.96, 23.43, 23.9, 24.38, 24.87, 25.37, 25.87, 26.38, 26.9, 27.42, 27.95,
    28.49, 29.04, 29.6, 30.16, 30.74, 31.32 };

  if (std::isnan(rtu_temp)) {
    localB->pressure = (rtNaN);
  } else if (rtu_temp > 80.0) {
    localB->pressure = (rtu_temp - 80.0) * 0.58000000000000185 + 31.32;
  } else if (rtu_temp < -20.0) {
    localB->pressure = (rtu_temp - -20.0) * 0.088999999999999968 + 2.445;
  } else {
    real_T r;
    int32_T high_i;
    int32_T low_i;
    int32_T low_ip1;
    high_i = 101;
    low_i = 1;
    low_ip1 = 2;
    while (high_i > low_ip1) {
      int32_T mid_i;
      mid_i = (low_i + high_i) >> 1;
      if (rtu_temp >= (static_cast<real_T>(mid_i) - 1.0) - 20.0) {
        low_i = mid_i;
        low_ip1 = mid_i + 1;
      } else {
        high_i = mid_i;
      }
    }

    r = (rtu_temp - ((static_cast<real_T>(low_i) - 1.0) - 20.0)) / ((
      static_cast<real_T>(low_i) - 20.0) - ((static_cast<real_T>(low_i) - 1.0) -
      20.0));
    if (r == 0.0) {
      localB->pressure = b[low_i - 1];
    } else if (r == 1.0) {
      localB->pressure = b[low_i];
    } else {
      localB->pressure = b[low_i - 1];
      if (!(localB->pressure == b[low_i])) {
        localB->pressure = (1.0 - r) * localB->pressure + r * b[low_i];
      }
    }
  }
}

/* Model step function */
void Cosy12_Model4_step(void)
{
  real_T C10;
  real_T C11;
  real_T C12;
  real_T C13;
  real_T C14;
  real_T C15;
  real_T C16;
  real_T C17;
  real_T C18;
  real_T C19;
  real_T C4;
  real_T C5;
  real_T C6;
  real_T rtb_MultiportSwitch1_f;
  int32_T high_i;
  int32_T low_i;
  int32_T low_ip1;
  int32_T mid_i;
  int16_T tmp_0;
  int8_T tmp;
  static const real_T b[6]{ 1.666, 1.707, 1.749, 1.791, 1.834, 1.878 };

  static const real_T b_0[9]{ 5.0, 5.0, 5.0, 5.0, 6.3, 8.0, 9.7, 10.0, 10.0 };

  static const int8_T b_1[4]{ 0, 25, 50, 105 };

  static const real_T c[5]{ 2.536, 3.2, 4.18, 4.887, 5.67 };

  static const int16_T b_2[5]{ 4400, 4000, 3200, 3000, 2000 };

  static const int16_T c_0[4]{ 0, 2000, 3000, 4400 };

  static const int16_T b_3[4]{ 0, 100, 220, 420 };

  real_T C8_tmp;
  real_T C9_tmp;

  /* Sum: '<Root>/Subtract1' incorporates:
   *  Inport: '<Root>/Inport1'
   *  Inport: '<Root>/Inport4'
   *  Inport: '<Root>/Inport6'
   */
  Cosy12_Model4_Y.OUTPUT10 = (Cosy12_Model4_U.Inport1 - Cosy12_Model4_U.Inport4)
    - Cosy12_Model4_U.Inport6;

  /* MATLAB Function: '<Root>/Compressor Suction Mass(g//s) //RPM' incorporates:
   *  Inport: '<Root>/Inport2'
   *  Inport: '<Root>/Inport3'
   */
  C4 = Cosy12_Model4_Y.OUTPUT10 * Cosy12_Model4_U.Inport2;
  C5 = Cosy12_Model4_Y.OUTPUT10 * Cosy12_Model4_U.Inport3;
  C6 = Cosy12_Model4_U.Inport2 * Cosy12_Model4_U.Inport3;
  rtb_MultiportSwitch1_f = Cosy12_Model4_Y.OUTPUT10 * Cosy12_Model4_Y.OUTPUT10;
  C8_tmp = Cosy12_Model4_U.Inport2 * Cosy12_Model4_U.Inport2;
  C9_tmp = Cosy12_Model4_U.Inport3 * Cosy12_Model4_U.Inport3;
  C10 = C4 * Cosy12_Model4_U.Inport3;
  C11 = rtb_MultiportSwitch1_f * Cosy12_Model4_U.Inport2;
  C12 = rtb_MultiportSwitch1_f * Cosy12_Model4_U.Inport3;
  C13 = rtb_MultiportSwitch1_f * Cosy12_Model4_Y.OUTPUT10;
  C14 = C4 * Cosy12_Model4_U.Inport2;
  C15 = C8_tmp * Cosy12_Model4_U.Inport3;
  C16 = C8_tmp * Cosy12_Model4_U.Inport2;
  C17 = C5 * Cosy12_Model4_U.Inport3;
  C18 = C6 * Cosy12_Model4_U.Inport3;
  C19 = C9_tmp * Cosy12_Model4_U.Inport3;
  Cosy12_Model4_Y.OUTPUT4 = ((((((((((((((((((Cosy12_Model4_Y.OUTPUT10 * 0.0 +
    8.55) + Cosy12_Model4_U.Inport2 * 0.0) + Cosy12_Model4_U.Inport3 * 0.197) +
    C4 * 0.0689) + C5 * -0.00779) + C6 * 0.00656) + rtb_MultiportSwitch1_f *
    -0.0843) + C8_tmp * 0.0) + C9_tmp * 0.0) + C10 * 0.000112) + C11 * 0.0) +
    C12 * -3.88E-5) + C13 * 0.0) + C14 * 0.0) + C15 * 2.5E-5) + C16 * 0.00118) +
    C17 * 9.57E-7) + C18 * 0.0) + C19 * 3.58E-9;
  Cosy12_Model4_Y.OUTPUT9 = ((((((((((((((((((Cosy12_Model4_Y.OUTPUT10 * -0.083
    - 0.432) + Cosy12_Model4_U.Inport2 * -0.0138) + Cosy12_Model4_U.Inport3 *
    0.00764) + C4 * 0.00163) + C5 * 0.00024) + C6 * 8.69E-6) +
    rtb_MultiportSwitch1_f * 0.0) + C8_tmp * 0.0) + C9_tmp * -4.53E-8) + C10 *
    0.0) + C11 * 8.4E-6) + C12 * 2.53E-6) + C13 * 4.9E-5) + C14 * -1.52E-5) +
    C15 * -9.78E-8) + C16 * 0.0) + C17 * 0.0) + C18 * 0.0) + C19 * 0.0;
  Cosy12_Model4_Y.OUTPUT15 = ((((((((((((((((((Cosy12_Model4_Y.OUTPUT10 * -39.6
    - 334.0) + Cosy12_Model4_U.Inport2 * 0.0) + Cosy12_Model4_U.Inport3 * 2.9) +
    C4 * 1.3) + C5 * 0.103) + C6 * -0.0114) + rtb_MultiportSwitch1_f * 1.31) +
    C8_tmp * 0.0) + C9_tmp * 0.0) + C10 * -0.000641) + C11 * -0.0227) + C12 *
    0.000887) + C13 * 0.0208) + C14 * -0.0153) + C15 * -0.000113) + C16 * 0.0) +
    C17 * 0.0) + C18 * -3.15E-7) + C19 * 0.0;

  /* MATLAB Function: '<Root>/Mass_Flow_Air_Function1' incorporates:
   *  Inport: '<Root>/Inport2'
   *  MATLAB Function: '<Root>/Mass_Flow_Air_Function2'
   */
  if (std::isnan(Cosy12_Model4_U.Inport2)) {
    C4 = (rtNaN);
    Cosy12_Model4_Y.OUTPUT14 = (rtNaN);
  } else if (Cosy12_Model4_U.Inport2 > 70.0) {
    C4 = (Cosy12_Model4_U.Inport2 - 70.0) / 10.0 * 0.043999999999999817 + 1.878;
    Cosy12_Model4_Y.OUTPUT14 = (Cosy12_Model4_U.Inport2 - 70.0) / 5.0 * 0.0 +
      10.0;
  } else {
    if (Cosy12_Model4_U.Inport2 < 20.0) {
      C4 = (Cosy12_Model4_U.Inport2 - 20.0) / 10.0 * 0.041000000000000147 +
        1.666;
    } else {
      high_i = 6;
      low_i = 0;
      low_ip1 = 2;
      while (high_i > low_ip1) {
        mid_i = ((low_i + high_i) + 1) >> 1;
        if (Cosy12_Model4_U.Inport2 >= (static_cast<real_T>(mid_i) - 1.0) * 10.0
            + 20.0) {
          low_i = mid_i - 1;
          low_ip1 = mid_i + 1;
        } else {
          high_i = mid_i;
        }
      }

      C4 = 10.0 * static_cast<real_T>(low_i) + 20.0;
      C6 = (Cosy12_Model4_U.Inport2 - C4) / (((static_cast<real_T>(low_i) + 1.0)
        * 10.0 + 20.0) - C4);
      if (C6 == 0.0) {
        C4 = b[low_i];
      } else if (C6 == 1.0) {
        C4 = b[low_i + 1];
      } else {
        C4 = b[low_i + 1];
        if (C4 == b[low_i]) {
          C4 = b[low_i];
        } else {
          C4 = (1.0 - C6) * b[low_i] + C4 * C6;
        }
      }
    }

    if (Cosy12_Model4_U.Inport2 < 30.0) {
      Cosy12_Model4_Y.OUTPUT14 = (Cosy12_Model4_U.Inport2 - 30.0) / 5.0 * 0.0 +
        5.0;
    } else {
      high_i = 9;
      low_i = 1;
      low_ip1 = 2;
      while (high_i > low_ip1) {
        mid_i = (low_i + high_i) >> 1;
        if (Cosy12_Model4_U.Inport2 >= (static_cast<real_T>(mid_i) - 1.0) * 5.0
            + 30.0) {
          low_i = mid_i;
          low_ip1 = mid_i + 1;
        } else {
          high_i = mid_i;
        }
      }

      C6 = (Cosy12_Model4_U.Inport2 - ((static_cast<real_T>(low_i) - 1.0) * 5.0
             + 30.0)) / static_cast<real_T>(5 * low_i - (low_i - 1) * 5);
      if (C6 == 0.0) {
        Cosy12_Model4_Y.OUTPUT14 = b_0[low_i - 1];
      } else if (C6 == 1.0) {
        Cosy12_Model4_Y.OUTPUT14 = b_0[low_i];
      } else {
        Cosy12_Model4_Y.OUTPUT14 = b_0[low_i - 1];
        if (!(Cosy12_Model4_Y.OUTPUT14 == b_0[low_i])) {
          Cosy12_Model4_Y.OUTPUT14 = (1.0 - C6) * Cosy12_Model4_Y.OUTPUT14 + C6 *
            b_0[low_i];
        }
      }
    }
  }

  /* End of MATLAB Function: '<Root>/Mass_Flow_Air_Function1' */

  /* Sum: '<Root>/Sum1' incorporates:
   *  Gain: '<Root>/Gain'
   *  Inport: '<Root>/Inport5'
   *  MATLAB Function: '<Root>/Compressor Suction Mass(g//s) //RPM'
   *  Product: '<Root>/Product'
   */
  C4 = (Cosy12_Model4_Y.OUTPUT15 + Cosy12_Model4_Y.OUTPUT4) / 1000.0 * 1000.0 +
    C4 * Cosy12_Model4_U.Inport5 * Cosy12_Model4_Y.OUTPUT9;

  /* Product: '<S13>/Divide1' incorporates:
   *  Constant: '<S13>/CP Water'
   *  Constant: '<S13>/kg to m3'
   *  Constant: '<S13>/s to hours'
   *  Product: '<S13>/Divide'
   *  Product: '<S13>/Product'
   *  Product: '<S13>/Product1'
   */
  C5 = C4 / (4180.0 * Cosy12_Model4_Y.OUTPUT14) * 3600.0 / 1000.0;

  /* MATLAB Function: '<Root>/Pump Flow to power Function' */
  if (std::isnan(C5)) {
    Cosy12_Model4_Y.OUTPUT6 = (rtNaN);
  } else if (C5 > 3.0) {
    Cosy12_Model4_Y.OUTPUT6 = (C5 - 3.0) * 55.0 + 105.0;
  } else if (C5 < 0.0) {
    Cosy12_Model4_Y.OUTPUT6 = C5 * 25.0;
  } else {
    high_i = 4;
    low_i = 1;
    low_ip1 = 2;
    while (high_i > low_ip1) {
      mid_i = (low_i + high_i) >> 1;
      if (C5 >= static_cast<real_T>(mid_i) - 1.0) {
        low_i = mid_i;
        low_ip1 = mid_i + 1;
      } else {
        high_i = mid_i;
      }
    }

    C6 = C5 - (static_cast<real_T>(low_i) - 1.0);
    if (C6 == 0.0) {
      Cosy12_Model4_Y.OUTPUT6 = b_1[low_i - 1];
    } else if (C6 == 1.0) {
      Cosy12_Model4_Y.OUTPUT6 = b_1[low_i];
    } else {
      tmp = b_1[low_i - 1];
      if (tmp == b_1[low_i]) {
        Cosy12_Model4_Y.OUTPUT6 = tmp;
      } else {
        Cosy12_Model4_Y.OUTPUT6 = (1.0 - C6) * static_cast<real_T>(tmp) + C6 *
          static_cast<real_T>(b_1[low_i]);
      }
    }
  }

  /* End of MATLAB Function: '<Root>/Pump Flow to power Function' */

  /* MATLAB Function: '<Root>/Compressor Suction Mass(g//s) //RPM6' */
  Cos_CompressorSuctionMassgsRPM5(Cosy12_Model4_Y.OUTPUT10,
    &Cosy12_Model4_B.sf_CompressorSuctionMassgsRPM6);

  /* MATLAB Function: '<Root>/Mass_Flow_Air_Function' */
  if (std::isnan(Cosy12_Model4_B.sf_CompressorSuctionMassgsRPM6.pressure)) {
    Cosy12_Model4_Y.OUTPUT12 = (rtNaN);
  } else if (Cosy12_Model4_B.sf_CompressorSuctionMassgsRPM6.pressure > 5.67) {
    Cosy12_Model4_Y.OUTPUT12 =
      (Cosy12_Model4_B.sf_CompressorSuctionMassgsRPM6.pressure - 5.67) /
      0.78300000000000036 * -1000.0 + 2000.0;
  } else if (Cosy12_Model4_B.sf_CompressorSuctionMassgsRPM6.pressure < 2.536) {
    Cosy12_Model4_Y.OUTPUT12 =
      (Cosy12_Model4_B.sf_CompressorSuctionMassgsRPM6.pressure - 2.536) /
      0.66400000000000015 * -400.0 + 4400.0;
  } else {
    high_i = 5;
    low_i = 0;
    low_ip1 = 2;
    while (high_i > low_ip1) {
      mid_i = ((low_i + high_i) + 1) >> 1;
      if (Cosy12_Model4_B.sf_CompressorSuctionMassgsRPM6.pressure >= c[mid_i - 1])
      {
        low_i = mid_i - 1;
        low_ip1 = mid_i + 1;
      } else {
        high_i = mid_i;
      }
    }

    C6 = (Cosy12_Model4_B.sf_CompressorSuctionMassgsRPM6.pressure - c[low_i]) /
      (c[low_i + 1] - c[low_i]);
    if (C6 == 0.0) {
      Cosy12_Model4_Y.OUTPUT12 = b_2[low_i];
    } else if (C6 == 1.0) {
      Cosy12_Model4_Y.OUTPUT12 = b_2[low_i + 1];
    } else {
      tmp_0 = b_2[low_i + 1];
      if (tmp_0 == b_2[low_i]) {
        Cosy12_Model4_Y.OUTPUT12 = b_2[low_i];
      } else {
        Cosy12_Model4_Y.OUTPUT12 = (1.0 - C6) * static_cast<real_T>(b_2[low_i])
          + static_cast<real_T>(tmp_0) * C6;
      }
    }
  }

  /* End of MATLAB Function: '<Root>/Mass_Flow_Air_Function' */

  /* MATLAB Function: '<Root>/Flow to power Function' */
  if (std::isnan(Cosy12_Model4_Y.OUTPUT12)) {
    Cosy12_Model4_Y.OUTPUT5 = (rtNaN);
  } else if (Cosy12_Model4_Y.OUTPUT12 > 4400.0) {
    Cosy12_Model4_Y.OUTPUT5 = (Cosy12_Model4_Y.OUTPUT12 - 4400.0) / 1400.0 *
      200.0 + 420.0;
  } else if (Cosy12_Model4_Y.OUTPUT12 < 0.0) {
    Cosy12_Model4_Y.OUTPUT5 = Cosy12_Model4_Y.OUTPUT12 / 2000.0 * 100.0;
  } else {
    high_i = 4;
    low_i = 0;
    low_ip1 = 2;
    while (high_i > low_ip1) {
      mid_i = ((low_i + high_i) + 1) >> 1;
      if (Cosy12_Model4_Y.OUTPUT12 >= c_0[mid_i - 1]) {
        low_i = mid_i - 1;
        low_ip1 = mid_i + 1;
      } else {
        high_i = mid_i;
      }
    }

    C6 = (Cosy12_Model4_Y.OUTPUT12 - static_cast<real_T>(c_0[low_i])) /
      static_cast<real_T>(c_0[low_i + 1] - c_0[low_i]);
    if (C6 == 0.0) {
      Cosy12_Model4_Y.OUTPUT5 = b_3[low_i];
    } else if (C6 == 1.0) {
      Cosy12_Model4_Y.OUTPUT5 = b_3[low_i + 1];
    } else {
      tmp_0 = b_3[low_i + 1];
      if (tmp_0 == b_3[low_i]) {
        Cosy12_Model4_Y.OUTPUT5 = b_3[low_i];
      } else {
        Cosy12_Model4_Y.OUTPUT5 = (1.0 - C6) * static_cast<real_T>(b_3[low_i]) +
          static_cast<real_T>(tmp_0) * C6;
      }
    }
  }

  /* End of MATLAB Function: '<Root>/Flow to power Function' */

  /* Sum: '<Root>/Add2' incorporates:
   *  MATLAB Function: '<Root>/Compressor Suction Mass(g//s) //RPM'
   *  Sum: '<Root>/Add'
   */
  C6 = (Cosy12_Model4_Y.OUTPUT6 + Cosy12_Model4_Y.OUTPUT5) +
    Cosy12_Model4_Y.OUTPUT4;

  /* MultiPortSwitch: '<S4>/Multiport Switch1' incorporates:
   *  Constant: '<S11>/Constant'
   *  RelationalOperator: '<S11>/Compare'
   *  Sum: '<Root>/Add2'
   */
  if (!(C6 == 0.0)) {
    /* MultiPortSwitch: '<S12>/Multiport Switch1' incorporates:
     *  Product: '<S12>/Divide'
     */
    if (Cosy12_Model4_ConstB.Compare == 0) {
      rtb_MultiportSwitch1_f = C4 / Cosy12_Model4_ConstB.MultiportSwitch;
    } else {
      rtb_MultiportSwitch1_f = Cosy12_Model4_ConstB.MultiportSwitch2_f;
    }

    /* End of MultiPortSwitch: '<S12>/Multiport Switch1' */

    /* Outport: '<Root>/OUTPUT1' incorporates:
     *  Gain: '<Root>/Gain1'
     *  Product: '<S4>/Divide'
     */
    Cosy12_Model4_Y.OUTPUT1 = 1000.0 * rtb_MultiportSwitch1_f / C6;
  } else {
    /* Outport: '<Root>/OUTPUT1' */
    Cosy12_Model4_Y.OUTPUT1 = Cosy12_Model4_ConstB.MultiportSwitch2;
  }

  /* End of MultiPortSwitch: '<S4>/Multiport Switch1' */

  /* Outport: '<Root>/OUTPUT3' incorporates:
   *  Gain: '<Root>/Gain6'
   */
  Cosy12_Model4_Y.OUTPUT3 = C6 * 0.001;

  /* Outport: '<Root>/OUTPUT7' incorporates:
   *  Constant: '<Root>/Constant'
   *  Sum: '<Root>/Subtract4'
   */
  Cosy12_Model4_Y.OUTPUT7 =
    Cosy12_Model4_B.sf_CompressorSuctionMassgsRPM6.pressure - 1.0;

  /* Outport: '<Root>/OUTPUT13' incorporates:
   *  Gain: '<Root>/Gain7'
   */
  Cosy12_Model4_Y.OUTPUT13 = 16.6667 * C5;

  /* Outport: '<Root>/OUTPUT2' incorporates:
   *  Gain: '<Root>/Gain3'
   */
  Cosy12_Model4_Y.OUTPUT2 = 0.000945 * C4;

  /* Outport: '<Root>/OUTPUT11' incorporates:
   *  Constant: '<Root>/Constant8'
   *  Inport: '<Root>/Inport2'
   *  Inport: '<Root>/Inport5'
   *  Sum: '<Root>/Subtract'
   *  Sum: '<Root>/Subtract3'
   */
  Cosy12_Model4_Y.OUTPUT11 = ((Cosy12_Model4_U.Inport2 - Cosy12_Model4_U.Inport5)
    - 5.0) - Cosy12_Model4_Y.OUTPUT10;

  /* MATLAB Function: '<Root>/Compressor Suction Mass(g//s) //RPM5' incorporates:
   *  Inport: '<Root>/Inport2'
   */
  Cos_CompressorSuctionMassgsRPM5(Cosy12_Model4_U.Inport2,
    &Cosy12_Model4_B.sf_CompressorSuctionMassgsRPM5);

  /* Outport: '<Root>/OUTPUT8' incorporates:
   *  Constant: '<Root>/Constant9'
   *  Sum: '<Root>/Subtract5'
   */
  Cosy12_Model4_Y.OUTPUT8 =
    Cosy12_Model4_B.sf_CompressorSuctionMassgsRPM5.pressure - 1.0;

  /* Matfile logging */
  rt_UpdateTXYLogVars(Cosy12_Model4_M->rtwLogInfo,
                      (&Cosy12_Model4_M->Timing.taskTime0));

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.01s, 0.0s] */
    if ((rtmGetTFinal(Cosy12_Model4_M)!=-1) &&
        !((rtmGetTFinal(Cosy12_Model4_M)-Cosy12_Model4_M->Timing.taskTime0) >
          Cosy12_Model4_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(Cosy12_Model4_M, "Simulation finished");
    }
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
  if (!(++Cosy12_Model4_M->Timing.clockTick0)) {
    ++Cosy12_Model4_M->Timing.clockTickH0;
  }

  Cosy12_Model4_M->Timing.taskTime0 = Cosy12_Model4_M->Timing.clockTick0 *
    Cosy12_Model4_M->Timing.stepSize0 + Cosy12_Model4_M->Timing.clockTickH0 *
    Cosy12_Model4_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void Cosy12_Model4_initialize(void)
{
  /* Registration code */
  rtmSetTFinal(Cosy12_Model4_M, 20000.0);
  Cosy12_Model4_M->Timing.stepSize0 = 0.01;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = (nullptr);
    Cosy12_Model4_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(Cosy12_Model4_M->rtwLogInfo, (nullptr));
    rtliSetLogXSignalPtrs(Cosy12_Model4_M->rtwLogInfo, (nullptr));
    rtliSetLogT(Cosy12_Model4_M->rtwLogInfo, "tout");
    rtliSetLogX(Cosy12_Model4_M->rtwLogInfo, "");
    rtliSetLogXFinal(Cosy12_Model4_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(Cosy12_Model4_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(Cosy12_Model4_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(Cosy12_Model4_M->rtwLogInfo, 1000);
    rtliSetLogDecimation(Cosy12_Model4_M->rtwLogInfo, 1);

    /*
     * Set pointers to the data and signal info for each output
     */
    {
      static void * rt_LoggedOutputSignalPtrs[] {
        &Cosy12_Model4_Y.OUTPUT1,
        &Cosy12_Model4_Y.OUTPUT2,
        &Cosy12_Model4_Y.OUTPUT3,
        &Cosy12_Model4_Y.OUTPUT4,
        &Cosy12_Model4_Y.OUTPUT5,
        &Cosy12_Model4_Y.OUTPUT6,
        &Cosy12_Model4_Y.OUTPUT7,
        &Cosy12_Model4_Y.OUTPUT8,
        &Cosy12_Model4_Y.OUTPUT9,
        &Cosy12_Model4_Y.OUTPUT10,
        &Cosy12_Model4_Y.OUTPUT11,
        &Cosy12_Model4_Y.OUTPUT12,
        &Cosy12_Model4_Y.OUTPUT13,
        &Cosy12_Model4_Y.OUTPUT14,
        &Cosy12_Model4_Y.OUTPUT15
      };

      rtliSetLogYSignalPtrs(Cosy12_Model4_M->rtwLogInfo, ((LogSignalPtrsType)
        rt_LoggedOutputSignalPtrs));
    }

    {
      static int_T rt_LoggedOutputWidths[] {
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1
      };

      static int_T rt_LoggedOutputNumDimensions[] {
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1
      };

      static int_T rt_LoggedOutputDimensions[] {
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1
      };

      static boolean_T rt_LoggedOutputIsVarDims[] {
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0
      };

      static void* rt_LoggedCurrentSignalDimensions[] {
        (nullptr),
        (nullptr),
        (nullptr),
        (nullptr),
        (nullptr),
        (nullptr),
        (nullptr),
        (nullptr),
        (nullptr),
        (nullptr),
        (nullptr),
        (nullptr),
        (nullptr),
        (nullptr),
        (nullptr)
      };

      static int_T rt_LoggedCurrentSignalDimensionsSize[] {
        4,
        4,
        4,
        4,
        4,
        4,
        4,
        4,
        4,
        4,
        4,
        4,
        4,
        4,
        4
      };

      static BuiltInDTypeId rt_LoggedOutputDataTypeIds[] {
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE
      };

      static int_T rt_LoggedOutputComplexSignals[] {
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0
      };

      static RTWPreprocessingFcnPtr rt_LoggingPreprocessingFcnPtrs[] {
        (nullptr),
        (nullptr),
        (nullptr),
        (nullptr),
        (nullptr),
        (nullptr),
        (nullptr),
        (nullptr),
        (nullptr),
        (nullptr),
        (nullptr),
        (nullptr),
        (nullptr),
        (nullptr),
        (nullptr)
      };

      static const char_T *rt_LoggedOutputLabels[]{
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "" };

      static const char_T *rt_LoggedOutputBlockNames[]{
        "Cosy12_Model4/OUTPUT1",
        "Cosy12_Model4/OUTPUT2",
        "Cosy12_Model4/OUTPUT3",
        "Cosy12_Model4/OUTPUT4",
        "Cosy12_Model4/OUTPUT5",
        "Cosy12_Model4/OUTPUT6",
        "Cosy12_Model4/OUTPUT7",
        "Cosy12_Model4/OUTPUT8",
        "Cosy12_Model4/OUTPUT9",
        "Cosy12_Model4/OUTPUT10",
        "Cosy12_Model4/OUTPUT11",
        "Cosy12_Model4/OUTPUT12",
        "Cosy12_Model4/OUTPUT13",
        "Cosy12_Model4/OUTPUT14",
        "Cosy12_Model4/OUTPUT15" };

      static RTWLogDataTypeConvert rt_RTWLogDataTypeConvert[] {
        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 }
      };

      static RTWLogSignalInfo rt_LoggedOutputSignalInfo[] {
        {
          15,
          rt_LoggedOutputWidths,
          rt_LoggedOutputNumDimensions,
          rt_LoggedOutputDimensions,
          rt_LoggedOutputIsVarDims,
          rt_LoggedCurrentSignalDimensions,
          rt_LoggedCurrentSignalDimensionsSize,
          rt_LoggedOutputDataTypeIds,
          rt_LoggedOutputComplexSignals,
          (nullptr),
          rt_LoggingPreprocessingFcnPtrs,

          { rt_LoggedOutputLabels },
          (nullptr),
          (nullptr),
          (nullptr),

          { rt_LoggedOutputBlockNames },

          { (nullptr) },
          (nullptr),
          rt_RTWLogDataTypeConvert
        }
      };

      rtliSetLogYSignalInfo(Cosy12_Model4_M->rtwLogInfo,
                            rt_LoggedOutputSignalInfo);

      /* set currSigDims field */
      rt_LoggedCurrentSignalDimensions[0] = &rt_LoggedOutputWidths[0];
      rt_LoggedCurrentSignalDimensions[1] = &rt_LoggedOutputWidths[1];
      rt_LoggedCurrentSignalDimensions[2] = &rt_LoggedOutputWidths[2];
      rt_LoggedCurrentSignalDimensions[3] = &rt_LoggedOutputWidths[3];
      rt_LoggedCurrentSignalDimensions[4] = &rt_LoggedOutputWidths[4];
      rt_LoggedCurrentSignalDimensions[5] = &rt_LoggedOutputWidths[5];
      rt_LoggedCurrentSignalDimensions[6] = &rt_LoggedOutputWidths[6];
      rt_LoggedCurrentSignalDimensions[7] = &rt_LoggedOutputWidths[7];
      rt_LoggedCurrentSignalDimensions[8] = &rt_LoggedOutputWidths[8];
      rt_LoggedCurrentSignalDimensions[9] = &rt_LoggedOutputWidths[9];
      rt_LoggedCurrentSignalDimensions[10] = &rt_LoggedOutputWidths[10];
      rt_LoggedCurrentSignalDimensions[11] = &rt_LoggedOutputWidths[11];
      rt_LoggedCurrentSignalDimensions[12] = &rt_LoggedOutputWidths[12];
      rt_LoggedCurrentSignalDimensions[13] = &rt_LoggedOutputWidths[13];
      rt_LoggedCurrentSignalDimensions[14] = &rt_LoggedOutputWidths[14];
    }

    rtliSetLogY(Cosy12_Model4_M->rtwLogInfo, "yout");
  }

  /* block I/O */
  (void) std::memset((static_cast<void *>(&Cosy12_Model4_B)), 0,
                     sizeof(B_Cosy12_Model4_T));

  /* external inputs */
  (void)std::memset(&Cosy12_Model4_U, 0, sizeof(ExtU_Cosy12_Model4_T));

  /* external outputs */
  (void)std::memset(&Cosy12_Model4_Y, 0, sizeof(ExtY_Cosy12_Model4_T));

  /* Initialize DataMapInfo substructure containing ModelMap for C API */
  Cosy12_Model4_InitializeDataMapInfo();

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(Cosy12_Model4_M->rtwLogInfo, 0.0,
    rtmGetTFinal(Cosy12_Model4_M), Cosy12_Model4_M->Timing.stepSize0,
    (&rtmGetErrorStatus(Cosy12_Model4_M)));
 
 #include <iostream>
 #include "Cosy12_Model4.h"  // Ensure you include the correct header
 
 // Ensure functions are properly exported
 extern "C" {
     void initializeModel() {
         std::cout << "Model initialized!" << std::endl;
         Cosy12_Model4_initialize(); // Call the model initialization function
     }
 
     void calculateOutputs(double in1, double in2, double in3, double in4, 
                           double in5, double in6, double* outputs) {
         // Debug: Print inputs
         std::cout << "Inputs: "
                   << in1 << ", " << in2 << ", " << in3 << ", " << in4 << ", "
                   << in5 << ", " << in6 << std::endl;
 
         // Assign inputs to the model
         Cosy12_Model4_U.Inport1 = in1;
         Cosy12_Model4_U.Inport2 = in2;
         Cosy12_Model4_U.Inport3 = in3;
         Cosy12_Model4_U.Inport4 = in4;
         Cosy12_Model4_U.Inport5 = in5;
         Cosy12_Model4_U.Inport6 = in6;
 
         // Debug: Print assigned inputs
         std::cout << "Assigned Inputs: "
                   << Cosy12_Model4_U.Inport1 << ", " << Cosy12_Model4_U.Inport2 << ", "
                   << Cosy12_Model4_U.Inport3 << ", " << Cosy12_Model4_U.Inport4 << ", "
                   << Cosy12_Model4_U.Inport5 << ", " << Cosy12_Model4_U.Inport6 << std::endl;
 
         // Run the model step function
         Cosy12_Model4_step();
 
         // Collect outputs
         outputs[0] = Cosy12_Model4_Y.OUTPUT1;
         outputs[1] = Cosy12_Model4_Y.OUTPUT2;
         outputs[2] = Cosy12_Model4_Y.OUTPUT3;
         outputs[3] = Cosy12_Model4_Y.OUTPUT4;
         outputs[4] = Cosy12_Model4_Y.OUTPUT5;
         outputs[5] = Cosy12_Model4_Y.OUTPUT6;
         outputs[6] = Cosy12_Model4_Y.OUTPUT7;
         outputs[7] = Cosy12_Model4_Y.OUTPUT8;
         outputs[8] = Cosy12_Model4_Y.OUTPUT9;
         outputs[9] = Cosy12_Model4_Y.OUTPUT10;
         outputs[10] = Cosy12_Model4_Y.OUTPUT11;
         outputs[11] = Cosy12_Model4_Y.OUTPUT12;
         outputs[12] = Cosy12_Model4_Y.OUTPUT13;
         outputs[13] = Cosy12_Model4_Y.OUTPUT14;
         outputs[14] = Cosy12_Model4_Y.OUTPUT15;
 
         // Debug: Print outputs
         std::cout << "Outputs: ";
         for (int i = 0; i < 15; i++) {
             std::cout << outputs[i] << " ";
         }
         std::cout << std::endl;
     }
 }
 
 
   
 
 
 /* Model terminate function */
 void Cosy12_Model4_terminate(void)
 {
 /* (no terminate code required) */
 }
