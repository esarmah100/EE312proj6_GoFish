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

        p1.addCard(p2.removeCardFromHand(cardCalled));

        p1.bookCards(cardCalled,p2.removeCardFromHand(cardCalled));        //book the two cards
        p1.removeCardFromHand(cardCalled);              //remove the two cards from hand b/c they have been booked
        p1.removeCardFromHand(p2.removeCardFromHand(cardCalled));

        cout << p1.getName() << " books the " << cardCalled.rankString(cardCalled.getRank()) << endl;

        cardCalled = p1.chooseCardFromHand();
        cout << p1.getName() <<" asks - do you have " << cardCalled.rankString(cardCalled.getRank()) << "?" << endl;

    }
    if(p2.cardInHand(p1.chooseCardFromHand()) == false)
        response = "Go Fish";

    cout << p2.getName() <<" says - " << response << endl;

    Card drawnCard = d.dealCard();

    p1.addCard(drawnCard);                   //player one draws card from deck
    cout << p1.getName() << " draws " << drawnCard.toString() << endl;

    vector<Card>::const_iterator iter;

    for(iter = 0; iter < p1.getHandSize(); iter ++){
        if(p1.checkHandForPair(iter, iter+1))
            p1.bookCards((*iter), (*iter+1));
    }



    //P2 STARTS (i think)


    Card cardCalled = p2.chooseCardFromHand();

    cout << p2.getName() <<" asks - do you have " << cardCalled.rankString(cardCalled.getRank()) << "?" << endl;

    response = "";

    while(p1.cardInHand(p2.chooseCardFromHand())){
        response = "Yes. I have a "+cardCalled.rankString(cardCalled.getRank());
        cout << p1.getName() <<" says - " << response << endl;

        p2.addCard(p1.removeCardFromHand(cardCalled));

        p2.bookCards(cardCalled,p1.removeCardFromHand(cardCalled));        //book the two cards
        p2.removeCardFromHand(cardCalled);              //remove the two cards from hand b/c they have been booked
        p2.removeCardFromHand(p1.removeCardFromHand(cardCalled));

        cout << p2.getName() << " books the " << cardCalled.rankString(cardCalled.getRank()) << endl;

        cardCalled = p2.chooseCardFromHand();
        cout << p2.getName() <<" asks - do you have " << cardCalled.rankString(cardCalled.getRank()) << "?" << endl;

    }
    if(p1.cardInHand(p2.chooseCardFromHand()) == false)
        response = "Go Fish";

    cout << p1.getName() <<" says - " << response << endl;

    Card drawnCard = d.dealCard();

    p2.addCard(drawnCard);                   //player two draws card from deck
    cout << p2.getName() << " draws " << drawnCard.toString() << endl;

    vector<Card>::const_iterator iter;

    for(iter = 0; iter < p2.getHandSize(); iter ++){
        if(p2.checkHandForPair(iter, iter+1))
            p2.bookCards((*iter), (*iter+1));
    }



    return EXIT_SUCCESS;  
}



void dealHand(Deck &d, Player &p, int numCards)
{
   for (int i=0; i < numCards; i++)
      p.addCard(d.dealCard());
}
   

