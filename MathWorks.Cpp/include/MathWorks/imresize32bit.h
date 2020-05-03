/*
 * imresize32bit.h
 *
 * Code generation for function 'imresize32bit'
 *
 */

#ifndef IMRESIZE32BIT_H
#define IMRESIZE32BIT_H

/* Include files */
#include <cstddef>
#include <cstdlib>
#include "rtwtypes.h"
#include "omp.h"
#include "MathWorksCpp_types.h"

/* Function Declarations */
ADAPTIVETHRESHOLD_DLL_EXPORT extern void imresize32bit(const emxArray_uint8_T
  *Image, unsigned int NewHeight, unsigned int NewWidth, unsigned int Method,
  emxArray_uint8_T *ResizedImage);

#endif

/* End of code generation (imresize32bit.h) */
