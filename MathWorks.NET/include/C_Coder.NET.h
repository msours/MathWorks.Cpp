
#include "C_Coder.h"
#include "Containers.h"

namespace MathWorks
{
	namespace NET
	{
		enum class SensorAlignment; 
		enum class ResizeMode;
		enum class RandomGenerator;
		enum class ThresholdMode;

		public ref class C_Coder abstract sealed 
		{
		public:
			static bool DetectCheckerboardPoints(ImageData^ Image, double CornerThreshold, array<Point2d^>^ %CornerDetections, Size2i^ %BoardSize);
			static ImageData^ Demosaic(ImageData^ BayerPatternImage, const SensorAlignment sensorAlignment);
			static ImageData^ Imresize(ImageData^ Image, size_t NewHeight, size_t NewWidth, ResizeMode resizeMode);
			static array<double>^ CubicSpline(array<double>^ X, array<double>^ Y, array<double>^ SplineX);
			static double CubicSpline(array<double>^ X, array<double>^ Y, double SplineX);
			static array<double>^ Splineapp(array<double>^ X, array<double>^ Y, array<double>^ Weight, array<double>^ SplineX);
		};

		public enum class SensorAlignment
		{
			rggb = 0,
			bggr = 1,
			grbg = 2,
			gbrg = 3
		};
		public enum class ResizeMode
		{
			billinear = 0,
			bicubic = 1,
			nearest = 2
		};

		public enum class RandomGenerator
		{
			twister = 0,
			v5normal = 1,
			v4 = 2
		};
		public enum class ThresholdMode
		{
			mean = 0,
			median = 1
		};
	}
}
