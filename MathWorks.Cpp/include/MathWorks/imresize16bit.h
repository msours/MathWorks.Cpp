/*
 * imresize16bit.h
 *
 * Code generation for function 'imresize16bit'
 *
 */

#ifndef IMRESIZE16BIT_H
#define IMRESIZE16BIT_H

/* Include files */
#include <cstddef>
#include <cstdlib>
#include "rtwtypes.h"
#include "omp.h"
#include "MathWorksCpp_types.h"

/* Function Declarations */
ADAPTIVETHRESHOLD_DLL_EXPORT extern void imresize16bit(const emxArray_uint16_T
  *Image, unsigned long long NewHeight, unsigned long long NewWidth, int Method,
  emxArray_uint16_T *ResizedImage);

#endif

/* End of code generation (imresize16bit.h) */
