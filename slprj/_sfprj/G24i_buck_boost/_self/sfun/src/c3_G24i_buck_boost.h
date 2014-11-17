#ifndef __c3_G24i_buck_boost_h__
#define __c3_G24i_buck_boost_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc3_G24i_buck_boostInstanceStruct
#define typedef_SFc3_G24i_buck_boostInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c3_sfEvent;
  uint8_T c3_tp_init;
  uint8_T c3_tp_Sample_and_call;
  uint8_T c3_tp_INCREMENT;
  uint8_T c3_tp_DECREMENT;
  uint8_T c3_tp_RETURN;
  boolean_T c3_isStable;
  uint8_T c3_is_active_c3_G24i_buck_boost;
  uint8_T c3_is_c3_G24i_buck_boost;
  real_T c3_V_prev1;
  real_T c3_I_prev1;
  real_T c3_V_REF;
  real_T c3_deltaV;
  real_T c3_deltaI;
  uint8_T c3_doSetSimStateSideEffects;
  const mxArray *c3_setSimStateSideEffectsInfo;
} SFc3_G24i_buck_boostInstanceStruct;

#endif                                 /*typedef_SFc3_G24i_buck_boostInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c3_G24i_buck_boost_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c3_G24i_buck_boost_get_check_sum(mxArray *plhs[]);
extern void c3_G24i_buck_boost_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
