//Dice.h
#ifndef PLAYER_H
#define PLAYER_H
#include<string>
using namespace std;
class Player{

private:
    string firstName;
    string lastName;
    float wallet;
    float bet;

public:
    Player();
    void setName(string fname, string lname);
    void setFName(string fname);
    void addWallet(float w);
    void removeWallet(float w);
    void setBet(float b);
    float getBet();
    float getWallet();
    string getName();

};
#endif // DICE_H


