
#include "Matfile.h"
#include <vector>

namespace mMatfile 
{
	Matfile::Matfile(String^ FilePath, String^ FileMode)
	{
		filePath = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(FilePath);
		fileMode = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(FileMode);
	}
	Matfile::~Matfile()
	{
		System::Runtime::InteropServices::Marshal::FreeHGlobal(System::IntPtr((void*)filePath));
		System::Runtime::InteropServices::Marshal::FreeHGlobal(System::IntPtr((void*)fileMode));
	}
	bool Matfile::Open()
	{
		Destination = matOpen(filePath, fileMode);

		return (!Destination == NULL);
	}
	bool Matfile::Close()
	{
		return (matClose(Destination) == 0);
	}
	void Matfile::Add(String^ Name, MatlabStruct^ Data)
	{
		const char *name = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(Name);
		matPutVariable(Destination, name, Data->Destination);

		System::Runtime::InteropServices::Marshal::FreeHGlobal(System::IntPtr((void*)name));
	}
	void Matfile::Add(String^ Name, CellArray^ Data)
	{
		const char *name = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(Name);
		matPutVariable(Destination, name, Data->Destination);

		System::Runtime::InteropServices::Marshal::FreeHGlobal(System::IntPtr((void*)name));
	}
	void Matfile::Add(String^ Name, array<double>^ Data, int Rows, int Cols, int Dim3)
	{
		int Length = Rows * Cols*Dim3;
		const char* name = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(Name);

		size_t Dim[3];
		Dim[0] = Rows;
		Dim[1] = Cols;
		Dim[2] = Dim3;

		mxArray *source = mxCreateNumericArray(3, Dim, mxDOUBLE_CLASS, mxREAL);

		std::vector<double> data;

		double V;
		for (int k = 0; k < Length; k++)
		{
			V = Data[k];
			data.push_back(V);
		}

		memcpy((void *)(mxGetPr(source)), (void *)data.data(), sizeof(double)*Length);
		matPutVariable(Destination, name, source);
		mxDestroyArray(source);

		System::Runtime::InteropServices::Marshal::FreeHGlobal(System::IntPtr((void*)name));
	}
	void Matfile::Add(String^ Name, array<float>^ Data, int Rows, int Cols, int Dim3)
	{
		int Length = Rows * Cols*Dim3;
		const char *name = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(Name);

		size_t Dim[3];
		Dim[0] = Rows;
		Dim[1] = Cols;
		Dim[2] = Dim3;

		mxArray *source = mxCreateNumericArray(3, Dim, mxSINGLE_CLASS, mxREAL);

		std::vector<float> data;

		float V;
		for (int k = 0; k < Length; k++)
		{
			V = Data[k];
			data.push_back(V);
		}

		memcpy((void *)(mxGetPr(source)), (void *)data.data(), sizeof(float)*Length);
		matPutVariable(Destination, name, source);
		mxDestroyArray(source);
		System::Runtime::InteropServices::Marshal::FreeHGlobal(System::IntPtr((void*)name));
	}
	void Matfile::Add(String^ Name, array<INT8>^ Data, int Rows, int Cols, int Dim3)
	{
		int Length = Rows * Cols*Dim3;
		const char *name = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(Name);

		size_t Dim[3];
		Dim[0] = Rows;
		Dim[1] = Cols;
		Dim[2] = Dim3;

		mxArray *source = mxCreateNumericArray(3, Dim, mxINT8_CLASS, mxREAL);

		std::vector<INT8> data;
		INT8 V;

		for (int k = 0; k < Length; k++)
		{
			V = Data[k];
			data.push_back(V);
		}

		memcpy((void *)(mxGetPr(source)), (void *)data.data(), sizeof(INT8)*Length);
		matPutVariable(Destination, name, source);
		mxDestroyArray(source);

		System::Runtime::InteropServices::Marshal::FreeHGlobal(System::IntPtr((void*)name));
	}
	void Matfile::Add(String^ Name, array<INT16>^ Data, int Rows, int Cols, int Dim3)
	{
		int Length = Rows * Cols*Dim3;
		const char *name = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(Name);

		size_t Dim[3];
		Dim[0] = Rows;
		Dim[1] = Cols;
		Dim[2] = Dim3;

		mxArray *source = mxCreateNumericArray(3, Dim, mxINT16_CLASS, mxREAL);

		std::vector<INT16> data;
		INT16 V;

		for (int k = 0; k < Length; k++)
		{
			V = Data[k];
			data.push_back(V);
		}

		memcpy((void *)(mxGetPr(source)), (void *)data.data(), sizeof(INT16)*Length);
		matPutVariable(Destination, name, source);
		mxDestroyArray(source);

		System::Runtime::InteropServices::Marshal::FreeHGlobal(System::IntPtr((void*)name));
	}
	void Matfile::Add(String^ Name, array<INT32>^ Data, int Rows, int Cols, int Dim3)
	{
		int Length = Rows * Cols*Dim3;
		const char *name = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(Name);

		size_t Dim[3];
		Dim[0] = Rows;
		Dim[1] = Cols;
		Dim[2] = Dim3;

		mxArray *source = mxCreateNumericArray(3, Dim, mxINT32_CLASS, mxREAL);

		std::vector<INT32> data;
		INT32 V;

		for (int k = 0; k < Length; k++)
		{
			V = Data[k];
			data.push_back(V);
		}

		memcpy((void *)(mxGetPr(source)), (void *)data.data(), sizeof(INT32)*Length);
		matPutVariable(Destination, name, source);
		mxDestroyArray(source);

		System::Runtime::InteropServices::Marshal::FreeHGlobal(System::IntPtr((void*)name));
	}
	void Matfile::Add(String^ Name, array<INT64>^ Data, int Rows, int Cols, int Dim3)
	{
		int Length = Rows * Cols*Dim3;
		const char *name = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(Name);

		size_t Dim[3];
		Dim[0] = Rows;
		Dim[1] = Cols;
		Dim[2] = Dim3;

		mxArray *source = mxCreateNumericArray(3, Dim, mxINT64_CLASS, mxREAL);

		std::vector<INT64> data;
		INT64 V;

		for (int k = 0; k < Length; k++)
		{
			V = Data[k];
			data.push_back(V);
		}

		memcpy((void *)(mxGetPr(source)), (void *)data.data(), sizeof(INT64)*Length);
		matPutVariable(Destination, name, source);
		mxDestroyArray(source);

		System::Runtime::InteropServices::Marshal::FreeHGlobal(System::IntPtr((void*)name));
	}
	void Matfile::Add(String^ Name, array<UINT8>^ Data, int Rows, int Cols, int Dim3)
	{
		int Length = Rows * Cols*Dim3;
		const char *name = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(Name);

		size_t Dim[3];
		Dim[0] = Rows;
		Dim[1] = Cols;
		Dim[2] = Dim3;

		mxArray *source = mxCreateNumericArray(3, Dim, mxUINT8_CLASS, mxREAL);

		std::vector<UINT8> data;
		UINT8 V;

		for (int k = 0; k < Length; k++)
		{
			V = Data[k];
			data.push_back(V);
		}

		memcpy((void *)(mxGetPr(source)), (void *)data.data(), sizeof(UINT8)*Length);
		matPutVariable(Destination, name, source);
		mxDestroyArray(source);

		System::Runtime::InteropServices::Marshal::FreeHGlobal(System::IntPtr((void*)name));
	}
	void Matfile::Add(String^ Name, array<UINT16>^ Data, int Rows, int Cols, int Dim3)
	{
		int Length = Rows * Cols*Dim3;
		const char *name = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(Name);

		size_t Dim[3];
		Dim[0] = Rows;
		Dim[1] = Cols;
		Dim[2] = Dim3;

		mxArray *source = mxCreateNumericArray(3, Dim, mxUINT16_CLASS, mxREAL);

		std::vector<UINT16> data;
		UINT16 V;

		for (int k = 0; k < Length; k++)
		{
			V = Data[k];
			data.push_back(V);
		}

		memcpy((void *)(mxGetPr(source)), (void *)data.data(), sizeof(UINT16)*Length);
		matPutVariable(Destination, name, source);

		mxDestroyArray(source);
		System::Runtime::InteropServices::Marshal::FreeHGlobal(System::IntPtr((void*)name));
	}
	void Matfile::Add(String^ Name, array<UINT32>^ Data, int Rows, int Cols, int Dim3)
	{
		int Length = Rows * Cols*Dim3;
		const char *name = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(Name);

		size_t Dim[3];
		Dim[0] = Rows;
		Dim[1] = Cols;
		Dim[2] = Dim3;

		mxArray *source = mxCreateNumericArray(3, Dim, mxUINT32_CLASS, mxREAL);

		std::vector<UINT32> data;
		UINT8 V;

		for (int k = 0; k < Length; k++)
		{
			V = Data[k];
			data.push_back(V);
		}

		memcpy((void *)(mxGetPr(source)), (void *)data.data(), sizeof(UINT32)*Length);
		matPutVariable(Destination, name, source);
		mxDestroyArray(source);

		System::Runtime::InteropServices::Marshal::FreeHGlobal(System::IntPtr((void*)name));
	}
	void Matfile::Add(String^ Name, array<UINT64>^ Data, int Rows, int Cols, int Dim3)
	{
		int Length = Rows * Cols*Dim3;
		const char *name = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(Name);

		size_t Dim[3];
		Dim[0] = Rows;
		Dim[1] = Cols;
		Dim[2] = Dim3;

		mxArray *source = mxCreateNumericArray(3, Dim, mxUINT64_CLASS, mxREAL);

		std::vector<UINT64> data;
		UINT64 V;

		for (int k = 0; k < Length; k++)
		{
			V = Data[k];
			data.push_back(V);
		}

		memcpy((void *)(mxGetPr(source)), (void *)data.data(), sizeof(UINT64)*Length);
		matPutVariable(Destination, name, source);
		mxDestroyArray(source);

		System::Runtime::InteropServices::Marshal::FreeHGlobal(System::IntPtr((void*)name));
	}
	void Matfile::Add(String^ Name, array<float>^ Data, int Rows, int Cols)
	{
		int Length = Rows * Cols;
		const char *name = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(Name);

		mxArray *source = mxCreateDoubleMatrix(Rows, Cols, mxREAL);

		std::vector<double> data;

		double V;
		for (int k = 0; k < Length; k++)
		{
			V = static_cast<double>(Data[k]);
			data.push_back(V);
		}

		memcpy((void *)(mxGetPr(source)), (void *)data.data(), sizeof(double)*Length);
		matPutVariable(Destination, name, source);
		mxDestroyArray(source);

		System::Runtime::InteropServices::Marshal::FreeHGlobal(System::IntPtr((void*)name));
	}
	void Matfile::Add(String^ Name, array<double>^ Data, int Rows, int Cols)
	{
		int Length = Rows * Cols;
		const char *name = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(Name);

		mxArray *source = mxCreateDoubleMatrix(Rows, Cols, mxREAL);

		std::vector<double> data;

		double V;
		for (int k = 0; k < Length; k++)
		{
			V = Data[k];
			data.push_back(V);
		}

		memcpy((void *)(mxGetPr(source)), (void *)data.data(), sizeof(double)*Length);
		matPutVariable(Destination, name, source);
		mxDestroyArray(source);

		System::Runtime::InteropServices::Marshal::FreeHGlobal(System::IntPtr((void*)name));
	}
	void Matfile::Add(String^ Name, double Data)
	{
		const char *name = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(Name);

		mxArray *source = mxCreateDoubleScalar(Data);

		memcpy((void *)(mxGetPr(source)), (void *)&Data, sizeof(double));
		matPutVariable(Destination, name, source);
		mxDestroyArray(source);

		System::Runtime::InteropServices::Marshal::FreeHGlobal(System::IntPtr((void*)name));
	}
	void Matfile::Add(String^ Name, float Data)
	{
		const char *name = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(Name);

		double value = static_cast<double>(Data);
		mxArray *source = mxCreateDoubleScalar(value);

		memcpy((void *)(mxGetPr(source)), (void *)&value, sizeof(double));
		matPutVariable(Destination, name, source);
		mxDestroyArray(source);

		System::Runtime::InteropServices::Marshal::FreeHGlobal(System::IntPtr((void*)name));
	}
	void Matfile::Add(String^ Name, int Data)
	{
		const char *name = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(Name);

		double value = static_cast<double>(Data);
		mxArray *source = mxCreateDoubleScalar(value);

		memcpy((void *)(mxGetPr(source)), (void *)&value, sizeof(double));
		matPutVariable(Destination, name, source);
		mxDestroyArray(source);

		System::Runtime::InteropServices::Marshal::FreeHGlobal(System::IntPtr((void*)name));
	}
	void Matfile::Add(String^ Name, bool Data)
	{
		const char *name = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(Name);

		mxArray *source = mxCreateLogicalScalar(Data);

		matPutVariable(Destination, name, source);
		mxDestroyArray(source);

		System::Runtime::InteropServices::Marshal::FreeHGlobal(System::IntPtr((void*)name));
	}
	void Matfile::Add(String^ Name, String^ Data)
	{
		const char *name = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(Name);

		char *V = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(Data);

		mxArray *source = mxCreateString(V);

		matPutVariable(Destination, name, source);
		mxDestroyArray(source);

		System::Runtime::InteropServices::Marshal::FreeHGlobal(System::IntPtr((void*)name));
	}
}