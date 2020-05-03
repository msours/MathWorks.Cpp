/*
 * rand.h
 *
 * Code generation for function 'rand'
 *
 */

#ifndef RAND_H
#define RAND_H

/* Include files */
#include <cstddef>
#include <cstdlib>
#include "rtwtypes.h"
#include "omp.h"
#include "MathWorksCpp_types.h"

/* Function Declarations */
extern double b_rand();
extern void c_rand(unsigned int varargin_1, unsigned int varargin_2,
                   emxArray_real_T *r);

#endif

/* End of code generation (rand.h) */
