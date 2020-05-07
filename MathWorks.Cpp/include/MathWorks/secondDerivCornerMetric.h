/*
 * secondDerivCornerMetric.h
 *
 * Code generation for function 'secondDerivCornerMetric'
 *
 */

#ifndef SECONDDERIVCORNERMETRIC_H
#define SECONDDERIVCORNERMETRIC_H

/* Include files */
#include <cstddef>
#include <cstdlib>
#include "rtwtypes.h"
#include "omp.h"
#include "MathWorksCpp_types.h"

/* Function Declarations */
extern void secondDerivCornerMetric(const emxArray_real32_T *b_I,
  emxArray_real32_T *cxy, emxArray_real32_T *c45, emxArray_real32_T *Ix,
  emxArray_real32_T *Iy, emxArray_real32_T *Ixy, emxArray_real32_T *I_45_45);

#endif

/* End of code generation (secondDerivCornerMetric.h) */
