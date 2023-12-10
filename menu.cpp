#include "game.hpp"

menu::menu() {
    intMenuTex();
    intMenuWin();
    intMenuVar();
}

void menu::intMenuTex() {
    //loading textures
    if(!MMBGtexture.loadFromFile("Textures/mainmenubg.png")){
        cout << "ERROR::MMBGtexture" << endl;
    }
    if(!Deathtexture.loadFromFile("Textures/death.png")){
        cout << "ERROR::Deathtexture" << endl;
    }
    if(!icon.loadFromFile("Textures/icon.png")){
        cout << "ERROR::icon" << endl;
    }
    if(!Titletexture.loadFromFile("Textures/title.png")){
        cout << "ERROR::Titletexture" << endl;
    }
    if(!Buttontexture.loadFromFile("Textures/button.png")){
        cout << "ERROR::Buttontexture" << endl;
    }
    if(!font.loadFromFile("Fonts/alagard.ttf")){
        cout << "ERROR::font" << endl;
    }

    //setting textures
    
}

void menu::intMenuWin() {

}

void menu::intMenuVar() {

}