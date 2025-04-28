#ifndef PROCESS_H
#define PROCESS_H
#include <sstream> 
#include "variable.h"
#include "function.h"
#include "collision.h"

class bike_process {
private:
    sf::Clock gameClock;
    int time_gap = 0;
    int jump_state = 0;
    int speed = 0;
    int game_on = 1;

public:
    void load_layer(int x = 0, int y = 0) {
        window.clear(sf::Color::Black);

        apply_texture(bg[0].getX(), 0, backSprites[0]);
        apply_texture(bg[1].getX(), 0, backSprites[1]);
        apply_texture(0, 0, upbackSprite);

        for (int i = 0; i < SMALL_WALL_MAX; i++) {
            if (w1[i].isActive()) {
                obsWallSprites[0].setPosition(w1[i].getX(), w1[i].getY());
                window.draw(obsWallSprites[0]);
            }
        }

        for (int i = 0; i < BIG_WALL_MAX; i++) {
            if (w2[i].isActive()) {
                obsWallSprites[1].setPosition(w2[i].getX(), w2[i].getY());
                window.draw(obsWallSprites[1]);
            }
        }

        bike.setPosition(bike_x, bike_y);
        window.draw(bike);
    }

    void change_coardinate(int n);
    bool process();
};

bool bike_process::process() {
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            return false;
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) || game_on == 0 || time_gap >= 90) {
        return false;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        if (jump_state == 0) {
            jump_state = 36;
        }
    }

    if ((bike_y < (bike_stand - bike.getGlobalBounds().height)) || jump_state >= 16) {
        int jump_height = 19 - jump_state;
        bike_y += jump_height;
        jump_state--;
        if (jump_state == 0) {
            jump_state--;
        }
    }
    else {
        bike_y = bike_stand - bike.getGlobalBounds().height;
        jump_state = 0;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        if (speed <= 20) {
            speed++;
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        if (speed > 0) {
            speed--;
        }
    }

    if (bike_x < FINISH_BIKE_X) {
        bike_x += speed;
    }
    else {
        change_coardinate(-speed / 2);
    }
    change_coardinate(0);

    load_layer();

    if ((w2[BIG_WALL_MAX - 1].getX() + w2[BIG_WALL_MAX - 1].getWidth()) < 0) {
        apply_texture(100, 300, dieSprite);
        window.display();
        sf::sleep(sf::seconds(2));
        return false;
    }

    std::stringstream time;
    time_gap = gameClock.getElapsedTime().asSeconds();
    int mm = time_gap / 60;
    int ss = time_gap % 60;
    time << "Timer: " << mm << ":" << ss;
    timerText.setString(time.str());

    apply_texture(600, 50, timerText);
    apply_texture(500, 55 + timerText.getGlobalBounds().height, timeLimitSprite);

    window.display();
    return true;
}

void bike_process::change_coardinate(int n) {
    if (is_collision()) {
        game_on = 0;
    }
    else if (n != 0) {
        bg[0].scroll(n);
        bg[1].scroll(n);

        for (int i = 0; i < SMALL_WALL_MAX; i++) {
            w1[i].move(n);
        }
        for (int i = 0; i < BIG_WALL_MAX; i++) {
            w2[i].move(n);
        }
    }
    else {
        bg[0].scroll(n);
        bg[1].scroll(n);
    }
}

#endif // PROCESS_H