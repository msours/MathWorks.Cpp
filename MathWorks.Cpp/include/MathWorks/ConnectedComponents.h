/*
 * ConnectedComponents.h
 *
 * Code generation for function 'ConnectedComponents'
 *
 */

#ifndef CONNECTEDCOMPONENTS_H
#define CONNECTEDCOMPONENTS_H

/* Include files */
#include <cstddef>
#include <cstdlib>
#include "rtwtypes.h"
#include "omp.h"
#include "MathWorksCpp_types.h"

/* Function Declarations */
ADAPTIVETHRESHOLD_DLL_EXPORT extern void ConnectedComponents(const
  emxArray_boolean_T *BinaryData, const emxArray_uint16_T *ImageData, int
  StrelSize, emxArray_struct0_T *imageComponents);

#endif

/* End of code generation (ConnectedComponents.h) */
