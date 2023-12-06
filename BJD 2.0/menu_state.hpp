#pragma once
#ifndef MENU_STATE_HPP
#define MENU_STATE_HPP

#include "game_state.hpp"

// concrete state: menu
class menu_state : public game_state {
public:
	void init() override;
	void clean() override;

	void handle_input(game &game) override;
	void update(game &game) override;
	void render(game &game) override;
};

#endif // !MENU_STATE_HPP
