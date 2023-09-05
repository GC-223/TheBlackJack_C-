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

    std::cout << players[dealerIndex].name << " Hand: " ;
    printHand( players[dealerIndex].hand ) ;

    std::cout << "\t\t" << players[dealerIndex].name << " Score: " << players[dealerIndex].score << '\n' ;

    for ( int p = 0 ; p < players.size() - 1 ; ++p )
    {
        std::cout << players[p].name << " Hand: " ;
        printHand( players[p].hand ) ;
        std::cout << '\t' << players[p].name << " Score: " << players[p].score << '\n' ;
    }

}

// true if the player busts
bool playerTurn( const std::array<Card, 52>& deck , Player& player , int& deckIndex )
{
    
    std::cout << "\n\n\n" << player.name << " Hand: " ;
    printHand( player.hand ) ;
    std::cout << '\t' << player.name << " Score: " << player.score << '\n' ;
    
    while ( true )
    {
        if ( hitOrStay( player ) )
        {
            std::cout << player.name << " drew a " ;
            printCard( deck[deckIndex] ) ;
            
            player.score += getCardValue( deck[deckIndex].rank ) ;
            dealCard( deck, player, deckIndex ) ;
            
            
            std::cout << "\n\n" << player.name << " Hand: " ;
            printHand( player.hand ) ;
            
            std::cout << '\t' << player.name << " Score: " << player.score << '\n' ;
            
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
    
    std::cout << "\n\n\n" << dealer.name << " Hand: " ;
    printHand( dealer.hand ) ;
    
    std::cout << "\t\t" << dealer.name << " Score: " << dealer.score << '\n' ;
    
    while ( true )
    {
        if ( dealer.score < 17 )
        {
            std::cout << dealer.name << " drew a " ;
            printCard( deck[deckIndex] ) ;
            
            dealer.score += getCardValue( deck[deckIndex].rank ) ;
            dealCard( deck, dealer, deckIndex ) ;
            
            std::cout << "\n\n" << dealer.name << " Hand: " ;
            printHand( dealer.hand ) ;
            std::cout << "\t\t" << dealer.name << " Score: " << dealer.score << '\n' ;
            
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

// true if playerWins
bool winOrLose( Player& player , Player& dealer )
{
    return evaluateHand( player ) > evaluateHand( dealer ) ;
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
