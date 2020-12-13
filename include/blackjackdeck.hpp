#ifndef BLACKJACKDECK_HPP_
#define BLACKJACKDECK_HPP_

#include <vector>
#include "deck.hpp"

namespace CardGame {
    class BlackjackDeck {
    public:
        BlackjackDeck();
        BlackjackDeck(int numDecks);

    private:
        int numDecks;
        std::vector<Deck> decks;
    };
}

#endif // BLACKJACKDECK_HPP_
