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
    int numCards = 7;
    int playerFlag = 1;
    int flagTemp;
    int player1OutFlag = 0;
    int player2OutFlag = 0;
    int gameFlag = 1;
    
    Player p1("Joe");
    Player p2("Jane");
    
    Deck d;  //create a deck of cards
    d.shuffle();
    
    dealHand(d, p1, numCards);
    dealHand(d, p2, numCards);
       
    cout << p1.getName() <<" has : " << p1.showHand() << endl;
    cout << p2.getName() <<" has : " << p2.showHand() << endl;

    while(gameFlag == 1) {

        /*Player 1*/
        if (playerFlag == 1) {


            Card c1;
            Card c2;
            if(p1.checkHandForPair(c1, c2)){
                p1.bookCards(c1, c2);
                p1.removeCardFromHand(c1);
                p1.removeCardFromHand(c2);
            }

            if(p1.getHandSize() > 0) {

               Card cardCalled = p1.chooseCardFromHand();
                cout << p1.getName() << " asks - do you have a " << cardCalled.rankString(cardCalled.getRank()) << "?"
                     << endl;


                string response = "";

                while (p2.cardInHand(p1.chooseCardFromHand())) {

                    response = "Yes. I have a " + cardCalled.rankString(cardCalled.getRank());
                    cout << p2.getName() << " says - " << response << endl;

                    Card cardMatched = p2.removeCardFromHand(cardCalled);

                    p1.addCard(cardMatched);


                    p1.bookCards(cardCalled, cardMatched);        //book the two cards
                    p1.removeCardFromHand(
                            cardCalled);              //remove the two cards from hand b/c they have been booked
                    p1.removeCardFromHand(cardMatched);

                    cout << p1.getName() << " books the " << cardCalled.rankString(cardCalled.getRank()) << endl;

                    if(p1.getHandSize() > 0) {
                        cardCalled = p1.chooseCardFromHand();
                        cout << p1.getName() << " asks - do you have a " << cardCalled.rankString(cardCalled.getRank())
                             << "?" << endl;
                    }

                }
                if (p2.cardInHand(p1.chooseCardFromHand()) == false && p1.getHandSize() >0) {
                    response = "Go Fish";
                    cout << p2.getName() << " says - " << response << endl;
                }

            }



            if(p1.getHandSize() == 0 && d.size() == 0){
                player1OutFlag = 1;             //player 1 is now out
            }



        }

        /* Player 2 */
        if (playerFlag == 2) {

            Card c3;
            Card c4;
            if(p2.checkHandForPair(c3 , c4)){
                p2.bookCards(c3, c4);
                p2.removeCardFromHand(c3);
                p2.removeCardFromHand(c4);
            }



            if(p2.getHandSize() > 0) {

                Card cardCalled = p2.chooseCardFromHand();
                cout << p2.getName() << " asks - do you have a " << cardCalled.rankString(cardCalled.getRank()) << "?"
                     << endl;

                string response = "";

                while (p1.cardInHand(p2.chooseCardFromHand())) {

                    response = "Yes. I have a " + cardCalled.rankString(cardCalled.getRank());
                    cout << p1.getName() << " says - " << response << endl;

                    Card cardMatched = p1.removeCardFromHand(cardCalled);

                    p2.addCard(cardMatched);


                    p2.bookCards(cardCalled, cardMatched);        //book the two cards
                    p2.removeCardFromHand(
                            cardCalled);              //remove the two cards from hand b/c they have been booked
                    p2.removeCardFromHand(cardMatched);

                    cout << p2.getName() << " books the " << cardCalled.rankString(cardCalled.getRank()) << endl;


                    if(p2.getHandSize() > 0) {
                        cardCalled = p2.chooseCardFromHand();
                        cout << p2.getName() << " asks - do you have " << cardCalled.rankString(cardCalled.getRank())
                             << "?"
                             << endl;
                    }

                }
                if (p1.cardInHand(p2.chooseCardFromHand()) == false && p2.getHandSize() >0) {
                    response = "Go Fish";
                    cout << p1.getName() << " says - " << response << endl;
                }

            }

            if(p2.getHandSize() == 0 && d.size() == 0){
                player2OutFlag = 1;             //player 2 is now out
            }



        }


        Card drawnCard = d.dealCard();
        if(drawnCard.getRank() == 0)
            cout << "empty deck" << endl;

        if (playerFlag == 1 && drawnCard.getRank() !=0) {
                p1.addCard(drawnCard);                   //player1 one draws card from deck
                cout << p1.getName() << " draws " << drawnCard.toString() << endl;
                cout << endl;
        }

        if (playerFlag == 2 && drawnCard.getRank() !=0) {
                p2.addCard(drawnCard);                   //player2 one draws card from deck
                cout << p2.getName() << " draws " << drawnCard.toString() << endl;
                cout << endl;
        }


        cout << p1.getName() << "'s book: " << p1.showBooks() << endl; //displays what the player1's book contains
        cout << p2.getName() << "'s book: " << p2.showBooks() << endl; //displays what the player2's book contains
        cout << endl;
        cout << p1.getName() <<"'s hand: " << p1.showHand() << endl; //debugging purposes
        cout << p2.getName() <<"'s hand: " << p2.showHand() << endl; // debugging purposes
        cout << endl;

        if (playerFlag == 1 && player2OutFlag == 0)
            flagTemp = 2;
        if(playerFlag == 1 && player2OutFlag == 1)
            flagTemp = 1;       //player 2 is out

        if(playerFlag == 2 && player1OutFlag == 0)
            flagTemp = 1;
        if(playerFlag == 2 && player1OutFlag == 1)
            flagTemp = 2;

        playerFlag = flagTemp;


        int numBooks = p1.getBookSize() + p2.getBookSize();
        if(numBooks == 52){
            gameFlag = 0;      //set game flag to 0, game is over b/c all cards have been booked
        }
    }


    if(p1.getBookSize() > p2.getBookSize())
        cout << "GAME OVER - " << p1.getName() << " won!" << endl;

    else if(p1.getBookSize() == p2.getBookSize())
        cout << "GAME OVER - TIE" << endl;
    else
        cout << "GAME OVER - " << p2.getName() << " won!" << endl;



    return EXIT_SUCCESS;  
}



void dealHand(Deck &d, Player &p, int numCards)
{
   for (int i=0; i < numCards; i++)
      p.addCard(d.dealCard());
}
   

