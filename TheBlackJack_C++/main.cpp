//
//  main.cpp
//  TheBlackJack_C++
//
//  Created by Greyson Chavez on 8/30/23.
//

#include <array>
#include <iostream>
#include "card.hpp"
#include "player.hpp"
#include "deck.hpp"
#include "blackJack.hpp"


int getNumPlayers()
{
    std::cout << "How many players (excluding dealer)? " ;
    int numPlayers { } ;
    std::cin >> numPlayers ;
    
    return numPlayers ;
}

// we can print the player hand, or we can print the entire deck for this function
template <typename T>
void printHand( const T& hand )
{
    for ( const auto& card : hand )
    {
        printCard( card ) ;
        std::cout << ' ' ;
    }
    std::cout << '\n' ;
}

int main(int argc, const char * argv[])
{
    
    
    std::array<Card, 52> deck { newDeck() } ;
    
    printHand( deck ) ;
    
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
