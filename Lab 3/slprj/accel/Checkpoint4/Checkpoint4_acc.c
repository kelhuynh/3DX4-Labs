#include <math.h>
#include "Checkpoint4_acc.h"
#include "Checkpoint4_acc_private.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include <stdio.h>
#include "slexec_vm_simstruct_bridge.h"
#include "slexec_vm_zc_functions.h"
#include "slexec_vm_lookup_functions.h"
#include "slsv_diagnostic_codegen_c_api.h"
#include "simtarget/slSimTgtMdlrefSfcnBridge.h"
#define CodeFormat S-Function
#define AccDefine1 Accelerator_S-Function
#include "simtarget/slAccSfcnBridge.h"
void rt_ssGetBlockPath ( SimStruct * S , int_T sysIdx , int_T blkIdx , char_T
* * path ) { _ssGetBlockPath ( S , sysIdx , blkIdx , path ) ; } void
rt_ssSet_slErrMsg ( SimStruct * S , void * diag ) { if ( !
_ssIsErrorStatusAslErrMsg ( S ) ) { _ssSet_slErrMsg ( S , diag ) ; } else {
_ssDiscardDiagnostic ( S , diag ) ; } } void rt_ssReportDiagnosticAsWarning (
SimStruct * S , void * diag ) { _ssReportDiagnosticAsWarning ( S , diag ) ; }
static void mdlOutputs ( SimStruct * S , int_T tid ) { real_T B_0_1_0 ;
B_Checkpoint4_T * _rtB ; DW_Checkpoint4_T * _rtDW ; P_Checkpoint4_T * _rtP ;
X_Checkpoint4_T * _rtX ; real_T rtb_B_0_14_0 ; real_T rtb_B_0_6_0 ; int32_T i
; _rtDW = ( ( DW_Checkpoint4_T * ) ssGetRootDWork ( S ) ) ; _rtX = ( (
X_Checkpoint4_T * ) ssGetContStates ( S ) ) ; _rtP = ( ( P_Checkpoint4_T * )
ssGetModelRtp ( S ) ) ; _rtB = ( ( B_Checkpoint4_T * ) _ssGetModelBlockIO ( S
) ) ; i = ssIsSampleHit ( S , 1 , 0 ) ; if ( i != 0 ) { { t_error result ;
result = hil_task_read_analog ( _rtDW -> HILReadAnalogTimebase_Task , 1 , &
_rtDW -> HILReadAnalogTimebase_Buffer ) ; if ( result < 0 ) {
msg_get_error_messageA ( NULL , result , _rt_error_message , sizeof (
_rt_error_message ) ) ; ssSetErrorStatus ( S , _rt_error_message ) ; }
B_0_1_0 = _rtDW -> HILReadAnalogTimebase_Buffer ; } _rtB -> B_0_2_0 = _rtP ->
P_17 * B_0_1_0 ; _rtB -> B_0_5_0 [ 0 ] = _rtB -> B_0_2_0 ; } i =
ssIsSampleHit ( S , 2 , 0 ) ; if ( i != 0 ) { memcpy ( & _rtB -> B_0_5_0 [ 1
] , & _rtDW -> TappedDelay_X [ 0 ] , 100U * sizeof ( real_T ) ) ; } i =
ssIsSampleHit ( S , 1 , 0 ) ; if ( i != 0 ) { rtb_B_0_6_0 = - 0.0 ; for ( i =
0 ; i < 101 ; i ++ ) { rtb_B_0_6_0 += _rtB -> B_0_5_0 [ i ] ; } _rtB ->
B_0_7_0 = rtb_B_0_6_0 / Checkpoint4_rtC ( S ) -> B_0_0_0 ;
ssCallAccelRunBlock ( S , 0 , 8 , SS_CALL_MDL_OUTPUTS ) ; _rtB -> B_0_10_0 =
muDoubleScalarAbs ( _rtB -> B_0_1_0 - _rtB -> B_0_7_0 ) ; ssCallAccelRunBlock
( S , 0 , 11 , SS_CALL_MDL_OUTPUTS ) ; rtb_B_0_6_0 = _rtB -> B_0_1_0 - _rtB
-> B_0_2_0 ; _rtB -> B_0_13_0 = _rtP -> P_19 * rtb_B_0_6_0 ; } i =
ssIsSampleHit ( S , 1 , 0 ) ; if ( i != 0 ) { _rtB -> B_0_15_0 = _rtP -> P_21
* rtb_B_0_6_0 ; } _rtB -> B_0_18_0 = ( _rtB -> B_0_15_0 - _rtX ->
Filter_CSTATE ) * _rtP -> P_23 ; rtb_B_0_14_0 = ( ( _rtB -> B_0_13_0 + _rtX
-> Integrator_CSTATE ) + _rtB -> B_0_18_0 ) * _rtP -> P_24 ; if (
rtb_B_0_14_0 > _rtP -> P_25 ) { rtb_B_0_14_0 = _rtP -> P_25 ; } else { if (
rtb_B_0_14_0 < _rtP -> P_26 ) { rtb_B_0_14_0 = _rtP -> P_26 ; } } if (
muDoubleScalarAbs ( rtb_B_0_14_0 ) > _rtP -> P_27 ) { _rtB -> B_0_23_0 =
rtb_B_0_14_0 ; } else { _rtB -> B_0_23_0 = _rtB -> B_0_2_0_m ; } i =
ssIsSampleHit ( S , 1 , 0 ) ; if ( i != 0 ) { { t_error result ; result =
hil_write_analog ( ( ( DW_Checkpoint4_T * ) ssGetRootDWork ( S ) ) ->
HILInitialize_Card , & _rtP -> P_47 , 1 , & _rtB -> B_0_23_0 ) ; if ( result
< 0 ) { msg_get_error_messageA ( NULL , result , _rt_error_message , sizeof (
_rt_error_message ) ) ; ssSetErrorStatus ( S , _rt_error_message ) ; } }
ssCallAccelRunBlock ( S , 0 , 25 , SS_CALL_MDL_OUTPUTS ) ; _rtB -> B_0_26_0 =
_rtP -> P_28 * rtb_B_0_6_0 ; } UNUSED_PARAMETER ( tid ) ; } static void
mdlOutputsTID3 ( SimStruct * S , int_T tid ) { B_Checkpoint4_T * _rtB ;
P_Checkpoint4_T * _rtP ; _rtP = ( ( P_Checkpoint4_T * ) ssGetModelRtp ( S ) )
; _rtB = ( ( B_Checkpoint4_T * ) _ssGetModelBlockIO ( S ) ) ; _rtB -> B_0_1_0
= _rtP -> P_30 * _rtP -> P_29 ; _rtB -> B_0_2_0_m = _rtP -> P_31 ;
UNUSED_PARAMETER ( tid ) ; }
#define MDL_UPDATE
static void mdlUpdate ( SimStruct * S , int_T tid ) { B_Checkpoint4_T * _rtB
; DW_Checkpoint4_T * _rtDW ; int32_T isHit ; _rtDW = ( ( DW_Checkpoint4_T * )
ssGetRootDWork ( S ) ) ; _rtB = ( ( B_Checkpoint4_T * ) _ssGetModelBlockIO (
S ) ) ; isHit = ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit != 0 ) { for ( isHit
= 0 ; isHit < 99 ; isHit ++ ) { _rtDW -> TappedDelay_X [ isHit ] = _rtDW ->
TappedDelay_X [ isHit + 1 ] ; } _rtDW -> TappedDelay_X [ 99 ] = _rtB ->
B_0_2_0 ; } UNUSED_PARAMETER ( tid ) ; }
#define MDL_UPDATE
static void mdlUpdateTID3 ( SimStruct * S , int_T tid ) { UNUSED_PARAMETER (
tid ) ; }
#define MDL_DERIVATIVES
static void mdlDerivatives ( SimStruct * S ) { B_Checkpoint4_T * _rtB ;
XDot_Checkpoint4_T * _rtXdot ; _rtXdot = ( ( XDot_Checkpoint4_T * ) ssGetdX (
S ) ) ; _rtB = ( ( B_Checkpoint4_T * ) _ssGetModelBlockIO ( S ) ) ; _rtXdot
-> Integrator_CSTATE = _rtB -> B_0_26_0 ; _rtXdot -> Filter_CSTATE = _rtB ->
B_0_18_0 ; } static void mdlInitializeSizes ( SimStruct * S ) {
ssSetChecksumVal ( S , 0 , 1080079331U ) ; ssSetChecksumVal ( S , 1 ,
3459603090U ) ; ssSetChecksumVal ( S , 2 , 2385746067U ) ; ssSetChecksumVal (
S , 3 , 3661745419U ) ; { mxArray * slVerStructMat = NULL ; mxArray *
slStrMat = mxCreateString ( "simulink" ) ; char slVerChar [ 10 ] ; int status
= mexCallMATLAB ( 1 , & slVerStructMat , 1 , & slStrMat , "ver" ) ; if (
status == 0 ) { mxArray * slVerMat = mxGetField ( slVerStructMat , 0 ,
"Version" ) ; if ( slVerMat == NULL ) { status = 1 ; } else { status =
mxGetString ( slVerMat , slVerChar , 10 ) ; } } mxDestroyArray ( slStrMat ) ;
mxDestroyArray ( slVerStructMat ) ; if ( ( status == 1 ) || ( strcmp (
slVerChar , "10.2" ) != 0 ) ) { return ; } } ssSetOptions ( S ,
SS_OPTION_EXCEPTION_FREE_CODE ) ; if ( ssGetSizeofDWork ( S ) != sizeof (
DW_Checkpoint4_T ) ) { ssSetErrorStatus ( S ,
"Unexpected error: Internal DWork sizes do "
"not match for accelerator mex file." ) ; } if ( ssGetSizeofGlobalBlockIO ( S
) != sizeof ( B_Checkpoint4_T ) ) { ssSetErrorStatus ( S ,
"Unexpected error: Internal BlockIO sizes do "
"not match for accelerator mex file." ) ; } { int ssSizeofParams ;
ssGetSizeofParams ( S , & ssSizeofParams ) ; if ( ssSizeofParams != sizeof (
P_Checkpoint4_T ) ) { static char msg [ 256 ] ; sprintf ( msg ,
"Unexpected error: Internal Parameters sizes do "
"not match for accelerator mex file." ) ; } } _ssSetModelRtp ( S , ( real_T *
) & Checkpoint4_rtDefaultP ) ; _ssSetConstBlockIO ( S , &
Checkpoint4_rtInvariant ) ; } static void mdlInitializeSampleTimes (
SimStruct * S ) { slAccRegPrmChangeFcn ( S , mdlOutputsTID3 ) ; } static void
mdlTerminate ( SimStruct * S ) { }
#include "simulink.c"
