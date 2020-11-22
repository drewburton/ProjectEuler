#include "stdafx.h"
#include "Sequence.h"
#include <iostream>


Sequence::Sequence(int startingNumber)
{
    amountInChain = generateChain(startingNumber);
}


Sequence::~Sequence()
{

}

bool Sequence::isOdd(int number)
{
    return (number % 2) > 0 ? true : false;
}

int Sequence::generateChain(int startingNumber)
{
    using namespace std;

    int nextNumber = 0;
    int numbersInChain = 2;

    nextNumber = isOdd(startingNumber) ? 3 * startingNumber + 1 : startingNumber / 2;
    while (nextNumber != 1)
    {
        nextNumber = isOdd(nextNumber) ? 3 * nextNumber + 1 : nextNumber / 2;
        numbersInChain++;
    }
    return numbersInChain;
}
