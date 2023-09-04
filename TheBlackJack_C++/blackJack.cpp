//
//  blackJack.cpp
//  TheBlackJack_C++
//
//  Created by Greyson Chavez on 8/30/23.
//

#include "blackJack.hpp"

 
// true if the player wins
bool playBlackJack( const std::array<Card, 52>& deck )
{
    int deckIndex { 0 } ;
    
    std::vector<Player> players (getNumPlayers() + 1 ) ;
    
    
    givePlayerName( players ) ;
    
//    Player dealer { "Dealer" } ;
//    Player player { "Player One" } ;
    
//    // Dealer starts with one card
//    dealCard( deck, dealer, deckIndex ) ;
//    std::cout << dealer.name << " Hand: " ;
//    printHand( dealer.hand ) ;
//    std::cout << dealer.name << " Score: " << evaluateHand( dealer ) << '\n' ;
//
//    // player starts with two cards
//    dealCard( deck, player, deckIndex ) ;
//    dealCard( deck, player, deckIndex ) ;
    
//    std::cout << player.name << " Hand: " ;
//    printHand( player.hand ) ;
//    std::cout << player.name << "Score: " << evaluateHand( player ) << '\n' ;

    startingHands( players , deck , deckIndex ) ;
    
    printAllPlayers( players ) ;
    
    play( players , deck , deckIndex ) ;
    
    // if player busts
//    if ( playerTurn( deck , player , deckIndex ) )
//    {
//        return false ;
//    }
//
//    if ( dealerTurn( deck , dealer , deckIndex ) )
//    {
//        return true ;
//    };
//
//
//    return ( winOrLose( player , dealer ) ) ;
    return true ;
}

// true if the player busts
bool playerTurn( const std::array<Card, 52>& deck , Player& player , int& deckIndex )
{
    
    std::cout << "\n\n\n" << player.name << " Hand: " ;
    printHand( player.hand ) ;
    std::cout << '\t' << player.name << " Score: " << evaluateHand( player ) << '\n' ;
    
    while ( true )
    {
        if ( hitOrStay( player ) )
        {
            std::cout << player.name << " drew a " ;
            printCard( deck[deckIndex] ) ;
            dealCard( deck, player, deckIndex ) ;
            
            std::cout << "\n\n" << player.name << " Hand: " ;
            printHand( player.hand ) ;
            std::cout << '\t' << player.name << " Score: " << evaluateHand( player ) << '\n' ;
            
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

// return true if the dealer busts
//bool dealerTurn( const std::array<Card, 52>& deck , Player& player , int& deckIndex )
//{
//    while ( true )
//    {
//        if ( evaluateHand(player) < 17 )
//        {
//            std::cout << player.name << " drew a " ;
//            printCard( deck[deckIndex] ) ;
//            std::cout << '\n' ;
//            dealCard( deck, player, deckIndex ) ;
//            printHand( player.hand ) ;
//            std::cout << "Score: " << evaluateHand( player ) << '\n' ;
//
//            if ( isBust( player ) )
//            {
//                std::cout << player.name << " Bust\n" ;
//                return true ;
//            }
//        }
//        else
//        {
//            return false ;
//        }
//    }
//}

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
bool isBust( Player& player )
{
    return evaluateHand( player ) > 21 ;
}

// true if playerWins
bool winOrLose( Player& player , Player& dealer )
{
    return evaluateHand( player ) > evaluateHand( dealer ) ;
}
