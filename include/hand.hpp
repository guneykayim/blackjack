#ifndef HAND_HPP_
#define HAND_HPP_

#include <vector>
#include "card.hpp"

namespace CardGame {
  class Hand {
  public:
    virtual void addCard(Card& card);
    virtual int getScore() const = 0;
    virtual std::vector<Card*>& getCards();
    virtual void reset();
    virtual ~Hand() = default;
  protected:
    std::vector<Card*> cards;
  };
}

#endif // HAND_HPP_
