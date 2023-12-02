#include "game.hpp"

playerList::playerList(){
    size = 0;
    head = tail = NULL;
}

player::player(int pos){
    health = 100;
    mana = 10;
    position = pos;
    flag = true;
    // setCharacter(); commented out lang muna since wala pa
    // need to connect deck and the gamedeck
}

// NTS FOR LOOP / WHILE LOOP i = 0 i < numPlayers , player(i)

// int will come from game file
void playerList::addPlayers(int n){
    int i = 1;
    while(n-->0){
        player* newPlayer = new player(i); // will set the player using overloaded constructor
        if(!head)
            head = tail = newPlayer;
        else{
            tail->next = newPlayer;
            newPlayer->prev = tail;
            tail = newPlayer;
        }
        i++;
        size++;
    }
}

void playerList::transferPlayer(playerList *defeated, int a){
    player *n = head;
    
    while(n != NULL) {
        if(getPosition(n) == a-1)
            break;
            
        n = n->next;
    }
    
    if(n == NULL)
        cout << "ERROR: Player does not exist.\n";
        
    defeated->tail->next = n;
    n->prev = defeated->tail;
    defeated->tail = n;
    defeated->size++;
}

int playerList::getHealth(player* p){
    return p->health;
}

int playerList::getMana(player* p){
    return p->mana;
}

int playerList::getPosition(player* p){
    return p->position;
}

void playerList::displayPlayers(){
    player *tmp = head;

    while(tmp != NULL) {
        cout << "Position: " << getPosition(tmp) << " Health: " << getHealth(tmp) << " Mana: " << getMana(tmp) << endl;
        tmp = tmp->next;
    }
}