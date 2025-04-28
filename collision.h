#ifndef COLLISION_H
#define COLLISION_H

#include "constants.h"
#include "variable.h"
#include "function.h"

#define SMAX_WALL SMALL_WALL_MAX
#define BMAX_WALL BIG_WALL_MAX

inline bool check_collision_wall(const sf::FloatRect& source, const sf::FloatRect& destination) {
    if (source.left + source.width < destination.left ||
        source.left > destination.left + destination.width ||
        source.top + source.height < destination.top ||
        source.top > destination.top + destination.height) {
        bike_stand = LAYER_Y;
        return false;
    }

    if ((source.top + source.height <= destination.top + 20) &&
        (source.top + source.height >= destination.top - 10)) {
        bike_stand = destination.top;
        bike_y = destination.top - source.height;
        return false;
    }

    window.clear(sf::Color::Black);
    apply_texture(100, 300, dieSprite);
    window.display();
    sf::sleep(sf::seconds(2));

    return true;
}

inline bool is_collision() {
    sf::FloatRect bike_rect(bike_x, bike_y, bike.getGlobalBounds().width, bike.getGlobalBounds().height);

    for (int i = 0; i < SMAX_WALL; i++) {
        if (w1[i].isActive() && check_collision_wall(bike_rect, w1[i].getRect())) {
            return true;
        }
    }

    for (int i = 0; i < BMAX_WALL; i++) {
        if (w2[i].isActive() && check_collision_wall(bike_rect, w2[i].getRect())) {
            return true;
        }
    }

    return false;
}

#endif // COLLISION_H