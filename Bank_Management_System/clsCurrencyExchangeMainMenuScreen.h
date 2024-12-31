
#pragma once
#include <iostream>
#include "clsScreen.h"
#include <iomanip>
#include "clsInputValidate.h"
#include "clsCurrenciesListScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateCurrencyRateScreen.h"
#include "clsCurrencyCalculatorScreen.h"



using namespace std;


class clsCurrencyExchangeMainMenuScreen:protected clsScreen
{

private:
    enum _enCurrencyExchangeMainMenueOptions {
        eListCurrencies = 1, eFindCurrency = 2, eUpdateRate = 3,
        eCurrencyCalculator = 4, eMainMenue = 5
       
    };
    static short _ReadCurrencyExchangeMainMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]? ";

        short Choice = 0;
        Choice = clsInputValidate::ReadIntNumberBetween(1, 5, "Enter Number Between 1 and 5\n");

        return Choice;
    }

    static void _GoBackToCurrencyExchangeMenue()
    {
        cout << "\n\nPress any key to go back to Currency Exchange Menue...";
        system("pause>0");
        ShowCurrencyExchangeMainScreen();
    }

    static void _ShowListCurrenciesScreen() {
        clsCurrenciesListScreen::ShowCurrenciesListScreen();
    }
    static void _ShowFindCurrencyScreen() {
        clsFindCurrencyScreen::ShowFindUserScreen();
    }
    static void _ShowUpdateRateScreen() {
        clsUpdateCurrencyRateScreen::ShowUpdateCurrencyRateScreen();
    }
    static void _ShowCurrencyCalculatorScreen() {
        clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
    }


    static void _PerformeCurrencyExchangeMenueOption(_enCurrencyExchangeMainMenueOptions CurrencyExchangeMainMenueOptions)
    {
        switch (CurrencyExchangeMainMenueOptions)
        {
        case _enCurrencyExchangeMainMenueOptions::eListCurrencies:
        {
            system("cls");
            _ShowListCurrenciesScreen();
            _GoBackToCurrencyExchangeMenue();
            break;
        }

        case _enCurrencyExchangeMainMenueOptions::eFindCurrency:
        {
            system("cls");
            _ShowFindCurrencyScreen();
            _GoBackToCurrencyExchangeMenue();
            break;
        }

        case _enCurrencyExchangeMainMenueOptions::eUpdateRate:
        {
            system("cls");
            _ShowUpdateRateScreen();
            _GoBackToCurrencyExchangeMenue();
            break;
        }

        case _enCurrencyExchangeMainMenueOptions::eCurrencyCalculator:
        {
            system("cls");
            _ShowCurrencyCalculatorScreen();
            _GoBackToCurrencyExchangeMenue();
            break;
        }

        case _enCurrencyExchangeMainMenueOptions::eMainMenue:
        {
   
            break;
        }
        }
    }

public:

    static void ShowCurrencyExchangeMainScreen()
    {

        system("cls");

        _DrawScreenHeader("\tCurrency Exchange Main Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\tCurrency Exchange Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
        cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
        cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
        cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
        cout << setw(37) << left << "" << "\t[5] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformeCurrencyExchangeMenueOption((_enCurrencyExchangeMainMenueOptions)_ReadCurrencyExchangeMainMenueOption());

    }



};

