/* *
 * Michael Burrage II
 * BlackJack game.cpp
 * 
 * */

#include <vector>
#include <numeric>
#include <iostream>
#include "blackjack.h"

void Game::print(std::vector<int> const &input){
    for ( int i = 0 ; i < input.size() ; i++ ){
        std::cout<< input.at(i) << ' ';
    }
};

//deck
int Game::deck[52] = { 1,2,3,4,5,6,7,8,9,10,10,10,10,
                       1,2,3,4,5,6,7,8,9,10,10,10,10,
                       1,2,3,4,5,6,7,8,9,10,10,10,10,
                       1,2,3,4,5,6,7,8,9,10,10,10,10
                     };

//check bust
int Game::isBust(std::vector<int> h){
    int handValue  = std::accumulate(h.begin(), h.end(), 0);
    if( handValue > 21 ){ //if bust
        //if an 11 turn to 1

        return -1;
    } else {
        return handValue;
    }
};

//getwinner
void Game::getWinner(Player p , Dealer d){
    std::cout<< "Your Cards "; print(p.pHand); std::cout<< " = " << isBust(p.pHand) << "\n";
    std::cout<< "Dealers Cards "; print(d.hand); std::cout<< " = " << isBust(d.hand) << "\n";
    
    if(isBust(p.pHand) == -1 ){ //player bust, dealer wins
        std::cout<< "Dealer Wins" << "\n";
        return;
    }

    if(isBust(d.hand) == -1 ){ //dealer bust, player wins
        std::cout<< "Player Wins" << "\n";
        return;
    }

    int playerHand = std::accumulate(p.pHand.begin(), p.pHand.end(), 0);
    int dealerHand = std::accumulate(d.hand.begin(), d.hand.end(), 0);
    print(p.pHand);
    print(d.hand);
    std::cout<< "Player Value: " << playerHand << "\n";
    std::cout<< "Dealer Value: " << dealerHand << "\n";

    if( playerHand>dealerHand ){ //player>dealer, player wins
        std::cout<< "Player Wins" << "\n";
    } else if( dealerHand>playerHand ) { //dealer>player, dealer wins
        std::cout<< "Dealer Wins" << "\n";
    } else { //hands are equal draw.
        std::cout<< "Draw" << "\n";
    }

    return;
};

//startGame
void Game::startGame(){
    Dealer* dealer = new Dealer;
    Player* player = new Player;
    Game* game = new Game;
    int cardNum = 0;
    int choice;
    bool isStay = false;

    /* Shuffle Deck */
    dealer->shuffle(game->deck); //--> shuffle 52 numbers

    /* Start Game */ 
    player->pHand.push_back(game->deck[cardNum]);
    cardNum++;
    player->pHand.push_back(game->deck[cardNum]);
    cardNum++;
    dealer->hand.push_back(game->deck[cardNum]);
    cardNum++;
    dealer->hand.push_back(game->deck[cardNum]);
    cardNum++;

    //Players Turn
    std::cout<< "Dealers Card: " << dealer->hand.back() << "\n";
    while(isStay == false){
        std::cout<< "Your Cards "; print(player->pHand); std::cout<< "\n";
        std::cout<< "Stay (0) or Hit (1) ?" << "\n"; 
        std::cin >> choice;
        if( choice == 0 ){ // Stay
            isStay = true;
            game->isBust(player->pHand); //check for bust
        } else if ( choice == 1 ){ // Hit
            player->pHand.push_back(game->deck[cardNum]);
            cardNum++;
        } else { // invalid response
            std::cout<< "invalid";
        }
    }   

    //Dealers Turn
    isStay = false;
    while(isStay == false){
        std::cout<< "Dealers Cards "; print(dealer->hand); std::cout<< "\n";
        choice = dealer->dealersTurn( game->isBust(dealer->hand) );
        if( choice == 0 ){ // Stay
            isStay = true;
            game->isBust(dealer->hand); //check for bust
        } else { // Hit
            dealer->hand.push_back(game->deck[cardNum]);
            cardNum++;
        }
    }
    
    game->getWinner(*player,*dealer);

    delete game;
    delete dealer;
    delete player;

};

