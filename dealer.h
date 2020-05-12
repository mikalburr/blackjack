/* *
 * Michael Burrage II
 * BlackJack dealer header
 * */

#include <vector>

class Dealer {
  public:
    std::vector<int> hand;
    void shuffle(int cards[]);
    int dealersTurn( int n );
};
