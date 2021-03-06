// Problem2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
int fibonacciSequence();

int main()
{
    std::cout << "sum of even numbers in Fibonacci sequence: " << fibonacciSequence() << std::endl;
    std::cin.get();
    return 0;
}

int fibonacciSequence()
{

    long currentNumber = 1;
    long lastNumber = 0;
    long EvenSumInSequence = 0;

    long nextNumber = currentNumber + lastNumber;
    do
    {
        if ((nextNumber % 2) == 0)
        {
            EvenSumInSequence += nextNumber;
        }

        lastNumber = currentNumber;
        currentNumber = nextNumber;

        nextNumber = currentNumber + lastNumber;
    } while (nextNumber <= 4000000);

    return EvenSumInSequence;
}

