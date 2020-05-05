
#include "C_Coder.h"

void TestDemosaic()
{
	const cv::Mat &BayerImage = cv::imread("BayerPattern.png", cv::IMREAD_ANYDEPTH | cv::IMREAD_ANYCOLOR);
	const cv::Mat &ColorImage = MathWorks::C_Coder::Demosaic(BayerImage, MathWorks::SensorAlignment::rggb);

	cv::imwrite("Color.png", ColorImage);
}

void Testimresize()
{
	const cv::Mat Image48Bit = cv::imread("48bit.png", cv::IMREAD_ANYDEPTH | cv::IMREAD_ANYCOLOR);

	const cv::Mat ResizedImage = MathWorks::C_Coder::Imresize(Image48Bit, 1000, 1000, MathWorks::ResizeMode::billinear);

	std::cout << cv::imwrite("ResizedImage.png", ResizedImage) << "\n";
}

void TestDetectCheckerboardPoints()
{
	const cv::Mat &CheckerboardImage = cv::imread("Checkerboard.png", cv::IMREAD_ANYDEPTH | cv::IMREAD_ANYCOLOR);

	std::vector<cv::Point2d> CornerDetections;
	cv::Size2i BoardSize;

	std::cout << MathWorks::C_Coder::DetectCheckerboardPoints(CheckerboardImage, 0.03, CornerDetections, BoardSize) << "\n\n";

	for (int k = 0; k < CornerDetections.size(); k++) std::cout << CornerDetections[k].x << ", " << CornerDetections[k].y << "\n";

}

int main()
{
	TestDetectCheckerboardPoints();

	return 0;
}
