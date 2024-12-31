#pragma once
#include <iostream>
#include "Global.h"
#include "clsUser.h"
#include "clsDate.h"

using namespace std;


class clsScreen
{


protected:

	static void _DrawScreenHeader(string Title, string SubTitle ="") {

		clsDate Date = clsDate::GetSystemDateTimeString();


		cout << "\t\t\t\t\t_____________________________________\n";
		cout << "\n\t\t\t\t\t" << Title;


		if (SubTitle != "") {
			cout << "\n\t\t\t\t\t   " << SubTitle;
		}

		cout << "\n\t\t\t\t\t_____________________________________\n\n";


		
			cout << "\n\t\t\t\t\tUser : " << CurrentUser.UserName << endl;
		
			cout << "\t\t\t\t\tDate : " << clsDate::DateToString(clsDate()) << endl << endl;

		
	}

	static bool CheckAccessRights(clsUser::enMainMenuePermissions Permission) {

		if (!CurrentUser.CheckAccessPermission(Permission))
		{
			system("cls");
			cout << "\t\t\t\t\t_____________________________________";
			cout << "\n\n\t\t\t\t\t  Access Denied! Contact your Admin.";
			cout << "\n\t\t\t\t\t_____________________________________\n";

			return false;
		}
		else {
			return true;
		}
	}






};

