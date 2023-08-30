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

std::array<Card, 52> newDeck() ;

void shuffleDeck( std::array<Card, 52>& deck ) ;

void dealCard( const std::array<Card, 52>& deck , Player& player , int& deckIndex ) ;


#endif /* deck_hpp */
