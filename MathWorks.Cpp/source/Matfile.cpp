
#include "Matfile.h"

namespace MathWorks
{
	Matfile::Matfile(MATFile *Destination) 
	{
		this->Destination = Destination;
	}
	Matfile Matfile::Open(const std::string &FilePath, const MatfileMode FileMode)
	{
		const std::string MatfileModes[5]{ "r", "u" , "w6", "wz", "w7.3" };

		const char *mode = MatfileModes[static_cast<int>(FileMode)].c_str();

		MATFile *Destination = matOpen(FilePath.c_str(), mode);

		if (Destination == NULL) throw std::invalid_argument("Invalid file name or format");

		return Matfile(Destination);
	}
	bool Matfile::Close()
	{
		return (matClose(Destination) == 0);
	}
	void Matfile::Add(const std::string &Name, MatlabStruct &Data)
	{
		const char *name = Name.c_str();
		matPutVariable(Destination, name, Data.Destination);
	}
	void Matfile::Add(const std::string &Name, CellArray &Data)
	{
		const char *name = Name.c_str();
		matPutVariable(Destination, name, Data.Destination);
	}
	void Matfile::Add(const std::string &Name, const double Data)
	{
		const char *name = Name.c_str();

		mxArray *source = mxCreateDoubleScalar(Data);

		memcpy((void *)(mxGetPr(source)), (void *)&Data, sizeof(double));
		matPutVariable(Destination, name, source);
		mxDestroyArray(source);
	}
	void Matfile::Add(const std::string &Name, const float Data)
	{
		const char *name = Name.c_str();

		double value = static_cast<double>(Data);
		mxArray *source = mxCreateDoubleScalar(value);

		memcpy((void *)(mxGetPr(source)), (void *)&value, sizeof(double));
		matPutVariable(Destination, name, source);
		mxDestroyArray(source);


	}
	void Matfile::Add(const std::string &Name, const int Data)
	{
		const char *name = Name.c_str();

		double value = static_cast<double>(Data);
		mxArray *source = mxCreateDoubleScalar(value);

		memcpy((void *)(mxGetPr(source)), (void *)&value, sizeof(double));
		matPutVariable(Destination, name, source);
		mxDestroyArray(source);

	}
	void Matfile::Add(const std::string &Name, const bool Data)
	{
		const char *name = Name.c_str();

		mxArray *source = mxCreateLogicalScalar(Data);

		matPutVariable(Destination, name, source);
		mxDestroyArray(source);

	}
	void Matfile::Add(const std::string &Name, const std::string &Data)
	{
		const char *name = Name.c_str();

		const char *V = Data.c_str();

		mxArray *source = mxCreateString(V);

		matPutVariable(Destination, name, source);
		mxDestroyArray(source);

	}

	void Matfile::Add(const std::string &Name, const std::vector<double> &Data) 
	{
		this->ReshapeAdd(Name, Data, 1, Data.size(), 1);
	}
	void Matfile::Add(const std::string &Name, const std::vector<float> &Data)
	{
		this->ReshapeAdd(Name, Data, 1, Data.size(), 1);
	}
	void Matfile::Add(const std::string &Name, const std::vector<int8_t> &Data)
	{
		this->ReshapeAdd(Name, Data, 1, Data.size(), 1);
	}
	void Matfile::Add(const std::string &Name, const std::vector<int16_t> &Data)
	{
		this->ReshapeAdd(Name, Data, 1, Data.size(), 1);
	}
	void Matfile::Add(const std::string &Name, const std::vector<int> &Data)
	{
		this->ReshapeAdd(Name, Data, 1, Data.size(), 1);
	}	
	void Matfile::Add(const std::string &Name, const std::vector<int64_t> &Data)
	{
		this->ReshapeAdd(Name, Data, 1, Data.size(), 1);
	}
	void Matfile::Add(const std::string &Name, const std::vector<uint8_t> &Data)
	{
		this->ReshapeAdd(Name, Data, 1, Data.size(), 1);
	}
	void Matfile::Add(const std::string &Name, const std::vector<uint16_t> &Data)
	{
		this->ReshapeAdd(Name, Data, 1, Data.size(), 1);
	}
	void Matfile::Add(const std::string &Name, const std::vector<uint32_t> &Data)
	{
		this->ReshapeAdd(Name, Data, 1, Data.size(), 1);
	}
	void Matfile::Add(const std::string &Name, const std::vector<uint64_t> &Data)
	{
		this->ReshapeAdd(Name, Data, 1, Data.size(), 1);
	}

	void Matfile::AddImage(const std::string &Name, const cv::Mat &Image)
	{
		const int DataType = Image.type() & CV_MAT_DEPTH_MASK;
		const int Channels = Image.channels();

		switch (DataType)
		{
		case cv::DataType<uint8_t>::type:
		{
			uint8_t *data;
			TypeConverters::CvMatTo1DArray(Image, data);

			this->ReshapeAdd(Name, data, Image.rows, Image.cols, Channels);

			delete[] data;

			return;
		}
		case cv::DataType<uint16_t>::type:
		{
			uint16_t *data;
			TypeConverters::CvMatTo1DArray(Image, data);

			this->ReshapeAdd(Name, data, Image.rows, Image.cols, Channels);

			delete[] data;

			return;
		}
		case cv::DataType<float>::type:
		{
			float *data;
			TypeConverters::CvMatTo1DArray(Image, data);

			this->ReshapeAdd(Name, data, Image.rows, Image.cols, Channels);

			delete[] data;

			return;
		}
		case cv::DataType<double>::type:
		{
			double *data;
			TypeConverters::CvMatTo1DArray(Image, data);

			this->ReshapeAdd(Name, data, Image.rows, Image.cols, Channels);

			delete[] data;

			return;
		}
		default:

			return;
		}
	}

	void Matfile::ReshapeAdd(const std::string &Name, const std::vector<double> &Data, const int Rows, const int Cols, const int Dim3)
	{
		int Length = Rows * Cols*Dim3;
		const char *name = Name.c_str();

		const size_t Dim[3] = { Rows, Cols, Dim3 };

		mxArray *source = mxCreateNumericArray(3, Dim, mxDOUBLE_CLASS, mxREAL);

		memcpy((void *)(mxGetPr(source)), (void *)Data.data(), sizeof(double)*Length);
		matPutVariable(Destination, name, source);
		mxDestroyArray(source);
	}
	void Matfile::ReshapeAdd(const std::string &Name, const std::vector<float> &Data, const int Rows, const int Cols, const int Dim3)
	{
		int Length = Rows * Cols*Dim3;
		const char *name = Name.c_str();

		const size_t Dim[3] = { Rows, Cols, Dim3 };

		mxArray *source = mxCreateNumericArray(3, Dim, mxSINGLE_CLASS, mxREAL);

		memcpy((void *)(mxGetPr(source)), (void *)Data.data(), sizeof(float)*Length);
		matPutVariable(Destination, name, source);
		mxDestroyArray(source);

	}
	void Matfile::ReshapeAdd(const std::string &Name, const std::vector<int8_t> &Data, const int Rows, const int Cols, const int Dim3)
	{
		int Length = Rows * Cols*Dim3;
		const char *name = Name.c_str();

		const size_t Dim[3] = { Rows, Cols, Dim3 };

		mxArray *source = mxCreateNumericArray(3, Dim, mxINT8_CLASS, mxREAL);

		memcpy((void *)(mxGetPr(source)), (void *)Data.data(), sizeof(int8_t)*Length);
		matPutVariable(Destination, name, source);
		mxDestroyArray(source);

	}
	void Matfile::ReshapeAdd(const std::string &Name, const std::vector<int16_t> &Data, const int Rows, const int Cols, const int Dim3)
	{
		int Length = Rows * Cols*Dim3;
		const char *name = Name.c_str();

		const size_t Dim[3] = { Rows, Cols, Dim3 };

		mxArray *source = mxCreateNumericArray(3, Dim, mxINT16_CLASS, mxREAL);

		memcpy((void *)(mxGetPr(source)), (void *)Data.data(), sizeof(int16_t)*Length);
		matPutVariable(Destination, name, source);
		mxDestroyArray(source);

	}
	void Matfile::ReshapeAdd(const std::string &Name, const std::vector<int32_t> &Data, const int Rows, const int Cols, const int Dim3)
	{
		int Length = Rows * Cols*Dim3;
		const char *name = Name.c_str();

		const size_t Dim[3] = { Rows, Cols, Dim3 };

		mxArray *source = mxCreateNumericArray(3, Dim, mxINT32_CLASS, mxREAL);

		memcpy((void *)(mxGetPr(source)), (void *)Data.data(), sizeof(int32_t)*Length);
		matPutVariable(Destination, name, source);
		mxDestroyArray(source);

	}
	void Matfile::ReshapeAdd(const std::string &Name, const std::vector<int64_t> &Data, const int Rows, const int Cols, const int Dim3)
	{
		int Length = Rows * Cols*Dim3;
		const char *name = Name.c_str();

		const size_t Dim[3] = { Rows, Cols, Dim3 };

		mxArray *source = mxCreateNumericArray(3, Dim, mxINT64_CLASS, mxREAL);

		memcpy((void *)(mxGetPr(source)), (void *)Data.data(), sizeof(int64_t)*Length);
		matPutVariable(Destination, name, source);
		mxDestroyArray(source);

	}
	void Matfile::ReshapeAdd(const std::string &Name, const std::vector<uint8_t> &Data, const int Rows, const int Cols, const int Dim3)
	{
		int Length = Rows * Cols*Dim3;
		const char *name = Name.c_str();

		const size_t Dim[3] = { Rows, Cols, Dim3 };

		mxArray *source = mxCreateNumericArray(3, Dim, mxUINT8_CLASS, mxREAL);

		memcpy((void *)(mxGetPr(source)), (void *)Data.data(), sizeof(uint8_t)*Length);
		matPutVariable(Destination, name, source);
		mxDestroyArray(source);

	}
	void Matfile::ReshapeAdd(const std::string &Name, const std::vector<uint16_t> &Data, const int Rows, const int Cols, const int Dim3)
	{
		int Length = Rows * Cols*Dim3;
		const char *name = Name.c_str();

		const size_t Dim[3] = { Rows, Cols, Dim3 };

		mxArray *source = mxCreateNumericArray(3, Dim, mxUINT16_CLASS, mxREAL);

		memcpy((void *)(mxGetPr(source)), (void *)Data.data(), sizeof(uint16_t)*Length);
		matPutVariable(Destination, name, source);

		mxDestroyArray(source);

	}
	void Matfile::ReshapeAdd(const std::string &Name, const std::vector<uint32_t> &Data, const int Rows, const int Cols, const int Dim3)
	{
		int Length = Rows * Cols*Dim3;
		const char *name = Name.c_str();

		const size_t Dim[3] = { Rows, Cols, Dim3 };

		mxArray *source = mxCreateNumericArray(3, Dim, mxUINT32_CLASS, mxREAL);

		memcpy((void *)(mxGetPr(source)), (void *)Data.data(), sizeof(uint32_t)*Length);
		matPutVariable(Destination, name, source);
		mxDestroyArray(source);

	}
	void Matfile::ReshapeAdd(const std::string &Name, const std::vector<uint64_t> &Data, const int Rows, const int Cols, const int Dim3)
	{
		int Length = Rows * Cols*Dim3;
		const char *name = Name.c_str();

		const size_t Dim[3] = { Rows, Cols, Dim3 };

		mxArray *source = mxCreateNumericArray(3, Dim, mxUINT64_CLASS, mxREAL);

		memcpy((void *)(mxGetPr(source)), (void *)Data.data(), sizeof(uint64_t)*Length);
		matPutVariable(Destination, name, source);
		mxDestroyArray(source);

	}
	void Matfile::ReshapeAdd(const std::string &Name, const double *Data, const int Rows, const int Cols, const int Dim3) 
	{
		int Length = Rows * Cols*Dim3;
		const char *name = Name.c_str();

		const size_t Dim[3] = { Rows, Cols, Dim3 };

		mxArray *source = mxCreateNumericArray(3, Dim, mxDOUBLE_CLASS, mxREAL);

		memcpy((void *)(mxGetPr(source)), (void *)Data, sizeof(double)*Length);
		matPutVariable(Destination, name, source);
		mxDestroyArray(source);
	}
	void Matfile::ReshapeAdd(const std::string &Name, const float *Data, const int Rows, const int Cols, const int Dim3)
	{
		int Length = Rows * Cols*Dim3;
		const char *name = Name.c_str();

		const size_t Dim[3] = { Rows, Cols, Dim3 };

		mxArray *source = mxCreateNumericArray(3, Dim, mxSINGLE_CLASS, mxREAL);

		memcpy((void *)(mxGetPr(source)), (void *)Data, sizeof(float)*Length);
		matPutVariable(Destination, name, source);
		mxDestroyArray(source);
	}
	void Matfile::ReshapeAdd(const std::string &Name, const uint8_t *Data, const int Rows, const int Cols, const int Dim3)
	{
		int Length = Rows * Cols * Dim3;
		const char *name = Name.c_str();

		const size_t Dim[3] = { Rows, Cols, Dim3 };

		mxArray *source = mxCreateNumericArray(3, Dim, mxUINT8_CLASS, mxREAL);

		memcpy((void *)(mxGetPr(source)), (void *)Data, sizeof(uint8_t)*Length);
		matPutVariable(Destination, name, source);
		mxDestroyArray(source);
	}
	void Matfile::ReshapeAdd(const std::string &Name, const uint16_t *Data, const int Rows, const int Cols, const int Dim3)
	{
		int Length = Rows * Cols * Dim3;
		const char *name = Name.c_str();

		const size_t Dim[3] = { Rows, Cols, Dim3 };

		mxArray *source = mxCreateNumericArray(3, Dim, mxUINT16_CLASS, mxREAL);

		memcpy((void *)(mxGetPr(source)), (void *)Data, sizeof(uint16_t)*Length);
		matPutVariable(Destination, name, source);
		mxDestroyArray(source);
	}
}