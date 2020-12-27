#ifndef DECK_HPP_
#define DECK_HPP_

#include <vector>
#include "card.hpp"

namespace CardGame {
  class Deck {
  public:
    Deck();
    void shuffle();
    Card& dealCard();
    int cardsLeft() const;
  private:
    std::vector<Card> _cards;
    int _dealIndex { 0 };
    Card _voidCard { };
  };
}

#endif // DECK_HPP_
