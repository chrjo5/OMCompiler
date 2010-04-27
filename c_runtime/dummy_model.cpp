// Simulation code for BouncingBall generated by the OpenModelica Compiler.
#include "modelica.h"
#include "assert.h"
#include "string.h"
#include "simulation_runtime.h"

#if defined(_MSC_VER) && !defined(_SIMULATION_RUNTIME_H)
  #define DLLExport   __declspec( dllexport ) 
#else 
  #define DLLExport /* nothing */
#endif 

#include "dummy_model_functions.cpp"

extern "C" {

}

#define NHELP 6
#define NG 2//number of zero crossing
#define NX 2
#define NY 4
#define NP 2 // number of parameters
#define NO 0 // number of outputvar on topmodel
#define NI 0 // number of inputvar on topmodel
#define NR 3 // number of residuals for initialialization function
#define NEXT 0 // number of external objects
#define MAXORD 5
#define NYSTR 0 // number of alg. string variables
#define NPSTR 0 // number of alg. string variables

static DATA* localData = 0;
#define time localData->timeValue
extern "C" { /* adrpo: this is needed for Visual C++ compilation to work! */
  char *model_name="BouncingBall";
  char *model_dir="";
}
char* state_names[2]={"h", "v"};
char* derivative_names[2]={"der(h)", "der(v)"};
char* algvars_names[4]={"flying", "impact", "v_new", "foo"};
char* input_names[1] = {""};
char* output_names[1] = {""};
char* param_names[2]={"e", "g"};
char* string_alg_names[1] = {""};
char* string_param_names[1] = {""};

char* state_comments[2]={ "height of ball",  "velocity of ball"};
char* derivative_comments[2]={ "height of ball",  "velocity of ball"};
char* algvars_comments[4]={ "true, if ball is flying", "", "", ""};
char* input_comments[1] = {""};
char* output_comments[1] = {""};
char* param_comments[2]={ "coefficient of restitution",  "gravity acceleration"};
char* string_param_comments[1] = {""};
char* string_alg_comments[1] = {""};

#define $g localData->parameters[1]
#define $e localData->parameters[0]
#define $foo localData->algebraics[3]
#define $v_new localData->algebraics[2]
#define $impact localData->algebraics[1]
#define $flying localData->algebraics[0]
#define $v localData->states[1]
#define $DER$v localData->statesDerivatives[1]
#define $h localData->states[0]
#define $DER$h localData->statesDerivatives[0]

char* getName( double* ptr)
{
  if( &$g == ptr ) return param_names[1];
  if( &$e == ptr ) return param_names[0];
  if( &$foo == ptr ) return algvars_names[3];
  if( &$v_new == ptr ) return algvars_names[2];
  if( &$impact == ptr ) return algvars_names[1];
  if( &$flying == ptr ) return algvars_names[0];
  if( &$DER$v == ptr ) return derivative_names[1];
  if( &$v == ptr ) return state_names[1];
  if( &$DER$h == ptr ) return derivative_names[0];
  if( &$h == ptr ) return state_names[0];
  return "";
}

static char init_fixed[NX+NX+NY+NP]={
	1/*h*/, 1/*v*/, 1/*default*/, 1/*default*/, 
	0/*flying*/, 0/*impact*/, 0/*v_new*/, 
	0/*foo*/, 1/*e*/, 1/*g*/
};

char var_attr[NX+NY+NP]={/*h:*/1+0, /*v:*/1+0, /*flying:*/8+16, /*impact:*/8+16, 
/*v_new:*/1+16, /*foo:*/4+16, /*e:*/1+0, 
/*g:*/1+0};

#define DIVISION(a,b,c) ((b != 0) ? a / b : a / division_error(b,c))


int encounteredDivisionByZero = 0;
double division_error(double b,const char* division_str)
{
  if(!encounteredDivisionByZero){
    fprintf(stderr,"ERROR: Division by zero in partial equation: %s.\n",division_str);
    encounteredDivisionByZero = 1;
   }
   return b;
}

void setLocalData(DATA* data)
{
   localData = data;
}

DATA* initializeDataStruc(DATA_FLAGS flags)
{
  DATA* returnData = (DATA*)malloc(sizeof(DATA));

  if(!returnData) //error check
    return 0;

  memset(returnData,0,sizeof(DATA));
  returnData->nStates = NX;
  returnData->nAlgebraic = NY;
  returnData->nParameters = NP;
  returnData->nInputVars = NI;
  returnData->nOutputVars = NO;
  returnData->nZeroCrossing = NG;
  returnData->nInitialResiduals = NR;
  returnData->nHelpVars = NHELP;
  returnData->stringVariables.nParameters = NPSTR;
  returnData->stringVariables.nAlgebraic = NYSTR;

  if(flags & STATES && returnData->nStates) {
    returnData->states = (double*) malloc(sizeof(double)*returnData->nStates);
    returnData->oldStates = (double*) malloc(sizeof(double)*returnData->nStates);
    returnData->oldStates2 = (double*) malloc(sizeof(double)*returnData->nStates);
    assert(returnData->states&&returnData->oldStates&&returnData->oldStates2);
    memset(returnData->states,0,sizeof(double)*returnData->nStates);
    memset(returnData->oldStates,0,sizeof(double)*returnData->nStates);
    memset(returnData->oldStates2,0,sizeof(double)*returnData->nStates);
  } else {
    returnData->states = 0;
    returnData->oldStates = 0;
    returnData->oldStates2 = 0;
  }

  if(flags & STATESDERIVATIVES && returnData->nStates) {
    returnData->statesDerivatives = (double*) malloc(sizeof(double)*returnData->nStates);
    returnData->oldStatesDerivatives = (double*) malloc(sizeof(double)*returnData->nStates);
    returnData->oldStatesDerivatives2 = (double*) malloc(sizeof(double)*returnData->nStates);
    assert(returnData->statesDerivatives&&returnData->oldStatesDerivatives&&returnData->oldStatesDerivatives2);
    memset(returnData->statesDerivatives,0,sizeof(double)*returnData->nStates);
    memset(returnData->oldStatesDerivatives,0,sizeof(double)*returnData->nStates);
    memset(returnData->oldStatesDerivatives2,0,sizeof(double)*returnData->nStates);
  } else {
    returnData->statesDerivatives = 0;
    returnData->oldStatesDerivatives = 0;
    returnData->oldStatesDerivatives2 = 0;
  }

  if(flags & HELPVARS && returnData->nHelpVars) {
    returnData->helpVars = (double*) malloc(sizeof(double)*returnData->nHelpVars);
    assert(returnData->helpVars);
    memset(returnData->helpVars,0,sizeof(double)*returnData->nHelpVars);
  } else {
    returnData->helpVars = 0;
  }

  if(flags & ALGEBRAICS && returnData->nAlgebraic) {
    returnData->algebraics = (double*) malloc(sizeof(double)*returnData->nAlgebraic);
    returnData->oldAlgebraics = (double*) malloc(sizeof(double)*returnData->nAlgebraic);
    returnData->oldAlgebraics2 = (double*) malloc(sizeof(double)*returnData->nAlgebraic);
    assert(returnData->algebraics&&returnData->oldAlgebraics&&returnData->oldAlgebraics2);
    memset(returnData->algebraics,0,sizeof(double)*returnData->nAlgebraic);
    memset(returnData->oldAlgebraics,0,sizeof(double)*returnData->nAlgebraic);
    memset(returnData->oldAlgebraics2,0,sizeof(double)*returnData->nAlgebraic);
  } else {
    returnData->algebraics = 0;
    returnData->oldAlgebraics = 0;
    returnData->oldAlgebraics2 = 0;
    returnData->stringVariables.algebraics = 0;
  }

  if (flags & ALGEBRAICS && returnData->stringVariables.nAlgebraic) {
    returnData->stringVariables.algebraics = (char**)malloc(sizeof(char*)*returnData->stringVariables.nAlgebraic);
    assert(returnData->stringVariables.algebraics);
    memset(returnData->stringVariables.algebraics,0,sizeof(char*)*returnData->stringVariables.nAlgebraic);
  } else {
    returnData->stringVariables.algebraics=0;
  }

  if(flags & PARAMETERS && returnData->nParameters) {
    returnData->parameters = (double*) malloc(sizeof(double)*returnData->nParameters);
    assert(returnData->parameters);
    memset(returnData->parameters,0,sizeof(double)*returnData->nParameters);
  } else {
    returnData->parameters = 0;
  }

  if (flags & PARAMETERS && returnData->stringVariables.nParameters) {
  	  returnData->stringVariables.parameters = (char**)malloc(sizeof(char*)*returnData->stringVariables.nParameters);
      assert(returnData->stringVariables.parameters);
      memset(returnData->stringVariables.parameters,0,sizeof(char*)*returnData->stringVariables.nParameters);
  } else {
      returnData->stringVariables.parameters=0;
  }

  if(flags & OUTPUTVARS && returnData->nOutputVars) {
    returnData->outputVars = (double*) malloc(sizeof(double)*returnData->nOutputVars);
    assert(returnData->outputVars);
    memset(returnData->outputVars,0,sizeof(double)*returnData->nOutputVars);
  } else {
    returnData->outputVars = 0;
  }

  if(flags & INPUTVARS && returnData->nInputVars) {
    returnData->inputVars = (double*) malloc(sizeof(double)*returnData->nInputVars);
    assert(returnData->inputVars);
    memset(returnData->inputVars,0,sizeof(double)*returnData->nInputVars);
  } else {
    returnData->inputVars = 0;
  }

  if(flags & INITIALRESIDUALS && returnData->nInitialResiduals) {
    returnData->initialResiduals = (double*) malloc(sizeof(double)*returnData->nInitialResiduals);
    assert(returnData->initialResiduals);
    memset(returnData->initialResiduals,0,sizeof(double)*returnData->nInitialResiduals);
  } else {
    returnData->initialResiduals = 0;
  }

  if(flags & INITFIXED) {
    returnData->initFixed = init_fixed;
  } else {
    returnData->initFixed = 0;
  }

  /*   names   */
  if(flags & MODELNAME) {
    returnData->modelName = model_name;
  } else {
    returnData->modelName = 0;
  }

  if(flags & STATESNAMES) {
    returnData->statesNames = state_names;
  } else {
    returnData->statesNames = 0;
  }

  if(flags & STATESDERIVATIVESNAMES) {
    returnData->stateDerivativesNames = derivative_names;
  } else {
    returnData->stateDerivativesNames = 0;
  }

  if(flags & ALGEBRAICSNAMES) {
    returnData->algebraicsNames = algvars_names;
  } else {
    returnData->algebraicsNames = 0;
  }

  if(flags & PARAMETERSNAMES) {
    returnData->parametersNames = param_names;
  } else {
    returnData->parametersNames = 0;
  }

  if(flags & INPUTNAMES) {
    returnData->inputNames = input_names;
  } else {
    returnData->inputNames = 0;
  }

  if(flags & OUTPUTNAMES) {
    returnData->outputNames = output_names;
  } else {
    returnData->outputNames = 0;
  }

  /*   comments  */
  if(flags & STATESCOMMENTS) {
    returnData->statesComments = state_comments;
  } else {
    returnData->statesComments = 0;
  }

  if(flags & STATESDERIVATIVESCOMMENTS) {
    returnData->stateDerivativesComments = derivative_comments;
  } else {
    returnData->stateDerivativesComments = 0;
  }

  if(flags & ALGEBRAICSCOMMENTS) {
    returnData->algebraicsComments = algvars_comments;
  } else {
    returnData->algebraicsComments = 0;
  }

  if(flags & PARAMETERSCOMMENTS) {
    returnData->parametersComments = param_comments;
  } else {
    returnData->parametersComments = 0;
  }

  if(flags & INPUTCOMMENTS) {
    returnData->inputComments = input_comments;
  } else {
    returnData->inputComments = 0;
  }

  if(flags & OUTPUTCOMMENTS) {
    returnData->outputComments = output_comments;
  } else {
    returnData->outputComments = 0;
  }

  if (flags & EXTERNALVARS) {
    returnData->extObjs = (void**)malloc(sizeof(void*)*NEXT);
    if (!returnData->extObjs) {
      printf("error allocating external objects\n");
      exit(-2);
    }
    memset(returnData->extObjs,0,sizeof(void*)*NEXT);
    setLocalData(returnData); /* must be set since used by constructors*/
  }
  return returnData;
}

void deInitializeDataStruc(DATA* data, DATA_FLAGS flags)
{
  if(!data)
    return;

  if(flags & STATES && data->states) {
    free(data->states);
    data->states = 0;
  }

  if(flags & STATESDERIVATIVES && data->statesDerivatives) {
    free(data->statesDerivatives);
    data->statesDerivatives = 0;
  }

  if(flags & ALGEBRAICS && data->algebraics) {
    free(data->algebraics);
    data->algebraics = 0;
  }

  if(flags & PARAMETERS && data->parameters) {
    free(data->parameters);
    data->parameters = 0;
  }

  if(flags & OUTPUTVARS && data->inputVars) {
    free(data->inputVars);
    data->inputVars = 0;
  }

  if(flags & INPUTVARS && data->outputVars) {
    free(data->outputVars);
    data->outputVars = 0;
  }

  if(flags & INITIALRESIDUALS && data->initialResiduals){
    free(data->initialResiduals);
    data->initialResiduals = 0;
  }
  if (flags & EXTERNALVARS && data->extObjs) {
    free(data->extObjs);
    data->extObjs = 0;
  }
}

int functionDAE_output()
{
  state mem_state;
  mem_state = get_memory_state();
  restore_memory_state(mem_state);
  return 0;
}

int functionDAE_output2()
{
  state mem_state;
  modelica_boolean tmp0;
  modelica_integer tmp1;
  mem_state = get_memory_state();
  tmp0 = $impact;
  if (tmp0) {
    tmp1 = 1;
  }
  else {
    tmp1 = 2;
  }
  $foo = tmp1;
  restore_memory_state(mem_state);
  return 0;
}

/*
*/
int input_function()
{
  return 0;
}

/*
*/
int output_function()
{
  return 0;
}

int functionDAE_res(double *t, double *x, double *xd, double *delta, fortran_integer *ires, double *rpar, fortran_integer* ipar)
{
  int i;
  double temp_xd[NX];
  double* statesBackup;
  double* statesDerivativesBackup;
  double timeBackup;
  statesBackup = localData->states;
  statesDerivativesBackup = localData->statesDerivatives;
  timeBackup = localData->timeValue;
  localData->states = x;
  for (i=0; i<localData->nStates; i++) temp_xd[i]=localData->statesDerivatives[i];
  
  localData->statesDerivatives = temp_xd;
  localData->timeValue = *t;
  
  functionODE();
  /* get the difference between the temp_xd(=localData->statesDerivatives) and xd(=statesDerivativesBackup) */
  for (i=0; i < localData->nStates; i++) delta[i]=localData->statesDerivatives[i]-statesDerivativesBackup[i];
  
  localData->states = statesBackup;
  localData->statesDerivatives = statesDerivativesBackup;
  localData->timeValue = timeBackup;
  if (modelErrorCode) {
      if (ires) *ires = -1;
      modelErrorCode =0;
  }
  return 0;
}

int function_zeroCrossing(fortran_integer *neqm, double *t, double *x, fortran_integer *ng, double *gout, double *rpar, fortran_integer* ipar)
{
  double timeBackup;
  state mem_state;
  mem_state = get_memory_state();
  timeBackup = localData->timeValue;
  localData->timeValue = *t;
  functionODE();
  functionDAE_output();
  ZEROCROSSING(0,LessEq($h,0.0));
  ZEROCROSSING(1,LessEq($v,0.0));
  restore_memory_state(mem_state);
  localData->timeValue = timeBackup;
  return 0;
}

int handleZeroCrossing(long index)
{
  state mem_state;
  mem_state = get_memory_state();
  switch(index) {
    case 0:
      save($impact);
      break;

    case 1:
      break;

    default: break;
  }
  restore_memory_state(mem_state);
  return 0;
}

int function_updateDependents()
{
  state mem_state;
  modelica_boolean tmp0;
  modelica_boolean tmp1;
  modelica_real tmp2;
  modelica_boolean tmp3;
  modelica_integer tmp4;
  modelica_boolean tmp5;
  modelica_boolean tmp6;
  modelica_boolean tmp7;
  modelica_boolean tmp8;
  modelica_boolean tmp9;
  modelica_boolean tmp10;
  inUpdate=initial()?0:1;
  mem_state = get_memory_state();
  $DER$h = $v;
  RELATIONLESSEQ(tmp0,$h,0.0);
  $impact = tmp0;
  tmp1 = $flying;
  if (tmp1) {
    tmp2 = (-$g);
  }
  else {
    tmp2 = 0.0;
  }
  $DER$v = tmp2;
  tmp3 = $impact;
  if (tmp3) {
    tmp4 = 1;
  }
  else {
    tmp4 = 2;
  }
  $foo = tmp4;
  RELATIONLESSEQ(tmp5,$h,0.0);
  RELATIONLESSEQ(tmp6,$v,0.0);
  localData->helpVars[2] = (tmp5 && tmp6);
  localData->helpVars[3] = $impact;
  RELATIONLESSEQ(tmp7,$h,0.0);
  RELATIONLESSEQ(tmp8,$v,0.0);
  localData->helpVars[0] = (tmp7 && tmp8);
  localData->helpVars[1] = $impact;
  RELATIONLESSEQ(tmp9,$h,0.0);
  RELATIONLESSEQ(tmp10,$v,0.0);
  localData->helpVars[4] = (tmp9 && tmp10);
  localData->helpVars[5] = $impact;
  restore_memory_state(mem_state);
  inUpdate=0;
  return 0;
}

int function_updateDepend()
{
  state mem_state;
  modelica_boolean tmp0;
  modelica_boolean tmp1;
  modelica_boolean tmp2;
  edge_rettype tmp3;
  modelica_boolean tmp4;
  modelica_real tmp5;
  modelica_real tmp6;
  modelica_boolean tmp7;
  modelica_boolean tmp8;
  modelica_boolean tmp9;
  modelica_boolean tmp10;
  modelica_real tmp11;
  modelica_boolean tmp12;
  modelica_integer tmp13;
  modelica_boolean tmp14;
  modelica_boolean tmp15;
  inUpdate=initial()?0:1;
  mem_state = get_memory_state();
  $DER$h = $v;
  RELATIONLESSEQ(tmp0,$h,0.0);
  $impact = tmp0;
  localData->helpVars[3] = $impact;
  RELATIONLESSEQ(tmp1,$h,0.0);
  RELATIONLESSEQ(tmp2,$v,0.0);
  localData->helpVars[2] = (tmp1 && tmp2);
  if (edge(localData->helpVars[3]) || edge(localData->helpVars[2])) {
    tmp3 = edge($impact);
    tmp4 = tmp3;
    if (tmp4) {
      tmp6 = pre($v);
      tmp5 = ((-$e) * tmp6);
    }
    else {
      tmp5 = 0.0;
    }
    $v_new=tmp5;
  }else{
    $v_new= pre($v_new);
  }
  localData->helpVars[3] = $impact;
  RELATIONLESSEQ(tmp7,$h,0.0);
  RELATIONLESSEQ(tmp8,$v,0.0);
  localData->helpVars[2] = (tmp7 && tmp8);
  if (edge(localData->helpVars[3]) || edge(localData->helpVars[2])) {
    RELATIONGREATER(tmp9,$v_new,0.0);
    $flying=tmp9;
  }else{
    $flying= pre($flying);
  }
  tmp10 = $flying;
  if (tmp10) {
    tmp11 = (-$g);
  }
  else {
    tmp11 = 0.0;
  }
  $DER$v = tmp11;
  tmp12 = $impact;
  if (tmp12) {
    tmp13 = 1;
  }
  else {
    tmp13 = 2;
  }
  $foo = tmp13;
  localData->helpVars[3] = $impact;
  RELATIONLESSEQ(tmp14,$h,0.0);
  RELATIONLESSEQ(tmp15,$v,0.0);
  localData->helpVars[2] = (tmp14 && tmp15);
  if (edge(localData->helpVars[3]) || edge(localData->helpVars[2])) {
        $v = $v_new;

  }else{
  }
  restore_memory_state(mem_state);
  inUpdate=0;
  return 0;
}

int function_onlyZeroCrossings(double *gout,double *t)
{
  state mem_state;
  mem_state = get_memory_state();
  ZEROCROSSING(0,LessEq($h,0.0));
  ZEROCROSSING(1,LessEq($v,0.0));
  restore_memory_state(mem_state);
  return 0;
}

int checkForDiscreteChanges()
{
  int needToIterate=0;
if (change($foo)) { needToIterate=1; }
  
  
  if (change($flying)) { needToIterate=1; }
  return needToIterate;
}
int function_storeDelayed()
{
  state mem_state;
  mem_state = get_memory_state();
  restore_memory_state(mem_state);
  return 0;
}

int function_when(int i)
{
  edge_rettype tmp0;
  modelica_boolean tmp1;
  modelica_real tmp2;
  modelica_real tmp3;
  modelica_boolean tmp4;
  state mem_state;
  mem_state = get_memory_state();
  switch(i) {
     case 0: //when {$h <= 0.0 AND $v <= 0.0,$impact}

    save($v_new);

    tmp0 = edge($impact);
    tmp1 = tmp0;
    if (tmp1) {
      tmp3 = pre($v);
      tmp2 = ((-$e) * tmp3);
    }
    else {
      tmp2 = 0.0;
    }
    $v_new = tmp2;
    
      break;

     case 1: //when {$h <= 0.0 AND $v <= 0.0,$impact}

    save($flying);

    RELATIONGREATER(tmp4,$v_new,0.0);
    $flying = tmp4;
    
      break;

     case 2: //when {$h <= 0.0 AND $v <= 0.0,$impact}

        $v = $v_new;

      break;

    default: break;
  }
  restore_memory_state(mem_state);
  return 0;
}

int functionODE()
{
  state mem_state;
  modelica_boolean tmp0;
  modelica_real tmp1;
  mem_state = get_memory_state();
  $DER$h = $v;
  tmp0 = $flying;
  if (tmp0) {
    tmp1 = (-$g);
  }
  else {
    tmp1 = 0.0;
  }
  $DER$v = tmp1;
  restore_memory_state(mem_state);
  return 0;
}

int initial_function()
{
  return 0;
}

int initial_residual()
{
  modelica_boolean tmp0;
  modelica_real tmp1;
  int i=0;
  state mem_state;
  mem_state = get_memory_state();
  tmp0 = $flying;
  if (tmp0) {
    tmp1 = (-$g);
  }
  else {
    tmp1 = 0.0;
  }
  localData->initialResiduals[i++] = ($DER$v - tmp1);
  localData->initialResiduals[i++] = ($DER$h - $v);
  localData->initialResiduals[i++] = ($h - 1.0);
  restore_memory_state(mem_state);
  return 0;
}

int bound_parameters()
{
  state mem_state;
  mem_state = get_memory_state();
  restore_memory_state(mem_state);
  return 0;
}

int checkForDiscreteVarChanges()
{
  int needToIterate=0;
  if (edge(localData->helpVars[2])) AddEvent(0 + localData->nZeroCrossing);
  if (edge(localData->helpVars[3])) AddEvent(0 + localData->nZeroCrossing);
  if (edge(localData->helpVars[0])) AddEvent(1 + localData->nZeroCrossing);
  if (edge(localData->helpVars[1])) AddEvent(1 + localData->nZeroCrossing);
  if (edge(localData->helpVars[4])) AddEvent(2 + localData->nZeroCrossing);
  if (edge(localData->helpVars[5])) AddEvent(2 + localData->nZeroCrossing);
  if (change($foo)) { needToIterate=1; }
  
  
  if (change($flying)) { needToIterate=1; }
  for (long i = 0; i < localData->nHelpVars; i++) {
    if (change(localData->helpVars[i])) { needToIterate=1; }
  }
  return needToIterate;
}


/* provide a dummy MAIN__ for libf2c */
extern "C"
{
  void MAIN__(void)
  {
  }

}

