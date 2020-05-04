
#include "MathWorks.h"

void TestDemosaic()
{
	const cv::Mat &BayerImage = cv::imread("BayerPattern.png", cv::IMREAD_ANYDEPTH | cv::IMREAD_ANYCOLOR);
	const cv::Mat &ColorImage = MathWorks::Functions::Demosaic(BayerImage, MathWorks::SensorAlignment::rggb);

	cv::imwrite("Color.png", ColorImage);
}

int main()
{
	const cv::Mat Image16Bit = cv::imread("16bit.png", cv::IMREAD_ANYDEPTH | cv::IMREAD_ANYCOLOR);

	const cv::Mat ResizedImage = MathWorks::Functions::Imresize(Image16Bit, 1000, 1000, MathWorks::ResizeMode::billinear);

	std::cout << cv::imwrite("ResizedImage.png", ResizedImage) << "\n";

	return 0;
}
