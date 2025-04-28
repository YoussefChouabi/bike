#ifndef COORDINATE_H
#define COORDINATE_H

#include <SFML/Graphics.hpp>
#include "constants.h"

class GameObject {
protected:
    sf::FloatRect rect;

public:
    GameObject(float x = 0, float y = 0, float w = 0, float h = 0)
        : rect{ x, y, w, h } {
    }

    float getX() const { return rect.left; }
    float getY() const { return rect.top; }
    float getWidth() const { return rect.width; }
    float getHeight() const { return rect.height; }
    sf::FloatRect getRect() const { return rect; }

    void setPosition(float x, float y) { rect.left = x; rect.top = y; }
    void setDimensions(float w, float h) { rect.width = w; rect.height = h; }
};

class Background : public GameObject {
public:
    Background() = default;
    Background(float x, float y, float w, float h) : GameObject(x, y, w, h) {}

    void scroll(float amount) {
        rect.left += amount;
        if (rect.left < -SCREEN_WIDTH) {
            rect.left += 2 * SCREEN_WIDTH;
        }
    }
};

class Wall : public GameObject {
    bool active = false;

public:
    Wall() = default;
    Wall(float x, float y, float w, float h) : GameObject(x, y, w, h) {}

    bool isActive() const { return active; }
    void setActive(bool state) { active = state; }

    void move(float amount) {
        rect.left += amount;
        active = !(rect.left > SCREEN_WIDTH || (rect.left + rect.width) < 0);
    }
};

#endif // COORDINATE_H