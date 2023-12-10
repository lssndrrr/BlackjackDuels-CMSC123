#ifndef HEADER_HPP
#define HEADER_HPP

#include <iostream>
#include <random>
#include <vector>
#include <deque>
#include <list>
#include <algorithm>
#include <string>
#include <sstream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

using namespace sf;

using std::string;
using std::cout;
using std::endl;
using std::cin;
using std::vector;
using std::deque;
using std::list;


class playerList;

// deck
enum suit{
    clubs,
    diamonds,
    hearts,
    spades
};

enum rank{
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

class card{
    suit s;
    rank r;
    int value;
    Sprite *cardSprite;
public:
    friend class deck;
    friend class game;
};

class deck{
    deque <card> cards;
    int overallValue;
public:
    deck(); 
    void gameDeck();
    int cardValue(rank);
    void findOverallValue();
    void hitDeck(deck*);
    void shuffle();
    void dealCards(playerList*); 
    string getSuit(suit);
    string getRank(rank);
    void displayDeck();
    int size();
    friend class game;
};

//character
enum charType {
    jackChar,
    jakeChar,
    jacksonChar,
    jadeChar,
    none
};

class character {
    public:
        charType type = none;
        Sprite *charSprite;
        string name;
};


// player
class player{
    int health, mana, position, points;
    bool flag = false;
    deck d;
    character c;
    string username;
public:
    player *prev, *next;
    player();
    player(int);
    int getPoints();
    string getUsername();
    void setUsername(string);
    friend class playerList;
    friend class deck;
    friend class game;
};

class playerList{
    list<player> playerlist;
public:
    // list<player> playerlist;
    playerList(); 
    void addPlayers(int);
    void transferPlayer(const list<player>::iterator&, playerList*);
    int getHealth(player*);
    int getMana(player*);
    int getPosition(player*);
    int size();
    // void erase(list<player>::iterator&);
    void displayPlayers();
    friend class game;
    friend class deck;
};

#endif