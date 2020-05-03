/*
 * imresize8bit.h
 *
 * Code generation for function 'imresize8bit'
 *
 */

#ifndef IMRESIZE8BIT_H
#define IMRESIZE8BIT_H

/* Include files */
#include <cstddef>
#include <cstdlib>
#include "rtwtypes.h"
#include "omp.h"
#include "MathWorksCpp_types.h"

/* Function Declarations */
ADAPTIVETHRESHOLD_DLL_EXPORT extern void imresize8bit(const emxArray_uint8_T
  *Image, unsigned int NewHeight, unsigned int NewWidth, int Method,
  emxArray_uint8_T *ResizedImage);

#endif

/* End of code generation (imresize8bit.h) */
