
#include "C_Coder.NET.h"

namespace MathWorks
{
	namespace NET
	{
		bool C_Coder::DetectCheckerboardPoints(ImageData^ Image, double CornerThreshold, array<Point2d^>^ %CornerDetections, Size2i^ %BoardSize)
		{
			const cv::Mat &image = Image->ToCvMat();

			std::vector<cv::Point2d> cornerDetections;
			cv::Size2i boardSize;

			bool Success = MathWorks::C_Coder::DetectCheckerboardPoints(image, CornerThreshold, cornerDetections, boardSize);
			if (!Success) return false;

			CornerDetections = gcnew array<Point2d^>(cornerDetections.size());
			for (int k = 0; k < cornerDetections.size(); k++)  CornerDetections[k] = gcnew Point2d(cornerDetections[k]);

			BoardSize = gcnew Size2i(boardSize);

			return true;
		}
		ImageData^ C_Coder::Demosaic(ImageData^ BayerPatternImage, const SensorAlignment sensorAlignment)
		{
			const cv::Mat &bayerPatternImage = BayerPatternImage->ToCvMat();
			const cv::Mat &ColorImage = MathWorks::C_Coder::Demosaic(bayerPatternImage, static_cast<MathWorks::SensorAlignment>(sensorAlignment));

			return gcnew ImageData(ColorImage);
		}
		ImageData^ C_Coder::Imresize(ImageData^ Image, size_t NewHeight, size_t NewWidth, ResizeMode resizeMode) 
		{
			const cv::Mat &image = Image->ToCvMat();
			const cv::Mat resizedImage = MathWorks::C_Coder::Imresize(image, NewHeight, NewWidth, static_cast<MathWorks::ResizeMode>(resizeMode));

			return gcnew ImageData(resizedImage);
		}
	}
}