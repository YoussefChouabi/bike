#ifndef FUNCTION_H
#define FUNCTION_H

#include "variable.h"

inline void apply_texture(float x, float y, sf::Sprite& sprite) {
    sprite.setPosition(x, y);
    window.draw(sprite);
}

inline void apply_texture(float x, float y, sf::Text& text) {
    text.setPosition(x, y);
    window.draw(text);
}

#endif // FUNCTION_H