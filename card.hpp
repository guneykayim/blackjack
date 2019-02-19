#ifndef CARD_HPP_
#define CARD_HPP_

#include "stdint.h"
#include <string>

enum class Suite { HEARTS, CLUBS, SPADES, DIAMONDS };
static const std::string suiteStrings[] = {"Hearts", "Clubs", "Spades", "Diamonds"};

class Card {
public:
  Card() = default;
  Card(uint8_t value, Suite suite);
  uint8_t getValue() const;
  Suite getSuite() const;
  std::string getSuiteName() const;
  bool isValid() const;
  friend std::ostream& operator<<(std::ostream &stream, const Card &card);
private:
  uint8_t value { };
  Suite suite { };
  bool initialized { false };
};

#endif // CARD_HPP_
