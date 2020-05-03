/*
 * demosaic.h
 *
 * Code generation for function 'demosaic'
 *
 */

#ifndef DEMOSAIC_H
#define DEMOSAIC_H

/* Include files */
#include <cstddef>
#include <cstdlib>
#include "rtwtypes.h"
#include "omp.h"
#include "MathWorksCpp_types.h"

/* Function Declarations */
extern void b_blue(int secondIdxLen, int firstIdxLen, int secondIdxStart, int
                   firstIdxStart, int position, int gOffset, int bOffset,
                   emxArray_uint8_T *RGB, const emxArray_real_T *Ipad);
extern void b_demosaic(const emxArray_uint8_T *b_I, emxArray_uint8_T *RGB);
extern void b_green1(int secondIdxLen, int firstIdxLen, int secondIdxStart, int
                     firstIdxStart, int position, int gOffset, int bOffset,
                     emxArray_uint8_T *RGB, const emxArray_real_T *Ipad);
extern void b_green2(int secondIdxLen, int firstIdxLen, int secondIdxStart, int
                     firstIdxStart, int position, int gOffset, int bOffset,
                     emxArray_uint8_T *RGB, const emxArray_real_T *Ipad);
extern void b_red(int secondIdxLen, int firstIdxLen, int secondIdxStart, int
                  firstIdxStart, int position, int gOffset, int bOffset,
                  emxArray_uint8_T *RGB, const emxArray_real_T *Ipad);
extern void blue(int secondIdxLen, int firstIdxLen, int secondIdxStart, int
                 firstIdxStart, int position, int gOffset, int bOffset,
                 emxArray_uint16_T *RGB, const emxArray_real_T *Ipad);
extern void demosaic(const emxArray_uint16_T *b_I, emxArray_uint16_T *RGB);
extern void green1(int secondIdxLen, int firstIdxLen, int secondIdxStart, int
                   firstIdxStart, int position, int gOffset, int bOffset,
                   emxArray_uint16_T *RGB, const emxArray_real_T *Ipad);
extern void green2(int secondIdxLen, int firstIdxLen, int secondIdxStart, int
                   firstIdxStart, int position, int gOffset, int bOffset,
                   emxArray_uint16_T *RGB, const emxArray_real_T *Ipad);
extern void red(int secondIdxLen, int firstIdxLen, int secondIdxStart, int
                firstIdxStart, int position, int gOffset, int bOffset,
                emxArray_uint16_T *RGB, const emxArray_real_T *Ipad);

#endif

/* End of code generation (demosaic.h) */
