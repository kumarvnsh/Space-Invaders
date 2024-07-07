#pragma once

#include <SFML/Graphics.hpp>

class PlayerView {
public:
    PlayerView();
    ~PlayerView();

    void initialize(sf::RenderWindow* window);
    void render(); // No arguments needed

private:
    sf::RenderWindow* game_window;
    sf::Sprite player_sprite;
    sf::Texture player_texture;

    void initializePlayerSprite();
};
