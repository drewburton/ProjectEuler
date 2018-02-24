// Problem6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

// first hundred numbers
int SumOfSquares();
int SquareOfSums();

int main()
{
    std::cout << (SquareOfSums() - SumOfSquares());
    std::cin.get();
    return 0;
}

int SumOfSquares()
{
    int sumOfSquares = 0;
    for (int counter = 1; counter <= 100; counter++)
    {
        sumOfSquares += (counter * counter);
    }
    return sumOfSquares;
}

int SquareOfSums()
{
    int sum = 0;
    for (int counter = 1; counter <= 100; counter++)
    {
        sum += counter;
    }
    return sum * sum;
}

