#include <iostream>    // Provides cout and cin
#include <cstdlib>     // Provides EXIT_SUCCESS
#include <ctime>
#include "card.h"
#include "player.h"
#include "deck.h"

using namespace std;

Deck ::Deck() {
    for(int i = 1; i < 5; i++){
        for (int j = 0; j < 13; j++){
            if (i == 1){
                myCards[i*j] = Card(i+1, Card::hearts);
            }
            if (i == 2){
                myCards[i*j] = Card(i+1, Card::clubs);
            }
            if (i == 3){
                myCards[i*j] = Card(i+1, Card::diamonds);
            }
            if (i == 4){
                myCards[i*j] = Card(i+1, Card::spades);
            }
        }
    }
}

void Deck::shuffle(){
    unsigned int currentTime = (unsigned)time(0);
    srand(currentTime);

    Card temp;

    for (int i = 0; i < 104; i++){
        int randIndex = rand() % 52;
        int randIndex2 = rand() % 52;
        
        if (randIndex == randIndex2){
            randIndex2 = rand() % 52;
        }

        temp =  myCards[randIndex];
        myCards[randIndex] = myCards[randIndex2];
        myCards[randIndex] = temp;
    }
}



Card Deck::dealCard(){

    if(myCards.size() == 0)         //deck is empty, no cards left to deal
        return;
    else {
        Card r = myCards[myIndex];
        myIndex++;
        return r;
    }


}

int Deck::size() const {

    for(int i = 0; i)


}


