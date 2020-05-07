/*
 * regionprops.h
 *
 * Code generation for function 'regionprops'
 *
 */

#ifndef REGIONPROPS_H
#define REGIONPROPS_H

/* Include files */
#include <cstddef>
#include <cstdlib>
#include "rtwtypes.h"
#include "omp.h"
#include "MathWorksCpp_types.h"

/* Function Declarations */
extern void b_regionprops(const double varargin_1_ImageSize[2], double
  varargin_1_NumObjects, const emxArray_real_T *varargin_1_RegionIndices, const
  emxArray_int32_T *varargin_1_RegionLengths, const emxArray_uint8_T *varargin_2,
  emxArray_struct0_T *outstats);
extern void regionprops(const double varargin_1_ImageSize[2], double
  varargin_1_NumObjects, const emxArray_real_T *varargin_1_RegionIndices, const
  emxArray_int32_T *varargin_1_RegionLengths, const emxArray_uint16_T
  *varargin_2, emxArray_struct0_T *outstats);

#endif

/* End of code generation (regionprops.h) */
