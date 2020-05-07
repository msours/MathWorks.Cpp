/*
 * MathWorksCpp_emxutil.h
 *
 * Code generation for function 'MathWorksCpp_emxutil'
 *
 */

#ifndef MATHWORKSCPP_EMXUTIL_H
#define MATHWORKSCPP_EMXUTIL_H

/* Include files */
#include <cstddef>
#include <cstdlib>
#include "rtwtypes.h"
#include "omp.h"
#include "MathWorksCpp_types.h"

/* Function Declarations */
ADAPTIVETHRESHOLD_DLL_EXPORT extern void c_emxFreeStruct_vision_internal
  (c_vision_internal_calibration_c *pStruct);
ADAPTIVETHRESHOLD_DLL_EXPORT extern void c_emxInitStruct_vision_internal
  (c_vision_internal_calibration_c *pStruct);
ADAPTIVETHRESHOLD_DLL_EXPORT extern void emxCopyStruct_struct_T(b_struct_T *dst,
  const b_struct_T *src);
ADAPTIVETHRESHOLD_DLL_EXPORT extern void emxCopyStruct_struct_T1(c_struct_T *dst,
  const c_struct_T *src);
ADAPTIVETHRESHOLD_DLL_EXPORT extern void emxEnsureCapacity_boolean_T
  (emxArray_boolean_T *emxArray, int oldNumel);
ADAPTIVETHRESHOLD_DLL_EXPORT extern void emxEnsureCapacity_int32_T
  (emxArray_int32_T *emxArray, int oldNumel);
ADAPTIVETHRESHOLD_DLL_EXPORT extern void emxEnsureCapacity_int8_T
  (emxArray_int8_T *emxArray, int oldNumel);
ADAPTIVETHRESHOLD_DLL_EXPORT extern void emxEnsureCapacity_real32_T
  (emxArray_real32_T *emxArray, int oldNumel);
ADAPTIVETHRESHOLD_DLL_EXPORT extern void emxEnsureCapacity_real_T
  (emxArray_real_T *emxArray, int oldNumel);
ADAPTIVETHRESHOLD_DLL_EXPORT extern void emxEnsureCapacity_struct0_T
  (emxArray_struct0_T *emxArray, int oldNumel);
ADAPTIVETHRESHOLD_DLL_EXPORT extern void emxEnsureCapacity_struct_T
  (emxArray_struct_T *emxArray, int oldNumel);
ADAPTIVETHRESHOLD_DLL_EXPORT extern void emxEnsureCapacity_struct_T1
  (b_emxArray_struct_T *emxArray, int oldNumel);
ADAPTIVETHRESHOLD_DLL_EXPORT extern void emxEnsureCapacity_uint16_T
  (emxArray_uint16_T *emxArray, int oldNumel);
ADAPTIVETHRESHOLD_DLL_EXPORT extern void emxEnsureCapacity_uint32_T
  (emxArray_uint32_T *emxArray, int oldNumel);
ADAPTIVETHRESHOLD_DLL_EXPORT extern void emxEnsureCapacity_uint8_T
  (emxArray_uint8_T *emxArray, int oldNumel);
ADAPTIVETHRESHOLD_DLL_EXPORT extern void emxFreeStruct_struct_T(b_struct_T
  *pStruct);
ADAPTIVETHRESHOLD_DLL_EXPORT extern void emxFreeStruct_struct_T1(c_struct_T
  *pStruct);
ADAPTIVETHRESHOLD_DLL_EXPORT extern void emxFreeStruct_struct_T2(d_struct_T
  *pStruct);
ADAPTIVETHRESHOLD_DLL_EXPORT extern void emxFreeStruct_struct_T3(e_struct_T
  *pStruct);
ADAPTIVETHRESHOLD_DLL_EXPORT extern void emxFree_boolean_T(emxArray_boolean_T
  **pEmxArray);
ADAPTIVETHRESHOLD_DLL_EXPORT extern void emxFree_int32_T(emxArray_int32_T
  **pEmxArray);
ADAPTIVETHRESHOLD_DLL_EXPORT extern void emxFree_int8_T(emxArray_int8_T
  **pEmxArray);
ADAPTIVETHRESHOLD_DLL_EXPORT extern void emxFree_real32_T(emxArray_real32_T
  **pEmxArray);
ADAPTIVETHRESHOLD_DLL_EXPORT extern void emxFree_real_T(emxArray_real_T
  **pEmxArray);
ADAPTIVETHRESHOLD_DLL_EXPORT extern void emxFree_struct0_T(emxArray_struct0_T
  **pEmxArray);
ADAPTIVETHRESHOLD_DLL_EXPORT extern void emxFree_struct_T(emxArray_struct_T
  **pEmxArray);
ADAPTIVETHRESHOLD_DLL_EXPORT extern void emxFree_struct_T1(b_emxArray_struct_T **
  pEmxArray);
ADAPTIVETHRESHOLD_DLL_EXPORT extern void emxFree_uint16_T(emxArray_uint16_T
  **pEmxArray);
ADAPTIVETHRESHOLD_DLL_EXPORT extern void emxFree_uint32_T(emxArray_uint32_T
  **pEmxArray);
ADAPTIVETHRESHOLD_DLL_EXPORT extern void emxFree_uint8_T(emxArray_uint8_T
  **pEmxArray);
ADAPTIVETHRESHOLD_DLL_EXPORT extern void emxInitStruct_struct_T(b_struct_T
  *pStruct);
ADAPTIVETHRESHOLD_DLL_EXPORT extern void emxInitStruct_struct_T1(c_struct_T
  *pStruct);
ADAPTIVETHRESHOLD_DLL_EXPORT extern void emxInitStruct_struct_T2(d_struct_T
  *pStruct);
ADAPTIVETHRESHOLD_DLL_EXPORT extern void emxInitStruct_struct_T3(e_struct_T
  *pStruct);
ADAPTIVETHRESHOLD_DLL_EXPORT extern void emxInit_boolean_T(emxArray_boolean_T
  **pEmxArray, int numDimensions);
ADAPTIVETHRESHOLD_DLL_EXPORT extern void emxInit_int32_T(emxArray_int32_T
  **pEmxArray, int numDimensions);
ADAPTIVETHRESHOLD_DLL_EXPORT extern void emxInit_int8_T(emxArray_int8_T
  **pEmxArray, int numDimensions);
ADAPTIVETHRESHOLD_DLL_EXPORT extern void emxInit_real32_T(emxArray_real32_T
  **pEmxArray, int numDimensions);
ADAPTIVETHRESHOLD_DLL_EXPORT extern void emxInit_real_T(emxArray_real_T
  **pEmxArray, int numDimensions);
ADAPTIVETHRESHOLD_DLL_EXPORT extern void emxInit_struct0_T(emxArray_struct0_T
  **pEmxArray, int numDimensions);
ADAPTIVETHRESHOLD_DLL_EXPORT extern void emxInit_struct_T(emxArray_struct_T
  **pEmxArray, int numDimensions);
ADAPTIVETHRESHOLD_DLL_EXPORT extern void emxInit_struct_T1(b_emxArray_struct_T **
  pEmxArray, int numDimensions);
ADAPTIVETHRESHOLD_DLL_EXPORT extern void emxInit_uint16_T(emxArray_uint16_T
  **pEmxArray, int numDimensions);
ADAPTIVETHRESHOLD_DLL_EXPORT extern void emxInit_uint32_T(emxArray_uint32_T
  **pEmxArray, int numDimensions);
ADAPTIVETHRESHOLD_DLL_EXPORT extern void emxInit_uint8_T(emxArray_uint8_T
  **pEmxArray, int numDimensions);

#endif

/* End of code generation (MathWorksCpp_emxutil.h) */
