#pragma once
#ifndef GAME_HPP
#define GAME_HPP

#include "header.hpp"

//class button{
//    public:
//        RectangleShape btn;
//        Text text;
//        void setButton(string, Vector2f, int, Texture*, Color, Font*);
//        void setFont(Font &font);
//        void setButtonTexture(Texture texture);
//        void setTextColor(Color color);
//        void setPosition(Vector2f pos);
//        void drawButton(RenderWindow &window);
//        bool isMouseOver(RenderWindow &window);
//        friend class game;
//};
//
//class dashboard {
//    public:
//        Sprite charContainer;
//        RectangleShape background;
//        void setDashboard(Sprite*, Color, Vector2f);
//        void setPosition(Vector2f);
//        void setBackgroundPosition(Vector2f);
//        void drawDashboard(RenderWindow &window);
//};

//enum gameState{
//    mainMenu,
//    tutorialScreen,
//    chooseNumPlayersScreen,
//    chooseCharScreen,
//    mainGameScreen,
//    pauseScreen,
//    winScreen,
//    loseScreen
//};

class game{
private:
    int cnt;
    bool is_running;
    SDL_Window *window;
public:
    game();
    ~game();
    void init(const char *title, int x, int y, int width, int height, bool fullscreen);
    
    void handle_events();
    void update();
    void render();
    void clean();

    bool running() { return is_running;  }

    static SDL_Renderer *renderer;

    //// updates
    //void updateMainMenu();
    //void updateTutorial();
    //void updateChooseNumPlayers();
    //void updateChooseCharScreen();
    //void updateGameEvent();
    //void updatePauseScreen();
    //void updateWinScreen();

    //// render
    //void renderMainMenu();
    //void renderChooseNum();
    //void renderChooseChar();
    //void renderMainGame();

    //// main game render
    //void renderButtons();
    //void setBackground();
    //void setCandle();
    //void setDeathIdle();
    //void setDashboard();
    //void updateOverallValue();
    //void updatePlayerNum();
    //void renderBust();
    //
    //// game logic
    //void runRound();
    //void intCardSprites();

    //void renderDeck();
    //void renderCard(const card&, float, float);
    ////void initRound();
};

// round

#endif