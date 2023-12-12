#ifndef GAME_HPP
#define GAME_HPP

#include "header.hpp"
#include "players.hpp"
#include "deck.hpp"

class button {
    public:
        RectangleShape btn;
        Text text;
        void setButton(string, Vector2f, int, Texture*, Color, Font*);
        void setFont(Font &font);
        void setButtonTexture(Texture texture);
        void setTextColor(Color color);
        void setPosition(Vector2f pos);
        void drawButton(RenderWindow &window);
        bool isMouseOver(RenderWindow &window);
        friend class game;
};

class dashboard {
    public:
        Sprite charContainer;
        RectangleShape background;
        void setDashboard(Sprite*, Color, Vector2f);
        void setPosition(Vector2f);
        void setBackgroundPosition(Vector2f);
        void drawDashboard(RenderWindow &window);
};

enum gameState {
    chooseNumPlayersScreen,
    chooseCharScreen,
    mainGameScreen,
    pauseScreen,
    winScreen,
    loseScreen
};

class game {
    // SFML Basics
    RenderWindow *window;
    View view;
    gameState state;
    Event event;
    Event constantEvent;
    VideoMode video;
    float aspectRatio, viewHeight, viewWidth;
    Image icon;

    // Mouse
    Vector2i mousePosW;
    Vector2f mousePosV;

    // Sprites and Textures
    // main menu
    vector<vector<Texture>> cardTextures;
    Texture MMBGtexture;
    Texture Deathtexture;
    Texture Titletexture;
    Texture Buttontexture;
    Texture Tutorialtexture;
    Sprite Death;
    Sprite mainMenuBG;
    Sprite Title;
    Sprite Tutorial;
    Font font;

    Text numHeader;
    Text charHeader;
    Text num;

    //Characters
    Texture jackTex, jakeTex, jacksonTex, jadeTex;
    Texture jackMenuTex, jakeMenuTex, jacksonMenuTex, jadeMenuTex;

    Sprite jackSprite, jakeSprite, jacksonSprite, jadeSprite;

    // cards
    Texture C0, C1, C2, C3, C4, C5, C6, C7, C8, C9, C10, C11, C12;
    Texture D0, D1, D2, D3, D4, D5, D6, D7, D8, D9, D10, D11, D12;
    Texture H0, H1, H2, H3, H4, H5, H6, H7, H8, H9, H10, H11, H12;
    Texture S0, S1, S2, S3, S4, S5, S6, S7, S8, S9, S10, S11, S12;

    Sprite tempSprite;
    Sprite C0Sprite, C1Sprite, C2Sprite, C3Sprite, C4Sprite, C5Sprite, C6Sprite, C7Sprite, C8Sprite, C9Sprite, C10Sprite, C11Sprite, C12Sprite;
    Sprite D0Sprite, D1Sprite, D2Sprite, D3Sprite, D4Sprite, D5Sprite, D6Sprite, D7Sprite, D8Sprite, D9Sprite, D10Sprite, D11Sprite, D12Sprite;
    Sprite H0Sprite, H1Sprite, H2Sprite, H3Sprite, H4Sprite, H5Sprite, H6Sprite, H7Sprite, H8Sprite, H9Sprite, H10Sprite, H11Sprite, H12Sprite;
    Sprite S0Sprite, S1Sprite, S2Sprite, S3Sprite, S4Sprite, S5Sprite, S6Sprite, S7Sprite, S8Sprite, S9Sprite, S10Sprite, S11Sprite, S12Sprite;

    //Music and SFX
    Music gameMusic;

    // buttons
    button playButton;
    button nextButton;
    button startButton;
    button twoP;
    button threeP;
    button fourP;
    button jack;
    button jake;
    button jackson;
    button jade;
    button backButton;
    button tutorialButton;
    button tryAgainButton;
    button quitButton;
    button hitButton;
    button standButton;
    button pauseButton;
    button mainMenuButton;

    //Main game
    Texture mainGameBGTopTex;
    Texture mainGameBGBottomTex;
    Texture candleTex;
    Texture deathIdleTex;
    Texture pTex;
    Sprite mainGameBGTop;
    Sprite mainGameBGBottom;
    Sprite candle1;
    Sprite candle2;
    Sprite deathIdle;
    Sprite p;
    
    Texture lifeTex;
    Texture deadTex;
    Sprite life;
    Sprite dead;
    vector<Sprite> lives;
    vector<Sprite> deaths;
    
    dashboard playerDashboard;
    Text overallValue;
    Text pauseText;
    Text bustText;
    Text winner;
    Text loseText;
    Text enterName;
    Text username;
    string input;

    // game logic variables
    int highestValue;
    int numPlayers = 0;
    playerList defeated;
    playerList players;
    int hit;
    deck gameDeck;
    list<player>::iterator current;
    bool lose;
    bool stand;
    bool out;
    bool paused;
    bool end;
    bool open;

    int i, jackFlag, jakeFlag, jacksonFlag, jadeFlag;
    Clock candleTime, idle, bust;

    // init funcs
    void intVar();
    void intTex();
    void intWin(RenderWindow*&, View&, VideoMode&);

public:
    game();
    game(RenderWindow*&, View&, VideoMode&);
    const bool running() const;
    void updateMouse();
    player run();// int for number of players
    player update();
    void render();

    // updates
    void updateChooseNumPlayers();
    void updateChooseCharScreen();
    void updateGameEvent();
    void updatePauseScreen();
    void updateWinScreen();

    // render
    void renderChooseNum();
    void renderChooseChar();
    void renderMainGame();
    void renderPauseScreen();
    void renderWinScreen();

    // main game render
    void setCandle();
    void setDeathIdle();
    void setDashboard();
    void updateOverallValue();
    void updatePlayerNum();
    void renderBust();
    void winLoop();
    void restoreCards();
    
    // game logic
    void intCardSprites();

    void renderDeck();
    void renderCard(const card&, float, float);
};


#endif