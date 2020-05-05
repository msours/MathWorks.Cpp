/*
 * NormalRand.h
 *
 * Code generation for function 'NormalRand'
 *
 */

#ifndef NORMALRAND_H
#define NORMALRAND_H

/* Include files */
#include <cstddef>
#include <cstdlib>
#include "rtwtypes.h"
#include "omp.h"
#include "MathWorksCpp_types.h"

/* Function Declarations */
ADAPTIVETHRESHOLD_DLL_EXPORT extern void NormalRand(unsigned long long Rows,
  unsigned long long Cols, unsigned int Seed, int Generator, emxArray_real_T
  *b_X);
extern void eml_rand_mcg16807_stateful(unsigned int varargin_1);

#endif

/* End of code generation (NormalRand.h) */
