#include "card.hpp"
#include <iostream>

Card::Card(uint8_t value, Suite suite) : value { std::max<uint8_t>(std::min<uint8_t>(value, 13), 1) }, suite { suite }, initialized { true } {
}

uint8_t Card::getValue() const {
  return this->value;
}

Suite Card::getSuite() const {
  return this->suite;
}

std::string Card::getSuiteName() const {
  return suiteStrings[static_cast<int>(this->suite)];
}

bool Card::isValid() const {
  return this->initialized;
}

std::ostream& operator<<(std::ostream &stream, const Card &card) {
  if (card.isValid()) {
    stream << std::to_string(card.getValue()) << " of " << card.getSuiteName();
  } else {
    stream << "Invalid Card!";
  }
  return stream;
}
