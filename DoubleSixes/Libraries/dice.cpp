//Dice.cpp
#include "dice.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

Dice::Dice()
{
    srand(time(0));
    dice = 0;
    wallet =5000;
}
void Dice::roll()
{
    dice = 1 + rand() % 6;
}
int Dice::getRoll()
{
    return dice;
}

float Dice::getWallet()
{
    return wallet;
}

void Dice::addWallet(float n)
{
    wallet+=n;
}

void Dice::removeWallet(float n)
{
    wallet-=n;
}
