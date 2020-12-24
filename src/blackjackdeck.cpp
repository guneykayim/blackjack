#include "blackjackdeck.hpp"

namespace CardGame {
    BlackjackDeck::BlackjackDeck() {
        initDecks(BlackjackDeckType::SINGLE);
    }

    BlackjackDeck::BlackjackDeck(BlackjackDeckType deckType) {
        initDecks(deckType);
    }

    void BlackjackDeck::initDecks(BlackjackDeckType deckType) {
        _numDecks = static_cast<int>(deckType);
        _rng = std::mt19937(_rd());
        _distr = std::uniform_int_distribution<>(0, _numDecks-1);
        for(int i = 0; i < _numDecks; ++i) {
            Deck d;
            d.shuffle();
            _decks.emplace_back(d);
        }
    }

    Card& BlackjackDeck::dealCard() {
        auto i = _distr(_rng);
        if(cardsLeft()) {
            while(_decks[i].cardsLeft() == 0) {
                ++i;
                i = i % _numDecks;
            }
            return _decks[i].dealCard();
        } else {
            // no cards left, so this will return a void card
            return _decks[0].dealCard();
        }
    }

    int BlackjackDeck::cardsLeft() const {
        int c = 0;
        for(const Deck &d : _decks) {
            c += d.cardsLeft();
        }
        return c;
    }
}
