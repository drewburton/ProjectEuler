// Problem10.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

void SieveOfEratosthenes(int numbersLessThan);

int main()
{
    SieveOfEratosthenes(2000000);
    cin.get();
    return 0;
}

void SieveOfEratosthenes(int numbersLessThan)
{
    bool* prime = new bool[numbersLessThan + 1];
    memset(prime, true, sizeof(prime));

    for (int primeIndex = 2; primeIndex*primeIndex <= numbersLessThan; primeIndex++)
    {
        if (prime[primeIndex])
        {
            for (int i = primeIndex * 2; i <= numbersLessThan; i += primeIndex)
                prime[i] = false;
        }
    }

    long long sum = 0;
    for (int primeIndex = 2; primeIndex <= numbersLessThan; primeIndex++)
        if (prime[primeIndex])
            sum += primeIndex;
    cout << "answer to problem 10: " << sum;
    delete prime;
}
