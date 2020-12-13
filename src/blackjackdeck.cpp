#include "blackjackdeck.hpp"

namespace CardGame {
    BlackjackDeck::BlackjackDeck() : numDecks { 1 } {
    }

    BlackjackDeck::BlackjackDeck(int numDecks) : numDecks { numDecks } {
        ///TODO: init numDecks many decks
    }
}
