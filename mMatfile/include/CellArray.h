#define CellArray_H

#pragma managed
#include "MathWorks/mat.h"
#include "MathWorks/matrix.h"
#include <Windows.h>

#pragma once

using namespace System;

namespace mMatfile
{
	ref class MatlabStruct;

	public ref class CellArray : IDisposable
	{
	public:
		mxArray *Destination;
		mxArray *Source = NULL;

		bool HighestStructure = true;

		int Rows;
		int Cols;

		CellArray(int Rows, int Cols);
		~CellArray();
		void Add(double Data, int InsertRow, int InsertCol);
		void Add(array<double>^ Data, int Rows, int Cols, int InsertRow, int InsertCol);
		void Add(array<double>^ Data, int Rows, int Cols, int Dim3, int InsertRow, int InsertCol);
		void Add(float Data, int InsertRow, int InsertCol);
		void Add(array<float>^ Data, int Rows, int Cols, int Dim3, int InsertRow, int InsertCol);
		void Add(array<INT8>^ Data, int Rows, int Cols, int Dim3, int InsertRow, int InsertCol);
		void Add(array<INT16>^ Data, int Rows, int Cols, int Dim3, int InsertRow, int InsertCol);
		void Add(array<INT32>^ Data, int Rows, int Cols, int Dim3, int InsertRow, int InsertCol);
		void Add(array<INT64>^ Data, int Rows, int Cols, int Dim3, int InsertRow, int InsertCol);
		void Add(array<UINT8>^ Data, int Rows, int Cols, int Dim3, int InsertRow, int InsertCol);
		void Add(array<UINT16>^ Data, int Rows, int Cols, int Dim3, int InsertRow, int InsertCol);
		void Add(array<UINT32>^ Data, int Rows, int Cols, int Dim3, int InsertRow, int InsertCol);
		void Add(array<UINT64>^ Data, int Rows, int Cols, int Dim3, int InsertRow, int InsertCol);
		void Add(String^ Data, int InsertRow, int InsertCol);
		void Add(CellArray^ Data, int InsertRow, int InsertCol);
		void Add(MatlabStruct^ Data, int InsertRow, int InsertCol);
		void Add(int Data, int InsertRow, int InsertCol);
		void Add(bool Data, int InsertRow, int InsertCol);
	};
}

#include "MatlabStruct.h"