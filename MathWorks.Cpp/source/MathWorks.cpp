
#include "MathWorks.h"
#include "MathWorks/MathWorksCpp_emxAPI.h"
#include "MathWorks/MathWorksCpp_initialize.h"
#include "MathWorks/MathWorksCpp_terminate.h"

#include "MathWorks/Demosaic8Bit.h"
#include "MathWorks/Demosaic16Bit.h"

#include "MathWorks/imresize8bit.h"
#include "MathWorks/imresize16bit.h"

namespace MathWorks
{
	cv::Mat Functions::Demosaic(const cv::Mat &BayerPatternImage, const SensorAlignment sensorAlignment)
	{
		cv::Mat ColorImage;

		if (BayerPatternImage.depth() <= 1)
		{
			MatlabImage8 Image;
			MatlabImage8 bayerPatternImage;

			CvMatToMatlabImage(BayerPatternImage, bayerPatternImage);

			emxInitArray_uint8_T(&Image, 3);

			Demosaic8Bit(bayerPatternImage, static_cast<int>(sensorAlignment), Image);

			MatlabImageToCvMat(Image, ColorImage);

			emxDestroyArray_uint8_T(Image);
			emxDestroyArray_uint8_T(bayerPatternImage);
		}
		else
		{
			MatlabImage16 Image;
			MatlabImage16 bayerPatternImage;

			CvMatToMatlabImage(BayerPatternImage, bayerPatternImage);

			emxInitArray_uint16_T(&Image, 3);

			Demosaic16Bit(bayerPatternImage, static_cast<int>(sensorAlignment), Image);

			MatlabImageToCvMat(Image, ColorImage);

			emxDestroyArray_uint16_T(Image);
			emxDestroyArray_uint16_T(bayerPatternImage);
		}

		return ColorImage;
	}
	cv::Mat Functions::Imresize(const cv::Mat &Image, const size_t NewHeight, const size_t NewWidth, const ResizeMode resizeMode)
	{
		cv::Mat ResizedImage;

		if (Image.depth() <= 1)
		{
			if (Image.channels() <= 1)
			{
				MatlabImage8 resizedImage;
				MatlabImage8 image;

				CvMatToMatlabImage(Image, image);

				emxInitArray_uint8_T(&resizedImage, 2);

				imresize8bit(image, NewHeight, NewWidth, static_cast<int>(resizeMode), resizedImage);

				MatlabImageToCvMat(resizedImage, ResizedImage);

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

				CvMatToMatlabImage(Image, image);

				emxInitArray_uint16_T(&resizedImage, 2);

				imresize16bit(image, NewHeight, NewWidth, static_cast<int>(resizeMode), resizedImage);

				MatlabImageToCvMat(resizedImage, ResizedImage);

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

	void Functions::MatlabImageToCvMat(const MatlabImage16 &MatlabImageIn, cv::Mat & CvImageOut)
	{
		const int Height = MatlabImageIn->size[0];
		const int Width = MatlabImageIn->size[1];

		const int Channels = MatlabImageIn->numDimensions > 2 ? 3 : 1;

		const int N = Width * Height;

		const int Type = Channels == 1 ? CV_16UC1 : CV_16UC3;

		CvImageOut = cv::Mat::zeros(Height, Width, Type);

		byte lsb, msb;

		if (Channels > 1)
		{
			for (int j = 0; j < Width; j++)
			{
				for (int k = 0; k < Height; k++)
				{
					for (int c = 0; c < Channels; c++)
					{
						lsb = (byte)(MatlabImageIn->data[k + Height * j + N * (2 - c)] & 0xFF);
						msb = (byte)((MatlabImageIn->data[k + Height * j + N * (2 - c)] >> 8) & 0xFF);

						CvImageOut.data[(k * Width + j) * 2 * Channels + (2 * c)] = lsb;
						CvImageOut.data[(k * Width + j) * 2 * Channels + (2 * c) + 1] = msb;
					}
				}
			}
		}
		else
		{
			for (int j = 0; j < Width; j++)
			{
				for (int k = 0; k < Height; k++)
				{
					lsb = (byte)(MatlabImageIn->data[k + Height * j] & 0xFF);
					msb = (byte)((MatlabImageIn->data[k + Height * j] >> 8) & 0xFF);

					CvImageOut.data[(k * Width + j) * 2] = lsb;
					CvImageOut.data[(k * Width + j) * 2 + 1] = msb;
				}
			}
		}
	}

	void Functions::MatlabImageToCvMat(const MatlabImage8 &MatlabImageIn, cv::Mat &CvImageOut)
	{
		const int Height = MatlabImageIn->size[0];
		const int Width = MatlabImageIn->size[1];

		const int Channels = MatlabImageIn->numDimensions > 2 ? 3 : 1;

		const int N = Width * Height;

		const int Type = Channels == 1 ? CV_8UC1 : CV_8UC3;

		CvImageOut = cv::Mat::zeros(Height, Width, Type);

		if (Channels > 1)
		{
			for (int j = 0; j < Width; j++)
			{
				for (int k = 0; k < Height; k++)
				{
					for (int c = 0; c < Channels; c++)
					{
						CvImageOut.data[(k * Width + j) * Channels + c] = MatlabImageIn->data[k + Height * j + N * (2 - c)];
					}
				}
			}
		}
		else
		{
			for (int j = 0; j < Width; j++)
			{
				for (int k = 0; k < Height; k++)
				{
					CvImageOut.data[j + Width * k] = MatlabImageIn->data[k + Height * j];
				}
			}
		}
	}

	void Functions::CvMatToMatlabImage(const cv::Mat &CvImageIn, MatlabImage16 &MatlabImageOut)
	{
		int Height = CvImageIn.rows;
		int Width = CvImageIn.cols;

		int Size[2] = { Height, Width };

		const int Channels = CvImageIn.channels();
		const int NumDimensions = Channels > 1 ? 3 : 2;
		const int N = Width * Height;

		// Known issue with emxCreateND_uint16_T with at least one Matlab versions C Coder output, doesn't correctly allocate memory for 3 channel 16 bit images.
		MatlabImageOut = emxCreateND_uint16_T(NumDimensions, Size);

		uint16_t Value;
		if (Channels > 1)
		{
			for (int j = 0; j < Width; j++)
			{
				for (int k = 0; k < Height; k++)
				{
					for (int c = 0; c < Channels; c++)
					{
						Value = ((uint16_t)CvImageIn.data[(j + Width * k) * 2 * Channels + (2 * c) + 1] << 8) | ((uint16_t)CvImageIn.data[(j + Width * k) * 2 * Channels + (2 * c)]);
						MatlabImageOut->data[k + Height * j + N * (2 - c)] = Value;
					}
				}
			}
		}
		else
		{
			for (int j = 0; j < Width; j++)
			{
				for (int k = 0; k < Height; k++)
				{
					Value = ((uint16_t)CvImageIn.data[(j + Width * k) * 2 + 1] << 8) | ((uint16_t)CvImageIn.data[(j + Width * k) * 2]);
					MatlabImageOut->data[k + Height * j] = Value;
				}
			}
		}
	}
	void Functions::CvMatToMatlabImage(const cv::Mat &CvImageIn, MatlabImage8 &MatlabImageOut)
	{
		int Height = CvImageIn.rows;
		int Width = CvImageIn.cols;

		int Size[2] = { Height, Width };

		const int Channels = CvImageIn.channels();
		const int NumDimensions = Channels > 1 ? 3 : 2;
		const int N = Width * Height;

		// Known issue with emxCreateND_uint8_T with at least one Matlab versions C Coder output, doesn't correctly allocate memory for 3 channel 8 bit images.
		MatlabImageOut = emxCreateND_uint8_T(NumDimensions, Size);

		if (Channels > 1)
		{
			for (int j = 0; j < Width; j++)
			{
				for (int k = 0; k < Height; k++)
				{
					for (int c = 0; c < Channels; c++)
					{
						MatlabImageOut->data[k + Height * j + N * (2 - c)] = CvImageIn.data[(k * Width + j) * Channels + c];
					}
				}
			}
		}
		else
		{
			for (int j = 0; j < Width; j++)
			{
				for (int k = 0; k < Height; k++)
				{
					MatlabImageOut->data[k + Height * j] = CvImageIn.data[j + Width * k];
				}
			}
		}
	}
	emxArray_real_T* Functions::VectorToMatlabArray(const std::vector<float> &V)
	{
		emxArray_real_T *result;

		int Size[1] = { V.size() };
		result = emxCreateND_real_T(1, Size);

		for (int k = 0; k < V.size(); k++) result->data[k] = static_cast<double>(V[k]);

		return result;
	}
}
