
#pragma once
#include "CellArray.h"

#ifdef  CellArray_H

namespace MathWorks
{
	class MatlabStruct
	{
	public:
		mxArray *Destination;
		mxArray *Source = NULL;

		bool HighestStructure = true;

		int Rows;
		int Cols;
		int nFields;

		MatlabStruct(const int Rows, const int Cols, const int nFields, const std::vector<std::string> &FieldNames);
		~MatlabStruct();
		void Add(CellArray &Data, const std::string &FieldName, const int InsertRow, const int InsertCol);
		void Add(MatlabStruct &Data, const std::string &FieldName, const int InsertRow, const int InsertCol);
		void Add(double Data, const std::string &FieldName, const int InsertRow, const int InsertCol);
		void Add(const std::vector<double> &Data, const int Rows, const int Cols, const std::string &FieldName, const int InsertRow, const int InsertCol);
		void Add(const std::vector<double> &Data, const int Rows, const int Cols, const int Dim3, const std::string &FieldName, const int InsertRow, const int InsertCol);
		void Add(const float Data, const std::string &FieldName, const int InsertRow, const int InsertCol);
		void Add(const std::vector<float> &Data, const int Rows, const int Cols, const int Dim3, const std::string &FieldName, const int InsertRow, const int InsertCol);
		void Add(const std::vector<INT8> &Data, const int Rows, const int Cols, const int Dim3, const std::string &FieldName, const int InsertRow, const int InsertCol);
		void Add(const std::vector<int16_t> &Data, const int Rows, const int Cols, const int Dim3, const std::string &FieldName, const int InsertRow, const int InsertCol);
		void Add(const std::vector<int32_t> &Data, const int Rows, const int Cols, const int Dim3, const std::string &FieldName, const int InsertRow, const int InsertCol);
		void Add(const std::vector<int64_t> &Data, const int Rows, const int Cols, const int Dim3, const std::string &FieldName, const int InsertRow, const int InsertCol);
		void Add(const std::vector<uint8_t> &Data, const int Rows, const int Cols, const int Dim3, const std::string &FieldName, const int InsertRow, const int InsertCol);
		void Add(const std::vector<uint16_t> &Data, const int Rows, const int Cols, const int Dim3, const std::string &FieldName, const int InsertRow, const int InsertCol);
		void Add(const std::vector<uint32_t> &Data, const int Rows, const int Cols, const int Dim3, const std::string &FieldName, const int InsertRow, const int InsertCol);
		void Add(const std::vector<uint64_t> &Data, const int Rows, const int Cols, const int Dim3, const std::string &FieldName, const int InsertRow, const int InsertCol);
		void Add(const std::string &Data, const std::string &FieldName, const int InsertRow, const int InsertCol);
		void Add(const int Data, const std::string &FieldName, const int InsertRow, const int InsertCol);
		void Add(const bool Data, const std::string &FieldName, const int InsertRow, const int InsertCol);
	};
}

#endif