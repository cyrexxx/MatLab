/* Include files */

#include <stddef.h>
#include "blas.h"
#include "G24i_buck_boost_sfun.h"
#include "c4_G24i_buck_boost.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(NULL,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;

/* Function Declarations */
static void initialize_c4_G24i_buck_boost(SFc4_G24i_buck_boostInstanceStruct
  *chartInstance);
static void initialize_params_c4_G24i_buck_boost
  (SFc4_G24i_buck_boostInstanceStruct *chartInstance);
static void enable_c4_G24i_buck_boost(SFc4_G24i_buck_boostInstanceStruct
  *chartInstance);
static void disable_c4_G24i_buck_boost(SFc4_G24i_buck_boostInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c4_G24i_buck_boost
  (SFc4_G24i_buck_boostInstanceStruct *chartInstance);
static void set_sim_state_c4_G24i_buck_boost(SFc4_G24i_buck_boostInstanceStruct *
  chartInstance, const mxArray *c4_st);
static void finalize_c4_G24i_buck_boost(SFc4_G24i_buck_boostInstanceStruct
  *chartInstance);
static void sf_gateway_c4_G24i_buck_boost(SFc4_G24i_buck_boostInstanceStruct
  *chartInstance);
static void initSimStructsc4_G24i_buck_boost(SFc4_G24i_buck_boostInstanceStruct *
  chartInstance);
static void init_script_number_translation(uint32_T c4_machineNumber, uint32_T
  c4_chartNumber, uint32_T c4_instanceNumber);
static real_T c4_emlrt_marshallIn(SFc4_G24i_buck_boostInstanceStruct
  *chartInstance, const mxArray *c4_D, const char_T *c4_identifier);
static real_T c4_b_emlrt_marshallIn(SFc4_G24i_buck_boostInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static real_T c4_c_emlrt_marshallIn(SFc4_G24i_buck_boostInstanceStruct
  *chartInstance, const mxArray *c4_b_Dold, const char_T *c4_identifier);
static real_T c4_d_emlrt_marshallIn(SFc4_G24i_buck_boostInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static real_T c4_e_emlrt_marshallIn(SFc4_G24i_buck_boostInstanceStruct
  *chartInstance, const mxArray *c4_b_Pold, const char_T *c4_identifier);
static real_T c4_f_emlrt_marshallIn(SFc4_G24i_buck_boostInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static real_T c4_g_emlrt_marshallIn(SFc4_G24i_buck_boostInstanceStruct
  *chartInstance, const mxArray *c4_b_Vold, const char_T *c4_identifier);
static real_T c4_h_emlrt_marshallIn(SFc4_G24i_buck_boostInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static uint8_T c4_i_emlrt_marshallIn(SFc4_G24i_buck_boostInstanceStruct
  *chartInstance, const mxArray *c4_b_is_active_c4_G24i_buck_boost, const char_T
  *c4_identifier);
static uint8_T c4_j_emlrt_marshallIn(SFc4_G24i_buck_boostInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void init_dsm_address_info(SFc4_G24i_buck_boostInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c4_G24i_buck_boost(SFc4_G24i_buck_boostInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c4_Vold_not_empty = false;
  chartInstance->c4_Pold_not_empty = false;
  chartInstance->c4_Dold_not_empty = false;
  chartInstance->c4_is_active_c4_G24i_buck_boost = 0U;
}

static void initialize_params_c4_G24i_buck_boost
  (SFc4_G24i_buck_boostInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c4_G24i_buck_boost(SFc4_G24i_buck_boostInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c4_G24i_buck_boost(SFc4_G24i_buck_boostInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static const mxArray *get_sim_state_c4_G24i_buck_boost
  (SFc4_G24i_buck_boostInstanceStruct *chartInstance)
{
  const mxArray *c4_st;
  const mxArray *c4_y = NULL;
  real_T c4_u;
  const mxArray *c4_b_y = NULL;
  real_T c4_b_u;
  const mxArray *c4_c_y = NULL;
  real_T c4_c_u;
  const mxArray *c4_d_y = NULL;
  real_T c4_d_u;
  const mxArray *c4_e_y = NULL;
  uint8_T c4_e_u;
  const mxArray *c4_f_y = NULL;
  real_T *c4_D;
  c4_D = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c4_st = NULL;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_createcellmatrix(5, 1), false);
  c4_u = *c4_D;
  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", &c4_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c4_y, 0, c4_b_y);
  c4_b_u = chartInstance->c4_Dold;
  c4_c_y = NULL;
  if (!chartInstance->c4_Dold_not_empty) {
    sf_mex_assign(&c4_c_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c4_c_y, sf_mex_create("y", &c4_b_u, 0, 0U, 0U, 0U, 0), false);
  }

  sf_mex_setcell(c4_y, 1, c4_c_y);
  c4_c_u = chartInstance->c4_Pold;
  c4_d_y = NULL;
  if (!chartInstance->c4_Pold_not_empty) {
    sf_mex_assign(&c4_d_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c4_d_y, sf_mex_create("y", &c4_c_u, 0, 0U, 0U, 0U, 0), false);
  }

  sf_mex_setcell(c4_y, 2, c4_d_y);
  c4_d_u = chartInstance->c4_Vold;
  c4_e_y = NULL;
  if (!chartInstance->c4_Vold_not_empty) {
    sf_mex_assign(&c4_e_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c4_e_y, sf_mex_create("y", &c4_d_u, 0, 0U, 0U, 0U, 0), false);
  }

  sf_mex_setcell(c4_y, 3, c4_e_y);
  c4_e_u = chartInstance->c4_is_active_c4_G24i_buck_boost;
  c4_f_y = NULL;
  sf_mex_assign(&c4_f_y, sf_mex_create("y", &c4_e_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c4_y, 4, c4_f_y);
  sf_mex_assign(&c4_st, c4_y, false);
  return c4_st;
}

static void set_sim_state_c4_G24i_buck_boost(SFc4_G24i_buck_boostInstanceStruct *
  chartInstance, const mxArray *c4_st)
{
  const mxArray *c4_u;
  real_T *c4_D;
  c4_D = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c4_u = sf_mex_dup(c4_st);
  *c4_D = c4_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 0)),
    "D");
  chartInstance->c4_Dold = c4_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c4_u, 1)), "Dold");
  chartInstance->c4_Pold = c4_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c4_u, 2)), "Pold");
  chartInstance->c4_Vold = c4_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c4_u, 3)), "Vold");
  chartInstance->c4_is_active_c4_G24i_buck_boost = c4_i_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 4)),
     "is_active_c4_G24i_buck_boost");
  sf_mex_destroy(&c4_u);
  sf_mex_destroy(&c4_st);
}

static void finalize_c4_G24i_buck_boost(SFc4_G24i_buck_boostInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c4_G24i_buck_boost(SFc4_G24i_buck_boostInstanceStruct
  *chartInstance)
{
  real_T c4_P;
  real_T c4_dV;
  real_T c4_dP;
  real_T *c4_D;
  real_T *c4_V;
  real_T *c4_I;
  real_T *c4_Enabled;
  real_T (*c4_Param)[4];
  c4_D = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c4_I = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c4_V = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c4_Enabled = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c4_Param = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = sf_get_time(chartInstance->S);
  if (!chartInstance->c4_Vold_not_empty) {
    chartInstance->c4_Vold = 0.0;
    chartInstance->c4_Vold_not_empty = true;
    chartInstance->c4_Pold = 0.0;
    chartInstance->c4_Pold_not_empty = true;
    chartInstance->c4_Dold = (*c4_Param)[0];
    chartInstance->c4_Dold_not_empty = true;
  }

  c4_P = *c4_V * *c4_I;
  c4_dV = *c4_V - chartInstance->c4_Vold;
  c4_dP = c4_P - chartInstance->c4_Pold;
  if ((c4_dP != 0.0) && (*c4_Enabled != 0.0)) {
    if (c4_dP < 0.0) {
      if (c4_dV < 0.0) {
        *c4_D = chartInstance->c4_Dold - (*c4_Param)[3];
      } else {
        *c4_D = chartInstance->c4_Dold + (*c4_Param)[3];
      }
    } else if (c4_dV < 0.0) {
      *c4_D = chartInstance->c4_Dold + (*c4_Param)[3];
    } else {
      *c4_D = chartInstance->c4_Dold - (*c4_Param)[3];
    }
  } else {
    *c4_D = chartInstance->c4_Dold;
  }

  if ((*c4_D >= (*c4_Param)[1]) || (*c4_D <= (*c4_Param)[2])) {
    *c4_D = chartInstance->c4_Dold;
  }

  chartInstance->c4_Dold = *c4_D;
  chartInstance->c4_Vold = *c4_V;
  chartInstance->c4_Pold = c4_P;
}

static void initSimStructsc4_G24i_buck_boost(SFc4_G24i_buck_boostInstanceStruct *
  chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c4_machineNumber, uint32_T
  c4_chartNumber, uint32_T c4_instanceNumber)
{
  (void)c4_machineNumber;
  (void)c4_chartNumber;
  (void)c4_instanceNumber;
}

const mxArray *sf_c4_G24i_buck_boost_get_eml_resolved_functions_info(void)
{
  const mxArray *c4_nameCaptureInfo = NULL;
  c4_nameCaptureInfo = NULL;
  sf_mex_assign(&c4_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c4_nameCaptureInfo;
}

static real_T c4_emlrt_marshallIn(SFc4_G24i_buck_boostInstanceStruct
  *chartInstance, const mxArray *c4_D, const char_T *c4_identifier)
{
  real_T c4_y;
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_D), &c4_thisId);
  sf_mex_destroy(&c4_D);
  return c4_y;
}

static real_T c4_b_emlrt_marshallIn(SFc4_G24i_buck_boostInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  real_T c4_y;
  real_T c4_d0;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_d0, 1, 0, 0U, 0, 0U, 0);
  c4_y = c4_d0;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static real_T c4_c_emlrt_marshallIn(SFc4_G24i_buck_boostInstanceStruct
  *chartInstance, const mxArray *c4_b_Dold, const char_T *c4_identifier)
{
  real_T c4_y;
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_Dold), &c4_thisId);
  sf_mex_destroy(&c4_b_Dold);
  return c4_y;
}

static real_T c4_d_emlrt_marshallIn(SFc4_G24i_buck_boostInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  real_T c4_y;
  real_T c4_d1;
  if (mxIsEmpty(c4_u)) {
    chartInstance->c4_Dold_not_empty = false;
  } else {
    chartInstance->c4_Dold_not_empty = true;
    sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_d1, 1, 0, 0U, 0, 0U, 0);
    c4_y = c4_d1;
  }

  sf_mex_destroy(&c4_u);
  return c4_y;
}

static real_T c4_e_emlrt_marshallIn(SFc4_G24i_buck_boostInstanceStruct
  *chartInstance, const mxArray *c4_b_Pold, const char_T *c4_identifier)
{
  real_T c4_y;
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_Pold), &c4_thisId);
  sf_mex_destroy(&c4_b_Pold);
  return c4_y;
}

static real_T c4_f_emlrt_marshallIn(SFc4_G24i_buck_boostInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  real_T c4_y;
  real_T c4_d2;
  if (mxIsEmpty(c4_u)) {
    chartInstance->c4_Pold_not_empty = false;
  } else {
    chartInstance->c4_Pold_not_empty = true;
    sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_d2, 1, 0, 0U, 0, 0U, 0);
    c4_y = c4_d2;
  }

  sf_mex_destroy(&c4_u);
  return c4_y;
}

static real_T c4_g_emlrt_marshallIn(SFc4_G24i_buck_boostInstanceStruct
  *chartInstance, const mxArray *c4_b_Vold, const char_T *c4_identifier)
{
  real_T c4_y;
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_Vold), &c4_thisId);
  sf_mex_destroy(&c4_b_Vold);
  return c4_y;
}

static real_T c4_h_emlrt_marshallIn(SFc4_G24i_buck_boostInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  real_T c4_y;
  real_T c4_d3;
  if (mxIsEmpty(c4_u)) {
    chartInstance->c4_Vold_not_empty = false;
  } else {
    chartInstance->c4_Vold_not_empty = true;
    sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_d3, 1, 0, 0U, 0, 0U, 0);
    c4_y = c4_d3;
  }

  sf_mex_destroy(&c4_u);
  return c4_y;
}

static uint8_T c4_i_emlrt_marshallIn(SFc4_G24i_buck_boostInstanceStruct
  *chartInstance, const mxArray *c4_b_is_active_c4_G24i_buck_boost, const char_T
  *c4_identifier)
{
  uint8_T c4_y;
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_j_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c4_b_is_active_c4_G24i_buck_boost), &c4_thisId);
  sf_mex_destroy(&c4_b_is_active_c4_G24i_buck_boost);
  return c4_y;
}

static uint8_T c4_j_emlrt_marshallIn(SFc4_G24i_buck_boostInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  uint8_T c4_y;
  uint8_T c4_u0;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_u0, 1, 3, 0U, 0, 0U, 0);
  c4_y = c4_u0;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void init_dsm_address_info(SFc4_G24i_buck_boostInstanceStruct
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

void sf_c4_G24i_buck_boost_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(548939089U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2313477252U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1216138104U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3404803866U);
}

mxArray *sf_c4_G24i_buck_boost_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("MbSope2LdizvJNdGwdPq7D");
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

mxArray *sf_c4_G24i_buck_boost_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c4_G24i_buck_boost_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c4_G24i_buck_boost(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x5'type','srcId','name','auxInfo'{{M[1],M[5],T\"D\",},{M[4],M[0],T\"Dold\",S'l','i','p'{{M1x2[563 567],M[0],}}},{M[4],M[0],T\"Pold\",S'l','i','p'{{M1x2[558 562],M[0],}}},{M[4],M[0],T\"Vold\",S'l','i','p'{{M1x2[553 557],M[0],}}},{M[8],M[0],T\"is_active_c4_G24i_buck_boost\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 5, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c4_G24i_buck_boost_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static const char* sf_get_instance_specialization(void)
{
  return "cxeys2rqhuVMYaRtIMeStD";
}

static void sf_opaque_initialize_c4_G24i_buck_boost(void *chartInstanceVar)
{
  initialize_params_c4_G24i_buck_boost((SFc4_G24i_buck_boostInstanceStruct*)
    chartInstanceVar);
  initialize_c4_G24i_buck_boost((SFc4_G24i_buck_boostInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c4_G24i_buck_boost(void *chartInstanceVar)
{
  enable_c4_G24i_buck_boost((SFc4_G24i_buck_boostInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c4_G24i_buck_boost(void *chartInstanceVar)
{
  disable_c4_G24i_buck_boost((SFc4_G24i_buck_boostInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c4_G24i_buck_boost(void *chartInstanceVar)
{
  sf_gateway_c4_G24i_buck_boost((SFc4_G24i_buck_boostInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c4_G24i_buck_boost(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c4_G24i_buck_boost
    ((SFc4_G24i_buck_boostInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c4_G24i_buck_boost();/* state var info */
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

extern void sf_internal_set_sim_state_c4_G24i_buck_boost(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c4_G24i_buck_boost();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c4_G24i_buck_boost((SFc4_G24i_buck_boostInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c4_G24i_buck_boost(SimStruct* S)
{
  return sf_internal_get_sim_state_c4_G24i_buck_boost(S);
}

static void sf_opaque_set_sim_state_c4_G24i_buck_boost(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c4_G24i_buck_boost(S, st);
}

static void sf_opaque_terminate_c4_G24i_buck_boost(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc4_G24i_buck_boostInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_G24i_buck_boost_optimization_info();
    }

    finalize_c4_G24i_buck_boost((SFc4_G24i_buck_boostInstanceStruct*)
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
  initSimStructsc4_G24i_buck_boost((SFc4_G24i_buck_boostInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c4_G24i_buck_boost(SimStruct *S)
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
    initialize_params_c4_G24i_buck_boost((SFc4_G24i_buck_boostInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c4_G24i_buck_boost(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_G24i_buck_boost_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,4);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,4,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,4,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,4);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,4,4);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,4,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,4);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2032985118U));
  ssSetChecksum1(S,(3403173721U));
  ssSetChecksum2(S,(525460481U));
  ssSetChecksum3(S,(960710661U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c4_G24i_buck_boost(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c4_G24i_buck_boost(SimStruct *S)
{
  SFc4_G24i_buck_boostInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc4_G24i_buck_boostInstanceStruct *)utMalloc(sizeof
    (SFc4_G24i_buck_boostInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc4_G24i_buck_boostInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c4_G24i_buck_boost;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c4_G24i_buck_boost;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c4_G24i_buck_boost;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c4_G24i_buck_boost;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c4_G24i_buck_boost;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c4_G24i_buck_boost;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c4_G24i_buck_boost;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c4_G24i_buck_boost;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c4_G24i_buck_boost;
  chartInstance->chartInfo.mdlStart = mdlStart_c4_G24i_buck_boost;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c4_G24i_buck_boost;
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

void c4_G24i_buck_boost_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c4_G24i_buck_boost(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c4_G24i_buck_boost(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c4_G24i_buck_boost(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c4_G24i_buck_boost_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
