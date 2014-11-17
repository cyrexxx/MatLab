#ifndef __c2_G24i_buck_boost_h__
#define __c2_G24i_buck_boost_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc2_G24i_buck_boostInstanceStruct
#define typedef_SFc2_G24i_buck_boostInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c2_sfEvent;
  boolean_T c2_isStable;
  boolean_T c2_doneDoubleBufferReInit;
  uint8_T c2_is_active_c2_G24i_buck_boost;
  real_T c2_Vold;
  boolean_T c2_Vold_not_empty;
  real_T c2_Pold;
  boolean_T c2_Pold_not_empty;
  real_T c2_Dold;
  boolean_T c2_Dold_not_empty;
} SFc2_G24i_buck_boostInstanceStruct;

#endif                                 /*typedef_SFc2_G24i_buck_boostInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c2_G24i_buck_boost_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c2_G24i_buck_boost_get_check_sum(mxArray *plhs[]);
extern void c2_G24i_buck_boost_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
