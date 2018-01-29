#include <iostream>
#include <string>
#include "Libraries/dice.h"
#include "Libraries/player.h"
using namespace std;

int main()
{
    float bet=0;
    bool gameEnd=false, setBet=false, validOpt=false;
    string fname1, fname2, fname3,fname4, fname5;
    char opt;
    cout<<"What is the first name of player 1: "<<endl;
    cin>>fname1;
    cout<<"What is the first name of player 2: "<<endl;
    cin>>fname2;
    cout<<"What is the first name of player 3: "<<endl;
    cin>>fname3;
    cout<<"What is the first name of player 4: "<<endl;
    cin>>fname4;
    cout<<"What is the first name of player 5: "<<endl;
    cin>>fname5;


   //creating player objects
    Player p1, p2, p3, p4, p5;
    Dice comp;
    int roll1, roll2;
    p1.setFName(fname1);
    p2.setFName(fname2);
    p3.setFName(fname3);
    p4.setFName(fname4);
    p5.setFName(fname5);
    while(gameEnd==false)
    {
         cout<<"-----------Your bet-------------"<<endl;
        //getting bets players
        if(p1.getWallet()<=0)
            {
                cout<<"Enter a zero to sit out this round or an amount you can afford: ";
                cin>>bet;
                p1.setBet(bet);
            }
        else
            {
                while(setBet==false)
                {
                    cout<<p1.getName()<<" please enter your bet: ";
                    cin>>bet;
                        if(bet>p1.getWallet())
                        {
                            cout<<"You cannot afford this round, your wallet is: "<< p1.getWallet();
                        }
                        else
                        {
                            p1.setBet(bet);
                            setBet=true;
                        }

                }
                setBet=false;
            }

            if(p2.getWallet()<=0)
                {
                    cout<<"Enter a zero to sit out this round or an amount you can afford: ";
                    cin>>bet;
                    p2.setBet(bet);
                }
            else
                {
                    while(setBet==false)
                    {
                        cout<<p2.getName()<<" please enter your bet: ";
                        cin>>bet;
                            if(bet>p2.getWallet())
                            {
                                cout<<"You cannot afford this round, your wallet is: "<< p2.getWallet();
                            }
                            else
                            {
                                p2.setBet(bet);
                                setBet=true;
                            }

                    }
                    setBet=false;
                }

            if(p3.getWallet()<=0)
                {
                    cout<<"Enter a zero to sit out this round or an amount you can afford: ";
                    cin>>bet;
                    p3.setBet(bet);
                }
            else
                {
                    while(setBet==false)
                    {
                        cout<<p3.getName()<<" please enter your bet: ";
                        cin>>bet;
                            if(bet>p3.getWallet())
                            {
                                cout<<"You cannot afford this round, your wallet is: "<< p3.getWallet();
                            }
                            else
                            {
                                p3.setBet(bet);
                                setBet=true;
                            }

                    }
                    setBet=false;
                }

                if(p4.getWallet()<=0)
                {
                    cout<<"Enter a zero to sit out this round or an amount you can afford: ";
                    cin>>bet;
                    p4.setBet(bet);
                }
                else
                {
                    while(setBet==false)
                    {
                        cout<<p4.getName()<<" please enter your bet: ";
                        cin>>bet;
                            if(bet>p4.getWallet())
                            {
                                cout<<"You cannot afford this round, your wallet is: "<< p4.getWallet();
                            }
                            else
                            {
                                p4.setBet(bet);
                                setBet=true;
                            }

                    }
                    setBet=false;
                }

                if(p5.getWallet()<=0)
                {
                    cout<<"Enter a zero to sit out this round or an amount you can afford: ";
                    cin>>bet;

                    p5.setBet(bet);
                }
                else
                {
                    while(setBet==false)
                    {
                        cout<<p5.getName()<<" please enter your bet: ";
                        cin>>bet;
                            if(bet>p5.getWallet())
                            {
                                cout<<"You cannot afford this round, your wallet is: "<< p5.getWallet();
                            }
                            else
                            {
                                p5.setBet(bet);
                                setBet=true;
                            }

                    }
                    setBet=false;
                }
            comp.roll();
            roll1=comp.getRoll();
            comp.roll();
            roll2=comp.getRoll();
            cout<<"Computer rolled a ["<<roll1<<"] and ["<<roll2<<"]"<<endl;

            if(roll1==6 and roll2==6)
            {
                cout<<endl;
                cout<<"yay! all players win!";
                comp.removeWallet(p1.getBet()+p2.getBet()+p3.getBet()+p4.getBet()+p5.getBet());
                p1.addWallet(p1.getBet());
                p2.addWallet(p2.getBet());
                p3.addWallet(p3.getBet());
                p4.addWallet(p4.getBet());
                p5.addWallet(p5.getBet());

            }
            else
            {
                cout<<endl;
                cout<<"sorry! all players loose!";
                comp.addWallet(p1.getBet()+p2.getBet()+p3.getBet()+p4.getBet()+p5.getBet());
                p1.removeWallet(p1.getBet());
                p2.removeWallet(p2.getBet());
                p3.removeWallet(p3.getBet());
                p4.removeWallet(p4.getBet());
                p5.removeWallet(p5.getBet());
            }
        //displaying wallet
        cout<<endl;
        cout<<"-----------Current Wallet-------------"<<endl;
        cout<<p1.getName()<<"  :"<<p1.getWallet()<<endl;
        cout<<p2.getName()<<"  :"<<p2.getWallet()<<endl;
        cout<<p3.getName()<<"  :"<<p3.getWallet()<<endl;
        cout<<p4.getName()<<"  :"<<p4.getWallet()<<endl;
        cout<<p5.getName()<<"  :"<<p5.getWallet()<<endl;
        cout<<"COMPUTER: "<<comp.getWallet()<<endl;
        cout<<endl;

        //asking user if they want to continue or not
        while(validOpt==false)
        {
            cout<<"Do you wish to contiune? Y/N?"<<endl;
            cin>>opt;
            if (opt=='n' or opt=='N')
            {
                gameEnd=true;
                validOpt=true;
            }
            else if (opt=='y' or opt=='Y')
            {
                gameEnd=false;
                validOpt=true;
            }
            else
            {
                validOpt=false;
            }

        }
        validOpt=false;

    }

    return 0;

}

