

#include "card.h"
#include <string>

using namespace std;

Card::Card() {
    myRank = 1;
    mySuit = spades;

}

Card::Card(int rank, Suit s) {
    myRank = rank;
    mySuit = s;
}

string Card ::toString() const {
    string rankVal = rankString(this->myRank);
    string suitVal = suitString(this->mySuit);
    string cardVal = rankVal+suitVal;
    return cardVal;


}

int Card ::getRank() const {
    return myRank;
}

string Card ::suitString(Suit s) const {
    string suit;
    if(s == spades){
        suit = s;
    }
    if(s == hearts){
        suit = h;
    }
    if(s == diamonds){
        suit = d;
    }
    if(s == clubs){
        suit = c;
    }
    return suit;


}

string Card ::rankString(int r) const {
    string rank;
    if(r >= 2 && r<=10){
        rank = (char)r;
    }
    if(r == 1){
        rank = A;
    }
    if(r == 11){
        rank = J;
    }
    if(r == 12){
        rank = Q;
    }
    if(r == 13){
        rank = K;
    }
    return rank;

}

bool Card ::operator==(const Card &rhs) const {
    if(mySuit == rhs.mySuit && myRank == rhs.myRank)
        return true;
    else
        return false;

}

bool Card ::operator!=(const Card &rhs) const {
    if(mySuit != rhs.mySuit || myRank != rhs.myRank)
        return true;
    else
        return false;



}




