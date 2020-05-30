
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

		std::vector<std::string> FieldNames;

		MatlabStruct(const int Rows, const int Cols, const std::vector<std::string> &FieldNames);
		~MatlabStruct();

		void Add(CellArray &Data, const std::string &FieldName, const int InsertRow, const int InsertCol);
		void Add(MatlabStruct &Data, const std::string &FieldName, const int InsertRow, const int InsertCol);

		void Add(double Data, const std::string &FieldName, const int InsertRow, const int InsertCol);
		void Add(const float Data, const std::string &FieldName, const int InsertRow, const int InsertCol);
		void Add(const int Data, const std::string &FieldName, const int InsertRow, const int InsertCol);
		void Add(const bool Data, const std::string &FieldName, const int InsertRow, const int InsertCol);
		void Add(const std::string &Data, const std::string &FieldName, const int InsertRow, const int InsertCol);

		void Add(const std::vector<double> &Data, const std::string &FieldName, const int InsertRow, const int InsertCol);
		void Add(const std::vector<float> &Data, const std::string &FieldName, const int InsertRow, const int InsertCol);
		void Add(const std::vector<uint8_t> &Data, const std::string &FieldName, const int InsertRow, const int InsertCol);
		void Add(const std::vector<uint16_t> &Data, const std::string &FieldName, const int InsertRow, const int InsertCol);
		void Add(const std::vector<uint32_t> &Data, const std::string &FieldName, const int InsertRow, const int InsertCol);
		void Add(const std::vector<uint64_t> &Data, const std::string &FieldName, const int InsertRow, const int InsertCol);
		void Add(const std::vector<int8_t> &Data, const std::string &FieldName, const int InsertRow, const int InsertCol);
		void Add(const std::vector<int16_t> &Data, const std::string &FieldName, const int InsertRow, const int InsertCol);
		void Add(const std::vector<int> &Data, const std::string &FieldName, const int InsertRow, const int InsertCol);
		void Add(const std::vector<int64_t> &Data, const std::string &FieldName, const int InsertRow, const int InsertCol);

		void ReshapeAdd(const std::vector<double> &Data, const int Rows, const int Cols, const int Dim3, const std::string &FieldName, const int InsertRow, const int InsertCol);
		void ReshapeAdd(const std::vector<float> &Data, const int Rows, const int Cols, const int Dim3, const std::string &FieldName, const int InsertRow, const int InsertCol);
		void ReshapeAdd(const std::vector<int8_t> &Data, const int Rows, const int Cols, const int Dim3, const std::string &FieldName, const int InsertRow, const int InsertCol);
		void ReshapeAdd(const std::vector<int16_t> &Data, const int Rows, const int Cols, const int Dim3, const std::string &FieldName, const int InsertRow, const int InsertCol);
		void ReshapeAdd(const std::vector<int32_t> &Data, const int Rows, const int Cols, const int Dim3, const std::string &FieldName, const int InsertRow, const int InsertCol);
		void ReshapeAdd(const std::vector<int64_t> &Data, const int Rows, const int Cols, const int Dim3, const std::string &FieldName, const int InsertRow, const int InsertCol);
		void ReshapeAdd(const std::vector<uint8_t> &Data, const int Rows, const int Cols, const int Dim3, const std::string &FieldName, const int InsertRow, const int InsertCol);
		void ReshapeAdd(const std::vector<uint16_t> &Data, const int Rows, const int Cols, const int Dim3, const std::string &FieldName, const int InsertRow, const int InsertCol);
		void ReshapeAdd(const std::vector<uint32_t> &Data, const int Rows, const int Cols, const int Dim3, const std::string &FieldName, const int InsertRow, const int InsertCol);
		void ReshapeAdd(const std::vector<uint64_t> &Data, const int Rows, const int Cols, const int Dim3, const std::string &FieldName, const int InsertRow, const int InsertCol);

	private:

		void ReshapeAdd(const double *Data, const int Rows, const int Cols, const int Dim3, const std::string &FieldName, int InsertRow, int InsertCol);
		void ReshapeAdd(const float *Data, const int Rows, const int Cols, const int Dim3, const std::string &FieldName, int InsertRow, int InsertCol);
		void ReshapeAdd(const uint8_t *Data, const int Rows, const int Cols, const int Dim3, const std::string &FieldName, int InsertRow, int InsertCol);
		void ReshapeAdd(const uint16_t *Data, const int Rows, const int Cols, const int Dim3, const std::string &FieldName, int InsertRow, int InsertCol);
	};
}

#endif