#include "deck.hpp"
#include <algorithm>
#include <random>
#include <chrono>

namespace CardGame {
  Deck::Deck() {
    for (int s = 0; s <=3; ++s) {
      for (uint8_t v = 1; v <= 13; ++v) {
        _cards.emplace_back(Card { v, static_cast<Suite>(s) });
      }
    }
  }

  void Deck::shuffle() {
    if(_dealIndex < _cards.size()) {
      unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
      std::default_random_engine rng { seed };
      std::shuffle(_cards.begin() + _dealIndex, _cards.end(), rng);
    }
  }

  Card& Deck::dealCard() {
    if(_dealIndex < _cards.size()) {
      return _cards[_dealIndex++];
    } else {
      return _voidCard;
    }
  }

  int Deck::cardsLeft() const {
    return _cards.size() - _dealIndex;
  }
}
