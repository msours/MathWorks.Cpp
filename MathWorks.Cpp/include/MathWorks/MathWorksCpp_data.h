/*
 * MathWorksCpp_data.h
 *
 * Code generation for function 'MathWorksCpp_data'
 *
 */

#ifndef MATHWORKSCPP_DATA_H
#define MATHWORKSCPP_DATA_H

/* Include files */
#include <cstddef>
#include <cstdlib>
#include "rtwtypes.h"
#include "omp.h"
#include "MathWorksCpp_types.h"

/* Variable Declarations */
extern unsigned int method;
extern unsigned int state[625];
extern unsigned int b_state[2];
extern unsigned int c_state;
extern omp_nest_lock_t emlrtNestLockGlobal;
extern boolean_T isInitialized_MathWorksCpp;

#endif

/* End of code generation (MathWorksCpp_data.h) */
