//
//  deck.cpp
//  TheBlackJack_C++
//
//  Created by Greyson Chavez on 8/30/23.
//

#include "deck.hpp"

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
