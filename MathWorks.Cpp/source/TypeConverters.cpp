
#include "TypeConverters.h"

#include "MathWorks/MathWorksCpp_emxAPI.h"
#include "MathWorks/MathWorksCpp_initialize.h"
#include "MathWorks/MathWorksCpp_terminate.h"

namespace MathWorks 
{
	void TypeConverters::MatlabImageToCvMat(const MatlabImage16 &MatlabImageIn, cv::Mat & CvImageOut)
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

	void TypeConverters::MatlabImageToCvMat(const MatlabImage8 &MatlabImageIn, cv::Mat &CvImageOut)
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

	void TypeConverters::CvMatToMatlabImage(const cv::Mat &CvImageIn, MatlabImage16 &MatlabImageOut)
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
	void TypeConverters::CvMatToMatlabImage(const cv::Mat &CvImageIn, MatlabImage8 &MatlabImageOut)
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

	void TypeConverters::MatlabMatrixToCvMat(const MatlabMatrix &MatlabMatrixIn, cv::Mat &CvMatOut) 
	{
		const int Height = MatlabMatrixIn->size[0];
		const int Width = MatlabMatrixIn->size[1];

		CvMatOut = cv::Mat(Height, Width, cv::DataType<double>::type);

		for (int j = 0; j < Width; j++)
		{
			for (int k = 0; k < Height; k++)
			{
				CvMatOut.at<double>(k, j) = MatlabMatrixIn->data[k + Height * j];
			}
		}
	}

	void TypeConverters::VectorToMatlabMatrix(const std::vector<double> &VectorIn, MatlabMatrix &MatlabMatrixOut)
	{
		MatlabMatrix result;

		int Size[1] = { VectorIn.size() };
		MatlabMatrixOut = emxCreateND_real_T(1, Size);

		for (int k = 0; k < VectorIn.size(); k++) result->data[k] = VectorIn[k];
	}
}

