// FILE: card_demo.cpp
// This is a small demonstration program showing how the Card and Deck classes are used.
#include <iostream>    // Provides cout and cin
#include <cstdlib>     // Provides EXIT_SUCCESS
#include "card.h"
#include "player.h"
#include "deck.h"

using namespace std;


// PROTOTYPES for functions used by this demonstration program:
void dealHand(Deck &d, Player &p, int numCards);




int main( )
{
    int numCards = 5;
    
    Player p1("Joe");
    Player p2("Jane");
    
    Deck d;  //create a deck of cards
    d.shuffle();
    
    dealHand(d, p1, numCards);
    dealHand(d, p2, numCards);
       
    cout << p1.getName() <<" has : " << p1.showHand() << endl;
    cout << p2.getName() <<" has : " << p2.showHand() << endl;

    cout << p1.getName() <<" asks - do you have " << p1.chooseCardFromHand().rankString(cardCalled.getRank()) << "?" << endl;

    string response = "";
    Card cardCalled = p1.chooseCardFromHand();

    while(p2.cardInHand(p1.chooseCardFromHand())){
        response = "Yes. I have a "+p1.chooseCardFromHand().rankString(cardCalled.getRank());
        cout << p2.getName() <<" says - " << response << endl;
        p1.addCard(cardCalled);
        p1.bookCards(, p1.chooseCardFromHand());        //book the two cards
        cout << p1.getName() << "books the" << cardCalled.rankString(cardCalled.getRank());
        


    }
    else
        reponse = "Go Fish";

    cout << p2.getName() <<" says - " << response << endl;

    p2.addCard(p1.chooseCardFromHand());
    //p2.bookCards();

    
    return EXIT_SUCCESS;  
}



void dealHand(Deck &d, Player &p, int numCards)
{
   for (int i=0; i < numCards; i++)
      p.addCard(d.dealCard());
}
   

