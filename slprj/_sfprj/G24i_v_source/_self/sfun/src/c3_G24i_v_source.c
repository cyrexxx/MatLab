/* Include files */

#include <stddef.h>
#include "blas.h"
#include "G24i_v_source_sfun.h"
#include "c3_G24i_v_source.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "G24i_v_source_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)
#define c3_IN_NO_ACTIVE_CHILD          ((uint8_T)0U)
#define c3_IN_DECREMENT                ((uint8_T)1U)
#define c3_IN_INCREMENT                ((uint8_T)2U)
#define c3_IN_RETURN                   ((uint8_T)3U)
#define c3_IN_Sample_and_call          ((uint8_T)4U)
#define c3_IN_init                     ((uint8_T)5U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c3_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_b_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_c_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_d_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_e_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_f_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_g_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_h_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_i_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_j_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_k_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_l_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_m_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_n_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_o_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_p_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_q_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_r_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_s_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_t_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_u_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_v_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_w_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static boolean_T c3_dataWrittenToVector[6];

/* Function Declarations */
static void initialize_c3_G24i_v_source(SFc3_G24i_v_sourceInstanceStruct
  *chartInstance);
static void initialize_params_c3_G24i_v_source(SFc3_G24i_v_sourceInstanceStruct *
  chartInstance);
static void enable_c3_G24i_v_source(SFc3_G24i_v_sourceInstanceStruct
  *chartInstance);
static void disable_c3_G24i_v_source(SFc3_G24i_v_sourceInstanceStruct
  *chartInstance);
static void c3_update_debugger_state_c3_G24i_v_source
  (SFc3_G24i_v_sourceInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c3_G24i_v_source
  (SFc3_G24i_v_sourceInstanceStruct *chartInstance);
static void set_sim_state_c3_G24i_v_source(SFc3_G24i_v_sourceInstanceStruct
  *chartInstance, const mxArray *c3_st);
static void c3_set_sim_state_side_effects_c3_G24i_v_source
  (SFc3_G24i_v_sourceInstanceStruct *chartInstance);
static void finalize_c3_G24i_v_source(SFc3_G24i_v_sourceInstanceStruct
  *chartInstance);
static void sf_gateway_c3_G24i_v_source(SFc3_G24i_v_sourceInstanceStruct
  *chartInstance);
static void initSimStructsc3_G24i_v_source(SFc3_G24i_v_sourceInstanceStruct
  *chartInstance);
static void c3_Sample_and_call(SFc3_G24i_v_sourceInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber, uint32_T c3_instanceNumber);
static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData);
static real_T c3_emlrt_marshallIn(SFc3_G24i_v_sourceInstanceStruct
  *chartInstance, const mxArray *c3_nargout, const char_T *c3_identifier);
static real_T c3_b_emlrt_marshallIn(SFc3_G24i_v_sourceInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static boolean_T c3_c_emlrt_marshallIn(SFc3_G24i_v_sourceInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static void c3_info_helper(const mxArray **c3_info);
static const mxArray *c3_emlrt_marshallOut(const char * c3_u);
static const mxArray *c3_b_emlrt_marshallOut(const uint32_T c3_u);
static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static int32_T c3_d_emlrt_marshallIn(SFc3_G24i_v_sourceInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_d_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static uint8_T c3_e_emlrt_marshallIn(SFc3_G24i_v_sourceInstanceStruct
  *chartInstance, const mxArray *c3_b_tp_init, const char_T *c3_identifier);
static uint8_T c3_f_emlrt_marshallIn(SFc3_G24i_v_sourceInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_g_emlrt_marshallIn(SFc3_G24i_v_sourceInstanceStruct
  *chartInstance, const mxArray *c3_b_setSimStateSideEffectsInfo, const char_T
  *c3_identifier);
static const mxArray *c3_h_emlrt_marshallIn(SFc3_G24i_v_sourceInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_updateDataWrittenToVector(SFc3_G24i_v_sourceInstanceStruct
  *chartInstance, uint32_T c3_vectorIndex);
static void c3_errorIfDataNotWrittenToFcn(SFc3_G24i_v_sourceInstanceStruct
  *chartInstance, uint32_T c3_vectorIndex, uint32_T c3_dataNumber);
static void init_dsm_address_info(SFc3_G24i_v_sourceInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c3_G24i_v_source(SFc3_G24i_v_sourceInstanceStruct
  *chartInstance)
{
  chartInstance->c3_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c3_doSetSimStateSideEffects = 0U;
  chartInstance->c3_setSimStateSideEffectsInfo = NULL;
  chartInstance->c3_tp_DECREMENT = 0U;
  chartInstance->c3_tp_INCREMENT = 0U;
  chartInstance->c3_tp_RETURN = 0U;
  chartInstance->c3_tp_Sample_and_call = 0U;
  chartInstance->c3_tp_init = 0U;
  chartInstance->c3_is_active_c3_G24i_v_source = 0U;
  chartInstance->c3_is_c3_G24i_v_source = c3_IN_NO_ACTIVE_CHILD;
}

static void initialize_params_c3_G24i_v_source(SFc3_G24i_v_sourceInstanceStruct *
  chartInstance)
{
  (void)chartInstance;
}

static void enable_c3_G24i_v_source(SFc3_G24i_v_sourceInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c3_G24i_v_source(SFc3_G24i_v_sourceInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c3_update_debugger_state_c3_G24i_v_source
  (SFc3_G24i_v_sourceInstanceStruct *chartInstance)
{
  uint32_T c3_prevAniVal;
  c3_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (chartInstance->c3_is_active_c3_G24i_v_source == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_c3_G24i_v_source == c3_IN_init) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_c3_G24i_v_source == c3_IN_Sample_and_call) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_c3_G24i_v_source == c3_IN_INCREMENT) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_c3_G24i_v_source == c3_IN_DECREMENT) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_c3_G24i_v_source == c3_IN_RETURN) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c3_sfEvent);
  }

  _SFD_SET_ANIMATION(c3_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c3_G24i_v_source
  (SFc3_G24i_v_sourceInstanceStruct *chartInstance)
{
  const mxArray *c3_st;
  const mxArray *c3_y = NULL;
  real_T c3_hoistedGlobal;
  real_T c3_u;
  const mxArray *c3_b_y = NULL;
  real_T c3_b_hoistedGlobal;
  real_T c3_b_u;
  const mxArray *c3_c_y = NULL;
  real_T c3_c_hoistedGlobal;
  real_T c3_c_u;
  const mxArray *c3_d_y = NULL;
  real_T c3_d_hoistedGlobal;
  real_T c3_d_u;
  const mxArray *c3_e_y = NULL;
  real_T c3_e_hoistedGlobal;
  real_T c3_e_u;
  const mxArray *c3_f_y = NULL;
  real_T c3_f_hoistedGlobal;
  real_T c3_f_u;
  const mxArray *c3_g_y = NULL;
  uint8_T c3_g_hoistedGlobal;
  uint8_T c3_g_u;
  const mxArray *c3_h_y = NULL;
  uint8_T c3_h_hoistedGlobal;
  uint8_T c3_h_u;
  const mxArray *c3_i_y = NULL;
  real_T *c3_v_ref;
  c3_v_ref = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c3_st = NULL;
  c3_st = NULL;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_createcellmatrix(8, 1), false);
  c3_hoistedGlobal = *c3_v_ref;
  c3_u = c3_hoistedGlobal;
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 0, c3_b_y);
  c3_b_hoistedGlobal = chartInstance->c3_I_prev1;
  c3_b_u = c3_b_hoistedGlobal;
  c3_c_y = NULL;
  sf_mex_assign(&c3_c_y, sf_mex_create("y", &c3_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 1, c3_c_y);
  c3_c_hoistedGlobal = chartInstance->c3_V_REF;
  c3_c_u = c3_c_hoistedGlobal;
  c3_d_y = NULL;
  sf_mex_assign(&c3_d_y, sf_mex_create("y", &c3_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 2, c3_d_y);
  c3_d_hoistedGlobal = chartInstance->c3_V_prev1;
  c3_d_u = c3_d_hoistedGlobal;
  c3_e_y = NULL;
  sf_mex_assign(&c3_e_y, sf_mex_create("y", &c3_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 3, c3_e_y);
  c3_e_hoistedGlobal = chartInstance->c3_deltaI;
  c3_e_u = c3_e_hoistedGlobal;
  c3_f_y = NULL;
  sf_mex_assign(&c3_f_y, sf_mex_create("y", &c3_e_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 4, c3_f_y);
  c3_f_hoistedGlobal = chartInstance->c3_deltaV;
  c3_f_u = c3_f_hoistedGlobal;
  c3_g_y = NULL;
  sf_mex_assign(&c3_g_y, sf_mex_create("y", &c3_f_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 5, c3_g_y);
  c3_g_hoistedGlobal = chartInstance->c3_is_active_c3_G24i_v_source;
  c3_g_u = c3_g_hoistedGlobal;
  c3_h_y = NULL;
  sf_mex_assign(&c3_h_y, sf_mex_create("y", &c3_g_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 6, c3_h_y);
  c3_h_hoistedGlobal = chartInstance->c3_is_c3_G24i_v_source;
  c3_h_u = c3_h_hoistedGlobal;
  c3_i_y = NULL;
  sf_mex_assign(&c3_i_y, sf_mex_create("y", &c3_h_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 7, c3_i_y);
  sf_mex_assign(&c3_st, c3_y, false);
  return c3_st;
}

static void set_sim_state_c3_G24i_v_source(SFc3_G24i_v_sourceInstanceStruct
  *chartInstance, const mxArray *c3_st)
{
  const mxArray *c3_u;
  real_T *c3_v_ref;
  c3_v_ref = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c3_u = sf_mex_dup(c3_st);
  *c3_v_ref = c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u,
    0)), "v_ref");
  chartInstance->c3_I_prev1 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 1)), "I_prev1");
  chartInstance->c3_V_REF = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 2)), "V_REF");
  chartInstance->c3_V_prev1 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 3)), "V_prev1");
  chartInstance->c3_deltaI = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 4)), "deltaI");
  chartInstance->c3_deltaV = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 5)), "deltaV");
  chartInstance->c3_is_active_c3_G24i_v_source = c3_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 6)),
     "is_active_c3_G24i_v_source");
  chartInstance->c3_is_c3_G24i_v_source = c3_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 7)), "is_c3_G24i_v_source");
  sf_mex_assign(&chartInstance->c3_setSimStateSideEffectsInfo,
                c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c3_u, 8)), "setSimStateSideEffectsInfo"), true);
  sf_mex_destroy(&c3_u);
  chartInstance->c3_doSetSimStateSideEffects = 1U;
  c3_update_debugger_state_c3_G24i_v_source(chartInstance);
  sf_mex_destroy(&c3_st);
}

static void c3_set_sim_state_side_effects_c3_G24i_v_source
  (SFc3_G24i_v_sourceInstanceStruct *chartInstance)
{
  if (chartInstance->c3_doSetSimStateSideEffects != 0) {
    if (chartInstance->c3_is_c3_G24i_v_source == c3_IN_DECREMENT) {
      chartInstance->c3_tp_DECREMENT = 1U;
    } else {
      chartInstance->c3_tp_DECREMENT = 0U;
    }

    if (chartInstance->c3_is_c3_G24i_v_source == c3_IN_INCREMENT) {
      chartInstance->c3_tp_INCREMENT = 1U;
    } else {
      chartInstance->c3_tp_INCREMENT = 0U;
    }

    if (chartInstance->c3_is_c3_G24i_v_source == c3_IN_RETURN) {
      chartInstance->c3_tp_RETURN = 1U;
    } else {
      chartInstance->c3_tp_RETURN = 0U;
    }

    if (chartInstance->c3_is_c3_G24i_v_source == c3_IN_Sample_and_call) {
      chartInstance->c3_tp_Sample_and_call = 1U;
    } else {
      chartInstance->c3_tp_Sample_and_call = 0U;
    }

    if (chartInstance->c3_is_c3_G24i_v_source == c3_IN_init) {
      chartInstance->c3_tp_init = 1U;
    } else {
      chartInstance->c3_tp_init = 0U;
    }

    chartInstance->c3_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c3_G24i_v_source(SFc3_G24i_v_sourceInstanceStruct
  *chartInstance)
{
  sf_mex_destroy(&chartInstance->c3_setSimStateSideEffectsInfo);
}

static void sf_gateway_c3_G24i_v_source(SFc3_G24i_v_sourceInstanceStruct
  *chartInstance)
{
  uint32_T c3_debug_family_var_map[2];
  real_T c3_nargin = 0.0;
  real_T c3_nargout = 0.0;
  real_T c3_b_nargin = 0.0;
  real_T c3_b_nargout = 0.0;
  real_T c3_c_nargin = 0.0;
  real_T c3_c_nargout = 0.0;
  real_T c3_d_nargin = 0.0;
  real_T c3_d_nargout = 0.0;
  real_T c3_e_nargin = 0.0;
  real_T c3_e_nargout = 0.0;
  real_T *c3_deltaD;
  real_T *c3_v_ref;
  real_T *c3_V;
  real_T *c3_I;
  c3_I = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c3_V = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c3_v_ref = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c3_deltaD = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c3_set_sim_state_side_effects_c3_G24i_v_source(chartInstance);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c3_deltaD, 0U);
  _SFD_DATA_RANGE_CHECK(*c3_v_ref, 1U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c3_V_prev1, 2U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c3_I_prev1, 3U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c3_V_REF, 4U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c3_deltaV, 5U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c3_deltaI, 6U);
  _SFD_DATA_RANGE_CHECK(*c3_V, 7U);
  _SFD_DATA_RANGE_CHECK(*c3_I, 8U);
  chartInstance->c3_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
  if (chartInstance->c3_is_active_c3_G24i_v_source == 0U) {
    _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
    chartInstance->c3_is_active_c3_G24i_v_source = 1U;
    _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 12U, chartInstance->c3_sfEvent);
    chartInstance->c3_is_c3_G24i_v_source = c3_IN_init;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c3_sfEvent);
    chartInstance->c3_tp_init = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    chartInstance->c3_V_prev1 = 0.0;
    c3_updateDataWrittenToVector(chartInstance, 1U);
    _SFD_DATA_RANGE_CHECK(chartInstance->c3_V_prev1, 2U);
    chartInstance->c3_I_prev1 = 0.0;
    c3_updateDataWrittenToVector(chartInstance, 2U);
    _SFD_DATA_RANGE_CHECK(chartInstance->c3_I_prev1, 3U);
    chartInstance->c3_V_REF = 0.5;
    c3_updateDataWrittenToVector(chartInstance, 3U);
    _SFD_DATA_RANGE_CHECK(chartInstance->c3_V_REF, 4U);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    switch (chartInstance->c3_is_c3_G24i_v_source) {
     case c3_IN_DECREMENT:
      CV_CHART_EVAL(0, 0, 1);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, chartInstance->c3_sfEvent);
      chartInstance->c3_tp_DECREMENT = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
      chartInstance->c3_is_c3_G24i_v_source = c3_IN_RETURN;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c3_sfEvent);
      chartInstance->c3_tp_RETURN = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_e_debug_family_names,
        c3_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargin, 0U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargout, 1U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      chartInstance->c3_V_prev1 = *c3_V;
      c3_updateDataWrittenToVector(chartInstance, 1U);
      _SFD_DATA_RANGE_CHECK(chartInstance->c3_V_prev1, 2U);
      chartInstance->c3_I_prev1 = *c3_I;
      c3_updateDataWrittenToVector(chartInstance, 2U);
      _SFD_DATA_RANGE_CHECK(chartInstance->c3_I_prev1, 3U);
      c3_errorIfDataNotWrittenToFcn(chartInstance, 0U, 1U);
      chartInstance->c3_V_REF = *c3_v_ref;
      c3_updateDataWrittenToVector(chartInstance, 3U);
      _SFD_DATA_RANGE_CHECK(chartInstance->c3_V_REF, 4U);
      _SFD_SYMBOL_SCOPE_POP();
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
      break;

     case c3_IN_INCREMENT:
      CV_CHART_EVAL(0, 0, 2);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 5U, chartInstance->c3_sfEvent);
      chartInstance->c3_tp_INCREMENT = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
      chartInstance->c3_is_c3_G24i_v_source = c3_IN_RETURN;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c3_sfEvent);
      chartInstance->c3_tp_RETURN = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_e_debug_family_names,
        c3_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargin, 0U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargout, 1U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      chartInstance->c3_V_prev1 = *c3_V;
      c3_updateDataWrittenToVector(chartInstance, 1U);
      _SFD_DATA_RANGE_CHECK(chartInstance->c3_V_prev1, 2U);
      chartInstance->c3_I_prev1 = *c3_I;
      c3_updateDataWrittenToVector(chartInstance, 2U);
      _SFD_DATA_RANGE_CHECK(chartInstance->c3_I_prev1, 3U);
      c3_errorIfDataNotWrittenToFcn(chartInstance, 0U, 1U);
      chartInstance->c3_V_REF = *c3_v_ref;
      c3_updateDataWrittenToVector(chartInstance, 3U);
      _SFD_DATA_RANGE_CHECK(chartInstance->c3_V_REF, 4U);
      _SFD_SYMBOL_SCOPE_POP();
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c3_sfEvent);
      break;

     case c3_IN_RETURN:
      CV_CHART_EVAL(0, 0, 3);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
      chartInstance->c3_tp_RETURN = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c3_sfEvent);
      chartInstance->c3_is_c3_G24i_v_source = c3_IN_Sample_and_call;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c3_sfEvent);
      chartInstance->c3_tp_Sample_and_call = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_b_debug_family_names,
        c3_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargin, 0U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargout, 1U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      c3_errorIfDataNotWrittenToFcn(chartInstance, 1U, 2U);
      chartInstance->c3_deltaV = *c3_V - chartInstance->c3_V_prev1;
      c3_updateDataWrittenToVector(chartInstance, 4U);
      _SFD_DATA_RANGE_CHECK(chartInstance->c3_deltaV, 5U);
      c3_errorIfDataNotWrittenToFcn(chartInstance, 2U, 3U);
      chartInstance->c3_deltaI = *c3_I - chartInstance->c3_I_prev1;
      c3_updateDataWrittenToVector(chartInstance, 5U);
      _SFD_DATA_RANGE_CHECK(chartInstance->c3_deltaI, 6U);
      c3_errorIfDataNotWrittenToFcn(chartInstance, 3U, 4U);
      *c3_v_ref = chartInstance->c3_V_REF;
      c3_updateDataWrittenToVector(chartInstance, 0U);
      _SFD_DATA_RANGE_CHECK(*c3_v_ref, 1U);
      _SFD_SYMBOL_SCOPE_POP();
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
      break;

     case c3_IN_Sample_and_call:
      CV_CHART_EVAL(0, 0, 4);
      c3_Sample_and_call(chartInstance);
      break;

     case c3_IN_init:
      CV_CHART_EVAL(0, 0, 5);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 11U, chartInstance->c3_sfEvent);
      chartInstance->c3_tp_init = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c3_sfEvent);
      chartInstance->c3_is_c3_G24i_v_source = c3_IN_Sample_and_call;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c3_sfEvent);
      chartInstance->c3_tp_Sample_and_call = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_b_debug_family_names,
        c3_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_nargin, 0U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_nargout, 1U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      c3_errorIfDataNotWrittenToFcn(chartInstance, 1U, 2U);
      chartInstance->c3_deltaV = *c3_V - chartInstance->c3_V_prev1;
      c3_updateDataWrittenToVector(chartInstance, 4U);
      _SFD_DATA_RANGE_CHECK(chartInstance->c3_deltaV, 5U);
      c3_errorIfDataNotWrittenToFcn(chartInstance, 2U, 3U);
      chartInstance->c3_deltaI = *c3_I - chartInstance->c3_I_prev1;
      c3_updateDataWrittenToVector(chartInstance, 5U);
      _SFD_DATA_RANGE_CHECK(chartInstance->c3_deltaI, 6U);
      c3_errorIfDataNotWrittenToFcn(chartInstance, 3U, 4U);
      *c3_v_ref = chartInstance->c3_V_REF;
      c3_updateDataWrittenToVector(chartInstance, 0U);
      _SFD_DATA_RANGE_CHECK(*c3_v_ref, 1U);
      _SFD_SYMBOL_SCOPE_POP();
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, chartInstance->c3_sfEvent);
      break;

     default:
      CV_CHART_EVAL(0, 0, 0);
      chartInstance->c3_is_c3_G24i_v_source = c3_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
      break;
    }
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_G24i_v_sourceMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc3_G24i_v_source(SFc3_G24i_v_sourceInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c3_Sample_and_call(SFc3_G24i_v_sourceInstanceStruct *chartInstance)
{
  uint32_T c3_debug_family_var_map[3];
  real_T c3_nargin = 0.0;
  real_T c3_nargout = 1.0;
  boolean_T c3_out;
  real_T c3_b_nargin = 0.0;
  real_T c3_b_nargout = 1.0;
  boolean_T c3_b_out;
  real_T c3_hoistedGlobal;
  real_T c3_b_hoistedGlobal;
  real_T c3_A;
  real_T c3_B;
  real_T c3_x;
  real_T c3_y;
  real_T c3_b_x;
  real_T c3_b_y;
  real_T c3_c_x;
  real_T c3_c_y;
  real_T c3_d_y;
  real_T c3_c_hoistedGlobal;
  real_T c3_d_hoistedGlobal;
  real_T c3_b_A;
  real_T c3_b_B;
  real_T c3_d_x;
  real_T c3_e_y;
  real_T c3_e_x;
  real_T c3_f_y;
  real_T c3_f_x;
  real_T c3_g_y;
  real_T c3_h_y;
  real_T c3_c_nargin = 0.0;
  real_T c3_c_nargout = 1.0;
  boolean_T c3_c_out;
  real_T c3_e_hoistedGlobal;
  real_T c3_f_hoistedGlobal;
  real_T c3_c_A;
  real_T c3_c_B;
  real_T c3_g_x;
  real_T c3_i_y;
  real_T c3_h_x;
  real_T c3_j_y;
  real_T c3_i_x;
  real_T c3_k_y;
  real_T c3_l_y;
  real_T c3_g_hoistedGlobal;
  real_T c3_h_hoistedGlobal;
  real_T c3_d_A;
  real_T c3_d_B;
  real_T c3_j_x;
  real_T c3_m_y;
  real_T c3_k_x;
  real_T c3_n_y;
  real_T c3_l_x;
  real_T c3_o_y;
  real_T c3_p_y;
  uint32_T c3_b_debug_family_var_map[2];
  real_T c3_d_nargin = 0.0;
  real_T c3_d_nargout = 0.0;
  real_T c3_e_nargin = 0.0;
  real_T c3_e_nargout = 0.0;
  real_T c3_f_nargin = 0.0;
  real_T c3_f_nargout = 1.0;
  boolean_T c3_d_out;
  real_T c3_i_hoistedGlobal;
  real_T c3_j_hoistedGlobal;
  real_T c3_e_A;
  real_T c3_e_B;
  real_T c3_m_x;
  real_T c3_q_y;
  real_T c3_n_x;
  real_T c3_r_y;
  real_T c3_o_x;
  real_T c3_s_y;
  real_T c3_t_y;
  real_T c3_k_hoistedGlobal;
  real_T c3_l_hoistedGlobal;
  real_T c3_f_A;
  real_T c3_f_B;
  real_T c3_p_x;
  real_T c3_u_y;
  real_T c3_q_x;
  real_T c3_v_y;
  real_T c3_r_x;
  real_T c3_w_y;
  real_T c3_x_y;
  real_T c3_g_nargin = 0.0;
  real_T c3_g_nargout = 0.0;
  real_T c3_h_nargin = 0.0;
  real_T c3_h_nargout = 1.0;
  boolean_T c3_e_out;
  real_T c3_i_nargin = 0.0;
  real_T c3_i_nargout = 1.0;
  boolean_T c3_f_out;
  real_T c3_j_nargin = 0.0;
  real_T c3_j_nargout = 1.0;
  boolean_T c3_g_out;
  real_T c3_k_nargin = 0.0;
  real_T c3_k_nargout = 0.0;
  real_T c3_l_nargin = 0.0;
  real_T c3_l_nargout = 1.0;
  boolean_T c3_h_out;
  real_T c3_m_nargin = 0.0;
  real_T c3_m_nargout = 0.0;
  real_T c3_n_nargin = 0.0;
  real_T c3_n_nargout = 1.0;
  boolean_T c3_i_out;
  real_T c3_o_nargin = 0.0;
  real_T c3_o_nargout = 0.0;
  real_T *c3_v_ref;
  real_T *c3_deltaD;
  real_T *c3_V;
  real_T *c3_I;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  c3_I = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c3_V = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c3_v_ref = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c3_deltaD = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 14U, chartInstance->c3_sfEvent);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 13U, chartInstance->c3_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_g_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_out, 2U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  c3_errorIfDataNotWrittenToFcn(chartInstance, 4U, 5U);
  c3_out = CV_EML_IF(13, 0, 0, chartInstance->c3_deltaV != 0.0);
  _SFD_SYMBOL_SCOPE_POP();
  guard1 = false;
  guard2 = false;
  guard3 = false;
  if (c3_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 13U, chartInstance->c3_sfEvent);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 6U, chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_k_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargin, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargout, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_out, 2U, c3_b_sf_marshallOut,
      c3_b_sf_marshallIn);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 5U, 6U);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 4U, 5U);
    c3_hoistedGlobal = chartInstance->c3_deltaI;
    c3_b_hoistedGlobal = chartInstance->c3_deltaV;
    c3_A = c3_hoistedGlobal;
    c3_B = c3_b_hoistedGlobal;
    c3_x = c3_A;
    c3_y = c3_B;
    c3_b_x = c3_x;
    c3_b_y = c3_y;
    c3_c_x = c3_b_x;
    c3_c_y = c3_b_y;
    c3_d_y = c3_c_x / c3_c_y;
    c3_c_hoistedGlobal = *c3_I;
    c3_d_hoistedGlobal = *c3_V;
    c3_b_A = c3_c_hoistedGlobal;
    c3_b_B = c3_d_hoistedGlobal;
    c3_d_x = c3_b_A;
    c3_e_y = c3_b_B;
    c3_e_x = c3_d_x;
    c3_f_y = c3_e_y;
    c3_f_x = c3_e_x;
    c3_g_y = c3_f_y;
    c3_h_y = c3_f_x / c3_g_y;
    c3_b_out = CV_EML_IF(6, 0, 0, c3_d_y != -c3_h_y);
    _SFD_SYMBOL_SCOPE_POP();
    if (c3_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 6U, chartInstance->c3_sfEvent);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 8U,
                   chartInstance->c3_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_n_debug_family_names,
        c3_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargin, 0U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargout, 1U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_out, 2U, c3_b_sf_marshallOut,
        c3_b_sf_marshallIn);
      c3_errorIfDataNotWrittenToFcn(chartInstance, 5U, 6U);
      c3_errorIfDataNotWrittenToFcn(chartInstance, 4U, 5U);
      c3_e_hoistedGlobal = chartInstance->c3_deltaI;
      c3_f_hoistedGlobal = chartInstance->c3_deltaV;
      c3_c_A = c3_e_hoistedGlobal;
      c3_c_B = c3_f_hoistedGlobal;
      c3_g_x = c3_c_A;
      c3_i_y = c3_c_B;
      c3_h_x = c3_g_x;
      c3_j_y = c3_i_y;
      c3_i_x = c3_h_x;
      c3_k_y = c3_j_y;
      c3_l_y = c3_i_x / c3_k_y;
      c3_g_hoistedGlobal = *c3_I;
      c3_h_hoistedGlobal = *c3_V;
      c3_d_A = c3_g_hoistedGlobal;
      c3_d_B = c3_h_hoistedGlobal;
      c3_j_x = c3_d_A;
      c3_m_y = c3_d_B;
      c3_k_x = c3_j_x;
      c3_n_y = c3_m_y;
      c3_l_x = c3_k_x;
      c3_o_y = c3_n_y;
      c3_p_y = c3_l_x / c3_o_y;
      c3_c_out = CV_EML_IF(8, 0, 0, c3_l_y > -c3_p_y);
      _SFD_SYMBOL_SCOPE_POP();
      if (c3_c_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 8U, chartInstance->c3_sfEvent);
        chartInstance->c3_tp_Sample_and_call = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c3_sfEvent);
        chartInstance->c3_is_c3_G24i_v_source = c3_IN_DECREMENT;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
        chartInstance->c3_tp_DECREMENT = 1U;
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_d_debug_family_names,
          c3_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargin, 0U, c3_sf_marshallOut,
          c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargout, 1U,
          c3_sf_marshallOut, c3_sf_marshallIn);
        c3_errorIfDataNotWrittenToFcn(chartInstance, 0U, 1U);
        *c3_v_ref -= *c3_deltaD;
        c3_updateDataWrittenToVector(chartInstance, 0U);
        _SFD_DATA_RANGE_CHECK(*c3_v_ref, 1U);
        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 4U, chartInstance->c3_sfEvent);
        chartInstance->c3_tp_Sample_and_call = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c3_sfEvent);
        chartInstance->c3_is_c3_G24i_v_source = c3_IN_INCREMENT;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
        chartInstance->c3_tp_INCREMENT = 1U;
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_c_debug_family_names,
          c3_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_nargin, 0U, c3_sf_marshallOut,
          c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_nargout, 1U,
          c3_sf_marshallOut, c3_sf_marshallIn);
        c3_errorIfDataNotWrittenToFcn(chartInstance, 0U, 1U);
        *c3_v_ref += *c3_deltaD;
        c3_updateDataWrittenToVector(chartInstance, 0U);
        _SFD_DATA_RANGE_CHECK(*c3_v_ref, 1U);
        _SFD_SYMBOL_SCOPE_POP();
      }
    } else {
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 7U,
                   chartInstance->c3_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_j_debug_family_names,
        c3_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_f_nargin, 0U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_f_nargout, 1U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_out, 2U, c3_b_sf_marshallOut,
        c3_b_sf_marshallIn);
      c3_errorIfDataNotWrittenToFcn(chartInstance, 5U, 6U);
      c3_errorIfDataNotWrittenToFcn(chartInstance, 4U, 5U);
      c3_i_hoistedGlobal = chartInstance->c3_deltaI;
      c3_j_hoistedGlobal = chartInstance->c3_deltaV;
      c3_e_A = c3_i_hoistedGlobal;
      c3_e_B = c3_j_hoistedGlobal;
      c3_m_x = c3_e_A;
      c3_q_y = c3_e_B;
      c3_n_x = c3_m_x;
      c3_r_y = c3_q_y;
      c3_o_x = c3_n_x;
      c3_s_y = c3_r_y;
      c3_t_y = c3_o_x / c3_s_y;
      c3_k_hoistedGlobal = *c3_I;
      c3_l_hoistedGlobal = *c3_V;
      c3_f_A = c3_k_hoistedGlobal;
      c3_f_B = c3_l_hoistedGlobal;
      c3_p_x = c3_f_A;
      c3_u_y = c3_f_B;
      c3_q_x = c3_p_x;
      c3_v_y = c3_u_y;
      c3_r_x = c3_q_x;
      c3_w_y = c3_v_y;
      c3_x_y = c3_r_x / c3_w_y;
      c3_d_out = CV_EML_IF(7, 0, 0, c3_t_y == -c3_x_y);
      _SFD_SYMBOL_SCOPE_POP();
      if (c3_d_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 7U, chartInstance->c3_sfEvent);
        chartInstance->c3_tp_Sample_and_call = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c3_sfEvent);
        chartInstance->c3_is_c3_G24i_v_source = c3_IN_RETURN;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c3_sfEvent);
        chartInstance->c3_tp_RETURN = 1U;
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_e_debug_family_names,
          c3_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_g_nargin, 0U, c3_sf_marshallOut,
          c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_g_nargout, 1U,
          c3_sf_marshallOut, c3_sf_marshallIn);
        chartInstance->c3_V_prev1 = *c3_V;
        c3_updateDataWrittenToVector(chartInstance, 1U);
        _SFD_DATA_RANGE_CHECK(chartInstance->c3_V_prev1, 2U);
        chartInstance->c3_I_prev1 = *c3_I;
        c3_updateDataWrittenToVector(chartInstance, 2U);
        _SFD_DATA_RANGE_CHECK(chartInstance->c3_I_prev1, 3U);
        c3_errorIfDataNotWrittenToFcn(chartInstance, 0U, 1U);
        chartInstance->c3_V_REF = *c3_v_ref;
        c3_updateDataWrittenToVector(chartInstance, 3U);
        _SFD_DATA_RANGE_CHECK(chartInstance->c3_V_REF, 4U);
        _SFD_SYMBOL_SCOPE_POP();
      } else {
        guard3 = true;
      }
    }
  } else {
    guard3 = true;
  }

  if (guard3 == true) {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 15U,
                 chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_f_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_h_nargin, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_h_nargout, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_out, 2U, c3_b_sf_marshallOut,
      c3_b_sf_marshallIn);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 4U, 5U);
    c3_e_out = CV_EML_IF(15, 0, 0, chartInstance->c3_deltaV == 0.0);
    _SFD_SYMBOL_SCOPE_POP();
    if (c3_e_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 15U, chartInstance->c3_sfEvent);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 10U,
                   chartInstance->c3_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_i_debug_family_names,
        c3_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_i_nargin, 0U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_i_nargout, 1U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_f_out, 2U, c3_b_sf_marshallOut,
        c3_b_sf_marshallIn);
      c3_errorIfDataNotWrittenToFcn(chartInstance, 5U, 6U);
      c3_f_out = CV_EML_IF(10, 0, 0, chartInstance->c3_deltaI != 0.0);
      _SFD_SYMBOL_SCOPE_POP();
      if (c3_f_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 10U, chartInstance->c3_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 9U,
                     chartInstance->c3_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_m_debug_family_names,
          c3_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_j_nargin, 0U, c3_sf_marshallOut,
          c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_j_nargout, 1U,
          c3_sf_marshallOut, c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_g_out, 2U, c3_b_sf_marshallOut,
          c3_b_sf_marshallIn);
        c3_errorIfDataNotWrittenToFcn(chartInstance, 5U, 6U);
        c3_g_out = CV_EML_IF(9, 0, 0, chartInstance->c3_deltaI > 0.0);
        _SFD_SYMBOL_SCOPE_POP();
        if (c3_g_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 9U, chartInstance->c3_sfEvent);
          chartInstance->c3_tp_Sample_and_call = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c3_sfEvent);
          chartInstance->c3_is_c3_G24i_v_source = c3_IN_INCREMENT;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
          chartInstance->c3_tp_INCREMENT = 1U;
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_c_debug_family_names,
            c3_b_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_k_nargin, 0U,
            c3_sf_marshallOut, c3_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_k_nargout, 1U,
            c3_sf_marshallOut, c3_sf_marshallIn);
          c3_errorIfDataNotWrittenToFcn(chartInstance, 0U, 1U);
          *c3_v_ref += *c3_deltaD;
          c3_updateDataWrittenToVector(chartInstance, 0U);
          _SFD_DATA_RANGE_CHECK(*c3_v_ref, 1U);
          _SFD_SYMBOL_SCOPE_POP();
        } else {
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 0U,
                       chartInstance->c3_sfEvent);
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_l_debug_family_names,
            c3_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_l_nargin, 0U,
            c3_sf_marshallOut, c3_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_l_nargout, 1U,
            c3_sf_marshallOut, c3_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_h_out, 2U,
            c3_b_sf_marshallOut, c3_b_sf_marshallIn);
          c3_errorIfDataNotWrittenToFcn(chartInstance, 5U, 6U);
          c3_h_out = CV_EML_IF(0, 0, 0, chartInstance->c3_deltaI <= 0.0);
          _SFD_SYMBOL_SCOPE_POP();
          if (c3_h_out) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
            chartInstance->c3_tp_Sample_and_call = 0U;
            _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c3_sfEvent);
            chartInstance->c3_is_c3_G24i_v_source = c3_IN_DECREMENT;
            _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
            chartInstance->c3_tp_DECREMENT = 1U;
            _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_d_debug_family_names,
              c3_b_debug_family_var_map);
            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_m_nargin, 0U,
              c3_sf_marshallOut, c3_sf_marshallIn);
            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_m_nargout, 1U,
              c3_sf_marshallOut, c3_sf_marshallIn);
            c3_errorIfDataNotWrittenToFcn(chartInstance, 0U, 1U);
            *c3_v_ref -= *c3_deltaD;
            c3_updateDataWrittenToVector(chartInstance, 0U);
            _SFD_DATA_RANGE_CHECK(*c3_v_ref, 1U);
            _SFD_SYMBOL_SCOPE_POP();
          } else {
            guard2 = true;
          }
        }
      } else {
        guard2 = true;
      }
    } else {
      guard1 = true;
    }
  }

  if (guard2 == true) {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 3U, chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_h_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_n_nargin, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_n_nargout, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_i_out, 2U, c3_b_sf_marshallOut,
      c3_b_sf_marshallIn);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 5U, 6U);
    c3_i_out = CV_EML_IF(3, 0, 0, chartInstance->c3_deltaI == 0.0);
    _SFD_SYMBOL_SCOPE_POP();
    if (c3_i_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, chartInstance->c3_sfEvent);
      chartInstance->c3_tp_Sample_and_call = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c3_sfEvent);
      chartInstance->c3_is_c3_G24i_v_source = c3_IN_RETURN;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c3_sfEvent);
      chartInstance->c3_tp_RETURN = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_e_debug_family_names,
        c3_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_o_nargin, 0U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_o_nargout, 1U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      chartInstance->c3_V_prev1 = *c3_V;
      c3_updateDataWrittenToVector(chartInstance, 1U);
      _SFD_DATA_RANGE_CHECK(chartInstance->c3_V_prev1, 2U);
      chartInstance->c3_I_prev1 = *c3_I;
      c3_updateDataWrittenToVector(chartInstance, 2U);
      _SFD_DATA_RANGE_CHECK(chartInstance->c3_I_prev1, 3U);
      c3_errorIfDataNotWrittenToFcn(chartInstance, 0U, 1U);
      chartInstance->c3_V_REF = *c3_v_ref;
      c3_updateDataWrittenToVector(chartInstance, 3U);
      _SFD_DATA_RANGE_CHECK(chartInstance->c3_V_REF, 4U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      guard1 = true;
    }
  }

  if (guard1 == true) {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 3U, chartInstance->c3_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c3_sfEvent);
}

static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber, uint32_T c3_instanceNumber)
{
  (void)c3_machineNumber;
  (void)c3_chartNumber;
  (void)c3_instanceNumber;
}

static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  real_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_G24i_v_sourceInstanceStruct *chartInstance;
  chartInstance = (SFc3_G24i_v_sourceInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(real_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static real_T c3_emlrt_marshallIn(SFc3_G24i_v_sourceInstanceStruct
  *chartInstance, const mxArray *c3_nargout, const char_T *c3_identifier)
{
  real_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_nargout), &c3_thisId);
  sf_mex_destroy(&c3_nargout);
  return c3_y;
}

static real_T c3_b_emlrt_marshallIn(SFc3_G24i_v_sourceInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  real_T c3_y;
  real_T c3_d0;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_d0, 1, 0, 0U, 0, 0U, 0);
  c3_y = c3_d0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_nargout;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y;
  SFc3_G24i_v_sourceInstanceStruct *chartInstance;
  chartInstance = (SFc3_G24i_v_sourceInstanceStruct *)chartInstanceVoid;
  c3_nargout = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_nargout), &c3_thisId);
  sf_mex_destroy(&c3_nargout);
  *(real_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  boolean_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_G24i_v_sourceInstanceStruct *chartInstance;
  chartInstance = (SFc3_G24i_v_sourceInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(boolean_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static boolean_T c3_c_emlrt_marshallIn(SFc3_G24i_v_sourceInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  boolean_T c3_y;
  boolean_T c3_b0;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_b0, 1, 11, 0U, 0, 0U, 0);
  c3_y = c3_b0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_sf_internal_predicateOutput;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  boolean_T c3_y;
  SFc3_G24i_v_sourceInstanceStruct *chartInstance;
  chartInstance = (SFc3_G24i_v_sourceInstanceStruct *)chartInstanceVoid;
  c3_sf_internal_predicateOutput = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_sf_internal_predicateOutput), &c3_thisId);
  sf_mex_destroy(&c3_sf_internal_predicateOutput);
  *(boolean_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

const mxArray *sf_c3_G24i_v_source_get_eml_resolved_functions_info(void)
{
  const mxArray *c3_nameCaptureInfo = NULL;
  c3_nameCaptureInfo = NULL;
  sf_mex_assign(&c3_nameCaptureInfo, sf_mex_createstruct("structure", 2, 7, 1),
                false);
  c3_info_helper(&c3_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c3_nameCaptureInfo);
  return c3_nameCaptureInfo;
}

static void c3_info_helper(const mxArray **c3_info)
{
  const mxArray *c3_rhs0 = NULL;
  const mxArray *c3_lhs0 = NULL;
  const mxArray *c3_rhs1 = NULL;
  const mxArray *c3_lhs1 = NULL;
  const mxArray *c3_rhs2 = NULL;
  const mxArray *c3_lhs2 = NULL;
  const mxArray *c3_rhs3 = NULL;
  const mxArray *c3_lhs3 = NULL;
  const mxArray *c3_rhs4 = NULL;
  const mxArray *c3_lhs4 = NULL;
  const mxArray *c3_rhs5 = NULL;
  const mxArray *c3_lhs5 = NULL;
  const mxArray *c3_rhs6 = NULL;
  const mxArray *c3_lhs6 = NULL;
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("mrdivide"), "name", "name", 0);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1388460096U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1370009886U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c3_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs0), "rhs", "rhs", 0);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs0), "lhs", "lhs", 0);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 1);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 1);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c3_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs1), "rhs", "rhs", 1);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs1), "lhs", "lhs", 1);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 2);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("rdivide"), "name", "name", 2);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 2);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1363713880U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c3_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs2), "rhs", "rhs", 2);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs2), "lhs", "lhs", 2);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 3);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c3_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs3), "rhs", "rhs", 3);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs3), "lhs", "lhs", 3);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 4);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1286818796U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c3_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs4), "rhs", "rhs", 4);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs4), "lhs", "lhs", 4);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_div"), "name", "name", 5);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 5);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1375980688U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c3_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs5), "rhs", "rhs", 5);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs5), "lhs", "lhs", 5);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("coder.internal.div"), "name",
                  "name", 6);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 6);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1389307920U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c3_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs6), "rhs", "rhs", 6);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs6), "lhs", "lhs", 6);
  sf_mex_destroy(&c3_rhs0);
  sf_mex_destroy(&c3_lhs0);
  sf_mex_destroy(&c3_rhs1);
  sf_mex_destroy(&c3_lhs1);
  sf_mex_destroy(&c3_rhs2);
  sf_mex_destroy(&c3_lhs2);
  sf_mex_destroy(&c3_rhs3);
  sf_mex_destroy(&c3_lhs3);
  sf_mex_destroy(&c3_rhs4);
  sf_mex_destroy(&c3_lhs4);
  sf_mex_destroy(&c3_rhs5);
  sf_mex_destroy(&c3_lhs5);
  sf_mex_destroy(&c3_rhs6);
  sf_mex_destroy(&c3_lhs6);
}

static const mxArray *c3_emlrt_marshallOut(const char * c3_u)
{
  const mxArray *c3_y = NULL;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c3_u)), false);
  return c3_y;
}

static const mxArray *c3_b_emlrt_marshallOut(const uint32_T c3_u)
{
  const mxArray *c3_y = NULL;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 7, 0U, 0U, 0U, 0), false);
  return c3_y;
}

static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_G24i_v_sourceInstanceStruct *chartInstance;
  chartInstance = (SFc3_G24i_v_sourceInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(int32_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static int32_T c3_d_emlrt_marshallIn(SFc3_G24i_v_sourceInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  int32_T c3_y;
  int32_T c3_i0;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_i0, 1, 6, 0U, 0, 0U, 0);
  c3_y = c3_i0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_sfEvent;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  int32_T c3_y;
  SFc3_G24i_v_sourceInstanceStruct *chartInstance;
  chartInstance = (SFc3_G24i_v_sourceInstanceStruct *)chartInstanceVoid;
  c3_b_sfEvent = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_sfEvent),
    &c3_thisId);
  sf_mex_destroy(&c3_b_sfEvent);
  *(int32_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_d_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  uint8_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_G24i_v_sourceInstanceStruct *chartInstance;
  chartInstance = (SFc3_G24i_v_sourceInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(uint8_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static uint8_T c3_e_emlrt_marshallIn(SFc3_G24i_v_sourceInstanceStruct
  *chartInstance, const mxArray *c3_b_tp_init, const char_T *c3_identifier)
{
  uint8_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_tp_init),
    &c3_thisId);
  sf_mex_destroy(&c3_b_tp_init);
  return c3_y;
}

static uint8_T c3_f_emlrt_marshallIn(SFc3_G24i_v_sourceInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  uint8_T c3_y;
  uint8_T c3_u0;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_u0, 1, 3, 0U, 0, 0U, 0);
  c3_y = c3_u0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_tp_init;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  uint8_T c3_y;
  SFc3_G24i_v_sourceInstanceStruct *chartInstance;
  chartInstance = (SFc3_G24i_v_sourceInstanceStruct *)chartInstanceVoid;
  c3_b_tp_init = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_tp_init),
    &c3_thisId);
  sf_mex_destroy(&c3_b_tp_init);
  *(uint8_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_g_emlrt_marshallIn(SFc3_G24i_v_sourceInstanceStruct
  *chartInstance, const mxArray *c3_b_setSimStateSideEffectsInfo, const char_T
  *c3_identifier)
{
  const mxArray *c3_y = NULL;
  emlrtMsgIdentifier c3_thisId;
  c3_y = NULL;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  sf_mex_assign(&c3_y, c3_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_b_setSimStateSideEffectsInfo), &c3_thisId), false);
  sf_mex_destroy(&c3_b_setSimStateSideEffectsInfo);
  return c3_y;
}

static const mxArray *c3_h_emlrt_marshallIn(SFc3_G24i_v_sourceInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  const mxArray *c3_y = NULL;
  (void)chartInstance;
  (void)c3_parentId;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_duplicatearraysafe(&c3_u), false);
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_updateDataWrittenToVector(SFc3_G24i_v_sourceInstanceStruct
  *chartInstance, uint32_T c3_vectorIndex)
{
  (void)chartInstance;
  c3_dataWrittenToVector[(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)
    c3_vectorIndex, 0, 5, 1, 0)] = true;
}

static void c3_errorIfDataNotWrittenToFcn(SFc3_G24i_v_sourceInstanceStruct
  *chartInstance, uint32_T c3_vectorIndex, uint32_T c3_dataNumber)
{
  (void)chartInstance;
  _SFD_DATA_READ_BEFORE_WRITE_CHECK(c3_dataNumber, c3_dataWrittenToVector
    [(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)c3_vectorIndex, 0, 5, 1,
    0)]);
}

static void init_dsm_address_info(SFc3_G24i_v_sourceInstanceStruct
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

void sf_c3_G24i_v_source_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1408962042U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2386656458U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(659784475U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1589012227U);
}

mxArray *sf_c3_G24i_v_source_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("SoKhnwC47KL70CxZbPpUTE");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

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
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,5,3,dataFields);

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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxData);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c3_G24i_v_source_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c3_G24i_v_source_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c3_G24i_v_source(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x8'type','srcId','name','auxInfo'{{M[1],M[24],T\"v_ref\",},{M[3],M[26],T\"I_prev1\",},{M[3],M[27],T\"V_REF\",},{M[3],M[25],T\"V_prev1\",},{M[3],M[29],T\"deltaI\",},{M[3],M[28],T\"deltaV\",},{M[8],M[0],T\"is_active_c3_G24i_v_source\",},{M[9],M[0],T\"is_c3_G24i_v_source\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 8, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c3_G24i_v_source_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc3_G24i_v_sourceInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc3_G24i_v_sourceInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _G24i_v_sourceMachineNumber_,
           3,
           5,
           16,
           0,
           9,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize ist own list of scripts */
        init_script_number_translation(_G24i_v_sourceMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_G24i_v_sourceMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _G24i_v_sourceMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"deltaD");
          _SFD_SET_DATA_PROPS(1,2,0,1,"v_ref");
          _SFD_SET_DATA_PROPS(2,0,0,0,"V_prev1");
          _SFD_SET_DATA_PROPS(3,0,0,0,"I_prev1");
          _SFD_SET_DATA_PROPS(4,0,0,0,"V_REF");
          _SFD_SET_DATA_PROPS(5,0,0,0,"deltaV");
          _SFD_SET_DATA_PROPS(6,0,0,0,"deltaI");
          _SFD_SET_DATA_PROPS(7,1,1,0,"V");
          _SFD_SET_DATA_PROPS(8,1,1,0,"I");
          _SFD_STATE_INFO(0,0,0);
          _SFD_STATE_INFO(1,0,0);
          _SFD_STATE_INFO(2,0,0);
          _SFD_STATE_INFO(3,0,0);
          _SFD_STATE_INFO(4,0,0);
          _SFD_CH_SUBSTATE_COUNT(5);
          _SFD_CH_SUBSTATE_DECOMP(0);
          _SFD_CH_SUBSTATE_INDEX(0,0);
          _SFD_CH_SUBSTATE_INDEX(1,1);
          _SFD_CH_SUBSTATE_INDEX(2,2);
          _SFD_CH_SUBSTATE_INDEX(3,3);
          _SFD_CH_SUBSTATE_INDEX(4,4);
          _SFD_ST_SUBSTATE_COUNT(0,0);
          _SFD_ST_SUBSTATE_COUNT(1,0);
          _SFD_ST_SUBSTATE_COUNT(2,0);
          _SFD_ST_SUBSTATE_COUNT(3,0);
          _SFD_ST_SUBSTATE_COUNT(4,0);
        }

        _SFD_CV_INIT_CHART(5,1,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(1,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(2,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(3,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(4,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(12,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(11,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(1,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(14,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(15,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(13,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(3,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(10,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(7,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(6,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(9,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(4,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(8,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(5,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(2,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(4,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(3,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(1,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(0,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(2,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(15,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(15,0,0,1,10,1,10);
        _SFD_CV_INIT_EML(13,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(13,0,0,1,10,1,10);
        _SFD_CV_INIT_EML(3,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(3,0,0,1,10,1,10);
        _SFD_CV_INIT_EML(10,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(10,0,0,1,10,1,10);
        _SFD_CV_INIT_EML(7,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(7,0,0,1,24,1,24);
        _SFD_CV_INIT_EML(6,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(6,0,0,1,24,1,24);
        _SFD_CV_INIT_EML(0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(0,0,0,1,10,1,10);
        _SFD_CV_INIT_EML(9,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(9,0,0,1,9,1,9);
        _SFD_CV_INIT_EML(8,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(8,0,0,1,25,1,25);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);

        {
          real_T *c3_deltaD;
          real_T *c3_v_ref;
          real_T *c3_V;
          real_T *c3_I;
          c3_I = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c3_V = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c3_v_ref = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c3_deltaD = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c3_deltaD);
          _SFD_SET_DATA_VALUE_PTR(1U, c3_v_ref);
          _SFD_SET_DATA_VALUE_PTR(2U, &chartInstance->c3_V_prev1);
          _SFD_SET_DATA_VALUE_PTR(3U, &chartInstance->c3_I_prev1);
          _SFD_SET_DATA_VALUE_PTR(4U, &chartInstance->c3_V_REF);
          _SFD_SET_DATA_VALUE_PTR(5U, &chartInstance->c3_deltaV);
          _SFD_SET_DATA_VALUE_PTR(6U, &chartInstance->c3_deltaI);
          _SFD_SET_DATA_VALUE_PTR(7U, c3_V);
          _SFD_SET_DATA_VALUE_PTR(8U, c3_I);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _G24i_v_sourceMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "dkEEEflxNVSZaAPyEkBDlH";
}

static void sf_opaque_initialize_c3_G24i_v_source(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc3_G24i_v_sourceInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c3_G24i_v_source((SFc3_G24i_v_sourceInstanceStruct*)
    chartInstanceVar);
  initialize_c3_G24i_v_source((SFc3_G24i_v_sourceInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c3_G24i_v_source(void *chartInstanceVar)
{
  enable_c3_G24i_v_source((SFc3_G24i_v_sourceInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c3_G24i_v_source(void *chartInstanceVar)
{
  disable_c3_G24i_v_source((SFc3_G24i_v_sourceInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c3_G24i_v_source(void *chartInstanceVar)
{
  sf_gateway_c3_G24i_v_source((SFc3_G24i_v_sourceInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c3_G24i_v_source(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c3_G24i_v_source
    ((SFc3_G24i_v_sourceInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c3_G24i_v_source();/* state var info */
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

extern void sf_internal_set_sim_state_c3_G24i_v_source(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c3_G24i_v_source();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c3_G24i_v_source((SFc3_G24i_v_sourceInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c3_G24i_v_source(SimStruct* S)
{
  return sf_internal_get_sim_state_c3_G24i_v_source(S);
}

static void sf_opaque_set_sim_state_c3_G24i_v_source(SimStruct* S, const mxArray
  *st)
{
  sf_internal_set_sim_state_c3_G24i_v_source(S, st);
}

static void sf_opaque_terminate_c3_G24i_v_source(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc3_G24i_v_sourceInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_G24i_v_source_optimization_info();
    }

    finalize_c3_G24i_v_source((SFc3_G24i_v_sourceInstanceStruct*)
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
  initSimStructsc3_G24i_v_source((SFc3_G24i_v_sourceInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c3_G24i_v_source(SimStruct *S)
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
    initialize_params_c3_G24i_v_source((SFc3_G24i_v_sourceInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c3_G24i_v_source(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_G24i_v_source_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,3);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,3,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,3,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,3);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,3,3);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,3,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 3; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,3);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1772497510U));
  ssSetChecksum1(S,(1015077506U));
  ssSetChecksum2(S,(3619227902U));
  ssSetChecksum3(S,(3998712355U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c3_G24i_v_source(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c3_G24i_v_source(SimStruct *S)
{
  SFc3_G24i_v_sourceInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc3_G24i_v_sourceInstanceStruct *)utMalloc(sizeof
    (SFc3_G24i_v_sourceInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc3_G24i_v_sourceInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c3_G24i_v_source;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c3_G24i_v_source;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c3_G24i_v_source;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c3_G24i_v_source;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c3_G24i_v_source;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c3_G24i_v_source;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c3_G24i_v_source;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c3_G24i_v_source;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c3_G24i_v_source;
  chartInstance->chartInfo.mdlStart = mdlStart_c3_G24i_v_source;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c3_G24i_v_source;
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

void c3_G24i_v_source_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c3_G24i_v_source(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c3_G24i_v_source(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c3_G24i_v_source(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c3_G24i_v_source_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
