#pragma once
#include "clsScreen.h"
#include "clsListCurrenciesScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateCurrencyScreen.h"
#include "clsCurrencyCalculatorScreen.h"

class clsCurrencyMenuScreen : protected clsScreen
{
private:

	enum enMenuOptions
	{
		elistCurrencies = 1,
		eFindCurrency = 2,
		eUpdateRate = 3,
		eCurrencyCalcualtor = 4

	};

#pragma region Helper fucntions


	static void _ClearScreen()
	{
		system("cls");
	}


	static void _GoToMainMenuScreen()
	{
		cout << ("\n\nPress any key to go back to currency menu...\t");
		system("pause > 0");
	}


#pragma region Side functions

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



#pragma endregion


#pragma region Main functions

	static void _ShowListCurrenciesScreen()
	{
		clsListCurrenciesScreen::ShowListCurrenciesScreen();
	}


	static void _ShowFindCurrencyScreen()
	{
		clsFindCurrencyScreen::ShowFindCurrencyScreen();
	}


	static void _ShowUpdateRateScreen()
	{
		clsUpdateCurrencyScreen::ShowUpdateCurrencyScreen();
	}


	static void _ShowCurrencyCalcualtorScreen()
	{
		do
		{
			_ClearScreen();
			clsCurrencyCalculatorScreen::ShowCurrencyCalculator();
		} while (ReadAnswerYesOrNO("\nDo you want to perform another calculation y/n ?"));
		
	}


	static short _ReadUserOptionForMenu()
	{
		cout << setw(40) << left << "" << "What do you want to do ? [1,4]? ";

		short Option = ReadShortNumberBetween(1, 4);

		return Option;
	}


	static void _ApplyUserOption(enMenuOptions Option)
	{

		switch (Option)
		{
			

			case(enMenuOptions::elistCurrencies):
			{
				_ClearScreen();
				_ShowListCurrenciesScreen();
				_GoToMainMenuScreen();

				break;
			}
			case(enMenuOptions::eFindCurrency):
			{
				_ClearScreen();
				_ShowFindCurrencyScreen();
				_GoToMainMenuScreen();

				break;

			}
			case(enMenuOptions::eUpdateRate):
			{
				_ClearScreen();
				_ShowUpdateRateScreen();
				_GoToMainMenuScreen();

				break;

			}
			case(enMenuOptions::eCurrencyCalcualtor):
			{
				_ShowCurrencyCalcualtorScreen();
				_GoToMainMenuScreen();
				break;

			}
		}

	}


	static void _PrintMenuItems()
	{
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] List currencies.\n";
		cout << setw(37) << left << "" << "\t[2] Find currency.\n";
		cout << setw(37) << left << "" << "\t[3] Update rate\n";
		cout << setw(37) << left << "" << "\t[4] Currency calculator\n";
		cout << setw(37) << left << "" << "===========================================\n";
	}


#pragma endregion




public:

	static void ShowMenuScreen()
	{
		_ClearScreen();
		_DrawScreenHeader("\t\tCurrency Menu");
		_PrintMenuItems();
		_ApplyUserOption((enMenuOptions)_ReadUserOptionForMenu());
	}



};

