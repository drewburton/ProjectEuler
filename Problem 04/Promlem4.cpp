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
int LargestPalindromeFromProductOfThreeDigitNumbers();

int main()
{
    cout << "before finding answer\n";
    cout << LargestPalindromeFromProductOfThreeDigitNumbers() << endl;
    cout << "after finding answer\n";
    //cout << ReverseString(ConvertIntToString(number));
    //cout << IsNumberPalindrome();
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
    bool isNumberProductOfThreeDigitNumber = false;
    int threeDigitFactors[500];
    int threeDigitFactorsIndex = 0;
    for (int index = 100; index <= 1000; index++) 
    {
        if (number % index == 0)
        {
            threeDigitFactors[threeDigitFactorsIndex] = index;
            threeDigitFactorsIndex++;
        }
    }
    if ((threeDigitFactors[threeDigitFactorsIndex - 2]  * threeDigitFactors[threeDigitFactorsIndex - 1]) == number)
    {
        isNumberProductOfThreeDigitNumber = true;
    }
    return isNumberProductOfThreeDigitNumber;
}

int LargestPalindromeFromProductOfThreeDigitNumbers()
{
    int palindromes[1000];
    int palindromesIndex = 0;
    while (number <= 998001)
    {
        if (IsNumberPalindrome() && IsNumberProduct3Digits())
        {
            palindromes[palindromesIndex] = number;
            palindromesIndex++;
        }
        number++;
    }
    return palindromes[palindromesIndex - 1];
}

