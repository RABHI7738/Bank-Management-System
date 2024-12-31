#pragma once
#include<iostream>
#include<vector>

using namespace std;
class clsString {
private:

    string _Value;


public:

    clsString() {
        _Value = "";
    }
    clsString(string Value) {

        _Value = Value;
    }

    void SetValue(string Value) {
        _Value = Value;
    }
    string GetValue() {
        return _Value;
    }
    __declspec(property(get = GetValue, put = SetValue))string Value;


    static short Length(string S1) {
        return S1.length();
    }
    short Length() {
        return _Value.length();
    }


    static string UpperFirstLetterOfEachWord(string text) {
        bool IsFirstLetter = true;

        for (int i = 0; i < text.length(); i++) {
            if (text[i] != ' ' && IsFirstLetter) {
                text[i] = toupper(text[i]);
            }
            IsFirstLetter = (text[i] == ' ') ? true : false;
        }
        return text;
    }
    void UpperFirstLetterOfEachWord() {
        _Value = UpperFirstLetterOfEachWord(_Value);
    }


    static string LowerFirstLetterOfEachWord(string text) {
        bool IsFirstLetter = true;

        for (int i = 0; i < text.length(); i++) {
            if (text[i] != ' ' && IsFirstLetter) {
                text[i] = tolower(text[i]);
            }
            IsFirstLetter = (text[i] == ' ') ? true : false;
        }
        return text;
    }
    void LowerFirstLetterOfEachWord() {
        _Value = LowerFirstLetterOfEachWord(_Value);
    }


    static string LowerAllString(string text) {

        for (int i = 0; i <= text.length(); i++) {

            text[i] = tolower(text[i]);
        }
        return text;
    }
    void LowerAllString() {
        _Value = LowerAllString(_Value);
    }


    static string UppperAllString(string text) {

        for (int i = 0; i <= text.length(); i++) {

            text[i] = toupper(text[i]);
        }
        return text;
    }
    void UppperAllString() {
        _Value = UppperAllString(_Value);
    }


    static char InversCharacter(char character) {
        return islower(character) ? toupper(character) : tolower(character);
    }


    static string InvertAllLettersCase(string S1) {
        for (int i = 0; i <= S1.length(); i++) {
            S1[i] = InversCharacter(S1[i]);
        }
        return S1;
    }
    void InvertAllLettersCase() {
        _Value = InvertAllLettersCase(_Value);
    }


    enum enWhatToCoun { CapitalLtters = 0, SmallLatters = 1, All = 2 };
    static short CountLetters(string S1, enWhatToCoun WhatToCoun = enWhatToCoun::All) {

        if (WhatToCoun == All) {
            return S1.length();
        }

        short count = 0;
        for (int i = 0; i <= S1.length(); i++) {
            if (WhatToCoun == enWhatToCoun::CapitalLtters && isupper(S1[i])) {
                count++;
            }
            else if (WhatToCoun == enWhatToCoun::SmallLatters && islower(S1[i])) {
                count++;
            }
        }
        return count;
    }


    static short CountSmallLetters(string S1) {
        short count = 0;
        for (int i = 0; i <= S1.length(); i++) {
            islower(S1[i]) ? count++ : count;
        }
        return count;
    }
    short CountSmallLetters() {
        return CountSmallLetters(_Value);
    }


    static short CountCapitalLetters(string S1) {
        short count = 0;
        for (int i = 0; i <= S1.length(); i++) {
            isupper(S1[i]) ? count++ : count;
        }
        return count;
    }
    short CountCapitalLetters() {
        return CountCapitalLetters(_Value);
    }


    static short countWords(string S1) {
        short count = 0;
        short pos = 0;
        string  delimiter = " ";
        string world;

        while ((pos = S1.find(delimiter)) != std::string::npos) {

            world = S1.substr(0, pos);
            if (world != "") {
                count++;
            }

            S1.erase(0, pos + delimiter.length());
        }
        if (S1 != "") {
            count++;
        }

        return count;
    }
    short countWords() {
        return  countWords(_Value);
    }


    static short CountSpecificLetters(string S1, char Letter, bool MatchCase = true) {
        short count = 0;


        for (int i = 0; i <= S1.length(); i++) {
            if (MatchCase) {
                if (S1[i] == Letter) {
                    count++;
                }
            }
            else {
                if (toupper(S1[i]) == toupper(Letter)) {
                    count++;
                }
            }

        }
        return count;
    }
    short CountSpecificLetters(char Letter, bool MatchCase = true) {
        return  CountSpecificLetters(_Value, Letter, MatchCase);
    }


    static bool IsAVowel(char character) {
        character = tolower(character);
        return (character == 'a') || (character == 'e') || (character == 'o') || (character == 'i') || (character == 'u');
    }


    static short CountVowels(string S1) {

        short count = 0;
        for (int i = 0; i <= S1.length(); i++) {
            if (IsAVowel(S1[i])) {
                count++;
            }
        }
        return count;
    }
    short CountVowels() {
        return  CountVowels(_Value);
    }


    static   string TrimLeft(string S1) {
        for (int i = 0; i <= S1.length(); i++) {
            if (S1[i] != ' ') {
                return  S1.substr(i, S1.length() - i);
            }
        }
        return "";
    }
    void TrimLeft() {
        _Value = TrimLeft(_Value);
    }


    static string TrimRight(string S1) {
        for (int i = S1.length() - 1; i >= 0; i--) {
            if (S1[i] != ' ') {
                return S1.substr(0, i + 1);
            }
        }
        return "";
    }
    void TrimRight() {
        _Value = TrimRight(_Value);
    }


    static string Trim(string S1) {
        return TrimRight(TrimLeft(S1));

    }
    void Trim() {
        _Value = Trim(_Value);
    }


    static vector<string> Split(string S1, string delim) {
        vector<string> vTokens;
        short pos = 0;

        string world;

        while ((pos = S1.find(delim)) != std::string::npos) {

            world = S1.substr(0, pos);
            if (world != " ") {
                vTokens.push_back(world);

            }

            S1.erase(0, pos + delim.length());

        }
        if (S1 != "") {
            vTokens.push_back(S1);


        }


        return vTokens;
    }
    vector<string> Split(string delim) {

        vector<string> V1 = Split(_Value, delim);

        return V1;
    }


    static string JoinString(vector<string>& vToken, string delim) {
        short delimNum = vToken.size() - 1;
        string S1 = "";
        for (string& Token : vToken) {
            S1 = S1 + Token + delim;

        }
        return S1.substr(0, S1.length() - delim.length());
    }
    static string JoinString(string arr[], short length, string delim) {

        string S1 = "";
        for (int i = 0; i <= length - 1; i++) {
            S1 = S1 + arr[i] + delim;
        }
        return S1.substr(0, S1.length() - delim.length());
    }


    static string RevesWordsInString(string S1) {

        vector <string> vString;
        vString = Split(S1, " ");
        string S2 = "";

        vector <string>::iterator iter = vString.end();
        while (iter != vString.begin()) {

            iter--;
            S2 += *iter + " ";
        }
        S2 = S2.substr(0, S2.length() - 1);
        return S2;
    }
    void RevesWordsInString() {
        _Value = RevesWordsInString(_Value);
    }



    static string  ReplaceWord(string S1, string StringToReplace, string ReplaceTo, bool MatchCase = true) {

        vector <string> vReplace;

        vReplace = Split(S1, " ");
        if (MatchCase) {
            for (string& Replace : vReplace) {
                if (Replace == StringToReplace) {
                    Replace = ReplaceTo;
                }
            }
        }
        else {
            for (string& Replace : vReplace) {
                if (LowerAllString(Replace) == LowerAllString(StringToReplace)) {
                    Replace = ReplaceTo;
                }
            }
        }

        return JoinString(vReplace, " ");
    }
    string ReplaceWord(string StringToReplace, string ReplaceTo) {
        return  ReplaceWord(_Value, StringToReplace, ReplaceTo);
    }



    static bool IsPauncuation(char S1) {

        return !(S1 < char(33) || S1 > char(63));

    }
    static string RemovePauncuations(string S1) {
        string S2 = "";
        for (short i = 0; i <= S1.length() - 1; i++) {
            if (!IsPauncuation(S1[i])) {

                S2 += S1[i];
            }

        }
        return S2;
    }
    void RemovePauncuations() {
        _Value = RemovePauncuations(_Value);
    }

};


