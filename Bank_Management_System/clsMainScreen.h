#pragma once
#include <iostream>
#include <iomanip>
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsListClientsScreen.h"
#include "clsShowAddNewClientsScreen.h"
#include "clsDeleteClient.h"
#include "clsUpdateClient.h"
#include "clsFindClient.h"
#include "clsTransanctionsMenue.h"
#include "clsManageUsersScreen.h"
#include "Global.h"
#include "clsUser.h"
#include "clsLoginRegisterScreen.h"
#include "clsCurrencyExchangeMainMenuScreen.h"

using namespace std;




class clsMainScreen :protected clsScreen
{
    enum _enMainMenueOptions {
        eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
        eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenue = 6,
        eManageUsers = 7, eLoginRigester = 8, eCurrencyExchange = 9, eExit = 10
    };
   static short _ReadMainMenueOption()
    {
       cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 10]? ";

        short Choice = 0;
        Choice = clsInputValidate::ReadIntNumberBetween(1, 10,"Enter Number Between 1 and 10\n");

        return Choice;
    }
   static void _GoBackToMainMenue()
   {
       cout << setw(37) << left << ""  "\n\tPress any key to go back to Main Menue...";
       system("pause>0");
       ShowMainMenue();
   }

   


   static void _ShowAllClientsScreen() {

       clsListClientsScreen::ShowAllClientsScreen();
   }
   static void _ShowAddNewClientsScreen() {
       clsShowAddNewClientsScreen::ShowAddNewClient();
   }
   static void _ShowDeleteClientScreen() {
       clsDeleteClient::ShowDeleteClient();
   }
   static void _ShowUpdateClientScreen() {
       clsUpdateClient::ShowUpdateClient();
   }
   static void _ShowFindClientScreen() {
       clsFindClient::ShowFindClientScreen();
   }
   static void _ShowTransactionsMenue() {


       clsTransanctionsMenue::ShowTransactionsMenue();
   }
   static void _ShowManageUsersMenue() {
       clsManageUsersScreen::ShowManageUsersMenue(); 
   }
   static void _ShowLoginRegisterScreen() {
       clsLoginRegisterScreen::ShowLoginRegisterScreen();
   }
   static void _ShowCurrencyExchangeMenue() {
       clsCurrencyExchangeMainMenuScreen::ShowCurrencyExchangeMainScreen();
   }
   static void _Logout() {

       clsUser CurrentUser = clsUser::Find("", "");

   }


   static void _PerfromeMainMenueOption(_enMainMenueOptions MainMenueOption) {

       switch (MainMenueOption)
       {
       case _enMainMenueOptions::eListClients:
       {
        
            system("cls");
           _ShowAllClientsScreen();       
           _GoBackToMainMenue();
           break;
       }
       case _enMainMenueOptions::eAddNewClient:
           system("cls");
           _ShowAddNewClientsScreen();
           _GoBackToMainMenue();
           break;

       case _enMainMenueOptions::eDeleteClient:
           system("cls");
           _ShowDeleteClientScreen();
           _GoBackToMainMenue();
           break;

       case _enMainMenueOptions::eUpdateClient:
           system("cls");
           _ShowUpdateClientScreen();
           _GoBackToMainMenue();
           break;

       case _enMainMenueOptions::eFindClient:
           system("cls");
           _ShowFindClientScreen();
           _GoBackToMainMenue();
           break;

       case _enMainMenueOptions::eShowTransactionsMenue:
           system("cls");
           _ShowTransactionsMenue();
           _GoBackToMainMenue();
           break;

       case _enMainMenueOptions::eManageUsers:
           system("cls");
           _ShowManageUsersMenue();
           _GoBackToMainMenue();
           break;

       case _enMainMenueOptions::eLoginRigester:
           system("cls");
           _ShowLoginRegisterScreen();

           _GoBackToMainMenue();
       case _enMainMenueOptions::eCurrencyExchange:
           system("cls");
            _ShowCurrencyExchangeMenue();

           _GoBackToMainMenue();

       case _enMainMenueOptions::eExit:
           system("cls");
           _Logout();


           break;
       }
   }
   

   
 


public:

    static void ShowMainMenue()
    {

        system("cls");

         _DrawScreenHeader("\t\tMain Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\tMain Menue Screen\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
        cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
        cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
        cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
        cout << setw(37) << left << "" << "\t[5] Find Client.\n";
        cout << setw(37) << left << "" << "\t[6] Transactions.\n";
        cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
        cout << setw(37) << left << "" << "\t[8] Login Register.\n";
        cout << setw(37) << left << "" << "\t[9] Currency Exchange.\n";
        cout << setw(37) << left << "" << "\t[10] Logout.\n";
        cout << setw(37) << left << "" << "===========================================\n";


        _PerfromeMainMenueOption((_enMainMenueOptions)_ReadMainMenueOption());
    }



};

