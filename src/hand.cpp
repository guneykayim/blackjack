#include "hand.hpp"

namespace CardGame {
  void Hand::addCard(Card& card) {
    if(card.isValid()) {
      this->cards.emplace_back(&card);
    }
  }

  std::vector<Card*>& Hand::getCards() {
    return this->cards;
  }

  void Hand::reset() {
    this->cards.clear();
  }
}
