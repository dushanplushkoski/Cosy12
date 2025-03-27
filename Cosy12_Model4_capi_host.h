#ifndef Cosy12_Model4_cap_host_h__
#define Cosy12_Model4_cap_host_h__
#ifdef HOST_CAPI_BUILD
#include "rtw_capi.h"
#include "rtw_modelmap.h"

struct Cosy12_Model4_host_DataMapInfo_T {
  rtwCAPI_ModelMappingInfo mmi;
};

#ifdef __cplusplus

extern "C"
{

#endif

  void Cosy12_Model4_host_InitializeDataMapInfo(Cosy12_Model4_host_DataMapInfo_T
    *dataMap, const char *path);

#ifdef __cplusplus

}

#endif
#endif                                 /* HOST_CAPI_BUILD */
#endif                                 /* Cosy12_Model4_cap_host_h__ */

/* EOF: Cosy12_Model4_capi_host.h */
