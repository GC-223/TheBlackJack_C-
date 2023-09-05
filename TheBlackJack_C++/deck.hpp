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

#include "player.hpp"
#include "card.hpp"



// we can print the player hand, or we can print the entire deck for this function
template <typename T>
void printHand( const T& hand )
{
    for ( const auto& card : hand )
    {
        printCard( card ) ;
        std::cout << ' ' ;
    }
}


// Creates a brand new (non-shuffled) deck of cards
std::array<Card, 52> newDeck() ;

// shuffles the deck
void shuffleDeck( std::array<Card, 52>& deck ) ;

// deals one card to a player
// maybe this should be in playBlackJack
void dealCard( const std::array<Card, 52>& deck , Player& player , int& deckIndex ) ;



#endif /* deck_hpp */
