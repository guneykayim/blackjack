#ifndef BLACKJACKHAND_HPP_
#define BLACKJACKHAND_HPP_

#include "hand.hpp"

namespace CardGame {
  class BlackjackHand : public Hand {
  public:
    int getScore() const override;
    bool isBlackjack() const;
    bool isBusted() const;
  private:
    static constexpr unsigned blackjack { 21 };
  };
}

#endif // BLACKJACKHAND_HPP_
