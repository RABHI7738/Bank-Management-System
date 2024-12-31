

#include <iostream>
#include<string>
#include "clsString.h"
#include"clsDate.h"
#include "clsInputValidate.h"
#include "clsUtil.h"
#include "clsPerson.h"
#include"clsBankClient.h"
#include "clsMainScreen.h"
#include "clsLoginScreen.h"
#include "clsAddNewUsersScreen.h"
#include "clsCurrency.h"
#include "clsCurrenciesListScreen.h"

using namespace std;







int main()
{

	
	while (true)
	{
		if (!clsLoginScreen::ShowLoginScreen()) {
			break;
		}

	}










	cout << endl << endl << endl;
	system("pause>0");
	return 0;

}