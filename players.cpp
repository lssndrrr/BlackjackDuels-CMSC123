#include "game.hpp"

playerList::playerList(){
    // nada;
}

player::player() {

}

player::player(int pos){
    this->health = 100;
    this->mana = 10;
    this->position = pos;
    this->flag = true;
    this->points = 0;
    this->username = "";
}

int player::getPoints() {
    return this->points;
}

string player::getUsername() {
    return this->username;
}

void player::setUsername(string input) {
    this->username = input;
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

int playerList::size() {
    return playerlist.size();
}

// void playerList::erase(list<player>::iterator& current) {
//     playerlist.erase(current);
// }

void playerList::displayPlayers(){
    list<player>::iterator p = playerlist.begin();

    while(p != playerlist.end()) {
        cout << "Position: " << getPosition(&(*p)) << " Health: " << getHealth(&(*p)) << " Mana: " << getMana(&(*p)) << endl;
        ++p;
    }
}
