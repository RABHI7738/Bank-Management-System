



#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>
#include<string>
#include "clsString.h"
#include"clsDate.h"
#include "clsPerson.h"
using namespace std;


class clsBankClient : public clsPerson
{
private:

	enum enMode{  EmptyMode = 0 , UpdateMode = 1, AddNewMode = 2, DeleteClient = 3 };
	enMode _Mode;

	string _AccountNumber;
	string _PinCode;
	float _AccountBalance;
	bool _MarkForDelete = false;

	string _PrepareTransferLogRecord(float Amount, clsBankClient Destination,string UserName, string Separator = "#//#") {

		string UserRecord = "";
		UserRecord += clsDate::GetSystemDateTimeString() + Separator;
		UserRecord += AccountNumber+ Separator;
		UserRecord += Destination.AccountNumber + Separator;
		UserRecord += to_string(Amount) + Separator;
		UserRecord += to_string (AccountBalance) + Separator;
		UserRecord += to_string(Destination.AccountBalance) + Separator;
		UserRecord += UserName;
		return UserRecord;


	}

	void _RegisterTransferLog(float Amount , clsBankClient DestinationClient,string UserName) {

		string stDataLine = _PrepareTransferLogRecord(Amount, DestinationClient, UserName);

		fstream MyFile;
		MyFile.open("TransferLog.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{

			MyFile << stDataLine << endl;

			MyFile.close();
		}
	}

static clsBankClient _ConverLinetoClientObject(string Line, string Seperator = "#//#")
	{
		vector<string> vClientData;

		vClientData = clsString::Split(Line, Seperator);

		return clsBankClient(enMode::UpdateMode,vClientData[0], vClientData[1], vClientData[2], vClientData[3], vClientData[4], vClientData[5], stof(vClientData[6]));
	}
static clsBankClient _GetEmptyClientObject() {
	return clsBankClient(enMode::EmptyMode, " ", " ", " ", " ", " ", " ", 0);
}
static vector <clsBankClient> _LoadCleintsDataFromFile(string FileName)
{

	vector <clsBankClient> vClients;

	fstream MyFile;
	MyFile.open(FileName, ios::in);//read Mode

	if (MyFile.is_open())
	{

		string Line;

		while (getline(MyFile, Line))
		{

			clsBankClient	Client = _ConverLinetoClientObject(Line);

			vClients.push_back(Client);
		}

		MyFile.close();

	}

	return vClients;

}
static string _ConvertClientRecordToLine(clsBankClient Client, string Seperator = "#//#"){

	string stClientRecord = "";

	stClientRecord += Client.FirstName + Seperator;
	stClientRecord += Client.LastName + Seperator;
	stClientRecord += Client.Email + Seperator;
	stClientRecord += Client.Phone + Seperator;
	stClientRecord += Client.PinCode + Seperator;
	stClientRecord += Client.AccountNumber + Seperator;
	stClientRecord += to_string(Client.AccountBalance);

	return stClientRecord;

}
static vector <clsBankClient> _SaveCleintsDataToFile(string FileName, vector <clsBankClient> vClients)
{

	fstream MyFile;
	MyFile.open(FileName, ios::out);

	string DataLine;

	if (MyFile.is_open())
	{

		for (clsBankClient C : vClients)
		{
			if (C.MarkForDelete() == false) {

				DataLine = _ConvertClientRecordToLine(C);
				MyFile << DataLine << endl;
			}
		


		}

		MyFile.close();

	}

	return vClients;

}
static void _AddDataLineToFile(string FileName, string  stDataLine)
{
	fstream MyFile;
	MyFile.open(FileName, ios::out | ios::app);

	if (MyFile.is_open())
	{

		MyFile << stDataLine << endl;

		MyFile.close();
	}

}





void _Update() {

	vector <clsBankClient> _vClient = _LoadCleintsDataFromFile("Clients.txt");

		for (clsBankClient& C : _vClient) {
			if (C.AccountNumber == _AccountNumber) {
				C = *this;
				break;
			}
		}
		_SaveCleintsDataToFile("Clients.txt", _vClient);
}
void _AddNewClient() {

	_AddDataLineToFile("Clients.txt", _ConvertClientRecordToLine(*this));
}



public:
	clsBankClient(enMode Mode,string FirstName, string LastName, string Email, string Phone, string PinCode, string AccountNumber, float AccountBalance) :
    clsPerson(FirstName, LastName, Phone, Email) {
		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_PinCode = PinCode;
		_AccountBalance = AccountBalance;
	}


	void Deposit(double Amount) {
		_AccountBalance += Amount;
		Save();
	}
	void WithDraw(double Amount) {
		_AccountBalance -= Amount;
		Save();
	}

	bool Delete() {
		vector <clsBankClient> _vClients = _LoadCleintsDataFromFile("Clients.txt");

		{
			for (clsBankClient& C : _vClients)
			{
				if (C.AccountNumber == _AccountNumber)
				{
					C._MarkForDelete = true;
					break;
				}
			}
			
		}

		_SaveCleintsDataToFile("Clients.txt", _vClients);
		*this = _GetEmptyClientObject();
		return true;
	}

	bool MarkForDelete() {
		return _MarkForDelete;
	}

	void SetAccountNumber(string AccountNumber) {
		_AccountNumber = AccountNumber;
	}
	string GetAccountNumber() {
		return _AccountNumber;
	}
	__declspec(property(get = GetAccountNumber, put = SetAccountNumber)) string AccountNumber;

	void SetPinCode(string PinCode) {
		_PinCode = PinCode;
	}
	string GetPinCode() {
		return _PinCode;
	}
	__declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;

	void SetAccountBalance(float AccountBalance) {
		_AccountBalance = AccountBalance;
	}
	float GetAccountBalance() {
		return _AccountBalance;
	}
	__declspec(property(get = GetAccountBalance, put = SetAccountBalance)) float AccountBalance;

	 bool IsEmpty() {
		return ( _Mode == enMode::EmptyMode);
}
	
	static clsBankClient Find(string AccountNumber)
	{

		vector <clsBankClient> vClients;

		fstream MyFile;
		string Line;

		MyFile.open("Clients.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{

		
			while (getline(MyFile, Line))
			{

				clsBankClient Client = _ConverLinetoClientObject(Line);
				if (Client.AccountNumber == AccountNumber) {

					MyFile.close();

					return Client;
				}

				vClients.push_back(Client);
			}

			MyFile.close();

		}

		return _GetEmptyClientObject();
		 
	}
	static clsBankClient Find(string AccountNumber, string PinCode)
	{

		vector <clsBankClient> vClients;

		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);

		if (MyFile.is_open())
		{

			string Line;


			while (getline(MyFile, Line))
			{

				clsBankClient Client = _ConverLinetoClientObject(Line);
				if (Client.AccountNumber == AccountNumber && Client.PinCode == PinCode) {

					MyFile.close();

					return Client;
				}

				vClients.push_back(Client);
			}

			MyFile.close();

		}

		return _GetEmptyClientObject();

	}

	void Print() {
		cout << endl << "Client Card : \n";
		cout << "_____________________________\n";
		cout << "FirstName       : " << FirstName << endl;
		cout << "LastName        : " << LastName << endl;
		cout << "Full Name        : " << FullName() << endl;
		cout << "Email          : " << Email << endl;
		cout << "Phone          : " << Phone << endl;
		cout << "PinCode        : " << PinCode << endl;
		cout << "Acc.Number  : " << AccountNumber << endl;
		cout << "Acc.Balance : " << AccountBalance;
		cout << "\n_____________________________\n";


	}

	static bool IsClientExist(string AccountNumber) {
		clsBankClient Client = clsBankClient::Find(AccountNumber);
		return (!Client.IsEmpty());
	}

	static clsBankClient GetAddNewClient(string AccountNumber) {
		return clsBankClient(AddNewMode, " ", " ", " ", " ", " ", AccountNumber, 0);
	}


	enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svAccountNumberExists = 2 };
	 enSaveResults Save() {

		switch (_Mode) {

		case enMode::EmptyMode:
			
			if (IsEmpty())
			{

				return enSaveResults::svFaildEmptyObject;

			}
		case enMode::UpdateMode:

			_Update();


			return enSaveResults::svSucceeded;

		case enMode::AddNewMode:

			_AddNewClient();
			_Mode = enMode::UpdateMode;
			return enSaveResults::svSucceeded;
	
		}

	}
	 	 static clsBankClient GetAddNewClientObject(string AccountNumber)
	 {
		 return clsBankClient(enMode::AddNewMode, "", "", "","","", AccountNumber, 0);
	 }
	 static clsBankClient GetClientObjectForDelete(string AccountNumber)
	 {
		 return clsBankClient(enMode::DeleteClient, "", "", "", "", AccountNumber, "", 0);
	 }

	 static vector < clsBankClient > GetClientList() {

		 return _LoadCleintsDataFromFile("Clients.txt");
	}

	 static double GetTotalBalances() {

		 vector < clsBankClient > _vClient = clsBankClient::GetClientList();
		 double TotalBalances = 0;

		 for (clsBankClient C : _vClient) {
			 TotalBalances += C.AccountBalance;

		 }
		 return TotalBalances;
	 }
	

	 bool Transfer(float Amount, clsBankClient& Destination,string UserName) {

		 if (Amount > AccountBalance) {
			 return false;
		 }

		 WithDraw(Amount);
		 Destination.Deposit(Amount);
		 _RegisterTransferLog(Amount, Destination, UserName);
		 return true;

	 }
















};



















