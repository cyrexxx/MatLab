/* Include files */

#include <stddef.h>
#include "blas.h"
#include "G24i_buck_boost_sfun.h"
#include "c2_G24i_buck_boost.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "G24i_buck_boost_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c2_debug_family_names[17] = { "Dinit", "Dmax", "Dmin",
  "deltaD", "P", "dV", "dP", "nargin", "nargout", "Param", "Enabled", "V", "I",
  "D", "Vold", "Pold", "Dold" };

/* Function Declarations */
static void initialize_c2_G24i_buck_boost(SFc2_G24i_buck_boostInstanceStruct
  *chartInstance);
static void initialize_params_c2_G24i_buck_boost
  (SFc2_G24i_buck_boostInstanceStruct *chartInstance);
static void enable_c2_G24i_buck_boost(SFc2_G24i_buck_boostInstanceStruct
  *chartInstance);
static void disable_c2_G24i_buck_boost(SFc2_G24i_buck_boostInstanceStruct
  *chartInstance);
static void c2_update_debugger_state_c2_G24i_buck_boost
  (SFc2_G24i_buck_boostInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c2_G24i_buck_boost
  (SFc2_G24i_buck_boostInstanceStruct *chartInstance);
static void set_sim_state_c2_G24i_buck_boost(SFc2_G24i_buck_boostInstanceStruct *
  chartInstance, const mxArray *c2_st);
static void finalize_c2_G24i_buck_boost(SFc2_G24i_buck_boostInstanceStruct
  *chartInstance);
static void sf_gateway_c2_G24i_buck_boost(SFc2_G24i_buck_boostInstanceStruct
  *chartInstance);
static void initSimStructsc2_G24i_buck_boost(SFc2_G24i_buck_boostInstanceStruct *
  chartInstance);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber, uint32_T c2_instanceNumber);
static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData);
static real_T c2_emlrt_marshallIn(SFc2_G24i_buck_boostInstanceStruct
  *chartInstance, const mxArray *c2_b_Dold, const char_T *c2_identifier);
static real_T c2_b_emlrt_marshallIn(SFc2_G24i_buck_boostInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static real_T c2_c_emlrt_marshallIn(SFc2_G24i_buck_boostInstanceStruct
  *chartInstance, const mxArray *c2_b_Pold, const char_T *c2_identifier);
static real_T c2_d_emlrt_marshallIn(SFc2_G24i_buck_boostInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static real_T c2_e_emlrt_marshallIn(SFc2_G24i_buck_boostInstanceStruct
  *chartInstance, const mxArray *c2_b_Vold, const char_T *c2_identifier);
static real_T c2_f_emlrt_marshallIn(SFc2_G24i_buck_boostInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static real_T c2_g_emlrt_marshallIn(SFc2_G24i_buck_boostInstanceStruct
  *chartInstance, const mxArray *c2_D, const char_T *c2_identifier);
static real_T c2_h_emlrt_marshallIn(SFc2_G24i_buck_boostInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_e_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static const mxArray *c2_f_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static int32_T c2_i_emlrt_marshallIn(SFc2_G24i_buck_boostInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static uint8_T c2_j_emlrt_marshallIn(SFc2_G24i_buck_boostInstanceStruct
  *chartInstance, const mxArray *c2_b_is_active_c2_G24i_buck_boost, const char_T
  *c2_identifier);
static uint8_T c2_k_emlrt_marshallIn(SFc2_G24i_buck_boostInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void init_dsm_address_info(SFc2_G24i_buck_boostInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c2_G24i_buck_boost(SFc2_G24i_buck_boostInstanceStruct
  *chartInstance)
{
  chartInstance->c2_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c2_Vold_not_empty = false;
  chartInstance->c2_Pold_not_empty = false;
  chartInstance->c2_Dold_not_empty = false;
  chartInstance->c2_is_active_c2_G24i_buck_boost = 0U;
}

static void initialize_params_c2_G24i_buck_boost
  (SFc2_G24i_buck_boostInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c2_G24i_buck_boost(SFc2_G24i_buck_boostInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c2_G24i_buck_boost(SFc2_G24i_buck_boostInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c2_update_debugger_state_c2_G24i_buck_boost
  (SFc2_G24i_buck_boostInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c2_G24i_buck_boost
  (SFc2_G24i_buck_boostInstanceStruct *chartInstance)
{
  const mxArray *c2_st;
  const mxArray *c2_y = NULL;
  real_T c2_hoistedGlobal;
  real_T c2_u;
  const mxArray *c2_b_y = NULL;
  real_T c2_b_hoistedGlobal;
  real_T c2_b_u;
  const mxArray *c2_c_y = NULL;
  real_T c2_c_hoistedGlobal;
  real_T c2_c_u;
  const mxArray *c2_d_y = NULL;
  real_T c2_d_hoistedGlobal;
  real_T c2_d_u;
  const mxArray *c2_e_y = NULL;
  uint8_T c2_e_hoistedGlobal;
  uint8_T c2_e_u;
  const mxArray *c2_f_y = NULL;
  real_T *c2_D;
  c2_D = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c2_st = NULL;
  c2_st = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createcellmatrix(5, 1), false);
  c2_hoistedGlobal = *c2_D;
  c2_u = c2_hoistedGlobal;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c2_y, 0, c2_b_y);
  c2_b_hoistedGlobal = chartInstance->c2_Dold;
  c2_b_u = c2_b_hoistedGlobal;
  c2_c_y = NULL;
  if (!chartInstance->c2_Dold_not_empty) {
    sf_mex_assign(&c2_c_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c2_c_y, sf_mex_create("y", &c2_b_u, 0, 0U, 0U, 0U, 0), false);
  }

  sf_mex_setcell(c2_y, 1, c2_c_y);
  c2_c_hoistedGlobal = chartInstance->c2_Pold;
  c2_c_u = c2_c_hoistedGlobal;
  c2_d_y = NULL;
  if (!chartInstance->c2_Pold_not_empty) {
    sf_mex_assign(&c2_d_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c2_d_y, sf_mex_create("y", &c2_c_u, 0, 0U, 0U, 0U, 0), false);
  }

  sf_mex_setcell(c2_y, 2, c2_d_y);
  c2_d_hoistedGlobal = chartInstance->c2_Vold;
  c2_d_u = c2_d_hoistedGlobal;
  c2_e_y = NULL;
  if (!chartInstance->c2_Vold_not_empty) {
    sf_mex_assign(&c2_e_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c2_e_y, sf_mex_create("y", &c2_d_u, 0, 0U, 0U, 0U, 0), false);
  }

  sf_mex_setcell(c2_y, 3, c2_e_y);
  c2_e_hoistedGlobal = chartInstance->c2_is_active_c2_G24i_buck_boost;
  c2_e_u = c2_e_hoistedGlobal;
  c2_f_y = NULL;
  sf_mex_assign(&c2_f_y, sf_mex_create("y", &c2_e_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c2_y, 4, c2_f_y);
  sf_mex_assign(&c2_st, c2_y, false);
  return c2_st;
}

static void set_sim_state_c2_G24i_buck_boost(SFc2_G24i_buck_boostInstanceStruct *
  chartInstance, const mxArray *c2_st)
{
  const mxArray *c2_u;
  real_T *c2_D;
  c2_D = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c2_doneDoubleBufferReInit = true;
  c2_u = sf_mex_dup(c2_st);
  *c2_D = c2_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 0)),
    "D");
  chartInstance->c2_Dold = c2_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c2_u, 1)), "Dold");
  chartInstance->c2_Pold = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c2_u, 2)), "Pold");
  chartInstance->c2_Vold = c2_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c2_u, 3)), "Vold");
  chartInstance->c2_is_active_c2_G24i_buck_boost = c2_j_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 4)),
     "is_active_c2_G24i_buck_boost");
  sf_mex_destroy(&c2_u);
  c2_update_debugger_state_c2_G24i_buck_boost(chartInstance);
  sf_mex_destroy(&c2_st);
}

static void finalize_c2_G24i_buck_boost(SFc2_G24i_buck_boostInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c2_G24i_buck_boost(SFc2_G24i_buck_boostInstanceStruct
  *chartInstance)
{
  int32_T c2_i0;
  real_T c2_hoistedGlobal;
  real_T c2_b_hoistedGlobal;
  real_T c2_c_hoistedGlobal;
  int32_T c2_i1;
  real_T c2_Param[4];
  real_T c2_Enabled;
  real_T c2_V;
  real_T c2_I;
  uint32_T c2_debug_family_var_map[17];
  real_T c2_Dinit;
  real_T c2_Dmax;
  real_T c2_Dmin;
  real_T c2_deltaD;
  real_T c2_P;
  real_T c2_dV;
  real_T c2_dP;
  real_T c2_nargin = 4.0;
  real_T c2_nargout = 1.0;
  real_T c2_D;
  real_T *c2_b_D;
  real_T *c2_b_Enabled;
  real_T *c2_b_V;
  real_T *c2_b_I;
  real_T (*c2_b_Param)[4];
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  c2_b_I = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c2_b_V = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c2_b_Enabled = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c2_b_D = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c2_b_Param = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
  for (c2_i0 = 0; c2_i0 < 4; c2_i0++) {
    _SFD_DATA_RANGE_CHECK((*c2_b_Param)[c2_i0], 0U);
  }

  chartInstance->c2_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
  c2_hoistedGlobal = *c2_b_Enabled;
  c2_b_hoistedGlobal = *c2_b_V;
  c2_c_hoistedGlobal = *c2_b_I;
  for (c2_i1 = 0; c2_i1 < 4; c2_i1++) {
    c2_Param[c2_i1] = (*c2_b_Param)[c2_i1];
  }

  c2_Enabled = c2_hoistedGlobal;
  c2_V = c2_b_hoistedGlobal;
  c2_I = c2_c_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 17U, 17U, c2_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_Dinit, 0U, c2_d_sf_marshallOut,
    c2_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_Dmax, 1U, c2_d_sf_marshallOut,
    c2_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_Dmin, 2U, c2_d_sf_marshallOut,
    c2_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_deltaD, 3U, c2_d_sf_marshallOut,
    c2_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_P, 4U, c2_d_sf_marshallOut,
    c2_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_dV, 5U, c2_d_sf_marshallOut,
    c2_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_dP, 6U, c2_d_sf_marshallOut,
    c2_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 7U, c2_d_sf_marshallOut,
    c2_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 8U, c2_d_sf_marshallOut,
    c2_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_Param, 9U, c2_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_Enabled, 10U, c2_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_V, 11U, c2_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_I, 12U, c2_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_D, 13U, c2_d_sf_marshallOut,
    c2_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&chartInstance->c2_Vold, 14U,
    c2_c_sf_marshallOut, c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&chartInstance->c2_Pold, 15U,
    c2_b_sf_marshallOut, c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&chartInstance->c2_Dold, 16U,
    c2_sf_marshallOut, c2_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 12);
  c2_Dinit = c2_Param[0];
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 13);
  c2_Dmax = c2_Param[1];
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 14);
  c2_Dmin = c2_Param[2];
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 15);
  c2_deltaD = c2_Param[3];
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 19);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 23);
  if (CV_EML_IF(0, 1, 0, !chartInstance->c2_Vold_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 24);
    chartInstance->c2_Vold = 0.0;
    chartInstance->c2_Vold_not_empty = true;
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 25);
    chartInstance->c2_Pold = 0.0;
    chartInstance->c2_Pold_not_empty = true;
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 26);
    chartInstance->c2_Dold = c2_Dinit;
    chartInstance->c2_Dold_not_empty = true;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 29);
  c2_P = c2_V * c2_I;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 30);
  c2_dV = c2_V - chartInstance->c2_Vold;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 31);
  c2_dP = c2_P - chartInstance->c2_Pold;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 33);
  guard2 = false;
  if (CV_EML_COND(0, 1, 0, c2_dP != 0.0)) {
    if (CV_EML_COND(0, 1, 1, c2_Enabled != 0.0)) {
      CV_EML_MCDC(0, 1, 0, true);
      CV_EML_IF(0, 1, 1, true);
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 34);
      if (CV_EML_IF(0, 1, 2, c2_dP < 0.0)) {
        _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 35);
        if (CV_EML_IF(0, 1, 3, c2_dV < 0.0)) {
          _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 36);
          c2_D = chartInstance->c2_Dold + c2_deltaD;
        } else {
          _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 38);
          c2_D = chartInstance->c2_Dold - c2_deltaD;
        }
      } else {
        _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 41);
        if (CV_EML_IF(0, 1, 4, c2_dV < 0.0)) {
          _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 42);
          c2_D = chartInstance->c2_Dold + c2_deltaD;
        } else {
          _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 44);
          c2_D = chartInstance->c2_Dold - c2_deltaD;
        }
      }
    } else {
      guard2 = true;
    }
  } else {
    guard2 = true;
  }

  if (guard2 == true) {
    CV_EML_MCDC(0, 1, 0, false);
    CV_EML_IF(0, 1, 1, false);
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 47);
    c2_D = chartInstance->c2_Dold;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 50);
  guard1 = false;
  if (CV_EML_COND(0, 1, 2, c2_D >= c2_Dmax)) {
    guard1 = true;
  } else if (CV_EML_COND(0, 1, 3, c2_D <= c2_Dmin)) {
    guard1 = true;
  } else {
    CV_EML_MCDC(0, 1, 1, false);
    CV_EML_IF(0, 1, 5, false);
  }

  if (guard1 == true) {
    CV_EML_MCDC(0, 1, 1, true);
    CV_EML_IF(0, 1, 5, true);
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 51);
    c2_D = chartInstance->c2_Dold;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 54);
  chartInstance->c2_Dold = c2_D;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 55);
  chartInstance->c2_Vold = c2_V;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 56);
  chartInstance->c2_Pold = c2_P;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, -56);
  _SFD_SYMBOL_SCOPE_POP();
  *c2_b_D = c2_D;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_G24i_buck_boostMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  _SFD_DATA_RANGE_CHECK(*c2_b_D, 1U);
  _SFD_DATA_RANGE_CHECK(*c2_b_Enabled, 2U);
  _SFD_DATA_RANGE_CHECK(*c2_b_V, 3U);
  _SFD_DATA_RANGE_CHECK(*c2_b_I, 4U);
}

static void initSimStructsc2_G24i_buck_boost(SFc2_G24i_buck_boostInstanceStruct *
  chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber, uint32_T c2_instanceNumber)
{
  (void)c2_machineNumber;
  (void)c2_chartNumber;
  (void)c2_instanceNumber;
}

static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  real_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_G24i_buck_boostInstanceStruct *chartInstance;
  chartInstance = (SFc2_G24i_buck_boostInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  if (!chartInstance->c2_Dold_not_empty) {
    sf_mex_assign(&c2_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), false);
  } else {
    sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), false);
  }

  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static real_T c2_emlrt_marshallIn(SFc2_G24i_buck_boostInstanceStruct
  *chartInstance, const mxArray *c2_b_Dold, const char_T *c2_identifier)
{
  real_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_Dold), &c2_thisId);
  sf_mex_destroy(&c2_b_Dold);
  return c2_y;
}

static real_T c2_b_emlrt_marshallIn(SFc2_G24i_buck_boostInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d0;
  if (mxIsEmpty(c2_u)) {
    chartInstance->c2_Dold_not_empty = false;
  } else {
    chartInstance->c2_Dold_not_empty = true;
    sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d0, 1, 0, 0U, 0, 0U, 0);
    c2_y = c2_d0;
  }

  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_Dold;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_G24i_buck_boostInstanceStruct *chartInstance;
  chartInstance = (SFc2_G24i_buck_boostInstanceStruct *)chartInstanceVoid;
  c2_b_Dold = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_Dold), &c2_thisId);
  sf_mex_destroy(&c2_b_Dold);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  real_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_G24i_buck_boostInstanceStruct *chartInstance;
  chartInstance = (SFc2_G24i_buck_boostInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  if (!chartInstance->c2_Pold_not_empty) {
    sf_mex_assign(&c2_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), false);
  } else {
    sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), false);
  }

  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static real_T c2_c_emlrt_marshallIn(SFc2_G24i_buck_boostInstanceStruct
  *chartInstance, const mxArray *c2_b_Pold, const char_T *c2_identifier)
{
  real_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_Pold), &c2_thisId);
  sf_mex_destroy(&c2_b_Pold);
  return c2_y;
}

static real_T c2_d_emlrt_marshallIn(SFc2_G24i_buck_boostInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d1;
  if (mxIsEmpty(c2_u)) {
    chartInstance->c2_Pold_not_empty = false;
  } else {
    chartInstance->c2_Pold_not_empty = true;
    sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d1, 1, 0, 0U, 0, 0U, 0);
    c2_y = c2_d1;
  }

  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_Pold;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_G24i_buck_boostInstanceStruct *chartInstance;
  chartInstance = (SFc2_G24i_buck_boostInstanceStruct *)chartInstanceVoid;
  c2_b_Pold = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_Pold), &c2_thisId);
  sf_mex_destroy(&c2_b_Pold);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  real_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_G24i_buck_boostInstanceStruct *chartInstance;
  chartInstance = (SFc2_G24i_buck_boostInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  if (!chartInstance->c2_Vold_not_empty) {
    sf_mex_assign(&c2_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), false);
  } else {
    sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), false);
  }

  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static real_T c2_e_emlrt_marshallIn(SFc2_G24i_buck_boostInstanceStruct
  *chartInstance, const mxArray *c2_b_Vold, const char_T *c2_identifier)
{
  real_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_Vold), &c2_thisId);
  sf_mex_destroy(&c2_b_Vold);
  return c2_y;
}

static real_T c2_f_emlrt_marshallIn(SFc2_G24i_buck_boostInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d2;
  if (mxIsEmpty(c2_u)) {
    chartInstance->c2_Vold_not_empty = false;
  } else {
    chartInstance->c2_Vold_not_empty = true;
    sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d2, 1, 0, 0U, 0, 0U, 0);
    c2_y = c2_d2;
  }

  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_Vold;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_G24i_buck_boostInstanceStruct *chartInstance;
  chartInstance = (SFc2_G24i_buck_boostInstanceStruct *)chartInstanceVoid;
  c2_b_Vold = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_Vold), &c2_thisId);
  sf_mex_destroy(&c2_b_Vold);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  real_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_G24i_buck_boostInstanceStruct *chartInstance;
  chartInstance = (SFc2_G24i_buck_boostInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static real_T c2_g_emlrt_marshallIn(SFc2_G24i_buck_boostInstanceStruct
  *chartInstance, const mxArray *c2_D, const char_T *c2_identifier)
{
  real_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_D), &c2_thisId);
  sf_mex_destroy(&c2_D);
  return c2_y;
}

static real_T c2_h_emlrt_marshallIn(SFc2_G24i_buck_boostInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d3;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d3, 1, 0, 0U, 0, 0U, 0);
  c2_y = c2_d3;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_D;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_G24i_buck_boostInstanceStruct *chartInstance;
  chartInstance = (SFc2_G24i_buck_boostInstanceStruct *)chartInstanceVoid;
  c2_D = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_D), &c2_thisId);
  sf_mex_destroy(&c2_D);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_e_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i2;
  real_T c2_b_inData[4];
  int32_T c2_i3;
  real_T c2_u[4];
  const mxArray *c2_y = NULL;
  SFc2_G24i_buck_boostInstanceStruct *chartInstance;
  chartInstance = (SFc2_G24i_buck_boostInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i2 = 0; c2_i2 < 4; c2_i2++) {
    c2_b_inData[c2_i2] = (*(real_T (*)[4])c2_inData)[c2_i2];
  }

  for (c2_i3 = 0; c2_i3 < 4; c2_i3++) {
    c2_u[c2_i3] = c2_b_inData[c2_i3];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 1, 4), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

const mxArray *sf_c2_G24i_buck_boost_get_eml_resolved_functions_info(void)
{
  const mxArray *c2_nameCaptureInfo = NULL;
  c2_nameCaptureInfo = NULL;
  sf_mex_assign(&c2_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c2_nameCaptureInfo;
}

static const mxArray *c2_f_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_G24i_buck_boostInstanceStruct *chartInstance;
  chartInstance = (SFc2_G24i_buck_boostInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(int32_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static int32_T c2_i_emlrt_marshallIn(SFc2_G24i_buck_boostInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  int32_T c2_y;
  int32_T c2_i4;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_i4, 1, 6, 0U, 0, 0U, 0);
  c2_y = c2_i4;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_sfEvent;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  int32_T c2_y;
  SFc2_G24i_buck_boostInstanceStruct *chartInstance;
  chartInstance = (SFc2_G24i_buck_boostInstanceStruct *)chartInstanceVoid;
  c2_b_sfEvent = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_sfEvent),
    &c2_thisId);
  sf_mex_destroy(&c2_b_sfEvent);
  *(int32_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static uint8_T c2_j_emlrt_marshallIn(SFc2_G24i_buck_boostInstanceStruct
  *chartInstance, const mxArray *c2_b_is_active_c2_G24i_buck_boost, const char_T
  *c2_identifier)
{
  uint8_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_k_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c2_b_is_active_c2_G24i_buck_boost), &c2_thisId);
  sf_mex_destroy(&c2_b_is_active_c2_G24i_buck_boost);
  return c2_y;
}

static uint8_T c2_k_emlrt_marshallIn(SFc2_G24i_buck_boostInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  uint8_T c2_y;
  uint8_T c2_u0;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_u0, 1, 3, 0U, 0, 0U, 0);
  c2_y = c2_u0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void init_dsm_address_info(SFc2_G24i_buck_boostInstanceStruct
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

void sf_c2_G24i_buck_boost_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2531637755U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(94406677U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(938317899U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1357805072U);
}

mxArray *sf_c2_G24i_buck_boost_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("YlGSy49vyMdr2uMF3zQ86B");
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

mxArray *sf_c2_G24i_buck_boost_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c2_G24i_buck_boost_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c2_G24i_buck_boost(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x5'type','srcId','name','auxInfo'{{M[1],M[5],T\"D\",},{M[4],M[0],T\"Dold\",S'l','i','p'{{M1x2[566 570],M[0],}}},{M[4],M[0],T\"Pold\",S'l','i','p'{{M1x2[561 565],M[0],}}},{M[4],M[0],T\"Vold\",S'l','i','p'{{M1x2[556 560],M[0],}}},{M[8],M[0],T\"is_active_c2_G24i_buck_boost\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 5, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_G24i_buck_boost_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_G24i_buck_boostInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc2_G24i_buck_boostInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _G24i_buck_boostMachineNumber_,
           2,
           1,
           1,
           0,
           5,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize ist own list of scripts */
        init_script_number_translation(_G24i_buck_boostMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_G24i_buck_boostMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _G24i_buck_boostMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"Param");
          _SFD_SET_DATA_PROPS(1,2,0,1,"D");
          _SFD_SET_DATA_PROPS(2,1,1,0,"Enabled");
          _SFD_SET_DATA_PROPS(3,1,1,0,"V");
          _SFD_SET_DATA_PROPS(4,1,1,0,"I");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,1,6,0,0,0,0,0,4,2);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,1051);
        _SFD_CV_INIT_EML_IF(0,1,0,597,613,-1,657);
        _SFD_CV_INIT_EML_IF(0,1,1,696,720,966,982);
        _SFD_CV_INIT_EML_IF(0,1,2,725,734,844,965);
        _SFD_CV_INIT_EML_IF(0,1,3,743,752,792,839);
        _SFD_CV_INIT_EML_IF(0,1,4,857,866,906,953);
        _SFD_CV_INIT_EML_IF(0,1,5,984,1007,-1,1023);

        {
          static int condStart[] = { 699, 709 };

          static int condEnd[] = { 706, 720 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,0,699,720,2,0,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 987, 999 };

          static int condEnd[] = { 996, 1007 };

          static int pfixExpr[] = { 0, 1, -2 };

          _SFD_CV_INIT_EML_MCDC(0,1,1,987,1007,2,2,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_e_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_d_sf_marshallOut,(MexInFcnForType)c2_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_d_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_d_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_d_sf_marshallOut,(MexInFcnForType)NULL);

        {
          real_T *c2_D;
          real_T *c2_Enabled;
          real_T *c2_V;
          real_T *c2_I;
          real_T (*c2_Param)[4];
          c2_I = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c2_V = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c2_Enabled = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c2_D = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c2_Param = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c2_Param);
          _SFD_SET_DATA_VALUE_PTR(1U, c2_D);
          _SFD_SET_DATA_VALUE_PTR(2U, c2_Enabled);
          _SFD_SET_DATA_VALUE_PTR(3U, c2_V);
          _SFD_SET_DATA_VALUE_PTR(4U, c2_I);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _G24i_buck_boostMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "XK3tfLZddJ2yWz7VJeOVCH";
}

static void sf_opaque_initialize_c2_G24i_buck_boost(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc2_G24i_buck_boostInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c2_G24i_buck_boost((SFc2_G24i_buck_boostInstanceStruct*)
    chartInstanceVar);
  initialize_c2_G24i_buck_boost((SFc2_G24i_buck_boostInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c2_G24i_buck_boost(void *chartInstanceVar)
{
  enable_c2_G24i_buck_boost((SFc2_G24i_buck_boostInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c2_G24i_buck_boost(void *chartInstanceVar)
{
  disable_c2_G24i_buck_boost((SFc2_G24i_buck_boostInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c2_G24i_buck_boost(void *chartInstanceVar)
{
  sf_gateway_c2_G24i_buck_boost((SFc2_G24i_buck_boostInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c2_G24i_buck_boost(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c2_G24i_buck_boost
    ((SFc2_G24i_buck_boostInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_G24i_buck_boost();/* state var info */
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

extern void sf_internal_set_sim_state_c2_G24i_buck_boost(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c2_G24i_buck_boost();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c2_G24i_buck_boost((SFc2_G24i_buck_boostInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c2_G24i_buck_boost(SimStruct* S)
{
  return sf_internal_get_sim_state_c2_G24i_buck_boost(S);
}

static void sf_opaque_set_sim_state_c2_G24i_buck_boost(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c2_G24i_buck_boost(S, st);
}

static void sf_opaque_terminate_c2_G24i_buck_boost(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_G24i_buck_boostInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_G24i_buck_boost_optimization_info();
    }

    finalize_c2_G24i_buck_boost((SFc2_G24i_buck_boostInstanceStruct*)
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
  initSimStructsc2_G24i_buck_boost((SFc2_G24i_buck_boostInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_G24i_buck_boost(SimStruct *S)
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
    initialize_params_c2_G24i_buck_boost((SFc2_G24i_buck_boostInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c2_G24i_buck_boost(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_G24i_buck_boost_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,2);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,2,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,2,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,2);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,2,4);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,2,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,2);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1098999231U));
  ssSetChecksum1(S,(3028612429U));
  ssSetChecksum2(S,(1948477602U));
  ssSetChecksum3(S,(1117013308U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c2_G24i_buck_boost(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c2_G24i_buck_boost(SimStruct *S)
{
  SFc2_G24i_buck_boostInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc2_G24i_buck_boostInstanceStruct *)utMalloc(sizeof
    (SFc2_G24i_buck_boostInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc2_G24i_buck_boostInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c2_G24i_buck_boost;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c2_G24i_buck_boost;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c2_G24i_buck_boost;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c2_G24i_buck_boost;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c2_G24i_buck_boost;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c2_G24i_buck_boost;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c2_G24i_buck_boost;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c2_G24i_buck_boost;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_G24i_buck_boost;
  chartInstance->chartInfo.mdlStart = mdlStart_c2_G24i_buck_boost;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c2_G24i_buck_boost;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.debugInstance = sfGlobalDebugInstanceStruct;
  chartInstance->S = S;
  crtInfo->instanceInfo = (&(chartInstance->chartInfo));
  crtInfo->isJITEnabled = false;
  ssSetUserData(S,(void *)(crtInfo));  /* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
  chart_debug_initialization(S,1);
}

void c2_G24i_buck_boost_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_G24i_buck_boost(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_G24i_buck_boost(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_G24i_buck_boost(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_G24i_buck_boost_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
