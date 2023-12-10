#ifndef GAME_HPP
#define GAME_HPP

#include "header.hpp"

class button{
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

enum gameState{
    // mainMenu,
    // tutorialScreen,
    chooseNumPlayersScreen,
    chooseCharScreen,
    mainGameScreen,
    pauseScreen,
    winScreen,
    loseScreen
};

class game{
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
    Texture jackTex;
    Texture jakeTex;
    Texture jacksonTex;
    Texture jadeTex;
    Texture jackMenuTex;
    Texture jakeMenuTex;
    Texture jacksonMenuTex;
    Texture jadeMenuTex;

    Sprite jackSprite;
    Sprite jakeSprite;
    Sprite jacksonSprite;
    Sprite jadeSprite;

    // cards
    Texture C0;
    Texture C1;
    Texture C2;
    Texture C3;
    Texture C4;
    Texture C5;
    Texture C6;
    Texture C7;
    Texture C8;
    Texture C9;
    Texture C10;
    Texture C11;
    Texture C12;
    Texture D0;
    Texture D1;
    Texture D2;
    Texture D3;
    Texture D4;
    Texture D5;
    Texture D6;
    Texture D7;
    Texture D8;
    Texture D9; 
    Texture D10;
    Texture D11;
    Texture D12;
    Texture H0;
    Texture H1;
    Texture H2;
    Texture H3;
    Texture H4;
    Texture H5;
    Texture H6;
    Texture H7;
    Texture H8;
    Texture H9;
    Texture H10;
    Texture H11;
    Texture H12;
    Texture S0;
    Texture S1;
    Texture S2;
    Texture S3;
    Texture S4;
    Texture S5;
    Texture S6;
    Texture S7;
    Texture S8;
    Texture S9;
    Texture S10;
    Texture S11;
    Texture S12;

    Sprite tempSprite;
    Sprite C0Sprite;
    Sprite C1Sprite;
    Sprite C2Sprite;
    Sprite C3Sprite;
    Sprite C4Sprite;
    Sprite C5Sprite;
    Sprite C6Sprite;
    Sprite C7Sprite;
    Sprite C8Sprite;
    Sprite C9Sprite;
    Sprite C10Sprite;
    Sprite C11Sprite;
    Sprite C12Sprite;
    Sprite D0Sprite;
    Sprite D1Sprite;
    Sprite D2Sprite;
    Sprite D3Sprite;
    Sprite D4Sprite;
    Sprite D5Sprite;
    Sprite D6Sprite;
    Sprite D7Sprite;
    Sprite D8Sprite;
    Sprite D9Sprite;
    Sprite D10Sprite;
    Sprite D11Sprite;
    Sprite D12Sprite;
    Sprite H0Sprite;
    Sprite H1Sprite;
    Sprite H2Sprite;
    Sprite H3Sprite;
    Sprite H4Sprite;
    Sprite H5Sprite;
    Sprite H6Sprite;
    Sprite H7Sprite;
    Sprite H8Sprite;
    Sprite H9Sprite;
    Sprite H10Sprite;
    Sprite H11Sprite;
    Sprite H12Sprite;
    Sprite S0Sprite;
    Sprite S1Sprite;
    Sprite S2Sprite;
    Sprite S3Sprite;
    Sprite S4Sprite;
    Sprite S5Sprite;
    Sprite S6Sprite;
    Sprite S7Sprite;
    Sprite S8Sprite;
    Sprite S9Sprite;
    Sprite S10Sprite;
    Sprite S11Sprite;
    Sprite S12Sprite;

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
    void updateMainMenu();
    void updateTutorial();
    void updateChooseNumPlayers();
    void updateChooseCharScreen();
    void updateGameEvent();
    void updatePauseScreen();
    void updateWinScreen();

    // render
    void renderMainMenu();
    void renderChooseNum();
    void renderChooseChar();
    void renderMainGame();
    void renderPauseScreen();
    void renderWinScreen();

    // main game render
    void renderButtons();
    void setBackground();
    void setCandle();
    void setDeathIdle();
    void setDashboard();
    void updateOverallValue();
    void updatePlayerNum();
    void renderBust();
    void winLoop();
    void restoreCards();
    
    // game logic
    void runRound();
    void intCardSprites();

    void renderDeck();
    void renderCard(const card&, float, float);
    //void initRound();
};

// main menu classes
//Main Menu classes

enum menuState{
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
    Image icon;

    //sprites
    Sprite Death;
    Sprite mainMenuBG;
    Sprite Title;
    Sprite Tutorial;
    Font font;

    //buttons
    button playButton;
    button tutorialButton;
    button backButton;

    //game
    game *g;

    //leaderboard
    Leaderboard winners;

public:
    menu();
    ~menu();
    
    //initialize
    void intMenuTex();
    void intMenuWin();
    void intMenuVar();
    const bool running() const;
    void run();
    void update();
    void render();
    void createGame();
    // void insertWinner(player);
    // void displayWinners();
};

#endif