// Problem6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

// first hundred numbers
int DifferneceSumOfSquaresAndSquareOfSums();

int main()
{
    std::cout << DifferneceSumOfSquaresAndSquareOfSums();
    std::cin.get();
    return 0;
}

int DifferneceSumOfSquaresAndSquareOfSums()
{
    int sumOfSquares = 0;
    int sum = 0;
    int squareOfSums = 0;
    for (int counter = 1; counter <= 100; counter++)
    {
        sum += counter;
        sumOfSquares += (counter * counter);
    }
    squareOfSums = sum * sum;
    return squareOfSums - sumOfSquares;
}

