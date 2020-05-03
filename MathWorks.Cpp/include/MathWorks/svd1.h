/*
 * svd1.h
 *
 * Code generation for function 'svd1'
 *
 */

#ifndef SVD1_H
#define SVD1_H

/* Include files */
#include <cstddef>
#include <cstdlib>
#include "rtwtypes.h"
#include "omp.h"
#include "MathWorksCpp_types.h"

/* Function Declarations */
extern void b_svd(const emxArray_real_T *A, emxArray_real_T *U, emxArray_real_T *
                  s, emxArray_real_T *V);
extern void d_svd(const double A[841], double U[841], double s[29], double V[841]);

#endif

/* End of code generation (svd1.h) */
