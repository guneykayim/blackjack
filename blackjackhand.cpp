#include "blackjackhand.hpp"

namespace CardGame {
    int BlackjackHand::getScore() const {
      int v { 0 };
      //TODO implement me
      return v;
    }

    bool BlackjackHand::isBlackJack() const {
      return this->cards.size() == 2 && this->getScore() == this->blackjack;
    }

    bool BlackjackHand::isBusted() const {
      return this->getScore() > this->blackjack;
    }
}
