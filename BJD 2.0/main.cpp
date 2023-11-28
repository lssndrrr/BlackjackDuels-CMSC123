//#include "game.hpp"
//#include "button.cpp"
//// #include "characters.cpp"
//#include "deck.cpp"
//#include "game.cpp"
//#include "mainGame.cpp"
//#include "players.cpp"
//#include "textures.cpp"
//#include "updates.cpp"
//#include "header.hpp"
#define SDL_MAIN_HANDLED
#include "game.hpp"

game *bjd = NULL;

int main(int argc, char *argv[]) {

    // target frame rate
    const int fps = 60;
    const int frame_delay = 1000 / fps;

    // clock
    Uint32 frame_start;
    int frame_time;

    // create an instance of game
    bjd = new game();

    //initialize
    bjd->init("BJD", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, false);

    while(bjd->running()) {

        frame_start = SDL_GetTicks();

        bjd->handle_events();
        bjd->update();
        bjd->render();

        frame_time = SDL_GetTicks() - frame_start;

        if(frame_delay > frame_time) {
            SDL_Delay(frame_delay - frame_time);
        }
    }

    bjd->clean(); 
    return 0;
}