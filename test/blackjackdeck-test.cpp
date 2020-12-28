#include "gtest/gtest.h"
#include "blackjackdeck.hpp"
#include "card.hpp"

using CardGame::Suite;
using CardGame::Card;
using CardGame::BlackjackDeck;
using CardGame::BlackjackDeckType;

TEST(BlackjackDeckCardsLeft, test1) {
    BlackjackDeck deck { };
    
    EXPECT_EQ (deck.cardsLeft(), 52);
}

TEST(BlackjackDeckCardsLeft, test2) {
    BlackjackDeck deck { BlackjackDeckType::SINGLE };
    
    EXPECT_EQ (deck.cardsLeft(), 52);
}

TEST(BlackjackDeckCardsLeft, test3) {
    BlackjackDeck deck { BlackjackDeckType::DOUBLE };
    
    EXPECT_EQ (deck.cardsLeft(), 52*2);
}

TEST(BlackjackDeckCardsLeft, test4) {
    BlackjackDeck deck { BlackjackDeckType::FOUR };
    
    EXPECT_EQ (deck.cardsLeft(), 52*4);
}

TEST(BlackjackDeckCardsLeft, test5) {
    BlackjackDeck deck { BlackjackDeckType::SIX };
    
    EXPECT_EQ (deck.cardsLeft(), 52*6);
}

TEST(BlackjackDeckCardsLeft, test6) {
    BlackjackDeck deck { BlackjackDeckType::EIGHT };
    
    EXPECT_EQ (deck.cardsLeft(), 52*8);
}

TEST(BlackjackDeckCardsLeft, test7) {
    BlackjackDeck deck { BlackjackDeckType::EIGHT };

    int n = 200;
    for(int i = 0; i < n; ++i) {
        deck.dealCard();
    }
    
    EXPECT_EQ (deck.cardsLeft(), 52*8 - n);
}

TEST(BlackjackDeckDealCard, test1) {
    BlackjackDeck deck { BlackjackDeckType::SINGLE };
    EXPECT_TRUE (deck.dealCard().isValid());
}

TEST(BlackjackDeckDealCard, test2) {
    BlackjackDeck deck { BlackjackDeckType::SINGLE };

    int n = 20;
    for(int i = 0; i < n; ++i) {
        deck.dealCard();
    }
    
    EXPECT_TRUE (deck.dealCard().isValid());
}

TEST(BlackjackDeckDealCard, test3) {
    BlackjackDeck deck { BlackjackDeckType::SINGLE };

    int n = 52;
    for(int i = 0; i < n; ++i) {
        deck.dealCard();
    }
    
    EXPECT_FALSE (deck.dealCard().isValid());
}

TEST(BlackjackDeckDealCard, test4) {
    BlackjackDeck deck { BlackjackDeckType::DOUBLE };
    EXPECT_TRUE (deck.dealCard().isValid());
}

TEST(BlackjackDeckDealCard, test5) {
    BlackjackDeck deck { BlackjackDeckType::DOUBLE };

    int n = 50;
    for(int i = 0; i < n; ++i) {
        deck.dealCard();
    }
    
    EXPECT_TRUE (deck.dealCard().isValid());
}

TEST(BlackjackDeckDealCard, test6) {
    BlackjackDeck deck { BlackjackDeckType::DOUBLE };

    int n = 52*2;
    for(int i = 0; i < n; ++i) {
        deck.dealCard();
    }
    
    EXPECT_FALSE (deck.dealCard().isValid());
}

TEST(BlackjackDeckDealCard, test7) {
    BlackjackDeck deck { BlackjackDeckType::FOUR };
    EXPECT_TRUE (deck.dealCard().isValid());
}

TEST(BlackjackDeckDealCard, test8) {
    BlackjackDeck deck { BlackjackDeckType::FOUR };

    int n = 100;
    for(int i = 0; i < n; ++i) {
        deck.dealCard();
    }
    
    EXPECT_TRUE (deck.dealCard().isValid());
}

TEST(BlackjackDeckDealCard, test9) {
    BlackjackDeck deck { BlackjackDeckType::FOUR };

    int n = 52*4;
    for(int i = 0; i < n; ++i) {
        deck.dealCard();
    }
    
    EXPECT_FALSE (deck.dealCard().isValid());
}

TEST(BlackjackDeckDealCard, test10) {
    BlackjackDeck deck { BlackjackDeckType::SIX };
    EXPECT_TRUE (deck.dealCard().isValid());
}

TEST(BlackjackDeckDealCard, test11) {
    BlackjackDeck deck { BlackjackDeckType::SIX };

    int n = 150;
    for(int i = 0; i < n; ++i) {
        deck.dealCard();
    }
    
    EXPECT_TRUE (deck.dealCard().isValid());
}

TEST(BlackjackDeckDealCard, test12) {
    BlackjackDeck deck { BlackjackDeckType::SIX };

    int n = 52*6;
    for(int i = 0; i < n; ++i) {
        deck.dealCard();
    }
    
    EXPECT_FALSE (deck.dealCard().isValid());
}

TEST(BlackjackDeckDealCard, test13) {
    BlackjackDeck deck { BlackjackDeckType::EIGHT };
    EXPECT_TRUE (deck.dealCard().isValid());
}

TEST(BlackjackDeckDealCard, test14) {
    BlackjackDeck deck { BlackjackDeckType::EIGHT };

    int n = 200;
    for(int i = 0; i < n; ++i) {
        deck.dealCard();
    }
    
    EXPECT_TRUE (deck.dealCard().isValid());
}

TEST(BlackjackDeckDealCard, test15) {
    BlackjackDeck deck { BlackjackDeckType::EIGHT };

    int n = 52*8;
    for(int i = 0; i < n; ++i) {
        deck.dealCard();
    }
    
    EXPECT_FALSE (deck.dealCard().isValid());
}

TEST(BlackjackDeckAssignment, test1) {
    BlackjackDeck deck1 { BlackjackDeckType::EIGHT };
    BlackjackDeck deck2 { };

    int n = 52;
    for(int i = 0; i < n; ++i) {
        deck1.dealCard();
    }

    deck2 = deck1;
    
    EXPECT_EQ (deck1.cardsLeft(), deck2.cardsLeft());
}

TEST(BlackjackDeckAssignment, test2) {
    BlackjackDeck deck1 { BlackjackDeckType::EIGHT };
    BlackjackDeck deck2 { };

    int n = 26;
    for(int i = 0; i < n; ++i) {
        deck2.dealCard();
    }

    deck1 = deck2;
    
    EXPECT_EQ (deck1.cardsLeft(), deck2.cardsLeft());
}

TEST(BlackjackDeckAssignment, test3) {
    BlackjackDeck *deck1 = new BlackjackDeck(BlackjackDeckType::EIGHT);

    int n = 52;
    for(int i = 0; i < n; ++i) {
        deck1->dealCard();
    }

    BlackjackDeck *deck2 = new BlackjackDeck();
    *deck2 = *deck1;
    
    EXPECT_EQ (deck1->cardsLeft(), deck2->cardsLeft());
}

TEST(BlackjackDeckAssignment, test4) {
    BlackjackDeck *deck1 = new BlackjackDeck();

    int n = 26;
    for(int i = 0; i < n; ++i) {
        deck1->dealCard();
    }

    BlackjackDeck *deck2 = new BlackjackDeck(BlackjackDeckType::EIGHT);
    *deck2 = *deck1;
    delete deck1;
    
    EXPECT_EQ (deck2->cardsLeft(), 26);
}
TEST(BlackjackDeckCopy, test1) {
    BlackjackDeck deck1 { BlackjackDeckType::EIGHT };

    int n = 52;
    for(int i = 0; i < n; ++i) {
        deck1.dealCard();
    }

    BlackjackDeck deck2 = deck1;
    
    EXPECT_EQ (deck1.cardsLeft(), deck2.cardsLeft());
}

TEST(BlackjackDeckCopy, test2) {
    BlackjackDeck deck2 { };

    int n = 26;
    for(int i = 0; i < n; ++i) {
        deck2.dealCard();
    }

    BlackjackDeck deck1 = deck2;
    
    EXPECT_EQ (deck1.cardsLeft(), deck2.cardsLeft());
}

TEST(BlackjackDeckCopy, test3) {
    BlackjackDeck *deck1 = new BlackjackDeck(BlackjackDeckType::EIGHT);

    int n = 52;
    for(int i = 0; i < n; ++i) {
        deck1->dealCard();
    }

    BlackjackDeck *deck2 = new BlackjackDeck(*deck1);
    
    EXPECT_EQ (deck1->cardsLeft(), deck2->cardsLeft());
}

TEST(BlackjackDeckCopy, test4) {
    BlackjackDeck *deck1 = new BlackjackDeck();

    int n = 26;
    for(int i = 0; i < n; ++i) {
        deck1->dealCard();
    }

    BlackjackDeck *deck2 = new BlackjackDeck(*deck1);
    delete deck1;
    
    EXPECT_EQ (deck2->cardsLeft(), 26);
}