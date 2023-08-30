//
//  card.hpp
//  TheBlackJack_C++
//
//  Created by Greyson Chavez on 8/30/23.
//

#ifndef card_hpp
#define card_hpp

#include <iostream>

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

char getSuit( const CardSuit& suit ) ;

char getRank( const CardRank& rank ) ;

void printCard( const Card& card ) ;

int getCardValue( const CardRank& rank ) ;


#endif /* card_hpp */
