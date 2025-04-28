#ifndef MENU_H
#define MENU_H

#include "variable.h"
#include "function.h"

int start_menu() {
    bool running = true;
    sf::Vector2i mousePos;

    while (running) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                running = false;
                return 0;
            }

            if (event.type == sf::Event::MouseMoved) {
                mousePos = sf::Mouse::getPosition(window);

                window.clear(sf::Color::Black);

                if ((mousePos.x > 594) && (mousePos.x < 756) && (mousePos.y > 340) && (mousePos.y < 357)) {
                    apply_texture(0, 0, playMenu);
                }
                else {
                    apply_texture(0, 0, menuPic);
                }

                window.display();
            }

            if (event.type == sf::Event::MouseButtonPressed) {
                mousePos = sf::Mouse::getPosition(window);

                if ((mousePos.x > 594) && (mousePos.x < 756) && (mousePos.y > 340) && (mousePos.y < 357)) {
                    return 1; // Start game
                }
            }
        }
    }

    return 0;
}

#endif // MENU_H