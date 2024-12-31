#pragma once

#include <iostream>
#include"clsBankClient.h"
#include "clsScreen.h"
#include "clsInputValidate.h"


using namespace std;




class clsUpdateClient:protected clsScreen
{
private:

	static void _ReadClientSpecificInfo(clsBankClient& Client) {
		system("cls");
		_DrawScreenHeader("\tUpdate Clinet Screen");

		_PrintClinet(Client);
		short Number = 0;

		cout << "\nUpdate Client Info: \n";
		cout << "___________________\n";

		cout << "===================================\n";
		cout << "\t[1] FirstName.\n";
		cout << "\t[2] LastName.\n";
		cout << "\t[3] Email\n";
		cout << "\t[4] Phone.\n";
		cout << "\t[5] PinCode.\n";
		cout << "\t[6] AccountBalance.\n";
		cout << "===================================\n";

		do {
			cout << "Choose what do you want to change from [1] to [6] : ?\n";
			Number = clsInputValidate::ReadIntNumber();

		} while (Number < 1 || Number > 6);

		switch (Number)
		{
		case 1:
			cout << "\n\nEnter FirstName? ";
			Client.FirstName = clsInputValidate::ReadString();
			break;

		case 2:
			cout << "Enter LastName? ";
			Client.LastName = clsInputValidate::ReadString();
			break;

		case 3:
			cout << "Enter Email? ";
			Client.Email = clsInputValidate::ReadString();
			break;

		case 4:
			cout << "Enter Phone? ";
			Client.Phone = clsInputValidate::ReadString();
			break;

		case 5:
			cout << "Enter PinCode? ";
			Client.PinCode = clsInputValidate::ReadString();
			break;

		case 6:
			cout << "Enter AccountBalance? ";
			Client.AccountBalance = clsInputValidate::ReadFltNumber();
			break;
		}
	}
	static void _ReadClientInfo(clsBankClient& Client) {
		system("cls");

		_DrawScreenHeader("\tUpdate Clinet Screen");
		_PrintClinet(Client);


		cout << "\nUpdate Client Info: \n";
		cout << "___________________ \n";


		cout << "\nEnter FirstName? ";
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
	
	static void ShowUpdateClient() {


		if (!CheckAccessRights(clsUser::enMainMenuePermissions::pUpdateClients)) {
			return;//this will exit the function and it will not
		}

		_DrawScreenHeader("\tUpdate Client Screen");


		cout << "Please Enter Client Account Number : \n";
		string AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber)) {

			cout << "Account number is not found, choose another one : ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);
		system("cls");
		_PrintClinet(Client);
		short Number = 0;
		cout << "\nDo you want to change One Informmation Or More?\n";
		cout << "\n\t[1] One Informmation.\n";
		cout << "\t[2] More.\n";


		cout << "\nPlease choose one?\n";
		Number = clsInputValidate::ReadIntNumberBetween(1, 2);



		char Answer = 'Y';
		cout << "\n\nAre you sure you want to Update this Client? y/n ? ";
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y') {

			(Number == 1) ? _ReadClientSpecificInfo(Client) : _ReadClientInfo(Client);

			system("cls");

			clsBankClient::enSaveResults SaveResult;
			SaveResult = Client.Save();

			switch (SaveResult)
			{

			case clsBankClient::enSaveResults::svFaildEmptyObject:
				cout << "Error Account was not saved because it's empty :-(\n";
				break;

			case clsBankClient::enSaveResults::svSucceeded:
				cout << "\nAccount Updated Successfully :-)\n";
				_PrintClinet(Client);

				break;
			}

			}

	}


};

