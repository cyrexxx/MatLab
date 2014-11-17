#ifndef __c5_G24i_buck_boost_h__
#define __c5_G24i_buck_boost_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc5_G24i_buck_boostInstanceStruct
#define typedef_SFc5_G24i_buck_boostInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c5_sfEvent;
  uint8_T c5_tp_init;
  uint8_T c5_tp_Sample_and_call;
  uint8_T c5_tp_INCREMENT;
  uint8_T c5_tp_DECREMENT;
  uint8_T c5_tp_RETURN;
  boolean_T c5_isStable;
  uint8_T c5_is_active_c5_G24i_buck_boost;
  uint8_T c5_is_c5_G24i_buck_boost;
  real_T c5_Vmpp;
  real_T c5_deltaV;
  real_T c5_V_REF;
  uint8_T c5_doSetSimStateSideEffects;
  const mxArray *c5_setSimStateSideEffectsInfo;
} SFc5_G24i_buck_boostInstanceStruct;

#endif                                 /*typedef_SFc5_G24i_buck_boostInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c5_G24i_buck_boost_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c5_G24i_buck_boost_get_check_sum(mxArray *plhs[]);
extern void c5_G24i_buck_boost_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
