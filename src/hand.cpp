#include "hand.hpp"

namespace CardGame {
  void Hand::addCard(Card& card) {
    if(card.isValid()) {
      _cards.emplace_back(&card);
    }
  }

  std::vector<Card*>& Hand::getCards() {
    return _cards;
  }

  void Hand::reset() {
    _cards.clear();
  }
}
