
#include "CellArray.h"
#include <vector>

namespace MathWorks
{
	CellArray::CellArray(int Rows, int Cols)
	{
		this->Rows = Rows;
		this->Cols = Cols;

		Destination = mxCreateCellMatrix(Rows, Cols);
	}
	CellArray::~CellArray()
	{
		if (HighestStructure && !Destination == NULL)
		{
			mxDestroyArray(Destination);
			Destination = NULL;
		}
	}
	void CellArray::Add(double Data, int InsertRow, int InsertCol)
	{
		Source = mxCreateDoubleScalar(Data);
		
		memcpy((void *)(mxGetPr(Source)), (void *)&Data, sizeof(double));

		int Ind = (InsertCol - 1) * this->Rows + InsertRow - 1;
		mxSetCell(Destination, Ind, Source);
	}
	void CellArray::Add(const std::vector<double> &Data, int Rows, int Cols, int InsertRow, int InsertCol)
	{
		int Length = Rows * Cols;

		Source = mxCreateDoubleMatrix(Rows, Cols, mxREAL);

		memcpy((void *)(mxGetPr(Source)), (void *)Data.data(), sizeof(double)*Length);

		int Ind = (InsertCol - 1)*this->Rows + InsertRow - 1;
		mxSetCell(Destination, Ind, Source);
	}
	void CellArray::Add(const std::vector<double> &Data, int Rows, int Cols, int Dim3, int InsertRow, int InsertCol)
	{
		int Length = Rows * Cols*Dim3;

		size_t Dim[3];
		Dim[0] = Rows;
		Dim[1] = Cols;
		Dim[2] = Dim3;

		Source = mxCreateNumericArray(3, Dim, mxDOUBLE_CLASS, mxREAL);

		memcpy((void *)(mxGetPr(Source)), (void *)Data.data(), sizeof(double)*Length);

		int Ind = (InsertCol - 1)*this->Rows + InsertRow - 1;
		mxSetCell(Destination, Ind, Source);
	}
	void CellArray::Add(float Data, int InsertRow, int InsertCol)
	{
		double value = static_cast<double>(Data);
		Source = mxCreateDoubleScalar(value);

		memcpy((void *)(mxGetPr(Source)), (void *)&value, sizeof(double));

		int Ind = (InsertCol - 1)*this->Rows + InsertRow - 1;
		mxSetCell(Destination, Ind, Source);
	}
	void CellArray::Add(int Data, int InsertRow, int InsertCol)
	{
		double value = static_cast<double>(Data);
		Source = mxCreateDoubleScalar(value);

		memcpy((void *)(mxGetPr(Source)), (void *)&value, sizeof(double));

		int Ind = (InsertCol - 1)*this->Rows + InsertRow - 1;
		mxSetCell(Destination, Ind, Source);
	}
	void CellArray::Add(bool Data, int InsertRow, int InsertCol)
	{
		Source = mxCreateLogicalScalar(Data);

		int Ind = (InsertCol - 1)*this->Rows + InsertRow - 1;
		mxSetCell(Destination, Ind, Source);
	}
	void CellArray::Add(const std::vector<float> &Data, int Rows, int Cols, int Dim3, int InsertRow, int InsertCol)
	{
		int Length = Rows * Cols*Dim3;

		size_t Dim[3];
		Dim[0] = Rows;
		Dim[1] = Cols;
		Dim[2] = Dim3;

		Source = mxCreateNumericArray(3, Dim, mxSINGLE_CLASS, mxREAL);

		memcpy((void *)(mxGetPr(Source)), (void *)Data.data(), sizeof(float)*Length);

		int Ind = (InsertCol - 1) * this->Rows + InsertRow - 1;
		mxSetCell(Destination, Ind, Source);
	}
	void CellArray::Add(const std::vector<INT8> &Data, int Rows, int Cols, int Dim3, int InsertRow, int InsertCol)
	{
		int Length = Rows * Cols*Dim3;

		size_t Dim[3];
		Dim[0] = Rows;
		Dim[1] = Cols;
		Dim[2] = Dim3;

		Source = mxCreateNumericArray(3, Dim, mxINT8_CLASS, mxREAL);

		memcpy((void *)(mxGetPr(Source)), (void *)Data.data(), sizeof(INT8)*Length);

		int Ind = (InsertCol - 1)*this->Rows + InsertRow - 1;
		mxSetCell(Destination, Ind, Source);
	}
	void CellArray::Add(const std::vector<int16_t> &Data, int Rows, int Cols, int Dim3, int InsertRow, int InsertCol)
	{
		int Length = Rows * Cols*Dim3;

		size_t Dim[3];
		Dim[0] = Rows;
		Dim[1] = Cols;
		Dim[2] = Dim3;

		Source = mxCreateNumericArray(3, Dim, mxINT16_CLASS, mxREAL);

		memcpy((void *)(mxGetPr(Source)), (void *)Data.data(), sizeof(INT16)*Length);

		int Ind = (InsertCol - 1)*this->Rows + InsertRow - 1;
		mxSetCell(Destination, Ind, Source);
	}
	void CellArray::Add(const std::vector<int32_t> &Data, int Rows, int Cols, int Dim3, int InsertRow, int InsertCol)
	{
		int Length = Rows * Cols*Dim3;

		size_t Dim[3];
		Dim[0] = Rows;
		Dim[1] = Cols;
		Dim[2] = Dim3;

		Source = mxCreateNumericArray(3, Dim, mxINT32_CLASS, mxREAL);

		memcpy((void *)(mxGetPr(Source)), (void *)Data.data(), sizeof(INT32)*Length);

		int Ind = (InsertCol - 1) * this->Rows + InsertRow - 1;
		mxSetCell(Destination, Ind, Source);
	}
	void CellArray::Add(const std::vector<int64_t> &Data, int Rows, int Cols, int Dim3, int InsertRow, int InsertCol)
	{
		int Length = Rows * Cols*Dim3;

		size_t Dim[3];
		Dim[0] = Rows;
		Dim[1] = Cols;
		Dim[2] = Dim3;

		Source = mxCreateNumericArray(3, Dim, mxINT64_CLASS, mxREAL);

		memcpy((void *)(mxGetPr(Source)), (void *)Data.data(), sizeof(INT64)*Length);

		int Ind = (InsertCol - 1) * this->Rows + InsertRow - 1;
		mxSetCell(Destination, Ind, Source);
	}
	void CellArray::Add(const std::vector<uint8_t> &Data, int Rows, int Cols, int Dim3, int InsertRow, int InsertCol)
	{
		int Length = Rows * Cols*Dim3;

		size_t Dim[3];
		Dim[0] = Rows;
		Dim[1] = Cols;
		Dim[2] = Dim3;

		Source = mxCreateNumericArray(3, Dim, mxUINT8_CLASS, mxREAL);

		memcpy((void *)(mxGetPr(Source)), (void *)Data.data(), sizeof(UINT8)*Length);

		int Ind = (InsertCol - 1)*this->Rows + InsertRow - 1;
		mxSetCell(Destination, Ind, Source);
	}
	void CellArray::Add(const std::vector<uint16_t> &Data, int Rows, int Cols, int Dim3, int InsertRow, int InsertCol)
	{
		int Length = Rows * Cols*Dim3;

		size_t Dim[3];
		Dim[0] = Rows;
		Dim[1] = Cols;
		Dim[2] = Dim3;

		Source = mxCreateNumericArray(3, Dim, mxUINT16_CLASS, mxREAL);

		memcpy((void *)(mxGetPr(Source)), (void *)Data.data(), sizeof(UINT16)*Length);

		int Ind = (InsertCol - 1) * this->Rows + InsertRow - 1;
		mxSetCell(Destination, Ind, Source);
	}
	void CellArray::Add(const std::vector<uint32_t> &Data, int Rows, int Cols, int Dim3, int InsertRow, int InsertCol)
	{
		int Length = Rows * Cols*Dim3;

		size_t Dim[3];
		Dim[0] = Rows;
		Dim[1] = Cols;
		Dim[2] = Dim3;

		Source = mxCreateNumericArray(3, Dim, mxUINT32_CLASS, mxREAL);

		memcpy((void *)(mxGetPr(Source)), (void *)Data.data(), sizeof(UINT32)*Length);

		int Ind = (InsertCol - 1)*this->Rows + InsertRow - 1;
		mxSetCell(Destination, Ind, Source);
	}
	void CellArray::Add(const std::vector<uint64_t> &Data, int Rows, int Cols, int Dim3, int InsertRow, int InsertCol)
	{
		int Length = Rows * Cols*Dim3;

		size_t Dim[3];
		Dim[0] = Rows;
		Dim[1] = Cols;
		Dim[2] = Dim3;

		Source = mxCreateNumericArray(3, Dim, mxUINT64_CLASS, mxREAL);

		memcpy((void *)(mxGetPr(Source)), (void *)Data.data(), sizeof(UINT64)*Length);

		int Ind = (InsertCol - 1) * this->Rows + InsertRow - 1;
		mxSetCell(Destination, Ind, Source);
	}
	void CellArray::Add(const std::string &Data, int InsertRow, int InsertCol)
	{
		const char *V = Data.c_str();
		Source = mxCreateString(V);

		int Ind = (InsertCol - 1) * this->Rows + InsertRow - 1;
		mxSetCell(Destination, Ind, Source);
	}
	void CellArray::Add(CellArray &Data, int InsertRow, int InsertCol)
	{
		int Ind = (InsertCol - 1)*this->Rows + InsertRow - 1;
		mxSetCell(Destination, Ind, Data.Destination);

		this->HighestStructure = true;
		Data.HighestStructure = false;
	}
	void CellArray::Add(MatlabStruct &Data, int InsertRow, int InsertCol)
	{
		int Ind = (InsertCol - 1)*(this->Rows) + InsertRow - 1;
		mxSetCell(Destination, Ind, Data.Destination);

		this->HighestStructure = true;
		Data.HighestStructure = false;
	}
}