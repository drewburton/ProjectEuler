// Problem12.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>

using namespace std;

int divisorsOfTriangleNumber(int triangle);
int triangleWithDivisors();

int divisors[600];

int main()
{
    cout << "Answer to problem 12: " << triangleWithDivisors();
    cin.get();
    return 0;
}

int divisorsOfTriangleNumber(int triangle)
{
    int divisorsIndex = 0;
    for (long index = 1; index <= sqrt(triangle); index++)
    {
        if ((triangle % index) == 0)
        {
            divisors[divisorsIndex] = index;

            if ((triangle / index) != index)
            {
                divisors[divisorsIndex + 1] = triangle / index;
                divisorsIndex += 2;
            }
            else 
            {
                divisorsIndex++;
            }

        }
    }

    return divisorsIndex;
}

int triangleWithDivisors()
{
    int amountOfDivisors = 0;
    int index;
    int makeTriangle = 1;
    for (index = 1; amountOfDivisors < 500; index += makeTriangle)
    {
            amountOfDivisors = divisorsOfTriangleNumber(index);
            makeTriangle++;
            if (amountOfDivisors > 500)
                index -= makeTriangle;
    }
    return index;
}