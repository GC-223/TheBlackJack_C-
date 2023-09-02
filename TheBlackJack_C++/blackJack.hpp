//
//  blackJack.hpp
//  TheBlackJack_C++
//
//  Created by Greyson Chavez on 8/30/23.
//

#ifndef blackJack_hpp
#define blackJack_hpp

#include "card.hpp"
#include "deck.hpp"
#include "player.hpp"





// true if the player wins
bool playBlackJack( const std::array<Card, 52>& deck ) ;

// true if the player busts
bool playerTurn( const std::array<Card, 52>& deck , Player& player , int& deckIndex ) ;

// return true if the dealer busts
bool dealerTurn( const std::array<Card, 52>& deck , Player& player , int& deckIndex ) ;

// true if hit
bool hitOrStay() ;

// true if bust
bool isBust( Player& player ) ;

// true if playerWins
bool winOrLose( Player& player , Player& dealer ) ;

#endif /* blackJack_hpp */
