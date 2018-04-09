#pragma once
#include <string>

using namespace std;

class LargeInt
{
public:
    LargeInt(string number);
    ~LargeInt();

    void stringToInt(string number); // stored in digits

protected:
    int digits[100];

};

