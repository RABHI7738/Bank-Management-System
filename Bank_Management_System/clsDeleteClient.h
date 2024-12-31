#pragma once

#include <iostream>
#include"clsBankClient.h" 
#include "clsScreen.h"
#include "clsInputValidate.h"

using namespace std;

class clsDeleteClient:protected clsScreen
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
	static void ShowDeleteClient() {

		if (!CheckAccessRights(clsUser::enMainMenuePermissions::pDeleteClient)) {
			return;//this will exit the function and it will not
		}

		_DrawScreenHeader("\tDelete Client Screen ");


		cout << "Please Enter Client Account Number : \n";
		string AccountNumber = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(AccountNumber)) {

			cout << "Account number is not found, choose another one : ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);
		_PrintClinet(Client);


		char Answer = 'Y';
		cout << "\n\nAre you sure you want delete this client? y/n ? ";
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y') {

			if (Client.Delete()) {
				_PrintClinet(Client);
				cout << "\n\nClient Deleted Successfully :-)";
			}
			else {
				cout << "Error Client Was Not Deleted :-(";
			}

		}



	}


};

