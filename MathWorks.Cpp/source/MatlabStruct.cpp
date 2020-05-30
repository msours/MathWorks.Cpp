
#include "MatlabStruct.h"

namespace MathWorks
{
	MatlabStruct::MatlabStruct(const int Rows, const int Cols, const std::vector<std::string> &FieldNames)
	{
		this->Rows = Rows;
		this->Cols = Cols;
		this->FieldNames = FieldNames;

		char **names = new char*[FieldNames.size()];

		for (int k = 0; k < FieldNames.size(); k++) names[k] = const_cast<char *>(FieldNames[k].c_str());

		Destination = mxCreateStructMatrix(Rows, Cols, FieldNames.size(), const_cast<const char **>(names));

		delete[] names;
	}
	MatlabStruct::~MatlabStruct()
	{
		if (HighestStructure && !Destination == NULL)
		{
			mxDestroyArray(Destination);
			Destination = NULL;
		}
	}
	void MatlabStruct::Add(CellArray &Data, const std::string &FieldName, const int InsertRow, const int InsertCol)
	{
		const char *fieldName = FieldName.c_str();
		if (mxGetFieldNumber(Destination, fieldName) == -1) return;

		int Ind = (InsertCol - 1)*this->Rows + InsertRow - 1;
		mxSetField(Destination, Ind, fieldName, Data.Destination);

		this->HighestStructure = true;
		Data.HighestStructure = false;
	}
	void MatlabStruct::Add(MatlabStruct &Data, const std::string &FieldName, const int InsertRow, const int InsertCol)
	{
		const char *fieldName = FieldName.c_str();
		if (mxGetFieldNumber(Destination, fieldName) == -1) return;

		int Ind = (InsertCol - 1)*this->Rows + InsertRow - 1;
		mxSetField(Destination, Ind, fieldName, Data.Destination);

		this->HighestStructure = true;
		Data.HighestStructure = false;
	}
	void MatlabStruct::Add(const std::string &Data, const std::string &FieldName, const int InsertRow, const int InsertCol)
	{
		const char *fieldName = FieldName.c_str();
		if (mxGetFieldNumber(Destination, fieldName) == -1) return;

		const char *V = Data.c_str();
		Source = mxCreateString(V);

		int Ind = (InsertCol - 1)*this->Rows + InsertRow - 1;
		mxSetField(Destination, Ind, fieldName, Source);
	}
	void MatlabStruct::Add(double Data, const std::string &FieldName, const int InsertRow, const int InsertCol)
	{
		const char *fieldName = FieldName.c_str();
		if (mxGetFieldNumber(Destination, fieldName) == -1) return;

		Source = mxCreateDoubleScalar(Data);
		memcpy((void *)(mxGetPr(Source)), (void *)&Data, sizeof(double));

		int Ind = (InsertCol - 1)*this->Rows + InsertRow - 1;
		mxSetField(Destination, Ind, fieldName, Source);
	}
	void MatlabStruct::Add(float Data, const std::string &FieldName, const int InsertRow, const int InsertCol)
	{
		const char *fieldName = FieldName.c_str();
		if (mxGetFieldNumber(Destination, fieldName) == -1) return;

		double value = static_cast<double>(Data);
		Source = mxCreateDoubleScalar(value);
		memcpy((void *)(mxGetPr(Source)), (void *)&value, sizeof(double));

		int Ind = (InsertCol - 1)*this->Rows + InsertRow - 1;
		mxSetField(Destination, Ind, fieldName, Source);
	}
	void MatlabStruct::Add(int Data, const std::string &FieldName, const int InsertRow, const int InsertCol)
	{
		const char *fieldName = FieldName.c_str();
		if (mxGetFieldNumber(Destination, fieldName) == -1) return;

		double value = static_cast<double>(Data);
		Source = mxCreateDoubleScalar(value);
		memcpy((void *)(mxGetPr(Source)), (void *)&value, sizeof(double));

		int Ind = (InsertCol - 1)*this->Rows + InsertRow - 1;
		mxSetField(Destination, Ind, fieldName, Source);
	}
	void MatlabStruct::Add(bool Data, const std::string &FieldName, const int InsertRow, const int InsertCol)
	{
		const char *fieldName = FieldName.c_str();
		if (mxGetFieldNumber(Destination, fieldName) == -1) return;

		Source = mxCreateLogicalScalar(Data);

		int Ind = (InsertCol - 1)*this->Rows + InsertRow - 1;
		mxSetField(Destination, Ind, fieldName, Source);
	}

	void MatlabStruct::Add(const std::vector<double> &Data, const std::string &FieldName, const int InsertRow, const int InsertCol)
	{
		this->ReshapeAdd(Data, 1, Data.size(), 1, FieldName, InsertRow, InsertCol);
	}
	void MatlabStruct::Add(const std::vector<float> &Data, const std::string &FieldName, const int InsertRow, const int InsertCol)
	{
		this->ReshapeAdd(Data, 1, Data.size(), 1, FieldName, InsertRow, InsertCol);
	}
	void MatlabStruct::Add(const std::vector<uint8_t> &Data, const std::string &FieldName, const int InsertRow, const int InsertCol)
	{
		this->ReshapeAdd(Data, 1, Data.size(), 1, FieldName, InsertRow, InsertCol);
	}
	void MatlabStruct::Add(const std::vector<uint16_t> &Data, const std::string &FieldName, const int InsertRow, const int InsertCol)
	{
		this->ReshapeAdd(Data, 1, Data.size(), 1, FieldName, InsertRow, InsertCol);
	}
	void MatlabStruct::Add(const std::vector<uint32_t> &Data, const std::string &FieldName, const int InsertRow, const int InsertCol)
	{
		this->ReshapeAdd(Data, 1, Data.size(), 1, FieldName, InsertRow, InsertCol);
	}
	void MatlabStruct::Add(const std::vector<uint64_t> &Data, const std::string &FieldName, const int InsertRow, const int InsertCol)
	{
		this->ReshapeAdd(Data, 1, Data.size(), 1, FieldName, InsertRow, InsertCol);
	}
	void MatlabStruct::Add(const std::vector<int8_t> &Data, const std::string &FieldName, const int InsertRow, const int InsertCol)
	{
		this->ReshapeAdd(Data, 1, Data.size(), 1, FieldName, InsertRow, InsertCol);
	}
	void MatlabStruct::Add(const std::vector<int16_t> &Data, const std::string &FieldName, const int InsertRow, const int InsertCol)
	{
		this->ReshapeAdd(Data, 1, Data.size(), 1, FieldName, InsertRow, InsertCol);
	}
	void MatlabStruct::Add(const std::vector<int> &Data, const std::string &FieldName, const int InsertRow, const int InsertCol)
	{
		this->ReshapeAdd(Data, 1, Data.size(), 1, FieldName, InsertRow, InsertCol);
	}
	void MatlabStruct::Add(const std::vector<int64_t> &Data, const std::string &FieldName, const int InsertRow, const int InsertCol)
	{
		this->ReshapeAdd(Data, 1, Data.size(), 1, FieldName, InsertRow, InsertCol);
	}

	void MatlabStruct::ReshapeAdd(const std::vector<double> &Data, const int Rows, const int Cols, const int Dim3, const std::string &FieldName, const int InsertRow, const int InsertCol)
	{
		const char *fieldName = FieldName.c_str();
		if (mxGetFieldNumber(Destination, fieldName) == -1) return;

		int Length = Rows * Cols*Dim3;

		const size_t Dim[3] = { Rows, Cols, Dim3 };

		Source = mxCreateNumericArray(3, Dim, mxDOUBLE_CLASS, mxREAL);

		memcpy((void *)(mxGetPr(Source)), (void *)Data.data(), sizeof(double)*Length);

		int Ind = (InsertCol - 1)*this->Rows + InsertRow - 1;
		mxSetField(Destination, Ind, fieldName, Source);
	}

	void MatlabStruct::ReshapeAdd(const std::vector<float> &Data, const int Rows, const int Cols, const int Dim3, const std::string &FieldName, const int InsertRow, const int InsertCol)
	{
		const char *fieldName = FieldName.c_str();
		if (mxGetFieldNumber(Destination, fieldName) == -1) return;

		int Length = Rows * Cols*Dim3;

		const size_t Dim[3] = { Rows, Cols, Dim3 };

		Source = mxCreateNumericArray(3, Dim, mxSINGLE_CLASS, mxREAL);

		memcpy((void *)(mxGetPr(Source)), (void *)Data.data(), sizeof(float)*Length);

		int Ind = (InsertCol - 1)*this->Rows + InsertRow - 1;
		mxSetField(Destination, Ind, fieldName, Source);
	}
	void MatlabStruct::ReshapeAdd(const std::vector<int8_t> &Data, const int Rows, const int Cols, const int Dim3, const std::string &FieldName, const int InsertRow, const int InsertCol)
	{
		const char *fieldName = FieldName.c_str();
		if (mxGetFieldNumber(Destination, fieldName) == -1) return;

		int Length = Rows * Cols*Dim3;

		const size_t Dim[3] = { Rows, Cols, Dim3 };

		Source = mxCreateNumericArray(3, Dim, mxINT8_CLASS, mxREAL);

		memcpy((void *)(mxGetPr(Source)), (void *)Data.data(), sizeof(int8_t)*Length);

		int Ind = (InsertCol - 1)*this->Rows + InsertRow - 1;
		mxSetField(Destination, Ind, fieldName, Source);
	}
	void MatlabStruct::ReshapeAdd(const std::vector<int16_t> &Data, const int Rows, const int Cols, const int Dim3, const std::string &FieldName, const int InsertRow, const int InsertCol)
	{
		const char *fieldName = FieldName.c_str();
		if (mxGetFieldNumber(Destination, fieldName) == -1) return;

		int Length = Rows * Cols*Dim3;

		const size_t Dim[3] = { Rows, Cols, Dim3 };

		Source = mxCreateNumericArray(3, Dim, mxINT16_CLASS, mxREAL);

		memcpy((void *)(mxGetPr(Source)), (void *)Data.data(), sizeof(int16_t)*Length);

		int Ind = (InsertCol - 1)*this->Rows + InsertRow - 1;
		mxSetField(Destination, Ind, fieldName, Source);
	}
	void MatlabStruct::ReshapeAdd(const std::vector<int32_t> &Data, const int Rows, const int Cols, const int Dim3, const std::string &FieldName, const int InsertRow, const int InsertCol)
	{
		const char *fieldName = FieldName.c_str();
		if (mxGetFieldNumber(Destination, fieldName) == -1) return;

		int Length = Rows * Cols*Dim3;

		const size_t Dim[3] = { Rows, Cols, Dim3 };

		Source = mxCreateNumericArray(3, Dim, mxINT32_CLASS, mxREAL);

		memcpy((void *)(mxGetPr(Source)), (void *)Data.data(), sizeof(int32_t)*Length);

		int Ind = (InsertCol - 1)*this->Rows + InsertRow - 1;
		mxSetField(Destination, Ind, fieldName, Source);
	}
	void MatlabStruct::ReshapeAdd(const std::vector<int64_t> &Data, const int Rows, const int Cols, const int Dim3, const std::string &FieldName, const int InsertRow, const int InsertCol)
	{
		const char *fieldName = FieldName.c_str();
		if (mxGetFieldNumber(Destination, fieldName) == -1) return;

		int Length = Rows * Cols*Dim3;

		const size_t Dim[3] = { Rows, Cols, Dim3 };

		Source = mxCreateNumericArray(3, Dim, mxINT64_CLASS, mxREAL);

		memcpy((void *)(mxGetPr(Source)), (void *)Data.data(), sizeof(int64_t)*Length);

		int Ind = (InsertCol - 1)*this->Rows + InsertRow - 1;
		mxSetField(Destination, Ind, fieldName, Source);
	}
	void MatlabStruct::ReshapeAdd(const std::vector<uint8_t> &Data, const int Rows, const int Cols, const int Dim3, const std::string &FieldName, const int InsertRow, const int InsertCol)
	{
		const char *fieldName = FieldName.c_str();
		if (mxGetFieldNumber(Destination, fieldName) == -1) return;

		int Length = Rows * Cols*Dim3;

		const size_t Dim[3] = { Rows, Cols, Dim3 };

		Source = mxCreateNumericArray(3, Dim, mxUINT8_CLASS, mxREAL);

		memcpy((void *)(mxGetPr(Source)), (void *)Data.data(), sizeof(uint8_t)*Length);

		int Ind = (InsertCol - 1)*this->Rows + InsertRow - 1;
		mxSetField(Destination, Ind, fieldName, Source);
	}
	void MatlabStruct::ReshapeAdd(const std::vector<uint16_t> &Data, const int Rows, const int Cols, const int Dim3, const std::string &FieldName, const int InsertRow, const int InsertCol)
	{
		const char *fieldName = FieldName.c_str();
		if (mxGetFieldNumber(Destination, fieldName) == -1) return;

		int Length = Rows * Cols*Dim3;

		const size_t Dim[3] = { Rows, Cols, Dim3 };

		Source = mxCreateNumericArray(3, Dim, mxUINT16_CLASS, mxREAL);

		memcpy((void *)(mxGetPr(Source)), (void *)Data.data(), sizeof(uint16_t)*Length);

		int Ind = (InsertCol - 1)*this->Rows + InsertRow - 1;
		mxSetField(Destination, Ind, fieldName, Source);
	}
	void MatlabStruct::ReshapeAdd(const std::vector<uint32_t> &Data, const int Rows, const int Cols, const int Dim3, const std::string &FieldName, const int InsertRow, const int InsertCol)
	{
		const char *fieldName = FieldName.c_str();
		if (mxGetFieldNumber(Destination, fieldName) == -1) return;

		int Length = Rows * Cols*Dim3;

		const size_t Dim[3] = { Rows, Cols, Dim3 };

		Source = mxCreateNumericArray(3, Dim, mxUINT32_CLASS, mxREAL);

		memcpy((void *)(mxGetPr(Source)), (void *)Data.data(), sizeof(uint32_t)*Length);

		int Ind = (InsertCol - 1)*this->Rows + InsertRow - 1;
		mxSetField(Destination, Ind, fieldName, Source);
	}
	void MatlabStruct::ReshapeAdd(const std::vector<uint64_t> &Data, const int Rows, const int Cols, const int Dim3, const std::string &FieldName, const int InsertRow, const int InsertCol)
	{
		const char *fieldName = FieldName.c_str();
		if (mxGetFieldNumber(Destination, fieldName) == -1) return;

		int Length = Rows * Cols*Dim3;

		const size_t Dim[3] = { Rows, Cols, Dim3 };

		Source = mxCreateNumericArray(3, Dim, mxUINT64_CLASS, mxREAL);

		memcpy((void *)(mxGetPr(Source)), (void *)Data.data(), sizeof(uint64_t)*Length);

		int Ind = (InsertCol - 1)*this->Rows + InsertRow - 1;
		mxSetField(Destination, Ind, fieldName, Source);
	}
	void MatlabStruct::ReshapeAdd(const double *Data, const int Rows, const int Cols, const int Dim3, const std::string &FieldName, int InsertRow, int InsertCol)
	{
		const char *fieldName = FieldName.c_str();
		if (mxGetFieldNumber(Destination, fieldName) == -1) return;

		int Length = Rows * Cols*Dim3;

		const size_t Dim[3] = { Rows, Cols, Dim3 };

		Source = mxCreateNumericArray(3, Dim, mxDOUBLE_CLASS, mxREAL);

		memcpy((void *)(mxGetPr(Source)), (void *)Data, sizeof(double)*Length);

		int Ind = (InsertCol - 1)*this->Rows + InsertRow - 1;
		mxSetField(Destination, Ind, fieldName, Source);
	}
	void MatlabStruct::ReshapeAdd(const float *Data, const int Rows, const int Cols, const int Dim3, const std::string &FieldName, int InsertRow, int InsertCol)
	{
		const char *fieldName = FieldName.c_str();
		if (mxGetFieldNumber(Destination, fieldName) == -1) return;

		int Length = Rows * Cols*Dim3;

		const size_t Dim[3] = { Rows, Cols, Dim3 };

		Source = mxCreateNumericArray(3, Dim, mxSINGLE_CLASS, mxREAL);

		memcpy((void *)(mxGetPr(Source)), (void *)Data, sizeof(float)*Length);

		int Ind = (InsertCol - 1) * this->Rows + InsertRow - 1;
		mxSetField(Destination, Ind, fieldName, Source);
	}
	void MatlabStruct::ReshapeAdd(const uint8_t *Data, const int Rows, const int Cols, const int Dim3, const std::string &FieldName, int InsertRow, int InsertCol)
	{
		const char *fieldName = FieldName.c_str();
		if (mxGetFieldNumber(Destination, fieldName) == -1) return;

		int Length = Rows * Cols*Dim3;

		const size_t Dim[3] = { Rows, Cols, Dim3 };

		Source = mxCreateNumericArray(3, Dim, mxUINT8_CLASS, mxREAL);

		memcpy((void *)(mxGetPr(Source)), (void *)Data, sizeof(uint8_t)*Length);

		int Ind = (InsertCol - 1)*this->Rows + InsertRow - 1;
		mxSetField(Destination, Ind, fieldName, Source);
	}
	void MatlabStruct::ReshapeAdd(const uint16_t *Data, const int Rows, const int Cols, const int Dim3, const std::string &FieldName, int InsertRow, int InsertCol)
	{
		const char *fieldName = FieldName.c_str();
		if (mxGetFieldNumber(Destination, fieldName) == -1) return;

		int Length = Rows * Cols*Dim3;

		const size_t Dim[3] = { Rows, Cols, Dim3 };

		Source = mxCreateNumericArray(3, Dim, mxUINT16_CLASS, mxREAL);

		memcpy((void *)(mxGetPr(Source)), (void *)Data, sizeof(uint16_t)*Length);

		int Ind = (InsertCol - 1) * this->Rows + InsertRow - 1;
		mxSetField(Destination, Ind, fieldName, Source);
	}
}

