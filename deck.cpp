#include "deck.hpp"
#include <algorithm>
#include <random>
#include <chrono>

Deck::Deck() {
  for (int s = 0; s <=3; ++s) {
    for (uint8_t v = 1; v <= 13; ++v) {
      this->cards.emplace_back(Card { v, static_cast<Suite>(s) });
    }
  }
}

void Deck::shuffle() {
  if(this->dealIndex < this->cards.size()) {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine rng { seed };
    std::shuffle(this->cards.begin() + this->dealIndex, this->cards.end(), rng);
  }
}

Card Deck::dealCard() {
  if(this->dealIndex < this->cards.size()) {
    return this->cards[this->dealIndex++];
  } else {
    return Card();
  }
}

int Deck::cardsLeft() const {
  return this->cards.size() - this->dealIndex;
}
