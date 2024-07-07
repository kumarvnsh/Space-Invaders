#pragma once

#include <SFML/Graphics.hpp>
#include "PlayerModel.h"
#include "PlayerView.h"
#include "PlayerController.h"

class PlayerService {
public:
    PlayerService();
    ~PlayerService();

    void initialize(sf::RenderWindow* window);
    void update(float deltaTime);
    void render();

    int getScore();
    void setScore(int newScore);
    sf::Vector2f getPosition();
    void takeDamage();
    void shootBullets();

private:
    int health;
    sf::Vector2f position;
    float movement_speed;
    int player_score;

    sf::Texture player_texture;
    sf::Sprite player_sprite;

    const std::string player_texture_path = "assets/textures/player_ship.png";
    sf::RenderWindow* game_window;

    PlayerModel* player_model;
    PlayerView* player_view;
    PlayerController* player_controller;

    void initializePlayerSprite();
    void processPlayerInput(float deltaTime);
    void moveLeft(float deltaTime);
    void moveRight(float deltaTime);
};
