//#include "game.hpp"
//
//void dashboard::setDashboard(Sprite *charSprite, Color bgColor, Vector2f bgSize) {
//    charContainer = *charSprite;
//    charContainer.setScale(1.2f, 1.2f);
//
//    background.setFillColor(bgColor);
//    background.setSize(bgSize);
//}
//
//void dashboard::setBackgroundPosition(Vector2f pos) {
//    background.setPosition(pos);
//}
//
//void dashboard::setPosition(Vector2f pos) {
//    charContainer.setPosition(pos);
//}
//
//void dashboard::drawDashboard(RenderWindow &window) {
//    window.draw(background);
//    window.draw(charContainer);
//}
//
//void button::setButton(string t, Vector2f size, int charSize, Texture *texture, Color textColor, Font *font){
//    text.setString(t);
//    text.setFillColor(textColor);
//    text.setCharacterSize(charSize);
//    text.setFont(*font);
//
//    btn.setSize(size);
//    btn.setTexture(texture);
//}
//
//void button::setFont(Font &font) {
//    text.setFont(font);
//}
//
//void button::setTextColor(Color color) {
//    text.setFillColor(color);
//}
//
//void button::setButtonTexture(Texture texture){
//    btn.setTexture(&texture);
//}
//
//void button::setPosition(Vector2f pos){
//    btn.setPosition(pos);
//
//    float xPos = (pos.x + btn.getLocalBounds().width / 4) - (text.getLocalBounds().width / 2), 
//            yPos = (pos.y + btn.getLocalBounds().height / 2) - (text.getLocalBounds().height / 2);
//
//    text.setPosition({xPos, yPos});
//}
//
//void button::drawButton(RenderWindow &window){
//    window.draw(btn);
//    window.draw(text);
//}
//
//bool button::isMouseOver(RenderWindow &window){
//    float mouseX = Mouse::getPosition(window).x,
//        mouseY = Mouse::getPosition(window).y,
//
//        btnPosX = btn.getPosition().x,
//        btnPosY = btn.getPosition().y,
//
//        btnxPosWidth = btn.getPosition().x + btn.getGlobalBounds().width,
//        btnyPosHeight = btn.getPosition().y + btn.getGlobalBounds().height;
//
//    if(mouseX < btnxPosWidth && mouseX > btnPosX && mouseY < btnyPosHeight && mouseY > btnPosY) {
//        return true;
//        Cursor cursor;
//        cursor.loadFromSystem(Cursor::Hand);
//        window.setMouseCursor(cursor);
//    }
//    
//    return false;
//}