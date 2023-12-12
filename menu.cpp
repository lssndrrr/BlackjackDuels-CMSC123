#include "game.hpp"
#include "header.hpp"
#include "menu.hpp"

menu::menu() {
    winners.readData();
    this->intMenuWin();
    this->intMenuTex();
    this->intMenuVar();
    this->intLeaderboard();
}

menu::~menu() {
    delete this->window;
}

void menu::titleLoop() {
    if(loop.getElapsedTime().asMilliseconds()/100 >= 6)
        loop.restart();

    if(loop.getElapsedTime().asMilliseconds()/100 == 0)
        Titletexture.loadFromFile("Textures/title/00.png");
    else if(loop.getElapsedTime().asMilliseconds()/100 == 1)
        Titletexture.loadFromFile("Textures/title/01.png");
    else if(loop.getElapsedTime().asMilliseconds()/100 == 2)
        Titletexture.loadFromFile("Textures/title/02.png");
    else if(loop.getElapsedTime().asMilliseconds()/100 == 3)
        Titletexture.loadFromFile("Textures/title/03.png");
    else if(loop.getElapsedTime().asMilliseconds()/100 == 4)
        Titletexture.loadFromFile("Textures/title/04.png");
    else if(loop.getElapsedTime().asMilliseconds()/100 == 5)
        Titletexture.loadFromFile("Textures/title/05.png");

    Title.setTexture(Titletexture);
    Title.setScale(0.5, 0.5);
    Vector2f TitleSpriteSize = Title.getLocalBounds().getSize() * 0.5f;
    Vector2f positionTitle((window->getSize().x - TitleSpriteSize.x) / 2, (window->getSize().y - TitleSpriteSize.y) / 2 - 20.0f);
    Title.setPosition(positionTitle);
}

void menu::bgLoop() {
    if(BGloop.getElapsedTime().asMilliseconds()/100 >= 16)
        BGloop.restart();

    if(BGloop.getElapsedTime().asMilliseconds()/100 == 0)
        MMBGtexture.loadFromFile("Textures/background/00.png");
    else if(BGloop.getElapsedTime().asMilliseconds()/100 == 1)
        MMBGtexture.loadFromFile("Textures/background/01.png");
    else if(BGloop.getElapsedTime().asMilliseconds()/100 == 2)
        MMBGtexture.loadFromFile("Textures/background/02.png");
    else if(BGloop.getElapsedTime().asMilliseconds()/100 == 3)
        MMBGtexture.loadFromFile("Textures/background/03.png");
    else if(BGloop.getElapsedTime().asMilliseconds()/100 == 4)
        MMBGtexture.loadFromFile("Textures/background/04.png");
    else if(BGloop.getElapsedTime().asMilliseconds()/100 == 5)
        MMBGtexture.loadFromFile("Textures/background/05.png");
    else if(BGloop.getElapsedTime().asMilliseconds()/100 == 6)
        MMBGtexture.loadFromFile("Textures/background/06.png");
    else if(BGloop.getElapsedTime().asMilliseconds()/100 == 7)
        MMBGtexture.loadFromFile("Textures/background/07.png");
    else if(BGloop.getElapsedTime().asMilliseconds()/100 == 8)
        MMBGtexture.loadFromFile("Textures/background/08.png");
    else if(BGloop.getElapsedTime().asMilliseconds()/100 == 9)
        MMBGtexture.loadFromFile("Textures/background/09.png");
    else if(BGloop.getElapsedTime().asMilliseconds()/100 == 10)
        MMBGtexture.loadFromFile("Textures/background/10.png");
    else if(BGloop.getElapsedTime().asMilliseconds()/100 == 11)
        MMBGtexture.loadFromFile("Textures/background/11.png");
    else if(BGloop.getElapsedTime().asMilliseconds()/100 == 12)
        MMBGtexture.loadFromFile("Textures/background/12.png");
    else if(BGloop.getElapsedTime().asMilliseconds()/100 == 13)
        MMBGtexture.loadFromFile("Textures/background/13.png");
    else if(BGloop.getElapsedTime().asMilliseconds()/100 == 14)
        MMBGtexture.loadFromFile("Textures/background/14.png");
    else if(BGloop.getElapsedTime().asMilliseconds()/100 == 15)
        MMBGtexture.loadFromFile("Textures/background/15.png");

    mainMenuBG.setTexture(MMBGtexture);
    mainMenuBG.setScale(1.5f, 1.5f);
    mainMenuBG.setPosition(0, 0);
}

void menu::intMenuTex() {
    Vector2f windowSize = Vector2f(window->getSize());

    //music and sfx
    if(!menuMusic.openFromFile("Music/mainMenuMusic.wav"))
        cout << "ERROR::menuMusic" << endl;
    menuMusic.setLoop(true);
    menuMusic.play();

    if(!clickButtonBuffer.loadFromFile("Music/clickButton.wav"))
        cout << "ERROR::clickButton" << endl;
    clickButton.setBuffer(clickButtonBuffer);

    //loading texture
    if(!BGtexture.loadFromFile("Textures/mainmenubg.png")){
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
    BG.setTexture(BGtexture);
    Death.setTexture(Deathtexture);
    window->setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    playButton.setButton("START!", Vector2f(280.0, 70.0), 40, &Buttontexture, Color::Black, &font);
    tutorialButton.setButton("Tutorial", Vector2f(280.0, 70.0), 40, &Buttontexture, Color::Black, &font);
    LBButton.setButton("Leaderboard", Vector2f(280.0, 70.0), 40, &Buttontexture, Color::Black, &font);
    backButton.setButton("Back", Vector2f(175.0, 70.0), 50, &Buttontexture, Color::Black, &font);
    Tutorial.setTexture(Tutorialtexture);

    //Texts
    lbText.setFont(font);
    lbText.setString("HALL OF FAME");
    lbText.setFillColor(Color::White);
    lbText.setCharacterSize(75);
    lbText.setPosition(((float)window->getSize().x - lbText.getGlobalBounds().width)/2, 50.f);


    //scaling texture
    BG.setScale(windowSize.x / BGtexture.getSize().x, windowSize.y / BGtexture.getSize().y);
    Death.setScale(2.0, 2.0);
    Tutorial.setScale(windowSize.x / Tutorialtexture.getSize().x, windowSize.y / Tutorialtexture.getSize().y);

    //position
    BG.setPosition(0, 0);
    Tutorial.setPosition(0, 0);

    Vector2f deathSpriteSize = Death.getLocalBounds().getSize() * 2.0f;
    Vector2f positionDeath((windowSize.x - deathSpriteSize.x) / 2, (windowSize.y - deathSpriteSize.y) / 2 - 110.0f);
    Death.setPosition(positionDeath);

    Vector2f playbtnSize = playButton.btn.getLocalBounds().getSize();
    Vector2f positionplaybtn((windowSize.x - playbtnSize.x) / 2, (windowSize.y - playbtnSize.y) / 2 + 90.5f);
    playButton.setPosition(positionplaybtn);

    float PBtextPosX = positionplaybtn.x + (playbtnSize.x / 2.f) - (playButton.text.getLocalBounds().width / 2.f);
    float PBtextPosY = positionplaybtn.y + (playbtnSize.y / 2.f) - (playButton.text.getLocalBounds().height / 2.f + 15.5f);
    playButton.text.setPosition(PBtextPosX, PBtextPosY);

    Vector2f tutorialbtnSize = tutorialButton.btn.getLocalBounds().getSize();
    Vector2f positiontutorialbtn((windowSize.x - tutorialbtnSize.x) / 2, (windowSize.y - tutorialbtnSize.y) / 2 + 250.5f);
    tutorialButton.setPosition(positiontutorialbtn);
    
    float TBtextPosX = positiontutorialbtn.x + (tutorialbtnSize.x / 2.f) - (tutorialButton.text.getLocalBounds().width / 2.f);
    float TBtextPosY = positiontutorialbtn.y + (tutorialbtnSize.y / 2.f) - (tutorialButton.text.getLocalBounds().height / 2.f + 20.5f) + 5.f;
    tutorialButton.text.setPosition(TBtextPosX, TBtextPosY);

    Vector2f backbtnSize = backButton.btn.getLocalBounds().getSize();
    Vector2f positionbackbtn((windowSize.x - backbtnSize.x) / 2 - 500.f, (windowSize.y - backbtnSize.y) / 2 + 250.f);
    backButton.setPosition(positionbackbtn);
    
    float BBtextPosX = positionbackbtn.x + (backbtnSize.x / 2.f) - (backButton.text.getLocalBounds().width / 2.f);
    float BBtextPosY = positionbackbtn.y + (backbtnSize.y / 2.f) - (backButton.text.getLocalBounds().height / 2.f) - 15.f;
    backButton.text.setPosition(BBtextPosX, BBtextPosY);

    Vector2f LBbtnSize = LBButton.btn.getLocalBounds().getSize();
    Vector2f positionLBbtn((windowSize.x - LBbtnSize.x) / 2, (windowSize.y - LBbtnSize.y) / 2 + 170.f);
    LBButton.setPosition(positionLBbtn);

    float LBtextPosX = positionLBbtn.x + (LBbtnSize.x / 2.f) - (LBButton.text.getLocalBounds().width / 2.f);
    float LBtextPosY = positionLBbtn.y + (LBbtnSize.y / 2.f) - (LBButton.text.getLocalBounds().height / 2.f + 15.5f);
    LBButton.text.setPosition(LBtextPosX, LBtextPosY);
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
        bgLoop();
        titleLoop();

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

                    if (LBButton.isMouseOver(*window)){
                        LBButton.setTextColor(Color::Green);
                    } 
                    else {
                        LBButton.setTextColor(Color::Black);
                    }
                    break;

                case Event::MouseButtonPressed:
                    if (this->event.mouseButton.button == Mouse::Left && playButton.isMouseOver(*window)){
                        clickButton.play();
                        createGame();
                    } 
                    else if(this->event.mouseButton.button == Mouse::Left && tutorialButton.isMouseOver(*window)){
                        clickButton.play();
                        this->menuState = menuState::tutorialScreen;
                    }
                    else if(this->event.mouseButton.button == Mouse::Left && LBButton.isMouseOver(*window)){
                        clickButton.play();
                        this->menuState = menuState::leaderboard;
                        updateLeaderboard();
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
                        clickButton.play();
                        this->menuState = menuState::mainMenu;
                    }
                    break;

                default:
                    break;
            }
        }
    }
    else if(this->menuState == menuState::leaderboard) {
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
                        clickButton.play();
                        this->menuState = menuState::mainMenu;
                    }
                    break;

                default:
                    break;
            }
        }
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
        LBButton.drawButton(*window);
    }
    else if(this->menuState == menuState::tutorialScreen) {
        window->draw(BG);
        backButton.drawButton(*window);
        window->draw(Tutorial);
    }
    else if(this->menuState == menuState::leaderboard) {
        window->draw(BG);
        backButton.drawButton(*window);
        window->draw(lbText);
        for(int i = 0; i < 5; i++){
            window->draw(lbUsernames[i]);
            window->draw(lbPoints[i]);            
        }
    }
    this->window->display();
}

void menu::createGame() {
    this->g = new game(this->window, this->view, this->video);
    menuMusic.stop();
    player winner = g->run();
    menuMusic.play();

    winners.insort(winner.getUsername(), winner.getPoints());
    winners.writeData();
}

void menu::updateLeaderboard(){
    if(winners.size() == 0)
        return;
    
    for(int i = 0; i < winners.size(); i++){
        if(i == 10)
            return;

        lbUsernames[i].setFont(font);
        lbUsernames[i].setString(std::to_string(i+1) + ". " + winners[i]->getUsername());
        lbUsernames[i].setCharacterSize(50);
        lbUsernames[i].setPosition(((float)window->getSize().x - lbText.getGlobalBounds().width)/3, 175.f + (75.f * i));

        lbPoints[i].setFont(font);
        lbPoints[i].setString(winners[i]->getPoints());
        lbPoints[i].setCharacterSize(50);
        lbPoints[i].setPosition(((float)window->getSize().x - lbText.getGlobalBounds().width)*12/10, 175.f + (75.f * i));
        
        if(i == 0){
            lbPoints[i].setFillColor(Color(218,165,32));
            lbUsernames[i].setFillColor(Color(218,165,32));
        }else if(i == 1){
            lbPoints[i].setFillColor(Color(172,172,172));
            lbUsernames[i].setFillColor(Color(172,172,172));
        }else if(i == 2){
            lbPoints[i].setFillColor(Color(150,116,68));
            lbUsernames[i].setFillColor(Color(150,116,68));
        }else{
            lbPoints[i].setFillColor(Color::White);
            lbUsernames[i].setFillColor(Color::White);
        }
    }
}

void menu::intLeaderboard(){
    for(int i = 0; i < 10; i++){
        lbUsernames[i].setFont(font);
        lbUsernames[i].setString(std::to_string(i+1) + ". ");
        lbUsernames[i].setFillColor(Color::White);
        lbUsernames[i].setCharacterSize(50);
        lbUsernames[i].setPosition(((float)window->getSize().x - lbText.getGlobalBounds().width)/3, 175.f + (75.f * i));
        lbPoints[i].setFont(font);
        lbPoints[i].setString("");
        lbPoints[i].setFillColor(Color::White);
        lbPoints[i].setCharacterSize(50);
        lbPoints[i].setPosition(((float)window->getSize().x - lbText.getGlobalBounds().width)*12/10  , 175.f + (75.f * i));
    }
}

// void menu::insertWinner(player winner) {
//     if(this->winners.empty())
//         winners.push_back(winner);
//     else {
//         list<player>::iterator i = this->winners.begin();

//         while(i != this->winners.end()) { //winners are arranged in descending order
//             if(winner.getPoints() >= (*i).getPoints()) {
//                 this->winners.insert(i,winner);
//                 return;
//             }
//             i++;
//         }

//         this->winners.push_back(winner);
//     }

//     displayWinners();
// }

// void menu::displayWinners() {
//     list<player>::iterator i = this->winners.begin();
//     int pos = 1;

//     while(i != this->winners.end()) {
//         cout << pos << ". " << (*i).getUsername() << " - " << (*i).getPoints() << " points" << endl;
//         i++;
//     }
// }