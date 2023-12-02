#include "game.hpp"

deck::deck(){
    head = tail = NULL;    
    overallValue = 0;
}

void deck::gameDeck(){
    for(int s = static_cast<int>(suit::clubs); s <= static_cast<int>(suit::spades); s++){
        for(int r = static_cast<int>(rank::ace); r <= static_cast<int>(rank::king); r++){
            suit st = static_cast<suit>(s);
            rank rk = static_cast<rank>(r);
            addCard(st, rk);
        }
    }  
}

void deck::dealCards(playerList* p){
    card* current = head;
    player* currentPlayer = p->head;
    while(currentPlayer != NULL){
        int i = 0;
        while(i < 2){
            card* temp = current;
            current = current->next;
            temp->next = NULL;
            head = current;


            if(currentPlayer->d.head == NULL){
                currentPlayer->d.head = currentPlayer->d.tail = temp;
            } else{
                currentPlayer->d.tail->next = temp;
                temp = currentPlayer->d.tail;
            }
            i++;
        }
        currentPlayer = currentPlayer->next;
    }
}

void deck::addCard(suit st, rank rk){
    card* newCard = new card;
    newCard->s = st;
    newCard->r = rk;
    newCard->value = cardValue(rk);
    newCard->next = head;
    head = newCard;
    if(tail == NULL){
        tail = newCard;
    }
}

int deck::cardValue(rank rk){
    if(rk == rank::jack || rk == rank::queen || rk == rank::king)
        return 10;
    else if(rk == rank::ace)
        return 11;
    else
        return static_cast<int>(rk);
}

void deck::findOverallValue(){
    card *current = head;
    while(current != NULL){
        overallValue += current->value;
    }
}

void deck::hitDeck(deck* d){
    card* current = head;
    head = current->next;
    d->tail->next = current;
    d->tail = current;
    current->next = NULL;
}

void deck::shuffle(){
    std::random_device rd;
    std::mt19937 rng(rd());

    int num = 52;

    std::vector<card*> cards(num);
    card* current = head;
    int i = 0;
    while(current != NULL){
        cards[i] = current;
        current = current->next;
        i++;
    }

    std::shuffle(cards.begin(), cards.end(), rng);

    head = cards[0];
    tail = cards[num - 1];

    for(i = 0; i < num - 1; i++)
        cards[i]-> next = cards[i+1];
    cards[num - 1]->next = NULL;
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
        case rank::one:         return "One";
        case rank::two:         return "Two";
        case rank::three:       return "Three";
        case rank::four:        return "Four";
        case rank::five:        return "Five";
        case rank::six:         return "Six";
        case rank::seven:       return "Seven";
        case rank::eight:       return "Eight";
        case rank::nine:        return "Nine";
        case rank::jack:        return "Jack";
        case rank::queen:       return "Queen";
        case rank::king:        return "King";
        default:                return "ERROR";
    }
}

void deck::displayDeck(){
    card* current = head;
    int i = 1;
    while(current != NULL){
        cout << i <<" "<< getSuit(current->s) <<" "<< getRank(current->r) <<" "<< current->value << endl;
        current = current->next;
        i++;
    }
}

void deck::bindCardTex(){
    card *current = head;
    while(current != NULL){
        int suitIdx = static_cast<int>(current->s);
        int rankIdx = static_cast<int>(current->r);

        string path = "C:/Users/Az/Documents/1ST YEAR SEM 2/CMSC 21/Final Project/code/build/graphics/deck/CardTexture" + std::to_string(suitIdx) + std::to_string(rankIdx) + ".png";

        cardTextures[suitIdx][rankIdx].loadFromFile(path);
        current->cardTexture = cardTextures[suitIdx][rankIdx];
        current->cardSprite.setTexture(current->cardTexture);
    }
}