/* *
 * Michael Burrage II
 * BlackJack game header
 * */

#include "dealer.h"
#include "player.h"

//deck
class Game {
    //print vector
    void print(std::vector<int> const &input);
  public:
    static int deck[52];
    //check bust
    int isBust(std::vector<int> h);

    //getwinner
    void getWinner(Player p , Dealer d);

    //startGame
    void startGame ();
    
};


