#ifndef HEADER_HPP
#define HEADER_HPP

#include <iostream>
#include <random>
#include <vector>
#include <algorithm>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

using namespace sf;

using std::string;
using std::cout;
using std::endl;
using std::cin;
using std::vector;

// int numPlayers(); to include in game file


// char
/*enum chr{
    jackblack,
    jake,
    jackson,
    jade
};

class character{
    chr name;
public:
    character* next;
    void useAbility();
    friend class characterList;
};

// called using another function, say useAbility, so we can differentiate the characters using static_cast
// class jackblaclack: private character{
// public:
//     //jackAbility();
// };

class characterList{
    character *head, *tail;
public:
    characterList();
    void addCharacter(int);
    string getCharacter(chr);
    string getCharDesc(chr);
    string getAbDesc(chr);
    void displayCharacters();
};

// deck
enum suit{
    clubs,
    diamonds,
    hearts,
    spades
};

enum rank{
    ace,
    one,
    two,
    three,
    four,
    five,
    six,
    seven, 
    eight,
    nine, 
    jack,
    queen,
    king
};

class card{
    suit s;
    rank r;
    int value;
    Sprite cardSprite;
    Texture cardTexture;
public:
    card *next;
    friend class deck;
};

class deck{
    card *head, *tail;
    int overallValue;
    vector<vector<Texture>> cardTextures;
public:
    deck(); 
    void gameDeck();
    void addCard(suit, rank);
    void bindCardTex();
    int cardValue(rank);
    void findOverallValue();
    void hitDeck(deck*);
    void shuffle();
    void dealCards(playerList*); // dealing the cards, start from the top (head)
    string getSuit(suit);
    string getRank(rank);
    void displayDeck();
    friend class game;
};

// player
class player{
    int health, mana, position;
    bool flag;
    // character c; // player's character; to discuss how to connect character to player
    deck d; // player's deck of cards
public:
    player *prev, *next;
    player(int);
    void setCharacter();
    friend class playerList;
    friend class deck;
    friend class game;
};

class playerList{
    int size;
    player *head, *tail;
public:
    playerList(); 
    playerList(int); 
    void addPlayers(int);
    void transferPlayer(playerList*, int);
    int getHealth(player*);
    int getMana(player*);
    int getPosition(player*);
    void displayPlayers();
    friend class game;
    friend class deck;
};*/

// NTS AFTER EVERY TURN DEAL AND SHUFFLE

// do-while for hitting, meaning cin for hit or stand, cin last
// or while loop? cin last? cin set to yes initially?

// different classes for different characters since they have diff special abilities??? and then nakalist???

// look up inheritance, maybe we can do that for the characters?
// game class for the game??or

// friend class for deck n shit for game file bc it wont work if hindi

#endif