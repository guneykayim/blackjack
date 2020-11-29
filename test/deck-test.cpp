#include "gtest/gtest.h"
#include "deck.hpp"

using CardGame::Suite;
using CardGame::Card;
using CardGame::Deck;

TEST(DeckTest, cardsLeft1) {
    Deck deck { };
    
    EXPECT_EQ (deck.cardsLeft(), 52);
}

TEST(DeckTest, cardsLeft2) {
    Deck deck { };
    deck.shuffle();

    EXPECT_EQ (deck.cardsLeft(), 52);
}

TEST(DeckTest, cardsLeft3) {
    Deck deck { };
    deck.shuffle();
    for(int i = 0; i < 20; ++i) {
        deck.dealCard();
    }

    EXPECT_EQ (deck.cardsLeft(), 32);
}

TEST(DeckTest, cardsLeft4) {
    Deck deck { };
    deck.shuffle();
    for(int i = 0; i < 52; ++i) {
        deck.dealCard();
    }

    EXPECT_EQ (deck.cardsLeft(), 0);
}

TEST(DeckTest, cardsLeft5) {
    Deck deck { };
    deck.shuffle();
    for(int i = 0; i < 52; ++i) {
        deck.dealCard();
    }

    Card card = deck.dealCard();

    EXPECT_FALSE (card.isValid());
}
