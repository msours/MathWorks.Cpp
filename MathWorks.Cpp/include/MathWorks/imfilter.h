/*
 * imfilter.h
 *
 * Code generation for function 'imfilter'
 *
 */

#ifndef IMFILTER_H
#define IMFILTER_H

/* Include files */
#include <cstddef>
#include <cstdlib>
#include "rtwtypes.h"
#include "omp.h"
#include "MathWorksCpp_types.h"

/* Function Declarations */
extern void b_imfilter(emxArray_real32_T *varargin_1);
extern void b_padImage(const emxArray_real32_T *a_tmp, const double pad[2],
  emxArray_real32_T *a);
extern void c_imfilter(emxArray_real32_T *varargin_1);
extern void d_imfilter(emxArray_real32_T *varargin_1);
extern void e_imfilter(emxArray_real32_T *varargin_1);
extern void imfilter(emxArray_real_T *varargin_1, const emxArray_real_T
                     *varargin_2);

#endif

/* End of code generation (imfilter.h) */
