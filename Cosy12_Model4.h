/*
 * Cosy12_Model4.h
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

#ifndef Cosy12_Model4_h_
#define Cosy12_Model4_h_
#include <cmath>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#include "rt_nonfinite.h"
#include "Cosy12_Model4_types.h"

extern "C"
{

#include "rtGetNaN.h"

}

#include "rtw_modelmap.h"
#include <cfloat>
#include <cstring>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetDataMapInfo
#define rtmGetDataMapInfo(rtm)         ((rtm)->DataMapInfo)
#endif

#ifndef rtmSetDataMapInfo
#define rtmSetDataMapInfo(rtm, val)    ((rtm)->DataMapInfo = (val))
#endif

#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWLogInfo
#define rtmGetRTWLogInfo(rtm)          ((rtm)->rtwLogInfo)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                (&(rtm)->Timing.taskTime0)
#endif

/* Block signals for system '<Root>/Compressor Suction Mass(g//s) //RPM5' */
struct B_CompressorSuctionMassgsRPM5_T {
  real_T pressure;           /* '<Root>/Compressor Suction Mass(g//s) //RPM5' */
};

/* Block signals (default storage) */
struct B_Cosy12_Model4_T {
  B_CompressorSuctionMassgsRPM5_T sf_CompressorSuctionMassgsRPM6;
                             /* '<Root>/Compressor Suction Mass(g//s) //RPM6' */
  B_CompressorSuctionMassgsRPM5_T sf_CompressorSuctionMassgsRPM5;
                             /* '<Root>/Compressor Suction Mass(g//s) //RPM5' */
};

/* Invariant block signals (default storage) */
struct ConstB_Cosy12_Model4_T {
  real_T MultiportSwitch2;             /* '<S4>/Multiport Switch2' */
  real_T MultiportSwitch;              /* '<S12>/Multiport Switch' */
  real_T MultiportSwitch2_f;           /* '<S12>/Multiport Switch2' */
  uint8_T Compare;                     /* '<S14>/Compare' */
};

/* External inputs (root inport signals with default storage) */
struct ExtU_Cosy12_Model4_T {
  real_T Inport1;                      /* '<Root>/Inport1' */
  real_T Inport2;                      /* '<Root>/Inport2' */
  real_T Inport3;                      /* '<Root>/Inport3' */
  real_T Inport4;                      /* '<Root>/Inport4' */
  real_T Inport5;                      /* '<Root>/Inport5' */
  real_T Inport6;                      /* '<Root>/Inport6' */
};

/* External outputs (root outports fed by signals with default storage) */
struct ExtY_Cosy12_Model4_T {
  real_T OUTPUT1;                      /* '<Root>/OUTPUT1' */
  real_T OUTPUT2;                      /* '<Root>/OUTPUT2' */
  real_T OUTPUT3;                      /* '<Root>/OUTPUT3' */
  real_T OUTPUT4;                      /* '<Root>/OUTPUT4' */
  real_T OUTPUT5;                      /* '<Root>/OUTPUT5' */
  real_T OUTPUT6;                      /* '<Root>/OUTPUT6' */
  real_T OUTPUT7;                      /* '<Root>/OUTPUT7' */
  real_T OUTPUT8;                      /* '<Root>/OUTPUT8' */
  real_T OUTPUT9;                      /* '<Root>/OUTPUT9' */
  real_T OUTPUT10;                     /* '<Root>/OUTPUT10' */
  real_T OUTPUT11;                     /* '<Root>/OUTPUT11' */
  real_T OUTPUT12;                     /* '<Root>/OUTPUT12' */
  real_T OUTPUT13;                     /* '<Root>/OUTPUT13' */
  real_T OUTPUT14;                     /* '<Root>/OUTPUT14' */
  real_T OUTPUT15;                     /* '<Root>/OUTPUT15' */
};

/* Real-time Model Data Structure */
struct tag_RTM_Cosy12_Model4_T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;

  /*
   * DataMapInfo:
   * The following substructure contains information regarding
   * structures generated in the model's C API.
   */
  struct {
    rtwCAPI_ModelMappingInfo mmi;
  } DataMapInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block signals (default storage) */
#ifdef __cplusplus

extern "C"
{

#endif

  extern struct B_Cosy12_Model4_T Cosy12_Model4_B;

#ifdef __cplusplus

}

#endif

#ifdef __cplusplus

extern "C"
{

#endif

  /* External inputs (root inport signals with default storage) */
  extern struct ExtU_Cosy12_Model4_T Cosy12_Model4_U;

  /* External outputs (root outports fed by signals with default storage) */
  extern struct ExtY_Cosy12_Model4_T Cosy12_Model4_Y;

#ifdef __cplusplus

}

#endif

extern const ConstB_Cosy12_Model4_T Cosy12_Model4_ConstB;/* constant block i/o */

#ifdef __cplusplus

extern "C"
{

#endif

  /* Model entry point functions */
  extern void Cosy12_Model4_initialize(void);
  extern void Cosy12_Model4_step(void);
  extern void Cosy12_Model4_terminate(void);

#ifdef __cplusplus

}

#endif

/* Function to get C API Model Mapping Static Info */
extern const rtwCAPI_ModelMappingStaticInfo*
  Cosy12_Model4_GetCAPIStaticMap(void);

/* Real-time Model object */
#ifdef __cplusplus

extern "C"
{

#endif

  extern RT_MODEL_Cosy12_Model4_T *const Cosy12_Model4_M;

#ifdef __cplusplus

}

#endif

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S6>/Constant2' : Unused code path elimination
 * Block '<S6>/Heating Capacity kW' : Unused code path elimination
 * Block '<S6>/Product' : Unused code path elimination
 * Block '<S6>/Watts1' : Unused code path elimination
 * Block '<S6>/deltaH' : Unused code path elimination
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Cosy12_Model4'
 * '<S1>'   : 'Cosy12_Model4/Compressor Suction Mass(g//s) //RPM'
 * '<S2>'   : 'Cosy12_Model4/Compressor Suction Mass(g//s) //RPM5'
 * '<S3>'   : 'Cosy12_Model4/Compressor Suction Mass(g//s) //RPM6'
 * '<S4>'   : 'Cosy12_Model4/Divide3'
 * '<S5>'   : 'Cosy12_Model4/Flow to power Function'
 * '<S6>'   : 'Cosy12_Model4/Heating Capacity'
 * '<S7>'   : 'Cosy12_Model4/Mass_Flow_Air_Function'
 * '<S8>'   : 'Cosy12_Model4/Mass_Flow_Air_Function1'
 * '<S9>'   : 'Cosy12_Model4/Mass_Flow_Air_Function2'
 * '<S10>'  : 'Cosy12_Model4/Pump Flow to power Function'
 * '<S11>'  : 'Cosy12_Model4/Divide3/Compare To Zero'
 * '<S12>'  : 'Cosy12_Model4/Heating Capacity/Divide2'
 * '<S13>'  : 'Cosy12_Model4/Heating Capacity/Subsystem'
 * '<S14>'  : 'Cosy12_Model4/Heating Capacity/Divide2/Compare To Zero'
 */
#endif                                 /* Cosy12_Model4_h_ */
