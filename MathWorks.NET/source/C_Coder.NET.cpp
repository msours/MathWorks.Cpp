
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
		ImageData^ Demosaic(ImageData^ BayerPatternImage, const SensorAlignment sensorAlignment)
		{
			const cv::Mat &bayerPatternImage = BayerPatternImage->ToCvMat();
			const cv::Mat &ColorImage = MathWorks::C_Coder::Demosaic(bayerPatternImage, static_cast<MathWorks::SensorAlignment>(sensorAlignment));

			return gcnew ImageData(ColorImage);
		}
	}
}