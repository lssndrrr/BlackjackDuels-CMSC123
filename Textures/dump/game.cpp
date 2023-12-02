#include "game.hpp"

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