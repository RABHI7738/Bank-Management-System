#pragma once

#include <iostream>
#include"clsUser.h"
#include "clsScreen.h"
#include "clsInputValidate.h"

using namespace std;


class clsUpdateUserScreen :protected clsScreen
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


		return Permissions;

	}

	static void _ReadClientSpecificInfo(clsUser& User) {
		system("cls");
		_DrawScreenHeader("\tUpdate User Screen");

		_PrintUser(User);
		short Number = 0;

		cout << "\nUpdate User Info: \n";
		cout << "___________________\n";

		cout << "===================================\n";
		cout << "\t[1] FirstName.\n";
		cout << "\t[2] LastName.\n";
		cout << "\t[3] Email\n";
		cout << "\t[4] Phone.\n";
		cout << "\t[5] Password.\n";
		cout << "\t[6] Permission.\n";
		cout << "===================================\n";

		do {
			cout << "Choose what do you want to change from [1] to [6] : ?\n";
			Number = clsInputValidate::ReadIntNumber();

		} while (Number < 1 || Number > 6);

		switch (Number)
		{
		case 1:
			cout << "\n\nEnter FirstName? ";
			User.FirstName = clsInputValidate::ReadString();
			break;

		case 2:
			cout << "Enter LastName? ";
			User.LastName = clsInputValidate::ReadString();
			break;

		case 3:
			cout << "Enter Email? ";
			User.Email = clsInputValidate::ReadString();
			break;

		case 4:
			cout << "Enter Phone? ";
			User.Phone = clsInputValidate::ReadString();
			break;

		case 5:
			cout << "Enter Password? ";
			User.Password = clsInputValidate::ReadString();
			break;

		case 6:
			cout << "Enter Permissions : \n";
			User.Permissions = ReadPermissionsToSet();
			break;
		}
	}
	static void _ReadUserInfo(clsUser& User) {
		system("cls");

		_DrawScreenHeader("\tUpdate User Screen");
		_PrintUser(User);


		cout << "\nUpdate User Info: \n";
		cout << "___________________ \n";


		cout << "\nEnter FirstName? ";
		User.FirstName = clsInputValidate::ReadString();

		cout << "Enter LastName? ";
		User.LastName = clsInputValidate::ReadString();

		cout << "Enter Email? ";
		User.Email = clsInputValidate::ReadString();

		cout << "Enter Phone? ";
		User.Phone = clsInputValidate::ReadString();

		cout << "Enter Password? ";
		User.Password = clsInputValidate::ReadString();

		cout << "Enter Permissions : \n ";
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


		static void ShowUpdateUser() {

			_DrawScreenHeader("\tUpdate User Screen");


			cout << "Please Enter UserName : \n";
			string UserName = clsInputValidate::ReadString();

			while (!clsUser::IsUserExist(UserName)) {

				cout << "UserName is not found, choose another one : ";
				UserName = clsInputValidate::ReadString();
			}

			clsUser User = clsUser::Find(UserName);
			system("cls");
			_PrintUser(User);
			short Number = 0;
			cout << "\nDo you want to change One Information Or More?\n";
			cout << "\n\t[1] One Information.\n";
			cout << "\t[2] More.\n";


			cout << "\nPlease choose one?\n";
			Number = clsInputValidate::ReadIntNumberBetween(1, 2);



			char Answer = 'Y';
			cout << "\n\nAre you sure you want to Update this User? y/n ? ";
			cin >> Answer;

			if (Answer == 'y' || Answer == 'Y') {

				(Number == 1) ? _ReadClientSpecificInfo(User) : _ReadUserInfo(User);

				system("cls");

				clsUser::enSaveResults SaveResult;
				SaveResult = User.Save();

				switch (SaveResult)
				{

				case clsUser::enSaveResults::svFaildEmptyObject:
					cout << "Error Account was not saved because it's empty :-(\n";
					break;

				case clsUser::enSaveResults::svSucceeded:
					cout << "\nAccount Updated Successfully :-)\n";
					_PrintUser(User);

					break;
				}

			}

		}

};

