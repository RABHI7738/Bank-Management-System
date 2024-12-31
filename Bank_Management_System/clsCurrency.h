#pragma once

#include <iostream>
#include<string>
#include "clsString.h"
#include <vector>
#include <fstream>



using namespace std;



class clsCurrency
{

private:

	enum enMode { EmptyMode = 0, UpdateMode = 1 };
	enMode _Mode;

	string _Country;
	string _CurrencyCode;
	string _CurrencyName;
	float _Rate;

	bool _MarkedForDeleted = false;


	static clsCurrency _ConvertLineToCurrencyObject(string Line, string Separator = "#//#")
	{
		vector<string> vCurrencyData;
		vCurrencyData = clsString::Split(Line, Separator);


		return clsCurrency(enMode::UpdateMode, vCurrencyData[0], vCurrencyData[1], vCurrencyData[2], stof(vCurrencyData[3]));
	}

	static string _ConvertCurrencyObjectToLine(clsCurrency Currency, string Separator = "#//#")
	{
        string CurrencyRecord = "";

		CurrencyRecord += Currency.Country() + Separator;
		CurrencyRecord += Currency.CurrencyCode() + Separator;
		CurrencyRecord += Currency.CurrencyName() + Separator;
		CurrencyRecord += to_string(Currency.Rate())+ Separator;


		return CurrencyRecord;

	}

	static  vector <clsCurrency> _LoadCurrencyDataFromFile()
	{

		vector <clsCurrency> vCurrency;

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);

		if (MyFile.is_open())
		{

			string Line;


			while (getline(MyFile, Line))
			{

				clsCurrency Currency = _ConvertLineToCurrencyObject(Line);

				vCurrency.push_back(Currency);
			}

			MyFile.close();

		}

		return vCurrency;

	}

	static void _SaveCurrencyDataToFile(vector <clsCurrency> vCurrency)
	{

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::out);

		string DataLine;

		if (MyFile.is_open())
		{

			for (clsCurrency C : vCurrency)
			{
				if (C.MarkedForDeleted() == false)
				{
					
					DataLine = _ConvertCurrencyObjectToLine(C);
					MyFile << DataLine << endl;

				}

			}

			MyFile.close();

		}

	}

	void _Update()
	{
		vector <clsCurrency> vCurrency;
		vCurrency = _LoadCurrencyDataFromFile();

		for (clsCurrency& U : vCurrency)
		{
			if (U.CurrencyCode() == CurrencyCode())
			{
				U = *this;
				break;
			}
		}
		_SaveCurrencyDataToFile(vCurrency);
	}

    static clsCurrency _GetEmptyCurrencyObject()
		{
			return clsCurrency(enMode::EmptyMode, "", "", "", 0);
		}









	public:

		clsCurrency(enMode Mode, string Country, string CurrencyCode, string CurrencyName, float Rate) {

			_Mode = Mode;
			_Country = Country;
			_CurrencyCode = CurrencyCode;
			_CurrencyName = CurrencyName;
			_Rate = Rate;
		}

		bool MarkedForDeleted()
		{
			return _MarkedForDeleted;
		}


		string Country() {
			return _Country;
		}

		string CurrencyCode() {
			return _CurrencyCode;
		}

		string CurrencyName() {
			return _CurrencyName;
		}

		float Rate() {
			return _Rate;
		}

		void UpdateRate(float NewRate) {
			_Rate = NewRate;
			_Update();
		}

		bool IsEmpty()
		{
			return (_Mode == enMode::EmptyMode);
		}


		static clsCurrency FindByCode(string CurrencyCode)
		{
			CurrencyCode = clsString::UppperAllString(CurrencyCode);


			fstream MyFile;
			MyFile.open("Currencies.txt", ios::in);

			if (MyFile.is_open())
			{
				string Line;
				while (getline(MyFile, Line))
				{
					clsCurrency Currency = _ConvertLineToCurrencyObject(Line);
					if (Currency.CurrencyCode() == CurrencyCode)
					{
						MyFile.close();
						return Currency;
					}
				}

				MyFile.close();

			}

			return _GetEmptyCurrencyObject();
		}
		static clsCurrency FindByCountry(string Country)
		{
			Country = clsString::UppperAllString(Country);

			fstream MyFile;
			MyFile.open("Currencies.txt", ios::in);

			if (MyFile.is_open())
			{
				string Line;
				while (getline(MyFile, Line))
				{
					clsCurrency Currency = _ConvertLineToCurrencyObject(Line);
					if (clsString::UppperAllString(Currency.Country()) == Country)
					{
						MyFile.close();
						return Currency;
					}
				}

				MyFile.close();

			}

			return _GetEmptyCurrencyObject();
		}
		
		static bool IsCurrencyExist(string CurrencyCode) {
			clsCurrency C1 = clsCurrency::FindByCode(CurrencyCode);
			return (!C1.IsEmpty());
		}

		static vector <clsCurrency> GetCurrenciesList() {
			return _LoadCurrencyDataFromFile();
		}

		float ConvertToUSD(float Amount) {

			return (float)(Amount / Rate());
		}

		float ConvertToOtherCurrency(float Amount, clsCurrency Currency2) {

			float AmountUnUSD = ConvertToUSD(Amount);

			if (Currency2.CurrencyCode() == "USD") {
				return AmountUnUSD;
			}
			return (float)(AmountUnUSD)*Currency2.Rate();
		}












	};

