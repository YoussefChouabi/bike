#ifndef VARIABLE_H
#define VARIABLE_H

#include <SFML/Graphics.hpp>
#include "coordinate.h"

// SFML window and objects
extern sf::RenderWindow window;
extern sf::Event event;

// Textures and sprites
extern sf::Texture bikeTexture;
extern sf::Sprite bike;
extern sf::Texture playMenuTexture;
extern sf::Sprite playMenu;
extern sf::Texture menuPicTexture;
extern sf::Sprite menuPic;
extern sf::Texture dieTexture;
extern sf::Sprite dieSprite;
extern sf::Texture backTextures[2];
extern sf::Sprite backSprites[2];
extern sf::Texture upbackTexture;
extern sf::Sprite upbackSprite;
extern sf::Texture obsWallTextures[2];
extern sf::Sprite obsWallSprites[2];
extern sf::Texture timeLimitTexture;
extern sf::Sprite timeLimitSprite;

// Font
extern sf::Font font;
extern sf::Text timerText;

// Game objects
extern Background bg[2];
extern Wall w1[5];  // SMALL_WALL_MAX
extern Wall w2[4];  // BIG_WALL_MAX

// Bike state
extern float bike_x;
extern float bike_y;
extern float bike_stand;

#endif // VARIABLE_H