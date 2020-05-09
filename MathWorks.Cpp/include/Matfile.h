#pragma once

#include "MatlabStruct.h"
#include <iostream>

namespace MathWorks
{
	enum MatfileMode
	{
		Read = 0,
		Update = 1,
		Write = 2,
		CompressedWrite = 3,
		WriteHDF5 = 4
	};

	class Matfile
	{
	public:

		Matfile(const std::string &FilePath, const MatfileMode FileMode = MatfileMode::CompressedWrite);

		bool Open();
		bool Close();
		void Add(const std::string &Name, MatlabStruct &Data);
		void Add(const std::string &Name, CellArray &Data);
		void Add(const std::string &Name, const std::vector<double> &Data, const int Rows, const int Cols, const int Dim3);
		void Add(const std::string &Name, const std::vector<float> &Data, const int Rows, const int Cols, const int Dim3);
		void Add(const std::string &Name, const std::vector<float> &Data, const int Rows, const int Cols);
		void Add(const std::string &Name, const std::vector<double> &Data, const int Rows, const int Cols);
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

		char *filePath;
		MatfileMode fileMode;

		const std::string MatfileModes[5] = { "r", "u" , "w6", "wz", "w7.3" };

		MATFile *Destination = NULL;
	};
}
