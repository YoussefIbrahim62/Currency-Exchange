#pragma once
#include "AllNeededLibraries.h"
#include "clsCurrency.h"
#include "clsScreen.h"


class clsUpdateCurrencyScreen : protected clsScreen
{
private:


	static bool ReadAnswerYesOrNO(string message)
	{
		char answer;

		cout << message << " : ";
		cin >> answer;

		while (cin.fail() || (tolower(answer) != 'y' && tolower(answer) != 'n'))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << "\nInvalid input, try again: ";
			cin >> answer;
		}

		if (tolower(answer) == 'y')
			return true;
		else
			return false;
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


	static clsCurrency _AskUserForCurrencyCode()
	{
		string Code;

		cout << "Please enter currency code: ";
		cin >> Code;

		clsCurrency NewCurrency = clsCurrency::FindByCode(Code);

		return NewCurrency;
	}


	static double _UpdateRateScreen()
	{
		double NewRate;

		cout << "\nUpdate currency rate: \n";
		cout << "------------------------\n";

		cout << "Enter the new rate: ";
		cin >> NewRate;

		return NewRate;
	}


	static void _Update()
	{
		clsCurrency NewCurrency = _AskUserForCurrencyCode();

		if (NewCurrency.IsEmpty())
			cout << "The currency doesn't not exist in our system! ";
		else
		{
			_PrintCurrencyCard(NewCurrency);

			if (ReadAnswerYesOrNO("Are you sure you want to update the rate of this currency y/n? "))
			{
				double NewRate = _UpdateRateScreen();
				NewCurrency.UpdateRate(NewRate);

				cout << "\n\nCurrency rate has been updated successfully\n";

				_PrintCurrencyCard(NewCurrency);
			}

		}
	}

public:

	static void ShowUpdateCurrencyScreen()
	{

		_DrawScreenHeader("\t Update currency screen");
		_Update();	

	}



};

