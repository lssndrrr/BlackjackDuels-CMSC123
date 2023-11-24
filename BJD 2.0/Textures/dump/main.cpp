#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <random>
#include <vector>
#include <algorithm>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

using namespace sf;

using std::string;
using std::cout;
using std::endl;
using std::cin;
using std::vector;

enum gameState{
    mainMenu,
    numPlayersScreen,
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

        void setTexture(Texture texture) {
            btn.setTexture(&texture);
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

    //Number of Players
    Text header;
    Button btn1, btn2, btn3, next;
    int numPlayers, numFlag = 0;

    //Choose characters
    Text header2;
    int i = numPlayers;
    Button c;

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

int main(){
    game game;
    game.run();

    return 0;
}

// buttons

game::game(){
    this->intVar(); 
    this->intWin();
    this->intTex();
}

game::~game()
{
    delete window;
}

void game::intVar(){
    this->window = NULL;
    state = mainMenu;
}

void game::intWin(){
    this->video.height = 720;
    this->video.width = 1280;
    this->window = new RenderWindow(this->video, "Blackjack Duels!", Style::Default);
    this->view = View(FloatRect(0.f, 0.f, 1280.f, 720.f));
    this->window->setVerticalSyncEnabled(false);
    this->window->setFramerateLimit(60);
}

void game::intTex(){
    Vector2f windowSize = Vector2f(window->getSize());
    switch(state){
        case gameState::mainMenu:
            // loading texture
            if(!MMBGtexture.loadFromFile("C:/Users/user/Documents/cmsc21/Textures/mainmenubg.png")){
                cout << "ERROR::MMBGtexture" << endl;
            }

            // setting texture
            mainMenuBG.setTexture(MMBGtexture);

            // scaling texture
            mainMenuBG.setScale(windowSize.x / MMBGtexture.getSize().x, windowSize.y / MMBGtexture.getSize().y);
            mainMenuBG.setPosition(0, 0);

            if(!font.loadFromFile("Fonts/joystix-monospace.otf"))
                throw("Font did not load :(");

            play.setTextString("PLAY");
            play.setSize({175, 70});
            play.setTextSize(50);
            play.setFont(font);
            play.setButtonColor(Color::Transparent);
            play.setTextColor(Color::White);
            play.setPosition({540, 450});

            quit.setTextString("QUIT");
            quit.setSize({175, 70});
            quit.setTextSize(50);
            quit.setFont(font);
            quit.setButtonColor(Color::Transparent);
            quit.setTextColor(Color::White);
            quit.setPosition({540, 550});

        case gameState::numPlayersScreen:
            // loading texture
            if(!MMBGtexture.loadFromFile("C:/Users/user/Documents/cmsc21/Textures/mainmenubg.png")){
                cout << "ERROR::MMBGtexture" << endl;
            }

            // setting texture
            mainMenuBG.setTexture(MMBGtexture);

            // scaling texture
            mainMenuBG.setScale(windowSize.x / MMBGtexture.getSize().x, windowSize.y / MMBGtexture.getSize().y);
            mainMenuBG.setPosition(0, 0);

            if(!font.loadFromFile("Fonts/joystix-monospace.otf"))
                throw("Font did not load :(");

            header.setFont(font);
            header.setCharacterSize(45);
            header.setFillColor(Color::White);
            header.setString("CHOOSE NUMBER OF PLAYERS");
            header.setPosition(((float)window->getSize().x - header.getGlobalBounds().width)/2, 100.f);

            btn1.setTextString("2 PLAYERS");
            btn1.setSize({300, 375});
            btn1.setTextSize(30);
            btn1.setFont(font);
            btn1.setButtonColor(Color{55, 55, 55, 150});
            btn1.setTextColor(Color::White);
            btn1.setPosition({150, 200});

            btn2.setTextString("3 PLAYERS");
            btn2.setSize({300, 375});
            btn2.setTextSize(30);
            btn2.setFont(font);
            btn2.setButtonColor(Color{55, 55, 55, 150});
            btn2.setTextColor(Color::White);
            btn2.setPosition({490, 200});

            btn3.setTextString("4 PLAYERS");
            btn3.setSize({300, 375});
            btn3.setTextSize(30);
            btn3.setFont(font);
            btn3.setButtonColor(Color{55, 55, 55, 150});
            btn3.setTextColor(Color::White);
            btn3.setPosition({830, 200});

            next.setTextString("NEXT");
            next.setSize({120, 50});
            next.setTextSize(18);
            next.setFont(font);
            next.setButtonColor(Color{55, 55, 55, 255});
            next.setTextColor(Color::White);
            next.setPosition({(float)window->getSize().x - 270, (float)window->getSize().y - 100});

            break;

        case gameState::chooseCharScreen:
            // loading texture
            if(!MMBGtexture.loadFromFile("C:/Users/user/Documents/cmsc21/Textures/mainmenubg.png")){
                cout << "ERROR::MMBGtexture" << endl;
            }

            // setting texture
            mainMenuBG.setTexture(MMBGtexture);

            // scaling texture
            mainMenuBG.setScale(windowSize.x / MMBGtexture.getSize().x, windowSize.y / MMBGtexture.getSize().y);
            mainMenuBG.setPosition(0, 0);

            if(!font.loadFromFile("Fonts/joystix-monospace.otf"))
                throw("Font did not load :(");
                
            break;

        default:            break;
    }
}

const bool game::running() const{
    return this->window->isOpen();
}

void game::run(){
    while (running()){
        update();
        render();
    }
}

void game::updateEvents(){
    while(this->window->pollEvent(this->event)){
        switch(this->event.type){
            case Event::Closed:
                window->close();
                break;

            case Event::KeyPressed:
                if(this->event.key.code == Keyboard::Escape)
                    window->close();
                break;

            case Event::Resized:
                aspectRatio = static_cast<float>(event.size.width) / event.size.height;
                viewWidth, viewHeight;
                if(aspectRatio > 16.f / 9.f){
                    viewHeight = static_cast<float>(event.size.height);
                    viewWidth = viewHeight * (16.f / 9.f);
                } else{
                    viewWidth = static_cast<float>(event.size.width);
                    viewHeight = viewWidth / (16.f / 9.f);
                }
                this->view.setSize(viewWidth, viewHeight);
                window->setSize(Vector2u(viewWidth, viewHeight));
                break;

            case Event::MouseMoved:
                //Main Menu
                if(play.isMouseOver(*window)) {
                    if(Mouse::isButtonPressed(Mouse::Left)) {
                        play.setTextColor(Color::Green);
                        playFlag = 1;
                    }
                    else
                        play.setTextColor(Color::Green);
                }
                else
                    play.setTextColor(Color::White);

                if(quit.isMouseOver(*window)) {
                    if(Mouse::isButtonPressed(Mouse::Left)) {
                        quit.setTextColor(Color::Red);
                        quitFlag = 1;
                    }
                    else
                        quit.setTextColor(Color::Red);
                }
                else
                    quit.setTextColor(Color::White);

                //Choose number players

                if(btn1.isMouseOver(*window)) {
                    if(Mouse::isButtonPressed(Mouse::Left)) 
                        numPlayers = 2; //return maybe?? dpending on the implementation
                    else {
                        btn1.setButtonColor(Color{55, 55, 55, 255});
                        btn1.setTextColor(Color::White);
                    }
                }
                else {
                    btn1.setButtonColor(Color{55, 55, 55, 150});
                    btn1.setTextColor(Color::White);
                }

                if(btn2.isMouseOver(*window)) {
                    if(Mouse::isButtonPressed(Mouse::Left)) 
                        numPlayers = 3; //return maybe?? dpending on the implementation
                    else {
                        btn2.setButtonColor(Color{55, 55, 55, 255});
                        btn2.setTextColor(Color::White);
                    }
                }
                else {
                    btn2.setButtonColor(Color{55, 55, 55, 150});
                    btn2.setTextColor(Color::White);
                }

                if(btn3.isMouseOver(*window)) {
                    if(Mouse::isButtonPressed(Mouse::Left)) 
                        numPlayers = 4; //return maybe?? dpending on the implementation
                    else {
                        btn3.setButtonColor(Color{55, 55, 55, 255});
                        btn3.setTextColor(Color::White);
                    }
                }
                else {
                    btn3.setButtonColor(Color{55, 55, 55, 150});
                    btn3.setTextColor(Color::White);
                }

                if((numPlayers == 2 || numPlayers == 3 || numPlayers == 4) && next.isMouseOver(*window)) {
                    if(Mouse::isButtonPressed(Mouse::Left)) 
                        numFlag = 1;
                    else {
                        next.setButtonColor(Color{55, 55, 55, 255});
                        next.setTextColor(Color::White);
                    }
                }
                else {
                    btn3.setButtonColor(Color{55, 55, 55, 150});
                    btn3.setTextColor(Color::White);
                }
                
                // break;
            default:
                break;
        }
    }
}

void game::updateMouse(){
    this->mousePosW = Mouse::getPosition(*this->window);
    this->mousePosV = this->window->mapPixelToCoords((this->mousePosW));
}

void game::update(){
    updateEvents();
    switch(state){
        case gameState::mainMenu:
        // do main menu things
        // if button pressed, current = choosecharscreen
            if(playFlag) {
                play.setTextColor(Color::Green);
                state = numPlayersScreen;
            }

            if(quitFlag) {
                quit.setTextColor(Color::Red);
                window->close();
            }

            break;

        case gameState::numPlayersScreen:
        // do charscreen things
        // once everyone has chosen, a start button appears

            if(numPlayers == 2) {
                btn1.setButtonColor(Color::White);
                btn1.setTextColor(Color::Black);
            }
            else if(numPlayers == 3) {
                btn2.setButtonColor(Color::White);
                btn2.setTextColor(Color::Black);
            }
            else if(numPlayers == 4) {
                btn3.setButtonColor(Color::White);
                btn3.setTextColor(Color::Black);
            }
            
            if(numFlag) {
                next.setButtonColor(Color::White);
                next.setTextColor(Color::Black);
            }

            break;

        case gameState::chooseCharScreen:
        // do charscreen things
        // once everyone has chosen, a start button appears
        break;
        case gameState::mainGameScreen:
        // do maingamesceen things
        
        // players.addPlayers(numPlayers);

        break;
        case gameState::pauseScreen:
        // do pausegame things
        break;
        case gameState::winScreen:
        // do winScreen things
        break;
        default:            break;
    }
}

void game::render(){
    this->window->clear();
    switch(state){
        case gameState::mainMenu:
            window->draw(mainMenuBG);
            play.drawTo(*window);
            quit.drawTo(*window);

            break;
        case gameState::numPlayersScreen:
            window->draw(mainMenuBG);
            window->draw(header);
            btn1.drawTo(*window);
            btn2.drawTo(*window);
            btn3.drawTo(*window);
            next.drawTo(*window);

            if(numFlag)
                state = chooseCharScreen;

            break;
        case gameState::chooseCharScreen:
        // do charscreen things
            break;
        case gameState::mainGameScreen:
        // do maingamesceen things
        break;
        case gameState::pauseScreen:
        // do pausegame things
        break;
        case gameState::winScreen:
        // do winScreen things
        break;
        default:            break;
    }
    this->window->display();
}

#endif