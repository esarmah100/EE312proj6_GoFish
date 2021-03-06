//
// Created by Devina Parihar on 11/5/2018.
//

#include "player.h"
#include <iterator>

#include <string>

using namespace std;

Player::Player() {
    myName = "";

}

void Player::addCard(Card c) {

    myHand.push_back(c);


}

void Player::bookCards(Card c1, Card c2) {

    myBook.push_back(c1);
    myBook.push_back(c2);


}


Card Player::chooseCardFromHand() const {

    Card chosenCard;
    chosenCard = myHand.front();
    return chosenCard;

}

bool Player::cardInHand(Card c) const {

    vector<Card>::const_iterator iter;

    for(iter = myHand.begin(); iter < myHand.end(); iter++){
        if((*iter).getRank() == c.getRank())
            return true;
    }
    return false;

}

Card Player::removeCardFromHand(Card c) {

    vector<Card>::iterator iter;


    int n = 0;
    for(iter = myHand.begin(); iter->getRank() != c.getRank(); iter++){
        n++;
    }
    Card toBeReturned = *(myHand.begin() + n);

    myHand.erase(myHand.begin() + n);         //will erase the element that is card c

    return toBeReturned;



}

string Player::showHand() const {

    vector<Card>::const_iterator iter;

    string handList;
    string spaceComma = ", ";

    for(iter = myHand.begin(); iter < myHand.end(); iter++){
        handList+= (*iter).toString();
        handList = handList + spaceComma;


    }

    return handList;



}

string Player ::showBooks() const {

    vector<Card>::const_iterator iter;
    string bookList;
    string spaceComma = ", ";
    for(iter = myBook.begin(); iter < myBook.end(); iter++){
        bookList+= (*iter).toString();
        bookList = bookList + spaceComma;

    }

    return bookList;



}

int Player::getBookSize() const {

    vector<Card>::const_iterator iter;

    int bookSize = 0;

    for(iter = myBook.begin(); iter < myBook.end(); iter++){
        bookSize++;
    }
    return bookSize;




}

int Player::getHandSize() const {

    vector<Card>::const_iterator iter;

    int handSize = 0;

    for(iter = myHand.begin(); iter < myHand.end(); iter++){
        handSize++;
    }
    return handSize;


}

bool Player ::checkHandForPair(Card &c1, Card &c2) {

    vector<Card>::iterator iter;
    vector<Card>::iterator iter2;



    for(iter = myHand.begin(); iter < (myHand.end() -1); iter++){
        for(iter2 = (iter + 1); iter2 < myHand.end(); iter2++) {

            if ((*iter).getRank() == (*iter2).getRank()) {
                c1 = (*iter);
                c2 = (*iter2);

                return true;

            }
        }

    }
    return false;


}






