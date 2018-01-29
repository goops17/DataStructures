//Dice.h
#ifndef DICE_H
#define DICE_H

class Dice{

private:
    int dice;
    float wallet;


public:
    Dice();
    void roll();
    int getRoll();
    float getWallet();
    void addWallet(float n);
    void removeWallet(float n);

};
#endif // DICE_H

