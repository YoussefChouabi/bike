#ifndef INIT_H
#define INIT_H

#include "variable.h"
#include <iostream>

bool init_all() {
    window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "BIKE RACE");
    if (!window.isOpen()) {
        std::cerr << "Window could not be created!" << std::endl;
        return false;
    }

    return true;
}

bool load_texture(sf::Texture& texture, const std::string& filename) {
    if (!texture.loadFromFile(filename)) {
        std::cerr << "Unable to load image " << filename << std::endl;
        return false;
    }
    return true;
}

bool load_files() {
    // Load images
    if (!load_texture(bikeTexture, "images/bike.PNG")) return false;
    bike.setTexture(bikeTexture);

    if (!load_texture(playMenuTexture, "images/menu_play.JPG")) return false;
    playMenu.setTexture(playMenuTexture);

    if (!load_texture(menuPicTexture, "images/menu.jpg")) return false;
    menuPic.setTexture(menuPicTexture);

    if (!load_texture(dieTexture, "images/menu_exit.JPG")) return false;
    dieSprite.setTexture(dieTexture);

    if (!load_texture(backTextures[0], "images/bg2.PNG")) return false;
    if (!load_texture(backTextures[1], "images/bg1.PNG")) return false;
    backSprites[0].setTexture(backTextures[0]);
    backSprites[1].setTexture(backTextures[1]);

    if (!load_texture(upbackTexture, "images/bg1.PNG")) return false;
    upbackSprite.setTexture(upbackTexture);

    if (!load_texture(obsWallTextures[0], "images/wall.JPG")) return false;
    if (!load_texture(obsWallTextures[1], "images/wall1.JPG")) return false;
    obsWallSprites[0].setTexture(obsWallTextures[0]);
    obsWallSprites[1].setTexture(obsWallTextures[1]);

    if (!load_texture(timeLimitTexture, "images/menu_instruction.JPG")) return false;
    timeLimitSprite.setTexture(timeLimitTexture);

    // Initialize font
    if (!font.loadFromFile("font/Arial.ttf")) {
        std::cerr << "Failed to load font!" << std::endl;
        return false;
    }

    timerText.setFont(font);
    timerText.setCharacterSize(24);
    timerText.setFillColor(sf::Color::White);

    // Initialize game objects
    bg[0] = Background(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
    bg[1] = Background(SCREEN_WIDTH, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

    // Initialize walls
    for (int i = 0; i < SMALL_WALL_MAX; i++) {
        w1[i] = Wall(800 + i * 300, LAYER_Y, 50, 50);
        w1[i].setActive(true);
    }

    for (int i = 0; i < BIG_WALL_MAX; i++) {
        w2[i] = Wall(1000 + i * 400, LAYER_Y, 100, 100);
        w2[i].setActive(true);
    }

    // Initialize bike
    bike_x = START_BIKE_X;
    bike_y = LAYER_Y - 50; // Assuming bike height is about 50
    bike_stand = LAYER_Y;

    return true;
}

#endif // INIT_H