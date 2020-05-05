
#include "C_Coder.h"
#include "MathWorks/MathWorksCpp_emxAPI.h"
#include "MathWorks/MathWorksCpp_initialize.h"
#include "MathWorks/MathWorksCpp_terminate.h"

#include "MathWorks/Demosaic8Bit.h"
#include "MathWorks/Demosaic16Bit.h"

#include "MathWorks/imresize8bit.h"
#include "MathWorks/imresize16bit.h"

namespace MathWorks
{
	cv::Mat C_Coder::Demosaic(const cv::Mat &BayerPatternImage, const SensorAlignment sensorAlignment)
	{
		cv::Mat ColorImage;

		if (BayerPatternImage.depth() <= 1)
		{
			MatlabImage8 Image;
			MatlabImage8 bayerPatternImage;

			TypeConverters::CvMatToMatlabImage(BayerPatternImage, bayerPatternImage);

			emxInitArray_uint8_T(&Image, 3);

			Demosaic8Bit(bayerPatternImage, static_cast<int>(sensorAlignment), Image);

			TypeConverters::MatlabImageToCvMat(Image, ColorImage);

			emxDestroyArray_uint8_T(Image);
			emxDestroyArray_uint8_T(bayerPatternImage);
		}
		else
		{
			MatlabImage16 Image;
			MatlabImage16 bayerPatternImage;

			TypeConverters::CvMatToMatlabImage(BayerPatternImage, bayerPatternImage);

			emxInitArray_uint16_T(&Image, 3);

			Demosaic16Bit(bayerPatternImage, static_cast<int>(sensorAlignment), Image);

			TypeConverters::MatlabImageToCvMat(Image, ColorImage);

			emxDestroyArray_uint16_T(Image);
			emxDestroyArray_uint16_T(bayerPatternImage);
		}

		return ColorImage;
	}
	cv::Mat C_Coder::Imresize(const cv::Mat &Image, const size_t NewHeight, const size_t NewWidth, const ResizeMode resizeMode)
	{
		cv::Mat ResizedImage;

		if (Image.depth() <= 1)
		{
			if (Image.channels() <= 1)
			{
				MatlabImage8 resizedImage;
				MatlabImage8 image;

				TypeConverters::CvMatToMatlabImage(Image, image);

				emxInitArray_uint8_T(&resizedImage, 2);

				imresize8bit(image, NewHeight, NewWidth, static_cast<int>(resizeMode), resizedImage);

				TypeConverters::MatlabImageToCvMat(resizedImage, ResizedImage);

				emxDestroyArray_uint8_T(image);
				emxDestroyArray_uint8_T(resizedImage);

				return ResizedImage;
			}
		}
		else
		{
			if (Image.channels() <= 1)
			{
				MatlabImage16 resizedImage;
				MatlabImage16 image;

				TypeConverters::CvMatToMatlabImage(Image, image);

				emxInitArray_uint16_T(&resizedImage, 2);

				imresize16bit(image, NewHeight, NewWidth, static_cast<int>(resizeMode), resizedImage);

				TypeConverters::MatlabImageToCvMat(resizedImage, ResizedImage);

				emxDestroyArray_uint16_T(image);
				emxDestroyArray_uint16_T(resizedImage);

				return ResizedImage;
			}
		}

		std::vector<cv::Mat> SingleChannelImages;
		cv::split(Image, SingleChannelImages);

		for (int k = 0; k < SingleChannelImages.size(); k++) SingleChannelImages[k] = Imresize(SingleChannelImages[k], NewHeight, NewWidth, resizeMode);

		cv::merge(SingleChannelImages, ResizedImage);

		return ResizedImage;
	}
}
