//
//  player.cpp
//  TheBlackJack_C++
//
//  Created by Greyson Chavez on 8/30/23.
//

#include "player.hpp"

// Get the total score of the hand
int evaluateHand( const Player& player )
{
    int totalValue { 0 } ;
    for ( const auto& card : player.hand )
    {
        totalValue += getCardValue( card.rank ) ;
    }
    
    return totalValue ;
}




