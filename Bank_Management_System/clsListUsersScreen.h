#pragma once

#include <iostream>
#include"clsUser.h"
#include <iomanip>
#include "clsScreen.h"
#include "clsUtil.h"



using namespace std;


class clsListUsersScreen:protected clsScreen
{

private:

	static void _PrintUserRecordLine(clsUser User)
	{
		cout << setw(8) << left << "" << "|" << setw(12) << left << User.UserName;
		cout << "|" << setw(25) << left << User.FullName();
		cout << "|" << setw(12) << left <<User.Phone;
		cout << "|" << setw(20) << left <<User.Email;
		cout << "|" << setw(10) << left << User.Password, 323;
		cout << "|" << setw(12) << left << User.Permissions;
	}

public:

	static void ShowAllUsersScreen()
	{

	vector <clsUser> vClients = clsUser::GetUsersList();


	string Title = "\t User List Screen \n";
	string SubTitle = "\t   (" + to_string(vClients.size()) + ") User(s).";

	_DrawScreenHeader(Title, SubTitle);

	cout << setw(8) << left << "" << "\n\t_______________________________________________________";
	cout << "_________________________________________\n" << endl;

	cout << setw(8) << left << "" << "|" << left << setw(12) << "UserName";
	cout << "|" << left << setw(25) << "FullName";
	cout << "|" << left << setw(12) << "Phone";
	cout << "|" << left << setw(20) << "Email";
	cout << "|" << left << setw(10) << "Password";
	cout << "|" << left << setw(12) << "Permissions";
	cout << setw(8) << left << "" << "\n\t_______________________________________________________";
	cout << "_________________________________________\n" << endl;

	if (vClients.size() == 0)
		cout << "\t\t\t\tNo Users Available In the System!";
	else

		for (clsUser User : vClients)
		{

			_PrintUserRecordLine(User);
			cout << endl;
		}

	cout << setw(8) << left << "" << "\n\t_______________________________________________________";
	cout << "_________________________________________\n" << endl;


}

};

