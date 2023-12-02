#include <iostream>
#include <random>
#include <vector>
#include <algorithm>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "button.cpp"

//choosing number of players
using namespace sf;

int main() {
    RenderWindow window(VideoMode(1920, 1080), "Blackjack Duels!", Style::Default);

    Font font;
    if(!font.loadFromFile("Fonts/joystix-monospace.otf"))
        throw("Font did not load :(");
    
    Text header;
    header.setFont(font);
    header.setCharacterSize(75);
    header.setFillColor(Color::White);
    header.setString("CHOOSE NUMBER OF PLAYERS");
    header.setPosition(((float)window.getSize().x - header.getGlobalBounds().width)/2, 100.f);

    Text num;
    num.setFont(font);
    num.setCharacterSize(50);
    num.setPosition(50.f, (float)window.getSize().y - 100.f);
    num.setFillColor(Color::White);
    num.setString("- players");

    Button btn1("2 Players",  {400, 500}, 30, Color{55, 55, 55, 150}, Color::White);
    btn1.setPosition({270, 300});
    btn1.setFont(font);

    Button btn2("3 Players",  {400, 500}, 30, Color{55, 55, 55, 150}, Color::White);
    btn2.setPosition({760, 300});
    btn2.setFont(font);

    Button btn3("4 Players",  {400, 500}, 30, Color{55, 55, 55, 150}, Color::White);
    btn3.setPosition({1250, 300});
    btn3.setFont(font);

    int numPlayers;

    while(window.isOpen()) {
        Event event;

        while(window.pollEvent(event)) {
            if(event.type == Event::Closed)
                window.close();
            if(event.type == Event::KeyPressed && event.key.code == Keyboard::Escape)
                window.close();
            if(Event::MouseMoved){
                if(btn1.isMouseOver(window)) {
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

                if(btn2.isMouseOver(window)) {
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

                if(btn3.isMouseOver(window)) {
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
            }
        }

        if(numPlayers == 2) {
            btn1.setButtonColor(Color::White);
            btn1.setTextColor(Color::Black);
            num.setString("2 players");
        }
        else if(numPlayers == 3) {
            btn2.setButtonColor(Color::White);
            btn2.setTextColor(Color::Black);
            num.setString("3 players");
        }
        else if(numPlayers == 4) {
            btn3.setButtonColor(Color::White);
            btn3.setTextColor(Color::Black);
            num.setString("4 players");
        }

        window.clear();

        window.draw(header);

        btn1.drawTo(window);
        btn2.drawTo(window);
        btn3.drawTo(window);

        window.draw(num);

        window.display();
    }

    return 0;
}