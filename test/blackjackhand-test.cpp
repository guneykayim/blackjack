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

TEST(BlackjackHandTest, isBlackjack3) {
    Card c1 { 1, Suite::HEARTS };
    Card c2 { 11, Suite::HEARTS };
    Card c3 { 12, Suite::DIAMONDS };
    BlackjackHand hand { };
    hand.addCard(c1);
    hand.addCard(c2);
    hand.addCard(c3);
    
    EXPECT_FALSE (hand.isBlackjack());
}

TEST(BlackjackHandTest, isBusted1) {
    Card c1 { 1, Suite::HEARTS };
    Card c2 { 9, Suite::HEARTS };
    BlackjackHand hand { };
    hand.addCard(c1);
    hand.addCard(c2);
    
    EXPECT_FALSE (hand.isBusted());
}

TEST(BlackjackHandTest, isBusted2) {
    Card c1 { 1, Suite::HEARTS };
    Card c2 { 9, Suite::HEARTS };
    Card c3 { 9, Suite::DIAMONDS };
    BlackjackHand hand { };
    hand.addCard(c1);
    hand.addCard(c2);
    hand.addCard(c3);
    
    EXPECT_FALSE (hand.isBusted());
}

TEST(BlackjackHandTest, isBusted3) {
    Card c1 { 1, Suite::HEARTS };
    Card c2 { 13, Suite::HEARTS };
    Card c3 { 13, Suite::DIAMONDS };
    BlackjackHand hand { };
    hand.addCard(c1);
    hand.addCard(c2);
    hand.addCard(c3);
    
    EXPECT_FALSE (hand.isBusted());
}

TEST(BlackjackHandTest, isBusted4) {
    Card c1 { 9, Suite::SPADES };
    Card c2 { 9, Suite::HEARTS };
    Card c3 { 9, Suite::HEARTS };
    BlackjackHand hand { };
    hand.addCard(c1);
    hand.addCard(c2);
    hand.addCard(c3);
    
    EXPECT_TRUE (hand.isBusted());
}