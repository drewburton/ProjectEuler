#include "stdafx.h"
#include "LargeInt.h"


LargeInt::LargeInt(string number)
{
    for (unsigned int index = 0; index < number.length(); index++)
        digits[index] = 0;
    stringToInt(number);
}


LargeInt::~LargeInt()
{

}

void LargeInt::stringToInt(string number)
{
    for (unsigned int index = 0; index < number.length(); index++)
        digits[index] = number[index];
}