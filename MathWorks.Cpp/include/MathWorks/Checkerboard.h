/*
 * Checkerboard.h
 *
 * Code generation for function 'Checkerboard'
 *
 */

#ifndef CHECKERBOARD_H
#define CHECKERBOARD_H

/* Include files */
#include <cstddef>
#include <cstdlib>
#include "rtwtypes.h"
#include "omp.h"
#include "MathWorksCpp_types.h"

/* Function Declarations */
extern void Checkerboard_initialize(c_vision_internal_calibration_c *b_this,
  double seedIdx, const emxArray_real32_T *points, const float v1[2], const
  float v2[2]);
extern void c_Checkerboard_expandBoardDirec(c_vision_internal_calibration_c
  *b_this, double direction);

#endif

/* End of code generation (Checkerboard.h) */
