/*
 * xaxpy.h
 *
 * Code generation for function 'xaxpy'
 *
 */

#ifndef XAXPY_H
#define XAXPY_H

/* Include files */
#include <cstddef>
#include <cstdlib>
#include "rtwtypes.h"
#include "omp.h"
#include "MathWorksCpp_types.h"

/* Function Declarations */
extern void b_xaxpy(int n, double a, const emxArray_real_T *x, int ix0,
                    emxArray_real_T *y, int iy0);
extern void c_xaxpy(int n, double a, int ix0, double y[841], int iy0);
extern void d_xaxpy(int n, double a, const double x[841], int ix0, double y[29],
                    int iy0);
extern void e_xaxpy(int n, double a, const double x[29], int ix0, double y[841],
                    int iy0);
extern void xaxpy(int n, double a, int ix0, emxArray_real_T *y, int iy0);

#endif

/* End of code generation (xaxpy.h) */
