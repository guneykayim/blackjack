#include "gtest/gtest.h"
#include "blackjackhand.hpp"
#include "card.hpp"

using CardGame::Suite;
using CardGame::Card;
using CardGame::BlackjackHand;

TEST(BlackjackHandTest, isBlackjack1) {
    Card c1 { 1, Suite::HEARTS };
    Card c2 { 10, Suite::HEARTS };
    BlackjackHand hand { };
    hand.addCard(c1);
    hand.addCard(c2);
    
    EXPECT_TRUE (hand.isBlackjack());
}

TEST(BlackjackHandTest, isBlackjack2) {
    Card c1 { 1, Suite::HEARTS };
    Card c2 { 9, Suite::HEARTS };
    BlackjackHand hand { };
    hand.addCard(c1);
    hand.addCard(c2);
    
    EXPECT_FALSE (hand.isBlackjack());
}