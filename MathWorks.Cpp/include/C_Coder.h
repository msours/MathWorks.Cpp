
#pragma once

#include "TypeConverters.h"

namespace MathWorks
{
	enum SensorAlignment
	{
		rggb = 0,
		bggr = 1,
		grbg = 2,
		gbrg = 3
	};

	enum ResizeMode
	{
		billinear = 0,
		bicubic = 1,
		nearest = 2
	};

	enum RandomGenerator
	{
		twister = 0,
		v5normal = 1,
		v4 = 2
	};
	enum ThresholdMode 
	{
		mean = 0,
		median = 1
	};

	class C_Coder
	{
	public:

		static bool DetectCheckerboardPoints(const cv::Mat &Image, const double CornerThreshold, std::vector<cv::Point2d> &CornerDetections, cv::Size2i &BoardSize);

		static cv::Mat Demosaic(const cv::Mat &BayerPatternImage, const SensorAlignment sensorAlignment);

		static cv::Mat Imresize(const cv::Mat &Image, const size_t NewHeight, const size_t NewWidth, const ResizeMode resizeMode);

		static std::vector<double> CubicSpline(const std::vector<double> &X, const std::vector<double> &Y, const std::vector<double> &SplineX);

		static double CubicSpline(const std::vector<double> &X, const std::vector<double> &Y, const double SplineX);

		static std::vector<double> Splineapp(const std::vector<double> &X, const std::vector<double> &Y, const std::vector<double> &Weight, const std::vector<double> &SplineX);

		static cv::Mat AdaptiveThreshold(const cv::Mat &Image, const double WindowSize, const double C, const ThresholdMode thresholdMode = ThresholdMode::mean);

		static std::vector<ComponentRegion> ConnectedComponents(const cv::Mat &BinaryImage, const cv::Mat &Image, const int StrelSize, const double AreaThreshold = 25.0);

		static std::vector<ComponentRegion> AdaptiveThresholdConnectedComponents(const cv::Mat &Image, const double WindowSize, const double C, const double AreaThreshold = 25.0, const ThresholdMode thresholdMode = ThresholdMode::mean);

		static cv::Mat UniformRandom(const size_t Rows, const size_t Columns, const uint32_t Seed, const RandomGenerator randomGenerator = RandomGenerator::twister);
		static cv::Mat UniformRandom(const size_t Rows, const size_t Columns, const RandomGenerator randomGenerator = RandomGenerator::twister);

		static cv::Mat NormalRandom(const size_t Rows, const size_t Columns, const uint32_t Seed, const RandomGenerator randomGenerator = RandomGenerator::twister);
		static cv::Mat NormalRandom(const size_t Rows, const size_t Columns, const RandomGenerator randomGenerator = RandomGenerator::twister);

		static std::vector<int> RandomPermute(const size_t RangeN, const size_t SampleN, const  uint32_t Seed, const RandomGenerator randomGenerator = RandomGenerator::twister);
		static std::vector<int> RandomPermute(const size_t RangeN, const size_t SampleN, const RandomGenerator randomGenerator = RandomGenerator::twister);

	};
}
