#pragma once

#include <iostream>
#include "clsScreen.h"
#include <iomanip>
#include "clsInputValidate.h"
#include "clsBankClient.h"

using namespace std;

class clsDepositScreen :protected clsScreen
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
    static string _ReadAccountNumber() {
        cout << "Please Enter Client Account Number : \n";
        return clsInputValidate::ReadString();  
    }


public:

    static void ShowDepositScreen() {
        _DrawScreenHeader("\tDeposit Screen");

        string AccountNumber = _ReadAccountNumber();

        while (!clsBankClient::IsClientExist(AccountNumber)) {

            cout << "Account number with [ " << AccountNumber << " ] Not Found Choose Another One :\n";
            AccountNumber = _ReadAccountNumber();
        }

        clsBankClient Client = clsBankClient::Find(AccountNumber);
        _PrintClinet(Client);

        double Amount = 0;
        cout << "\nPlease enter deposit amount? ";
        Amount = clsInputValidate::ReadDblNumber();


        char Answer = 'n';
        cout << "\n\nAre you sure you want performe this transaction? y/n ? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Client.Deposit(Amount);
            cout << "Amount Deposited Successfully.\n";
            cout << "New Balance Is : " << Client.AccountBalance << endl;

        }
        else {
            cout << "Operation Was Cancelled.\n";
        }
    }

};