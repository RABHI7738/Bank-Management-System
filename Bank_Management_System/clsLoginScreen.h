#pragma once
#include <iostream>
#include"clsUser.h"
#include "clsScreen.h"
#include "clsMainScreen.h"
#include "Global.h"
#include <Windows.h>
#include "clsUtil.h"


using namespace std;


class clsLoginScreen :protected clsScreen
{

private:
    
    static bool _IsPassed() {



        bool LoginFaild = false;
        short FaildLoginCount = 0;

        string Username, Password;

        do
        {



            if (LoginFaild)
            {
                FaildLoginCount++;

                cout << "\nInvalid Username/Password!\n";
            }
            if (FaildLoginCount == 3) {

                for (int i = 60; i >= 1; i--) {
                    system("cls");

                    cout << "\n\n\n\t\t\t\t\t\t ======================\n";
                    cout << "\n\t\t\t\t\t\t     Faild Trails !\n";
                    cout << "\n\t\t\t\t\t\t ======================\n";
                    cout << "\n\t\t\t\t\t\t Wait " << i << " Second(s)";
                    Sleep(100);
                    system("cls");
                    _DrawScreenHeader("\t    Login Screen");

                }

                return false;
            }

            cout << "\nEnter Username? ";
            cin >> Username;

            cout << "Enter Password? ";
            cin >> Password;

            CurrentUser = clsUser::Find(Username, Password);

            LoginFaild = CurrentUser.IsEmpty();



        } while (LoginFaild);
        return true;
    }
    
	static bool _Login()
    {

        if (!_IsPassed()) {



            bool LoginFaild = false;
            short FaildLoginCount = 0;

            string Username, Password;

            do
            {



                if (LoginFaild)
                {
                    FaildLoginCount++;

                    cout << "\nInvalid Username/Password!\n";
                    cout << "You Have " << 3 - FaildLoginCount << " Trails To Login \n";
                }
                if (FaildLoginCount == 3) {
                    cout << "\nYou are locked after 3 failed Trails\n";
                    return false;
                }

                cout << "\nEnter Username? ";
                cin >> Username;

                cout << "Enter Password? ";
                cin >> Password;
                CurrentUser = clsUser::Find(Username, Password);

                LoginFaild = CurrentUser.IsEmpty();



            } while (LoginFaild);
        }
        else {
            CurrentUser.RegisterLogIn();
            clsMainScreen::ShowMainMenue();
            
            return true;
        }

















    }

public:


	static bool ShowLoginScreen() {

        system("cls");
		_DrawScreenHeader("\t    Login Screen");

       return  _Login();
	}

};

