/*
 * squeeze.h
 *
 * Code generation for function 'squeeze'
 *
 */

#ifndef SQUEEZE_H
#define SQUEEZE_H

/* Include files */
#include <cstddef>
#include <cstdlib>
#include "rtwtypes.h"
#include "omp.h"
#include "MathWorksCpp_types.h"

/* Function Declarations */
extern void b_squeeze(const emxArray_real_T *a, emxArray_real_T *b);
extern void squeeze(const emxArray_real_T *a, emxArray_real_T *b);

#endif

/* End of code generation (squeeze.h) */
