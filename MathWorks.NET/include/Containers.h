
#pragma once

#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>

typedef unsigned char byte;

namespace MathWorks
{
	namespace NET
	{
		public ref struct Point2d
		{
			Point2d() {};
			Point2d(double X, double Y)
			{
				this->X = X;
				this->Y = Y;
			}
			Point2d(const cv::Point2d &point2d)
			{
				this->X = point2d.x;
				this->Y = point2d.y;
			}
			double X = std::numeric_limits<double>::quiet_NaN(), Y = std::numeric_limits<double>::quiet_NaN();
		};

		public ref struct Size2i 
		{
			Size2i() {}
			Size2i(int Width, int Height)
			{
				this->Width = Width;
				this->Height = Height;
			}
			Size2i(const cv::Size2i &size2i) 
			{
				this->Width = size2i.width;
				this->Height = size2i.height;
			}
			int Width = std::numeric_limits<int>::quiet_NaN(), Height = std::numeric_limits<int>::quiet_NaN();
		};

		public ref class ImageData
		{
		public:

			ImageData(array<byte>^ Data, size_t Width, size_t Height, int BitDepth, int Channels);
			ImageData(const cv::Mat &Image);
			bool Save(System::String^ FilePath);

			cv::Mat ToCvMat();

			array<byte>^ Data;
			size_t Width, Height;
			int BitDepth;
			int Channels;

		private:

			static void AssertData16Bit(byte *&data, size_t Width, size_t Height, int BitDepth, int Channels);

		};
	}
}