// Problem12.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>

using namespace std;

int divisorsOfTriangleNumber(int triangle);
int triangleWithDivisors();
bool isTriangleNumber(int number);

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
    for (long index = 1; index <= triangle; index++)
    {
        if ((triangle % index) == 0)
        {
            divisors[divisorsIndex] = index;
            divisorsIndex++;
        }
    }

    return divisorsIndex;
}

int triangleWithDivisors()
{
    int amountOfDivisors = 0;
    int index;
    for (index = 0; amountOfDivisors < 500; index += 1)
    {
        if (isTriangleNumber(index))
        {
            amountOfDivisors = divisorsOfTriangleNumber(index);
        }
    }
    return index;
}

bool isTriangleNumber(int number)
{
    int c = (-2 * number);
    int b = 1, a = 1;
    int d = (b * b) - (4 * a * c);

    if (d < 0)
        return false;

    double root1 = (-b + sqrt(d)) / (2 * a);
    double root2 = (-b - sqrt(d)) / (2 * a);

    if (root1 > 0 && floor(root1) == root1)
        return true;

    if (root2 > 0 && floor(root2) == root2)
        return true;

    return false;
}
