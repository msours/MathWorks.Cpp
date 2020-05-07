/*
 * detectCheckerboardPoints8Bit.h
 *
 * Code generation for function 'detectCheckerboardPoints8Bit'
 *
 */

#ifndef DETECTCHECKERBOARDPOINTS8BIT_H
#define DETECTCHECKERBOARDPOINTS8BIT_H

/* Include files */
#include <cstddef>
#include <cstdlib>
#include "rtwtypes.h"
#include "omp.h"
#include "MathWorksCpp_types.h"

/* Function Declarations */
ADAPTIVETHRESHOLD_DLL_EXPORT extern void detectCheckerboardPoints8Bit(const
  emxArray_uint8_T *ImageData, double CornerThreshold, emxArray_real_T
  *imagePoints, double boardSize[2]);

#endif

/* End of code generation (detectCheckerboardPoints8Bit.h) */
