#pragma once
#include <iostream>
#include"clsBankClient.h"
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsDate.h"
#include <string>

using namespace std;




class clsTransferScreen :protected clsScreen
{

private:


    static void _PrintClient(clsBankClient Client) {

        cout << endl << "Client Card : \n";
        cout << "_____________________________\n";   
        cout << "Full Name   : " << Client.FullName() << endl;
        cout << "Acc.Number  : " << Client.AccountNumber << endl;
        cout << "Acc.Balance : " << Client.AccountBalance;
        cout << "\n_____________________________\n";
    }
    

    static string _ReadAccountNumber(string Message) {

        cout << Message;
        string AccountNumber =  clsInputValidate::ReadString();

        while (!clsBankClient::IsClientExist(AccountNumber)) {

            cout << "Account number with [ " << AccountNumber << " ] Not Found Choose Another One :\n";
            AccountNumber =  clsInputValidate::ReadString();
        }

        
        return AccountNumber;
    }
    static float _ReadAmount() {

    }

public:



	static void ShowTransferScreen() {
        _DrawScreenHeader("\tTransfer Screen");

        clsBankClient SourceClient = clsBankClient::Find(_ReadAccountNumber("\nPlease Enter Account Number To Transfer From : \n"));
        _PrintClient(SourceClient);

        clsBankClient DestinationClient = clsBankClient::Find(_ReadAccountNumber("\nPlease Enter Account Number To Transfer To : \n"));
        _PrintClient(DestinationClient);

        
        float Amount = 0;
       cout << "\nEnter Transfer Amount? ";
       Amount = clsInputValidate::ReadDblNumberBetween(1, SourceClient.AccountBalance,"Amount Exceeds The Available Balance, Enter Another Amount ?");

       char Answer = 'n';
       cout << "\n\nAre you sure you want perform this Operation ? y/n ? ";
       cin >> Answer;
       if (Answer == 'y' || Answer == 'Y')
       {
           if (SourceClient.Transfer(Amount, DestinationClient,CurrentUser.UserName)) {
               cout << "\nTransfer Done Successfully.\n";

               _PrintClient(SourceClient);
               _PrintClient(DestinationClient);
           }
           else {
               cout << "\nTransfer Failed.\n";

           }


       }
       else {
           cout << "Operation Was Cancelled.\n";
       }
    }
	

};

