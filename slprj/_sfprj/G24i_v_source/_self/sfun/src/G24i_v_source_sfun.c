/* Include files */

#include "G24i_v_source_sfun.h"
#include "G24i_v_source_sfun_debug_macros.h"
#include "c5_G24i_v_source.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _G24i_v_sourceMachineNumber_;

/* Function Declarations */

/* Function Definitions */
void G24i_v_source_initializer(void)
{
}

void G24i_v_source_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_G24i_v_source_method_dispatcher(SimStruct *simstructPtr,
  unsigned int chartFileNumber, const char* specsCksum, int_T method, void *data)
{
  if (chartFileNumber==5) {
    c5_G24i_v_source_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

unsigned int sf_G24i_v_source_process_check_sum_call( int nlhs, mxArray * plhs[],
  int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[20];
  if (nrhs<1 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the checksum */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"sf_get_check_sum"))
    return 0;
  plhs[0] = mxCreateDoubleMatrix( 1,4,mxREAL);
  if (nrhs>1 && mxIsChar(prhs[1])) {
    mxGetString(prhs[1], commandName,sizeof(commandName)/sizeof(char));
    commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
    if (!strcmp(commandName,"machine")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2601584474U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(4062640028U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3617265922U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(219411976U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3987852453U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3259867419U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1188018889U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(634556893U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 5:
        {
          extern void sf_c5_G24i_v_source_get_check_sum(mxArray *plhs[]);
          sf_c5_G24i_v_source_get_check_sum(plhs);
          break;
        }

       default:
        ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0.0);
      }
    } else if (!strcmp(commandName,"target")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3031367619U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(4001028638U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3978939492U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(838979348U);
    } else {
      return 0;
    }
  } else {
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4205502269U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2961235474U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(184376280U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2041896818U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_G24i_v_source_autoinheritance_info( int nlhs, mxArray * plhs[],
  int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[32];
  char aiChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the autoinheritance_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_autoinheritance_info"))
    return 0;
  mxGetString(prhs[2], aiChksum,sizeof(aiChksum)/sizeof(char));
  aiChksum[(sizeof(aiChksum)/sizeof(char)-1)] = '\0';

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 5:
      {
        if (strcmp(aiChksum, "Ti5icv8DTBii7kpUHzrAa") == 0) {
          extern mxArray *sf_c5_G24i_v_source_get_autoinheritance_info(void);
          plhs[0] = sf_c5_G24i_v_source_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_G24i_v_source_get_eml_resolved_functions_info( int nlhs, mxArray
  * plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[64];
  if (nrhs<2 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the get_eml_resolved_functions_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_eml_resolved_functions_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 5:
      {
        extern const mxArray
          *sf_c5_G24i_v_source_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c5_G24i_v_source_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_G24i_v_source_third_party_uses_info( int nlhs, mxArray * plhs[],
  int nrhs, const mxArray * prhs[] )
{
  char commandName[64];
  char tpChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the third_party_uses_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  mxGetString(prhs[2], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_third_party_uses_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 5:
      {
        if (strcmp(tpChksum, "e5NhVukxcr1wEL5s3SFXJG") == 0) {
          extern mxArray *sf_c5_G24i_v_source_third_party_uses_info(void);
          plhs[0] = sf_c5_G24i_v_source_third_party_uses_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

unsigned int sf_G24i_v_source_updateBuildInfo_args_info( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
{
  char commandName[64];
  char tpChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the updateBuildInfo_args_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  mxGetString(prhs[2], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_updateBuildInfo_args_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 5:
      {
        if (strcmp(tpChksum, "e5NhVukxcr1wEL5s3SFXJG") == 0) {
          extern mxArray *sf_c5_G24i_v_source_updateBuildInfo_args_info(void);
          plhs[0] = sf_c5_G24i_v_source_updateBuildInfo_args_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

void G24i_v_source_debug_initialize(struct SfDebugInstanceStruct* debugInstance)
{
  _G24i_v_sourceMachineNumber_ = sf_debug_initialize_machine(debugInstance,
    "G24i_v_source","sfun",0,1,0,0,0);
  sf_debug_set_machine_event_thresholds(debugInstance,
    _G24i_v_sourceMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(debugInstance,
    _G24i_v_sourceMachineNumber_,0);
}

void G24i_v_source_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray* load_G24i_v_source_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info("G24i_v_source",
      "G24i_v_source");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_G24i_v_source_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}
