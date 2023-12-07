#include "menu_state.hpp"
#include "game_obj.hpp"
#include <SDL.h>
#include <iostream>

game_object *main_menu_background, *main_menu_death;

void menu_state::init() {
	// init stuff, objects?
	// textures?
	main_menu_background = new game_object("BJD 2.0/Textures/mainmenubg.png", 0, 0);

	if(main_menu_background)
		cout << "MAIN_MENU_BG initialized ... " << endl;

	main_menu_death = new game_object("BJD 2.0/Textures/death.png", 0, 0);
	
	if(main_menu_death)
		cout << "MAIN_MENU_DEATH initialized ... " << endl;
}

void menu_state::clean() {
}

void menu_state::handle_input(game &game) {
	SDL_Event event;
	while(SDL_PollEvent(&event)) {
		switch(event.type) {
		case SDL_QUIT:
			// this->is_running = false;
			break;
		case SDL_KEYDOWN:
			if(event.key.keysym.sym == SDLK_RETURN) {
				// game.set_state(std::make_unique<>());
			}
			break;
		}
	}
}

void menu_state::update(game& game) {
	main_menu_background->update();
	main_menu_death->update();
}

void menu_state::render(game& game) {
	SDL_RenderClear(game.renderer);

	main_menu_background->render();
	main_menu_death->render();

	SDL_RenderPresent(game.renderer);
}