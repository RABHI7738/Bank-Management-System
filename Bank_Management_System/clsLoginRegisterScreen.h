#pragma once

#include <iostream>
#include"clsUser.h"
#include "clsScreen.h"
#include <iomanip>


using namespace std;


class clsLoginRegisterScreen :protected clsScreen
{

private:


	static void _PrintLoginRegisterRecordLin(clsUser::stLoginRegisterRecord LoginRegisterRecord){

		

		cout << setw(8) << left << "" << "|" << setw(35) << left << LoginRegisterRecord.DateTime;
		cout << "|" << setw(20) << left <<LoginRegisterRecord.UserName;
		cout << "|" << setw(20) << left <<LoginRegisterRecord.Password;
		cout << "|" << setw(10) << left <<LoginRegisterRecord.Permission;
		
	}



public:

	static void ShowLoginRegisterScreen()
	{
		if (!CheckAccessRights(clsUser::enMainMenuePermissions::pLoginRegister)) {
			return;//this will exit the function and it will not
		}


		vector <clsUser::stLoginRegisterRecord> vLoginRegisterRecord = clsUser::GetLoginRegisterList();
		

	string Title = "\t Login Register List Screen \n";
		string SubTitle = "\t   (" + to_string(vLoginRegisterRecord.size()) + ") Record(s).";

		_DrawScreenHeader(Title, SubTitle);

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		cout << setw(8) << left << "" << "|" << left << setw(35) << "Date/Time";
		cout << "|" << left << setw(20) << "UserName";
		cout << "|" << left << setw(20) << "Password";
		cout << "|" << left << setw(10) << "Permissions";
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		if (vLoginRegisterRecord.size() == 0)
			cout << "\t\t\t\tNo Users Available In the System!";
		else

			
			for (clsUser::stLoginRegisterRecord Record : vLoginRegisterRecord) {
				_PrintLoginRegisterRecordLin(Record);
				cout << endl;
			}


			

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

	}





};

