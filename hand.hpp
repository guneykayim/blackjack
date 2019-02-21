#ifndef HAND_HPP_
#define HAND_HPP_

#include <vector>
#include "card.hpp"

namespace CardGame {
  class Hand {
  public:
    virtual void addCard(Card& card);
    virtual int getScore() const;
    virtual void reset();
    virtual ~Hand() = default;
  private:
    std::vector<Card*> cards;
  };
}

#endif // HAND_HPP_
