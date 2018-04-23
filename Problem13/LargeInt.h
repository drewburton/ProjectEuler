#pragma once
#include <string>
#include <iostream>

using namespace std;

class LargeInt
{
public:
    LargeInt(string number);
    ~LargeInt();

    void stringToInt(string number); // stored in digits
    void addLargeInt(int * firstArray, int * secondArray);
    int _largeIntAnswer[100];

protected:
    int _digits[100];
};

