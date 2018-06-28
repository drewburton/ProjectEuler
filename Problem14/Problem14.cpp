// Problem14.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

bool isOdd(int number);
int generateChain(int startingNumber);

int main()
{
    int previousAmount = generateChain(2);
    int currentAmount;
    int highestAmount = previousAmount;

    for (int startingNumber = 3; startingNumber < 1000000; startingNumber++)
    {
        currentAmount = generateChain(startingNumber);
        if (currentAmount > previousAmount)
        {
            highestAmount = currentAmount;
        }
        previousAmount = currentAmount;
    }

    cout << "The answer to problem 14 is " << highestAmount << endl;
    return 0;
}

bool isOdd(int number)
{
    return (number % 2) > 0 ? true : false;
}

int generateChain(int startingNumber)
{
    using namespace std;

    int nextNumber = 0;
    int numbersInChain = 2;

    nextNumber = isOdd(startingNumber) ? 3 * startingNumber + 1 : startingNumber / 2;
    while (nextNumber != 1)
    {
        nextNumber = isOdd(nextNumber) ? 3 * nextNumber + 1 : nextNumber / 2;
        numbersInChain++;
    }
    return numbersInChain;
}