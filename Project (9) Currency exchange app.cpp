#include "AllNeededLibraries.h"
#include "clsCurrency.h"
#include "clsCurrencyMenuScreen.h"


void PrintCurrency(clsCurrency C)
{

    cout << "\n\n";

    cout << "Country    : " << C.GetCountry() << endl;
    cout << "Code       : " << C.GetCode() << endl;
    cout << "Currency   : " << C.GetCurrencyName() << endl;
    cout << "Rate(1$) = : " << C.GetRate() << endl << endl;

}




int main()
{

   /* clsCurrency C1 = clsCurrency::FindByCode("EgP");
    if (!C1.IsEmpty())
    {
        PrintCurrency(C1);
    }





    clsCurrency C2 = clsCurrency::FindByCode("jod");
    if (!C2.IsEmpty())
    {
        PrintCurrency(C2);
    }


    cout << "AFTER UPDATE";

    C2.UpdateRate(0.701);

    if (!C2.IsEmpty())
    {
        PrintCurrency(C2);
    }*/



    while (true)
    {
        clsCurrencyMenuScreen::ShowMenuScreen();
    }

}

