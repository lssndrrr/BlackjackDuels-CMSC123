#pragma once
#ifndef GAME_OBJ_HPP
#define GAME_OBJ_HPP

/*
This header file is for the creation of a game object, like buttons, cards, and other stuff that may be useful.
*/

#include "game.hpp"

class game_object {
private:
	int x_position;
	int y_position;

	SDL_Texture *obj_texture;
	SDL_Rect src_rect, dest_rect;

public:
	game_object() {}
	game_object(const char *texture_sheet, int x, int y);
	~game_object() {}

	void update();
	void render();
};

#endif // !GAME_OBJ_HPP
