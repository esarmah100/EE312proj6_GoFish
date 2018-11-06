#include <iostream>    // Provides cout and cin
#include <cstdlib>     // Provides EXIT_SUCCESS
#include <ctime>
#include "card.h"
#include "player.h"
#include "deck.h"

using namespace std;

Deck ::Deck() {
    int count = 0;
    for(int i = 0; i < 4; i++){
        for (int j = 0; j < 13; j++){
            if (i == 0){
                myCards[count] = Card(j+1, Card::hearts);
            }
            if (i == 1){
                myCards[count] = Card(j+1, Card::clubs);
            }
            if (i == 2){
                myCards[count] = Card(j+1, Card::diamonds);
            }
            if (i == 3){
                myCards[count] = Card(j+1, Card::spades);
            }

            count++;
            myIndex = 0;
        }
    }
}

void Deck::shuffle(){
    unsigned int currentTime = (unsigned)time(0);
    srand(currentTime);

    Card temp;

    for (int i = 0; i < 104; i++){
        int randIndex = rand() % 51;
        int randIndex2 = rand() % 51;
        
        if (randIndex == randIndex2){
            randIndex2 = rand() % 51;
        }

        temp =  myCards[randIndex];
        myCards[randIndex] = myCards[randIndex2];
        myCards[randIndex2] = temp;
    }
}



Card Deck::dealCard(){

    if(size() == 0) {       //deck is empty, no cards left to deal
        Card sp0(0, Card::spades);
        return sp0;
    }
    else {
        Card r = myCards[myIndex];
        myIndex++;
        return r;
    }


}

int Deck::size() const {

    int counter = 0;
    for(int i = myIndex; i <SIZE; i++){
       counter ++;
    }

    return counter;


}


