#include "game.hpp"
#include "header.hpp"

menu::menu() {
    this->intMenuWin();
    this->intMenuTex();
    this->intMenuVar();
}

menu::~menu() {
    delete this->window;
}

void menu::intMenuTex() {
    Vector2f windowSize = Vector2f(window->getSize());

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
    if(!Tutorialtexture.loadFromFile("Textures/tutorial.png")){
        cout << "ERROR::Tutorial" << endl;
    }
    if(!font.loadFromFile("Fonts/alagard.ttf")){
        cout << "ERROR::font" << endl;
    }

    //setting textures
    mainMenuBG.setTexture(MMBGtexture);
    Death.setTexture(Deathtexture);
    window->setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    Title.setTexture(Titletexture);
    playButton.setButton("Play", Vector2f(175.0, 70.0), 50, &Buttontexture, Color::Black, &font);
    tutorialButton.setButton("Learn", Vector2f(175.0, 70.0), 50, &Buttontexture, Color::Black, &font);
    backButton.setButton("Back", Vector2f(175.0, 70.0), 50, &Buttontexture, Color::Black, &font);
    Tutorial.setTexture(Tutorialtexture);

    //scaling texture
    mainMenuBG.setScale(windowSize.x / MMBGtexture.getSize().x, windowSize.y / MMBGtexture.getSize().y);
    Death.setScale(2.0, 2.0);
    Title.setScale(0.5, 0.5);
    Tutorial.setScale(windowSize.x / Tutorialtexture.getSize().x, windowSize.y / Tutorialtexture.getSize().y);

    //position
    mainMenuBG.setPosition(0, 0);
    Tutorial.setPosition(0, 0);

    Vector2f deathSpriteSize = Death.getLocalBounds().getSize() * 2.0f;
    Vector2f positionDeath((windowSize.x - deathSpriteSize.x) / 2, (windowSize.y - deathSpriteSize.y) / 2 - 110.0f);
    Death.setPosition(positionDeath);

    Vector2f TitleSpriteSize = Title.getLocalBounds().getSize() * 0.5f;
    Vector2f positionTitle((windowSize.x - TitleSpriteSize.x) / 2, (windowSize.y - TitleSpriteSize.y) / 2 - 20.0f);
    Title.setPosition(positionTitle);

    Vector2f playbtnSize = playButton.btn.getLocalBounds().getSize();
    Vector2f positionplaybtn((windowSize.x - playbtnSize.x) / 2, (windowSize.y - playbtnSize.y) / 2 + 110.5f);
    playButton.setPosition(positionplaybtn);

    float PBtextPosX = positionplaybtn.x + (playbtnSize.x / 2.f) - (playButton.text.getLocalBounds().width / 2.f);
    float PBtextPosY = positionplaybtn.y + (playbtnSize.y / 2.f) - (playButton.text.getLocalBounds().height / 2.f + 15.5f);
    playButton.text.setPosition(PBtextPosX, PBtextPosY);

    Vector2f tutorialbtnSize = tutorialButton.btn.getLocalBounds().getSize();
    Vector2f positiontutorialbtn((windowSize.x - tutorialbtnSize.x) / 2, (windowSize.y - tutorialbtnSize.y) / 2 + 210.5f);
    tutorialButton.setPosition(positiontutorialbtn);
    
    float TBtextPosX = positiontutorialbtn.x + (tutorialbtnSize.x / 2.f) - (tutorialButton.text.getLocalBounds().width / 2.f);
    float TBtextPosY = positiontutorialbtn.y + (tutorialbtnSize.y / 2.f) - (tutorialButton.text.getLocalBounds().height / 2.f + 20.5f) + 5.f;
    tutorialButton.text.setPosition(TBtextPosX, TBtextPosY);

    Vector2f backbtnSize = backButton.btn.getLocalBounds().getSize();
    Vector2f positionbackbtn((windowSize.x - backbtnSize.x) / 2 - 400.f, (windowSize.y - backbtnSize.y) / 2 + 250.f);
    backButton.setPosition(positionbackbtn);
    
    float BBtextPosX = positionbackbtn.x + (backbtnSize.x / 2.f) - (backButton.text.getLocalBounds().width / 2.f);
    float BBtextPosY = positionbackbtn.y + (backbtnSize.y / 2.f) - (backButton.text.getLocalBounds().height / 2.f) - 15.f;
    backButton.text.setPosition(BBtextPosX, BBtextPosY);
}

void menu::intMenuWin() {
    this->window = NULL;
    video.height = 720;
    video.width = 1280;
    window = new RenderWindow(video, "Blackjack Duels!", Style::Default);
    view = View(FloatRect(0.f, 0.f, 1280.f, 720.f));
    window->setVerticalSyncEnabled(false);
}

void menu::intMenuVar() {
    this->menuState = menuState::mainMenu;
}

const bool menu::running() const {
    return this->window->isOpen();
}

void menu::run() {
    while(this->running()) {
        this->update();
        this->render();
    }
}

void menu::update() {
    if(this->menuState == menuState::mainMenu) {
        while (this->window->pollEvent(this->event)) {
            switch (this->event.type) {
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
                    if (playButton.isMouseOver(*window)){
                        playButton.setTextColor(Color::Green);
                    } 
                    else {
                        playButton.setTextColor(Color::Black);
                    }

                    if (tutorialButton.isMouseOver(*window)){
                        tutorialButton.setTextColor(Color::Green);
                    } 
                    else {
                        tutorialButton.setTextColor(Color::Black);
                    }
                    break;

                case Event::MouseButtonPressed:
                    if (this->event.mouseButton.button == Mouse::Left && playButton.isMouseOver(*window)){
                        createGame();
                    } 
                    else if(this->event.mouseButton.button == Mouse::Left && tutorialButton.isMouseOver(*window)){
                        this->menuState = menuState::tutorialScreen;
                    }
                    break;

                default:
                    break;
            }
        }
    }
    else if(this->menuState == menuState::tutorialScreen) {
        while (this->window->pollEvent(this->event)) {
            switch (this->event.type){
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
                    if (backButton.isMouseOver(*window)){
                        backButton.setTextColor(Color::Green);
                    } else {
                        backButton.setTextColor(Color::Black);
                    }
                    break;

                case Event::MouseButtonPressed:
                    if (this->event.mouseButton.button == Mouse::Left && backButton.isMouseOver(*window)){
                        this->menuState = menuState::mainMenu;
                    }
                    break;

                default:
                    break;
            }
        }
    }
    else if(this->menuState == menuState::leaderboard) {

    }
}

void menu::render() {
    this->window->clear();

    if(this->menuState == menuState::mainMenu) {
        window->draw(mainMenuBG);
        window->draw(Death);
        window->draw(Title);
        playButton.drawButton(*window);
        tutorialButton.drawButton(*window);
    }
    else if(this->menuState == menuState::tutorialScreen) {
        window->draw(mainMenuBG);
        backButton.drawButton(*window);
        window->draw(Tutorial);
    }
    else if(this->menuState == menuState::leaderboard) {

    }

    this->window->display();
}

void menu::createGame() {
    this->g = new game(this->window, this->view, this->video);
    player winner = g->run();

    insertWinner(winner);
}

void menu::insertWinner(player winner) {
    if(this->winners.empty())
        winners.push_back(winner);
    else {
        list<player>::iterator i = this->winners.begin();
        while(i != this->winners.end()) { //winners are arranged in descending order
            if(winner.getPoints() >= (*i).getPoints()) {
                this->winners.insert(i,winner);
                return;
            }
            i++;
        }

        this->winners.push_back(winner);
    }

    displayWinners();
}

void menu::displayWinners() {
    list<player>::iterator i = this->winners.begin();
    int pos = 1;

    cout << "LEADERBOARD---------------" << endl;

    while(i != this->winners.end()) {
        cout << pos << ". " << (*i).getUsername() << " - " << (*i).getPoints() << " points" << endl;
        i++;
    }
}