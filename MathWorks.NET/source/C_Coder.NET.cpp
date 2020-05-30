
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
		array<double>^ C_Coder::CubicSpline(array<double>^ X, array<double>^ Y, array<double>^ SplineX)
		{
			std::vector<double> X_, Y_, SplineX_;

			for (int k = 0; k < X->Length; k++) X_.push_back((double)X[k]);
			for (int k = 0; k < Y->Length; k++) Y_.push_back((double)Y[k]);
			for (int k = 0; k < SplineX->Length; k++) SplineX_.push_back((double)SplineX[k]);

			const std::vector<double> &SplineY_ = MathWorks::C_Coder::CubicSpline(X_, Y_, SplineX_);

			array<double>^ SplineY = gcnew array<double>(SplineY_.size());

			System::Runtime::InteropServices::Marshal::Copy(System::IntPtr((void *)SplineY_.data()), SplineY, 0, SplineY->Length);

			return SplineY;
		}
		double C_Coder::CubicSpline(array<double>^ X, array<double>^ Y, double SplineX)
		{
			std::vector<double> X_, Y_;

			for (int k = 0; k < X->Length; k++) X_.push_back((double)X[k]);
			for (int k = 0; k < Y->Length; k++) Y_.push_back((double)Y[k]);

			return MathWorks::C_Coder::CubicSpline(X_, Y_, SplineX);
		}
	}
}