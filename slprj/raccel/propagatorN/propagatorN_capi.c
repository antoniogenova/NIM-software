#include "__cf_propagatorN.h"
#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "propagatorN_capi_host.h"
#define sizeof(s) ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el) ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s) (s)    
#else
#include "builtin_typeid_types.h"
#include "propagatorN.h"
#include "propagatorN_capi.h"
#include "propagatorN_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST                  
#define TARGET_STRING(s)               (NULL)                    
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif
static const rtwCAPI_Signals rtBlockSignals [ ] = { { 0 , 0 , TARGET_STRING (
"propagatorN/Environment /Clock" ) , TARGET_STRING ( "time" ) , 0 , 0 , 0 , 0
, 0 } , { 1 , 0 , TARGET_STRING ( "propagatorN/Environment /Integrator" ) ,
TARGET_STRING ( "u" ) , 0 , 0 , 0 , 0 , 0 } , { 2 , 0 , TARGET_STRING (
"propagatorN/Environment /Integrator1" ) , TARGET_STRING ( "v" ) , 0 , 0 , 0
, 0 , 0 } , { 3 , 0 , TARGET_STRING ( "propagatorN/Environment /Integrator2"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 4 , 0 , TARGET_STRING (
"propagatorN/Environment /Integrator3" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 ,
0 , 0 } , { 5 , 0 , TARGET_STRING ( "propagatorN/Environment /Integrator4" )
, TARGET_STRING ( "w" ) , 0 , 0 , 0 , 0 , 0 } , { 6 , 0 , TARGET_STRING (
"propagatorN/Environment /Integrator5" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 ,
0 , 0 } , { 7 , 0 , TARGET_STRING ( "propagatorN/Init /Initial State Vector"
) , TARGET_STRING ( "X0" ) , 0 , 0 , 1 , 0 , 1 } , { 8 , 0 , TARGET_STRING (
"propagatorN/Lidar Measurement/Rate Transition" ) , TARGET_STRING ( "time" )
, 0 , 0 , 0 , 0 , 2 } , { 9 , 0 , TARGET_STRING (
"propagatorN/Lidar Measurement/Rate Transition" ) , TARGET_STRING ( "X" ) , 0
, 0 , 1 , 0 , 2 } , { 10 , 0 , TARGET_STRING (
"propagatorN/Environment /Subsystem/Product" ) , TARGET_STRING ( "aN_x" ) , 0
, 0 , 0 , 0 , 0 } , { 11 , 0 , TARGET_STRING (
"propagatorN/Environment /Subsystem/Product1" ) , TARGET_STRING ( "aN_y" ) ,
0 , 0 , 0 , 0 , 0 } , { 12 , 0 , TARGET_STRING (
"propagatorN/Environment /Subsystem/Product2" ) , TARGET_STRING ( "aN_z" ) ,
0 , 0 , 0 , 0 , 0 } , { 13 , 0 , TARGET_STRING (
"propagatorN/Environment /Subsystem/Unary Minus" ) , TARGET_STRING ( "-mi" )
, 0 , 0 , 0 , 0 , 1 } , { 0 , 0 , ( NULL ) , ( NULL ) , 0 , 0 , 0 , 0 , 0 } }
; static const rtwCAPI_BlockParameters rtBlockParameters [ ] = { { 14 ,
TARGET_STRING ( "propagatorN/Environment /Subsystem/Constant" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 0 , ( NULL ) , ( NULL ) , 0 , 0 ,
0 } } ; static const rtwCAPI_ModelParameters rtModelParameters [ ] = { { 15 ,
TARGET_STRING ( "X0" ) , 0 , 1 , 0 } , { 16 , TARGET_STRING ( "mi" ) , 0 , 0
, 0 } , { 0 , ( NULL ) , 0 , 0 , 0 } } ;
#ifndef HOST_CAPI_BUILD
static void * rtDataAddrMap [ ] = { & rtB . fvdrarjklh , & rtB . hlyoede2ou ,
& rtB . heynuzo0o5 , & rtB . jqdmu0onem , & rtB . oqoepvxuhl , & rtB .
ego0coqkjl , & rtB . gecdibna14 , & rtB . gojcuhgrmx [ 0 ] , & rtB .
c3rqc1rio3 , & rtB . fsbqipywni [ 0 ] , & rtB . ip1ehjsak5 , & rtB .
abfmtekobg , & rtB . f5dz3p0zap , & rtB . bwaqcq2ocz , & rtP . Constant_Value
, & rtP . X0 [ 0 ] , & rtP . mi , } ; static int32_T * rtVarDimsAddrMap [ ] =
{ ( NULL ) } ;
#endif
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap [ ] = { { "double" ,
"real_T" , 0 , 0 , sizeof ( real_T ) , SS_DOUBLE , 0 , 0 , 0 } } ;
#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif
static TARGET_CONST rtwCAPI_ElementMap rtElementMap [ ] = { { ( NULL ) , 0 ,
0 , 0 , 0 } , } ; static const rtwCAPI_DimensionMap rtDimensionMap [ ] = { {
rtwCAPI_SCALAR , 0 , 2 , 0 } , { rtwCAPI_VECTOR , 2 , 2 , 0 } } ; static
const uint_T rtDimensionArray [ ] = { 1 , 1 , 6 , 1 } ; static const real_T
rtcapiStoredFloats [ ] = { 0.0 , 0.1 } ; static const rtwCAPI_FixPtMap
rtFixPtMap [ ] = { { ( NULL ) , ( NULL ) , rtwCAPI_FIX_RESERVED , 0 , 0 , 0 }
, } ; static const rtwCAPI_SampleTimeMap rtSampleTimeMap [ ] = { { ( const
void * ) & rtcapiStoredFloats [ 0 ] , ( const void * ) & rtcapiStoredFloats [
0 ] , 0 , 0 } , { ( NULL ) , ( NULL ) , 3 , 0 } , { ( const void * ) &
rtcapiStoredFloats [ 1 ] , ( const void * ) & rtcapiStoredFloats [ 0 ] , 2 ,
0 } } ; static rtwCAPI_ModelMappingStaticInfo mmiStatic = { { rtBlockSignals
, 14 , ( NULL ) , 0 , ( NULL ) , 0 } , { rtBlockParameters , 1 ,
rtModelParameters , 2 } , { ( NULL ) , 0 } , { rtDataTypeMap , rtDimensionMap
, rtFixPtMap , rtElementMap , rtSampleTimeMap , rtDimensionArray } , "float"
, { 473134070U , 3374777374U , 1377649563U , 3095674371U } , ( NULL ) , 0 , 0
} ; const rtwCAPI_ModelMappingStaticInfo * propagatorN_GetCAPIStaticMap (
void ) { return & mmiStatic ; }
#ifndef HOST_CAPI_BUILD
void propagatorN_InitializeDataMapInfo ( void ) { rtwCAPI_SetVersion ( ( *
rt_dataMapInfoPtr ) . mmi , 1 ) ; rtwCAPI_SetStaticMap ( ( *
rt_dataMapInfoPtr ) . mmi , & mmiStatic ) ; rtwCAPI_SetLoggingStaticMap ( ( *
rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ; rtwCAPI_SetDataAddressMap ( ( *
rt_dataMapInfoPtr ) . mmi , rtDataAddrMap ) ; rtwCAPI_SetVarDimsAddressMap (
( * rt_dataMapInfoPtr ) . mmi , rtVarDimsAddrMap ) ;
rtwCAPI_SetInstanceLoggingInfo ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArray ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( ( * rt_dataMapInfoPtr ) . mmi , 0 ) ; }
#else
#ifdef __cplusplus
extern "C" {
#endif
void propagatorN_host_InitializeDataMapInfo ( propagatorN_host_DataMapInfo_T
* dataMap , const char * path ) { rtwCAPI_SetVersion ( dataMap -> mmi , 1 ) ;
rtwCAPI_SetStaticMap ( dataMap -> mmi , & mmiStatic ) ;
rtwCAPI_SetDataAddressMap ( dataMap -> mmi , NULL ) ;
rtwCAPI_SetVarDimsAddressMap ( dataMap -> mmi , NULL ) ; rtwCAPI_SetPath (
dataMap -> mmi , path ) ; rtwCAPI_SetFullPath ( dataMap -> mmi , NULL ) ;
rtwCAPI_SetChildMMIArray ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( dataMap -> mmi , 0 ) ; }
#ifdef __cplusplus
}
#endif
#endif
