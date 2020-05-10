
#pragma once

#include "MatlabStruct.NET.h"
#include "Matfile.h"
#include <Windows.h>

namespace MathWorks
{
	namespace NET
	{
		public enum class MatfileMode
		{
			Read = 0,
			Update = 1,
			Write = 2,
			CompressedWrite = 3,
			WriteHDF5 = 4
		};

		public ref class Matfile : System::IDisposable
		{
		public:
			static Matfile^ Open(System::String^ FilePath, MatfileMode FileMode);
			~Matfile();

			bool Close();
			void Add(System::String^ Name, MatlabStruct^ Data);
			void Add(System::String^ Name, CellArray^ Data);
			void Add(System::String^ Name, array<double>^ Data, int Rows, int Cols, int Dim3);
			void Add(System::String^ Name, array<float>^ Data, int Rows, int Cols, int Dim3);
			void Add(System::String^ Name, array<float>^ Data, int Rows, int Cols);
			void Add(System::String^ Name, array<double>^ Data, int Rows, int Cols);
			void Add(System::String^ Name, System::String^ Data);
			void Add(System::String^ Name, double Data);
			void Add(System::String^ Name, float Data);
			void Add(System::String^ Name, int Data);
			void Add(System::String^ Name, array<INT8>^ Data, int Rows, int Cols, int Dim3);
			void Add(System::String^ Name, array<INT16>^ Data, int Rows, int Cols, int Dim3);
			void Add(System::String^ Name, array<INT32>^ Data, int Rows, int Cols, int Dim3);
			void Add(System::String^ Name, array<INT64>^ Data, int Rows, int Cols, int Dim3);
			void Add(System::String^ Name, array<UINT8>^ Data, int Rows, int Cols, int Dim3);
			void Add(System::String^ Name, array<UINT16>^ Data, int Rows, int Cols, int Dim3);
			void Add(System::String^ Name, array<UINT32>^ Data, int Rows, int Cols, int Dim3);
			void Add(System::String^ Name, array<UINT64>^ Data, int Rows, int Cols, int Dim3);
			void Add(System::String^ Name, bool Data);

		private:
			Matfile(MathWorks::Matfile *Matfile);

			MathWorks::Matfile *Matfile_;

		};
	}
}