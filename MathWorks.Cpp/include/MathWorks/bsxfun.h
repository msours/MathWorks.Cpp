/*
 * bsxfun.h
 *
 * Code generation for function 'bsxfun'
 *
 */

#ifndef BSXFUN_H
#define BSXFUN_H

/* Include files */
#include <cstddef>
#include <cstdlib>
#include "rtwtypes.h"
#include "omp.h"
#include "MathWorksCpp_types.h"

/* Function Declarations */
extern void b_bsxfun(const emxArray_real_T *a, const emxArray_real_T *b,
                     emxArray_real_T *c);
extern void bsxfun(const emxArray_int32_T *a, const emxArray_int32_T *b,
                   emxArray_int32_T *c);
extern void c_bsxfun(const emxArray_real_T *a, const emxArray_real_T *b,
                     emxArray_real_T *c);

#endif

/* End of code generation (bsxfun.h) */
