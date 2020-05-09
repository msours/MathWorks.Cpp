#define CellArray_H

#pragma once

#include "MathWorks/mat.h"
#include "MathWorks/matrix.h"

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
		void Add(const double Data, int InsertRow, int InsertCol);
		void Add(const std::vector<double> &Data, int Rows, int Cols, int InsertRow, int InsertCol);
		void Add(const std::vector<double> &Data, int Rows, int Cols, int Dim3, int InsertRow, int InsertCol);
		void Add(const float Data, int InsertRow, int InsertCol);
		void Add(const std::vector<float> &Data, int Rows, int Cols, int Dim3, int InsertRow, int InsertCol);
		void Add(const std::vector<int8_t> &Data, int Rows, int Cols, int Dim3, int InsertRow, int InsertCol);
		void Add(const std::vector<int16_t> &Data, int Rows, int Cols, int Dim3, int InsertRow, int InsertCol);
		void Add(const std::vector<int32_t> &Data, int Rows, int Cols, int Dim3, int InsertRow, int InsertCol);
		void Add(const std::vector<int64_t> &Data, int Rows, int Cols, int Dim3, int InsertRow, int InsertCol);
		void Add(const std::vector<uint8_t> &Data, int Rows, int Cols, int Dim3, int InsertRow, int InsertCol);
		void Add(const std::vector<uint16_t> &Data, int Rows, int Cols, int Dim3, int InsertRow, int InsertCol);
		void Add(const std::vector<uint32_t> &Data, int Rows, int Cols, int Dim3, int InsertRow, int InsertCol);
		void Add(const std::vector<uint64_t> &Data, int Rows, int Cols, int Dim3, int InsertRow, int InsertCol);
		void Add(const std::string &Data, int InsertRow, int InsertCol);
		void Add(CellArray &Data, int InsertRow, int InsertCol);
		void Add(MatlabStruct &Data, int InsertRow, int InsertCol);
		void Add(const int Data, int InsertRow, int InsertCol);
		void Add(const bool Data, int InsertRow, int InsertCol);
	};
}

#include "MatlabStruct.h"