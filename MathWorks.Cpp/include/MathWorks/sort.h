/*
 * sort.h
 *
 * Code generation for function 'sort'
 *
 */

#ifndef SORT_H
#define SORT_H

/* Include files */
#include <cstddef>
#include <cstdlib>
#include "rtwtypes.h"
#include "omp.h"
#include "MathWorksCpp_types.h"

/* Function Declarations */
extern void b_sort(double x[4]);
extern void c_sort(double x[2], int idx[2]);
extern void d_sort(emxArray_real_T *x, emxArray_int32_T *idx);
extern void sort(emxArray_real32_T *x, emxArray_int32_T *idx);

#endif

/* End of code generation (sort.h) */
