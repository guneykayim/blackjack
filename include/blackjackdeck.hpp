#ifndef BLACKJACKDECK_HPP_
#define BLACKJACKDECK_HPP_

#include <vector>
#include <random>
#include "deck.hpp"

namespace CardGame {
    enum class BlackjackDeckType { SINGLE = 1, DOUBLE = 2, FOUR = 4, SIX = 6, EIGHT = 8 };

    class BlackjackDeck {
    public:
        BlackjackDeck();
        BlackjackDeck(BlackjackDeckType deckType);
        BlackjackDeck(const BlackjackDeck &);
        BlackjackDeck& operator=(const BlackjackDeck &);

        Card& dealCard();
        int cardsLeft() const;

    private:
        int _numDecks;
        std::vector<Deck> _decks;
        std::random_device _rd;
        std::mt19937 _rng;
        std::uniform_int_distribution<> _distr;

        void initDecks(BlackjackDeckType deckType);
    };
}

#endif // BLACKJACKDECK_HPP_
