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
    else

        return myCards[myIndex];



}

int Deck::size() const {

    for(int i = 0; i)


}


