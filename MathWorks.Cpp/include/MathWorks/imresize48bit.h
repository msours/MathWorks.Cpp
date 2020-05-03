/*
 * imresize48bit.h
 *
 * Code generation for function 'imresize48bit'
 *
 */

#ifndef IMRESIZE48BIT_H
#define IMRESIZE48BIT_H

/* Include files */
#include <cstddef>
#include <cstdlib>
#include "rtwtypes.h"
#include "omp.h"
#include "MathWorksCpp_types.h"

/* Function Declarations */
ADAPTIVETHRESHOLD_DLL_EXPORT extern void imresize48bit(const emxArray_uint16_T
  *Image, unsigned int NewHeight, unsigned int NewWidth, int Method,
  emxArray_uint16_T *ResizedImage);

#endif

/* End of code generation (imresize48bit.h) */
