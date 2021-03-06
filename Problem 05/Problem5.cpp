// Problem5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

bool IsNumberDivisible1Through20(int number);
int SmallestNumberDivisible();

int main()
{
    std::cout << SmallestNumberDivisible();
    std::cin.get();
    return 0;
}

bool IsNumberDivisible1Through20(int number)
{
    bool isDivisible = false;
    int timesWorked = 0;
    for (int index = 1; index <= 20; index++)
    {
        if ((number % index) == 0)
            timesWorked++;
    }
    if (timesWorked == 20)
        isDivisible = true;
    return isDivisible;
}

int SmallestNumberDivisible()
{
    bool isComplete = false;
    int number = 20;
    while (!isComplete)
    {
        if (IsNumberDivisible1Through20(number))
        {
            return number;
        }
        else
        {
            number += 20;
        }
    }
}


