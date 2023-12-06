#pragma once
#ifndef GAME_STATE_HPP
#define GAME_STATE_HPP

/*
To avoid changing the actual game state manager, an interface is created. It is purely abstract.
*/

#include "game.hpp"

class game;

class game_state {
public:
	virtual ~game_state() = 0 {}

	virtual void init() = 0;
	virtual void clean() = 0;

	/*virtual void pause() = 0;
	virtual void resume() = 0;*/

	virtual void handle_input(game &game) = 0;
	virtual void update(game &game) = 0;		
	virtual void render(game &game) = 0;
};

#endif // !GAME_STATE_HPP
