#include "../Header/PlayerService.h"
#include "../Header/ServiceLocator.h"
#include <iostream>


// Constructor
PlayerService::PlayerService() {
    game_window = nullptr;
    health = 3;
    position = sf::Vector2f(375.0f, 500.0f);
    movement_speed = 350.0f; // Movement speed is now units per second
    player_score = 0;
}

// Destructor
PlayerService::~PlayerService() = default;

// Initialize the player service
void PlayerService::initialize() {
    game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
    initializePlayerSprite();
}

// Update the player service
void PlayerService::update(float deltaTime) {
    processPlayerInput(deltaTime);
    player_sprite.setPosition(getPosition());
}

// Render the player service
void PlayerService::render() {
    game_window->draw(player_sprite);
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

// Private method to process player input
void PlayerService::processPlayerInput(float deltaTime) {
    EventService* event_service = ServiceLocator::getInstance()->getEventService();
    if (event_service->pressedLeftKey()) {
        moveLeft(deltaTime);
    }
    if (event_service->pressedRightKey()) {
        moveRight(deltaTime);
    }
}

// Method to move the player left
void PlayerService::moveLeft(float deltaTime) {
    position.x -= movement_speed * deltaTime;
    if (position.x < 25) position.x = 25;
}

// Method to move the player right
void PlayerService::moveRight(float deltaTime) {
    position.x += movement_speed * deltaTime;
    if (position.x > 725) position.x = 725;
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
