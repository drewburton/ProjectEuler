// Promlem4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string> 

using namespace std;

int number = 10000;
char factors[500];

string ConvertIntToString(int number);
int    ConvertStringToInt(string string);
string ReverseString(string notReversed);

bool IsNumberPalindrome();
bool IsNumberProduct3Digits();
int threeDigitFactorsOfNumber();

int main()
{
    int palindromes[500];
    int numberIndex = 0;
    for (int numberTest; numberTest <= 998001; numberTest++)
    {
        if (IsNumberPalindrome() && IsNumberProduct3Digits())
        {
            palindromes[numberIndex] = numberTest;
        }
    }
    //cout << ReverseString(ConvertIntToString(number));
    cout << IsNumberPalindrome();
    cin.get();
    return 0;
}

string ConvertIntToString(int number)
{
    string numberString = std::to_string(number);
    return numberString;
}

int ConvertStringToInt(string string)
{
    return stoi(string);
}

string ReverseString(string notReversed)
{
    string reversed;
    if (number < 100000)
    {
        reversed += notReversed[4];
        reversed += notReversed[3];
        reversed += notReversed[2];
        reversed += notReversed[1];
        reversed += notReversed[0];
    }

    if (number >= 100000)
    {
        reversed += notReversed[6];
        reversed += notReversed[5];
        reversed += notReversed[4];
        reversed += notReversed[3];
        reversed += notReversed[2];
        reversed += notReversed[1];
        reversed += notReversed[0];
    }

    return reversed;
}

bool IsNumberPalindrome()
{
    bool isNumberPalindrome = false;
    string numberString = ConvertIntToString(number);
    string reversedString = ReverseString(numberString);
    //cout << numberString << " " << reversedString << endl;

    if (numberString == reversedString)
    {
        isNumberPalindrome = true;
    }

    return isNumberPalindrome;
}

bool IsNumberProduct3Digits()
{
    if (threeDigitFactorsOfNumber() >= 2)
    {
        return true;
    }

    if (threeDigitFactorsOfNumber() < 2)
    {
        return false;
    }
}

int threeDigitFactorsOfNumber()
{
    int threeDigitFactors = 0;
    for (int index = 100; index <= 1000; index++) {
        if (number % index == 0)
            threeDigitFactors++;
    }
    return threeDigitFactors;
}

