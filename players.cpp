#include "game.hpp"

playerList::playerList(){
    // nada;
}

player::player(int pos){
    health = 100;
    mana = 10;
    position = pos;
    flag = true;
}

// NTS FOR LOOP / WHILE LOOP i = 0 i < numPlayers , player(i)

// int will come from game file
void playerList::addPlayers(int n){
    int i = 1;
    while(n){
        player* newPlayer = new player(i); // will set the player using overloaded constructor
        playerlist.push_back(*newPlayer);
        i++;
        n--;
    }
}

void playerList::transferPlayer(const list<player>::iterator& it, playerList* defeated){
    defeated->playerlist.push_back(*it);
    playerlist.erase(it);
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
    list<player>::iterator p = playerlist.begin();

    while(p != playerlist.end()) {
        cout << "Position: " << getPosition(&(*p)) << " Health: " << getHealth(&(*p)) << " Mana: " << getMana(&(*p)) << endl;
        ++p;
    }
}
