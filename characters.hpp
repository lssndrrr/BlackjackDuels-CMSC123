#pragma once
#ifndef CHARACTERS_HPP
#define CHARACTERS_HPP

#include "header.hpp"

enum charType {
    jackChar,
    jakeChar,
    jacksonChar,
    jadeChar,
    none
};

class character {
public:
    charType type = none;
    Sprite *charSprite;
    string name;
    void ability();
};

#endif // !CHARACTERS_HPP
