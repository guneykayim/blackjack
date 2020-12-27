#ifndef CARD_HPP_
#define CARD_HPP_

#include "stdint.h"
#include <string>
#include <unordered_map>

namespace CardGame {
  enum class Suite { HEARTS, CLUBS, SPADES, DIAMONDS };
  static const std::string suiteStrings[] = {"Hearts", "Clubs", "Spades", "Diamonds"};
  static const std::unordered_map<uint8_t, std::string> valueStrings = { { (uint8_t)1, "Ace" }, { (uint8_t)11, "Jack" }, { (uint8_t)12, "Queen"} , { (uint8_t)13, "King" } };

  class Card {
  public:
    Card() = default;
    Card(uint8_t value, Suite suite);
    uint8_t getValue() const;
    std::string getStringValue() const;
    Suite getSuite() const;
    std::string getSuiteName() const;
    bool isValid() const;
    friend std::ostream& operator<<(std::ostream &stream, const Card &card);
  private:
    uint8_t _value { };
    Suite _suite { };
    bool _initialized { false };
  };
}

#endif // CARD_HPP_
