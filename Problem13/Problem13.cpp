// Problem13.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include "LargeInt.h"

using namespace std;
LargeInt * _numberToAdd = new LargeInt("37107287533902102798797998220837590246510135740250");

int addLargeIntAnswer[1000];
//void addLargeInt(int index1, int index2);

int main()
{
    cout << _numberToAdd << endl;
    return 0;
}
 /*
void addLargeInt(int index1, int index2)
{    
    for (int addex = 49; addex >= 0; addex--)
    {
        if ((largeInt[index1][addex] + largeInt[index2][addex]) > 9)
        {
            addLargeIntAnswer[addex] += (largeInt[index1][addex] + largeInt[index2][addex]) - 10;
            addLargeIntAnswer[addex - 1] += 1;
        }
        else
        {
            addLargeIntAnswer[addex] += largeInt[index1][addex] + largeInt[index2][addex];
        }
        if (addLargeIntAnswer[addex] > 9)
        {
            addLargeIntAnswer[addex] -= 10;
            addLargeIntAnswer[addex - 1] += 1;
        }
    }

    for (int index = -1; index < 50; index++)
    {
        cout << addLargeIntAnswer[index] << endl << endl;
    }
}
*/