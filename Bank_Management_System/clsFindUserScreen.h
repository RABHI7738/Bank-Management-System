#pragma once
#include <iostream>
#include"clsUser.h"
#include "clsScreen.h"
#include "clsInputValidate.h"


using namespace std;

class clsFindUserScreen :protected clsScreen
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
		cout << "UserName    : " << User.UserName << endl;
		cout << "Permission  : " << User.Permissions;
		cout << "\n_____________________________\n";
	}


public:

	static void ShowFindUserScreen() {

		_DrawScreenHeader("\tFind User Screen");


		cout << "Please Enter UserName : \n";
		string UserName = clsInputValidate::ReadString();

		while (!clsUser::IsUserExist(UserName)) {

			cout << "UserName is not found, Choose Another One : ";
			UserName = clsInputValidate::ReadString();
		}

		clsUser User = clsUser::Find(UserName);

		if (!User.IsEmpty()) {
			cout << "\nUser Found :-)\n";
		}
		else {
			cout << "\nUser was not Found :-( \n";
		}


		_PrintUser(User);

	}



};

