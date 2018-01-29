#include <iostream>
#include <string>
#include "player.h"
#include "dice.h"
using namespace std;

int main()
{
    string fname1, fname2, lname1,lname2;
    int totalRoll1, totalRoll12;
    cout<<"What is the first name of player 1: "<<endl;
    cin>>fname1;
    cout<<"What is the last name of player 1: "<<endl;
    cin>>lname1;
    cout<<"What is the first name of player 2: "<<endl;
    cin>>fname2;
    cout<<"What is the last name of player 2: "<<endl;
    cin>>lname2;
    Player p1;
    Player p2;
    p1.setName(fname1, lname1);
    p2.setName(fname2, lname2);
    Dice die1;
    Dice die2;
    Dice die3;
    for(int n=0; n<10;n++)
    {
        die1.roll();
        die2.roll();
        die3.roll();
        totalRoll1=die1.getRoll()+die2.getRoll();
        totalRoll12=die1.getRoll()+die3.getRoll();

        if(totalRoll1>totalRoll12)
        {
            cout<<"Player One " <<p1.getName()<<" won this round!"<<endl;
        }
        else if(totalRoll12>totalRoll1)
        {
            cout<<"Player Two " <<p2.getName() <<" won this round!"<<endl;
        }
        else
        {
            cout<<"Draw!!"<<endl;
        }
    }
    return 0;
}



