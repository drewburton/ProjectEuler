#pragma once
#include <string>
#include <iostream>
#include <list>

using namespace std;

class LargeInt
{
public:
    LargeInt();
    LargeInt(string number);
    LargeInt(list<int> *newDigits);
    ~LargeInt();

    LargeInt * addLargeInt(LargeInt * numberToAdd);
    void print(bool backward);

protected:
    int parseCharToInt(char character);
    int amountInList(list<int> listInput);

    list<int> *digits;
};

