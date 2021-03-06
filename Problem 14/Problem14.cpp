// Problem14.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

bool isOdd(unsigned long long number);
int generateChain(unsigned long long startingNumber);

int main()
{
    int previousAmount = 1;
    int highestAmount = previousAmount;
    long long highestStarting = 0;

    for (int startingNumber = 3; startingNumber < 1000000; startingNumber++)
    {
        int currentAmount = generateChain(startingNumber);
        if (currentAmount > highestAmount)
        {
            highestAmount = currentAmount;
            highestStarting = startingNumber;
        }
        previousAmount = currentAmount;
    }
    cout << highestAmount << endl;
    cout << highestStarting << endl;
    return 0;
}

bool isOdd(unsigned long long number)
{
    return (number % 2) != 0 ? true : false;
}

int generateChain(unsigned long long startingNumber)
{
    using namespace std;

    int numbersInChain = 2;

    unsigned long long nextNumber = isOdd(startingNumber) ? 3 * startingNumber + 1 : startingNumber / 2;
    while (nextNumber != 1)
    {
        nextNumber = isOdd(nextNumber) ? 3 * nextNumber + 1 : nextNumber / 2;
        numbersInChain++;
    }
    return numbersInChain;
}