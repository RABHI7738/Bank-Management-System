#pragma once
#include <iostream>
#include <string>
#include "clsPerson.h"
#include "clsString.h"
#include <vector>
#include <fstream>
#include "clsDate.h"
#include "clsUtil.h"
using namespace std;
class clsUser : public clsPerson
{
private:

    enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };
    enMode _Mode;
    string _UserName;
    string _Password;
    int _Permissions;

    bool _MarkedForDelete = false;


    struct stTransferLogRegisterRecord;
    static  stTransferLogRegisterRecord _ConvertLoginRegisterLineToRecord(string Line, string Separator = "#//#")
    {
        stTransferLogRegisterRecord TransferLogRegisterRecord;

        vector<string> vUserData = clsString::Split(Line, Separator);

        TransferLogRegisterRecord.DateTime = vUserData[0];
        TransferLogRegisterRecord.SourceClientAccountNumber = vUserData[1];
        TransferLogRegisterRecord.DestinationClientAccountNumber = vUserData[2];
        TransferLogRegisterRecord.Amount = stoi(vUserData[3]);
        TransferLogRegisterRecord.SourceClientBalance = stoi(vUserData[4]);
        TransferLogRegisterRecord.DestinationClientBalance = stoi(vUserData[5]);
        TransferLogRegisterRecord.User = vUserData[5];


        return TransferLogRegisterRecord;

    }
    struct stLoginRegisterRecord;
    static  stLoginRegisterRecord _ConvertLoginRegisterLinetoRecord(string Line, string Separator = "#//#")
    {
        stLoginRegisterRecord LoginRegisterRecord;

        vector<string> vUserData = clsString::Split(Line, Separator);

        LoginRegisterRecord.DateTime = vUserData[0];
        LoginRegisterRecord.UserName = vUserData[1];
        LoginRegisterRecord.Password = clsUtil::DecryptText(vUserData[2],323);
        LoginRegisterRecord.Permission = stoi(vUserData[3]);
        return LoginRegisterRecord;

    }

    string _PreparLogInRecord(string Separator = "#//#") {

        string UserRecord = "";
        UserRecord += clsDate::GetSystemDateTimeString() + Separator;
        UserRecord += UserName + Separator;
        UserRecord += clsUtil::EncryptText(Password,323) + Separator;
        UserRecord += to_string(Permissions);

        return UserRecord;

    }
    

  

  
  


    static clsUser _ConvertLinetoUserObject(string Line, string Seperator = "#//#")
    {
        vector<string> vUserData;
        vUserData = clsString::Split(Line, Seperator);

        return clsUser(enMode::UpdateMode, vUserData[0], vUserData[1], vUserData[2],
            vUserData[3], vUserData[4], clsUtil::DecryptText(vUserData[5],323), stoi(vUserData[6]));

    }

    static string _ConverUserObjectToLine(clsUser User, string Seperator = "#//#")
    {

        string UserRecord = "";
        UserRecord += User.FirstName + Seperator;
        UserRecord += User.LastName + Seperator;
        UserRecord += User.Phone + Seperator;
        UserRecord += User.Email + Seperator;
        UserRecord += User.UserName + Seperator;
        UserRecord += clsUtil::EncryptText(User.Password,323) + Seperator;
        UserRecord += to_string(User.Permissions);

        return UserRecord;

    }
    


    

    static  vector <clsUser> _LoadUsersDataFromFile()
    {

        vector <clsUser> vUsers;

        fstream MyFile;
        MyFile.open("Users.txt", ios::in);

        if (MyFile.is_open())
        {

            string Line;


            while (getline(MyFile, Line))
            {

                clsUser User = _ConvertLinetoUserObject(Line);

                vUsers.push_back(User);
            }

            MyFile.close();

        }

        return vUsers;

    }

    static void _SaveUsersDataToFile(vector <clsUser> vUsers)
    {

        fstream MyFile;
        MyFile.open("Users.txt", ios::out);

        string DataLine;

        if (MyFile.is_open())
        {

            for (clsUser U : vUsers)
            {
                if (U.MarkedForDeleted() == false)
                {
                   
                    DataLine = _ConverUserObjectToLine(U);
                    MyFile << DataLine << endl;

                }

            }

            MyFile.close();

        }

    }

    void _Update()
    {
        vector <clsUser> _vUsers;
        _vUsers = _LoadUsersDataFromFile();

        for (clsUser& U : _vUsers)
        {
            if (U.UserName == UserName)
            {
                U = *this;
                break;
            }

        }

        _SaveUsersDataToFile(_vUsers);

    }

    void _AddNew()
    {

        _AddDataLineToFile(_ConverUserObjectToLine(*this));
    }

    void _AddDataLineToFile(string  stDataLine)
    {
        fstream MyFile;
        MyFile.open("Users.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {

            MyFile << stDataLine << endl;

            MyFile.close();
        }

    }

    static clsUser _GetEmptyUserObject()
    {
        return clsUser(enMode::EmptyMode, "", "", "", "", "", "", 0);
    }

public:

    clsUser(enMode Mode, string FirstName, string LastName,  string Email, string Phone, string UserName, string Password,  int Permissions) :
        clsPerson(FirstName, LastName, Email, Phone )

    {
        _Mode = Mode;
        _UserName = UserName;
        _Password = Password;
        _Permissions = Permissions;
    }


    static enum enMainMenuePermissions {
        eAll = -1, pListClients = 1, pAddNewClient = 2, pDeleteClient = 4,
        pUpdateClients = 8, pFindClient = 16, pTranactions = 32, pManageUsers = 64, pLoginRegister = 128
    };


    bool IsEmpty()
    {
        return (_Mode == enMode::EmptyMode);
    }

    bool MarkedForDeleted()
    {
        return _MarkedForDelete;
    }

    string GetUserName()
    {
        return _UserName;
    }

    void SetUserName(string UserName)
    {
        _UserName = UserName;
    }

    __declspec(property(get = GetUserName, put = SetUserName)) string UserName;

    void SetPassword(string Password)
    {
        _Password = Password;
    }

    string GetPassword()
    {
        return _Password;
    }
    __declspec(property(get = GetPassword, put = SetPassword)) string Password;

    void SetPermissions(int Permissions)
    {
        _Permissions = Permissions;
    }

    int GetPermissions()
    {
        return _Permissions;
    }
    __declspec(property(get = GetPermissions, put = SetPermissions)) int Permissions;

    static clsUser Find(string UserName)
    {
        fstream MyFile;
        MyFile.open("Users.txt", ios::in);

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsUser User = _ConvertLinetoUserObject(Line);
                if (User.UserName == UserName)
                {
                    MyFile.close();
                    return User;
                }
            }

            MyFile.close();

        }

        return _GetEmptyUserObject();
    }

    static clsUser Find(string UserName, string Password)
    {

        fstream MyFile;
        MyFile.open("Users.txt", ios::in);

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsUser User = _ConvertLinetoUserObject(Line);
                if (User.UserName == UserName && User.Password == Password)
                {
                    MyFile.close();
                    return User;
                }

            }

            MyFile.close();

        }
        return _GetEmptyUserObject();
    }

    enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildUserExists = 2 };

    enSaveResults Save()
    {

        switch (_Mode)
        {
        case enMode::EmptyMode:
        {
            if (IsEmpty())
            {
                return enSaveResults::svFaildEmptyObject;
            }
        }

        case enMode::UpdateMode:
        {
            _Update();
            return enSaveResults::svSucceeded;

            break;
        }

        case enMode::AddNewMode:
        {
            //This will add new record to file or database
            if (clsUser::IsUserExist(_UserName))
            {
                return enSaveResults::svFaildUserExists;
            }
            else
            {
                _AddNew();
                //We need to set the mode to update after add new
                _Mode = enMode::UpdateMode;
                return enSaveResults::svSucceeded;
            }

            break;
        }
        }

    }

    static bool IsUserExist(string UserName)
    {

        clsUser User = clsUser::Find(UserName);
        return (!User.IsEmpty());
    }

    bool Delete()
    {
        vector <clsUser> _vUsers;
        _vUsers = _LoadUsersDataFromFile();

        for (clsUser& U : _vUsers)
        {
            if (U.UserName == _UserName)
            {
                U._MarkedForDelete = true;
                break;
            }

        }

        _SaveUsersDataToFile(_vUsers);

        *this = _GetEmptyUserObject();
        
        return true;

    }

    static clsUser GetAddNewUserObject(string UserName)
    {
        return clsUser(enMode::AddNewMode, "", "", "", "", UserName, "", 0);
    }

    static vector <clsUser> GetUsersList()
    {
        return _LoadUsersDataFromFile();
    }
   

     bool CheckAccessPermission(enMainMenuePermissions Permission)
    {
        if (this->Permissions == enMainMenuePermissions::eAll)
            return true;

        if ((Permission & this->Permissions) == Permission)
            return true;
        else
            return false;

    }



      void RegisterLogIn() {

          string stDataLine = _PreparLogInRecord();

          fstream MyFile;
          MyFile.open("LoginRegister.txt", ios::out | ios::app);

          if (MyFile.is_open())
          {

              MyFile << stDataLine << endl;

              MyFile.close();
          }
     }


      struct stTransferLogRegisterRecord {
          string DateTime;
          string SourceClientAccountNumber;
          string DestinationClientAccountNumber;
          float Amount;
          float SourceClientBalance;
          float DestinationClientBalance;
          string User;
      };
      static  vector <stTransferLogRegisterRecord> GetLogTransferRegisterList() {
          
          vector <stTransferLogRegisterRecord> vTransferLogRegisterRecord;
          fstream MyFile;
          MyFile.open("TransferLog.txt", ios::in);//read Mode

          if (MyFile.is_open())
          {

              string Line;
              stTransferLogRegisterRecord TransferLogRegisterRecord;

              while (getline(MyFile, Line))
              {

                  TransferLogRegisterRecord = _ConvertLoginRegisterLineToRecord(Line);

                  vTransferLogRegisterRecord.push_back(TransferLogRegisterRecord);
              }

              MyFile.close();

          }

          return vTransferLogRegisterRecord;
      
      }
     

      struct stLoginRegisterRecord {
          string DateTime;
          string UserName;
          string Password;
          int Permission;

      };
      static  vector <stLoginRegisterRecord> GetLoginRegisterList() {

          vector <stLoginRegisterRecord> vLoginRegisterRecord;

          fstream MyFile;
          MyFile.open("LoginRegister.txt", ios::in);//read Mode

          if (MyFile.is_open())
          {

              string Line;
              stLoginRegisterRecord LoginRegisterRecord;

              while (getline(MyFile, Line))
              {  

                  LoginRegisterRecord = _ConvertLoginRegisterLinetoRecord(Line);

                  vLoginRegisterRecord.push_back(LoginRegisterRecord);
              }

              MyFile.close();

          }

          return vLoginRegisterRecord;
      }

      


};

