/*
 * bwconncomp.h
 *
 * Code generation for function 'bwconncomp'
 *
 */

#ifndef BWCONNCOMP_H
#define BWCONNCOMP_H

/* Include files */
#include <cstddef>
#include <cstdlib>
#include "rtwtypes.h"
#include "omp.h"
#include "MathWorksCpp_types.h"

/* Function Declarations */
extern void bwconncomp(const emxArray_boolean_T *varargin_1, double
  *CC_Connectivity, double CC_ImageSize[2], double *CC_NumObjects,
  emxArray_real_T *CC_RegionIndices, emxArray_int32_T *CC_RegionLengths);

#endif

/* End of code generation (bwconncomp.h) */
