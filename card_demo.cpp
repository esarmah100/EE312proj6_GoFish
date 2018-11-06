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

    Card cardCalled = p1.chooseCardFromHand();

    cout << p1.getName() <<" asks - do you have " << cardCalled.rankString(cardCalled.getRank()) << "?" << endl;

    string response = "";

    while(p2.cardInHand(p1.chooseCardFromHand())){
        response = "Yes. I have a "+cardCalled.rankString(cardCalled.getRank());
        cout << p2.getName() <<" says - " << response << endl;
        p2.removeCardFromHand(cardCalled);

        p1.addCard(cardCalled);
        p1.bookCards(cardCalled, cardCalled);        //book the two cards
        p1.removeCardFromHand(cardCalled);              //remove the two cards from hand b/c they have been booked
        p1.removeCardFromHand(cardCalled);

        cout << p1.getName() << "books the" << cardCalled.rankString(cardCalled.getRank());

        cardCalled = p1.chooseCardFromHand();
        cout << p1.getName() <<" asks - do you have " << cardCalled.rankString(cardCalled.getRank()) << "?" << endl;

    }
    if(p2.cardInHand(p1.chooseCardFromHand()) == false)
        reponse = "Go Fish";

    cout << p2.getName() <<" says - " << response << endl;


    
    return EXIT_SUCCESS;  
}



void dealHand(Deck &d, Player &p, int numCards)
{
   for (int i=0; i < numCards; i++)
      p.addCard(d.dealCard());
}
   

