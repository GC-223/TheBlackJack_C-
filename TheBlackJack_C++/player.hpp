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
    int score { 0 } ;
    
    int numChips { 0 } ;
    
    bool busted { false } ;
} ;

// Get the total score of the hand
int evaluateHand( const Player& player ) ;

int getNumPlayers() ;

void givePlayerName( std::vector<Player>& players ) ;



#endif /* player_hpp */
