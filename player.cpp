//
// Created by Devina Parihar on 11/5/2018.
//

#include "player.h"

#include <string>

using namespace std;

Player::Player() {
    myName = "";

}

void Player::addCard(Card c) {

    myHand.push_back(c);


}

void Player::bookCards(Card c1, Card c2) {

    myHand.push_back(c1);
    myHand.push_back(c2);


}


Card Player::chooseCardFromHand() const {

    Card chosenCard;
    chosenCard = myHand.front();
    return chosenCard;

}

bool Player::cardInHand(Card c) const {

    vector<Card> const_iterator iter;

    for(iter = myHand.begin(); iter < myHand.end(); iter++){
        if(myHand[iter] == c)
            return true;
    }
    return false;

}

Card Player::removeCardFromHand(Card c) {

    vector<Card> iterator iter;

    int n;
    for(iter = myHand.begin(); myHand[iter] != c; iter++){
        n++;
    }
    n++;
    myHand.erase(myHand.begin + n);         //will erase the element that is card c

    return c;



}

string Player::showHand() const {

    vector<Card> const_iterator iter;

    string handList;

    for(iter = myHand.begin(); iter < myHand.end(); iter++){
        handList+= myHand[iter].toString();


    }

    return handList;



}

string Player ::showBooks() const {

    vector<Card> const_iterator iter;
    string bookList;
    for(iter = myBook.begin(); iter < myBook.end(); iter++){
        handList+= myBook[iter].toString();

    }

    return bookList;



}

int Player::getBookSize() const {

    vector<Card> const_iterator iter;

    int bookSize;

    for(iter = myBook.begin(); iter < myBook.end(); iter++){
        bookSize++;
    }
    return bookSize;




}

int Player::getHandSize() const {

    vector<Card> const_iterator iter;

    int handSize;

    for(iter = myHand.begin(); iter < myHand.end(); iter++){
        handSize++;
    }
    return handSize;


}




