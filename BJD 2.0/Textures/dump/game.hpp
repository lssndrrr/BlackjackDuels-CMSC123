#include "header.hpp"

enum gameState{
    mainMenu,
    numPlayers,
    chooseCharScreen,
    mainGameScreen,
    pauseScreen,
    winScreen
};

class Button {
    private:
        RectangleShape btn;
        Text text;

    public:
        Button() {

        }
        Button(std::string t, Vector2f size, int charSize, Color bgColor, Color textColor) {
            text.setString(t);
            text.setFillColor(textColor);
            text.setCharacterSize(charSize);

            btn.setSize(size);
            btn.setFillColor(bgColor);
        }

        void setTextString(std::string t) {
            text.setString(t);
        }

        void setSize(Vector2f size) {
            btn.setSize(size);
        }

        void setTextSize(int charSize) {
            text.setCharacterSize(charSize);
        }

        void setFont(Font &font) {
            text.setFont(font);
        }

        void setButtonColor(Color color) {
            btn.setFillColor(color);
        }

        void setTextColor(Color color) {
            text.setFillColor(color);
        }

        void setPosition(Vector2f pos) {
            btn.setPosition(pos);

            float xPos = pos.x + (btn.getLocalBounds().width / 2) - (text.getGlobalBounds().width / 2), 
                  yPos = pos.y + (btn.getGlobalBounds().height /2) - (text.getGlobalBounds().height);

            text.setPosition({xPos, yPos});
        }

        void drawTo(RenderWindow &window) {
            window.draw(btn);
            window.draw(text);
        }

        bool isMouseOver(RenderWindow &window) {
            float mouseX = Mouse::getPosition(window).x,
                mouseY = Mouse::getPosition(window).y,

                btnPosX = btn.getPosition().x,
                btnPosY = btn.getPosition().y,

                btnxPosWidth = btn.getPosition().x + btn.getGlobalBounds().width,
                btnyPosHeight = btn.getPosition().y + btn.getGlobalBounds().height;

            if(mouseX < btnxPosWidth && mouseX > btnPosX && mouseY < btnyPosHeight && mouseY > btnPosY) {
                return true;
            }
            
            return false;
        }
};

class game{
    // SFML Basics
    RenderWindow* window;
    View view;
    gameState state;
    Event event;
    VideoMode video;
    float aspectRatio, viewHeight, viewWidth;

    // Mouse
    Vector2i mousePosW;
    Vector2f mousePosV;

    // Sprites and Textures
    Texture MMBGtexture;
    // Texture PlayButtonTexture;
    // button playButton;
    Sprite mainMenuBG;

    //Main Menu
    Font font;
    Button play, quit;
    int playFlag = 0, quitFlag = 0;

    // init funcs
    void intVar();
    void intTex();
    void intWin();
public:
    game();
    ~game();
    const bool running() const;
    void updateEvents();
    void updateMouse();
    void run(); // int for number of players
    void update();
    void render();
};