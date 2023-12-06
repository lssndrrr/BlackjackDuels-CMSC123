#include "game.hpp"

void game::updatePlayerNum() {
    int pos = current->position;

    if(pos == 1)
        pTex.loadFromFile("Textures/P1.png");
    else if(pos == 2)
        pTex.loadFromFile("Textures/P2.png");
    else if(pos == 3)
        pTex.loadFromFile("Textures/P3.png");
    else if(pos == 4)
        pTex.loadFromFile("Textures/P4.png");

    p.setTexture(pTex);
    p.setScale(2, 2);
    p.setPosition(50.f, 25.f);
}

void game::setDashboard() {
    playerDashboard.setDashboard(current->c.charSprite, Color(0, 0, 0, 125), Vector2f(window->getSize().x, jackSprite.getGlobalBounds().height + 110.f));

    playerDashboard.setBackgroundPosition(Vector2f(0, window->getSize().y - playerDashboard.background.getGlobalBounds().height));

    Vector2f playerDBSize = playerDashboard.charContainer.getGlobalBounds().getSize();
    Vector2f playerDBPos(75.f, window->getSize().y - playerDBSize.y - 40.f);
    playerDashboard.setPosition(playerDBPos);
}

void game::setDeathIdle() {
    if(idle.getElapsedTime().asMilliseconds()/100 >= 26)
        idle.restart();

    if(idle.getElapsedTime().asMilliseconds()/100 == 0)
        deathIdleTex.loadFromFile("Textures/death_idle/00.png");
    else if(idle.getElapsedTime().asMilliseconds()/100 == 1)
        deathIdleTex.loadFromFile("Textures/death_idle/01.png");
    else if(idle.getElapsedTime().asMilliseconds()/100 == 2)
        deathIdleTex.loadFromFile("Textures/death_idle/02.png");
    else if(idle.getElapsedTime().asMilliseconds()/100 == 3)
        deathIdleTex.loadFromFile("Textures/death_idle/03.png");
    else if(idle.getElapsedTime().asMilliseconds()/100 == 4)
        deathIdleTex.loadFromFile("Textures/death_idle/04.png");
    else if(idle.getElapsedTime().asMilliseconds()/100 == 5)
        deathIdleTex.loadFromFile("Textures/death_idle/05.png");
    else if(idle.getElapsedTime().asMilliseconds()/100 == 6)
        deathIdleTex.loadFromFile("Textures/death_idle/06.png");
    else if(idle.getElapsedTime().asMilliseconds()/100 == 7)
        deathIdleTex.loadFromFile("Textures/death_idle/07.png");
    else if(idle.getElapsedTime().asMilliseconds()/100 == 8)
        deathIdleTex.loadFromFile("Textures/death_idle/08.png");
    else if(idle.getElapsedTime().asMilliseconds()/100 == 9)
        deathIdleTex.loadFromFile("Textures/death_idle/09.png");
    else if(idle.getElapsedTime().asMilliseconds()/100 == 10)
        deathIdleTex.loadFromFile("Textures/death_idle/10.png");
    else if(idle.getElapsedTime().asMilliseconds()/100 == 11)
        deathIdleTex.loadFromFile("Textures/death_idle/11.png");
    else if(idle.getElapsedTime().asMilliseconds()/100 == 12)
        deathIdleTex.loadFromFile("Textures/death_idle/12.png");
    else if(idle.getElapsedTime().asMilliseconds()/100 == 13)
        deathIdleTex.loadFromFile("Textures/death_idle/13.png");
    else if(idle.getElapsedTime().asMilliseconds()/100 == 14)
        deathIdleTex.loadFromFile("Textures/death_idle/14.png");
    else if(idle.getElapsedTime().asMilliseconds()/100 == 15)
        deathIdleTex.loadFromFile("Textures/death_idle/15.png");
    else if(idle.getElapsedTime().asMilliseconds()/100 == 16)
        deathIdleTex.loadFromFile("Textures/death_idle/16.png");
    else if(idle.getElapsedTime().asMilliseconds()/100 == 17)
        deathIdleTex.loadFromFile("Textures/death_idle/17.png");
    else if(idle.getElapsedTime().asMilliseconds()/100 == 18)
        deathIdleTex.loadFromFile("Textures/death_idle/18.png");
    else if(idle.getElapsedTime().asMilliseconds()/100 == 19)
        deathIdleTex.loadFromFile("Textures/death_idle/19.png");
    else if(idle.getElapsedTime().asMilliseconds()/100 == 20)
        deathIdleTex.loadFromFile("Textures/death_idle/20.png");
    else if(idle.getElapsedTime().asMilliseconds()/100 == 21)
        deathIdleTex.loadFromFile("Textures/death_idle/21.png");
    else if(idle.getElapsedTime().asMilliseconds()/100 == 22)
        deathIdleTex.loadFromFile("Textures/death_idle/22.png");
    else if(idle.getElapsedTime().asMilliseconds()/100 == 23)
        deathIdleTex.loadFromFile("Textures/death_idle/23.png");
    else if(idle.getElapsedTime().asMilliseconds()/100 == 24)
        deathIdleTex.loadFromFile("Textures/death_idle/24.png");
    else if(idle.getElapsedTime().asMilliseconds()/100 == 25)
        deathIdleTex.loadFromFile("Textures/death_idle/25.png");

    deathIdle.setTexture(deathIdleTex);
    deathIdle.setPosition((window->getSize().x / 2) - ((deathIdle.getGlobalBounds().width / 2) - 40.f), (window->getSize().y / 2) - (deathIdle.getGlobalBounds().height / 2 + 30.f));
}

void game::setCandle() {
    if(candleTime.getElapsedTime().asMilliseconds()/250 >= 15)
        candleTime.restart();

    if(candleTime.getElapsedTime().asMilliseconds()/250 == 0)
        candleTex.loadFromFile("Textures/candlelight/00.png");
    else if(candleTime.getElapsedTime().asMilliseconds()/250 == 1)
        candleTex.loadFromFile("Textures/candlelight/01.png");
    else if(candleTime.getElapsedTime().asMilliseconds()/250 == 2)
        candleTex.loadFromFile("Textures/candlelight/02.png");
    else if(candleTime.getElapsedTime().asMilliseconds()/250 == 3)
        candleTex.loadFromFile("Textures/candlelight/03.png");
    else if(candleTime.getElapsedTime().asMilliseconds()/250 == 4)
        candleTex.loadFromFile("Textures/candlelight/04.png");
    else if(candleTime.getElapsedTime().asMilliseconds()/250 == 5)
        candleTex.loadFromFile("Textures/candlelight/05.png");
    else if(candleTime.getElapsedTime().asMilliseconds()/250 == 6)
        candleTex.loadFromFile("Textures/candlelight/06.png");
    else if(candleTime.getElapsedTime().asMilliseconds()/250 == 7)
        candleTex.loadFromFile("Textures/candlelight/07.png");
    else if(candleTime.getElapsedTime().asMilliseconds()/250 == 8)
        candleTex.loadFromFile("Textures/candlelight/08.png");
    else if(candleTime.getElapsedTime().asMilliseconds()/250 == 9)
        candleTex.loadFromFile("Textures/candlelight/09.png");
    else if(candleTime.getElapsedTime().asMilliseconds()/250 == 10)
        candleTex.loadFromFile("Textures/candlelight/10.png");
    else if(candleTime.getElapsedTime().asMilliseconds()/250 == 11)
        candleTex.loadFromFile("Textures/candlelight/11.png");
    else if(candleTime.getElapsedTime().asMilliseconds()/250 == 12)
        candleTex.loadFromFile("Textures/candlelight/12.png");
    else if(candleTime.getElapsedTime().asMilliseconds()/250 == 13)
        candleTex.loadFromFile("Textures/candlelight/13.png");
    else if(candleTime.getElapsedTime().asMilliseconds()/250 == 14)
        candleTex.loadFromFile("Textures/candlelight/14.png");
    
    candle1.setTexture(candleTex);
    candle1.setScale(0.1f, 0.1f);
    candle1.setPosition((window->getSize().x / 4) - (candle1.getGlobalBounds().width / 2), (window->getSize().y / 2) - (candle1.getGlobalBounds().height / 2));

    candle2.setTexture(candleTex);
    candle2.setScale(0.1f, 0.1f);
    candle2.setPosition(((window->getSize().x / 4) * 3) - (candle2.getGlobalBounds().width / 2), (window->getSize().y / 2) - (candle2.getGlobalBounds().height / 2));

    // bg++;
}

// void game::setBackground() {
//     if(bg >= 2400)
//         bg = 0;

//     if(bg == 0)
//         mainGameBGTex.loadFromFile("Textures/background2/00.png");
//     else if(bg == 150)
//         mainGameBGTex.loadFromFile("Textures/background2/01.png");
//     else if(bg == 300)
//         mainGameBGTex.loadFromFile("Textures/background2/02.png");
//     else if(bg == 450)
//         mainGameBGTex.loadFromFile("Textures/background2/03.png");
//     else if(bg == 600)
//         mainGameBGTex.loadFromFile("Textures/background2/04.png");
//     else if(bg == 750)
//         mainGameBGTex.loadFromFile("Textures/background2/05.png");
//     else if(bg == 900)
//         mainGameBGTex.loadFromFile("Textures/background2/06.png");
//     else if(bg == 1050)
//         mainGameBGTex.loadFromFile("Textures/background2/07.png");
//     else if(bg == 1200)
//         mainGameBGTex.loadFromFile("Textures/background2/08.png");
//     else if(bg == 1350)
//         mainGameBGTex.loadFromFile("Textures/background2/09.png");
//     else if(bg == 1500)
//         mainGameBGTex.loadFromFile("Textures/background2/10.png");
//     else if(bg == 1650)
//         mainGameBGTex.loadFromFile("Textures/background2/11.png");
//     else if(bg == 1800)
//         mainGameBGTex.loadFromFile("Textures/background2/12.png");
//     else if(bg == 1950)
//         mainGameBGTex.loadFromFile("Textures/background2/13.png");
//     else if(bg == 2100)
//         mainGameBGTex.loadFromFile("Textures/background2/14.png");
//     else if(bg == 2250)
//         mainGameBGTex.loadFromFile("Textures/background2/15.png");
    
//     mainGameBG.setTexture(mainGameBGTex);
//     mainGameBG.setScale((window->getSize().x / mainGameBGTex.getSize().x) + 0.3f, (window->getSize().y / mainGameBGTex.getSize().y) + 0.8f);
//     mainGameBG.setPosition(0, 0);
//     bg++;
// }

void game::intTex(){
    std::vector<std::vector<sf::Texture>> cardTextures(4, std::vector<sf::Texture>(13));
    Vector2f windowSize = Vector2f(window->getSize());
    // loading texture
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
    if(!font.loadFromFile("Fonts/alagard.ttf")){
        cout << "ERROR::font" << endl;
    }
    if(!mainGameBGTopTex.loadFromFile("Textures/mainGameBG_top.png")) {
        cout << "ERROR::mainGameBGTex Top" << endl;
    }
    if(!mainGameBGBottomTex.loadFromFile("Textures/mainGameBG_bottom.png")) {
        cout << "ERROR::mainGameBGTex Bottom" << endl;
    }

    //Characters
    if(!jackMenuTex.loadFromFile("Textures/characters/jackMenu.png")){
        cout << "ERROR::Char: Jack Menu" << endl;
    }
    if(!jakeMenuTex.loadFromFile("Textures/characters/jakeMenu.png")){
        cout << "ERROR::Char: Jake Menu" << endl;
    }
    if(!jacksonMenuTex.loadFromFile("Textures/characters/jacksonMenu.png")){
        cout << "ERROR::Char: Jackson Menu" << endl;
    }
    if(!jadeMenuTex.loadFromFile("Textures/characters/jadeMenu.png")){
        cout << "ERROR::Char: Jade Menu" << endl;
    }
    if(!jackTex.loadFromFile("Textures/characters/jack.png")){
        cout << "ERROR::Char: Jack" << endl;
    }
    if(!jakeTex.loadFromFile("Textures/characters/jake.png")){
        cout << "ERROR::Char: Jake" << endl;
    }
    if(!jacksonTex.loadFromFile("Textures/characters/jackson.png")){
        cout << "ERROR::Char: Jackson" << endl;
    }
    if(!jadeTex.loadFromFile("Textures/characters/jade.png")){
        cout << "ERROR::Char: Jade" << endl;
    }

    //Cards
    if(!C0.loadFromFile("Textures/deck/CardTexture00.png")){
        cout << "ERROR::C0" << endl;
    }
    if(!C1.loadFromFile("Textures/deck/CardTexture01.png")){
        cout << "ERROR::C0" << endl;
    }
    if(!C2.loadFromFile("Textures/deck/CardTexture02.png")){
        cout << "ERROR::C0" << endl;
    }
    if(!C3.loadFromFile("Textures/deck/CardTexture03.png")){
        cout << "ERROR::C0" << endl;
    }
    if(!C4.loadFromFile("Textures/deck/CardTexture04.png")){
        cout << "ERROR::C0" << endl;
    }
    if(!C5.loadFromFile("Textures/deck/CardTexture05.png")){
        cout << "ERROR::C0" << endl;
    }
    if(!C6.loadFromFile("Textures/deck/CardTexture06.png")){
        cout << "ERROR::C0" << endl;
    }
    if(!C7.loadFromFile("Textures/deck/CardTexture07.png")){
        cout << "ERROR::C0" << endl;
    }
    if(!C8.loadFromFile("Textures/deck/CardTexture08.png")){
        cout << "ERROR::C0" << endl;
    }
    if(!C9.loadFromFile("Textures/deck/CardTexture09.png")){
        cout << "ERROR::C0" << endl;
    }
    if(!C10.loadFromFile("Textures/deck/CardTexture010.png")){
        cout << "ERROR::C0" << endl;
    }
    if(!C11.loadFromFile("Textures/deck/CardTexture011.png")){
        cout << "ERROR::C0" << endl;
    }
    if(!C12.loadFromFile("Textures/deck/CardTexture012.png")){
        cout << "ERROR::C0" << endl;
    }
    if(!D0.loadFromFile("Textures/deck/CardTexture10.png")){
        cout << "ERROR::C0" << endl;
    }
    if(!D1.loadFromFile("Textures/deck/CardTexture11.png")){
        cout << "ERROR::C0" << endl;
    }
    if(!D2.loadFromFile("Textures/deck/CardTexture12.png")){
        cout << "ERROR::C0" << endl;
    }
    if(!D3.loadFromFile("Textures/deck/CardTexture13.png")){
        cout << "ERROR::C0" << endl;
    }
    if(!D4.loadFromFile("Textures/deck/CardTexture14.png")){
        cout << "ERROR::C0" << endl;
    }
    if(!D5.loadFromFile("Textures/deck/CardTexture15.png")){
        cout << "ERROR::C0" << endl;
    }
    if(!D6.loadFromFile("Textures/deck/CardTexture16.png")){
        cout << "ERROR::C0" << endl;
    }
    if(!D7.loadFromFile("Textures/deck/CardTexture17.png")){
        cout << "ERROR::C0" << endl;
    }
    if(!D8.loadFromFile("Textures/deck/CardTexture18.png")){
        cout << "ERROR::C0" << endl;
    }
    if(!D9.loadFromFile("Textures/deck/CardTexture19.png")){
        cout << "ERROR::C0" << endl;
    }
    if(!D10.loadFromFile("Textures/deck/CardTexture110.png")){
        cout << "ERROR::C0" << endl;
    }
    if(!D11.loadFromFile("Textures/deck/CardTexture111.png")){
        cout << "ERROR::C0" << endl;
    }
    if(!D12.loadFromFile("Textures/deck/CardTexture112.png")){
        cout << "ERROR::C0" << endl;
    }
    if(!H0.loadFromFile("Textures/deck/CardTexture20.png")){
        cout << "ERROR::C0" << endl;
    }
    if(!H1.loadFromFile("Textures/deck/CardTexture21.png")){
        cout << "ERROR::C0" << endl;
    }
    if(!H2.loadFromFile("Textures/deck/CardTexture22.png")){
        cout << "ERROR::C0" << endl;
    }
    if(!H3.loadFromFile("Textures/deck/CardTexture23.png")){
        cout << "ERROR::C0" << endl;
    }
    if(!H4.loadFromFile("Textures/deck/CardTexture24.png")){
        cout << "ERROR::C0" << endl;
    }
    if(!H5.loadFromFile("Textures/deck/CardTexture25.png")){
        cout << "ERROR::C0" << endl;
    }
    if(!H6.loadFromFile("Textures/deck/CardTexture26.png")){
        cout << "ERROR::C0" << endl;
    }
    if(!H7.loadFromFile("Textures/deck/CardTexture27.png")){
        cout << "ERROR::C0" << endl;
    }
    if(!H8.loadFromFile("Textures/deck/CardTexture28.png")){
        cout << "ERROR::C0" << endl;
    }
    if(!H9.loadFromFile("Textures/deck/CardTexture29.png")){
        cout << "ERROR::C0" << endl;
    }
    if(!H10.loadFromFile("Textures/deck/CardTexture210.png")){
        cout << "ERROR::C0" << endl;
    }
    if(!H11.loadFromFile("Textures/deck/CardTexture211.png")){
        cout << "ERROR::C0" << endl;
    }
    if(!H12.loadFromFile("Textures/deck/CardTexture212.png")){
        cout << "ERROR::C0" << endl;
    }
    if(!S0.loadFromFile("Textures/deck/CardTexture30.png")){
        cout << "ERROR::C0" << endl;
    }
    if(!S1.loadFromFile("Textures/deck/CardTexture31.png")){
        cout << "ERROR::C0" << endl;
    }
    if(!S2.loadFromFile("Textures/deck/CardTexture32.png")){
        cout << "ERROR::C0" << endl;
    }
    if(!S3.loadFromFile("Textures/deck/CardTexture33.png")){
        cout << "ERROR::C0" << endl;
    }
    if(!S4.loadFromFile("Textures/deck/CardTexture34.png")){
        cout << "ERROR::C0" << endl;
    }
    if(!S5.loadFromFile("Textures/deck/CardTexture35.png")){
        cout << "ERROR::C0" << endl;
    }
    if(!S6.loadFromFile("Textures/deck/CardTexture36.png")){
        cout << "ERROR::C0" << endl;
    }
    if(!S7.loadFromFile("Textures/deck/CardTexture37.png")){
        cout << "ERROR::C0" << endl;
    }
    if(!S8.loadFromFile("Textures/deck/CardTexture38.png")){
        cout << "ERROR::C0" << endl;
    }
    if(!S9.loadFromFile("Textures/deck/CardTexture39.png")){
        cout << "ERROR::C0" << endl;
    }
    if(!S10.loadFromFile("Textures/deck/CardTexture310.png")){
        cout << "ERROR::C0" << endl;
    }
    if(!S11.loadFromFile("Textures/deck/CardTexture311.png")){
        cout << "ERROR::C0" << endl;
    }
    if(!S12.loadFromFile("Textures/deck/CardTexture312.png")){
        cout << "ERROR::C0" << endl;
    }
    if(!Tutorialtexture.loadFromFile("Textures/tutorial.png")){
        cout << "ERROR::Tutorial" << endl;
    }

    if(!lifeTex.loadFromFile("Textures/life.png")){
        cout << "ERROR::Life Icon" << endl;
    }
    if(!deadTex.loadFromFile("Textures/dead.png")){
        cout << "ERROR::Dead Icon" << endl;
    }

    // setting texture
    mainMenuBG.setTexture(MMBGtexture);
    mainGameBGTop.setTexture(mainGameBGTopTex);
    mainGameBGBottom.setTexture(mainGameBGBottomTex);
    Death.setTexture(Deathtexture);
    window->setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    Title.setTexture(Titletexture);
    playButton.setButton("Play", Vector2f(175.0, 70.0), 50, &Buttontexture, Color::Black, &font);
    nextButton.setButton("Next", Vector2f(175.0, 70.0), 50, &Buttontexture, Color::Black, &font);
    startButton.setButton("Continue", Vector2f(200.0, 70.0), 35, &Buttontexture, Color::Black, &font);
    twoP.setButton(" ", Vector2f(static_cast<float>(138), static_cast<float>(200)), 50, &C2, Color::Transparent, &font);
    threeP.setButton(" ", Vector2f(static_cast<float>(138), static_cast<float>(200)), 50, &D3, Color::Transparent, &font);
    fourP.setButton(" ", Vector2f(static_cast<float>(138), static_cast<float>(200)), 50, &S4, Color::Transparent, &font);
    hitButton.setButton("Hit", Vector2f(175.0, 70.0), 50, &Buttontexture, Color::Black, &font);
    standButton.setButton("Stand", Vector2f(175.0, 70.0), 50, &Buttontexture, Color::Black, &font);
    pauseButton.setButton("||", Vector2f(70.0, 70.0), 40, &Buttontexture, Color::Black, &font);
    life.setTexture(lifeTex);
    dead.setTexture(deadTex);

    numHeader.setFont(font);
    numHeader.setString("CHOOSE THE NUMBER OF PLAYERS");
    numHeader.setFillColor(Color::White);
    numHeader.setCharacterSize(50);
    numHeader.setPosition(((float)window->getSize().x - numHeader.getGlobalBounds().width)/2, 100.f);

    jack.setButton("Jack Black", Vector2f(200, 300), 25, &jackMenuTex, Color::White, &font);
    jake.setButton("Jake Blake", Vector2f(200, 300), 25, &jakeMenuTex, Color::White, &font);
    jackson.setButton("Jackson Blackson", Vector2f(200, 300), 25, &jacksonMenuTex, Color::White, &font);
    jade.setButton("Jade Blade", Vector2f(200, 300), 25, &jadeMenuTex, Color::White, &font);

    charHeader.setFont(font);
    charHeader.setString("SELECT YOUR CHARACTER");
    charHeader.setFillColor(Color::White);
    charHeader.setCharacterSize(50);
    charHeader.setPosition(((float)window->getSize().x - charHeader.getGlobalBounds().width)/2, 75.f);

    num.setFont(font);
    num.setString("PLAYER 1");
    num.setFillColor(Color::White);
    num.setCharacterSize(30);
    num.setPosition(((float)window->getSize().x - num.getGlobalBounds().width)/2, 140.f);

    tempSprite.setTexture(C0);
    C0Sprite.setTexture(C0);
    C1Sprite.setTexture(C1);
    C2Sprite.setTexture(C2);
    C3Sprite.setTexture(C3);
    C4Sprite.setTexture(C4);
    C5Sprite.setTexture(C5);
    C6Sprite.setTexture(C6);
    C7Sprite.setTexture(C7);
    C8Sprite.setTexture(C8);
    C9Sprite.setTexture(C9);
    C10Sprite.setTexture(C10);
    C11Sprite.setTexture(C11);
    C12Sprite.setTexture(C12);
    D0Sprite.setTexture(D0);
    D1Sprite.setTexture(D1);
    D2Sprite.setTexture(D2);
    D3Sprite.setTexture(D3);
    D4Sprite.setTexture(D4);
    D5Sprite.setTexture(D5);
    D6Sprite.setTexture(D6);
    D7Sprite.setTexture(D7);
    D8Sprite.setTexture(D8);
    D9Sprite.setTexture(D9);
    D10Sprite.setTexture(D10);
    D11Sprite.setTexture(D11);
    D12Sprite.setTexture(D12);
    H0Sprite.setTexture(H0);
    H1Sprite.setTexture(H1);
    H2Sprite.setTexture(H2);
    H3Sprite.setTexture(H3);
    H4Sprite.setTexture(H4);
    H5Sprite.setTexture(H5);
    H6Sprite.setTexture(H6);
    H7Sprite.setTexture(H7);
    H8Sprite.setTexture(H8);
    H9Sprite.setTexture(H9);
    H10Sprite.setTexture(H10);
    H11Sprite.setTexture(H11);
    H12Sprite.setTexture(H12);
    S0Sprite.setTexture(S0);
    S1Sprite.setTexture(S1);
    S2Sprite.setTexture(S2);
    S3Sprite.setTexture(S3);
    S4Sprite.setTexture(S4);
    S5Sprite.setTexture(S5);
    S6Sprite.setTexture(S6);
    S7Sprite.setTexture(S7);
    S8Sprite.setTexture(S8);
    S9Sprite.setTexture(S9);
    S10Sprite.setTexture(S10);
    S11Sprite.setTexture(S11);
    S12Sprite.setTexture(S12);

    jackSprite.setTexture(jackTex);
    jakeSprite.setTexture(jakeTex);
    jacksonSprite.setTexture(jacksonTex);
    jadeSprite.setTexture(jadeTex);


    tutorialButton.setButton("Learn", Vector2f(175.0, 70.0), 50, &Buttontexture, Color::Black, &font);
    backButton.setButton("Back", Vector2f(175.0, 70.0), 50, &Buttontexture, Color::Black, &font);
    Tutorial.setTexture(Tutorialtexture);

    overallValue.setFont(font);
    overallValue.setString("OVERALL VALUE: -");
    overallValue.setFillColor(Color::White);
    overallValue.setCharacterSize(30);
    float overallPosY = overallValue.getGlobalBounds().height + dead.getGlobalBounds().height + C0Sprite.getGlobalBounds().height;
    
    overallValue.setPosition(jackSprite.getGlobalBounds().width + 130.f, window->getSize().y - (overallPosY + 80.f));

    // scaling texture
    mainMenuBG.setScale(windowSize.x / MMBGtexture.getSize().x, windowSize.y / MMBGtexture.getSize().y);
    mainGameBGTop.setScale(0.2f, 0.2f);
    mainGameBGBottom.setScale(0.215f, 0.215f);
    Death.setScale(2.0, 2.0);
    Title.setScale(0.5, 0.5);
    Tutorial.setScale(windowSize.x / Tutorialtexture.getSize().x, windowSize.y / Tutorialtexture.getSize().y);
    dead.setScale(0.3f, 0.3f);
    life.setScale(0.3f, 0.3f);

    // position
    mainMenuBG.setPosition(0, 0);
    mainGameBGTop.setPosition(0, 0);
    mainGameBGBottom.setPosition(0, window->getSize().y - mainGameBGBottom.getGlobalBounds().height);
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

    Vector2f startbtnSize = startButton.btn.getLocalBounds().getSize();
    Vector2f positionstartbtn((windowSize.x - startbtnSize.x) / 2, (windowSize.y - startbtnSize.y) / 2 + 250.5f);
    startButton.setPosition(positionstartbtn);

    float SBtextPosX = positionstartbtn.x + (startbtnSize.x / 2.f) - (startButton.text.getLocalBounds().width / 2.f);
    float SBtextPosY = positionstartbtn.y + (startbtnSize.y / 2.f) - (startButton.text.getLocalBounds().height / 2.f + 17.0f);
    startButton.text.setPosition(SBtextPosX, SBtextPosY);

    Vector2f nextbtnSize = nextButton.btn.getLocalBounds().getSize();
    Vector2f positionnextbtn((windowSize.x - nextbtnSize.x) / 2, (windowSize.y - nextbtnSize.y) / 2 + 250.5f);
    nextButton.setPosition(positionnextbtn);

    float NBtextPosX = positionstartbtn.x + (startbtnSize.x / 2.f) - (nextButton.text.getLocalBounds().width / 2.f);
    nextButton.text.setPosition(NBtextPosX, SBtextPosY);

    /////////   

    Vector2f twoPbtnSize = twoP.btn.getLocalBounds().getSize();
    Vector2f positiontwoPbtn((windowSize.x - twoPbtnSize.x) / 2 - 270.5f, (windowSize.y - twoPbtnSize.y) / 2);
    twoP.setPosition(positiontwoPbtn);

    float TwPtextPosX = (positiontwoPbtn.x + (twoPbtnSize.x / 2.f) - (twoP.text.getLocalBounds().width / 2.f) - 230.5f);
    float TwPtextPosY = positiontwoPbtn.y + (twoPbtnSize.y / 2.f) - (twoP.text.getLocalBounds().height / 2.f - 43.5f);
    twoP.text.setPosition(TwPtextPosX, TwPtextPosY);
    
    Vector2f threePbtnSize = threeP.btn.getLocalBounds().getSize();
    Vector2f positionthreePbtn((windowSize.x - threePbtnSize.x) / 2.f, (windowSize.y - threePbtnSize.y) / 2);
    threeP.setPosition(positionthreePbtn);
    
    float ThPtextPosX = positionthreePbtn.x + (threePbtnSize.x / 2.f) - (threeP.text.getLocalBounds().width / 2.f);
    float ThPtextPosY = positionthreePbtn.y + (threePbtnSize.y / 2.f) - (threeP.text.getLocalBounds().height / 2.f + 13.5f);
    threeP.text.setPosition(ThPtextPosX, ThPtextPosY);
    
    Vector2f fourPbtnSize = fourP.btn.getLocalBounds().getSize();
    Vector2f positionfourPbtn((windowSize.x - fourPbtnSize.x) / 2 + 270.5f, (windowSize.y - fourPbtnSize.y) / 2);
    fourP.setPosition(positionfourPbtn);
    
    float FPtextPosX = positionfourPbtn.x + (fourPbtnSize.x / 2.f) - (fourP.text.getLocalBounds().width / 2.f);
    float FPtextPosY = positionfourPbtn.y + (fourPbtnSize.y / 2.f) - (fourP.text.getLocalBounds().height / 2.f + 13.5f);
    fourP.text.setPosition(FPtextPosX, FPtextPosY);

    ////
    Vector2f jackBtnSize = jack.btn.getLocalBounds().getSize();
    Vector2f jackBtnPos(165, (windowSize.y - jackBtnSize.y) / 2 - 10);
    float jackTextPosX = jackBtnPos.x + (jackBtnSize.x / 2.f) - (jack.text.getLocalBounds().width / 2.f);
    float jackTextPosY = jackBtnPos.y + jackBtnSize.y + 10.f;
    jack.setPosition(jackBtnPos);
    jack.text.setPosition(jackTextPosX, jackTextPosY);

    Vector2f jakeBtnSize = jake.btn.getLocalBounds().getSize();
    Vector2f jakeBtnPos(415, (windowSize.y - jakeBtnSize.y) / 2 - 10);
    float jakeTextPosX = jakeBtnPos.x + (jakeBtnSize.x / 2.f) - (jake.text.getLocalBounds().width / 2.f);
    float jakeTextPosY = jakeBtnPos.y + jakeBtnSize.y + 10.f;
    jake.setPosition(jakeBtnPos);
    jake.text.setPosition(jakeTextPosX, jakeTextPosY);

    Vector2f jacksonBtnSize = jackson.btn.getLocalBounds().getSize();
    Vector2f jacksonBtnPos(665, (windowSize.y - jacksonBtnSize.y) / 2 - 10);
    float jacksonTextPosX = jacksonBtnPos.x + (jacksonBtnSize.x / 2.f) - (jackson.text.getLocalBounds().width / 2.f);
    float jacksonTextPosY = jacksonBtnPos.y + jacksonBtnSize.y + 10.f;
    jackson.setPosition(jacksonBtnPos);
    jackson.text.setPosition(jacksonTextPosX, jacksonTextPosY);

    Vector2f jadeBtnSize = jade.btn.getLocalBounds().getSize();
    Vector2f jadeBtnPos(915, (windowSize.y - jadeBtnSize.y) / 2 - 10);
    float jadeTextPosX = jadeBtnPos.x + (jadeBtnSize.x / 2.f) - (jade.text.getLocalBounds().width / 2.f);
    float jadeTextPosY = jadeBtnPos.y + jadeBtnSize.y + 10.f;
    jade.setPosition(jadeBtnPos);
    jade.text.setPosition(jadeTextPosX, jadeTextPosY);  

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
    
    // Vector2f tryAgainbtnSize = tryAgainButton.btn.getLocalBounds().getSize();
    // Vector2f positiontryAgainbtn((windowSize.x - tryAgainbtnSize.x) / 2, (windowSize.y - tryAgainbtnSize.y) / 2 + 180.5f);
    // tryAgainButton.setPosition(positiontryAgainbtn);
    
    // float TrBtextPosX = positiontryAgainbtn.x + (tryAgainbtnSize.x / 2.f) - (tryAgainButton.text.getLocalBounds().width / 2.f);
    // float TrBtextPosY = positiontryAgainbtn.y + (tryAgainbtnSize.y / 2.f) - (tryAgainButton.text.getLocalBounds().height / 2.f + 13.5f);
    // tryAgainButton.text.setPosition(TrBtextPosX, TrBtextPosY);
    
    // Vector2f quitbtnSize = quitButton.btn.getLocalBounds().getSize();
    // Vector2f positionquitbtn((windowSize.x - quitbtnSize.x) / 2, (windowSize.y - quitbtnSize.y) / 2 + 180.5f);
    // quitButton.setPosition(positionquitbtn);
    
    // float QBtextPosX = positionquitbtn.x + (quitbtnSize.x / 2.f) - (quitButton.text.getLocalBounds().width / 2.f);
    // float QBtextPosY = positionquitbtn.y + (quitbtnSize.y / 2.f) - (quitButton.text.getLocalBounds().height / 2.f + 13.5f);
    // quitButton.text.setPosition(QBtextPosX, QBtextPosY);
        
    Vector2f hitbtnSize = hitButton.btn.getLocalBounds().getSize();
    Vector2f positionhitbtn((windowSize.x / 4) - (hitbtnSize.x / 2), (windowSize.y - hitbtnSize.y) / 2 - 100.f);
    hitButton.setPosition(positionhitbtn);
    
    float HBtextPosX = positionhitbtn.x + (hitbtnSize.x / 2.f) - (hitButton.text.getLocalBounds().width / 2.f);
    float HBtextPosY = positionhitbtn.y + (hitbtnSize.y / 2.f) - (hitButton.text.getLocalBounds().height / 2.f + 21.5f);
    hitButton.text.setPosition(HBtextPosX, HBtextPosY);
    
    Vector2f standbtnSize = standButton.btn.getLocalBounds().getSize();
    Vector2f positionstandbtn(((windowSize.x / 4) * 3) - (standbtnSize.x / 2), (windowSize.y - standbtnSize.y) / 2 - 100.f);
    standButton.setPosition(positionstandbtn);
    
    float STBtextPosX = positionstandbtn.x + (standbtnSize.x / 2.f) - (standButton.text.getLocalBounds().width / 2.f);
    float STBtextPosY = positionstandbtn.y + (standbtnSize.y / 2.f) - (standButton.text.getLocalBounds().height / 2.f + 20.5f);
    standButton.text.setPosition(STBtextPosX, STBtextPosY);

    Vector2f pausebtnSize = pauseButton.btn.getLocalBounds().getSize();
    Vector2f positionpausebtn(windowSize.x - 100.f, 25.f);
    pauseButton.setPosition(positionpausebtn);
    
    float pausetextPosX = positionpausebtn.x + (pausebtnSize.x / 2.f) - (pauseButton.text.getLocalBounds().width / 1.5f);
    float pausetextPosY = positionpausebtn.y + (pausebtnSize.y / 2.f) - (pauseButton.text.getLocalBounds().height / 2.f + 15.f);
    pauseButton.text.setPosition(pausetextPosX, pausetextPosY);
}