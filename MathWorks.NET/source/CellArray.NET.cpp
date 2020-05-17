
#include "CellArray.NET.h"
#include <msclr\marshal_cppstd.h>

namespace MathWorks
{
	namespace NET
	{
		CellArray::CellArray(int Rows, int Cols)
		{
			this->Rows = Rows;
			this->Cols = Cols;

			this->CellArray_ = new MathWorks::CellArray(Rows, Cols);
		}
		CellArray::~CellArray()
		{
			this->CellArray_->~CellArray();
			delete this->CellArray_;
		}

		void CellArray::Add(CellArray^ Data, int InsertRow, int InsertCol)
		{
			this->CellArray_->Add(*Data->CellArray_, InsertRow, InsertCol);
		}
		void CellArray::Add(MatlabStruct^ Data, int InsertRow, int InsertCol)
		{
			this->CellArray_->Add(*Data->MatlabStruct_, InsertRow, InsertCol);
		}

		void CellArray::Add(double Data, int InsertRow, int InsertCol)
		{
			this->CellArray_->Add(Data, InsertRow, InsertCol);
		}
		void CellArray::Add(float Data, int InsertRow, int InsertCol)
		{
			this->CellArray_->Add(Data, InsertRow, InsertCol);
		}
		void CellArray::Add(int Data, int InsertRow, int InsertCol)
		{
			this->CellArray_->Add(Data, InsertRow, InsertCol);
		}
		void CellArray::Add(bool Data, int InsertRow, int InsertCol)
		{
			this->CellArray_->Add(Data, InsertRow, InsertCol);
		}

		void CellArray::Add(System::String^ Data, int InsertRow, int InsertCol)
		{
			const std::string &data = msclr::interop::marshal_as<std::string>(Data);

			this->CellArray_->Add(data, InsertRow, InsertCol);
		}

		void CellArray::Add(array<double>^ Data, int InsertRow, int InsertCol) 
		{
			this->ReshapeAdd(Data, 1, Data->Length, 1, InsertRow, InsertCol);
		}
		void CellArray::Add(array<float>^ Data, int InsertRow, int InsertCol)
		{
			this->ReshapeAdd(Data, 1, Data->Length, 1, InsertRow, InsertCol);
		}
		void CellArray::Add(array<INT8>^ Data, int InsertRow, int InsertCol)
		{
			this->ReshapeAdd(Data, 1, Data->Length, 1, InsertRow, InsertCol);
		}
		void CellArray::Add(array<INT16>^ Data, int InsertRow, int InsertCol)
		{
			this->ReshapeAdd(Data, 1, Data->Length, 1, InsertRow, InsertCol);
		}
		void CellArray::Add(array<int>^ Data, int InsertRow, int InsertCol)
		{
			this->ReshapeAdd(Data, 1, Data->Length, 1, InsertRow, InsertCol);
		}
		void CellArray::Add(array<INT64>^ Data, int InsertRow, int InsertCol)
		{
			this->ReshapeAdd(Data, 1, Data->Length, 1, InsertRow, InsertCol);
		}
		void CellArray::Add(array<UINT8>^ Data, int InsertRow, int InsertCol)
		{
			this->ReshapeAdd(Data, 1, Data->Length, 1, InsertRow, InsertCol);
		}
		void CellArray::Add(array<UINT16>^ Data, int InsertRow, int InsertCol)
		{
			this->ReshapeAdd(Data, 1, Data->Length, 1, InsertRow, InsertCol);
		}
		void CellArray::Add(array<UINT32>^ Data, int InsertRow, int InsertCol)
		{
			this->ReshapeAdd(Data, 1, Data->Length, 1, InsertRow, InsertCol);
		}
		void CellArray::Add(array<UINT64>^ Data, int InsertRow, int InsertCol)
		{
			this->ReshapeAdd(Data, 1, Data->Length, 1, InsertRow, InsertCol);
		}

		void CellArray::ReshapeAdd(array<double>^ Data, int Rows, int Cols, int Dim3, int InsertRow, int InsertCol)
		{
			int Length = Rows * Cols*Dim3;

			std::vector<double> data;
			for (int k = 0; k < Length; k++) data.push_back((double)Data[k]);

			this->CellArray_->ReshapeAdd(data, Rows, Cols, Dim3, InsertRow, InsertCol);
		}
		void CellArray::ReshapeAdd(array<float>^ Data, int Rows, int Cols, int Dim3, int InsertRow, int InsertCol)
		{
			int Length = Rows * Cols*Dim3;

			std::vector<float> data;
			for (int k = 0; k < Length; k++) data.push_back((float)Data[k]);

			this->CellArray_->ReshapeAdd(data, Rows, Cols, Dim3, InsertRow, InsertCol);
		}
		void CellArray::ReshapeAdd(array<INT8>^ Data, int Rows, int Cols, int Dim3, int InsertRow, int InsertCol)
		{
			int Length = Rows * Cols * Dim3;

			std::vector<INT8> data;
			for (int k = 0; k < Length; k++) data.push_back((INT8)Data[k]);

			this->CellArray_->ReshapeAdd(data, Rows, Cols, Dim3, InsertRow, InsertCol);
		}
		void CellArray::ReshapeAdd(array<INT16>^ Data, int Rows, int Cols, int Dim3, int InsertRow, int InsertCol)
		{
			int Length = Rows * Cols * Dim3;

			std::vector<INT16> data;
			for (int k = 0; k < Length; k++) data.push_back((INT16)Data[k]);

			this->CellArray_->ReshapeAdd(data, Rows, Cols, Dim3, InsertRow, InsertCol);
		}
		void CellArray::ReshapeAdd(array<INT32>^ Data, int Rows, int Cols, int Dim3, int InsertRow, int InsertCol)
		{
			int Length = Rows * Cols * Dim3;

			std::vector<INT32> data;
			for (int k = 0; k < Length; k++) data.push_back((INT32)Data[k]);

			this->CellArray_->ReshapeAdd(data, Rows, Cols, Dim3, InsertRow, InsertCol);
		}
		void CellArray::ReshapeAdd(array<INT64>^ Data, int Rows, int Cols, int Dim3, int InsertRow, int InsertCol)
		{
			int Length = Rows * Cols * Dim3;

			std::vector<INT64> data;
			for (int k = 0; k < Length; k++) data.push_back((INT64)Data[k]);

			this->CellArray_->ReshapeAdd(data, Rows, Cols, Dim3, InsertRow, InsertCol);
		}
		void CellArray::ReshapeAdd(array<UINT8>^ Data, int Rows, int Cols, int Dim3, int InsertRow, int InsertCol)
		{
			int Length = Rows * Cols * Dim3;

			std::vector<UINT8> data;
			for (int k = 0; k < Length; k++) data.push_back((UINT8)Data[k]);

			this->CellArray_->ReshapeAdd(data, Rows, Cols, Dim3, InsertRow, InsertCol);
		}
		void CellArray::ReshapeAdd(array<UINT16>^ Data, int Rows, int Cols, int Dim3, int InsertRow, int InsertCol)
		{
			int Length = Rows * Cols * Dim3;

			std::vector<UINT16> data;
			for (int k = 0; k < Length; k++) data.push_back((UINT16)Data[k]);

			this->CellArray_->ReshapeAdd(data, Rows, Cols, Dim3, InsertRow, InsertCol);
		}
		void CellArray::ReshapeAdd(array<UINT32>^ Data, int Rows, int Cols, int Dim3, int InsertRow, int InsertCol)
		{
			int Length = Rows * Cols * Dim3;

			std::vector<UINT32> data;
			for (int k = 0; k < Length; k++) data.push_back((UINT32)Data[k]);

			this->CellArray_->ReshapeAdd(data, Rows, Cols, Dim3, InsertRow, InsertCol);
		}
		void CellArray::ReshapeAdd(array<UINT64>^ Data, int Rows, int Cols, int Dim3, int InsertRow, int InsertCol)
		{
			int Length = Rows * Cols * Dim3;

			std::vector<UINT64> data;
			for (int k = 0; k < Length; k++) data.push_back((UINT64)Data[k]);

			this->CellArray_->ReshapeAdd(data, Rows, Cols, Dim3, InsertRow, InsertCol);
		}
	}
}
