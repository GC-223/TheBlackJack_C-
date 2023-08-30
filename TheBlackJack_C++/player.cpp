//
//  player.cpp
//  TheBlackJack_C++
//
//  Created by Greyson Chavez on 8/30/23.
//

#include "player.hpp"

int evaluateHand( const Player& player )
{
    int totalValue { 0 } ;
    for ( const auto& card : player.hand )
    {
        totalValue += getCardValue( card.rank ) ;
    }
    
    return totalValue ;
}
