//Players.cpp
#include "player.h"
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

Player::Player()
{
    firstName="";
    lastName = "";
    wallet = 500;
    bet=0;
}
void Player::setName(string fname, string lname)
{
    firstName=fname;
    lastName=lname;
}
string Player::getName()
{
    return firstName;
}

float Player::getWallet()
{
    return wallet;
}

void Player::setFName(string fname)
{
    firstName=fname;
}

void Player::addWallet(float w)
{
    wallet+=w;
}

void Player::removeWallet(float w)
{
    wallet-=w;
}

float Player::getBet()
{
    return bet;
}

void Player::setBet(float b)
{
    bet=b;
}

