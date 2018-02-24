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
    unsigned long long finalAnswer = 10001 /*600851475143*/;
    int testNumber = 13195;
    cout << "this is a cout test" << std::endl;
    cout << "largest prime factor is " << largetPrimeFactor(finalAnswer) << endl;

    cin.get();

    return 0;
}

bool isNumberPrime(unsigned long long number)
{
    bool isPrime = false;
    
    cout << "start of is number prime" << endl;
    for (int primeTest = 2; primeTest < number; primeTest++)
    {
        if ((index2 % 100000) == 0)
            cout << "start of for loop 1 #" << primeTest - 1 << endl;

        if ((number % primeTest) == 0)
        {
            cout << "number is not prime" << endl;

            isPrime = false;
            break;
        }
        if (primeTest == (number - 1))
        {
            cout << "number is prime" << endl;

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
   
    cout << "start of larget prime factor" << endl;

    for (int number = 3; number < originalNumber; number++)
    {
        if ((index % 100000) == 0)
            cout << "start of for loop 2 #" << number - 2 << endl;

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

