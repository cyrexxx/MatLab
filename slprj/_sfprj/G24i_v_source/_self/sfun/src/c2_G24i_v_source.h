#ifndef __c2_G24i_v_source_h__
#define __c2_G24i_v_source_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc2_G24i_v_sourceInstanceStruct
#define typedef_SFc2_G24i_v_sourceInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint8_T c2_is_active_c2_G24i_v_source;
  real_T c2_Dold;
  boolean_T c2_Dold_not_empty;
  real_T c2_Voc_old;
  boolean_T c2_Voc_old_not_empty;
  real_T c2_upper_lim;
  boolean_T c2_upper_lim_not_empty;
  real_T c2_low_lim;
  boolean_T c2_low_lim_not_empty;
  real_T c2_iteration_count;
  boolean_T c2_iteration_count_not_empty;
  real_T c2_flag;
  boolean_T c2_flag_not_empty;
  real_T c2_Xs[4];
  boolean_T c2_Xs_not_empty;
  real_T c2_Vs[40];
  boolean_T c2_Vs_not_empty;
  real_T c2_idx;
  boolean_T c2_idx_not_empty;
  real_T c2_done;
  boolean_T c2_done_not_empty;
} SFc2_G24i_v_sourceInstanceStruct;

#endif                                 /*typedef_SFc2_G24i_v_sourceInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c2_G24i_v_source_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c2_G24i_v_source_get_check_sum(mxArray *plhs[]);
extern void c2_G24i_v_source_method_dispatcher(SimStruct *S, int_T method, void *
  data);

#endif
