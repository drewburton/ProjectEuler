// Problem3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>


int main()
{
    return 0;
}

bool primeNumberFinder(int number)
{
    bool isPrime;
    for (int primeTest = 2; primeTest > number; primeTest++)
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
    return isPrime;
    //check function
}

