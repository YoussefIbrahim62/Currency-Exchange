#pragma once
#include"AllNeededLibraries.h"
#include"clsScreen.h"
#include "clsCurrency.h"

class clsFindCurrencyScreen:protected clsScreen
{

private:

	enum enByCodeOrByCountry
	{
		ByCode = 1,
		ByCountry = 2
	};



#pragma region Side functions


	static bool IsNumberBetween(double Number, double From, double To)
	{
		if (Number >= From && Number <= To)
			return true;
		else
			return false;
	}


	static short ReadShortNumber(string ErrorMessage = "Invalid Number, Enter again\n")
	{
		short Number;
		while (!(cin >> Number)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
		}
		return Number;
	}


	static short ReadShortNumberBetween(short From, short To, string ErrorMessage = "Number is not within range, Enter again:\n")
	{
		short Number = ReadShortNumber();

		while (!IsNumberBetween(Number, From, To))
		{
			cout << ErrorMessage;
			Number = ReadShortNumber();
		}
		return Number;
	}


#pragma endregion


	static short _AskUserByCodeOrByCountry()
	{
		cout << "Find by: [1] Code or [2] Country ? ";

		short Option = ReadShortNumberBetween(1, 2);

		return Option;
	}


	static string _AskUserForCurrencyCode()
	{
		string Currency;

		cout << "\nPlease enter the currency code : ";
		cin >> Currency;

		return Currency;
	}


	static string _AskUserForCountry()
	{
		string Country;

		cout << "\nPlease enter the country : ";
		cin >> Country;

		return Country;
	}


	static void _PrintCurrencyCard(clsCurrency Currency)
	{
		cout << "\nCurrency card: \n";
		cout << "---------------------\n";

		cout << "Country    : " << Currency.GetCountry() << "\n";
		cout << "Code       : " << Currency.GetCode() << "\n";
		cout << "Name       : " << Currency.GetCurrencyName() << "\n";
		cout << "Rate(1$) = : " << Currency.GetRate() << "\n";

		cout << "--------------------------------------";

		cout << "\n\n";
	}



	static void _FindCurrency(enByCodeOrByCountry Option)
	{

		clsCurrency NewCurrency;

		if (Option == enByCodeOrByCountry::ByCode)
		{
			string CurrencyCode = _AskUserForCurrencyCode();

			NewCurrency  = clsCurrency::FindByCode(CurrencyCode);
			
		}
		else if (Option == enByCodeOrByCountry::ByCountry)
		{
			string Country = _AskUserForCountry();

			NewCurrency = clsCurrency::FindByCountry(Country);
		}

		if (!NewCurrency.IsEmpty())
		{
			cout << "\n\nThe currency is found :-) \n";
			_PrintCurrencyCard(NewCurrency);
		}
		else
			cout << "\nThe currency does not exist :-( \n";

	}




public:


	static void ShowFindCurrencyScreen()
	{
		_DrawScreenHeader("\t\tFind currency screen");

		_FindCurrency((enByCodeOrByCountry)_AskUserByCodeOrByCountry());
	}



};

