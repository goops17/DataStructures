// Test driver for class Deck
#include <iostream>
#include "../Libraries/deck.h"
#include "../Libraries/player.h"
#include <string>
int main ()
{
  void PrintDeck(Deck deck, Player p1, Player p2);
  Player p1;
  Player p2;
  string temp;
  cout<<"Please enter your first name: "<<endl;
  cin>>temp;
  p1.setFName(temp);
  cout<<"Please enter your first name: "<<endl;
  cin>>temp;
  p2.setFName(temp);
  Deck deck;
  Card card;
  deck.GenerateDeck();
  cout << "Deck after ten shuffles" << endl;
  deck.Shuffle();
  PrintDeck(deck, p1, p2);
  //PrintDeck(deck);
  return 0;
}

void PrintDeck(Deck deck, Player p1, Player p2)
{
  if (deck.GetLength() == 0)
     cout << "Deck is empty." << endl;
  else
  {

    deck.ResetList();
    Card card;
    cout<<endl;
    cout<<p1.getName()<<"'s hand: "<<endl;
    for (int counter = 1; counter <= 10; counter++)
    {
      card = deck.GetNextItem();
      cout << card.ToString() << endl;
    }
    cout<<endl;
    cout<<p2.getName()<<"'s hand: "<<endl;
    for (int counter = 11; counter <= 20; counter++)
    {
      card = deck.GetNextItem();
      cout << card.ToString() << endl;
    }
  }
  cout << endl;
}


