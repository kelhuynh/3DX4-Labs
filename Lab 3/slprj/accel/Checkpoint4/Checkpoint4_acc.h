#ifndef RTW_HEADER_Checkpoint4_acc_h_
#define RTW_HEADER_Checkpoint4_acc_h_
#include <string.h>
#include <stddef.h>
#ifndef Checkpoint4_acc_COMMON_INCLUDES_
#define Checkpoint4_acc_COMMON_INCLUDES_
#include <stdlib.h>
#define S_FUNCTION_NAME simulink_only_sfcn 
#define S_FUNCTION_LEVEL 2
#define RTW_GENERATED_S_FUNCTION
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "hil.h"
#include "quanser_messages.h"
#include "quanser_extern.h"
#endif
#include "Checkpoint4_acc_types.h"
#include "multiword_types.h"
#include "mwmathutil.h"
#include "rt_defines.h"
typedef struct { real_T B_0_2_0 ; real_T B_0_5_0 [ 101 ] ; real_T B_0_7_0 ;
real_T B_0_10_0 ; real_T B_0_13_0 ; real_T B_0_15_0 ; real_T B_0_18_0 ;
real_T B_0_23_0 ; real_T B_0_26_0 ; real_T B_0_1_0 ; real_T B_0_2_0_m ; }
B_Checkpoint4_T ; typedef struct { real_T TappedDelay_X [ 100 ] ; real_T
HILInitialize_AIMinimums [ 8 ] ; real_T HILInitialize_AIMaximums [ 8 ] ;
real_T HILInitialize_AOMinimums [ 8 ] ; real_T HILInitialize_AOMaximums [ 8 ]
; real_T HILInitialize_AOVoltages [ 8 ] ; real_T
HILInitialize_FilterFrequency [ 8 ] ; real_T HILInitialize_POSortedFreqs [ 8
] ; real_T HILInitialize_POValues [ 8 ] ; real_T HILReadAnalogTimebase_Buffer
; t_task HILReadAnalogTimebase_Task ; t_card HILInitialize_Card ; void *
HILWriteAnalog_PWORK ; void * Scope_PWORK [ 2 ] ; int32_T
HILInitialize_ClockModes [ 3 ] ; int32_T HILInitialize_QuadratureModes [ 8 ]
; int32_T HILInitialize_InitialEICounts [ 8 ] ; int32_T
HILInitialize_POModeValues [ 8 ] ; int32_T HILInitialize_POAlignValues [ 8 ]
; int32_T HILInitialize_POPolarityVals [ 8 ] ; uint32_T
HILInitialize_POSortedChans [ 8 ] ; char_T pad_HILInitialize_POSortedChans [
4 ] ; } DW_Checkpoint4_T ; typedef struct { real_T Integrator_CSTATE ; real_T
Filter_CSTATE ; } X_Checkpoint4_T ; typedef struct { real_T Integrator_CSTATE
; real_T Filter_CSTATE ; } XDot_Checkpoint4_T ; typedef struct { boolean_T
Integrator_CSTATE ; boolean_T Filter_CSTATE ; } XDis_Checkpoint4_T ; typedef
struct { const real_T B_0_0_0 ; } ConstB_Checkpoint4_T ;
#define Checkpoint4_rtC(S) ((ConstB_Checkpoint4_T *) _ssGetConstBlockIO(S))
struct P_Checkpoint4_T_ { real_T P_0 ; real_T P_1 ; real_T P_2 ; real_T P_3 ;
real_T P_4 ; real_T P_5 ; real_T P_6 ; real_T P_7 ; real_T P_8 ; real_T P_9 ;
real_T P_10 ; real_T P_11 ; real_T P_12 ; real_T P_13 ; real_T P_14 ; real_T
P_15 ; real_T P_16 ; real_T P_17 ; real_T P_18 ; real_T P_19 ; real_T P_20 ;
real_T P_21 ; real_T P_22 ; real_T P_23 ; real_T P_24 ; real_T P_25 ; real_T
P_26 ; real_T P_27 ; real_T P_28 ; real_T P_29 ; real_T P_30 ; real_T P_31 ;
int32_T P_32 [ 3 ] ; int32_T P_33 ; int32_T P_34 ; int32_T P_35 ; int32_T
P_36 ; int32_T P_37 ; int32_T P_38 ; int32_T P_39 ; uint32_T P_40 [ 8 ] ;
uint32_T P_41 [ 8 ] ; uint32_T P_42 [ 8 ] ; uint32_T P_43 ; uint32_T P_44 [ 8
] ; uint32_T P_45 ; uint32_T P_46 ; uint32_T P_47 ; boolean_T P_48 ;
boolean_T P_49 ; boolean_T P_50 ; boolean_T P_51 ; boolean_T P_52 ; boolean_T
P_53 ; boolean_T P_54 ; boolean_T P_55 ; boolean_T P_56 ; boolean_T P_57 ;
boolean_T P_58 ; boolean_T P_59 ; boolean_T P_60 ; boolean_T P_61 ; boolean_T
P_62 ; boolean_T P_63 ; boolean_T P_64 ; boolean_T P_65 ; boolean_T P_66 ;
boolean_T P_67 ; boolean_T P_68 ; boolean_T P_69 ; boolean_T P_70 ; boolean_T
P_71 ; boolean_T P_72 ; boolean_T P_73 ; boolean_T P_74 ; boolean_T P_75 ;
boolean_T P_76 ; boolean_T P_77 ; boolean_T P_78 ; boolean_T P_79 ; boolean_T
P_80 ; boolean_T P_81 ; boolean_T P_82 ; boolean_T P_83 ; boolean_T P_84 ;
uint8_T P_85 ; char_T pad_P_85 [ 2 ] ; } ; extern P_Checkpoint4_T
Checkpoint4_rtDefaultP ; extern const ConstB_Checkpoint4_T
Checkpoint4_rtInvariant ;
#endif
