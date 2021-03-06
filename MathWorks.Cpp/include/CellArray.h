#define CellArray_H

#pragma once

#include <vector>

#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include "mat.h"
#include "matrix.h"
#include "TypeConverters.h"

namespace MathWorks
{
	class MatlabStruct;

	class CellArray
	{
	public:
		mxArray *Destination;
		mxArray *Source = NULL;

		bool HighestStructure = true;

		int Rows;
		int Cols;

		CellArray(int Rows, int Cols);
		~CellArray();

		void Add(CellArray &Data, int InsertRow, int InsertCol);
		void Add(MatlabStruct &Data, int InsertRow, int InsertCol);

		void Add(const double Data, int InsertRow, int InsertCol);
		void Add(const float Data, int InsertRow, int InsertCol);
		void Add(const int Data, int InsertRow, int InsertCol);
		void Add(const bool Data, int InsertRow, int InsertCol);
		void Add(const std::string &Data, int InsertRow, int InsertCol);

		void ReshapeAdd(const std::vector<double> &Data, int InsertRow, int InsertCol);
		void ReshapeAdd(const std::vector<float> &Data, int InsertRow, int InsertCol);
		void ReshapeAdd(const std::vector<int8_t> &Data, int InsertRow, int InsertCol);
		void ReshapeAdd(const std::vector<int16_t> &Data, int InsertRow, int InsertCol);
		void ReshapeAdd(const std::vector<int> &Data, int InsertRow, int InsertCol);
		void ReshapeAdd(const std::vector<int64_t> &Data, int InsertRow, int InsertCol);
		void ReshapeAdd(const std::vector<uint8_t> &Data, int InsertRow, int InsertCol);
		void ReshapeAdd(const std::vector<uint16_t> &Data, int InsertRow, int InsertCol);
		void ReshapeAdd(const std::vector<uint32_t> &Data, int InsertRow, int InsertCol);
		void ReshapeAdd(const std::vector<uint64_t> &Data, int InsertRow, int InsertCol);

		void ReshapeAdd(const std::vector<double> &Data, int Rows, int Cols, int Dim3, int InsertRow, int InsertCol);
		void ReshapeAdd(const std::vector<float> &Data, int Rows, int Cols, int Dim3, int InsertRow, int InsertCol);
		void ReshapeAdd(const std::vector<int8_t> &Data, int Rows, int Cols, int Dim3, int InsertRow, int InsertCol);
		void ReshapeAdd(const std::vector<int16_t> &Data, int Rows, int Cols, int Dim3, int InsertRow, int InsertCol);
		void ReshapeAdd(const std::vector<int32_t> &Data, int Rows, int Cols, int Dim3, int InsertRow, int InsertCol);
		void ReshapeAdd(const std::vector<int64_t> &Data, int Rows, int Cols, int Dim3, int InsertRow, int InsertCol);
		void ReshapeAdd(const std::vector<uint8_t> &Data, int Rows, int Cols, int Dim3, int InsertRow, int InsertCol);
		void ReshapeAdd(const std::vector<uint16_t> &Data, int Rows, int Cols, int Dim3, int InsertRow, int InsertCol);
		void ReshapeAdd(const std::vector<uint32_t> &Data, int Rows, int Cols, int Dim3, int InsertRow, int InsertCol);
		void ReshapeAdd(const std::vector<uint64_t> &Data, int Rows, int Cols, int Dim3, int InsertRow, int InsertCol);

		void AddImage(const cv::Mat &Image, int InsertRow, int InsertCol);

	private:

		void ReshapeAdd(const double *Data, const int Rows, const int Cols, const int Dim3, int InsertRow, int InsertCol);
		void ReshapeAdd(const float *Data, const int Rows, const int Cols, const int Dim3, int InsertRow, int InsertCol);
		void ReshapeAdd(const uint8_t *Data, const int Rows, const int Cols, const int Dim3, int InsertRow, int InsertCol);
		void ReshapeAdd(const uint16_t *Data, const int Rows, const int Cols, const int Dim3, int InsertRow, int InsertCol);
	};
}

#include "MatlabStruct.h"