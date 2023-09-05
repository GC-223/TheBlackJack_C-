//
//  blackJack.cpp
//  TheBlackJack_C++
//
//  Created by Greyson Chavez on 8/30/23.
//

#include "blackJack.hpp"

 
// now a function to print each players information
void printAllPlayers( const std::vector<Player>& players )
{
    int dealerIndex { static_cast<int>(players.size() - 1) } ;

    printOnePlayer( players[dealerIndex] ) ;

    for ( int p = 0 ; p < dealerIndex ; ++p )
    {
        printOnePlayer( players[p] ) ;
    }

}

// true if the player busts
bool playerTurn( const std::array<Card, 52>& deck , Player& player , int& deckIndex )
{
    std::cout << "\n\n\n" ;
    
    printOnePlayer( static_cast<const Player>( player ) ) ;
    
    while ( true )
    {
        if ( hitOrStay( player ) )
        {
            std::cout << player.name << " drew a " ;
            printCard( deck[deckIndex] ) ;
            
            player.score += getCardValue( deck[deckIndex].rank ) ;
            dealCard( deck, player, deckIndex ) ;
            
            std::cout << "\n\n" ;
            printOnePlayer( static_cast<const Player>( player ) ) ;
            
            if ( isBust( player ) )
            {
                std::cout << player.name << " Bust\n" ;
                return true ;
            }
        }
        else
        {
            return false ;
        }
    }
}


// lets revamp dealerTurn
// Return true if bust
bool dealerTurn( const std::array<Card, 52>& deck, Player& dealer, int& deckIndex )
{
    std::cout << "\n\n\n" ;
    
    printOnePlayer( static_cast<const Player>( dealer ) ) ;
    
    while ( true )
    {
        if ( dealer.score < 17 )
        {
            std::cout << dealer.name << " drew a " ;
            printCard( deck[deckIndex] ) ;
            
            dealer.score += getCardValue( deck[deckIndex].rank ) ;
            dealCard( deck, dealer, deckIndex ) ;
            
            std::cout << "\n\n" ;
            printOnePlayer( static_cast<const Player>( dealer ) ) ;
            
            if ( isBust( dealer ) )
            {
                std::cout << dealer.name << " Bust\n" ;
                return true ;
            }
        }
        else
        {
            return false ;
        }
    }
}


// true if hit
bool hitOrStay( const Player& player )
{
    while ( true )
    {
        std::cout << player.name << ": Hit or Stay (h or s)? " ;
        char input { } ;
        std::cin >> input ;
        std::cin.ignore( 1000 , '\n' ) ;
        std::cin.clear() ;
        
        if ( input == 'h' )
        {
            return true ;
        }
        else if ( input == 's' )
        {
            return false ;
        }
        
        std::cout << "Error! Invalid Input\n" ;
    }
}

// true if bust
bool isBust( const Player& player )
{
    return player.score > 21 ;
}


// a function to deal the starting amount of cards
void startingHands( std::vector<Player>& players , const std::array<Card, 52>& deck , int& deckIndex )
{
    for ( int p = 0 ; p < players.size() ; ++p )
    {
        if ( players[p].name == "Dealer" )
        {
            
            dealCard( deck, players[p], deckIndex ) ;
            
        }
        else
        {
            dealCard( deck, players[p], deckIndex ) ;
            dealCard( deck, players[p], deckIndex ) ;
        }
        
        players[p].score = evaluateHand( static_cast<const Player>(players[p]) ) ;
    }
}
