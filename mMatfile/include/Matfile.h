#pragma once

#include "MatlabStruct.h"
#include <iostream>

using namespace System;

namespace mMatfile 
{
	public ref class Matfile
	{
	private:
		const char *filePath;
		const char *fileMode;

		MATFile *Destination = NULL;
	public:
		Matfile(String^ FilePath, String^ FileMode);
		~Matfile();
		bool Open();
		bool Close();
		void Add(String^ Name, MatlabStruct^ Data);
		void Add(String^ Name, CellArray^ Data);
		void Add(String^ Name, array<double>^ Data, int Rows, int Cols, int Dim3);
		void Add(String^ Name, array<float>^ Data, int Rows, int Cols, int Dim3);
		void Add(String^ Name, array<float>^ Data, int Rows, int Cols);
		void Add(String^ Name, array<double>^ Data, int Rows, int Cols);
		void Add(String^ Name, String^ Data);
		void Add(String^ Name, double Data);
		void Add(String^ Name, float Data);
		void Add(String^ Name, int Data);
		void Add(String^ Name, array<INT8>^ Data, int Rows, int Cols, int Dim3);
		void Add(String^ Name, array<INT16>^ Data, int Rows, int Cols, int Dim3);
		void Add(String^ Name, array<INT32>^ Data, int Rows, int Cols, int Dim3);
		void Add(String^ Name, array<INT64>^ Data, int Rows, int Cols, int Dim3);
		void Add(String^ Name, array<UINT8>^ Data, int Rows, int Cols, int Dim3);
		void Add(String^ Name, array<UINT16>^ Data, int Rows, int Cols, int Dim3);
		void Add(String^ Name, array<UINT32>^ Data, int Rows, int Cols, int Dim3);
		void Add(String^ Name, array<UINT64>^ Data, int Rows, int Cols, int Dim3);
		void Add(String^ Name, bool Data);
	};
}
