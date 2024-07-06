#pragma once
#pragma once

#include <SFML/Graphics.hpp>
#include "ServiceLocator.h"

class PlayerService {
private:
    // Private variables
    int health;
    sf::Vector2f position;
    float movement_speed;
    int player_score;

    sf::Texture player_texture;
    sf::Sprite player_sprite;

    const std::string player_texture_path = "assets/textures/player_ship.png";
    sf::RenderWindow* game_window;

    // Private methods
    void initializePlayerSprite();
    void processPlayerInput();

public:
    // Constructor and Destructor
    PlayerService();
    ~PlayerService();

    // Public methods
    void initialize();
    void update();
    void render();

    int getScore();
    void setScore(int newScore);
    sf::Vector2f getPosition();
    void takeDamage();
    void move(float offsetX);
    void shootBullets();
};
