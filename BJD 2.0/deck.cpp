#include "game.hpp"

deck::deck(){
    overallValue = 0;
}

void deck::gameDeck(){
    for(int s = static_cast<int>(suit::clubs); s <= static_cast<int>(suit::spades); s++){
        for(int r = static_cast<int>(rank::ace); r <= static_cast<int>(rank::king); r++){
            suit st = static_cast<suit>(s);
            rank rk = static_cast<rank>(r);
            card c;
            c.r = rk;
            c.s = st;
            c.value = cardValue(rk);
            cards.push_back(c);
        }
    }
}

void deck::dealCards(playerList* p){
    list<player>::iterator currentPlayer = p->playerlist.begin();
    while(currentPlayer != p->playerlist.end()){
        int i = 0;
        while(i < 2){
            if(cards.empty()){
                gameDeck();
                shuffle();
            }
            card c = cards.front();
            cards.pop_front();


            currentPlayer->d.cards.push_back(c);

            i++;
        }
        ++currentPlayer;
    }
}

int deck::cardValue(rank rk){
    if(rk == rank::jack || rk == rank::queen || rk == rank::king)
        return 10;
    else if(rk == rank::ace)
        return 11;
    else
        return (static_cast<int>(rk) + 1);
}

void deck::findOverallValue(){
    deque<card>::iterator current = cards.begin();
    overallValue = 0;
    while(current != cards.end()){
        overallValue += current->value;
        ++current;
    }
}

void deck::hitDeck(deck* d){
    if(cards.empty()){
        gameDeck();
        shuffle();
    }
    d->cards.push_back(cards.front());
    cards.pop_front();
}

void deck::shuffle(){
    std::random_device rd;
    std::mt19937 rng(rd());    

    std::shuffle(cards.begin(), cards.end(), rng);
}

string deck::getSuit(suit s){
    switch(s){
        case suit::clubs:       return "Clubs";
        case suit::diamonds:    return "Diamonds";
        case suit::hearts:      return "Hearts";
        case suit::spades:      return "Spades";
        default:                return "ERROR";
    }
}

string deck::getRank(rank r){
    switch(r){
        case rank::ace:         return "Ace";
        case rank::two:         return "Two";
        case rank::three:       return "Three";
        case rank::four:        return "Four";
        case rank::five:        return "Five";
        case rank::six:         return "Six";
        case rank::seven:       return "Seven";
        case rank::eight:       return "Eight";
        case rank::nine:        return "Nine";
        case rank::ten:         return "Ten";
        case rank::jack:        return "Jack";
        case rank::queen:       return "Queen";
        case rank::king:        return "King";
        default:                return "ERROR";
    }
}

void deck::displayDeck(){
    deque<card>::iterator current = cards.begin();
    int i = 1;
    while(current != cards.end()){
        cout << i <<" "<< getSuit(current->s) <<" "<< getRank(current->r) <<" "<< current->value << endl;
        ++current;
        i++;
    }
}