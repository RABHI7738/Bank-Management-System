#pragma once
#include <iostream>
#include "clsScreen.h"
#include <iomanip>
#include "clsUser.h"

using namespace std;





class clsTransferLogScreen :protected clsScreen
{


private:


	static void _PrintTransferLogRegisterRecordLine(clsUser::stTransferLogRegisterRecord TransferLogRegisterRecord) {


		cout << setw(8) << left << "" << "|" << setw(23) << left << TransferLogRegisterRecord.DateTime;
		cout << "|" << setw(8) << left << TransferLogRegisterRecord.SourceClientAccountNumber;
		cout << "|" << setw(8) << left << TransferLogRegisterRecord.DestinationClientAccountNumber;
		cout << "|" << setw(8) << left << TransferLogRegisterRecord.Amount;
		cout << "|" << setw(10) << left << TransferLogRegisterRecord.SourceClientBalance;
		cout << "|" << setw(10) << left << TransferLogRegisterRecord.DestinationClientBalance;
		cout << "|" << setw(8) << left << TransferLogRegisterRecord.User;

}



public:

	static void ShowTransferLogRegisterListScreen()
	{
	


		vector <clsUser::stTransferLogRegisterRecord> vTransferLogRegisterRecord = clsUser::GetLogTransferRegisterList();


		string Title = "\t Transfers Log List Screen \n";
		string SubTitle = "\t   (" + to_string(vTransferLogRegisterRecord.size()) + ") Record(s).";

		_DrawScreenHeader(Title, SubTitle);
		cout << setw(8) << left << "" << "\n\t_________________________________________________________________";
		cout << "_________________________________________\n" << endl;

		cout << setw(8) << left << "" << "|" << left << setw(23) << "Date/Time";
		cout << "|" << left << setw(8) << "s.Acc";
		cout << "|" << left << setw(8) << "d.Acc";
		cout << "|" << left << setw(8) << "Amount";
		cout << "|" << left << setw(10) << "s.Balance";
		cout << "|" << left << setw(10) << "d.Balance";
		cout << "|" << left << setw(8) << "UserName";
		cout << setw(8) << left << "" << "\n\t_________________________________________________________________";
		cout << "_________________________________________\n" << endl;




		if (vTransferLogRegisterRecord.size() == 0)
			cout << "\t\t\t\tNo Users Available In the System!";
		else


			for (clsUser::stTransferLogRegisterRecord Record : vTransferLogRegisterRecord) {
				_PrintTransferLogRegisterRecordLine(Record);
				cout << endl;
			}



		cout << setw(8) << left << "" << "\n\t_________________________________________________________________";
		cout << "_________________________________________\n" << endl;


	}
};