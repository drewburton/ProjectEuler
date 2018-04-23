#include "stdafx.h"
#include "LargeInt.h"


LargeInt::LargeInt(string number)
{
    for (unsigned int index = 0; index < number.length(); index++)
    {
        _digits[index] = 0;
        _largeIntAnswer[index] = 0;
    }
    stringToInt(number);
}


LargeInt::~LargeInt()
{

}

void LargeInt::stringToInt(string number)
{
    for (unsigned int index = 0; index < number.length(); index++)
        _digits[index] = number[index];
}

void LargeInt::addLargeInt(int * firstArray, int * secondArray)
{
    bool shouldCarry = false;
    int amountToCarry = 0;
    int sumOfDigit = 0;
    int answerIndexOffset = sizeof(firstArray - 1);

    for (int index = sizeof(firstArray - 1); index >= 0; index--)
    {
        sumOfDigit = firstArray[index] + secondArray[index] + _largeIntAnswer[index + answerIndexOffset];
        std::cout << "sumOfDigit: " << sumOfDigit << endl;

        if (sumOfDigit >= 10)
            amountToCarry = int(sumOfDigit / 10);
        else
            amountToCarry = 0;

        if (amountToCarry > 0)
        {
            cout << "amountToCarry: " << amountToCarry << endl;
            _largeIntAnswer[index + answerIndexOffset - 1] += amountToCarry;
            _largeIntAnswer[index + answerIndexOffset] = sumOfDigit - 10;
            if (amountToCarry > 10)
            {
                _largeIntAnswer[index + answerIndexOffset - 2] += 1;
                _largeIntAnswer[index + answerIndexOffset - 1] -= 10;
            }
        }
        else // hiiiiiii
            _largeIntAnswer[index + answerIndexOffset] = sumOfDigit;
    }
}