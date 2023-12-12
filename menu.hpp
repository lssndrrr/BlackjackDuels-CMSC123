#pragma once
#ifndef MENU_HPP
#define MENU_HPP

#include "game.hpp"
#include "leaderboard.hpp"

enum menuState {
    mainMenu,
    tutorialScreen,
    leaderboard
};

class menu {
    //window
    RenderWindow *window;
    View view;
    Event event;
    VideoMode video;
    float aspectRatio, viewHeight, viewWidth;
    menuState menuState;

    //textures
    Texture MMBGtexture;
    Texture Deathtexture;
    Texture Titletexture;
    Texture Buttontexture;
    Texture Tutorialtexture;
    Texture BGtexture;
    Image icon;

    //Music and SFX
    Music menuMusic;
    SoundBuffer clickButtonBuffer;
    Sound clickButton;

    //sprites
    Sprite Death;
    Sprite mainMenuBG;
    Sprite BG;
    Sprite Title;
    Sprite Tutorial;
    Font font;

    //buttons
    button playButton;
    button tutorialButton;
    button backButton;
    button LBButton;

    //Text
    Text lbText;
    Text lbUsernames[10];
    Text lbPoints[10];

    //game
    game *g;

    //leaderboard
    Leaderboard winners;

    //clock
    Clock loop, BGloop;

public:
    menu();
    ~menu();

    //initialize
    void intMenuTex();
    void intMenuWin();
    void intMenuVar();
    void intLeaderboard();
    void updateLeaderboard();
    const bool running() const;
    void run();
    void update();
    void render();
    void createGame();
    void titleLoop();
    void bgLoop();
};

#endif // !MENU_HPP
