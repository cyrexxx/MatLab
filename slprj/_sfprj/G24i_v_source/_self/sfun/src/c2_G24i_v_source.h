#ifndef __c2_G24i_v_source_h__
#define __c2_G24i_v_source_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef struct_sZC8snFIP2XGLBfvkfBz2BF
#define struct_sZC8snFIP2XGLBfvkfBz2BF

struct sZC8snFIP2XGLBfvkfBz2BF
{
  real_T voc[20];
  real_T vmpp[20];
  real_T _index;
};

#endif                                 /*struct_sZC8snFIP2XGLBfvkfBz2BF*/

#ifndef typedef_c2_sZC8snFIP2XGLBfvkfBz2BF
#define typedef_c2_sZC8snFIP2XGLBfvkfBz2BF

typedef struct sZC8snFIP2XGLBfvkfBz2BF c2_sZC8snFIP2XGLBfvkfBz2BF;

#endif                                 /*typedef_c2_sZC8snFIP2XGLBfvkfBz2BF*/

#ifndef typedef_SFc2_G24i_v_sourceInstanceStruct
#define typedef_SFc2_G24i_v_sourceInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c2_sfEvent;
  boolean_T c2_isStable;
  boolean_T c2_doneDoubleBufferReInit;
  uint8_T c2_is_active_c2_G24i_v_source;
  real_T c2_Dold;
  boolean_T c2_Dold_not_empty;
  real_T c2_Voc_old;
  boolean_T c2_Voc_old_not_empty;
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
