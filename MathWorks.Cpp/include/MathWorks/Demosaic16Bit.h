/*
 * Demosaic16Bit.h
 *
 * Code generation for function 'Demosaic16Bit'
 *
 */

#ifndef DEMOSAIC16BIT_H
#define DEMOSAIC16BIT_H

/* Include files */
#include <cstddef>
#include <cstdlib>
#include "rtwtypes.h"
#include "omp.h"
#include "MathWorksCpp_types.h"

/* Function Declarations */
ADAPTIVETHRESHOLD_DLL_EXPORT extern void Demosaic16Bit(const emxArray_uint16_T
  *BayerPatternImage, int ColorConversionCode, emxArray_uint16_T *Image);

#endif

/* End of code generation (Demosaic16Bit.h) */
