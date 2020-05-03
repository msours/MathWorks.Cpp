
#include "MatlabStruct.h"
#include <vector>

namespace mMatfile 
{
	MatlabStruct::MatlabStruct(int Rows, int Cols, int nFields, array<String^>^ FieldNames)
	{
		this->FieldNames = FieldNames;
		this->Rows = Rows;
		this->Cols = Cols;
		this->nFields = nFields;

		char **names = new char*[FieldNames->Length];

		for (int k = 0; k < FieldNames->Length; k++)
		{
			names[k] = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(FieldNames[k]);
		}

		Destination = mxCreateStructMatrix(Rows, Cols, nFields, const_cast<const char**> (names));

		for (int k = 0; k < FieldNames->Length; k++)
		{
			System::Runtime::InteropServices::Marshal::FreeHGlobal(System::IntPtr((void*)names[k]));
		}
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
	void MatlabStruct::Add(CellArray^ Data, String^ FieldName, int InsertRow, int InsertCol)
	{
		const char *fieldName = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(FieldName);
		if (mxGetFieldNumber(Destination, fieldName) == -1) { System::Runtime::InteropServices::Marshal::FreeHGlobal(System::IntPtr((void*)fieldName)); return; }

		int Ind = (InsertCol - 1)*this->Rows + InsertRow - 1;
		mxSetField(Destination, Ind, fieldName, Data->Destination);

		this->HighestStructure = true;
		Data->HighestStructure = false;

		System::Runtime::InteropServices::Marshal::FreeHGlobal(System::IntPtr((void*)fieldName));
	}
	void MatlabStruct::Add(MatlabStruct^ Data, String^ FieldName, int InsertRow, int InsertCol)
	{
		const char *fieldName = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(FieldName);
		if (mxGetFieldNumber(Destination, fieldName) == -1) { System::Runtime::InteropServices::Marshal::FreeHGlobal(System::IntPtr((void*)fieldName)); return; }

		int Ind = (InsertCol - 1)*this->Rows + InsertRow - 1;
		mxSetField(Destination, Ind, fieldName, Data->Destination);

		this->HighestStructure = true;
		Data->HighestStructure = false;

		System::Runtime::InteropServices::Marshal::FreeHGlobal(System::IntPtr((void*)fieldName));
	}
	void MatlabStruct::Add(String^ Data, String^ FieldName, int InsertRow, int InsertCol)
	{
		const char *fieldName = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(FieldName);
		if (mxGetFieldNumber(Destination, fieldName) == -1) { System::Runtime::InteropServices::Marshal::FreeHGlobal(System::IntPtr((void*)fieldName)); return; }

		char *V = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(Data);
		Source = mxCreateString(V);

		int Ind = (InsertCol - 1)*this->Rows + InsertRow - 1;
		mxSetField(Destination, Ind, fieldName, Source);

		System::Runtime::InteropServices::Marshal::FreeHGlobal(System::IntPtr((void*)V));
		System::Runtime::InteropServices::Marshal::FreeHGlobal(System::IntPtr((void*)fieldName));
	}
	void MatlabStruct::Add(double Data, String^ FieldName, int InsertRow, int InsertCol)
	{
		const char *fieldName = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(FieldName);
		if (mxGetFieldNumber(Destination, fieldName) == -1) { System::Runtime::InteropServices::Marshal::FreeHGlobal(System::IntPtr((void*)fieldName)); return; }

		Source = mxCreateDoubleScalar(Data);
		memcpy((void *)(mxGetPr(Source)), (void *)&Data, sizeof(double));

		int Ind = (InsertCol - 1)*this->Rows + InsertRow - 1;
		mxSetField(Destination, Ind, fieldName, Source);
		System::Runtime::InteropServices::Marshal::FreeHGlobal(System::IntPtr((void*)fieldName));
	}
	void MatlabStruct::Add(array<double>^ Data, int Rows, int Cols, String^ FieldName, int InsertRow, int InsertCol)
	{
		const char *fieldName = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(FieldName);
		if (mxGetFieldNumber(Destination, fieldName) == -1) { System::Runtime::InteropServices::Marshal::FreeHGlobal(System::IntPtr((void*)fieldName)); return; }

		int Length = Rows * Cols;

		Source = mxCreateDoubleMatrix(Rows, Cols, mxREAL);

		std::vector<double> data;

		double V;
		for (int k = 0; k < Length; k++)
		{
			V = Data[k];
			data.push_back(V);
		}

		memcpy((void *)(mxGetPr(Source)), (void *)data.data(), sizeof(double)*Length);

		int Ind = (InsertCol - 1)*this->Rows + InsertRow - 1;
		mxSetField(Destination, Ind, fieldName, Source);
		System::Runtime::InteropServices::Marshal::FreeHGlobal(System::IntPtr((void*)fieldName));
	}
	void MatlabStruct::Add(array<double>^ Data, int Rows, int Cols, int Dim3, String^ FieldName, int InsertRow, int InsertCol)
	{
		const char *fieldName = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(FieldName);
		if (mxGetFieldNumber(Destination, fieldName) == -1) { System::Runtime::InteropServices::Marshal::FreeHGlobal(System::IntPtr((void*)fieldName)); return; }

		int Length = Rows * Cols*Dim3;

		size_t Dim[3];
		Dim[0] = Rows;
		Dim[1] = Cols;
		Dim[2] = Dim3;

		Source = mxCreateNumericArray(3, Dim, mxDOUBLE_CLASS, mxREAL);

		std::vector<double> data;

		double V;
		for (int k = 0; k < Length; k++)
		{
			V = Data[k];
			data.push_back(V);
		}

		memcpy((void *)(mxGetPr(Source)), (void *)data.data(), sizeof(double)*Length);

		int Ind = (InsertCol - 1)*this->Rows + InsertRow - 1;
		mxSetField(Destination, Ind, fieldName, Source);
	}
	void MatlabStruct::Add(float Data, String^ FieldName, int InsertRow, int InsertCol)
	{
		const char *fieldName = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(FieldName);
		if (mxGetFieldNumber(Destination, fieldName) == -1) { System::Runtime::InteropServices::Marshal::FreeHGlobal(System::IntPtr((void*)fieldName)); return; }

		double value = static_cast<double>(Data);
		Source = mxCreateDoubleScalar(value);
		memcpy((void *)(mxGetPr(Source)), (void *)&value, sizeof(double));

		int Ind = (InsertCol - 1)*this->Rows + InsertRow - 1;
		mxSetField(Destination, Ind, fieldName, Source);
		System::Runtime::InteropServices::Marshal::FreeHGlobal(System::IntPtr((void*)fieldName));
	}
	void MatlabStruct::Add(int Data, String^ FieldName, int InsertRow, int InsertCol)
	{
		const char *fieldName = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(FieldName);
		if (mxGetFieldNumber(Destination, fieldName) == -1) { System::Runtime::InteropServices::Marshal::FreeHGlobal(System::IntPtr((void*)fieldName)); return; }

		double value = static_cast<double>(Data);
		Source = mxCreateDoubleScalar(value);
		memcpy((void *)(mxGetPr(Source)), (void *)&value, sizeof(double));

		int Ind = (InsertCol - 1)*this->Rows + InsertRow - 1;
		mxSetField(Destination, Ind, fieldName, Source);
		System::Runtime::InteropServices::Marshal::FreeHGlobal(System::IntPtr((void*)fieldName));
	}
	void MatlabStruct::Add(bool Data, String^ FieldName, int InsertRow, int InsertCol)
	{
		const char *fieldName = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(FieldName);
		if (mxGetFieldNumber(Destination, fieldName) == -1) { System::Runtime::InteropServices::Marshal::FreeHGlobal(System::IntPtr((void*)fieldName)); return; }

		Source = mxCreateLogicalScalar(Data);

		int Ind = (InsertCol - 1)*this->Rows + InsertRow - 1;
		mxSetField(Destination, Ind, fieldName, Source);
		System::Runtime::InteropServices::Marshal::FreeHGlobal(System::IntPtr((void*)fieldName));
	}
	void MatlabStruct::Add(array<float>^ Data, int Rows, int Cols, int Dim3, String^ FieldName, int InsertRow, int InsertCol)
	{
		const char *fieldName = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(FieldName);
		if (mxGetFieldNumber(Destination, fieldName) == -1) { System::Runtime::InteropServices::Marshal::FreeHGlobal(System::IntPtr((void*)fieldName)); return; }

		int Length = Rows * Cols*Dim3;

		size_t Dim[3];
		Dim[0] = Rows;
		Dim[1] = Cols;
		Dim[2] = Dim3;

		Source = mxCreateNumericArray(3, Dim, mxSINGLE_CLASS, mxREAL);

		std::vector<float> data;

		float V;
		for (int k = 0; k < Length; k++)
		{
			V = Data[k];
			data.push_back(V);
		}

		memcpy((void *)(mxGetPr(Source)), (void *)data.data(), sizeof(float)*Length);

		int Ind = (InsertCol - 1)*this->Rows + InsertRow - 1;
		mxSetField(Destination, Ind, fieldName, Source);
		System::Runtime::InteropServices::Marshal::FreeHGlobal(System::IntPtr((void*)fieldName));
	}
	void MatlabStruct::Add(array<INT8>^ Data, int Rows, int Cols, int Dim3, String^ FieldName, int InsertRow, int InsertCol)
	{
		const char *fieldName = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(FieldName);
		if (mxGetFieldNumber(Destination, fieldName) == -1) { System::Runtime::InteropServices::Marshal::FreeHGlobal(System::IntPtr((void*)fieldName)); return; }

		int Length = Rows * Cols*Dim3;

		size_t Dim[3];
		Dim[0] = Rows;
		Dim[1] = Cols;
		Dim[2] = Dim3;

		Source = mxCreateNumericArray(3, Dim, mxINT8_CLASS, mxREAL);

		std::vector<INT8> data;

		INT8 V;
		for (int k = 0; k < Length; k++)
		{
			V = Data[k];
			data.push_back(V);
		}

		memcpy((void *)(mxGetPr(Source)), (void *)data.data(), sizeof(INT8)*Length);

		int Ind = (InsertCol - 1)*this->Rows + InsertRow - 1;
		mxSetField(Destination, Ind, fieldName, Source);
		System::Runtime::InteropServices::Marshal::FreeHGlobal(System::IntPtr((void*)fieldName));
	}
	void MatlabStruct::Add(array<INT16>^ Data, int Rows, int Cols, int Dim3, String^ FieldName, int InsertRow, int InsertCol)
	{
		const char *fieldName = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(FieldName);
		if (mxGetFieldNumber(Destination, fieldName) == -1) { System::Runtime::InteropServices::Marshal::FreeHGlobal(System::IntPtr((void*)fieldName)); return; }

		int Length = Rows * Cols*Dim3;

		size_t Dim[3];
		Dim[0] = Rows;
		Dim[1] = Cols;
		Dim[2] = Dim3;

		Source = mxCreateNumericArray(3, Dim, mxINT16_CLASS, mxREAL);

		std::vector<INT16> data;

		INT16 V;
		for (int k = 0; k < Length; k++)
		{
			V = Data[k];
			data.push_back(V);
		}

		memcpy((void *)(mxGetPr(Source)), (void *)data.data(), sizeof(INT16)*Length);

		int Ind = (InsertCol - 1)*this->Rows + InsertRow - 1;
		mxSetField(Destination, Ind, fieldName, Source);
		System::Runtime::InteropServices::Marshal::FreeHGlobal(System::IntPtr((void*)fieldName));
	}
	void MatlabStruct::Add(array<INT32>^ Data, int Rows, int Cols, int Dim3, String^ FieldName, int InsertRow, int InsertCol)
	{
		const char *fieldName = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(FieldName);
		if (mxGetFieldNumber(Destination, fieldName) == -1) { System::Runtime::InteropServices::Marshal::FreeHGlobal(System::IntPtr((void*)fieldName)); return; }

		int Length = Rows * Cols*Dim3;

		size_t Dim[3];
		Dim[0] = Rows;
		Dim[1] = Cols;
		Dim[2] = Dim3;

		Source = mxCreateNumericArray(3, Dim, mxINT32_CLASS, mxREAL);

		std::vector<INT32> data;

		INT32 V;
		for (int k = 0; k < Length; k++)
		{
			V = Data[k];
			data.push_back(V);
		}

		memcpy((void *)(mxGetPr(Source)), (void *)data.data(), sizeof(INT32)*Length);

		int Ind = (InsertCol - 1)*this->Rows + InsertRow - 1;
		mxSetField(Destination, Ind, fieldName, Source);
		System::Runtime::InteropServices::Marshal::FreeHGlobal(System::IntPtr((void*)fieldName));
	}
	void MatlabStruct::Add(array<INT64>^ Data, int Rows, int Cols, int Dim3, String^ FieldName, int InsertRow, int InsertCol)
	{
		const char *fieldName = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(FieldName);
		if (mxGetFieldNumber(Destination, fieldName) == -1) { System::Runtime::InteropServices::Marshal::FreeHGlobal(System::IntPtr((void*)fieldName)); return; }

		int Length = Rows * Cols*Dim3;

		size_t Dim[3];
		Dim[0] = Rows;
		Dim[1] = Cols;
		Dim[2] = Dim3;

		Source = mxCreateNumericArray(3, Dim, mxINT64_CLASS, mxREAL);

		std::vector<INT64> data;

		INT64 V;
		for (int k = 0; k < Length; k++)
		{
			V = Data[k];
			data.push_back(V);
		}

		memcpy((void *)(mxGetPr(Source)), (void *)data.data(), sizeof(INT64)*Length);

		int Ind = (InsertCol - 1)*this->Rows + InsertRow - 1;
		mxSetField(Destination, Ind, fieldName, Source);
		System::Runtime::InteropServices::Marshal::FreeHGlobal(System::IntPtr((void*)fieldName));
	}
	void MatlabStruct::Add(array<UINT8>^ Data, int Rows, int Cols, int Dim3, String^ FieldName, int InsertRow, int InsertCol)
	{
		const char *fieldName = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(FieldName);
		if (mxGetFieldNumber(Destination, fieldName) == -1) { System::Runtime::InteropServices::Marshal::FreeHGlobal(System::IntPtr((void*)fieldName)); return; }

		int Length = Rows * Cols*Dim3;

		size_t Dim[3];
		Dim[0] = Rows;
		Dim[1] = Cols;
		Dim[2] = Dim3;

		Source = mxCreateNumericArray(3, Dim, mxUINT8_CLASS, mxREAL);

		std::vector<UINT8> data;

		UINT8 V;
		for (int k = 0; k < Length; k++)
		{
			V = Data[k];
			data.push_back(V);
		}

		memcpy((void *)(mxGetPr(Source)), (void *)data.data(), sizeof(UINT8)*Length);

		int Ind = (InsertCol - 1)*this->Rows + InsertRow - 1;
		mxSetField(Destination, Ind, fieldName, Source);
		System::Runtime::InteropServices::Marshal::FreeHGlobal(System::IntPtr((void*)fieldName));
	}
	void MatlabStruct::Add(array<UINT16>^ Data, int Rows, int Cols, int Dim3, String^ FieldName, int InsertRow, int InsertCol)
	{
		const char *fieldName = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(FieldName);
		if (mxGetFieldNumber(Destination, fieldName) == -1) { System::Runtime::InteropServices::Marshal::FreeHGlobal(System::IntPtr((void*)fieldName)); return; }

		int Length = Rows * Cols*Dim3;

		size_t Dim[3];
		Dim[0] = Rows;
		Dim[1] = Cols;
		Dim[2] = Dim3;

		Source = mxCreateNumericArray(3, Dim, mxUINT16_CLASS, mxREAL);

		std::vector<UINT16> data;

		UINT16 V;
		for (int k = 0; k < Length; k++)
		{
			V = Data[k];
			data.push_back(V);
		}

		memcpy((void *)(mxGetPr(Source)), (void *)data.data(), sizeof(UINT16)*Length);

		int Ind = (InsertCol - 1)*this->Rows + InsertRow - 1;
		mxSetField(Destination, Ind, fieldName, Source);
		System::Runtime::InteropServices::Marshal::FreeHGlobal(System::IntPtr((void*)fieldName));
	}
	void MatlabStruct::Add(array<UINT32>^ Data, int Rows, int Cols, int Dim3, String^ FieldName, int InsertRow, int InsertCol)
	{
		const char *fieldName = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(FieldName);
		if (mxGetFieldNumber(Destination, fieldName) == -1) { System::Runtime::InteropServices::Marshal::FreeHGlobal(System::IntPtr((void*)fieldName)); return; }

		int Length = Rows * Cols*Dim3;

		size_t Dim[3];
		Dim[0] = Rows;
		Dim[1] = Cols;
		Dim[2] = Dim3;

		Source = mxCreateNumericArray(3, Dim, mxUINT32_CLASS, mxREAL);

		std::vector<UINT32> data;

		UINT32 V;
		for (int k = 0; k < Length; k++)
		{
			V = Data[k];
			data.push_back(V);
		}

		memcpy((void *)(mxGetPr(Source)), (void *)data.data(), sizeof(UINT32)*Length);

		int Ind = (InsertCol - 1)*this->Rows + InsertRow - 1;
		mxSetField(Destination, Ind, fieldName, Source);
		System::Runtime::InteropServices::Marshal::FreeHGlobal(System::IntPtr((void*)fieldName));
	}
	void MatlabStruct::Add(array<UINT64>^ Data, int Rows, int Cols, int Dim3, String^ FieldName, int InsertRow, int InsertCol)
	{
		const char *fieldName = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(FieldName);
		if (mxGetFieldNumber(Destination, fieldName) == -1) { System::Runtime::InteropServices::Marshal::FreeHGlobal(System::IntPtr((void*)fieldName)); return; }

		int Length = Rows * Cols*Dim3;

		size_t Dim[3];
		Dim[0] = Rows;
		Dim[1] = Cols;
		Dim[2] = Dim3;

		Source = mxCreateNumericArray(3, Dim, mxUINT64_CLASS, mxREAL);

		std::vector<UINT64> data;

		UINT64 V;
		for (int k = 0; k < Length; k++)
		{
			V = Data[k];
			data.push_back(V);
		}

		memcpy((void *)(mxGetPr(Source)), (void *)data.data(), sizeof(UINT64)*Length);

		int Ind = (InsertCol - 1)*this->Rows + InsertRow - 1;
		mxSetField(Destination, Ind, fieldName, Source);
		System::Runtime::InteropServices::Marshal::FreeHGlobal(System::IntPtr((void*)fieldName));
	}
}



