//
//  deck.hpp
//  TheBlackJack_C++
//
//  Created by Greyson Chavez on 8/30/23.
//

#ifndef deck_hpp
#define deck_hpp

#include <array>
#include <iostream>
#include <random>
#include "card.hpp"
#include "player.hpp"

// Creates a brand new (non-shuffled) deck of cards
std::array<Card, 52> newDeck() ;

// shuffles the deck
void shuffleDeck( std::array<Card, 52>& deck ) ;

// deals one card to a player
void dealCard( const std::array<Card, 52>& deck , Player& player , int& deckIndex ) ;


#endif /* deck_hpp */
