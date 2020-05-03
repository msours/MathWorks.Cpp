
#pragma once

#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include "MathWorks/MathWorksCpp_types.h"

typedef unsigned char byte;

namespace Tools
{
	class MathWorks
	{
	public:


	private:

		static cv::Mat MatlabImageToCvMat(emxArray_uint16_T* Image);
		static cv::Mat MatlabImageToCvMat(emxArray_uint8_T* Image);

		static emxArray_real_T* VectorToMatlabArray(const std::vector<float> &V);
		static emxArray_uint16_T* CvMat16BitToMatlabImage(const cv::Mat &Image);
		static emxArray_uint8_T* CvMat8BitToMatlabImage(const cv::Mat &Image);

	};
}
