
#pragma once

#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include "MathWorks/MathWorksCpp_types.h"

typedef unsigned char byte;

typedef emxArray_uint16_T* MatlabImage16;
typedef emxArray_uint8_T* MatlabImage8; 
typedef emxArray_boolean_T* MatlabImageBinary;
typedef emxArray_real_T* MatlabMatrix;

namespace MathWorks
{
	class TypeConverters
	{
	public:
		static void MatlabImageToCvMat(const MatlabImage16 &MatlabImageIn, cv::Mat &CvImageOut);
		static void MatlabImageToCvMat(const MatlabImage8 &MatlabImageIn, cv::Mat &CvImageOut);
		static void MatlabImageToCvMat(const MatlabImageBinary &MatlabImageIn, cv::Mat &CvImageOut);

		static void MatlabMatrixToCvMat(const MatlabMatrix &MatlabMatrixIn, cv::Mat &CvMatOut);

		static void CvMatToMatlabImage(const cv::Mat &CvImageIn, MatlabImage16 &MatlabImageOut);
		static void CvMatToMatlabImage(const cv::Mat &CvImageIn, MatlabImage8 &MatlabImageOut);
		static void CvMatToMatlabImage(const cv::Mat &CvImageIn, MatlabImageBinary &MatlabImageOut);
		static void CvMatTo1DArray(const cv::Mat &CvImageIn, uint8_t *&Array1DOut);
		static void CvMatTo1DArray(const cv::Mat &CvImageIn, uint16_t *&Array1DOut);
		static void CvMatTo1DArray(const cv::Mat &CvImageIn, double *&Array1DOut);
		static void CvMatTo1DArray(const cv::Mat &CvImageIn, float *&Array1DOut);

		static void CvMatToMatlabMatrix(const cv::Mat &CvMatIn, MatlabMatrix &MatlabMatrixOut);

		static void VectorToMatlabMatrix(const std::vector<double> &VectorIn, MatlabMatrix &MatlabMatrixOut);

		static cv::Mat Assert64dCvMat(const cv::Mat &Matrix);
	};

	struct ComponentRegion
	{
		ComponentRegion() {}
		ComponentRegion(const struct0_T &componentRegion)
		{
			this->WeightedCentroid = cv::Point2d(componentRegion.WeightedCentroid[0] - 1.0, componentRegion.WeightedCentroid[1] - 1.0);
			this->BoundingRectangle = cv::Rect2d((double)componentRegion.BoundingBox[0] - 1.0, (double)componentRegion.BoundingBox[1] - 1.0, (double)componentRegion.BoundingBox[2], (double)componentRegion.BoundingBox[3]);
			this->Area = componentRegion.Area;
			this->RectangleArea = BoundingRectangle.area();
		}
		ComponentRegion(const cv::Point2d &WeightedCentroid, const cv::Rect2f &BoundingRectangle, const double Area)
		{
			this->Area = Area;
			this->RectangleArea = BoundingRectangle.area();
			this->WeightedCentroid = WeightedCentroid;
			this->BoundingRectangle = BoundingRectangle;
		}
		cv::Point2d WeightedCentroid;
		cv::Rect2d BoundingRectangle;
		double Area;
		double RectangleArea;
	};
}
