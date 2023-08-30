//
//  main.cpp
//  TheBlackJack_C++
//
//  Created by Greyson Chavez on 8/30/23.
//

#include <algorithm>
#include <array>
#include <iostream>
#include <random>
#include <string>


enum class CardSuit
{
    diamond ,
    heart ,
    spade ,
    club ,
    
    maxSuit ,
} ;

enum class CardRank
{
    two ,
    three ,
    four ,
    five ,
    six ,
    seven ,
    eight ,
    nine ,
    ten ,
    jack ,
    queen ,
    king ,
    ace ,
    
    maxRank ,
} ;

struct Card
{
    CardSuit suit { } ;
    CardRank rank { } ;
} ;


struct Player
{
    std::string name { } ;
    std::vector<Card> hand { } ;
} ;


char getSuit( const CardSuit& suit )
{
    switch ( suit )
    {
        using enum CardSuit ;
        case diamond:
            return 'D' ;
        case heart:
            return 'H' ;
        case spade:
            return 'S' ;
        case club:
            return 'C' ;
        default:
            std::cout << "Error\n" ;
            return NULL ;
    }
}

char getRank( const CardRank& rank )
{
    switch ( rank )
    {
        using enum CardRank ;
        case two:
            return '2' ;
        case three:
            return '3' ;
        case four:
            return '4' ;
        case five:
            return '5' ;
        case six:
            return '6' ;
        case seven:
            return '7' ;
        case eight:
            return '8' ;
        case nine:
            return '9' ;
        case ten:
            return 'T' ;
        case jack:
            return 'J' ;
        case queen:
            return 'Q' ;
        case king:
            return 'K' ;
        case ace:
            return 'A' ;
        default:
            std::cout << "Error\n" ;
            return NULL ;
    }
}


std::array<Card, 52> newDeck()
{
    std::array<Card, 52> deck { } ;
    
    int deckIndex { 0 } ;
    for ( int suit = 0 ; suit < static_cast<int>(CardSuit::maxSuit) ; ++suit )
    {
        for ( int rank = 0 ; rank < static_cast<int>(CardRank::maxRank) ; ++rank )
        {
            Card card { static_cast<CardSuit>(suit) , static_cast<CardRank>(rank) } ;
            deck[deckIndex] = card ;
            ++deckIndex ;
        }
    }
    return deck ;
}

template <typename T>
void printDeck( const T& deck )
{
    for ( const auto& card : deck )
    {
        std::cout << getRank(card.rank) << getSuit(card.suit) << ' ' ;
    }
}

void shuffleDeck( std::array<Card, 52>& deck )
{
    std::mt19937 mt { std::random_device{}() } ;
    std::shuffle( deck.begin() , deck.end() , mt ) ;
}

void dealCard( const std::array<Card, 52>& deck , Player& player , int& deckIndex )
{
    player.hand.push_back( deck[deckIndex] ) ;
    ++deckIndex ;
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
    printDeck( deck ) ;
    
    // We need a way to shuffle the deck
    shuffleDeck( deck ) ;
    
    std::cout << '\n' ;
    
    // we now have our deck of cards
    
    // We could have a player as a structure
        // within the structure is a vector for the hand
        // Perhaps even a string for the name of the player
    
    // We need a way to deal cards to a players hand
        // This should be pretty simple
        // we need to keep track of the deckIndex
        // Then we just deal the card at whatever the index is
    int deckIndex { 0 } ;
    Player p1 { "Player One" } ;
    dealCard( deck , p1 , deckIndex ) ;
    
    dealCard( deck , p1 , deckIndex ) ;

    
    printDeck( p1.hand ) ;
    
    
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
