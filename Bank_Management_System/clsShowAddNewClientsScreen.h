#pragma once
#include <iostream>
#include"clsBankClient.h" 
#include "clsScreen.h"
#include "clsInputValidate.h"

using namespace std;




class clsShowAddNewClientsScreen :protected clsScreen
{

	static void _ReadClientInfo(clsBankClient& Client) {



		cout << "\n\nEnter FirstName? ";
		Client.FirstName = clsInputValidate::ReadString();

		cout << "Enter LastName? ";
		Client.LastName = clsInputValidate::ReadString();

		cout << "Enter Email? ";
		Client.Email = clsInputValidate::ReadString();

		cout << "Enter Phone? ";
		Client.Phone = clsInputValidate::ReadString();

		cout << "Enter PinCode? ";
		Client.PinCode = clsInputValidate::ReadString();

		cout << "Enter AccountBalance? ";
		Client.AccountBalance = clsInputValidate::ReadFltNumber();




	}
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


	static void ShowAddNewClient() {


		if (!CheckAccessRights(clsUser::enMainMenuePermissions::pAddNewClient)) {
			return;
		}


		_DrawScreenHeader("\tAdd New Client Screen");

		cout << "Please Enter Client Account Number : \n";
		string AccountNumber = clsInputValidate::ReadString();

		while (clsBankClient::IsClientExist(AccountNumber)) {

			cout << "Account number is alrady exist,Please Enter Anather Account : ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);

		_ReadClientInfo(NewClient);

		clsBankClient::enSaveResults SaveResult;
		SaveResult = NewClient.Save();

		switch (SaveResult)
		{

		case clsBankClient::enSaveResults::svFaildEmptyObject:
			cout << "Error Account was not saved because it's empty :-(\n";
			
			break;

		case clsBankClient::enSaveResults::svSucceeded:
			cout << "\nAccount Added Successfully :-)\n";
			_PrintClinet(NewClient);
			break;

		case clsBankClient::enSaveResults::svAccountNumberExists:
			cout << "\nFaild ! Account number is alrady exist\n";
			break;
		}



	}


};