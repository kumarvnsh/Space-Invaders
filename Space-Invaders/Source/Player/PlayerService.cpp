#include "../../Header/Player/PlayerService.h"
#include "../../Header/ServiceLocator/ServiceLocator.h"
#include <iostream>
#include <SFML/Graphics.hpp>

// Constructor
PlayerService::PlayerService() {
    game_window = nullptr;
    health = 3;
    position = sf::Vector2f(375.0f, 500.0f);
    movement_speed = 350.0f; // Movement speed is now units per second
    player_score = 0;
    player_model = new PlayerModel();
    player_view = new PlayerView();
    player_controller = new PlayerController(player_model, player_view);
}

// Destructor
PlayerService::~PlayerService() {
    delete player_model;
    delete player_view;
    delete player_controller;
}

// Initialize the player service
void PlayerService::initialize(sf::RenderWindow* window) {
    game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
    initializePlayerSprite();
    player_controller->initialize(game_window);
}

// Update the player service
void PlayerService::update(float deltaTime) {
    player_controller->update(deltaTime);
    player_sprite.setPosition(player_model->getPosition());
}

// Render the player service
void PlayerService::render() {
    game_window->draw(player_sprite);
    player_controller->render();
}

// Private method to initialize player sprite
void PlayerService::initializePlayerSprite() {
    if (!player_texture.loadFromFile(player_texture_path)) {
        std::cerr << "Error loading player ship texture" << std::endl; // Use std::cerr
        return;
    }
    player_sprite.setTexture(player_texture);
    player_sprite.setScale(0.5f, 0.5f);
}

// Getter for player score
int PlayerService::getScore() {
    return player_score;
}

// Setter for player score
void PlayerService::setScore(int newScore) {
    player_score = newScore;
}

// Getter for player position
sf::Vector2f PlayerService::getPosition() {
    return position;
}

// Method to handle player damage
void PlayerService::takeDamage() {
    // Implement damage logic here
}

// Method to handle shooting bullets
void PlayerService::shootBullets() {
    // Implement shooting logic here
}
