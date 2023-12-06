#pragma once
#ifndef TEXTURES_HPP
#define TEXTURES_HPP

#include "game.hpp"

class texturizer {
public:
	static SDL_Texture *load_texture(const char *file_name);
	static void draw(SDL_Texture *texture, SDL_Rect src, SDL_Rect dest);
};

#endif
