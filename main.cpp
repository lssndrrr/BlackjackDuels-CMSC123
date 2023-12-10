#include "game.hpp"
#include "button.cpp"
// #include "characters.cpp"
#include "deck.cpp"
#include "game.cpp"
#include "mainGame.cpp"
#include "players.cpp"
#include "textures.cpp"
#include "updates.cpp"
#include "header.hpp"

int main(){
    RenderWindow *window;
    View view;
    VideoMode video;

    initWindow(window, view, video);
    menu();
 
    game g(window, view, video);
    g.run();

    return 0;
}