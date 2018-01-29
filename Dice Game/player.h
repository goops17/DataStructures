//Dice.h
#ifndef PLAYER_H
#define PLAYER_H
#include<string>
using namespace std;
class Player{

private:
    string firstName;
    string lastName;

public:
    Player();
    void setName(string fname, string lname);
    string getName();

};
#endif // DICE_H


