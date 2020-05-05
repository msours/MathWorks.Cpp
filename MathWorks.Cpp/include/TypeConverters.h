
#pragma once

#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include "MathWorks/MathWorksCpp_types.h"

typedef unsigned char byte;

typedef emxArray_uint16_T* MatlabImage16;
typedef emxArray_uint8_T* MatlabImage8; 
typedef emxArray_boolean_T* MatlabImageBinary;
typedef emxArray_real_T* MatlabMatrix;

namespace MathWorks
{
	class TypeConverters
	{
	public:
		static void MatlabImageToCvMat(const MatlabImage16 &MatlabImageIn, cv::Mat &CvImageOut);
		static void MatlabImageToCvMat(const MatlabImage8 &MatlabImageIn, cv::Mat &CvImageOut);
		static void MatlabImageToCvMat(const MatlabImageBinary &MatlabImageIn, cv::Mat &CvImageOut);

		static void MatlabMatrixToCvMat(const MatlabMatrix &MatlabMatrixIn, cv::Mat &CvMatOut);

		static void CvMatToMatlabImage(const cv::Mat &CvImageIn, MatlabImage16 &MatlabImageOut);
		static void CvMatToMatlabImage(const cv::Mat &CvImageIn, MatlabImage8 &MatlabImageOut);

		static void CvMatToMatlabMatrix(const cv::Mat &CvMatIn, MatlabMatrix &MatlabMatrixOut);

		static void VectorToMatlabMatrix(const std::vector<double> &VectorIn, MatlabMatrix &MatlabMatrixOut);

		static cv::Mat Assert64dCvMat(const cv::Mat &Matrix);
	};
}
