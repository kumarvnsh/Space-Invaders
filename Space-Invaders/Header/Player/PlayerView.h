#pragma once

#include <SFML/Graphics.hpp>

class PlayerView {
public:
    PlayerView();
    ~PlayerView();

    void initialize(sf::RenderWindow* window);
    void render();
    void setSpritePosition(const sf::Vector2f& position);

private:
    sf::RenderWindow* game_window;
    sf::Sprite player_sprite;
    sf::Texture player_texture;

    const int width = 50;
    const int height = 50;
    const std::string player_texture_path = "assets/textures/player_ship.png";

    void initializePlayerSprite();
    void scaleSprite();
};
