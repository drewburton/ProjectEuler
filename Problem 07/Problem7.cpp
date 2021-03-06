// Problem7.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>

using namespace std;

int nthPrimeNumber(int n);
bool isNumberPrime(int number);


int main()
{
    cout << nthPrimeNumber(10001);
    cin.get();
    return 0;
}

int nthPrimeNumber(int n)
{
    int primeFactors[1000];
    primeFactors[0] = 2;
    int primeFactorIndex = 1;
    int nthPrimeFactor = 1;
    int counter = 3;
    bool isNumberFound = false;
    while (!isNumberFound)
    {
        if (isNumberPrime(counter))
        {
            if (sizeof(primeFactors) >= 999)
                primeFactorIndex = 0;
            primeFactors[primeFactorIndex] = counter;
            primeFactorIndex++;
            nthPrimeFactor++;
        }
        counter += 2;
        if (nthPrimeFactor >= n)
        {
            isNumberFound = true;
        }
    }
    return primeFactors[primeFactorIndex - 1];
}

bool isNumberPrime(int number)
{
    bool isPrime = false;
    
    for (int primeTest = 2; primeTest < number; primeTest++)
    {
        if (((number % primeTest) == 0))
        {
            isPrime = false;
            break;
        }
        if (primeTest > sqrt(number))
        {
            isPrime = true;
            break;
        }
    }
    if ((number == 2) || (number == 3))
    {
        isPrime = true;
    }
    return isPrime;
}

