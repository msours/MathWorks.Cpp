/*
 * imresize.h
 *
 * Code generation for function 'imresize'
 *
 */

#ifndef IMRESIZE_H
#define IMRESIZE_H

/* Include files */
#include <cstddef>
#include <cstdlib>
#include "rtwtypes.h"
#include "omp.h"
#include "MathWorksCpp_types.h"

/* Function Declarations */
extern void b_imresize(const emxArray_uint8_T *Ain, const double varargin_1[2],
  emxArray_uint8_T *Bout);
extern void b_resizeAlongDim(const emxArray_uint8_T *in_, double dim, const
  emxArray_real_T *weights, const emxArray_int32_T *indices, emxArray_uint8_T
  *out);
extern void c_imresize(const emxArray_uint16_T *Ain, const double varargin_1[2],
  emxArray_uint16_T *Bout);
extern void c_resizeAlongDim(const emxArray_uint8_T *in_, double dim, const
  emxArray_real_T *weights, const emxArray_int32_T *indices, emxArray_uint8_T
  *out);
extern void contributions(int in_length, double out_length, double scale, double
  kernel_width, emxArray_real_T *weights, emxArray_int32_T *indices);
extern void d_imresize(const emxArray_uint8_T *Ain, const double varargin_1[2],
  emxArray_uint8_T *Bout);
extern void d_resizeAlongDim(const emxArray_uint16_T *in_, double dim, const
  emxArray_real_T *weights, const emxArray_int32_T *indices, emxArray_uint16_T
  *out);
extern void e_resizeAlongDim(const emxArray_uint16_T *in_, double dim, const
  emxArray_real_T *weights, const emxArray_int32_T *indices, emxArray_uint16_T
  *out);
extern void f_resizeAlongDim(const emxArray_uint8_T *in_, double dim, const
  emxArray_real_T *weights, const emxArray_int32_T *indices, emxArray_uint8_T
  *out);
extern void imresize(const emxArray_uint16_T *Ain, const double varargin_1[2],
                     emxArray_uint16_T *Bout);
extern void resizeAlongDim(const emxArray_uint16_T *in_, double dim, const
  emxArray_real_T *weights, const emxArray_int32_T *indices, emxArray_uint16_T
  *out);

#endif

/* End of code generation (imresize.h) */
