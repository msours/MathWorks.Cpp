
#include "CellArray.h"

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
	void CellArray::Add(const double Data, int InsertRow, int InsertCol)
	{
		Source = mxCreateDoubleScalar(Data);
		
		memcpy((void *)(mxGetPr(Source)), (void *)&Data, sizeof(double));

		int Ind = (InsertCol - 1) * this->Rows + InsertRow - 1;
		mxSetCell(Destination, Ind, Source);
	}
	void CellArray::Add(const float Data, int InsertRow, int InsertCol)
	{
		const double value = static_cast<double>(Data);
		Source = mxCreateDoubleScalar(value);

		memcpy((void *)(mxGetPr(Source)), (void *)&value, sizeof(double));

		int Ind = (InsertCol - 1)*this->Rows + InsertRow - 1;
		mxSetCell(Destination, Ind, Source);
	}
	void CellArray::Add(const int Data, int InsertRow, int InsertCol)
	{
		const double value = static_cast<double>(Data);
		Source = mxCreateDoubleScalar(value);

		memcpy((void *)(mxGetPr(Source)), (void *)&value, sizeof(double));

		int Ind = (InsertCol - 1)*this->Rows + InsertRow - 1;
		mxSetCell(Destination, Ind, Source);
	}
	void CellArray::Add(const bool Data, int InsertRow, int InsertCol)
	{
		Source = mxCreateLogicalScalar(Data);

		int Ind = (InsertCol - 1)*this->Rows + InsertRow - 1;
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

	void CellArray::ReshapeAdd(const std::vector<double> &Data, int InsertRow, int InsertCol)
	{
		this->ReshapeAdd(Data, 1, Data.size(), 1, InsertRow, InsertCol);
	}
	void CellArray::ReshapeAdd(const std::vector<float> &Data, int InsertRow, int InsertCol)
	{
		this->ReshapeAdd(Data, 1, Data.size(), 1, InsertRow, InsertCol);
	}
	void CellArray::ReshapeAdd(const std::vector<int8_t> &Data, int InsertRow, int InsertCol)
	{
		this->ReshapeAdd(Data, 1, Data.size(), 1, InsertRow, InsertCol);
	}
	void CellArray::ReshapeAdd(const std::vector<int16_t> &Data, int InsertRow, int InsertCol)
	{
		this->ReshapeAdd(Data, 1, Data.size(), 1, InsertRow, InsertCol);
	}
	void CellArray::ReshapeAdd(const std::vector<int> &Data, int InsertRow, int InsertCol)
	{
		this->ReshapeAdd(Data, 1, Data.size(), 1, InsertRow, InsertCol);
	}
	void CellArray::ReshapeAdd(const std::vector<int64_t> &Data, int InsertRow, int InsertCol)
	{
		this->ReshapeAdd(Data, 1, Data.size(), 1, InsertRow, InsertCol);
	}
	void CellArray::ReshapeAdd(const std::vector<uint8_t> &Data, int InsertRow, int InsertCol)
	{
		this->ReshapeAdd(Data, 1, Data.size(), 1, InsertRow, InsertCol);
	}
	void CellArray::ReshapeAdd(const std::vector<uint16_t> &Data, int InsertRow, int InsertCol)
	{
		this->ReshapeAdd(Data, 1, Data.size(), 1, InsertRow, InsertCol);
	}
	void CellArray::ReshapeAdd(const std::vector<uint32_t> &Data, int InsertRow, int InsertCol)
	{
		this->ReshapeAdd(Data, 1, Data.size(), 1, InsertRow, InsertCol);
	}
	void CellArray::ReshapeAdd(const std::vector<uint64_t> &Data, int InsertRow, int InsertCol)
	{
		this->ReshapeAdd(Data, 1, Data.size(), 1, InsertRow, InsertCol);
	}

	void CellArray::ReshapeAdd(const std::vector<double> &Data, int Rows, int Cols, int Dim3, int InsertRow, int InsertCol)
	{
		int Length = Rows * Cols*Dim3;

		const size_t Dim[3] = { Rows, Cols, Dim3 };

		Source = mxCreateNumericArray(3, Dim, mxDOUBLE_CLASS, mxREAL);

		memcpy((void *)(mxGetPr(Source)), (void *)Data.data(), sizeof(double)*Length);

		int Ind = (InsertCol - 1)*this->Rows + InsertRow - 1;
		mxSetCell(Destination, Ind, Source);
	}
	void CellArray::ReshapeAdd(const std::vector<float> &Data, int Rows, int Cols, int Dim3, int InsertRow, int InsertCol)
	{
		int Length = Rows * Cols*Dim3;

		const size_t Dim[3] = { Rows, Cols, Dim3 };

		Source = mxCreateNumericArray(3, Dim, mxSINGLE_CLASS, mxREAL);

		memcpy((void *)(mxGetPr(Source)), (void *)Data.data(), sizeof(float)*Length);

		int Ind = (InsertCol - 1) * this->Rows + InsertRow - 1;
		mxSetCell(Destination, Ind, Source);
	}
	void CellArray::ReshapeAdd(const std::vector<int8_t> &Data, int Rows, int Cols, int Dim3, int InsertRow, int InsertCol)
	{
		int Length = Rows * Cols*Dim3;

		const size_t Dim[3] = { Rows, Cols, Dim3 };

		Source = mxCreateNumericArray(3, Dim, mxINT8_CLASS, mxREAL);

		memcpy((void *)(mxGetPr(Source)), (void *)Data.data(), sizeof(int8_t)*Length);

		int Ind = (InsertCol - 1)*this->Rows + InsertRow - 1;
		mxSetCell(Destination, Ind, Source);
	}
	void CellArray::ReshapeAdd(const std::vector<int16_t> &Data, int Rows, int Cols, int Dim3, int InsertRow, int InsertCol)
	{
		int Length = Rows * Cols*Dim3;

		const size_t Dim[3] = { Rows, Cols, Dim3 };

		Source = mxCreateNumericArray(3, Dim, mxINT16_CLASS, mxREAL);

		memcpy((void *)(mxGetPr(Source)), (void *)Data.data(), sizeof(int16_t)*Length);

		int Ind = (InsertCol - 1)*this->Rows + InsertRow - 1;
		mxSetCell(Destination, Ind, Source);
	}
	void CellArray::ReshapeAdd(const std::vector<int32_t> &Data, int Rows, int Cols, int Dim3, int InsertRow, int InsertCol)
	{
		int Length = Rows * Cols*Dim3;

		const size_t Dim[3] = { Rows, Cols, Dim3 };

		Source = mxCreateNumericArray(3, Dim, mxINT32_CLASS, mxREAL);

		memcpy((void *)(mxGetPr(Source)), (void *)Data.data(), sizeof(int32_t)*Length);

		int Ind = (InsertCol - 1) * this->Rows + InsertRow - 1;
		mxSetCell(Destination, Ind, Source);
	}
	void CellArray::ReshapeAdd(const std::vector<int64_t> &Data, int Rows, int Cols, int Dim3, int InsertRow, int InsertCol)
	{
		int Length = Rows * Cols*Dim3;

		const size_t Dim[3] = { Rows, Cols, Dim3 };

		Source = mxCreateNumericArray(3, Dim, mxINT64_CLASS, mxREAL);

		memcpy((void *)(mxGetPr(Source)), (void *)Data.data(), sizeof(int64_t)*Length);

		int Ind = (InsertCol - 1) * this->Rows + InsertRow - 1;
		mxSetCell(Destination, Ind, Source);
	}
	void CellArray::ReshapeAdd(const std::vector<uint8_t> &Data, int Rows, int Cols, int Dim3, int InsertRow, int InsertCol)
	{
		int Length = Rows * Cols*Dim3;

		const size_t Dim[3] = { Rows, Cols, Dim3 };

		Source = mxCreateNumericArray(3, Dim, mxUINT8_CLASS, mxREAL);

		memcpy((void *)(mxGetPr(Source)), (void *)Data.data(), sizeof(uint8_t)*Length);

		int Ind = (InsertCol - 1)*this->Rows + InsertRow - 1;
		mxSetCell(Destination, Ind, Source);
	}
	void CellArray::ReshapeAdd(const std::vector<uint16_t> &Data, int Rows, int Cols, int Dim3, int InsertRow, int InsertCol)
	{
		int Length = Rows * Cols*Dim3;

		const size_t Dim[3] = { Rows, Cols, Dim3 };

		Source = mxCreateNumericArray(3, Dim, mxUINT16_CLASS, mxREAL);

		memcpy((void *)(mxGetPr(Source)), (void *)Data.data(), sizeof(uint16_t)*Length);

		int Ind = (InsertCol - 1) * this->Rows + InsertRow - 1;
		mxSetCell(Destination, Ind, Source);
	}
	void CellArray::ReshapeAdd(const std::vector<uint32_t> &Data, int Rows, int Cols, int Dim3, int InsertRow, int InsertCol)
	{
		int Length = Rows * Cols * Dim3;

		const size_t Dim[3] = { Rows, Cols, Dim3 };

		Source = mxCreateNumericArray(3, Dim, mxUINT32_CLASS, mxREAL);

		memcpy((void *)(mxGetPr(Source)), (void *)Data.data(), sizeof(uint32_t)*Length);

		int Ind = (InsertCol - 1)*this->Rows + InsertRow - 1;
		mxSetCell(Destination, Ind, Source);
	}
	void CellArray::ReshapeAdd(const std::vector<uint64_t> &Data, int Rows, int Cols, int Dim3, int InsertRow, int InsertCol)
	{
		int Length = Rows * Cols * Dim3;

		const size_t Dim[3] = { Rows, Cols, Dim3 };

		Source = mxCreateNumericArray(3, Dim, mxUINT64_CLASS, mxREAL);

		memcpy((void *)(mxGetPr(Source)), (void *)Data.data(), sizeof(uint64_t)*Length);

		int Ind = (InsertCol - 1) * this->Rows + InsertRow - 1;
		mxSetCell(Destination, Ind, Source);
	}
	void CellArray::ReshapeAdd(const double *Data, const int Rows, const int Cols, const int Dim3, int InsertRow, int InsertCol) 
	{
		int Length = Rows * Cols*Dim3;

		const size_t Dim[3] = { Rows, Cols, Dim3 };

		Source = mxCreateNumericArray(3, Dim, mxDOUBLE_CLASS, mxREAL);

		memcpy((void *)(mxGetPr(Source)), (void *)Data, sizeof(double)*Length);

		int Ind = (InsertCol - 1)*this->Rows + InsertRow - 1;
		mxSetCell(Destination, Ind, Source);
	}
	void CellArray::ReshapeAdd(const float *Data, const int Rows, const int Cols, const int Dim3, int InsertRow, int InsertCol) 
	{
		int Length = Rows * Cols*Dim3;

		const size_t Dim[3] = { Rows, Cols, Dim3 };

		Source = mxCreateNumericArray(3, Dim, mxSINGLE_CLASS, mxREAL);

		memcpy((void *)(mxGetPr(Source)), (void *)Data, sizeof(float)*Length);

		int Ind = (InsertCol - 1) * this->Rows + InsertRow - 1;
		mxSetCell(Destination, Ind, Source);
	}
	void CellArray::ReshapeAdd(const uint8_t *Data, const int Rows, const int Cols, const int Dim3, int InsertRow, int InsertCol) 
	{
		int Length = Rows * Cols*Dim3;

		const size_t Dim[3] = { Rows, Cols, Dim3 };

		Source = mxCreateNumericArray(3, Dim, mxUINT8_CLASS, mxREAL);

		memcpy((void *)(mxGetPr(Source)), (void *)Data, sizeof(uint8_t)*Length);

		int Ind = (InsertCol - 1)*this->Rows + InsertRow - 1;
		mxSetCell(Destination, Ind, Source);
	}
	void CellArray::ReshapeAdd(const uint16_t *Data, const int Rows, const int Cols, const int Dim3, int InsertRow, int InsertCol) 
	{
		int Length = Rows * Cols*Dim3;

		const size_t Dim[3] = { Rows, Cols, Dim3 };

		Source = mxCreateNumericArray(3, Dim, mxUINT16_CLASS, mxREAL);

		memcpy((void *)(mxGetPr(Source)), (void *)Data, sizeof(uint16_t)*Length);

		int Ind = (InsertCol - 1) * this->Rows + InsertRow - 1;
		mxSetCell(Destination, Ind, Source);
	}
	void CellArray::AddImage(const cv::Mat &Image, int InsertRow, int InsertCol)
	{
		const int DataType = Image.type() & CV_MAT_DEPTH_MASK;
		const int Channels = Image.channels();

		switch (DataType)
		{
		case cv::DataType<uint8_t>::type:
		{
			uint8_t *data;
			TypeConverters::CvMatTo1DArray(Image, data);

			this->ReshapeAdd(data, Image.rows, Image.cols, Channels, InsertRow, InsertCol);

			delete[] data;

			return;
		}
		case cv::DataType<uint16_t>::type:
		{
			uint16_t *data;
			TypeConverters::CvMatTo1DArray(Image, data);

			this->ReshapeAdd(data, Image.rows, Image.cols, Channels, InsertRow, InsertCol);

			delete[] data;

			return;
		}
		case cv::DataType<float>::type:
		{
			float *data;
			TypeConverters::CvMatTo1DArray(Image, data);

			this->ReshapeAdd(data, Image.rows, Image.cols, Channels, InsertRow, InsertCol);

			delete[] data;

			return;
		}
		case cv::DataType<double>::type:
		{
			double *data;
			TypeConverters::CvMatTo1DArray(Image, data);

			this->ReshapeAdd(data, Image.rows, Image.cols, Channels, InsertRow, InsertCol);

			delete[] data;

			return;
		}
		default:

			return;
		}
	}
}