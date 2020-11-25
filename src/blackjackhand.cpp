#include "blackjackhand.hpp"

namespace CardGame {
    int BlackjackHand::getScore() const {
      int score { 0 };
      int numAces { 0 };

      for(Card* c : this->cards) {
        auto v = std::min<uint8_t>(10, c->getValue());
        if(v == 1) { // ace
          ++numAces;
        } else {
          score += v;
        }
      }

      if (score > 10) {
        score += numAces;
      } else {
        if(numAces > 0) {
          score += 11 + numAces - 1;
          if(score > this->blackjack) {
            score -= 10;
          }
        }
      }

      return score;
    }

    bool BlackjackHand::isBlackJack() const {
      return this->cards.size() == 2 && this->getScore() == this->blackjack;
    }

    bool BlackjackHand::isBusted() const {
      return this->getScore() > this->blackjack;
    }
}
