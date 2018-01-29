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
}
void Player::setName(string fname, string lname)
{
    firstName=fname;
    lastName=lname;
}
string Player::getName()
{
    return firstName + " " + lastName;
}


