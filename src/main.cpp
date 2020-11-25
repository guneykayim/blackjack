#include <iostream>

#include "card.hpp"
#include "deck.hpp"
#include "blackjackhand.hpp"

using std::cout;
using std::endl;

using namespace CardGame;

int main() {

  Deck deck { };

  cout << "Shuffling the deck" << endl;
  deck.shuffle();

  cout << "\nDealing 2 cards from the deck and discarding them" << endl;
  cout << deck.dealCard() << endl;
  cout << deck.dealCard() << endl;

  BlackjackHand hand { };

  cout << "\nManually creating 3 cards" << endl;
  Card c1 { 1, Suite::HEARTS };
  Card c2 { 10, Suite::DIAMONDS };
  Card c3 { 10, Suite::SPADES };
  cout << c1 << endl;
  cout << c2 << endl;
  cout << c3 << endl;

  cout << "\nAdding the manually created cards to hand" << endl;
  hand.addCard(c1);
  hand.addCard(c2);
  hand.addCard(c3);

  cout << "Score in the hand: " << hand.getScore() << endl;
  cout << "Is it BlackJack? " << ((hand.isBlackJack())? "Yes" : "No") << endl;
  cout << "Is it busted? " << ((hand.isBusted())? "Yes" : "No") << endl;

  cout << "\nResetting the hand" << endl;
  hand.reset();

  cout << "\nDealing 2 cards from the deck and adding them to hand" << endl;
  hand.addCard(deck.dealCard());
  hand.addCard(deck.dealCard());

  auto addedCards = hand.getCards();
  cout << "Dealt cards are:" << endl;
  for(auto c : addedCards) {
    cout << (*c) << endl;
  }
  cout << "Score in the hand: " << hand.getScore() << endl;
  cout << "Is it BlackJack? " << ((hand.isBlackJack())? "Yes" : "No") << endl;
  cout << "Is it busted? " << ((hand.isBusted())? "Yes" : "No") << endl;

  return 0;
}
