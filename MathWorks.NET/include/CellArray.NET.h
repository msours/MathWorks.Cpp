
#pragma once

#include "CellArray.h"
#include <Windows.h>

namespace MathWorks
{
	namespace NET
	{
		ref class MatlabStruct;

		public ref class CellArray : System::IDisposable
		{
		public:

			CellArray(int Rows, int Cols);
			~CellArray();

			void Add(CellArray^ Data, int InsertRow, int InsertCol);
			void Add(MatlabStruct^ Data, int InsertRow, int InsertCol);

			void Add(double Data, int InsertRow, int InsertCol);
			void Add(float Data, int InsertRow, int InsertCol);
			void Add(int Data, int InsertRow, int InsertCol);
			void Add(bool Data, int InsertRow, int InsertCol);
			void Add(System::String^ Data, int InsertRow, int InsertCol);

			void Add(array<double>^ Data, int InsertRow, int InsertCol);
			void Add(array<float>^ Data, int InsertRow, int InsertCol);
			void Add(array<INT8>^ Data, int InsertRow, int InsertCol);
			void Add(array<INT16>^ Data, int InsertRow, int InsertCol);
			void Add(array<int>^ Data, int InsertRow, int InsertCol);
			void Add(array<INT64>^ Data, int InsertRow, int InsertCol);
			void Add(array<UINT8>^ Data, int InsertRow, int InsertCol);
			void Add(array<UINT16>^ Data, int InsertRow, int InsertCol);
			void Add(array<UINT32>^ Data, int InsertRow, int InsertCol);
			void Add(array<UINT64>^ Data, int InsertRow, int InsertCol);

			void Add(array<double, 2>^ Data, int InsertRow, int InsertCol);
			void Add(array<float, 2>^ Data, int InsertRow, int InsertCol);
			void Add(array<UINT8, 2>^ Data, int InsertRow, int InsertCol);
			void Add(array<UINT16, 2>^ Data, int InsertRow, int InsertCol);

			void Add(array<double, 3>^ Data, int InsertRow, int InsertCol);
			void Add(array<float, 3>^ Data, int InsertRow, int InsertCol);
			void Add(array<UINT8, 3>^ Data, int InsertRow, int InsertCol);
			void Add(array<UINT16, 3>^ Data, int InsertRow, int InsertCol);

			void ReshapeAdd(array<double>^ Data, int Rows, int Cols, int Dim3, int InsertRow, int InsertCol);
			void ReshapeAdd(array<float>^ Data, int Rows, int Cols, int Dim3, int InsertRow, int InsertCol);
			void ReshapeAdd(array<INT8>^ Data, int Rows, int Cols, int Dim3, int InsertRow, int InsertCol);
			void ReshapeAdd(array<INT16>^ Data, int Rows, int Cols, int Dim3, int InsertRow, int InsertCol);
			void ReshapeAdd(array<INT32>^ Data, int Rows, int Cols, int Dim3, int InsertRow, int InsertCol);
			void ReshapeAdd(array<INT64>^ Data, int Rows, int Cols, int Dim3, int InsertRow, int InsertCol);
			void ReshapeAdd(array<UINT8>^ Data, int Rows, int Cols, int Dim3, int InsertRow, int InsertCol);
			void ReshapeAdd(array<UINT16>^ Data, int Rows, int Cols, int Dim3, int InsertRow, int InsertCol);
			void ReshapeAdd(array<UINT32>^ Data, int Rows, int Cols, int Dim3, int InsertRow, int InsertCol);
			void ReshapeAdd(array<UINT64>^ Data, int Rows, int Cols, int Dim3, int InsertRow, int InsertCol);

			MathWorks::CellArray *CellArray_;
			int Rows;
			int Cols;

		};
	}
}

#include "MatlabStruct.NET.h"