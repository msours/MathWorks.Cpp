
#include "MathWorks.h"
#include "MathWorks/MathWorksCpp_emxAPI.h"
#include "MathWorks/MathWorksCpp_initialize.h"
#include "MathWorks/MathWorksCpp_terminate.h"

#include "MathWorks/Demosaic8Bit.h"
#include "MathWorks/Demosaic16Bit.h"

namespace Tools 
{
	cv::Mat MathWorks::Demosaic(const cv::Mat &BayerPatternImage, const SensorAlignment sensorAlignment)
	{
		cv::Mat ColorImage;

		if (BayerPatternImage.depth() <= 1)
		{
			emxArray_uint8_T *Image;
			emxArray_uint8_T *bayerPatternImage = CvMat8BitToMatlabImage(BayerPatternImage);

			emxInitArray_uint8_T(&Image, 3);

			Demosaic8Bit(bayerPatternImage, static_cast<int>(sensorAlignment), Image);

			ColorImage = MatlabImageToCvMat(Image);

			emxDestroyArray_uint8_T(Image);
			emxDestroyArray_uint8_T(bayerPatternImage);
		}
		else
		{
			emxArray_uint16_T *Image;
			emxArray_uint16_T *bayerPatternImage = CvMat16BitToMatlabImage(BayerPatternImage);

			emxInitArray_uint16_T(&Image, 3);

			Demosaic16Bit(bayerPatternImage, static_cast<int>(sensorAlignment), Image);

			ColorImage = MatlabImageToCvMat(Image);

			emxDestroyArray_uint16_T(Image);
			emxDestroyArray_uint16_T(bayerPatternImage);
		}
		
		return ColorImage;
	}


	cv::Mat MathWorks::MatlabImageToCvMat(emxArray_uint16_T* Image) 
	{
		const int Height = Image->size[0];
		const int Width = Image->size[1];

		const int Channels = Image->numDimensions;

		const int N = Width * Height;

		const int Type = Channels == 1 ? CV_16UC1 : CV_16UC3;

		cv::Mat cvImage = cv::Mat::zeros(Height, Width, Type);

		byte lsb, msb;

		int v = 0;
		int q = -1;
		for (int j = 0; j < Width; j++)
		{
			for (int k = 0; k < Height; k++)
			{
				for (int c = 0; c < Channels; c++)
				{
					lsb = (byte)(Image->data[v + N * (2 - c)] & 0xFF);
					msb = (byte)((Image->data[v + N * (2 - c)] >> 8) & 0xFF);

					q = (k * Width + j) * 2 * Channels + (2 * c);

					cvImage.data[q] = lsb;
					cvImage.data[q + 1] = msb;
				}
				v++;
			}
		}

		return cvImage;
	}
	cv::Mat MathWorks::MatlabImageToCvMat(emxArray_uint8_T* Image) 
	{
		const int Height = Image->size[0];
		const int Width = Image->size[1];

		const int Channels = Image->numDimensions;

		const int N = Width * Height;

		const int Type = Channels == 1 ? CV_8UC1 : CV_8UC3;

		cv::Mat cvImage = cv::Mat::zeros(Height, Width, Type);

		int v = 0;
		int q = -1;
		for (int j = 0; j < Width; j++)
		{
			for (int k = 0; k < Height; k++)
			{
				for (int c = 0; c < Channels; c++)
				{
					q = (k * Width + j) * Channels + c;
					cvImage.data[q] = Image->data[v + N * (2 - c)];
				}
				v++;
			}
		}

		return cvImage;
	}

	emxArray_real_T* MathWorks::VectorToMatlabArray(const std::vector<float> &V) 
	{
		emxArray_real_T *result;

		int Size[1] = { V.size() };
		result = emxCreateND_real_T(1, Size);

		for (int k = 0; k < V.size(); k++) result->data[k] = static_cast<double>(V[k]);

		return result;
	}

	emxArray_uint16_T* MathWorks::CvMat16BitToMatlabImage(const cv::Mat &Image) 
	{
		emxArray_uint16_T *result;

		int Height = Image.rows;
		int Width = Image.cols;

		byte *Data = Image.data;

		int Size[2] = { Height, Width };

		result = emxCreateND_uint16_T(2, Size);

		uint16_t Value;

		int t = 0;
		for (int k = 0; k < Height; k++)
		{
			for (int j = 0; j < Width; j++)
			{
				Value = ((uint16_t)Data[t + 1] << 8) | ((uint16_t)Data[t]);
				result->data[k + Height * j] = Value;

				t += 2;
			}
		}

		return result;
	}
	emxArray_uint8_T* MathWorks::CvMat8BitToMatlabImage(const cv::Mat &Image)
	{
		emxArray_uint8_T *result;

		int Height = Image.rows;
		int Width = Image.cols;

		int Size[2] = { Height, Width };

		result = emxCreateND_uint8_T(2, Size);

		for (int k = 0; k < Height; k++)
		{
			for (int j = 0; j < Width; j++)
			{
				result->data[k + Height * j] = Image.data[j + Width * k];
			}
		}

		return result;
	}
}
