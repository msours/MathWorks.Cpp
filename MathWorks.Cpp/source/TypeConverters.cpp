
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
	void TypeConverters::MatlabImageToCvMat(const MatlabImageBinary &MatlabImageIn, cv::Mat &CvImageOut)
	{
		const int Height = MatlabImageIn->size[0];
		const int Width = MatlabImageIn->size[1];

		const int Type = CV_8UC1;

		CvImageOut = cv::Mat::zeros(Height, Width, Type);

		for (int j = 0; j < Width; j++)
		{
			for (int k = 0; k < Height; k++)
			{
				CvImageOut.data[j + Width * k] = 255 * MatlabImageIn->data[k + Height * j];
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

		if (Channels > 1)
		{
			for (int j = 0; j < Width; j++)
			{
				for (int k = 0; k < Height; k++)
				{
					for (int c = 0; c < Channels; c++)
					{
						MatlabImageOut->data[k + Height * j + N * (2 - c)] = ((uint16_t)CvImageIn.data[(j + Width * k) * 2 * Channels + (2 * c) + 1] << 8) | ((uint16_t)CvImageIn.data[(j + Width * k) * 2 * Channels + (2 * c)]);
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
					MatlabImageOut->data[k + Height * j] = ((uint16_t)CvImageIn.data[(j + Width * k) * 2 + 1] << 8) | ((uint16_t)CvImageIn.data[(j + Width * k) * 2]);
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

	void TypeConverters::CvMatToMatlabImage(const cv::Mat &CvImageIn, MatlabImageBinary &MatlabImageOut)
	{
		int Height = CvImageIn.rows;
		int Width = CvImageIn.cols;

		int Size[2] = { Height, Width };

		MatlabImageOut = emxCreateND_boolean_T(2, Size);

		for (int j = 0; j < Width; j++)
		{
			for (int k = 0; k < Height; k++)
			{
				MatlabImageOut->data[k + Height * j] = CvImageIn.data[j + Width * k] > 0;
			}
		}
	}
	void TypeConverters::CvMatTo1DArray(const cv::Mat &CvImageIn, uint8_t *&Array1DOut)
	{
		const int Channels = CvImageIn.channels();
		const int Width = CvImageIn.cols;
		const int Height = CvImageIn.rows;

		const int N = Width * Height;

		Array1DOut = new uint8_t[N * Channels];

		if (Channels > 1)
		{
			for (int j = 0; j < Width; j++)
			{
				for (int k = 0; k < Height; k++)
				{
					for (int c = 0; c < Channels; c++)
					{
						Array1DOut[k + Height * j + N * (2 - c)] = CvImageIn.data[(k * Width + j) * Channels + c];
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
					Array1DOut[k + Height * j] = CvImageIn.data[j + Width * k];
				}
			}
		}
	}
	void TypeConverters::CvMatTo1DArray(const cv::Mat &CvImageIn, uint16_t *&Array1DOut)
	{
		const int Channels = CvImageIn.channels();
		const int Width = CvImageIn.cols;
		const int Height = CvImageIn.rows;

		const int N = Width * Height;

		Array1DOut = new uint16_t[N * Channels];

		if (Channels > 1)
		{
			for (int j = 0; j < Width; j++)
			{
				for (int k = 0; k < Height; k++)
				{
					for (int c = 0; c < Channels; c++)
					{
						Array1DOut[k + Height * j + N * (2 - c)] = ((uint16_t)CvImageIn.data[(j + Width * k) * 2 * Channels + (2 * c) + 1] << 8) | ((uint16_t)CvImageIn.data[(j + Width * k) * 2 * Channels + (2 * c)]);
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
					Array1DOut[k + Height * j] = ((uint16_t)CvImageIn.data[(j + Width * k) * 2 + 1] << 8) | ((uint16_t)CvImageIn.data[(j + Width * k) * 2]);
				}
			}
		}
	}
	void TypeConverters::CvMatTo1DArray(const cv::Mat &CvImageIn, double *&Array1DOut) 
	{
		const int Channels = CvImageIn.channels();
		const int Width = CvImageIn.cols;
		const int Height = CvImageIn.rows;

		const int N = Width * Height;

		Array1DOut = new double[N * Channels];

		if (Channels > 1)
		{
			for (int j = 0; j < Width; j++)
			{
				for (int k = 0; k < Height; k++)
				{
					const cv::Vec3d &V = CvImageIn.at<cv::Vec3d>(k, j);

					for (int c = 0; c < Channels; c++)
					{
						Array1DOut[k + Height * j + N * (2 - c)] = V(c);
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
					Array1DOut[k + Height * j] = CvImageIn.at<double>(k, j);
				}
			}
		}
	}
	void TypeConverters::CvMatTo1DArray(const cv::Mat &CvImageIn, float *&Array1DOut)
	{
		const int Channels = CvImageIn.channels();
		const int Width = CvImageIn.cols;
		const int Height = CvImageIn.rows;

		const int N = Width * Height;

		Array1DOut = new float[N * Channels];

		if (Channels > 1)
		{
			for (int j = 0; j < Width; j++)
			{
				for (int k = 0; k < Height; k++)
				{
					const cv::Vec3d &V = CvImageIn.at<cv::Vec3d>(k, j);

					for (int c = 0; c < Channels; c++)
					{
						Array1DOut[k + Height * j + N * (2 - c)] = V(c);
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
					Array1DOut[k + Height * j] = CvImageIn.at<float>(k, j);
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

	void TypeConverters::CvMatToMatlabMatrix(const cv::Mat &CvMatIn, MatlabMatrix &MatlabMatrixOut)
	{
		const cv::Mat &Matrix64d = Assert64dCvMat(CvMatIn);

		const int Height = Matrix64d.rows;
		const int Width = Matrix64d.cols;

		int Size[2] = { Height, Width };

		MatlabMatrixOut = emxCreateND_real_T(2, Size);

		for (int j = 0; j < Width; j++)
		{
			for (int k = 0; k < Height; k++)
			{
				MatlabMatrixOut->data[k + Height * j] = Matrix64d.at<double>(k, j);
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

	cv::Mat TypeConverters::Assert64dCvMat(const cv::Mat &Matrix)
	{
		if (Matrix.type() == cv::DataType<double>::type) return Matrix;

		cv::Mat CvMat64d;
		Matrix.convertTo(CvMat64d, cv::DataType<double>::type);

		return CvMat64d;
	}
}

