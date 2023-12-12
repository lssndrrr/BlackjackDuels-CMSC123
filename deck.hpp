#pragma once
#ifndef DECK_HPP
#define DECK_HPP

#include "header.hpp"

/*
DECK:
----- for all the deck stuff, including cards 
*/

enum suit {
    clubs,
    diamonds,
    hearts,
    spades
};

enum rank {
    ace,
    jack,
    two,
    three,
    four,
    five,
    six,
    seven,
    eight,
    nine,
    ten,
    queen,
    king
};

class card {
    suit s;
    rank r;
    int value;
    Sprite *cardSprite;
public:
    friend class deck;
    friend class game;
};

class deck {
    deque <card> cards;
    int overallValue;
public:
    deck();
    void gameDeck();
    int cardValue(rank);
    void findOverallValue();
    void hitDeck(deck *);
    void shuffle();
    void dealCards(playerList *);
    string getSuit(suit);
    string getRank(rank);
    void displayDeck();
    int size();
    friend class game;
};

#endif // !DECK_HPP
