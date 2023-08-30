//
//  player.hpp
//  TheBlackJack_C++
//
//  Created by Greyson Chavez on 8/30/23.
//

#ifndef player_hpp
#define player_hpp

#include <iostream>
#include "card.hpp"


struct Player
{
    std::string name { } ;
    std::vector<Card> hand { } ;
} ;

// Get the total score of the hand
int evaluateHand( const Player& player ) ;

// we can print the player hand, or we can print the entire deck for this function
template <typename T>
void printHand( const T& hand ) ;

#endif /* player_hpp */
