#pragma once
#include"AllNeededLibraries.h"
#include"clsCurrency.h"

class clsListCurrenciesScreen
{
private:


	static void _PrintTableHeader()
	{
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_______________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << left << setw(30) << "Country";
		cout << "| " << left << setw(8) << "Code";
		cout << "| " << left << setw(45) << "Name";
		cout << "| " << left << setw(10) << "Rate/(1$)";
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_______________________________________________\n" << endl;
	}

	static void _PrintRow(clsCurrency Currency)
	{
		cout << setw(8) << left << "" << "| " << setw(30) << left << Currency.GetCountry();
		cout << "| " << setw(8) << left << Currency.GetCode();
		cout << "| " << setw(45) << left << Currency.GetCurrencyName();
		cout << "| " << setw(10) << left << Currency.GetRate();
		cout << "\n";
	}

	static void _PrintFooter()
	{
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_______________________________________________\n" << endl;

	}



	
	static void _PrintRecordsRows()
	{
		vector <clsCurrency> vAllCurrencies = clsCurrency::GetAllCurrencies();

		if (vAllCurrencies.size() == 0)
			cout << "\t\t\t\t There are no currencies available in the system!";
		else
			for (clsCurrency &C : vAllCurrencies)
			{
				_PrintRow(C);		
			}

	}


public:

	static void ShowListCurrenciesScreen()
	{
		_PrintTableHeader();
		_PrintRecordsRows();
		_PrintFooter();
	}

};

