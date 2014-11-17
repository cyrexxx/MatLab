#ifndef __c4_G24i_buck_boost_h__
#define __c4_G24i_buck_boost_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc4_G24i_buck_boostInstanceStruct
#define typedef_SFc4_G24i_buck_boostInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint8_T c4_is_active_c4_G24i_buck_boost;
  real_T c4_Vold;
  boolean_T c4_Vold_not_empty;
  real_T c4_Pold;
  boolean_T c4_Pold_not_empty;
  real_T c4_Dold;
  boolean_T c4_Dold_not_empty;
} SFc4_G24i_buck_boostInstanceStruct;

#endif                                 /*typedef_SFc4_G24i_buck_boostInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c4_G24i_buck_boost_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c4_G24i_buck_boost_get_check_sum(mxArray *plhs[]);
extern void c4_G24i_buck_boost_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
