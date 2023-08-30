//
//  card.cpp
//  TheBlackJack_C++
//
//  Created by Greyson Chavez on 8/30/23.
//

#include "card.hpp"

// get the suit of a card
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

// get the rank of the card
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

// print a card
void printCard( const Card& card )
{
    std::cout << getRank(card.rank) << getSuit(card.suit) ;
}

// get the int value of the card
int getCardValue( const CardRank& rank )
{
    char cardValue { getRank( rank ) } ;
    
    if (cardValue == 'T' || cardValue == 'J' || cardValue == 'Q' || cardValue == 'K')
    {
        cardValue = 10 ;
    }
    else if ( cardValue == 'A' )
    {
        cardValue = 11 ;
    }
    else
    {
        cardValue = cardValue - '0' ;
    }
    
    return cardValue ;
}
