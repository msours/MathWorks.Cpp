/*
 * detectCheckerboard.h
 *
 * Code generation for function 'detectCheckerboard'
 *
 */

#ifndef DETECTCHECKERBOARD_H
#define DETECTCHECKERBOARD_H

/* Include files */
#include <cstddef>
#include <cstdlib>
#include "rtwtypes.h"
#include "omp.h"
#include "MathWorksCpp_types.h"

/* Function Declarations */
extern void b_detectCheckerboard(const emxArray_real32_T *b_I, double
  peakThreshold, emxArray_real_T *points, double boardSize[2]);
extern void detectCheckerboard(const emxArray_real32_T *b_I, double
  peakThreshold, emxArray_real_T *points, double boardSize[2]);

#endif

/* End of code generation (detectCheckerboard.h) */
