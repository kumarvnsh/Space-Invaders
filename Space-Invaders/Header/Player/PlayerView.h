#pragma once

#include <SFML/Graphics.hpp>

class PlayerView {
public:
    PlayerView();
    ~PlayerView();

    void initialize(sf::RenderWindow* window);
    void render();
    sf::FloatRect getSpriteBounds() const;

private:
    sf::RenderWindow* game_window;
    sf::Sprite player_sprite;
    sf::Texture player_texture;

    void initializePlayerSprite();
};
