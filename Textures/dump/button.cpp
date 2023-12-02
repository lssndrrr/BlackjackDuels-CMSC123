#include "game.hpp"
#include "header.hpp"

using namespace sf;

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

            float xPos = (pos.x + btn.getLocalBounds().width / 4) - (text.getGlobalBounds().width / 2), 
                  yPos = (pos.y + btn.getGlobalBounds().height / 2) - (text.getGlobalBounds().height / 2);

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