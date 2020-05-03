/*
 * randn.h
 *
 * Code generation for function 'randn'
 *
 */

#ifndef RANDN_H
#define RANDN_H

/* Include files */
#include <cstddef>
#include <cstdlib>
#include "rtwtypes.h"
#include "omp.h"
#include "MathWorksCpp_types.h"

/* Function Declarations */
extern void genrand_uint32_vector(unsigned int mt[625], unsigned int u[2]);
extern void randn(unsigned int varargin_1, unsigned int varargin_2,
                  emxArray_real_T *r);

#endif

/* End of code generation (randn.h) */
