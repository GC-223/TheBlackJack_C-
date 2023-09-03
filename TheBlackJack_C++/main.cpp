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


// a function to deal the starting amount of cards
void startingHands( std::vector<Player>& players , const std::array<Card, 52>& deck , int& deckIndex )
{
    for ( int p = 0 ; p < players.size() ; ++p )
    {
        if ( players[p].name == "Dealer" )
        {
            dealCard( deck, players[p], deckIndex ) ;
            ++deckIndex ;
        }
        else
        {
            dealCard( deck, players[p], deckIndex ) ;
            ++deckIndex ;
            dealCard( deck, players[p], deckIndex ) ;
            ++deckIndex ;
        }
    }
}

// now a function to print each players information
void printAllPlayers( const std::vector<Player>& players )
{
    int dealerIndex { static_cast<int>(players.size() - 1) } ;
    
    std::cout << players[dealerIndex].name << " Hand: " ;
    printHand( players[dealerIndex].hand ) ;
    
    std::cout << "\t\t" << players[dealerIndex].name << " Score: " << evaluateHand( players[dealerIndex] ) << '\n' ;
    
    for ( int p = 0 ; p < players.size() - 1 ; ++p )
    {
        std::cout << players[p].name << " Hand: " ;
        printHand( players[p].hand ) ;
        std::cout << '\t' << players[p].name << " Score: " << evaluateHand( players[p] ) << '\n' ;
    }
}

// a function to loop through all players for each turn
void play ( std::vector<Player>& players )
{
    for ( int i = 0 )
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
    
    
    // We can implement this functionality much later
//    // lets add a function that will give us a number of players
//    int numPlayers { getNumPlayers() } ;
//
//    // now a function to populate the player vector with players
//    std::vector<Player> players { } ;
    
    
    std::cout << '\n' ;
    
    if ( playBlackJack( deck ) )
    {
        std::cout << "You Win!\n" ;
    }
    else
    {
        std::cout << "You Lose\n" ;
    }
    
    
}
