#pragma once
#include <iostream>
#include "clsScreen.h"
#include <iomanip>
#include "clsInputValidate.h"
#include "clsMainScreen.h"
#include "clsDepositScreen.h"
#include "clsWithDraw.h"
#include "clsTotalBalancesScreen.h"
#include "clsTransferScreen.h"
#include "clsTransferLogScreen.h"

using namespace std;



class clsTransanctionsMenue:protected clsScreen
{
private:
	enum _enTransactionsMenueOptions { eDeposit = 1, eWithdraw = 2, eShowTotalBalance = 3, eTransfer = 4, eTransferLog = 5, eShowMainMenue = 6 };
    static short _ReadTransactionsMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";

        short Choice = 0;
        Choice = clsInputValidate::ReadIntNumberBetween(1, 6, "Enter Number Between 1 and 6\n");

        return Choice;
    }

    static void _GoBackToTransactionsMenue()
    {
        cout << "\n\nPress any key to go back to Transactions Menue...";
        system("pause>0");
        clsTransanctionsMenue::ShowTransactionsMenue();

    }

    static void _ShowDepositScreen() {
        clsDepositScreen::ShowDepositScreen();

    }
    static void _ShowWithDrawScreen() {
        clsWithDraw::ShowWithDrawScreen();

    }
    static void _ShowTotalBalancesScreen() {
        clsTotalBalancesScreen::ShowTotalBalancesScreen();

    }
    static void _ShowTransferScreen() {
        clsTransferScreen::ShowTransferScreen();

    }
    static void _ShowTransferLogRegisterListScreen() {
        clsTransferLogScreen::ShowTransferLogRegisterListScreen();

    }


    static void _PerformeTransactionsMenueOption(_enTransactionsMenueOptions TransactionsMenueOption) {

        switch (TransactionsMenueOption)
        {
        case _enTransactionsMenueOptions::eDeposit:
        {
            system("cls");
            _ShowDepositScreen();
            _GoBackToTransactionsMenue();
            break;
        }
        case _enTransactionsMenueOptions::eWithdraw:
            system("cls");
            _ShowWithDrawScreen();
            _GoBackToTransactionsMenue();
            break;

        case _enTransactionsMenueOptions::eShowTotalBalance:
            system("cls");
            _ShowTotalBalancesScreen();
            _GoBackToTransactionsMenue();
            break;


        case _enTransactionsMenueOptions::eTransfer:
            system("cls");
            _ShowTransferScreen();
            _GoBackToTransactionsMenue();

            break;

        case _enTransactionsMenueOptions::eTransferLog:
            system("cls");
            _ShowTransferLogRegisterListScreen();
            _GoBackToTransactionsMenue();
            break;

        case _enTransactionsMenueOptions::eShowMainMenue:
            system("cls");
            break;

        }
    }





public:

    static void ShowTransactionsMenue()
    {

        if (!CheckAccessRights(clsUser::enMainMenuePermissions::pTranactions)) {
            return;//this will exit the function and it will not
        }

        system("cls");

        _DrawScreenHeader("\tTransactions Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\tTransactions Menue Screen\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Deposit.\n";
        cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
        cout << setw(37) << left << "" << "\t[3] Show Total Balance.\n";
        cout << setw(37) << left << "" << "\t[4] Transfer.\n";
        cout << setw(37) << left << "" << "\t[5] Transfer Log.\n";
        cout << setw(37) << left << "" << "\t[6] Show Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";


        _PerformeTransactionsMenueOption((_enTransactionsMenueOptions)_ReadTransactionsMenueOption());
    }






};

