#pragma once

#include "MatlabStruct.h"
#include <iostream>

namespace MathWorks
{
	class Matfile
	{
	public:

		Matfile(const std::string &FilePath, const std::string &FileMode);

		bool Open();
		bool Close();
		void Add(const std::string &Name, MatlabStruct &Data);
		void Add(const std::string &Name, CellArray &Data);
		void Add(const std::string &Name, const std::vector<double> &Data, const int Rows, const int Cols, const int Dim3);
		void Add(const std::string &Name, const std::vector<float> &Data, const int Rows, const int Cols, const int Dim3);
		void Add(const std::string &Name, const std::vector<float> &Data, const int Rows,const int Cols);
		void Add(const std::string &Name, const std::vector<double> &Data, const int Rows,const int Cols);
		void Add(const std::string &Name, const std::string &Data);
		void Add(const std::string &Name, const double Data);
		void Add(const std::string &Name, const float Data);
		void Add(const std::string &Name, const int Data);
		void Add(const std::string &Name, const std::vector<int8_t> &Data, const int Rows, const int Cols, const int Dim3);
		void Add(const std::string &Name, const std::vector<int16_t> &Data, const int Rows, const int Cols, const int Dim3);
		void Add(const std::string &Name, const std::vector<int32_t> &Data, const int Rows, const int Cols, const int Dim3);
		void Add(const std::string &Name, const std::vector<int64_t> &Data, const int Rows, const int Cols, const int Dim3);
		void Add(const std::string &Name, const std::vector<uint8_t> &Data, const int Rows, const int Cols, const int Dim3);
		void Add(const std::string &Name, const std::vector<uint16_t> &Data, const int Rows, const int Cols, const int Dim3);
		void Add(const std::string &Name, const std::vector<uint32_t> &Data, const int Rows, const int Cols, const int Dim3);
		void Add(const std::string &Name, const std::vector<uint64_t> &Data, const int Rows, const int Cols, const int Dim3);
		void Add(const std::string &Name, const bool Data);

	private:

		const char *filePath;
		const char *fileMode;

		MATFile *Destination = NULL;
	};
}
