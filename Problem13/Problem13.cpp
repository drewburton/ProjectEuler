// Problem13.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

string firstString = "37107287533902102798797998220837590246510135740250";
string secondString = "46376937677490009712648124896970078050417018260538";

string addLargeInt(string firstNumber, string secondNumber);

int main()
{
    cout << addLargeInt(firstString, secondString);
    cin.get();
    return 0;
}

string addLargeInt(string firstNumber, string secondNumber)
{
    string largestInt;
    if (firstNumber > secondNumber)
    {
        largestInt = firstNumber;
    }
    else
    {
        largestInt = secondNumber;
    }

    string largeInt;
    for (int addex = size(largestInt); addex >= 0; addex--)
    {
        if ((firstNumber[addex] + secondNumber[addex] + largeInt[addex]) > 9)
        {
            largeInt[addex] += (firstNumber[addex] + secondNumber[addex]) - 10;
            largeInt[addex - 1] += 1;
        }
        else
        {
            largeInt[addex] = firstNumber[addex] + secondNumber[addex];
        }
    }
    return largeInt;
}

