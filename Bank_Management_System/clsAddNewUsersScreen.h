#pragma once
#include <iostream>
#include"clsUser.h"
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"

using namespace std;



class clsAddNewUsersScreen :protected clsScreen
{

private:


	static int ReadPermissionsToSet()
{

    int Permissions = 0;
    char Answer = 'n';


    cout << "\nDo you want to give full access? y/n? ";
    cin >> Answer;
    if (Answer == 'y' || Answer == 'Y')
    {
        return -1;
    }

    cout << "\nDo you want to give access to : \n ";

    cout << "\nShow Client List? y/n? ";
    cin >> Answer;
    if (Answer == 'y' || Answer == 'Y')
    {
        Permissions += clsUser::enMainMenuePermissions::pListClients;
    }


    cout << "\nAdd New Client? y/n? ";
    cin >> Answer;
    if (Answer == 'y' || Answer == 'Y')
    {
        Permissions += clsUser::enMainMenuePermissions::pAddNewClient;
    }

    cout << "\nDelete Client? y/n? ";
    cin >> Answer;
    if (Answer == 'y' || Answer == 'Y')
    {
        Permissions += clsUser::enMainMenuePermissions::pDeleteClient;
    }

    cout << "\nUpdate Client? y/n? ";
    cin >> Answer;
    if (Answer == 'y' || Answer == 'Y')
    {
        Permissions += clsUser::enMainMenuePermissions::pUpdateClients;
    }

    cout << "\nFind Client? y/n? ";
    cin >> Answer;
    if (Answer == 'y' || Answer == 'Y')
    {
        Permissions += clsUser::enMainMenuePermissions::pFindClient;
    }

    cout << "\nTransactions? y/n? ";
    cin >> Answer;
    if (Answer == 'y' || Answer == 'Y')
    {
        Permissions += clsUser::enMainMenuePermissions::pTranactions;
    }

    cout << "\nManage Users? y/n? ";
    cin >> Answer;
    if (Answer == 'y' || Answer == 'Y')
    {
        Permissions += clsUser::enMainMenuePermissions::pManageUsers;
    }

    cout << "\nShow Login Register? y/n? ";
    cin >> Answer;
    if (Answer == 'y' || Answer == 'Y')
    {
        Permissions += clsUser::enMainMenuePermissions::pLoginRegister;
    }


    return Permissions;

}
	static void _ReadUserInfo(clsUser& User) {

		cout << "\n\nEnter FirstName? ";
		User.FirstName = clsInputValidate::ReadString();

		cout << "Enter LastName? ";
		User.LastName = clsInputValidate::ReadString();

		cout << "Enter Email? ";
		User.Email = clsInputValidate::ReadString();

		cout << "Enter Phone? ";
		User.Phone = clsInputValidate::ReadString();

		cout << "Enter Password? ";
		User.Password = clsInputValidate::ReadString();

		cout << "Enter Permissions : \n";
		User.Permissions = ReadPermissionsToSet();

	}
	static void _PrintUser(clsUser User) {

		cout << endl << "Client Card : \n";
		cout << "_____________________________\n";
		cout << "FirstName   : " << User.FirstName << endl;
		cout << "LastName    : " << User.LastName << endl;
		cout << "Full Name   : " << User.FullName() << endl;
		cout << "Email       : " << User.Email << endl;
		cout << "Phone       : " << User.Phone << endl;
		cout << "Password    : " << User.Password << endl;
		cout << "UserName    : " << User.UserName << endl;
		cout << "Permission  : " << User.Permissions;
		cout << "\n_____________________________\n";
	}



public:

	static void ShowAddNewUser() {

		_DrawScreenHeader("\tAdd New Users Screen");

		cout << "Please Enter UserName : \n";
		string UserName = clsInputValidate::ReadString();

		while (clsUser::IsUserExist(UserName)) {

			cout << "UserName is already exist,Please Enter Another One : ";
			UserName = clsInputValidate::ReadString();
		}

		clsUser NewUser = clsUser::GetAddNewUserObject(UserName);

		_ReadUserInfo(NewUser);

		clsUser::enSaveResults SaveResult;
		SaveResult = NewUser.Save();

		switch (SaveResult)
		{

		case clsUser::enSaveResults::svFaildEmptyObject:
			cout << "Error UserName was not saved because it's empty :-(\n";

			break;

		case clsUser::enSaveResults::svSucceeded:
			cout << "\nUser Added Successfully :-)\n";
			_PrintUser(NewUser);
			break;

		case clsUser::enSaveResults::svFaildUserExists:
			cout << "\nFailed ! UserName is already exist\n";
			break;
		}




	};
};
