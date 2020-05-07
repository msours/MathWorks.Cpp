/*
 * MathWorksCpp_emxAPI.h
 *
 * Code generation for function 'MathWorksCpp_emxAPI'
 *
 */

#ifndef MATHWORKSCPP_EMXAPI_H
#define MATHWORKSCPP_EMXAPI_H

/* Include files */
#include <cstddef>
#include <cstdlib>
#include "rtwtypes.h"
#include "omp.h"
#include "MathWorksCpp_types.h"

/* Function Declarations */
ADAPTIVETHRESHOLD_DLL_EXPORT extern emxArray_boolean_T *emxCreateND_boolean_T
  (int numDimensions, const int *size);
ADAPTIVETHRESHOLD_DLL_EXPORT extern emxArray_real_T *emxCreateND_real_T(int
  numDimensions, const int *size);
ADAPTIVETHRESHOLD_DLL_EXPORT extern emxArray_struct0_T *emxCreateND_struct0_T
  (int numDimensions, const int *size);
ADAPTIVETHRESHOLD_DLL_EXPORT extern emxArray_uint16_T *emxCreateND_uint16_T(int
  numDimensions, const int *size);
ADAPTIVETHRESHOLD_DLL_EXPORT extern emxArray_uint8_T *emxCreateND_uint8_T(int
  numDimensions, const int *size);
ADAPTIVETHRESHOLD_DLL_EXPORT extern emxArray_boolean_T
  *emxCreateWrapperND_boolean_T(boolean_T *data, int numDimensions, const int
  *size);
ADAPTIVETHRESHOLD_DLL_EXPORT extern emxArray_real_T *emxCreateWrapperND_real_T
  (double *data, int numDimensions, const int *size);
ADAPTIVETHRESHOLD_DLL_EXPORT extern emxArray_struct0_T
  *emxCreateWrapperND_struct0_T(struct0_T *data, int numDimensions, const int
  *size);
ADAPTIVETHRESHOLD_DLL_EXPORT extern emxArray_uint16_T
  *emxCreateWrapperND_uint16_T(unsigned short *data, int numDimensions, const
  int *size);
ADAPTIVETHRESHOLD_DLL_EXPORT extern emxArray_uint8_T *emxCreateWrapperND_uint8_T
  (unsigned char *data, int numDimensions, const int *size);
ADAPTIVETHRESHOLD_DLL_EXPORT extern emxArray_boolean_T
  *emxCreateWrapper_boolean_T(boolean_T *data, int rows, int cols);
ADAPTIVETHRESHOLD_DLL_EXPORT extern emxArray_real_T *emxCreateWrapper_real_T
  (double *data, int rows, int cols);
ADAPTIVETHRESHOLD_DLL_EXPORT extern emxArray_struct0_T
  *emxCreateWrapper_struct0_T(struct0_T *data, int rows, int cols);
ADAPTIVETHRESHOLD_DLL_EXPORT extern emxArray_uint16_T *emxCreateWrapper_uint16_T
  (unsigned short *data, int rows, int cols);
ADAPTIVETHRESHOLD_DLL_EXPORT extern emxArray_uint8_T *emxCreateWrapper_uint8_T
  (unsigned char *data, int rows, int cols);
ADAPTIVETHRESHOLD_DLL_EXPORT extern emxArray_boolean_T *emxCreate_boolean_T(int
  rows, int cols);
ADAPTIVETHRESHOLD_DLL_EXPORT extern emxArray_real_T *emxCreate_real_T(int rows,
  int cols);
ADAPTIVETHRESHOLD_DLL_EXPORT extern emxArray_struct0_T *emxCreate_struct0_T(int
  rows, int cols);
ADAPTIVETHRESHOLD_DLL_EXPORT extern emxArray_uint16_T *emxCreate_uint16_T(int
  rows, int cols);
ADAPTIVETHRESHOLD_DLL_EXPORT extern emxArray_uint8_T *emxCreate_uint8_T(int rows,
  int cols);
ADAPTIVETHRESHOLD_DLL_EXPORT extern void emxDestroyArray_boolean_T
  (emxArray_boolean_T *emxArray);
ADAPTIVETHRESHOLD_DLL_EXPORT extern void emxDestroyArray_real_T(emxArray_real_T *
  emxArray);
ADAPTIVETHRESHOLD_DLL_EXPORT extern void emxDestroyArray_struct0_T
  (emxArray_struct0_T *emxArray);
ADAPTIVETHRESHOLD_DLL_EXPORT extern void emxDestroyArray_uint16_T
  (emxArray_uint16_T *emxArray);
ADAPTIVETHRESHOLD_DLL_EXPORT extern void emxDestroyArray_uint8_T
  (emxArray_uint8_T *emxArray);
ADAPTIVETHRESHOLD_DLL_EXPORT extern void emxInitArray_boolean_T
  (emxArray_boolean_T **pEmxArray, int numDimensions);
ADAPTIVETHRESHOLD_DLL_EXPORT extern void emxInitArray_real_T(emxArray_real_T
  **pEmxArray, int numDimensions);
ADAPTIVETHRESHOLD_DLL_EXPORT extern void emxInitArray_struct0_T
  (emxArray_struct0_T **pEmxArray, int numDimensions);
ADAPTIVETHRESHOLD_DLL_EXPORT extern void emxInitArray_uint16_T(emxArray_uint16_T
  **pEmxArray, int numDimensions);
ADAPTIVETHRESHOLD_DLL_EXPORT extern void emxInitArray_uint8_T(emxArray_uint8_T **
  pEmxArray, int numDimensions);

#endif

/* End of code generation (MathWorksCpp_emxAPI.h) */
