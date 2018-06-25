#include "stdafx.h"
#include "LargeInt.h"

LargeInt::LargeInt() {
    digits = new list<int>();
}

LargeInt::LargeInt(string number) : LargeInt()
{
    for (unsigned int index = 0; index < number.length(); index++)
    {
        digits->push_front(parseCharToInt(number[index]));
    }
}

LargeInt::LargeInt(list<int> *newDigits)
{
    digits = newDigits;
}


LargeInt::~LargeInt()
{
    delete digits;
}

LargeInt LargeInt::addLargeInt(LargeInt * numberToAdd)
{
    list<int> *secondDigits = numberToAdd->digits;
    list<int> *largeIntAnswer = new list<int>();
    list<int>::iterator firstIterator = digits->begin();
    list<int>::iterator secondIterator = secondDigits->begin();
    int amountToCarry = 0;
    int sumOfDigits = 0;

    if (digits->size() != secondDigits->size())
    {
        int difference = digits->size() - secondDigits->size();
        while (difference > 0)
        {
            secondDigits->push_back(0);
            difference = digits->size() - secondDigits->size();
        }
    }

    while (firstIterator != digits->end())
    {
        sumOfDigits = *firstIterator + *secondIterator + amountToCarry;
        if (sumOfDigits >= 10)
        {
            amountToCarry = 1;
            sumOfDigits -= 10;
        }
        else
            amountToCarry = 0;

        largeIntAnswer->push_front(sumOfDigits);
        advance(firstIterator, 1);
        advance(secondIterator, 1);
    }
    if (amountToCarry > 0)
    {
        largeIntAnswer->push_front(amountToCarry);
    }

    return LargeInt(largeIntAnswer);
}

void LargeInt::print(bool backward)
{
    if (backward)
    {
        list<int> * print = new list<int>();
        for (list<int>::iterator digitsIterator = digits->begin();
            digitsIterator != digits->end(); digitsIterator++)
        {
            print->push_front(*digitsIterator);
        }

        for (list<int>::iterator printIterator = print->begin(); printIterator != print->end(); printIterator++)
        {
            cout << *printIterator;
        }
    }
    else
    {
        for (list<int>::iterator digitsIterator = digits->begin();
            digitsIterator != digits->end(); digitsIterator++)
        {
            cout << *digitsIterator;
        }
    }
}

int LargeInt::parseCharToInt(char character)
{
    return character - '0';
}

int LargeInt::amountInList(list<int> listInput)
{

    int amountInList = 0;
    list<int>::iterator iterator = listInput.begin();
    for (;iterator != listInput.end(); advance(iterator, 1))
    {
        amountInList += 1;
    }
    return amountInList;
}