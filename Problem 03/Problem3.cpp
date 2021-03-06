// Problem3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
bool isNumberPrime(unsigned long long number);
unsigned long long largetPrimeFactor(unsigned long long number);

int index = 1;
int index2 = 1;
using namespace std;

int main()
{
    unsigned long long finalAnswer = 600851475143;
    int testNumber = 13195;
    cout << "largest prime factor is " << largetPrimeFactor(finalAnswer) << endl;

    cin.get();

    return 0;
}

bool isNumberPrime(unsigned long long number)
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
        index2++;
    }
    if (number == 2)
    {
        isPrime = true;
    }
    return isPrime;
}

unsigned long long largetPrimeFactor(unsigned long long originalNumber)
{
    int primeFactorsOfNumber[500];
    int primeFactors = 0;
   
    for (int number = 3; number < originalNumber; number++)
    {
        if (((originalNumber % number) == 0) && isNumberPrime(number))
        {
            cout << "found prime factor #" << primeFactors + 1 << endl;

            primeFactorsOfNumber[primeFactors] = number;
            primeFactors++;
        }
        index++;
    }
    cout << "returning largest prime factor" << endl;

    return primeFactorsOfNumber[primeFactors - 1];
}

