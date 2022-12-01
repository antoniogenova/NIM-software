#include "__cf_propagatorN.h"
#ifndef RTW_HEADER_propagatorN_h_
#define RTW_HEADER_propagatorN_h_
#include <stddef.h>
#include <string.h>
#include "rtw_modelmap.h"
#ifndef propagatorN_COMMON_INCLUDES_
#define propagatorN_COMMON_INCLUDES_
#include <stdlib.h>
#include "rtwtypes.h"
#include "simtarget/slSimTgtSigstreamRTW.h"
#include "simtarget/slSimTgtSlioCoreRTW.h"
#include "simtarget/slSimTgtSlioClientsRTW.h"
#include "simtarget/slSimTgtSlioSdiRTW.h"
#include "sigstream_rtw.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "raccel.h"
#include "slsv_diagnostic_codegen_c_api.h"
#include "rt_logging.h"
#include "dt_info.h"
#include "ext_work.h"
#endif
#include "propagatorN_types.h"
#include "multiword_types.h"
#include "mwmathutil.h"
#include "rt_defines.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#define MODEL_NAME propagatorN
#define NSAMPLE_TIMES (4) 
#define NINPUTS (0)       
#define NOUTPUTS (0)     
#define NBLOCKIO (14) 
#define NUM_ZC_EVENTS (0) 
#ifndef NCSTATES
#define NCSTATES (6)   
#elif NCSTATES != 6
#error Invalid specification of NCSTATES defined in compiler command
#endif
#ifndef rtmGetDataMapInfo
#define rtmGetDataMapInfo(rtm) (*rt_dataMapInfoPtr)
#endif
#ifndef rtmSetDataMapInfo
#define rtmSetDataMapInfo(rtm, val) (rt_dataMapInfoPtr = &val)
#endif
#ifndef IN_RACCEL_MAIN
#endif
typedef struct { real_T fvdrarjklh ; real_T c3rqc1rio3 ; real_T jqdmu0onem ;
real_T oqoepvxuhl ; real_T gecdibna14 ; real_T hlyoede2ou ; real_T heynuzo0o5
; real_T ego0coqkjl ; real_T fsbqipywni [ 6 ] ; real_T ip1ehjsak5 ; real_T
abfmtekobg ; real_T f5dz3p0zap ; real_T bwaqcq2ocz ; real_T gojcuhgrmx [ 6 ]
; } B ; typedef struct { real_T cu1zwqps1l ; real_T pxmoytqe33 [ 6 ] ; int_T
lme5rvswfq ; int_T fdhd0srwf4 ; int_T gy2ooyn5oy ; int_T ljzqqcgkl3 ; int_T
dauvg5ipgx ; int_T f0nkfvx4kv ; int8_T lf425rrkcg ; } DW ; typedef struct {
real_T fspxkrhtiu ; real_T meygbb43lf ; real_T enuggszhiy ; real_T ii0mta5lea
; real_T ctiwnkz2yn ; real_T ogl1svj2ne ; } X ; typedef struct { real_T
fspxkrhtiu ; real_T meygbb43lf ; real_T enuggszhiy ; real_T ii0mta5lea ;
real_T ctiwnkz2yn ; real_T ogl1svj2ne ; } XDot ; typedef struct { boolean_T
fspxkrhtiu ; boolean_T meygbb43lf ; boolean_T enuggszhiy ; boolean_T
ii0mta5lea ; boolean_T ctiwnkz2yn ; boolean_T ogl1svj2ne ; } XDis ; typedef
struct { real_T fspxkrhtiu ; real_T meygbb43lf ; real_T enuggszhiy ; real_T
ii0mta5lea ; real_T ctiwnkz2yn ; real_T ogl1svj2ne ; } CStateAbsTol ; typedef
struct { rtwCAPI_ModelMappingInfo mmi ; } DataMapInfo ; struct P_ { real_T X0
[ 6 ] ; real_T mi ; real_T Constant_Value ; } ; extern const char *
RT_MEMORY_ALLOCATION_ERROR ; extern B rtB ; extern X rtX ; extern DW rtDW ;
extern P rtP ; extern const rtwCAPI_ModelMappingStaticInfo *
propagatorN_GetCAPIStaticMap ( void ) ; extern SimStruct * const rtS ; extern
const int_T gblNumToFiles ; extern const int_T gblNumFrFiles ; extern const
int_T gblNumFrWksBlocks ; extern rtInportTUtable * gblInportTUtables ; extern
const char * gblInportFileName ; extern const int_T gblNumRootInportBlks ;
extern const int_T gblNumModelInputs ; extern const int_T
gblInportDataTypeIdx [ ] ; extern const int_T gblInportDims [ ] ; extern
const int_T gblInportComplex [ ] ; extern const int_T gblInportInterpoFlag [
] ; extern const int_T gblInportContinuous [ ] ; extern const int_T
gblParameterTuningTid ; extern DataMapInfo * rt_dataMapInfoPtr ; extern
rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr ; void MdlOutputs ( int_T tid )
; void MdlOutputsParameterSampleTime ( int_T tid ) ; void MdlUpdate ( int_T
tid ) ; void MdlTerminate ( void ) ; void MdlInitializeSizes ( void ) ; void
MdlInitializeSampleTimes ( void ) ; SimStruct * raccel_register_model ( void
) ;
#endif
