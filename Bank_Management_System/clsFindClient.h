#pragma once
#include <iostream>
#include"clsBankClient.h"
#include "clsScreen.h"
#include "clsInputValidate.h"


using namespace std;


class clsFindClient:protected clsScreen
{
private:


	static void _PrintClinet(clsBankClient Client) {

		cout << endl << "Client Card : \n";
		cout << "_____________________________\n";
		cout << "FirstName   : " << Client.FirstName << endl;
		cout << "LastName    : " << Client.LastName << endl;
		cout << "Full Name   : " << Client.FullName() << endl;
		cout << "Email       : " << Client.Email << endl;
		cout << "Phone       : " << Client.Phone << endl;
		cout << "Password    : " << Client.PinCode << endl;
		cout << "Acc.Number  : " << Client.AccountNumber << endl;
		cout << "Acc.Balance : " << Client.AccountBalance;
		cout << "\n_____________________________\n";
	}



public:


	static void ShowFindClientScreen(){

		if (!CheckAccessRights(clsUser::enMainMenuePermissions::pFindClient)) {
			return;//this will exit the function and it will not
		}

		_DrawScreenHeader("\tFind Client Screen");


		cout << "Please Enter Client Account Number : \n";
		string AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber)) {

			cout << "Account number is not found, Choose Another One : ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);
		
		if (!Client.IsEmpty()) {
			cout << "\nClient Found :-)\n";
		}
		else {
			cout << "\nClinet was not Found :-( \n";
		}


		_PrintClinet(Client);

	}



};

