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


// For multiplayer functionality
int getNumPlayers()
{
    std::cout << "How many players (excluding dealer)? " ;
    int numPlayers { } ;
    std::cin >> numPlayers ;
    
    return numPlayers ;
}


// we need a function to give all of the players names
void givePlayerName( std::vector<Player>& players )
{
    for ( int player = 0 ; player < players.size() ; ++player )
    {
        if ( player == players.size() - 1 )
        {
            players[player].name = "Dealer" ;
        }
        else
        {
            players[player].name = "Player " ;
            players[player].name += std::to_string(player + 1) ;
        }
    }
}


