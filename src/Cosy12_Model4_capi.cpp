/*
 * Cosy12_Model4_capi.cpp
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

#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "Cosy12_Model4_capi_host.h"
#define sizeof(...)                    ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el)              ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s)               (s)
#else                                  /* HOST_CAPI_BUILD */
#include "builtin_typeid_types.h"
#include "Cosy12_Model4.h"
#include "Cosy12_Model4_capi.h"
#include "Cosy12_Model4_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST
#define TARGET_STRING(s)               ((nullptr))
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif                                 /* HOST_CAPI_BUILD */

/* Root Inputs information */
static const rtwCAPI_Signals rtRootInputs[]{
  /* addrMapIndex, sysNum, blockPath,
   * signalName, portNumber, dataTypeIndex, dimIndex, fxpIndex, sTimeIndex
   */
  { 0, 0, TARGET_STRING("Cosy12_Model4/Inport1"),
    TARGET_STRING(""), 1, 0, 0, 0, 0 },

  { 1, 0, TARGET_STRING("Cosy12_Model4/Inport2"),
    TARGET_STRING(""), 2, 0, 0, 0, 0 },

  { 2, 0, TARGET_STRING("Cosy12_Model4/Inport3"),
    TARGET_STRING(""), 3, 0, 0, 0, 0 },

  { 3, 0, TARGET_STRING("Cosy12_Model4/Inport4"),
    TARGET_STRING(""), 4, 0, 0, 0, 0 },

  { 4, 0, TARGET_STRING("Cosy12_Model4/Inport5"),
    TARGET_STRING(""), 5, 0, 0, 0, 0 },

  { 5, 0, TARGET_STRING("Cosy12_Model4/Inport6"),
    TARGET_STRING(""), 6, 0, 0, 0, 0 },

  {
    0, 0, (nullptr), (nullptr), 0, 0, 0, 0, 0
  }
};

/* Root Outputs information */
static const rtwCAPI_Signals rtRootOutputs[]{
  /* addrMapIndex, sysNum, blockPath,
   * signalName, portNumber, dataTypeIndex, dimIndex, fxpIndex, sTimeIndex
   */
  { 6, 0, TARGET_STRING("Cosy12_Model4/OUTPUT1"),
    TARGET_STRING(""), 1, 0, 0, 0, 0 },

  { 7, 0, TARGET_STRING("Cosy12_Model4/OUTPUT2"),
    TARGET_STRING(""), 2, 0, 0, 0, 0 },

  { 8, 0, TARGET_STRING("Cosy12_Model4/OUTPUT3"),
    TARGET_STRING(""), 3, 0, 0, 0, 0 },

  { 9, 0, TARGET_STRING("Cosy12_Model4/OUTPUT4"),
    TARGET_STRING(""), 4, 0, 0, 0, 0 },

  { 10, 0, TARGET_STRING("Cosy12_Model4/OUTPUT5"),
    TARGET_STRING(""), 5, 0, 0, 0, 0 },

  { 11, 0, TARGET_STRING("Cosy12_Model4/OUTPUT6"),
    TARGET_STRING(""), 6, 0, 0, 0, 0 },

  { 12, 0, TARGET_STRING("Cosy12_Model4/OUTPUT7"),
    TARGET_STRING(""), 7, 0, 0, 0, 0 },

  { 13, 0, TARGET_STRING("Cosy12_Model4/OUTPUT8"),
    TARGET_STRING(""), 8, 0, 0, 0, 0 },

  { 14, 0, TARGET_STRING("Cosy12_Model4/OUTPUT9"),
    TARGET_STRING(""), 9, 0, 0, 0, 0 },

  { 15, 0, TARGET_STRING("Cosy12_Model4/OUTPUT10"),
    TARGET_STRING(""), 10, 0, 0, 0, 0 },

  { 16, 0, TARGET_STRING("Cosy12_Model4/OUTPUT11"),
    TARGET_STRING(""), 11, 0, 0, 0, 0 },

  { 17, 0, TARGET_STRING("Cosy12_Model4/OUTPUT12"),
    TARGET_STRING(""), 12, 0, 0, 0, 0 },

  { 18, 0, TARGET_STRING("Cosy12_Model4/OUTPUT13"),
    TARGET_STRING(""), 13, 0, 0, 0, 0 },

  { 19, 0, TARGET_STRING("Cosy12_Model4/OUTPUT14"),
    TARGET_STRING(""), 14, 0, 0, 0, 0 },

  { 20, 0, TARGET_STRING("Cosy12_Model4/OUTPUT15"),
    TARGET_STRING(""), 15, 0, 0, 0, 0 },

  {
    0, 0, (nullptr), (nullptr), 0, 0, 0, 0, 0
  }
};

#ifndef HOST_CAPI_BUILD

/* Declare Data Addresses statically */
static void* rtDataAddrMap[]{
  &Cosy12_Model4_U.Inport1,            /* 0: Root Input */
  &Cosy12_Model4_U.Inport2,            /* 1: Root Input */
  &Cosy12_Model4_U.Inport3,            /* 2: Root Input */
  &Cosy12_Model4_U.Inport4,            /* 3: Root Input */
  &Cosy12_Model4_U.Inport5,            /* 4: Root Input */
  &Cosy12_Model4_U.Inport6,            /* 5: Root Input */
  &Cosy12_Model4_Y.OUTPUT1,            /* 6: Root Output */
  &Cosy12_Model4_Y.OUTPUT2,            /* 7: Root Output */
  &Cosy12_Model4_Y.OUTPUT3,            /* 8: Root Output */
  &Cosy12_Model4_Y.OUTPUT4,            /* 9: Root Output */
  &Cosy12_Model4_Y.OUTPUT5,            /* 10: Root Output */
  &Cosy12_Model4_Y.OUTPUT6,            /* 11: Root Output */
  &Cosy12_Model4_Y.OUTPUT7,            /* 12: Root Output */
  &Cosy12_Model4_Y.OUTPUT8,            /* 13: Root Output */
  &Cosy12_Model4_Y.OUTPUT9,            /* 14: Root Output */
  &Cosy12_Model4_Y.OUTPUT10,           /* 15: Root Output */
  &Cosy12_Model4_Y.OUTPUT11,           /* 16: Root Output */
  &Cosy12_Model4_Y.OUTPUT12,           /* 17: Root Output */
  &Cosy12_Model4_Y.OUTPUT13,           /* 18: Root Output */
  &Cosy12_Model4_Y.OUTPUT14,           /* 19: Root Output */
  &Cosy12_Model4_Y.OUTPUT15,           /* 20: Root Output */
};

/* Declare Data Run-Time Dimension Buffer Addresses statically */
static int32_T* rtVarDimsAddrMap[]{
  (nullptr)
};

#endif

/* Data Type Map - use dataTypeMapIndex to access this structure */
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap[]{
  /* cName, mwName, numElements, elemMapIndex, dataSize, slDataId, *
   * isComplex, isPointer, enumStorageType */
  { "double", "real_T", 0, 0, sizeof(real_T), (uint8_T)SS_DOUBLE, 0, 0, 0 }
};

#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif

/* Structure Element Map - use elemMapIndex to access this structure */
static TARGET_CONST rtwCAPI_ElementMap rtElementMap[]{
  /* elementName, elementOffset, dataTypeIndex, dimIndex, fxpIndex */
  { (nullptr), 0, 0, 0, 0 },
};

/* Dimension Map - use dimensionMapIndex to access elements of ths structure*/
static const rtwCAPI_DimensionMap rtDimensionMap[]{
  /* dataOrientation, dimArrayIndex, numDims, vardimsIndex */
  { rtwCAPI_SCALAR, 0, 2, 0 }
};

/* Dimension Array- use dimArrayIndex to access elements of this array */
static const uint_T rtDimensionArray[]{
  1,                                   /* 0 */
  1                                    /* 1 */
};

/* C-API stores floating point values in an array. The elements of this  *
 * are unique. This ensures that values which are shared across the model*
 * are stored in the most efficient way. These values are referenced by  *
 *           - rtwCAPI_FixPtMap.fracSlopePtr,                            *
 *           - rtwCAPI_FixPtMap.biasPtr,                                 *
 *           - rtwCAPI_SampleTimeMap.samplePeriodPtr,                    *
 *           - rtwCAPI_SampleTimeMap.sampleOffsetPtr                     */
static const real_T rtcapiStoredFloats[]{
  0.01, 0.0
};

/* Fixed Point Map */
static const rtwCAPI_FixPtMap rtFixPtMap[]{
  /* fracSlopePtr, biasPtr, scaleType, wordLength, exponent, isSigned */
  { (nullptr), (nullptr), rtwCAPI_FIX_RESERVED, 0, 0, (boolean_T)0 },
};

/* Sample Time Map - use sTimeIndex to access elements of ths structure */
static const rtwCAPI_SampleTimeMap rtSampleTimeMap[]{
  /* samplePeriodPtr, sampleOffsetPtr, tid, samplingMode */
  { static_cast<const void *>(&rtcapiStoredFloats[0]), static_cast<const void *>
    (&rtcapiStoredFloats[1]), static_cast<int8_T>(0), static_cast<uint8_T>(0) }
};

static rtwCAPI_ModelMappingStaticInfo mmiStatic{
  /* Signals:{signals, numSignals,
   *           rootInputs, numRootInputs,
   *           rootOutputs, numRootOutputs},
   * Params: {blockParameters, numBlockParameters,
   *          modelParameters, numModelParameters},
   * States: {states, numStates},
   * Maps:   {dataTypeMap, dimensionMap, fixPtMap,
   *          elementMap, sampleTimeMap, dimensionArray},
   * TargetType: targetType
   */
  { (nullptr), 0,
    rtRootInputs, 6,
    rtRootOutputs, 15 },

  { (nullptr), 0,
    (nullptr), 0 },

  { (nullptr), 0 },

  { rtDataTypeMap, rtDimensionMap, rtFixPtMap,
    rtElementMap, rtSampleTimeMap, rtDimensionArray },
  "float",

  { 1338082895U,
    2388014805U,
    1979587571U,
    4269279243U },
  (nullptr), 0,
  (boolean_T)0
};

/* Function to get C API Model Mapping Static Info */
const rtwCAPI_ModelMappingStaticInfo*
  Cosy12_Model4_GetCAPIStaticMap(void)
{
  return &mmiStatic;
}

/* Cache pointers into DataMapInfo substructure of RTModel */
#ifndef HOST_CAPI_BUILD

void Cosy12_Model4_InitializeDataMapInfo(void)
{
  /* Set C-API version */
  rtwCAPI_SetVersion(Cosy12_Model4_M->DataMapInfo.mmi, 1);

  /* Cache static C-API data into the Real-time Model Data structure */
  rtwCAPI_SetStaticMap(Cosy12_Model4_M->DataMapInfo.mmi, &mmiStatic);

  /* Cache static C-API logging data into the Real-time Model Data structure */
  rtwCAPI_SetLoggingStaticMap(Cosy12_Model4_M->DataMapInfo.mmi, (nullptr));

  /* Cache C-API Data Addresses into the Real-Time Model Data structure */
  rtwCAPI_SetDataAddressMap(Cosy12_Model4_M->DataMapInfo.mmi, rtDataAddrMap);

  /* Cache C-API Data Run-Time Dimension Buffer Addresses into the Real-Time Model Data structure */
  rtwCAPI_SetVarDimsAddressMap(Cosy12_Model4_M->DataMapInfo.mmi,
    rtVarDimsAddrMap);

  /* Cache the instance C-API logging pointer */
  rtwCAPI_SetInstanceLoggingInfo(Cosy12_Model4_M->DataMapInfo.mmi, (nullptr));

  /* Set reference to submodels */
  rtwCAPI_SetChildMMIArray(Cosy12_Model4_M->DataMapInfo.mmi, (nullptr));
  rtwCAPI_SetChildMMIArrayLen(Cosy12_Model4_M->DataMapInfo.mmi, 0);
}

#else                                  /* HOST_CAPI_BUILD */
#ifdef __cplusplus

extern "C"
{

#endif

  void Cosy12_Model4_host_InitializeDataMapInfo(Cosy12_Model4_host_DataMapInfo_T
    *dataMap, const char *path)
  {
    /* Set C-API version */
    rtwCAPI_SetVersion(dataMap->mmi, 1);

    /* Cache static C-API data into the Real-time Model Data structure */
    rtwCAPI_SetStaticMap(dataMap->mmi, &mmiStatic);

    /* host data address map is NULL */
    rtwCAPI_SetDataAddressMap(dataMap->mmi, (nullptr));

    /* host vardims address map is NULL */
    rtwCAPI_SetVarDimsAddressMap(dataMap->mmi, (nullptr));

    /* Set Instance specific path */
    rtwCAPI_SetPath(dataMap->mmi, path);
    rtwCAPI_SetFullPath(dataMap->mmi, (nullptr));

    /* Set reference to submodels */
    rtwCAPI_SetChildMMIArray(dataMap->mmi, (nullptr));
    rtwCAPI_SetChildMMIArrayLen(dataMap->mmi, 0);
  }

#ifdef __cplusplus

}

#endif
#endif                                 /* HOST_CAPI_BUILD */

/* EOF: Cosy12_Model4_capi.cpp */
