/*
 * UniformRand.h
 *
 * Code generation for function 'UniformRand'
 *
 */

#ifndef UNIFORMRAND_H
#define UNIFORMRAND_H

/* Include files */
#include <cstddef>
#include <cstdlib>
#include "rtwtypes.h"
#include "omp.h"
#include "MathWorksCpp_types.h"

/* Function Declarations */
ADAPTIVETHRESHOLD_DLL_EXPORT extern void UniformRand(unsigned long long Rows,
  unsigned long long Columns, unsigned int Seed, int Generator, emxArray_real_T *
  b_X);

#endif

/* End of code generation (UniformRand.h) */
