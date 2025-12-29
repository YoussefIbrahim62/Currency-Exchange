#pragma once
#include "AllNeededLibraries.h"
#include "clsScreen.h"
#include"clsCurrency.h"

class clsCurrencyCalculatorScreen : protected clsScreen
{

private:

	static clsCurrency _AskUserForCurrency(string Message)
	{
		cout << Message << endl;

		string code;
		cin >> code;


		clsCurrency NewCurrency = clsCurrency::FindByCode(code);

		while (NewCurrency.IsEmpty())
		{
			cout << "\n\nInvalid code, please try again\n";

			cin >> code;
			NewCurrency = clsCurrency::FindByCode(code);
		}

		cout << "\n";
		return NewCurrency;
	}


	static int _AskUserForAmount()
	{
		int Amount;

		cout << "\nEnter amount to exchange: ";
		cin >> Amount;

		cout << "\n";
		return Amount;
	}


	static void _CalculateCurrency()
	{
		clsCurrency Currency1 = _AskUserForCurrency("\nPlease enter currency1 code");

		clsCurrency Currency2 = _AskUserForCurrency("\nPlease enter currency2 code");



		double Amount = _AskUserForAmount();

		double FinalAmount = clsCurrency::CurrencyExchangeCalculator(Currency1, Currency2, Amount);

		cout << "\n" << Amount << " " << Currency1.GetCode() << " = " << FinalAmount << " " << Currency2.GetCode() << "\n";
	}



public:

	static void ShowCurrencyCalculator()
	{
		_DrawScreenHeader("\tCurrency calculator screen");
		_CalculateCurrency();
	}



};

