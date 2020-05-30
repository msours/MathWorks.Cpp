
#include "Containers.h"

namespace MathWorks
{
	namespace NET
	{
		ImageData::ImageData(array<byte>^ Data, size_t Width, size_t Height, int BitDepth, int Channels)
		{
			this->Data = Data;
			this->Width = Width;
			this->Height = Height;
			this->BitDepth = BitDepth;
			this->Channels = Channels;
		}
		cv::Mat ImageData::ToCvMat()
		{
			byte* data = new byte[Data->Length];
			System::Runtime::InteropServices::Marshal::Copy(Data, 0, System::IntPtr(data), Data->Length);

			cv::Mat Image;

			if (BitDepth <= 8) Image = cv::Mat(Height, Width, CV_MAKETYPE(CV_8U, Channels), data);
			else
			{
				ImageData::AssertData16Bit(data, Width, Height, BitDepth, Channels);
				Image = cv::Mat(Height, Width, CV_MAKETYPE(CV_16U, Channels), data);
			}

			return Image;
		}

		void ImageData::AssertData16Bit(byte *&data, size_t Width, size_t Height, int BitDepth, int Channels)
		{
			if (BitDepth == 16) return;

			byte lsb, msb;
			uint16_t Value;

			double Scale = 65535.0 / (pow(2, BitDepth) - 1.0);

			int j = 0;
			for (size_t k = 0; k < Width * Height * Channels; k++)
			{
				Value = ((uint16_t)data[j + 1] << 8) | ((uint16_t)data[j]);
				Value = (uint16_t)((double)Value * Scale);

				lsb = (byte)(Value & 0xFF);
				msb = (byte)((Value >> 8) & 0xFF);

				data[j] = lsb;
				data[j + 1] = msb;

				j += 2;
			}
		}
	}
}