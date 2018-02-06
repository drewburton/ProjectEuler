// Problem3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
bool primeNumberFinder(int number);
int largetPrimeFactor(int number);


int main()
{
    bool isNumberPrime = primeNumberFinder(2);

    int random = 4;

    return 0;
}

bool primeNumberFinder(int number)
{
    bool isPrime = false;
    for (int primeTest = 2; primeTest < number; primeTest++)
    {
        if ((number % primeTest) == 0)
        {
            isPrime = false;
            break;
        }
        if (primeTest == (number - 1))
        {
            isPrime = true;
        }
    }
    if (number == 2)
    {
        isPrime = true;
    }
    return isPrime;
}

int largetPrimeFactor(int originalNumber)
{
    int factorsOfNumber[500];
    int factors = 0;
   
    for (int number = 0; number < originalNumber; number++)
    {
        if ((originalNumber % number) == 0)
        {
            factorsOfNumber[factors] = number;
            factors++;
        }
    }
    return factorsOfNumber[factors - 1];
}

