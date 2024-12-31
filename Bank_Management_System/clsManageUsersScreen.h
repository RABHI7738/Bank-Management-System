#pragma once
#include <iostream>
#include "clsScreen.h"
#include <iomanip>
#include "clsInputValidate.h"
#include "clsBankClient.h"
#include "clsListUsersScreen.h"
#include "clsAddNewUsersScreen.h"
#include "clsDeleteUser.h"
#include "clsUpdateUserScreen.h"
#include "clsFindUserScreen.h"

using namespace std;


class clsManageUsersScreen:protected clsScreen
{

private:

    enum _enManageUsersMenueOptions {
        eListUsers = 1, eAddNewUser = 2, eDeleteUser = 3,
        eUpdateUser = 4, eFindUser = 5, eMainMenue = 6
    };


    static short _ReadTransactionsMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";

        short Choice = 0;
        Choice = clsInputValidate::ReadIntNumberBetween(1, 6, "Enter Number Between 1 and 6\n");

        return Choice;
    }


    static void _GoBackToManageUsersMenue()
    {
        cout << "\n\nPress any key to go back to Manage Users Menue...";
        system("pause>0");
        clsManageUsersScreen::ShowManageUsersMenue();

    }


   static void _PerformeManageUsersMenueOption(_enManageUsersMenueOptions ManageUsersMenueOption)
    {
        switch (ManageUsersMenueOption)
        {
        case _enManageUsersMenueOptions::eListUsers:
        {
            system("cls");
            clsListUsersScreen::ShowAllUsersScreen();
           _GoBackToManageUsersMenue();
            break;
        }

        case _enManageUsersMenueOptions::eAddNewUser:
        {
            system("cls");
            clsAddNewUsersScreen::ShowAddNewUser();
            _GoBackToManageUsersMenue();
            break;
        }

        case _enManageUsersMenueOptions::eDeleteUser:
        {
            system("cls");
            clsDeleteUser::ShowDeleteUserScreen();
            _GoBackToManageUsersMenue();
            break;
        }

        case _enManageUsersMenueOptions::eUpdateUser:
        {
            system("cls");
            clsUpdateUserScreen::ShowUpdateUser();
            _GoBackToManageUsersMenue();
            break;
        }

        case _enManageUsersMenueOptions::eFindUser:
        {
            system("cls");

            clsFindUserScreen::ShowFindUserScreen();
            _GoBackToManageUsersMenue();
            break;
        }

        case _enManageUsersMenueOptions::eMainMenue:
        {

        }
      }
    }

public:

    static void ShowManageUsersMenue()
    {

        if (!CheckAccessRights(clsUser::enMainMenuePermissions::pManageUsers)) {
            return;//this will exit the function and it will not
        }

        system("cls");

        _DrawScreenHeader("\tManage Users Menue Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\tManage Users Menue Screen\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Users.\n";
        cout << setw(37) << left << "" << "\t[2] Add New User.\n";
        cout << setw(37) << left << "" << "\t[3] Delete User.\n";
        cout << setw(37) << left << "" << "\t[4] Update User.\n";
        cout << setw(37) << left << "" << "\t[5] Find User.\n";
        cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";


        _PerformeManageUsersMenueOption((_enManageUsersMenueOptions)_ReadTransactionsMenueOption());
    }

};

