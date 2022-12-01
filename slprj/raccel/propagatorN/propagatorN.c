#include "__cf_propagatorN.h"
#include "rt_logging_mmi.h"
#include "propagatorN_capi.h"
#include <math.h>
#include "propagatorN.h"
#include "propagatorN_private.h"
#include "propagatorN_dt.h"
extern void * CreateDiagnosticAsVoidPtr_wrapper ( const char * id , int nargs
, ... ) ; RTWExtModeInfo * gblRTWExtModeInfo = NULL ; extern boolean_T
gblExtModeStartPktReceived ; void raccelForceExtModeShutdown ( ) { if ( !
gblExtModeStartPktReceived ) { boolean_T stopRequested = false ;
rtExtModeWaitForStartPkt ( gblRTWExtModeInfo , 3 , & stopRequested ) ; }
rtExtModeShutdown ( 3 ) ; }
#include "slsv_diagnostic_codegen_c_api.h"
const int_T gblNumToFiles = 0 ; const int_T gblNumFrFiles = 0 ; const int_T
gblNumFrWksBlocks = 0 ;
#ifdef RSIM_WITH_SOLVER_MULTITASKING
boolean_T gbl_raccel_isMultitasking = 1 ;
#else
boolean_T gbl_raccel_isMultitasking = 0 ;
#endif
boolean_T gbl_raccel_tid01eq = 0 ; int_T gbl_raccel_NumST = 4 ; const char_T
* gbl_raccel_Version = "10.0 (R2019b) 18-Jul-2019" ; void
raccel_setup_MMIStateLog ( SimStruct * S ) {
#ifdef UseMMIDataLogging
rt_FillStateSigInfoFromMMI ( ssGetRTWLogInfo ( S ) , & ssGetErrorStatus ( S )
) ;
#else
UNUSED_PARAMETER ( S ) ;
#endif
} static DataMapInfo rt_dataMapInfo ; DataMapInfo * rt_dataMapInfoPtr = &
rt_dataMapInfo ; rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr = & (
rt_dataMapInfo . mmi ) ; const char * gblSlvrJacPatternFileName =
"slprj//raccel//propagatorN//propagatorN_Jpattern.mat" ; const int_T
gblNumRootInportBlks = 0 ; const int_T gblNumModelInputs = 0 ; extern
rtInportTUtable * gblInportTUtables ; extern const char * gblInportFileName ;
extern void * gblAperiodicPartitionHitTimes ; const int_T
gblInportDataTypeIdx [ ] = { - 1 } ; const int_T gblInportDims [ ] = { - 1 }
; const int_T gblInportComplex [ ] = { - 1 } ; const int_T
gblInportInterpoFlag [ ] = { - 1 } ; const int_T gblInportContinuous [ ] = {
- 1 } ; int_T enableFcnCallFlag [ ] = { 1 , 1 , 1 , 1 } ; const char *
raccelLoadInputsAndAperiodicHitTimes ( const char * inportFileName , int *
matFileFormat ) { return rt_RapidReadInportsMatFile ( inportFileName ,
matFileFormat , 1 ) ; }
#include "simstruc.h"
#include "fixedpoint.h"
B rtB ; X rtX ; DW rtDW ; static SimStruct model_S ; SimStruct * const rtS =
& model_S ; void MdlInitialize ( void ) { if ( ssIsFirstInitCond ( rtS ) ) {
rtX . fspxkrhtiu = 13426.726354 ; rtX . meygbb43lf = - 20645.023752 ; } rtDW
. lme5rvswfq = 1 ; rtDW . fdhd0srwf4 = 1 ; if ( ssIsFirstInitCond ( rtS ) ) {
rtX . enuggszhiy = 10108.071628 ; rtX . ii0mta5lea = 2.638622 ; } rtDW .
gy2ooyn5oy = 1 ; rtDW . ljzqqcgkl3 = 1 ; if ( ssIsFirstInitCond ( rtS ) ) {
rtX . ctiwnkz2yn = 0.329454 ; rtX . ogl1svj2ne = - 2.805018 ; } rtDW .
dauvg5ipgx = 1 ; rtDW . f0nkfvx4kv = 1 ; } void MdlStart ( void ) { int32_T i
; { void * * slioCatalogueAddr = rt_slioCatalogueAddr ( ) ; void * r2 = (
NULL ) ; void * * pOSigstreamManagerAddr = ( NULL ) ; const int
maxErrorBufferSize = 16384 ; char errMsgCreatingOSigstreamManager [ 16384 ] ;
bool errorCreatingOSigstreamManager = false ; const char *
errorAddingR2SharedResource = ( NULL ) ; * slioCatalogueAddr =
rtwGetNewSlioCatalogue ( rt_GetMatSigLogSelectorFileName ( ) ) ;
errorAddingR2SharedResource = rtwAddR2SharedResource (
rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( ) ) , 1 ) ; if (
errorAddingR2SharedResource != ( NULL ) ) { rtwTerminateSlioCatalogue (
slioCatalogueAddr ) ; * slioCatalogueAddr = ( NULL ) ; ssSetErrorStatus ( rtS
, errorAddingR2SharedResource ) ; return ; } r2 = rtwGetR2SharedResource (
rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( ) ) ) ;
pOSigstreamManagerAddr = rt_GetOSigstreamManagerAddr ( ) ;
errorCreatingOSigstreamManager = rtwOSigstreamManagerCreateInstance (
rt_GetMatSigLogSelectorFileName ( ) , r2 , pOSigstreamManagerAddr ,
errMsgCreatingOSigstreamManager , maxErrorBufferSize ) ; if (
errorCreatingOSigstreamManager ) { * pOSigstreamManagerAddr = ( NULL ) ;
ssSetErrorStatus ( rtS , errMsgCreatingOSigstreamManager ) ; return ; } } {
bool externalInputIsInDatasetFormat = false ; void * pISigstreamManager =
rt_GetISigstreamManager ( ) ; rtwISigstreamManagerGetInputIsInDatasetFormat (
pISigstreamManager , & externalInputIsInDatasetFormat ) ; if (
externalInputIsInDatasetFormat ) { } } for ( i = 0 ; i < 6 ; i ++ ) { rtB .
gojcuhgrmx [ i ] = rtP . X0 [ i ] ; } rtDW . lf425rrkcg = 0 ; MdlInitialize (
) ; } void MdlOutputs ( int_T tid ) { real_T nsldzv3jrb ; int32_T i ; rtB .
fvdrarjklh = ssGetT ( rtS ) ; if ( ssIsSampleHit ( rtS , 1 , 0 ) &&
ssIsSampleHit ( rtS , 2 , 0 ) ) { rtDW . cu1zwqps1l = rtB . fvdrarjklh ; } if
( ssIsSampleHit ( rtS , 2 , 0 ) ) { rtB . c3rqc1rio3 = rtDW . cu1zwqps1l ; }
if ( rtDW . lme5rvswfq != 0 ) { rtX . fspxkrhtiu = rtB . gojcuhgrmx [ 0 ] ; }
rtB . jqdmu0onem = rtX . fspxkrhtiu ; if ( rtDW . fdhd0srwf4 != 0 ) { rtX .
meygbb43lf = rtB . gojcuhgrmx [ 1 ] ; } rtB . oqoepvxuhl = rtX . meygbb43lf ;
if ( rtDW . gy2ooyn5oy != 0 ) { rtX . enuggszhiy = rtB . gojcuhgrmx [ 2 ] ; }
rtB . gecdibna14 = rtX . enuggszhiy ; if ( rtDW . ljzqqcgkl3 != 0 ) { rtX .
ii0mta5lea = rtB . gojcuhgrmx [ 3 ] ; } rtB . hlyoede2ou = rtX . ii0mta5lea ;
if ( rtDW . dauvg5ipgx != 0 ) { rtX . ctiwnkz2yn = rtB . gojcuhgrmx [ 4 ] ; }
rtB . heynuzo0o5 = rtX . ctiwnkz2yn ; if ( rtDW . f0nkfvx4kv != 0 ) { rtX .
ogl1svj2ne = rtB . gojcuhgrmx [ 5 ] ; } rtB . ego0coqkjl = rtX . ogl1svj2ne ;
if ( ssIsSampleHit ( rtS , 1 , 0 ) && ssIsSampleHit ( rtS , 2 , 0 ) ) { rtDW
. pxmoytqe33 [ 0 ] = rtB . jqdmu0onem ; rtDW . pxmoytqe33 [ 1 ] = rtB .
oqoepvxuhl ; rtDW . pxmoytqe33 [ 2 ] = rtB . gecdibna14 ; rtDW . pxmoytqe33 [
3 ] = rtB . hlyoede2ou ; rtDW . pxmoytqe33 [ 4 ] = rtB . heynuzo0o5 ; rtDW .
pxmoytqe33 [ 5 ] = rtB . ego0coqkjl ; } if ( ssIsSampleHit ( rtS , 2 , 0 ) )
{ for ( i = 0 ; i < 6 ; i ++ ) { rtB . fsbqipywni [ i ] = rtDW . pxmoytqe33 [
i ] ; } } nsldzv3jrb = ( rtB . jqdmu0onem * rtB . jqdmu0onem + rtB .
oqoepvxuhl * rtB . oqoepvxuhl ) + rtB . gecdibna14 * rtB . gecdibna14 ; if (
ssIsMajorTimeStep ( rtS ) ) { if ( rtDW . lf425rrkcg != 0 ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; rtDW . lf425rrkcg = 0 ;
} nsldzv3jrb = muDoubleScalarSqrt ( nsldzv3jrb ) ; } else if ( nsldzv3jrb <
0.0 ) { nsldzv3jrb = - muDoubleScalarSqrt ( muDoubleScalarAbs ( nsldzv3jrb )
) ; rtDW . lf425rrkcg = 1 ; } else { nsldzv3jrb = muDoubleScalarSqrt (
nsldzv3jrb ) ; } nsldzv3jrb = rtB . bwaqcq2ocz / muDoubleScalarPower (
nsldzv3jrb , rtP . Constant_Value ) ; rtB . ip1ehjsak5 = nsldzv3jrb * rtB .
jqdmu0onem ; rtB . abfmtekobg = nsldzv3jrb * rtB . oqoepvxuhl ; rtB .
f5dz3p0zap = nsldzv3jrb * rtB . gecdibna14 ; UNUSED_PARAMETER ( tid ) ; }
void MdlOutputsTID3 ( int_T tid ) { int32_T i ; rtB . bwaqcq2ocz = - rtP . mi
; for ( i = 0 ; i < 6 ; i ++ ) { rtB . gojcuhgrmx [ i ] = rtP . X0 [ i ] ; }
UNUSED_PARAMETER ( tid ) ; } void MdlUpdate ( int_T tid ) { rtDW . lme5rvswfq
= 0 ; rtDW . fdhd0srwf4 = 0 ; rtDW . gy2ooyn5oy = 0 ; rtDW . ljzqqcgkl3 = 0 ;
rtDW . dauvg5ipgx = 0 ; rtDW . f0nkfvx4kv = 0 ; UNUSED_PARAMETER ( tid ) ; }
void MdlUpdateTID3 ( int_T tid ) { UNUSED_PARAMETER ( tid ) ; } void
MdlDerivatives ( void ) { XDot * _rtXdot ; _rtXdot = ( ( XDot * ) ssGetdX (
rtS ) ) ; _rtXdot -> fspxkrhtiu = rtB . hlyoede2ou ; _rtXdot -> meygbb43lf =
rtB . heynuzo0o5 ; _rtXdot -> enuggszhiy = rtB . ego0coqkjl ; _rtXdot ->
ii0mta5lea = rtB . ip1ehjsak5 ; _rtXdot -> ctiwnkz2yn = rtB . abfmtekobg ;
_rtXdot -> ogl1svj2ne = rtB . f5dz3p0zap ; } void MdlProjection ( void ) { }
void MdlTerminate ( void ) { if ( rt_slioCatalogue ( ) != ( NULL ) ) { void *
* slioCatalogueAddr = rt_slioCatalogueAddr ( ) ; rtwSaveDatasetsToMatFile (
rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( ) ) ,
rt_GetMatSigstreamLoggingFileName ( ) ) ; rtwTerminateSlioCatalogue (
slioCatalogueAddr ) ; * slioCatalogueAddr = NULL ; } } void
MdlInitializeSizes ( void ) { ssSetNumContStates ( rtS , 6 ) ;
ssSetNumPeriodicContStates ( rtS , 0 ) ; ssSetNumY ( rtS , 0 ) ; ssSetNumU (
rtS , 0 ) ; ssSetDirectFeedThrough ( rtS , 0 ) ; ssSetNumSampleTimes ( rtS ,
3 ) ; ssSetNumBlocks ( rtS , 23 ) ; ssSetNumBlockIO ( rtS , 14 ) ;
ssSetNumBlockParams ( rtS , 8 ) ; } void MdlInitializeSampleTimes ( void ) {
ssSetSampleTime ( rtS , 0 , 0.0 ) ; ssSetSampleTime ( rtS , 1 , 0.0 ) ;
ssSetSampleTime ( rtS , 2 , 0.1 ) ; ssSetOffsetTime ( rtS , 0 , 0.0 ) ;
ssSetOffsetTime ( rtS , 1 , 1.0 ) ; ssSetOffsetTime ( rtS , 2 , 0.0 ) ; }
void raccel_set_checksum ( ) { ssSetChecksumVal ( rtS , 0 , 473134070U ) ;
ssSetChecksumVal ( rtS , 1 , 3374777374U ) ; ssSetChecksumVal ( rtS , 2 ,
1377649563U ) ; ssSetChecksumVal ( rtS , 3 , 3095674371U ) ; }
#if defined(_MSC_VER)
#pragma optimize( "", off )
#endif
SimStruct * raccel_register_model ( void ) { static struct _ssMdlInfo mdlInfo
; ( void ) memset ( ( char * ) rtS , 0 , sizeof ( SimStruct ) ) ; ( void )
memset ( ( char * ) & mdlInfo , 0 , sizeof ( struct _ssMdlInfo ) ) ;
ssSetMdlInfoPtr ( rtS , & mdlInfo ) ; { static time_T mdlPeriod [
NSAMPLE_TIMES ] ; static time_T mdlOffset [ NSAMPLE_TIMES ] ; static time_T
mdlTaskTimes [ NSAMPLE_TIMES ] ; static int_T mdlTsMap [ NSAMPLE_TIMES ] ;
static int_T mdlSampleHits [ NSAMPLE_TIMES ] ; static boolean_T
mdlTNextWasAdjustedPtr [ NSAMPLE_TIMES ] ; static int_T mdlPerTaskSampleHits
[ NSAMPLE_TIMES * NSAMPLE_TIMES ] ; static time_T mdlTimeOfNextSampleHit [
NSAMPLE_TIMES ] ; { int_T i ; for ( i = 0 ; i < NSAMPLE_TIMES ; i ++ ) {
mdlPeriod [ i ] = 0.0 ; mdlOffset [ i ] = 0.0 ; mdlTaskTimes [ i ] = 0.0 ;
mdlTsMap [ i ] = i ; mdlSampleHits [ i ] = 1 ; } } ssSetSampleTimePtr ( rtS ,
& mdlPeriod [ 0 ] ) ; ssSetOffsetTimePtr ( rtS , & mdlOffset [ 0 ] ) ;
ssSetSampleTimeTaskIDPtr ( rtS , & mdlTsMap [ 0 ] ) ; ssSetTPtr ( rtS , &
mdlTaskTimes [ 0 ] ) ; ssSetSampleHitPtr ( rtS , & mdlSampleHits [ 0 ] ) ;
ssSetTNextWasAdjustedPtr ( rtS , & mdlTNextWasAdjustedPtr [ 0 ] ) ;
ssSetPerTaskSampleHitsPtr ( rtS , & mdlPerTaskSampleHits [ 0 ] ) ;
ssSetTimeOfNextSampleHitPtr ( rtS , & mdlTimeOfNextSampleHit [ 0 ] ) ; }
ssSetSolverMode ( rtS , SOLVER_MODE_SINGLETASKING ) ; { ssSetBlockIO ( rtS ,
( ( void * ) & rtB ) ) ; ( void ) memset ( ( ( void * ) & rtB ) , 0 , sizeof
( B ) ) ; } { real_T * x = ( real_T * ) & rtX ; ssSetContStates ( rtS , x ) ;
( void ) memset ( ( void * ) x , 0 , sizeof ( X ) ) ; } { void * dwork = (
void * ) & rtDW ; ssSetRootDWork ( rtS , dwork ) ; ( void ) memset ( dwork ,
0 , sizeof ( DW ) ) ; } { static DataTypeTransInfo dtInfo ; ( void ) memset (
( char_T * ) & dtInfo , 0 , sizeof ( dtInfo ) ) ; ssSetModelMappingInfo ( rtS
, & dtInfo ) ; dtInfo . numDataTypes = 14 ; dtInfo . dataTypeSizes = &
rtDataTypeSizes [ 0 ] ; dtInfo . dataTypeNames = & rtDataTypeNames [ 0 ] ;
dtInfo . BTransTable = & rtBTransTable ; dtInfo . PTransTable = &
rtPTransTable ; dtInfo . dataTypeInfoTable = rtDataTypeInfoTable ; }
propagatorN_InitializeDataMapInfo ( ) ; ssSetIsRapidAcceleratorActive ( rtS ,
true ) ; ssSetRootSS ( rtS , rtS ) ; ssSetVersion ( rtS ,
SIMSTRUCT_VERSION_LEVEL2 ) ; ssSetModelName ( rtS , "propagatorN" ) ;
ssSetPath ( rtS , "propagatorN" ) ; ssSetTStart ( rtS , 0.0 ) ; ssSetTFinal (
rtS , 86400.0 ) ; { static RTWLogInfo rt_DataLoggingInfo ; rt_DataLoggingInfo
. loggingInterval = NULL ; ssSetRTWLogInfo ( rtS , & rt_DataLoggingInfo ) ; }
{ rtliSetLogXSignalInfo ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ;
rtliSetLogXSignalPtrs ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ; rtliSetLogT (
ssGetRTWLogInfo ( rtS ) , "tout" ) ; rtliSetLogX ( ssGetRTWLogInfo ( rtS ) ,
"" ) ; rtliSetLogXFinal ( ssGetRTWLogInfo ( rtS ) , "" ) ;
rtliSetLogVarNameModifier ( ssGetRTWLogInfo ( rtS ) , "none" ) ;
rtliSetLogFormat ( ssGetRTWLogInfo ( rtS ) , 4 ) ; rtliSetLogMaxRows (
ssGetRTWLogInfo ( rtS ) , 0 ) ; rtliSetLogDecimation ( ssGetRTWLogInfo ( rtS
) , 1 ) ; rtliSetLogY ( ssGetRTWLogInfo ( rtS ) , "" ) ;
rtliSetLogYSignalInfo ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ;
rtliSetLogYSignalPtrs ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ; } { static
struct _ssStatesInfo2 statesInfo2 ; ssSetStatesInfo2 ( rtS , & statesInfo2 )
; } { static ssPeriodicStatesInfo periodicStatesInfo ;
ssSetPeriodicStatesInfo ( rtS , & periodicStatesInfo ) ; } { static
ssSolverInfo slvrInfo ; static boolean_T contStatesDisabled [ 6 ] ; static
real_T absTol [ 6 ] = { 1.0E-13 , 1.0E-13 , 1.0E-13 , 1.0E-13 , 1.0E-13 ,
1.0E-13 } ; static uint8_T absTolControl [ 6 ] = { 0U , 0U , 0U , 0U , 0U ,
0U } ; ssSetSolverRelTol ( rtS , 0.001 ) ; ssSetStepSize ( rtS , 0.0 ) ;
ssSetMinStepSize ( rtS , 0.0001 ) ; ssSetMaxNumMinSteps ( rtS , - 1 ) ;
ssSetMinStepViolatedError ( rtS , 0 ) ; ssSetMaxStepSize ( rtS , 0.05 ) ;
ssSetSolverMaxOrder ( rtS , - 1 ) ; ssSetSolverRefineFactor ( rtS , 1 ) ;
ssSetOutputTimes ( rtS , ( NULL ) ) ; ssSetNumOutputTimes ( rtS , 0 ) ;
ssSetOutputTimesOnly ( rtS , 0 ) ; ssSetOutputTimesIndex ( rtS , 0 ) ;
ssSetZCCacheNeedsReset ( rtS , 0 ) ; ssSetDerivCacheNeedsReset ( rtS , 0 ) ;
ssSetNumNonContDerivSigInfos ( rtS , 0 ) ; ssSetNonContDerivSigInfos ( rtS ,
( NULL ) ) ; ssSetSolverInfo ( rtS , & slvrInfo ) ; ssSetSolverName ( rtS ,
"ode113" ) ; ssSetVariableStepSolver ( rtS , 1 ) ;
ssSetSolverConsistencyChecking ( rtS , 0 ) ; ssSetSolverAdaptiveZcDetection (
rtS , 0 ) ; ssSetSolverRobustResetMethod ( rtS , 0 ) ; ssSetAbsTolVector (
rtS , absTol ) ; ssSetAbsTolControlVector ( rtS , absTolControl ) ;
ssSetSolverAbsTol_Obsolete ( rtS , absTol ) ;
ssSetSolverAbsTolControl_Obsolete ( rtS , absTolControl ) ;
ssSetSolverStateProjection ( rtS , 0 ) ; ssSetSolverMassMatrixType ( rtS , (
ssMatrixType ) 0 ) ; ssSetSolverMassMatrixNzMax ( rtS , 0 ) ;
ssSetModelOutputs ( rtS , MdlOutputs ) ; ssSetModelLogData ( rtS ,
rt_UpdateTXYLogVars ) ; ssSetModelLogDataIfInInterval ( rtS ,
rt_UpdateTXXFYLogVars ) ; ssSetModelUpdate ( rtS , MdlUpdate ) ;
ssSetModelDerivatives ( rtS , MdlDerivatives ) ;
ssSetSolverMaxConsecutiveMinStep ( rtS , 1 ) ;
ssSetSolverShapePreserveControl ( rtS , 2 ) ; ssSetTNextTid ( rtS , INT_MIN )
; ssSetTNext ( rtS , rtMinusInf ) ; ssSetSolverNeedsReset ( rtS ) ;
ssSetNumNonsampledZCs ( rtS , 0 ) ; ssSetContStateDisabled ( rtS ,
contStatesDisabled ) ; ssSetSolverMaxConsecutiveMinStep ( rtS , 1 ) ; }
ssSetChecksumVal ( rtS , 0 , 473134070U ) ; ssSetChecksumVal ( rtS , 1 ,
3374777374U ) ; ssSetChecksumVal ( rtS , 2 , 1377649563U ) ; ssSetChecksumVal
( rtS , 3 , 3095674371U ) ; { static const sysRanDType rtAlwaysEnabled =
SUBSYS_RAN_BC_ENABLE ; static RTWExtModeInfo rt_ExtModeInfo ; static const
sysRanDType * systemRan [ 1 ] ; gblRTWExtModeInfo = & rt_ExtModeInfo ;
ssSetRTWExtModeInfo ( rtS , & rt_ExtModeInfo ) ;
rteiSetSubSystemActiveVectorAddresses ( & rt_ExtModeInfo , systemRan ) ;
systemRan [ 0 ] = & rtAlwaysEnabled ; rteiSetModelMappingInfoPtr (
ssGetRTWExtModeInfo ( rtS ) , & ssGetModelMappingInfo ( rtS ) ) ;
rteiSetChecksumsPtr ( ssGetRTWExtModeInfo ( rtS ) , ssGetChecksums ( rtS ) )
; rteiSetTPtr ( ssGetRTWExtModeInfo ( rtS ) , ssGetTPtr ( rtS ) ) ; } return
rtS ; }
#if defined(_MSC_VER)
#pragma optimize( "", on )
#endif
const int_T gblParameterTuningTid = 3 ; void MdlOutputsParameterSampleTime (
int_T tid ) { MdlOutputsTID3 ( tid ) ; }
