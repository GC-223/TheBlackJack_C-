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
bool dealerTurn( const std::array<Card, 52>& deck , Player& dealer , int& deckIndex ) ;

// true if hit
bool hitOrStay( const Player& player ) ;

// true if bust
bool isBust( const Player& player ) ;

// deals starting amount of cards
void startingHands( std::vector<Player>& players , const std::array<Card, 52>& deck , int& deckIndex ) ;



// prints info for all players
void printAllPlayers( const std::vector<Player>& players ) ;

// prints info for one player
void printOnePlayer( const Player& player ) ;




#endif /* blackJack_hpp */
