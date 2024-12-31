#pragma once

#include <iostream>
#include"clsUser.h"
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"


using namespace std;


class clsDeleteUser :protected clsScreen
{

private:

	static void _PrintUser(clsUser User) {

		cout << endl << "Client Card : \n";
		cout << "_____________________________\n";
		cout << "FirstName   : " << User.FirstName << endl;
		cout << "LastName    : " << User.LastName << endl;
		cout << "Full Name   : " << User.FullName() << endl;
		cout << "Email       : " << User.Email << endl;
		cout << "Phone       : " << User.Phone << endl;
		cout << "Password    : " << User.Password << endl;
		cout << "UserName : " << User.UserName << endl;
		cout << "Permission : " << User.Permissions;
		cout << "\n_____________________________\n";
	}

public:

	static void ShowDeleteUserScreen() {

		_DrawScreenHeader("\tDelete User Screen ");


		cout << "Please Enter Client UserName : \n";
		string AccountNumber = clsInputValidate::ReadString();
		while (!clsUser::IsUserExist(AccountNumber)) {

			cout << "UserName is not found, choose another one : ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsUser Client = clsUser::Find(AccountNumber);
		_PrintUser(Client);


		char Answer = 'Y';
		cout << "\n\nAre you sure you want delete this User? y/n ? ";
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y') {

			if (Client.Delete()) {
				_PrintUser(Client);
				cout << "\n\nUser Deleted Successfully :-)";
			}
			else {
				cout << "Error User Was Not Deleted :-(";
			}

		}
	}


};

