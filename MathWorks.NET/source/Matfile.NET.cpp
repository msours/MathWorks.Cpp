
#include "Matfile.NET.h"
#include <msclr\marshal_cppstd.h>

namespace MathWorks
{
	namespace NET
	{
		Matfile^ Matfile::Open(System::String^ FilePath, MatfileMode FileMode)
		{
			const std::string &filePath = msclr::interop::marshal_as<std::string>(FilePath);

			MathWorks::Matfile *Matfile_ = new MathWorks::Matfile(MathWorks::Matfile::Open(filePath, static_cast<MathWorks::MatfileMode>(FileMode)));

			return gcnew Matfile(Matfile_);
		}
		bool Matfile::Close()
		{
			return this->Matfile_->Close();
		}
		Matfile::Matfile(MathWorks::Matfile *Matfile)
		{
			this->Matfile_ = Matfile;
		}
		Matfile::~Matfile()
		{
			delete this->Matfile_;
		}
		void Matfile::Add(System::String^ Name, MatlabStruct^ Data)
		{
			const std::string &name = msclr::interop::marshal_as<std::string>(Name);
			this->Matfile_->Add(name, *Data->MatlabStruct_);
		}
		void Matfile::Add(System::String^ Name, CellArray^ Data)
		{
			const std::string &name = msclr::interop::marshal_as<std::string>(Name);
			this->Matfile_->Add(name, *Data->CellArray_);
		}
		void Matfile::Add(System::String^ Name, double Data)
		{
			const std::string &name = msclr::interop::marshal_as<std::string>(Name);

			this->Matfile_->Add(name, Data);
		}
		void Matfile::Add(System::String^ Name, float Data)
		{
			const std::string &name = msclr::interop::marshal_as<std::string>(Name);

			this->Matfile_->Add(name, Data);
		}
		void Matfile::Add(System::String^ Name, int Data)
		{
			const std::string &name = msclr::interop::marshal_as<std::string>(Name);

			this->Matfile_->Add(name, Data);
		}
		void Matfile::Add(System::String^ Name, bool Data)
		{
			const std::string &name = msclr::interop::marshal_as<std::string>(Name);

			this->Matfile_->Add(name, Data);
		}
		void Matfile::Add(System::String^ Name, System::String^ Data)
		{
			const std::string &name = msclr::interop::marshal_as<std::string>(Name);
			const std::string &data = msclr::interop::marshal_as<std::string>(Data);

			this->Matfile_->Add(name, data);
		}

		void Matfile::Add(System::String^ Name, array<double>^ Data)
		{
			this->ReshapeAdd(Name, Data, 1, Data->Length, 1);
		}

		void Matfile::Add(System::String^ Name, array<double, 2>^ Data)
		{
			const std::string &name = msclr::interop::marshal_as<std::string>(Name);

			const int Rows = Data->GetLength(0);
			const int Cols = Data->GetLength(1);

			std::vector<double> data;
			for (int k = 0; k < Cols; k++)
			{
				for (int j = 0; j < Rows; j++)
				{
					data.push_back((double)Data[j, k]);
				}
			}

			this->Matfile_->ReshapeAdd(name, data, Rows, Cols);
		}
		void Matfile::Add(System::String^ Name, array<double, 3>^ Data)
		{
			const std::string &name = msclr::interop::marshal_as<std::string>(Name);

			const int Rows = Data->GetLength(0);
			const int Cols = Data->GetLength(1);
			const int Dim3 = Data->GetLength(2);

			std::vector<double> data;
			for (int p = 0; p < Dim3; p++)
			{
				for (int k = 0; k < Cols; k++)
				{
					for (int j = 0; j < Rows; j++)
					{
						data.push_back((double)Data[j, k, p]);
					}
				}
			}

			this->Matfile_->ReshapeAdd(name, data, Rows, Cols, Dim3);
		}

		void Matfile::ReshapeAdd(System::String^ Name, array<double>^ Data, int Rows, int Cols, int Dim3)
		{
			int Length = Rows * Cols * Dim3;
			const std::string &name = msclr::interop::marshal_as<std::string>(Name);

			std::vector<double> data;
			for (int k = 0; k < Length; k++) data.push_back((double)Data[k]);

			this->Matfile_->ReshapeAdd(name, data, Rows, Cols, Dim3);
		}
		void Matfile::ReshapeAdd(System::String^ Name, array<float>^ Data, int Rows, int Cols, int Dim3)
		{
			int Length = Rows * Cols*Dim3;
			const std::string &name = msclr::interop::marshal_as<std::string>(Name);

			std::vector<float> data;
			for (int k = 0; k < Length; k++) data.push_back((float)Data[k]);

			this->Matfile_->ReshapeAdd(name, data, Rows, Cols, Dim3);
		}
		void Matfile::ReshapeAdd(System::String^ Name, array<INT8>^ Data, int Rows, int Cols, int Dim3)
		{
			int Length = Rows * Cols*Dim3;
			const std::string &name = msclr::interop::marshal_as<std::string>(Name);

			std::vector<INT8> data;
			for (int k = 0; k < Length; k++)  data.push_back((INT8)Data[k]);

			this->Matfile_->ReshapeAdd(name, data, Rows, Cols, Dim3);
		}
		void Matfile::ReshapeAdd(System::String^ Name, array<INT16>^ Data, int Rows, int Cols, int Dim3)
		{
			int Length = Rows * Cols*Dim3;
			const std::string &name = msclr::interop::marshal_as<std::string>(Name);

			std::vector<INT16> data;

			for (int k = 0; k < Length; k++)data.push_back((INT16)Data[k]);

			this->Matfile_->ReshapeAdd(name, data, Rows, Cols, Dim3);
		}
		void Matfile::ReshapeAdd(System::String^ Name, array<INT32>^ Data, int Rows, int Cols, int Dim3)
		{
			int Length = Rows * Cols*Dim3;
			const std::string &name = msclr::interop::marshal_as<std::string>(Name);

			std::vector<INT32> data;

			for (int k = 0; k < Length; k++)data.push_back((INT32)Data[k]);

			this->Matfile_->ReshapeAdd(name, data, Rows, Cols, Dim3);
		}
		void Matfile::ReshapeAdd(System::String^ Name, array<INT64>^ Data, int Rows, int Cols, int Dim3)
		{
			int Length = Rows * Cols*Dim3;
			const std::string &name = msclr::interop::marshal_as<std::string>(Name);

			std::vector<INT64> data;

			for (int k = 0; k < Length; k++)data.push_back((INT64)Data[k]);

			this->Matfile_->ReshapeAdd(name, data, Rows, Cols, Dim3);
		}
		void Matfile::ReshapeAdd(System::String^ Name, array<UINT8>^ Data, int Rows, int Cols, int Dim3)
		{
			int Length = Rows * Cols*Dim3;
			const std::string &name = msclr::interop::marshal_as<std::string>(Name);

			std::vector<UINT8> data;
			for (int k = 0; k < Length; k++)  data.push_back((UINT8)Data[k]);

			this->Matfile_->ReshapeAdd(name, data, Rows, Cols, Dim3);
		}
		void Matfile::ReshapeAdd(System::String^ Name, array<UINT16>^ Data, int Rows, int Cols, int Dim3)
		{
			int Length = Rows * Cols*Dim3;
			const std::string &name = msclr::interop::marshal_as<std::string>(Name);

			std::vector<UINT16> data;

			for (int k = 0; k < Length; k++)data.push_back((UINT16)Data[k]);

			this->Matfile_->ReshapeAdd(name, data, Rows, Cols, Dim3);
		}
		void Matfile::ReshapeAdd(System::String^ Name, array<UINT32>^ Data, int Rows, int Cols, int Dim3)
		{
			int Length = Rows * Cols*Dim3;
			const std::string &name = msclr::interop::marshal_as<std::string>(Name);

			std::vector<UINT32> data;

			for (int k = 0; k < Length; k++)data.push_back((UINT32)Data[k]);

			this->Matfile_->ReshapeAdd(name, data, Rows, Cols, Dim3);
		}
		void Matfile::ReshapeAdd(System::String^ Name, array<UINT64>^ Data, int Rows, int Cols, int Dim3)
		{
			int Length = Rows * Cols*Dim3;
			const std::string &name = msclr::interop::marshal_as<std::string>(Name);

			std::vector<UINT64> data;

			for (int k = 0; k < Length; k++)data.push_back((UINT64)Data[k]);

			this->Matfile_->ReshapeAdd(name, data, Rows, Cols, Dim3);
		}
	}
}