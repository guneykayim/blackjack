#include "hand.hpp"

namespace CardGame {
  void Hand::addCard(Card& card) {
    this->cards.emplace_back(&card);
  }

  int Hand::getScore() const {
    int score { 0 };
    for(Card* c : this->cards) {
      score += c->getValue();
    }
    return score;
  }

  void Hand::reset() {
    this->cards.clear();
  }
}
