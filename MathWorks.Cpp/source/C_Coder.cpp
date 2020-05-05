
#include "C_Coder.h"

#include "MathWorks/MathWorksCpp_emxAPI.h"
#include "MathWorks/MathWorksCpp_initialize.h"
#include "MathWorks/MathWorksCpp_terminate.h"

#include "MathWorks/Demosaic8Bit.h"
#include "MathWorks/Demosaic16Bit.h"

#include "MathWorks/imresize8bit.h"
#include "MathWorks/imresize16bit.h"

#include "MathWorks/detectCheckerboardPoints8Bit.h"
#include "MathWorks/detectCheckerboardPoints16Bit.h"

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

	bool C_Coder::DetectCheckerboardPoints(const cv::Mat &Image, const double CornerThreshold, std::vector<cv::Point2d> &CornerDetections, cv::Size2i &BoardSize) 
	{
		BoardSize = cv::Size(0, 0);

		// Only supports single channel images
		if (Image.channels() > 1) return false;

		MatlabMatrix imagePoints;
		emxInitArray_real_T(&imagePoints, 2);

		double boardSize[2];

		if (Image.depth() <= 1)
		{
			MatlabImage8 image;
			TypeConverters::CvMatToMatlabImage(Image, image);

			detectCheckerboardPoints8Bit(image, CornerThreshold, imagePoints, boardSize);

			emxDestroyArray_uint8_T(image);
		}
		else 
		{
			MatlabImage16 image;
			TypeConverters::CvMatToMatlabImage(Image, image);

			detectCheckerboardPoints16Bit(image, CornerThreshold, imagePoints, boardSize);

			emxDestroyArray_uint16_T(image);
		}

		int CheckerboardRows = (int)round(boardSize[0]) - 1;
		int CheckerboardColumns = (int)round(boardSize[1]) - 1;

		if (CheckerboardRows < 2)
		{
			emxDestroyArray_real_T(imagePoints);
			return false;
		}

		const int N = CheckerboardRows * CheckerboardColumns;

		for (int k = 0; k < N; k++)
		{
			// Subtract 1.0 since Matlab uses 1 based indexing, C++ uses 0
			CornerDetections.push_back(cv::Point2d(imagePoints->data[k] - 1.0, imagePoints->data[N + k] - 1.0));
		}

		emxDestroyArray_real_T(imagePoints);

		// Matlab is not consistent with the way that it returns the ordering of the points, and the board orientation.
		// Checkerboard columns is always the largest dimension, and checkerboard rows the smallest.
		// A check is performed for each possible orientation, and then re-ordered so that it is always row-major order, starting from the top left most point in the image. 
		const bool Flipped90 = CornerDetections[0].x < CornerDetections[CheckerboardRows - 1].x && abs((CornerDetections[CheckerboardRows - 1].x - CornerDetections[0].x)) > abs((CornerDetections[CheckerboardRows - 1].y - CornerDetections[0].y));
		const bool Flipped180 = CornerDetections[0].x > CornerDetections[CheckerboardRows * CheckerboardColumns - 1].x && CornerDetections[0].y > CornerDetections[CheckerboardRows * CheckerboardColumns - 1].y;
		const bool Flipped270 = CornerDetections[0].x > CornerDetections[CheckerboardRows - 1].x && abs((CornerDetections[CheckerboardRows - 1].x - CornerDetections[0].x)) > abs((CornerDetections[CheckerboardRows - 1].y - CornerDetections[0].y));

		std::vector<cv::Point2d> CornerDetections0(N);

		int t = 0;
		int t0 = 0;
		if (Flipped90)
		{
			CheckerboardColumns = (int)round(boardSize[0]) - 1;
			CheckerboardRows = (int)round(boardSize[1]) - 1;

			for (int k = CheckerboardRows - 1; k >= 0; k--)
			{
				for (int j = 0; j < CheckerboardColumns; j++)
				{
					t = j + k * CheckerboardColumns;
					CornerDetections0[t0++] = CornerDetections[t];
				}
			}
		}
		if (Flipped270)
		{
			CheckerboardColumns = (int)round(boardSize[0]) - 1;
			CheckerboardRows = (int)round(boardSize[1]) - 1;

			for (int k = 0; k < CheckerboardRows; k++)
			{
				for (int j = CheckerboardColumns - 1; j >= 0; j--)
				{
					t = j + k * CheckerboardColumns;
					CornerDetections0[t0++] = CornerDetections[t];
				}
			}
		}
		if (Flipped180)
		{
			t0 = N - 1;

			for (int j = 0; j < CheckerboardRows; j++)
			{
				for (int k = 0; k < CheckerboardColumns; k++)
				{
					t = j + k * CheckerboardRows;
					CornerDetections0[t0--] = CornerDetections[t];
				}
			}
		}
		if (!Flipped90 && !Flipped180 && !Flipped270)
		{
			for (int j = 0; j < CheckerboardRows; j++)
			{
				for (int k = 0; k < CheckerboardColumns; k++)
				{
					t = j + k * CheckerboardRows;
					CornerDetections0[t0++] = CornerDetections[t];
				}
			}
		}

		CornerDetections = CornerDetections0;
		BoardSize = cv::Size2i(CheckerboardColumns, CheckerboardRows);

		return true;
	}
}
