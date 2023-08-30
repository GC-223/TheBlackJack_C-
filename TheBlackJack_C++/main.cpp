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

void printDeck( const std::array<Card, 52>& deck )
{
    for ( int i = 0 ; i < 52 ; ++i )
    {
        std::cout << getRank(deck[i].rank) << getSuit(deck[i].suit) << ' ' ;
    }
}

void shuffleDeck( std::array<Card, 52>& deck )
{
    std::mt19937 mt { std::random_device{}() } ;
    std::shuffle( deck.begin() , deck.end() , mt ) ;
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
    printDeck( deck ) ;
    
    // we now have our deck of cards
    // We 
    
    // We need a way to deal cards
    
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
