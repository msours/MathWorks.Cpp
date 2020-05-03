/*
 * find_peaks.h
 *
 * Code generation for function 'find_peaks'
 *
 */

#ifndef FIND_PEAKS_H
#define FIND_PEAKS_H

/* Include files */
#include <cstddef>
#include <cstdlib>
#include "rtwtypes.h"
#include "omp.h"
#include "MathWorksCpp_types.h"

/* Function Declarations */
extern void find_peaks(const emxArray_real32_T *metric, double quality,
  emxArray_real32_T *loc);

#endif

/* End of code generation (find_peaks.h) */
