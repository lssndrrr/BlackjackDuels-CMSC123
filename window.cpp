#include "game.hpp"

void initWindow(RenderWindow*& window, View& view, VideoMode& video) {
    video.height = 720;
    video.width = 1280;
    window = new RenderWindow(video, "Blackjack Duels!", Style::Default);
    view = View(FloatRect(0.f, 0.f, 1280.f, 720.f));
    window->setVerticalSyncEnabled(false);
}