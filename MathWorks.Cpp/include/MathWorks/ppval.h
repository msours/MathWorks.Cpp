/*
 * ppval.h
 *
 * Code generation for function 'ppval'
 *
 */

#ifndef PPVAL_H
#define PPVAL_H

/* Include files */
#include <cstddef>
#include <cstdlib>
#include "rtwtypes.h"
#include "omp.h"
#include "MathWorksCpp_types.h"

/* Function Declarations */
extern void b_ppval(const e_struct_T pp, const emxArray_real_T *x,
                    emxArray_real_T *v);
extern void ppval(const d_struct_T pp, const emxArray_real_T *x, emxArray_real_T
                  *v);

#endif

/* End of code generation (ppval.h) */
