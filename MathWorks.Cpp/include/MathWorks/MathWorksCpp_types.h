/*
 * MathWorksCpp_types.h
 *
 * Code generation for function 'MathWorksCpp_types'
 *
 */

#ifndef MATHWORKSCPP_TYPES_H
#define MATHWORKSCPP_TYPES_H

/* Include files */
#include "rtwtypes.h"
#ifdef ADAPTIVETHRESHOLD_XIL_BUILD
#if defined(_MSC_VER) || defined(__LCC__)
#define ADAPTIVETHRESHOLD_DLL_EXPORT   __declspec(dllimport)
#else
#define ADAPTIVETHRESHOLD_DLL_EXPORT
#endif

#elif defined(BUILDING_ADAPTIVETHRESHOLD)
#if defined(_MSC_VER) || defined(__LCC__)
#define ADAPTIVETHRESHOLD_DLL_EXPORT   __declspec(dllexport)
#else
#define ADAPTIVETHRESHOLD_DLL_EXPORT   __attribute__ ((visibility("default")))
#endif

#else
#define ADAPTIVETHRESHOLD_DLL_EXPORT
#endif

/* Type Definitions */
struct emxArray_real_T
{
  double *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};

struct sUc2lNjkI6AOTVh0qwIq4SB_tag
{
  emxArray_real_T *breaks;
  emxArray_real_T *coefs;
};

typedef sUc2lNjkI6AOTVh0qwIq4SB_tag c_struct_T;
struct emxArray_real32_T
{
  float *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};

struct c_vision_internal_calibration_c
{
  boolean_T isValid;
  float Energy;
  emxArray_real_T *BoardCoords;
  emxArray_real_T *BoardIdx;
  emxArray_real32_T *Points;
  boolean_T IsDirectionBad[4];
  double LastExpandDirection;
  float PreviousEnergy;
};

struct emxArray_uint32_T
{
  unsigned int *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};

struct emxArray_boolean_T
{
  boolean_T *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};

struct emxArray_uint16_T
{
  unsigned short *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};

struct b_struct_T
{
  double Area;
  double Centroid[2];
  double BoundingBox[4];
  double MajorAxisLength;
  double MinorAxisLength;
  double Eccentricity;
  double Orientation;
  emxArray_boolean_T *Image;
  emxArray_boolean_T *FilledImage;
  double FilledArea;
  double EulerNumber;
  double Extrema[16];
  double EquivDiameter;
  double Extent;
  emxArray_real_T *PixelIdxList;
  emxArray_real_T *PixelList;
  double Perimeter;
  double Circularity;
  emxArray_uint16_T *PixelValues;
  double WeightedCentroid[2];
  double MeanIntensity;
  unsigned short MinIntensity;
  unsigned short MaxIntensity;
  emxArray_real_T *SubarrayIdx;
  double SubarrayIdxLengths[2];
};

struct emxArray_int8_T
{
  signed char *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};

struct emxArray_uint8_T
{
  unsigned char *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};

struct emxArray_int32_T
{
  int *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};

struct struct0_T
{
  double WeightedCentroid[2];
  double BoundingBox[4];
  double Area;
  double EquivDiameter;
};

struct emxArray_struct0_T
{
  struct0_T *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};

struct d_struct_T
{
  emxArray_real_T *breaks;
  emxArray_real_T *coefs;
};

struct emxArray_struct_T
{
  b_struct_T *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};

#endif

/* End of code generation (MathWorksCpp_types.h) */
