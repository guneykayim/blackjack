#include "blackjackhand.hpp"

namespace CardGame {
    int BlackjackHand::getScore() const {
      int score { 0 };
      int numAces { 0 };

      for(Card* c : _cards) {
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
          if(score > _blackjack) {
            score -= 10;
          }
        }
      }

      return score;
    }

    bool BlackjackHand::isBlackjack() const {
      return _cards.size() == 2 && getScore() == _blackjack;
    }

    bool BlackjackHand::isBusted() const {
      return getScore() > _blackjack;
    }
}
