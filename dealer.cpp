/* *
 * Michael Burrage II
 * BlackJack dealer.cpp
 * */
#include <vector>
#include <numeric>
#include <stdlib.h>
#include "blackjack.h"

std::vector<int> hand;

/**
 * int deck[52] = { 1,2,3,4,5,6,7,8,9,10,10,10,10,
                    1,2,3,4,5,6,7,8,9,10,10,10,10,
                    1,2,3,4,5,6,7,8,9,10,10,10,10,
                    1,2,3,4,5,6,7,8,9,10,10,10,10
                };
**/
//shuffle cards
void Dealer::shuffle(int cards[]){
    srand( time(NULL) * 1000 );
    int r;

    for( int i = 0 ; i < 52 ; i++ ){
        // Random for remaining positions. 
        r = i + (rand() % (52 - i)); 
  
        std::swap(cards[i], cards[r]); 
    }
};

//dealers turn
int Dealer::dealersTurn(int n ){
    if( n > 15 ){ //if bust
        return 0;
    } else {
        return 1;
    }
};



