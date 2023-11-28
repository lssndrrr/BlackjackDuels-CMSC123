#include "game_obj.hpp"
#include "textures.hpp"

game_object::game_object(const char *texture_sheet, int x, int y) {

	// texture
	this->obj_texture = texturizer::load_texture(texture_sheet);

	// initial positions
	this->x_position = x;
	this->y_position = y;
}

void game_object::update() {
	this->x_position++;

	src_rect.h = 216;
	src_rect.w = 384;
	src_rect.x = 0;
	src_rect.y = 0;

	dest_rect.x = this->x_position;
	dest_rect.y = this->y_position;
	dest_rect.h = src_rect.h * 2;
	dest_rect.w = src_rect.w * 2;
}

void game_object::render() {

	// draws the texture
	SDL_RenderCopy(game::renderer, this->obj_texture, &this->src_rect, &this->dest_rect);

}