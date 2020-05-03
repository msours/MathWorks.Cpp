/*
 * Demosaic8Bit.h
 *
 * Code generation for function 'Demosaic8Bit'
 *
 */

#ifndef DEMOSAIC8BIT_H
#define DEMOSAIC8BIT_H

/* Include files */
#include <cstddef>
#include <cstdlib>
#include "rtwtypes.h"
#include "omp.h"
#include "MathWorksCpp_types.h"

/* Function Declarations */
ADAPTIVETHRESHOLD_DLL_EXPORT extern void Demosaic8Bit(const emxArray_uint8_T
  *BayerPatternImage, int ColorConversionCode, emxArray_uint8_T *Image);

#endif

/* End of code generation (Demosaic8Bit.h) */
