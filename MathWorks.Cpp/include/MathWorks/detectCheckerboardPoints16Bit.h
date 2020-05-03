/*
 * detectCheckerboardPoints16Bit.h
 *
 * Code generation for function 'detectCheckerboardPoints16Bit'
 *
 */

#ifndef DETECTCHECKERBOARDPOINTS16BIT_H
#define DETECTCHECKERBOARDPOINTS16BIT_H

/* Include files */
#include <cstddef>
#include <cstdlib>
#include "rtwtypes.h"
#include "omp.h"
#include "MathWorksCpp_types.h"

/* Function Declarations */
ADAPTIVETHRESHOLD_DLL_EXPORT extern void detectCheckerboardPoints16Bit(const
  emxArray_uint16_T *ImageData, double CornerThreshold, emxArray_real_T
  *imagePoints, double boardSize[2]);

#endif

/* End of code generation (detectCheckerboardPoints16Bit.h) */
