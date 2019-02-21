#include "hand.hpp"

namespace CardGame {
  void Hand::addCard(Card& card) {
    this->cards.emplace_back(&card);
  }

  void Hand::reset() {
    this->cards.clear();
  }
}
