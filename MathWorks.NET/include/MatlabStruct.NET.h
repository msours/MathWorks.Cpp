
#pragma once

#include "MatlabStruct.h"
#include "CellArray.NET.h"

namespace MathWorks
{
	namespace NET
	{
		public ref class MatlabStruct : System::IDisposable
		{
		public:
			MatlabStruct(int Rows, int Cols, int nFields, array<System::String^>^ FieldNames);
			~MatlabStruct();

			void Add(CellArray^ Data, System::String^ FieldName, int InsertRow, int InsertCol);
			void Add(MatlabStruct^ Data, System::String^ FieldName, int InsertRow, int InsertCol);
			void Add(double Data, System::String^ FieldName, int InsertRow, int InsertCol);
			void Add(array<double>^ Data, int Rows, int Cols, System::String^ FieldName, int InsertRow, int InsertCol);
			void Add(array<double>^ Variable, int Rows, int Cols, int Dim3, System::String^ FieldName, int InsertRow, int InsertCol);
			void Add(float Data, System::String^ FieldName, int InsertRow, int InsertCol);
			void Add(array<float>^ Data, int Rows, int Cols, int Dim3, System::String^ FieldName, int InsertRow, int InsertCol);
			void Add(array<INT8>^ Data, int Rows, int Cols, int Dim3, System::String^ FieldName, int InsertRow, int InsertCol);
			void Add(array<INT16>^ Data, int Rows, int Cols, int Dim3, System::String^ FieldName, int InsertRow, int InsertCol);
			void Add(array<INT32>^ Data, int Rows, int Cols, int Dim3, System::String^ FieldName, int InsertRow, int InsertCol);
			void Add(array<INT64>^ Data, int Rows, int Cols, int Dim3, System::String^ FieldName, int InsertRow, int InsertCol);
			void Add(array<UINT8>^ Data, int Rows, int Cols, int Dim3, System::String^ FieldName, int InsertRow, int InsertCol);
			void Add(array<UINT16>^ Data, int Rows, int Cols, int Dim3, System::String^ FieldName, int InsertRow, int InsertCol);
			void Add(array<UINT32>^ Data, int Rows, int Cols, int Dim3, System::String^ FieldName, int InsertRow, int InsertCol);
			void Add(array<UINT64>^ Data, int Rows, int Cols, int Dim3, System::String^ FieldName, int InsertRow, int InsertCol);
			void Add(System::String^ Data, System::String^ FieldName, int InsertRow, int InsertCol);
			void Add(int Data, System::String^ FieldName, int InsertRow, int InsertCol);
			void Add(bool Data, System::String^ FieldName, int InsertRow, int InsertCol);

			int Rows;
			int Cols;

			array<System::String^>^ FieldNames;

			MathWorks::MatlabStruct *MatlabStruct_;
		};
	}
}
