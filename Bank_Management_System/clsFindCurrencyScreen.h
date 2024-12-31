#pragma once
#include <iostream>
#include"clsCurrency.h"
#include "clsScreen.h"
#include "clsInputValidate.h"


using namespace std;



class clsFindCurrencyScreen :protected clsScreen
{
private:


	static void _PrintCurrency(clsCurrency Currency)
	{
		cout << "\nCurrency Card:\n";
		cout << "_____________________________\n";
		cout << "\nCountry    : " << Currency.Country();
		cout << "\nCode       : " << Currency.CurrencyCode();
		cout << "\nName       : " << Currency.CurrencyName();
		cout << "\nRate(1$) = : " << Currency.Rate();

		cout << "\n_____________________________\n";

	}

	static void _ShowResult(clsCurrency Currency) {
		if (!Currency.IsEmpty()) {
			cout << "\nCurrency Found :-)\n";
			_PrintCurrency(Currency);
		}
		else {
			cout << "\nCurrency Was Not Found :-(\n";
		}
	}

public:

	static void ShowFindUserScreen() {

		_DrawScreenHeader("\tFind Currency Screen");

		cout << "\nFind By : [1] code or [2] Country ?\n";
		short Option = clsInputValidate::ReadShortNumberBetween(1, 2);

		if (Option == 1) {

			cout << "Please Enter Currency code : ";
			string CurrencyCode = clsInputValidate::ReadString();
			clsCurrency CurrencyObject = clsCurrency::FindByCode(CurrencyCode);
			_ShowResult(CurrencyObject);
		}
		else {
			cout << "Please Enter country : ";
			string Country = clsInputValidate::ReadString();
			clsCurrency CurrencyObject = clsCurrency::FindByCountry(Country);
			_ShowResult(CurrencyObject);
		}
		
	}

};

