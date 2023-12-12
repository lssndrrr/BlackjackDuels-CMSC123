#include "game.hpp"
#include "players.hpp"

game::game(){
    this->intTex();
    this->intVar(); 
}

game::game(RenderWindow*& window, View& view, VideoMode& video) {
    this->intWin(window, view, video);
    this->intTex();
    this->intVar();
}

void game::intVar(){
    this->state = gameState::chooseNumPlayersScreen;
    this->numPlayers = 0;
    this->lose = this->stand = false;
    this->i = 1;
    this->jackFlag = 0;
    this->jakeFlag = 0;
    this->jacksonFlag = 0;
    this->jadeFlag = 0;
    this->paused = this->out = this->end = false;
    this->open = true;

    Vector2f heartSize = dead.getGlobalBounds().getSize();
    float initPos = jackSprite.getGlobalBounds().width + 125.f;

    for(int x = 0; x < 10; x++) {
        deaths.push_back(dead);
        deaths[x].setPosition(initPos + ((heartSize.x + 10.f) * x), window->getSize().y - heartSize.y - 40.f);

        lives.push_back(life);
        lives[x].setPosition(initPos + ((heartSize.x + 10.f) * x), window->getSize().y - heartSize.y - 40.f);
    }
}

void game::intWin(RenderWindow*& window, View& view, VideoMode& video){
    this->video = video;
    this->window = window;
    this->view = view;
    this->window->setVerticalSyncEnabled(false);
}

const bool game::running() const{
    return this->open;
}

player game::run(){
    player winner;

    while (running()) {
        winner = update();
        render();
    }

    return winner;
}


player game::update(){
    player tmp; //for return purposes only, para walang error na lumabas

    if (state == gameState::chooseNumPlayersScreen) {
        updateChooseNumPlayers();
    }
    else if(state == gameState::chooseCharScreen) {
        updateChooseCharScreen();

        if(i == 2)
            num.setString("PLAYER 2");
        else if(i == 3)
            num.setString("PLAYER 3");
        else if(i == 4)
            num.setString("PLAYER 4");

        num.setPosition(((float)window->getSize().x - num.getGlobalBounds().width)/2, 140.f);

        if(i == numPlayers) {
            nextButton.text.setString("Start!");
            float NBtextPosX = (window->getSize().x - nextButton.btn.getLocalBounds().width) / 2 + (nextButton.btn.getLocalBounds().width / 2.f) - (nextButton.text.getLocalBounds().width / 2.f);
            float NBtextPosY = (window->getSize().y - nextButton.btn.getLocalBounds().height) / 2 + 250.5f + (nextButton.btn.getLocalBounds().height / 2.f) - (nextButton.text.getLocalBounds().height / 2.f + 17.0f);
            nextButton.text.setPosition(NBtextPosX, NBtextPosY);
        }

        if(current == players.playerlist.end())
            state = gameState::mainGameScreen;
    }
    else if (state == gameState::mainGameScreen){
        while(players.size() > 1){
            list<player>::iterator tmp;
            intCardSprites();
            current = players.playerlist.begin();
            highestValue = 0;
            restoreCards();

            gameDeck.dealCards(&players);

            while(current != players.playerlist.end()){
                cout << "state: " << this->state << endl;
                cout << "Player " << current->position << endl;
                current->d.displayDeck();
                current->d.findOverallValue();
                cout << "Overall value: " <<current->d.overallValue << endl;
                current->flag = false;

                updateOverallValue();
                updatePlayerNum();

                while(stand == false && lose == false){
                    setDeathIdle();
                    setCandle(); //found in textures.cpp
                    setDashboard();
                    updateGameEvent();

                    if(this->paused) { 
                        this->state = gameState::pauseScreen;
                        while(this->paused) { //loops the game in pause state as long as continue button isn't pressed
                            updatePauseScreen();
                            renderPauseScreen();
                        }
                    }
                    else
                        renderMainGame();

                    if(current->d.overallValue > 21){
                        cout << "Bust!" << endl;
                        lose = true;
                        current->flag = true;

                        bust.restart();
                        renderBust();
                    }

                    if(lose){
                        if(current->health > 10) {
                            current->health = current->health - 10;
                        } 
                        else {
                            tmp = std::next(current, 1);
                            players.transferPlayer(current, &defeated);
                            this->out = true;

                            if(players.size() <= 1) {
                                this->state = gameState::winScreen;
                                this->end = true;
                                update();
                                winLoop();
                                gameMusic.stop();
                                return players.playerlist.front();
                            }
                        }
                    }
                }

                if(!this->out) {
                    if(highestValue < current->d.overallValue && current->d.overallValue < 22)
                        highestValue = current->d.overallValue;

                    current++;
                }
                else {
                    current = tmp;
                }
                this->stand = this->lose = this->out = false;
            }

            current = players.playerlist.begin();
            while(current != players.playerlist.end()){
                if(highestValue > current->d.overallValue && current->flag != true){
                    if(current->health > 10){
                        current->health -= 10;
                    }
                    else{
                        tmp = std::next(current, 1);
                        players.transferPlayer(current, &defeated);
                        this->out = true;

                        if(players.size() <= 1) {
                            this->state = gameState::winScreen;
                            this->end = true;
                            update();
                            winLoop();
                            gameMusic.stop();
                            return players.playerlist.front();
                        }
                    }
                } 
                else {
                    current->flag = false;
                }

                if(!this->out) {
                    current->d.cards.clear();
                    ++current;
                }
                else {
                    current = tmp;
                }
            }
            
            cout << "Current standing:" << endl;
            players.displayPlayers();
            cout << endl << endl <<  "Size: " << players.size() << endl << endl;
        }
        
        if(players.playerlist.size() <= 1) {
            this->state = gameState::winScreen;
            this->end = true;
            update();
            winLoop();
            gameMusic.stop();
            return players.playerlist.front();
        }
    }
    else if (state == gameState::winScreen) {
        std::stringstream winText;

        winText << "PLAYER " << players.playerlist.front().position << " WINS!";
        cout << "Points: " << players.playerlist.front().points << endl;

        winner.setString(winText.str());
        winner.setPosition((window->getSize().x / 2) - (winner.getGlobalBounds().width / 2), (window->getSize().y / 2) - (winner.getGlobalBounds().height + 200.f));
    }

    return tmp;
}

void game::winLoop() {
    while(this->end) {
        updateWinScreen();
        renderWinScreen();
    }

    this->end = true;
    this->open = false;
}

void game::restoreCards() {
    if(gameDeck.size() < 10) {
        gameDeck.gameDeck();
        gameDeck.shuffle();
        intCardSprites();
        cout << "---Cards restored---" << endl;
    }
}

void game::render(){
    this->window->clear();

    if (state == gameState::chooseNumPlayersScreen) {
        renderChooseNum();
    }
    else if(state == gameState::chooseCharScreen) {
        renderChooseChar();
    }
    else if (state == gameState::pauseScreen) {
        renderPauseScreen();
    }
    else if (state == gameState::winScreen) {
        renderWinScreen();
    }
    else if(state == gameState::loseScreen) {
        renderWinScreen();
    }

    this->window->display();
}