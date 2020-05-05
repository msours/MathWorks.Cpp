
#pragma once

#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include "MathWorks/MathWorksCpp_types.h"

typedef unsigned char byte;
typedef emxArray_uint16_T* MatlabImage16;
typedef emxArray_uint8_T* MatlabImage8;

namespace MathWorks
{
	enum SensorAlignment;
	enum ResizeMode;

	class Functions
	{
	public:

		static cv::Mat Demosaic(const cv::Mat &BayerPatternImage, const SensorAlignment sensorAlignment);

		static cv::Mat Imresize(const cv::Mat &Image, const size_t NewHeight, const size_t NewWidth, const ResizeMode resizeMode);
		
	private:

		static void MatlabImageToCvMat(const MatlabImage16 &MatlabImageIn, cv::Mat &CvImageOut);
		static void MatlabImageToCvMat(const MatlabImage8 &MatlabImageIn, cv::Mat &CvImageOut);

		static void CvMatToMatlabImage(const cv::Mat &CvImageIn, MatlabImage16 &MatlabImageOut);
		static void CvMatToMatlabImage(const cv::Mat &CvImageIn, MatlabImage8 &MatlabImageOut);

		static emxArray_real_T* VectorToMatlabArray(const std::vector<float> &V);

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
	enum ResizeMode 
	{
		billinear = 0,
		bicubic = 1,
		nearest = 2
	};
}
