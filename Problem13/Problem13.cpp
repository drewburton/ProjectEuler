// Problem13.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include "LargeInt.h"

using namespace std;
LargeInt * _firstNumberToAdd = new LargeInt("37107287533902102798797998220837590246510135740250");
LargeInt * _secondNumberToAdd = new LargeInt("46376937677490009712648124896970078050417018260538");

int _testNumber1[10] = { 5,7,4,0,2,5,0 };
int _testNumber2[10] = { 8,2,6,0,5,3,8 };

int main()
{
    _firstNumberToAdd->addLargeInt(_testNumber1, _testNumber2);
    for (int index = 0; index < 50; index++)
        cout << _firstNumberToAdd->_largeIntAnswer[index];
    return 0;
}