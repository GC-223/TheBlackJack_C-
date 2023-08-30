//
//  main.cpp
//  TheBlackJack_C++
//
//  Created by Greyson Chavez on 8/30/23.
//

#include <algorithm>
#include <array>
#include <cstdlib>
#include <iostream>
#include <random>
#include <string>
#include "card.hpp"
#include "player.hpp"
#include "deck.hpp"






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







// return true for hit
bool hitOrStay()
{
    while ( true )
    {
        std::cout << "Hit or Stay (h or s)? " ;
        char input { } ;
        std::cin >> input ;
        
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

// function to tell if bust
bool isBust( Player& player )
{
    return evaluateHand( player ) > 21 ;
}

// Make this into a PlayerTurn function
// return true when player busts
bool playerTurn( const std::array<Card, 52>& deck , Player& player , int& deckIndex )
{
    while ( true )
    {
        if ( hitOrStay() )
        {
            std::cout << player.name << " drew a " ;
            printCard( deck[deckIndex] ) ;
            std::cout << '\n' ;
            dealCard( deck, player, deckIndex ) ;
            printHand( player.hand ) ;
            std::cout << "Score: " << evaluateHand( player ) << '\n' ;
            
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

bool dealerTurn( const std::array<Card, 52>& deck , Player& player , int& deckIndex )
{
    while ( true )
    {
        if ( evaluateHand(player) < 17 )
        {
            std::cout << player.name << " drew a " ;
            printCard( deck[deckIndex] ) ;
            std::cout << '\n' ;
            dealCard( deck, player, deckIndex ) ;
            printHand( player.hand ) ;
            std::cout << "Score: " << evaluateHand( player ) << '\n' ;
            
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

// return true if you win
bool winOrLose( Player& player , Player& dealer )
{
    return evaluateHand( player ) > evaluateHand( dealer ) ;
}


bool playBlackJack( const std::array<Card, 52>& deck )
{
    int deckIndex { 0 } ;
    
    Player dealer { "Dealer" } ;
    Player player1 { "Player One" } ;
    
    // Dealer starts with one card
    dealCard( deck, dealer, deckIndex ) ;
    std::cout << dealer.name << " Hand: " ;
    printHand( dealer.hand ) ;
    std::cout << "Score: " << evaluateHand( dealer ) << '\n' ;

    // player starts with two cards
    dealCard( deck, player1, deckIndex ) ;
    dealCard( deck, player1, deckIndex ) ;
    
    std::cout << player1.name << " Hand: " ;
    printHand( player1.hand ) ;
    std::cout << "Score: " << evaluateHand( player1 ) << '\n' ;

    
    if ( playerTurn( deck , player1 , deckIndex ) )
    {
        std::cout << "You Lose" ;
        return false ;
    }
    
    if ( dealerTurn( deck , dealer , deckIndex ) )
    {
        std::cout << "You Win!" ;
        return true ;
    };
    
    if ( winOrLose( player1 , dealer ) )
    {
        return true ;
    }
    else
    {
        return false ;
    }
}

int getNumPlayers()
{
    std::cout << "How many players (excluding dealer)? " ;
    int numPlayers { } ;
    std::cin >> numPlayers ;
    
    return numPlayers ;
}

int main(int argc, const char * argv[])
{
    
    // We need a deck
        // The deck will be made up of cards
            // Each card will be made up of a suit and a value
    std::array<Card, 52> deck { newDeck() } ;
    
    
    
    // need a function to create a new deck
        // if we loop through the number of suits
            // and loop through the number of cards
            // assign the deck at index with rank and suit
    
    // Now we need a function to print the deck
        // we loop through the deck
        // at each element
            // we need a way to print rank and suit
    printHand( deck ) ;
    
    // We need a way to shuffle the deck
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
    
    
    
    // we now have our deck of cards
    
    // We could have a player as a structure
        // within the structure is a vector for the hand
        // Perhaps even a string for the name of the player
    
    // We need a way to deal cards to a players hand
        // This should be pretty simple
        // we need to keep track of the deckIndex
        // Then we just deal the card at whatever the index is

    
    // Now lets get a function to play blackjack
    
    
    // A function to evaluate the hand
        // We need a way to count the value of each card
    
    
    // We need a hit or stand function
        // if it is playerTurn
        // ask the player if they want to hit
            // if hit
            // deal one card
            // evaluate hand
                // if over 21 then say bust and end playerTurn
                // else return back to Hit or Stay?
    
    
}
