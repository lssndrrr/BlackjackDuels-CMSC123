#pragma once
#ifndef GAME_OBJ_HPP
#define GAME_OBJ_HPP

#include "game.hpp"

class game_object {
private:
	int x_position;
	int y_position;

	SDL_Texture *obj_texture;
	SDL_Rect src_rect, dest_rect;

public:
	game_object(const char *texture_sheet, int x, int y);
	~game_object();

	void update();
	void render();
};

#endif // !GAME_OBJ_HPP
