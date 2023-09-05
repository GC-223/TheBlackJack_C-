//
//  main.cpp
//  TheBlackJack_C++
//
//  Created by Greyson Chavez on 8/30/23.
//

#include <array>
#include <iostream>

#include "blackJack.hpp"
#include "card.hpp"
#include "deck.hpp"
#include "player.hpp"
















// a function to tell if win or lost
// true for win
//bool winOrLose( const Player& player, const Player& dealer )
//{
//    if ( isBust( player ) )
//    {
//        return false ;
//    }
//    else if ( player.)
//}


// a function to loop through all players for each turn
void playBlackJackJAAAACK ( const std::array<Card, 52>& deck )
{
    int deckIndex { 0 } ;
    
    std::vector<Player> players (getNumPlayers() + 1 ) ;
    
    givePlayerName( players ) ;
    
    startingHands( players, deck, deckIndex ) ;
    
    printAllPlayers( players ) ;
    
    
    for ( int p = 0 ; p < players.size() ; ++p )
    {
        if ( players[p].name == "Dealer" )
        {
            if ( dealerTurn( deck, players[p], deckIndex ) )
            {
                players[p].busted = true ;
            }
        }
        else
        {
            if ( playerTurn( deck, players[p], deckIndex ) )
            {
                players[p].busted = true ;
            }
        }
    }
}



int main(int argc, const char * argv[])
{
    
    
//    // for multiplayer we wil need a vector of players
//    std::vector<Player> players (getNumPlayers() + 1) ;
//
//    givePlayerName( players ) ;
    
    
    
    
    // we are now going to need some function that will deal everyone's cards
    
    std::array<Card, 52> deck { newDeck() } ;
    
    printHand( deck ) ;
    std::cout << '\n' ;
    
    shuffleDeck( deck ) ;
    
    
    std::cout << '\n' ;
    
    playBlackJackJAAAACK ( deck ) ;

    
//    if ( playBlackJack( deck ) )
//    {
//        std::cout << "You Win!\n" ;
//    }
//    else
//    {
//        std::cout << "You Lose\n" ;
//    }
    
    
}
