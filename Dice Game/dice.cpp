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
}
void Dice::roll()
{
    dice = 1 + rand() % 6;
}
int Dice::getRoll()
{
    return dice;
}

