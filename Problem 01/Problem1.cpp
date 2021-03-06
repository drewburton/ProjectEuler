// ProjectEuler.cpp : Defines the entry point for the console application.
// project Euler problem #1
// username: DrewB21
// password: T

#include "stdafx.h"
#include <iostream>
double SumMultiples3and5();

int main()
{
    std::cout << "sum of multiples of 3 and 5: " << SumMultiples3and5() << std::endl;
    std::cin.get();
    return 0;
}

double SumMultiples3and5()
{
    int multiples[1000];
    int multipleCounter = 0;
    int sumMultiples = 0;

    for (int number = 1; number < 1000; number++)
    {
        if (((number % 3) == 0) || ((number % 5) == 0))
        {
            multiples[multipleCounter] = number;
            multipleCounter++;
        }
    }
    for (int multipleIndex = multipleCounter - 1; multipleIndex >= 0; multipleIndex--)
    {
        int currentMultiple = multiples[multipleIndex];
        sumMultiples += currentMultiple;
    }
    return sumMultiples;
}