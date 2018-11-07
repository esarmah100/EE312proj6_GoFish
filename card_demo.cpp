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
    int playerFlag = 1;
    int flagTemp;
    
    Player p1("Joe");
    Player p2("Jane");
    
    Deck d;  //create a deck of cards
    d.shuffle();
    
    dealHand(d, p1, numCards);
    dealHand(d, p2, numCards);
       
    cout << p1.getName() <<" has : " << p1.showHand() << endl;
    cout << p2.getName() <<" has : " << p2.showHand() << endl;

    while(d.size() != 0) {

        /*Player 1*/
        if (playerFlag == 1) {
            Card cardCalled = p1.chooseCardFromHand();
            cout << p1.getName() << " asks - do you have " << cardCalled.rankString(cardCalled.getRank()) << "?"
                 << endl;

            string response = "";

            while (p2.cardInHand(p1.chooseCardFromHand())) {
                response = "Yes. I have a " + cardCalled.rankString(cardCalled.getRank());
                cout << p2.getName() << " says - " << response << endl;

                Card cardMatched = p2.removeCardFromHand(cardCalled);

                p1.addCard(cardMatched);

               // cout << p1.getName() << " has : " << p1.showHand() << endl;   // shows the matched card transferred
               // cout << p2.getName() << " has : " << p2.showHand() << endl;   // to the other player

                p1.bookCards(cardCalled, cardMatched);        //book the two cards
                p1.removeCardFromHand(cardCalled);              //remove the two cards from hand b/c they have been booked
                p1.removeCardFromHand(cardMatched);

                //cout << p1.getName() << " books the " << cardCalled.rankString(cardCalled.getRank()) << endl;
                //cout << p1.getName() << "'s book has " << p1.showBooks() << endl; //displays what the player1's book contains

                //cout << p1.getName() << " has : " << p1.showHand() << endl;  //shows the players' hands
                //cout << p2.getName() << " has : " << p2.showHand() << endl;  //after hands have been booked

                cardCalled = p1.chooseCardFromHand();
                cout << p1.getName() << " asks - do you have " << cardCalled.rankString(cardCalled.getRank()) << "?" << endl;

            }
            if (p2.cardInHand(p1.chooseCardFromHand()) == false) {
                response = "Go Fish";
                cout << p2.getName() << " says - " << response << endl;
            }

            vector<Card>::const_iterator iter;

            for(iter = 0; iter < p1.getHandSize(); iter++){
                if((p1.checkHandForPair(iter, (iter+1))){
                    p1.bookCards(*(iter), *(iter+1));
                    p1.removeCardFromHand(*iter);
                    p1.removeCardFromHand(*(iter+1));
                }

            }



        }

        /* Player 2 */
        if (playerFlag == 2) {
            Card cardCalled = p2.chooseCardFromHand();
            cout << p2.getName() << " asks - do you have " << cardCalled.rankString(cardCalled.getRank()) << "?"
                 << endl;

            string response = "";

            while (p1.cardInHand(p2.chooseCardFromHand())) {
                response = "Yes. I have a " + cardCalled.rankString(cardCalled.getRank());
                cout << p1.getName() << " says - " << response << endl;

                Card cardMatched = p1.removeCardFromHand(cardCalled);

                p2.addCard(cardMatched);

                // cout << p1.getName() << " has : " << p1.showHand() << endl;   // shows the matched card transferred
                // cout << p2.getName() << " has : " << p2.showHand() << endl;   // to the other player

                p2.bookCards(cardCalled, cardMatched);        //book the two cards
                p2.removeCardFromHand(cardCalled);              //remove the two cards from hand b/c they have been booked
                p2.removeCardFromHand(cardMatched);

                //cout << p2.getName() << " books the " << cardCalled.rankString(cardCalled.getRank()) << endl;
                //cout << p2.getName() << "'s book has " << p1.showBooks() << endl; //displays what the player1's book contains

                //cout << p1.getName() << " has : " << p1.showHand() << endl;  //shows the players' hands
                //cout << p2.getName() << " has : " << p2.showHand() << endl;  //after hands have been booked

                cardCalled = p2.chooseCardFromHand();
                cout << p2.getName() << " asks - do you have " << cardCalled.rankString(cardCalled.getRank()) << "?" << endl;

            }
            if (p1.cardInHand(p2.chooseCardFromHand()) == false) {
                response = "Go Fish";
                cout << p1.getName() << " says - " << response << endl;
            }

            vector<Card>::const_iterator iter;

            for(iter = 0; iter < p2.getHandSize(); iter++){
                if((p2.checkHandForPair(iter, (iter+1))){
                    p2.bookCards(*(iter), *(iter+1));
                    p2.removeCardFromHand(*iter);
                    p2.removeCardFromHand(*(iter+1));
                }

            }

            


        }
        Card drawnCard = d.dealCard();

        if (playerFlag == 1) {
            p1.addCard(drawnCard);                   //player1 one draws card from deck
            cout << p1.getName() << " draws " << drawnCard.toString() << endl;
            cout << endl;
        }
        if (playerFlag == 2) {
            p2.addCard(drawnCard);                   //player2 one draws card from deck
            cout << p2.getName() << " draws " << drawnCard.toString() << endl;
            cout << endl;
        }

        cout << p1.getName() << "'s book has " << p1.showBooks() << endl; //displays what the player1's book contains
        cout << p2.getName() << "'s book has " << p2.showBooks() << endl; //displays what the player2's book contains
        cout << endl;

        if (playerFlag == 1)
            flagTemp = 2;
        else if(playerFlag == 2)
            flagTemp = 1;

        playerFlag = flagTemp;
    }

    return EXIT_SUCCESS;  
}



void dealHand(Deck &d, Player &p, int numCards)
{
   for (int i=0; i < numCards; i++)
      p.addCard(d.dealCard());
}
   

