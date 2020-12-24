#include "gtest/gtest.h"
#include "blackjackdeck.hpp"
#include "card.hpp"

using CardGame::Suite;
using CardGame::Card;
using CardGame::BlackjackDeck;
using CardGame::BlackjackDeckType;

TEST(BlackjackDeckTest, cardsLeft1) {
    BlackjackDeck deck { };
    
    EXPECT_EQ (deck.cardsLeft(), 52);
}

TEST(BlackjackDeckTest, cardsLeft2) {
    BlackjackDeck deck { BlackjackDeckType::SINGLE };
    
    EXPECT_EQ (deck.cardsLeft(), 52);
}

TEST(BlackjackDeckTest, cardsLeft3) {
    BlackjackDeck deck { BlackjackDeckType::DOUBLE };
    
    EXPECT_EQ (deck.cardsLeft(), 52*2);
}

TEST(BlackjackDeckTest, cardsLeft4) {
    BlackjackDeck deck { BlackjackDeckType::FOUR };
    
    EXPECT_EQ (deck.cardsLeft(), 52*4);
}

TEST(BlackjackDeckTest, cardsLeft5) {
    BlackjackDeck deck { BlackjackDeckType::SIX };
    
    EXPECT_EQ (deck.cardsLeft(), 52*6);
}

TEST(BlackjackDeckTest, cardsLeft6) {
    BlackjackDeck deck { BlackjackDeckType::EIGHT };
    
    EXPECT_EQ (deck.cardsLeft(), 52*8);
}

TEST(BlackjackDeckTest, cardsLeft7) {
    BlackjackDeck deck { BlackjackDeckType::EIGHT };

    int n = 200;
    for(int i = 0; i < n; ++i) {
        deck.dealCard();
    }
    
    EXPECT_EQ (deck.cardsLeft(), 52*8 - n);
}

TEST(BlackjackDeckTest, dealCard1) {
    BlackjackDeck deck { BlackjackDeckType::SINGLE };
    EXPECT_TRUE (deck.dealCard().isValid());
}

TEST(BlackjackDeckTest, dealCard2) {
    BlackjackDeck deck { BlackjackDeckType::SINGLE };

    int n = 20;
    for(int i = 0; i < n; ++i) {
        deck.dealCard();
    }
    
    EXPECT_TRUE (deck.dealCard().isValid());
}

TEST(BlackjackDeckTest, dealCard3) {
    BlackjackDeck deck { BlackjackDeckType::SINGLE };

    int n = 52;
    for(int i = 0; i < n; ++i) {
        deck.dealCard();
    }
    
    EXPECT_FALSE (deck.dealCard().isValid());
}

TEST(BlackjackDeckTest, dealCard4) {
    BlackjackDeck deck { BlackjackDeckType::DOUBLE };
    EXPECT_TRUE (deck.dealCard().isValid());
}

TEST(BlackjackDeckTest, dealCard5) {
    BlackjackDeck deck { BlackjackDeckType::DOUBLE };

    int n = 50;
    for(int i = 0; i < n; ++i) {
        deck.dealCard();
    }
    
    EXPECT_TRUE (deck.dealCard().isValid());
}

TEST(BlackjackDeckTest, dealCard6) {
    BlackjackDeck deck { BlackjackDeckType::DOUBLE };

    int n = 52*2;
    for(int i = 0; i < n; ++i) {
        deck.dealCard();
    }
    
    EXPECT_FALSE (deck.dealCard().isValid());
}

TEST(BlackjackDeckTest, dealCard7) {
    BlackjackDeck deck { BlackjackDeckType::FOUR };
    EXPECT_TRUE (deck.dealCard().isValid());
}

TEST(BlackjackDeckTest, dealCard8) {
    BlackjackDeck deck { BlackjackDeckType::FOUR };

    int n = 100;
    for(int i = 0; i < n; ++i) {
        deck.dealCard();
    }
    
    EXPECT_TRUE (deck.dealCard().isValid());
}

TEST(BlackjackDeckTest, dealCard9) {
    BlackjackDeck deck { BlackjackDeckType::FOUR };

    int n = 52*4;
    for(int i = 0; i < n; ++i) {
        deck.dealCard();
    }
    
    EXPECT_FALSE (deck.dealCard().isValid());
}

TEST(BlackjackDeckTest, dealCard10) {
    BlackjackDeck deck { BlackjackDeckType::SIX };
    EXPECT_TRUE (deck.dealCard().isValid());
}

TEST(BlackjackDeckTest, dealCard11) {
    BlackjackDeck deck { BlackjackDeckType::SIX };

    int n = 150;
    for(int i = 0; i < n; ++i) {
        deck.dealCard();
    }
    
    EXPECT_TRUE (deck.dealCard().isValid());
}

TEST(BlackjackDeckTest, dealCard12) {
    BlackjackDeck deck { BlackjackDeckType::SIX };

    int n = 52*6;
    for(int i = 0; i < n; ++i) {
        deck.dealCard();
    }
    
    EXPECT_FALSE (deck.dealCard().isValid());
}

TEST(BlackjackDeckTest, dealCard13) {
    BlackjackDeck deck { BlackjackDeckType::EIGHT };
    EXPECT_TRUE (deck.dealCard().isValid());
}

TEST(BlackjackDeckTest, dealCard14) {
    BlackjackDeck deck { BlackjackDeckType::EIGHT };

    int n = 200;
    for(int i = 0; i < n; ++i) {
        deck.dealCard();
    }
    
    EXPECT_TRUE (deck.dealCard().isValid());
}

TEST(BlackjackDeckTest, dealCard15) {
    BlackjackDeck deck { BlackjackDeckType::EIGHT };

    int n = 52*8;
    for(int i = 0; i < n; ++i) {
        deck.dealCard();
    }
    
    EXPECT_FALSE (deck.dealCard().isValid());
}