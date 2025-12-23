#pragma once
#include"AllNeededLibraries.h"

class clsCurrency
{
private:

	enum _enMode
	{
		EmptyMode = 0,
		UpdateMode = 1
	};

	_enMode _Mode;

	string _Country;
	string _Code;
	string _CurrencyName;
	double _Rate;

	bool MarkedForDeletion = false;


#pragma region File-related methods


	// Get Records
	static clsCurrency _ConvertRecordToObject(string Record)
	{
		vector<string> vRecordData = clsString::Split(Record,"#//#");

		return clsCurrency(_enMode::UpdateMode, vRecordData[0], vRecordData[1], vRecordData[2], stod(vRecordData[3]));

	}

	static vector<clsCurrency> _GetAllRecordsFromFile(string FileName)
	{

		vector<clsCurrency> vAllRecords;

		fstream MyFile;

		MyFile.open(FileName, ios::in);

		if (MyFile.is_open())
		{
			string Recrod;
			while (getline(MyFile, Recrod))
			{
				if (Recrod != "")
				{
					vAllRecords.push_back(_ConvertRecordToObject(Recrod));
				}
			}
		}

		MyFile.close();
		return vAllRecords;
	}


	//Update records 

	static string _ConvertObjectToRecord(clsCurrency Currency, string Separator = "#//#")
	{
		string Record = "";

		Record += Currency.GetCountry() + Separator;

		Record += Currency.GetCode() + Separator;

		Record += Currency.GetCurrencyName() + Separator;

		Record += to_string(Currency.GetRate());



		return Record;

	}


	static void _UpdateTheFileWithNewData(string FileName, vector<clsCurrency> vAllCurrencies)
	{
		fstream MyFile;

		MyFile.open(FileName, ios::out);

		if(MyFile.is_open())
		{
			for (clsCurrency C : vAllCurrencies)
			{
				if (C.MarkedForDeletion != true)
				{
					MyFile << _ConvertObjectToRecord(C) << endl;
				}
			}
		}

		MyFile.close();

	}

#pragma endregion



#pragma region Private Methods

	void _Update()
	{
		vector<clsCurrency> vAllCurrencies = _GetAllRecordsFromFile("Currencies.txt");

		for (clsCurrency &C : vAllCurrencies)
		{
			if (C.GetCountry() == this->GetCountry())
			{
				C = *this;
				break;
			}
		}

		_UpdateTheFileWithNewData("Currencies.txt", vAllCurrencies);
	}

	static clsCurrency _GetEmptyObject()
	{
		return clsCurrency(_enMode::EmptyMode, "", "", "", 0);
	}

#pragma endregion





public:


#pragma region constructor

	clsCurrency(_enMode Mode, string Country, string Code, string CurrencyName, double Rate)
	{
		_Mode = Mode;
		_Country = Country;
		_Code = Code;
		_CurrencyName = CurrencyName;
		_Rate = Rate;
	}


#pragma endregion


#pragma region Properties (setters/getters)

	string GetCountry()
	{
		return _Country;
	}

	string GetCode()
	{
		return _Code;
	}

	string GetCurrencyName()
	{
		return _CurrencyName;
	}

	double GetRate()
	{
		return _Rate;
	}


	void UpdateRate(double NewRate)
	{
		_Rate = NewRate;
		_Update();
	}


#pragma endregion



#pragma region Public Methods

	bool IsEmpty()
	{
		return (this->_Mode == _enMode::EmptyMode);
	}


#pragma endregion




#pragma region Public static Methods


	static clsCurrency FindByCountry(string Country)
	{
		Country = clsString::UpperAllString(Country);


		fstream MyFile;

		MyFile.open("Currencies.txt", ios::in);

		if (MyFile.is_open())
		{
			string Recrod;
			while (getline(MyFile, Recrod))
			{
				clsCurrency C = _ConvertRecordToObject(Recrod);
				if (C.GetCountry() == Country)
				{
					return C;
				}
			}
		}

		MyFile.close();

		return _GetEmptyObject();
	}


	static clsCurrency FindByCode(string Code)
	{
		Code = clsString::UpperAllString(Code);

		fstream MyFile;

		MyFile.open("Currencies.txt", ios::in);

		if (MyFile.is_open())
		{
			string Recrod;
			while (getline(MyFile, Recrod))
			{
				clsCurrency C = _ConvertRecordToObject(Recrod);
				if (C.GetCode() == Code)
				{
					return C;
				}
			}
		}

		MyFile.close();

		return _GetEmptyObject();
	}


	static bool DoesCurrencyExist(string CurrencyCode )
	{
		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
		return(!Currency.IsEmpty());
	}


	static vector <clsCurrency> GetAllCurrencies()
	{
		return _GetAllRecordsFromFile("Currencies.txt");
	}

#pragma endregion


};

