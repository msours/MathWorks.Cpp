
#pragma once
#include "CellArray.h"

#ifdef  CellArray_H

using namespace System;

namespace mMatfile
{
	public ref class MatlabStruct : IDisposable
	{
	public:
		mxArray *Destination;
		mxArray *Source = NULL;

		bool HighestStructure = true;

		int Rows;
		int Cols;
		int nFields;
		array<String^>^ FieldNames;

		MatlabStruct(int Rows, int Cols, int nFields, array<String^>^ FieldNames);
		~MatlabStruct();
		void Add(CellArray^ Data, String^ FieldName, int InsertRow, int InsertCol);
		void Add(MatlabStruct^ Data, String^ FieldName, int InsertRow, int InsertCol);
		void Add(double Data, String^ FieldName, int InsertRow, int InsertCol);
		void Add(array<double>^ Data, int Rows, int Cols, String^ FieldName, int InsertRow, int InsertCol);
		void Add(array<double>^ Variable, int Rows, int Cols, int Dim3, String^ FieldName, int InsertRow, int InsertCol);
		void Add(float Data, String^ FieldName, int InsertRow, int InsertCol);
		void Add(array<float>^ Data, int Rows, int Cols, int Dim3, String^ FieldName, int InsertRow, int InsertCol);
		void Add(array<INT8>^ Data, int Rows, int Cols, int Dim3, String^ FieldName, int InsertRow, int InsertCol);
		void Add(array<INT16>^ Data, int Rows, int Cols, int Dim3, String^ FieldName, int InsertRow, int InsertCol);
		void Add(array<INT32>^ Data, int Rows, int Cols, int Dim3, String^ FieldName, int InsertRow, int InsertCol);
		void Add(array<INT64>^ Data, int Rows, int Cols, int Dim3, String^ FieldName, int InsertRow, int InsertCol);
		void Add(array<UINT8>^ Data, int Rows, int Cols, int Dim3, String^ FieldName, int InsertRow, int InsertCol);
		void Add(array<UINT16>^ Data, int Rows, int Cols, int Dim3, String^ FieldName, int InsertRow, int InsertCol);
		void Add(array<UINT32>^ Data, int Rows, int Cols, int Dim3, String^ FieldName, int InsertRow, int InsertCol);
		void Add(array<UINT64>^ Data, int Rows, int Cols, int Dim3, String^ FieldName, int InsertRow, int InsertCol);
		void Add(String^ Data, String^ FieldName, int InsertRow, int InsertCol);
		void Add(int Data, String^ FieldName, int InsertRow, int InsertCol);
		void Add(bool Data, String^ FieldName, int InsertRow, int InsertCol);
	};
}

#endif