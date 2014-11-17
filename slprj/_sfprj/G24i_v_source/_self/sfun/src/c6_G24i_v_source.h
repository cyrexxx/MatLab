#ifndef __c6_G24i_v_source_h__
#define __c6_G24i_v_source_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc6_G24i_v_sourceInstanceStruct
#define typedef_SFc6_G24i_v_sourceInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint8_T c6_is_active_c6_G24i_v_source;
  real_T c6_Vold;
  boolean_T c6_Vold_not_empty;
  real_T c6_Pold;
  boolean_T c6_Pold_not_empty;
  real_T c6_Dold;
  boolean_T c6_Dold_not_empty;
} SFc6_G24i_v_sourceInstanceStruct;

#endif                                 /*typedef_SFc6_G24i_v_sourceInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c6_G24i_v_source_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c6_G24i_v_source_get_check_sum(mxArray *plhs[]);
extern void c6_G24i_v_source_method_dispatcher(SimStruct *S, int_T method, void *
  data);

#endif
