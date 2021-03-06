// Problem9.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

double productOfPythagoreanTriplet();

int main()
{
    cout << "answer to problem 9: " << productOfPythagoreanTriplet();
    cin.get();
    // answer: 31875000
    return 0;
}

double productOfPythagoreanTriplet()
{
    int a = 0;
    int b = 0;
    double c = 0;
    for (b = 0; b < 1000; b++)
    {
        for (a = 0; a <= 1000; a++)
        {
            c = sqrt((a * a) + (b * b));
            if (((a < b) && (b < c)) && ((a + b + c) == 1000))
            {
                return a * b * c;
            }
        }
    }
}

