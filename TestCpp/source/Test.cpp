
#include "C_Coder.h"
#include <Windows.h>
#include <profileapi.h>

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

void TestRandomNumberGenerator()
{
	std::cout << MathWorks::C_Coder::NormalRandom(10, 10) << "\n\n";
	std::cout << MathWorks::C_Coder::NormalRandom(10, 10) << "\n\n";
	std::cout << MathWorks::C_Coder::NormalRandom(10, 10) << "\n\n";
	std::cout << MathWorks::C_Coder::NormalRandom(10, 10) << "\n\n";

	std::cout << MathWorks::C_Coder::UniformRandom(10, 10) << "\n\n";
	std::cout << MathWorks::C_Coder::UniformRandom(10, 10) << "\n\n";
	std::cout << MathWorks::C_Coder::UniformRandom(10, 10) << "\n\n"; 
	std::cout << MathWorks::C_Coder::UniformRandom(10, 10) << "\n\n";

	std::vector<std::vector<int>> RandomData;

	for (int k = 0; k < 100; k++) 
	{
		RandomData.push_back(MathWorks::C_Coder::RandomPermute(20, 7));
	}

	for (int k = 0; k < 100; k++)
	{
		for (int j = 0; j < RandomData[k].size(); j++) std::cout << RandomData[k][j] << ", ";
		std::cout << "\n";
	}

	std::cout << "\n\n";
}

void TestAdaptiveThreshold() 
{
	const cv::Mat &DotsImage = cv::imread("Dots.png", cv::IMREAD_ANYDEPTH | cv::IMREAD_ANYCOLOR);

	const cv::Mat &IM = MathWorks::C_Coder::AdaptiveThreshold(DotsImage, 75.0, -4000, MathWorks::ThresholdMode::mean);

	cv::imwrite("Threshold.png", IM);

	std::vector<MathWorks::ComponentRegion> componentRegions = MathWorks::C_Coder::ConnectedComponents(IM, DotsImage, 0);

	for (int k = 0; k < componentRegions.size(); k++) 
	{
		std::cout << componentRegions[k].Area << "\n";
	}
}

int main()
{
	TestAdaptiveThreshold();

	return 0;
}
