
#pragma once

#include "TypeConverters.h"

namespace MathWorks
{
	enum SensorAlignment;
	enum ResizeMode;

	class C_Coder
	{
	public:
		static cv::Mat Demosaic(const cv::Mat &BayerPatternImage, const SensorAlignment sensorAlignment);

		static cv::Mat Imresize(const cv::Mat &Image, const size_t NewHeight, const size_t NewWidth, const ResizeMode resizeMode);
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
