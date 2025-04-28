#include <iostream>
#include <SFML/Graphics.hpp>
#include "constants.h"
#include "variable.h"
#include "init.h"
#include "menu.h"
#include "process.h"

// Initialize global variables
sf::RenderWindow window;
sf::Event event;

// Textures and sprites
sf::Texture bikeTexture;
sf::Sprite bike;
sf::Texture playMenuTexture;
sf::Sprite playMenu;
sf::Texture menuPicTexture;
sf::Sprite menuPic;
sf::Texture dieTexture;
sf::Sprite dieSprite;
sf::Texture backTextures[2];
sf::Sprite backSprites[2];
sf::Texture upbackTexture;
sf::Sprite upbackSprite;
sf::Texture obsWallTextures[2];
sf::Sprite obsWallSprites[2];
sf::Texture timeLimitTexture;
sf::Sprite timeLimitSprite;

// Font
sf::Font font;
sf::Text timerText;

// Game objects
Background bg[2];
Wall w1[SMALL_WALL_MAX];
Wall w2[BIG_WALL_MAX];

// Bike state
float bike_x = 0;
float bike_y = 0;
float bike_stand = 0;

int main() {
    if (!init_all()) {
        std::cerr << "Failed to initialize game!" << std::endl;
        return 1;
    }

    if (!load_files()) {
        std::cerr << "Failed to load game resources!" << std::endl;
        return 1;
    }

    int opt = start_menu();
    if (opt == 1) {
        bike_process bk;
        while (bk.process()) {
            // Processing happens inside the process() method
        }
    }

    return 0;
}