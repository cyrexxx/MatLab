/* Include files */

#include <stddef.h>
#include "blas.h"
#include "G24i_v_source_sfun.h"
#include "c6_G24i_v_source.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(NULL,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;

/* Function Declarations */
static void initialize_c6_G24i_v_source(SFc6_G24i_v_sourceInstanceStruct
  *chartInstance);
static void initialize_params_c6_G24i_v_source(SFc6_G24i_v_sourceInstanceStruct *
  chartInstance);
static void enable_c6_G24i_v_source(SFc6_G24i_v_sourceInstanceStruct
  *chartInstance);
static void disable_c6_G24i_v_source(SFc6_G24i_v_sourceInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c6_G24i_v_source
  (SFc6_G24i_v_sourceInstanceStruct *chartInstance);
static void set_sim_state_c6_G24i_v_source(SFc6_G24i_v_sourceInstanceStruct
  *chartInstance, const mxArray *c6_st);
static void finalize_c6_G24i_v_source(SFc6_G24i_v_sourceInstanceStruct
  *chartInstance);
static void sf_gateway_c6_G24i_v_source(SFc6_G24i_v_sourceInstanceStruct
  *chartInstance);
static void initSimStructsc6_G24i_v_source(SFc6_G24i_v_sourceInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c6_machineNumber, uint32_T
  c6_chartNumber, uint32_T c6_instanceNumber);
static real_T c6_emlrt_marshallIn(SFc6_G24i_v_sourceInstanceStruct
  *chartInstance, const mxArray *c6_D, const char_T *c6_identifier);
static real_T c6_b_emlrt_marshallIn(SFc6_G24i_v_sourceInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId);
static real_T c6_c_emlrt_marshallIn(SFc6_G24i_v_sourceInstanceStruct
  *chartInstance, const mxArray *c6_b_Dold, const char_T *c6_identifier);
static real_T c6_d_emlrt_marshallIn(SFc6_G24i_v_sourceInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId);
static real_T c6_e_emlrt_marshallIn(SFc6_G24i_v_sourceInstanceStruct
  *chartInstance, const mxArray *c6_b_Pold, const char_T *c6_identifier);
static real_T c6_f_emlrt_marshallIn(SFc6_G24i_v_sourceInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId);
static real_T c6_g_emlrt_marshallIn(SFc6_G24i_v_sourceInstanceStruct
  *chartInstance, const mxArray *c6_b_Vold, const char_T *c6_identifier);
static real_T c6_h_emlrt_marshallIn(SFc6_G24i_v_sourceInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId);
static uint8_T c6_i_emlrt_marshallIn(SFc6_G24i_v_sourceInstanceStruct
  *chartInstance, const mxArray *c6_b_is_active_c6_G24i_v_source, const char_T
  *c6_identifier);
static uint8_T c6_j_emlrt_marshallIn(SFc6_G24i_v_sourceInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId);
static void init_dsm_address_info(SFc6_G24i_v_sourceInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c6_G24i_v_source(SFc6_G24i_v_sourceInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c6_Vold_not_empty = false;
  chartInstance->c6_Pold_not_empty = false;
  chartInstance->c6_Dold_not_empty = false;
  chartInstance->c6_is_active_c6_G24i_v_source = 0U;
}

static void initialize_params_c6_G24i_v_source(SFc6_G24i_v_sourceInstanceStruct *
  chartInstance)
{
  (void)chartInstance;
}

static void enable_c6_G24i_v_source(SFc6_G24i_v_sourceInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c6_G24i_v_source(SFc6_G24i_v_sourceInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static const mxArray *get_sim_state_c6_G24i_v_source
  (SFc6_G24i_v_sourceInstanceStruct *chartInstance)
{
  const mxArray *c6_st;
  const mxArray *c6_y = NULL;
  real_T c6_u;
  const mxArray *c6_b_y = NULL;
  real_T c6_b_u;
  const mxArray *c6_c_y = NULL;
  real_T c6_c_u;
  const mxArray *c6_d_y = NULL;
  real_T c6_d_u;
  const mxArray *c6_e_y = NULL;
  uint8_T c6_e_u;
  const mxArray *c6_f_y = NULL;
  real_T *c6_D;
  c6_D = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c6_st = NULL;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_createcellmatrix(5, 1), false);
  c6_u = *c6_D;
  c6_b_y = NULL;
  sf_mex_assign(&c6_b_y, sf_mex_create("y", &c6_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c6_y, 0, c6_b_y);
  c6_b_u = chartInstance->c6_Dold;
  c6_c_y = NULL;
  if (!chartInstance->c6_Dold_not_empty) {
    sf_mex_assign(&c6_c_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c6_c_y, sf_mex_create("y", &c6_b_u, 0, 0U, 0U, 0U, 0), false);
  }

  sf_mex_setcell(c6_y, 1, c6_c_y);
  c6_c_u = chartInstance->c6_Pold;
  c6_d_y = NULL;
  if (!chartInstance->c6_Pold_not_empty) {
    sf_mex_assign(&c6_d_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c6_d_y, sf_mex_create("y", &c6_c_u, 0, 0U, 0U, 0U, 0), false);
  }

  sf_mex_setcell(c6_y, 2, c6_d_y);
  c6_d_u = chartInstance->c6_Vold;
  c6_e_y = NULL;
  if (!chartInstance->c6_Vold_not_empty) {
    sf_mex_assign(&c6_e_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c6_e_y, sf_mex_create("y", &c6_d_u, 0, 0U, 0U, 0U, 0), false);
  }

  sf_mex_setcell(c6_y, 3, c6_e_y);
  c6_e_u = chartInstance->c6_is_active_c6_G24i_v_source;
  c6_f_y = NULL;
  sf_mex_assign(&c6_f_y, sf_mex_create("y", &c6_e_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c6_y, 4, c6_f_y);
  sf_mex_assign(&c6_st, c6_y, false);
  return c6_st;
}

static void set_sim_state_c6_G24i_v_source(SFc6_G24i_v_sourceInstanceStruct
  *chartInstance, const mxArray *c6_st)
{
  const mxArray *c6_u;
  real_T *c6_D;
  c6_D = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c6_u = sf_mex_dup(c6_st);
  *c6_D = c6_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c6_u, 0)),
    "D");
  chartInstance->c6_Dold = c6_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c6_u, 1)), "Dold");
  chartInstance->c6_Pold = c6_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c6_u, 2)), "Pold");
  chartInstance->c6_Vold = c6_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c6_u, 3)), "Vold");
  chartInstance->c6_is_active_c6_G24i_v_source = c6_i_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c6_u, 4)),
     "is_active_c6_G24i_v_source");
  sf_mex_destroy(&c6_u);
  sf_mex_destroy(&c6_st);
}

static void finalize_c6_G24i_v_source(SFc6_G24i_v_sourceInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c6_G24i_v_source(SFc6_G24i_v_sourceInstanceStruct
  *chartInstance)
{
  real_T c6_P;
  real_T c6_dV;
  real_T c6_dP;
  real_T *c6_D;
  real_T *c6_V;
  real_T *c6_I;
  real_T *c6_Enabled;
  real_T (*c6_Param)[4];
  c6_I = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c6_V = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c6_Enabled = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c6_D = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c6_Param = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = sf_get_time(chartInstance->S);
  if (!chartInstance->c6_Vold_not_empty) {
    chartInstance->c6_Vold = 0.0;
    chartInstance->c6_Vold_not_empty = true;
    chartInstance->c6_Pold = 0.0;
    chartInstance->c6_Pold_not_empty = true;
    chartInstance->c6_Dold = (*c6_Param)[0];
    chartInstance->c6_Dold_not_empty = true;
  }

  c6_P = *c6_V * *c6_I;
  c6_dV = *c6_V - chartInstance->c6_Vold;
  c6_dP = c6_P - chartInstance->c6_Pold;
  if ((c6_dP != 0.0) && (*c6_Enabled != 0.0)) {
    if (c6_dP < 0.0) {
      if (c6_dV < 0.0) {
        *c6_D = chartInstance->c6_Dold - (*c6_Param)[3];
      } else {
        *c6_D = chartInstance->c6_Dold + (*c6_Param)[3];
      }
    } else if (c6_dV < 0.0) {
      *c6_D = chartInstance->c6_Dold + (*c6_Param)[3];
    } else {
      *c6_D = chartInstance->c6_Dold - (*c6_Param)[3];
    }
  } else {
    *c6_D = chartInstance->c6_Dold;
  }

  if ((*c6_D >= (*c6_Param)[1]) || (*c6_D <= (*c6_Param)[2])) {
    *c6_D = chartInstance->c6_Dold;
  }

  chartInstance->c6_Dold = *c6_D;
  chartInstance->c6_Vold = *c6_V;
  chartInstance->c6_Pold = c6_P;
}

static void initSimStructsc6_G24i_v_source(SFc6_G24i_v_sourceInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c6_machineNumber, uint32_T
  c6_chartNumber, uint32_T c6_instanceNumber)
{
  (void)c6_machineNumber;
  (void)c6_chartNumber;
  (void)c6_instanceNumber;
}

const mxArray *sf_c6_G24i_v_source_get_eml_resolved_functions_info(void)
{
  const mxArray *c6_nameCaptureInfo = NULL;
  c6_nameCaptureInfo = NULL;
  sf_mex_assign(&c6_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c6_nameCaptureInfo;
}

static real_T c6_emlrt_marshallIn(SFc6_G24i_v_sourceInstanceStruct
  *chartInstance, const mxArray *c6_D, const char_T *c6_identifier)
{
  real_T c6_y;
  emlrtMsgIdentifier c6_thisId;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_D), &c6_thisId);
  sf_mex_destroy(&c6_D);
  return c6_y;
}

static real_T c6_b_emlrt_marshallIn(SFc6_G24i_v_sourceInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId)
{
  real_T c6_y;
  real_T c6_d0;
  (void)chartInstance;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), &c6_d0, 1, 0, 0U, 0, 0U, 0);
  c6_y = c6_d0;
  sf_mex_destroy(&c6_u);
  return c6_y;
}

static real_T c6_c_emlrt_marshallIn(SFc6_G24i_v_sourceInstanceStruct
  *chartInstance, const mxArray *c6_b_Dold, const char_T *c6_identifier)
{
  real_T c6_y;
  emlrtMsgIdentifier c6_thisId;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_b_Dold), &c6_thisId);
  sf_mex_destroy(&c6_b_Dold);
  return c6_y;
}

static real_T c6_d_emlrt_marshallIn(SFc6_G24i_v_sourceInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId)
{
  real_T c6_y;
  real_T c6_d1;
  if (mxIsEmpty(c6_u)) {
    chartInstance->c6_Dold_not_empty = false;
  } else {
    chartInstance->c6_Dold_not_empty = true;
    sf_mex_import(c6_parentId, sf_mex_dup(c6_u), &c6_d1, 1, 0, 0U, 0, 0U, 0);
    c6_y = c6_d1;
  }

  sf_mex_destroy(&c6_u);
  return c6_y;
}

static real_T c6_e_emlrt_marshallIn(SFc6_G24i_v_sourceInstanceStruct
  *chartInstance, const mxArray *c6_b_Pold, const char_T *c6_identifier)
{
  real_T c6_y;
  emlrtMsgIdentifier c6_thisId;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_b_Pold), &c6_thisId);
  sf_mex_destroy(&c6_b_Pold);
  return c6_y;
}

static real_T c6_f_emlrt_marshallIn(SFc6_G24i_v_sourceInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId)
{
  real_T c6_y;
  real_T c6_d2;
  if (mxIsEmpty(c6_u)) {
    chartInstance->c6_Pold_not_empty = false;
  } else {
    chartInstance->c6_Pold_not_empty = true;
    sf_mex_import(c6_parentId, sf_mex_dup(c6_u), &c6_d2, 1, 0, 0U, 0, 0U, 0);
    c6_y = c6_d2;
  }

  sf_mex_destroy(&c6_u);
  return c6_y;
}

static real_T c6_g_emlrt_marshallIn(SFc6_G24i_v_sourceInstanceStruct
  *chartInstance, const mxArray *c6_b_Vold, const char_T *c6_identifier)
{
  real_T c6_y;
  emlrtMsgIdentifier c6_thisId;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_b_Vold), &c6_thisId);
  sf_mex_destroy(&c6_b_Vold);
  return c6_y;
}

static real_T c6_h_emlrt_marshallIn(SFc6_G24i_v_sourceInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId)
{
  real_T c6_y;
  real_T c6_d3;
  if (mxIsEmpty(c6_u)) {
    chartInstance->c6_Vold_not_empty = false;
  } else {
    chartInstance->c6_Vold_not_empty = true;
    sf_mex_import(c6_parentId, sf_mex_dup(c6_u), &c6_d3, 1, 0, 0U, 0, 0U, 0);
    c6_y = c6_d3;
  }

  sf_mex_destroy(&c6_u);
  return c6_y;
}

static uint8_T c6_i_emlrt_marshallIn(SFc6_G24i_v_sourceInstanceStruct
  *chartInstance, const mxArray *c6_b_is_active_c6_G24i_v_source, const char_T
  *c6_identifier)
{
  uint8_T c6_y;
  emlrtMsgIdentifier c6_thisId;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_j_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c6_b_is_active_c6_G24i_v_source), &c6_thisId);
  sf_mex_destroy(&c6_b_is_active_c6_G24i_v_source);
  return c6_y;
}

static uint8_T c6_j_emlrt_marshallIn(SFc6_G24i_v_sourceInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId)
{
  uint8_T c6_y;
  uint8_T c6_u0;
  (void)chartInstance;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), &c6_u0, 1, 3, 0U, 0, 0U, 0);
  c6_y = c6_u0;
  sf_mex_destroy(&c6_u);
  return c6_y;
}

static void init_dsm_address_info(SFc6_G24i_v_sourceInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

/* SFunction Glue Code */
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

void sf_c6_G24i_v_source_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(516337011U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1348855820U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1911300709U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2399469623U);
}

mxArray *sf_c6_G24i_v_source_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("4iB5kEzdmIZnh8PgrJ96W");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,4,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(4);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c6_G24i_v_source_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c6_G24i_v_source_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c6_G24i_v_source(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x5'type','srcId','name','auxInfo'{{M[1],M[5],T\"D\",},{M[4],M[0],T\"Dold\",S'l','i','p'{{M1x2[563 567],M[0],}}},{M[4],M[0],T\"Pold\",S'l','i','p'{{M1x2[558 562],M[0],}}},{M[4],M[0],T\"Vold\",S'l','i','p'{{M1x2[553 557],M[0],}}},{M[8],M[0],T\"is_active_c6_G24i_v_source\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 5, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c6_G24i_v_source_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static const char* sf_get_instance_specialization(void)
{
  return "i9B2eOOAszAWqmirP3BOQE";
}

static void sf_opaque_initialize_c6_G24i_v_source(void *chartInstanceVar)
{
  initialize_params_c6_G24i_v_source((SFc6_G24i_v_sourceInstanceStruct*)
    chartInstanceVar);
  initialize_c6_G24i_v_source((SFc6_G24i_v_sourceInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c6_G24i_v_source(void *chartInstanceVar)
{
  enable_c6_G24i_v_source((SFc6_G24i_v_sourceInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c6_G24i_v_source(void *chartInstanceVar)
{
  disable_c6_G24i_v_source((SFc6_G24i_v_sourceInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c6_G24i_v_source(void *chartInstanceVar)
{
  sf_gateway_c6_G24i_v_source((SFc6_G24i_v_sourceInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c6_G24i_v_source(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c6_G24i_v_source
    ((SFc6_G24i_v_sourceInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c6_G24i_v_source();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_raw2high'.\n");
  }

  return plhs[0];
}

extern void sf_internal_set_sim_state_c6_G24i_v_source(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c6_G24i_v_source();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c6_G24i_v_source((SFc6_G24i_v_sourceInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c6_G24i_v_source(SimStruct* S)
{
  return sf_internal_get_sim_state_c6_G24i_v_source(S);
}

static void sf_opaque_set_sim_state_c6_G24i_v_source(SimStruct* S, const mxArray
  *st)
{
  sf_internal_set_sim_state_c6_G24i_v_source(S, st);
}

static void sf_opaque_terminate_c6_G24i_v_source(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc6_G24i_v_sourceInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_G24i_v_source_optimization_info();
    }

    finalize_c6_G24i_v_source((SFc6_G24i_v_sourceInstanceStruct*)
      chartInstanceVar);
    utFree((void *)chartInstanceVar);
    if (crtInfo != NULL) {
      utFree((void *)crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc6_G24i_v_source((SFc6_G24i_v_sourceInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c6_G24i_v_source(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    initialize_params_c6_G24i_v_source((SFc6_G24i_v_sourceInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c6_G24i_v_source(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_G24i_v_source_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,6);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,6,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,6,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,6);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,6,4);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,6,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 4; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,6);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(37965041U));
  ssSetChecksum1(S,(3923149069U));
  ssSetChecksum2(S,(223566589U));
  ssSetChecksum3(S,(633747277U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c6_G24i_v_source(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c6_G24i_v_source(SimStruct *S)
{
  SFc6_G24i_v_sourceInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc6_G24i_v_sourceInstanceStruct *)utMalloc(sizeof
    (SFc6_G24i_v_sourceInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc6_G24i_v_sourceInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c6_G24i_v_source;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c6_G24i_v_source;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c6_G24i_v_source;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c6_G24i_v_source;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c6_G24i_v_source;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c6_G24i_v_source;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c6_G24i_v_source;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c6_G24i_v_source;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c6_G24i_v_source;
  chartInstance->chartInfo.mdlStart = mdlStart_c6_G24i_v_source;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c6_G24i_v_source;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->S = S;
  crtInfo->instanceInfo = (&(chartInstance->chartInfo));
  crtInfo->isJITEnabled = false;
  ssSetUserData(S,(void *)(crtInfo));  /* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
}

void c6_G24i_v_source_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c6_G24i_v_source(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c6_G24i_v_source(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c6_G24i_v_source(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c6_G24i_v_source_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
