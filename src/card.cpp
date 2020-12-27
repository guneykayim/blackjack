#include "card.hpp"
#include <iostream>
namespace CardGame {
  Card::Card(uint8_t value, Suite suite) : _value { std::max<uint8_t>(std::min<uint8_t>(value, 13), 1) }, _suite { suite }, _initialized { true } {
  }

  uint8_t Card::getValue() const {
    return _value;
  }

  std::string Card::getStringValue() const {
    if(_value > 1 && _value < 11) {
      return std::to_string(_value);
    } else {
      return valueStrings.at(_value);
    }
  }

  Suite Card::getSuite() const {
    return _suite;
  }

  std::string Card::getSuiteName() const {
    return suiteStrings[static_cast<int>(_suite)];
  }

  bool Card::isValid() const {
    return _initialized;
  }

  std::ostream& operator<<(std::ostream &stream, const Card &card) {
    if (card.isValid()) {
      stream << card.getStringValue() << " of " << card.getSuiteName();
    } else {
      stream << "Invalid Card!";
    }
    return stream;
  }
}
