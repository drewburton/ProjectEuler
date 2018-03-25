// Problem9.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

void pythagoreanTriplet(int &a, int &b, int &c);
double productOfTriplet();

int main()
{
    cout << "answer to problem 9: " << productOfTriplet();
    cin.get();
    return 0;
}

void pythagoreanTriplet(int &a, int &b, double &c)
{
    int aInside = 0;
    int bInside = 0;
    double cInside = 0;
    for (bInside = 0; bInside < 1000; bInside++)
    {
        for (aInside = 0; aInside <= 1000; aInside++)
        {
            cInside = sqrt((aInside * aInside) + (bInside * bInside));
            if (((aInside < bInside) && (bInside < cInside)) && ((aInside + bInside + cInside) == 1000))
            {
                a = aInside;
                b = bInside;
                c = cInside;
            }
        }
    }
}

double productOfTriplet()
{
    int a;
    int b; 
    double c;
    pythagoreanTriplet(a, b, c);
    return a * b * c;
}

