#pragma once

#include <SFML/Graphics.hpp>

class MainMenuUIController {
public:
    MainMenuUIController();
    ~MainMenuUIController();

    void initialize(sf::RenderWindow* window);
    void update();
    void render();

private:
    sf::RenderWindow* game_window;
};
