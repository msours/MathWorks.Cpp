
#pragma once

#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include "MathWorks/MathWorksCpp_types.h"

typedef unsigned char byte;

namespace Tools
{
	enum SensorAlignment;

	class MathWorks
	{
	public:

		static cv::Mat Demosaic(const cv::Mat &BayerPatternImage, const SensorAlignment sensorAlignment);
		
	private:

		static cv::Mat MatlabImageToCvMat(emxArray_uint16_T* Image);
		static cv::Mat MatlabImageToCvMat(emxArray_uint8_T* Image);

		static emxArray_real_T* VectorToMatlabArray(const std::vector<float> &V);
		static emxArray_uint16_T* CvMat16BitToMatlabImage(const cv::Mat &Image);
		static emxArray_uint8_T* CvMat8BitToMatlabImage(const cv::Mat &Image);

	};

	// based on:
	// https://www.mathworks.com/help/images/ref/demosaic.html#bu45ckm-3
	enum SensorAlignment
	{
		rggb = 0,
		bggr = 1,
		grbg = 2,
		gbrg = 3
	};
}
