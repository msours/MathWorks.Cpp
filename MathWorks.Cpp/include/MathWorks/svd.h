/*
 * svd.h
 *
 * Code generation for function 'svd'
 *
 */

#ifndef SVD_H
#define SVD_H

/* Include files */
#include <cstddef>
#include <cstdlib>
#include "rtwtypes.h"
#include "omp.h"
#include "MathWorksCpp_types.h"

/* Function Declarations */
extern void c_svd(const double A[841], double U[841], double S[841], double V
                  [841]);
extern void svd(const emxArray_real_T *A, emxArray_real_T *U, emxArray_real_T *S,
                emxArray_real_T *V);

#endif

/* End of code generation (svd.h) */
