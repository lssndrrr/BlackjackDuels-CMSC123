#include "game.hpp"
/*
void game::runRound(){
    highestValue = 0;
    deck gameDeck;
    gameDeck.shuffle();
    player *current = players.head, *temp = players.head;

    while(players.size != 1){
        gameDeck.dealCards(&players);
        current = players.head;
        temp = players.head;
        while(current != NULL){
            current->d.findOverallValue();
            while(current->d.overallValue < 22){
                switch(window->pollEvent(event)){
                    case Event::MouseButtonReleased:
                        if(event.mouseButton.button == Mouse::Left){
                            if(hitButton.contains(Mouse::getPosition(*window))){
                                gameDeck.hitDeck(&(current->d));
                                current->d.findOverallValue();
                            } else if(standButton.contains(Mouse::getPosition(*window))){
                                current->d.findOverallValue();
                                break;
                            }
                        }
                    break;
                    default: break;
                }
            }
            if(current->d.overallValue > 21){
                if(current->health > 10){
                    current->health -= 10;
                    current->flag = false;
                    current = current->next;
                } else{
                    temp = current->next;
                    players.transferPlayer(&defeated, static_cast<int>(current->position)+1);
                    current = temp;
                }
            } else{
                if(highestValue < current->d.overallValue){
                    highestValue = current->d.overallValue;
                }
                current = current->next;
            }
            current = players.head;
            while(current != NULL){
                if(current->flag){
                    if(current->d.overallValue < highestValue){
                        current->health -= 10;
                    }
                    current = current->next;
                } else{
                    current->flag = true;
                }
            }
        }
    }
    state = winScreen;
}*/