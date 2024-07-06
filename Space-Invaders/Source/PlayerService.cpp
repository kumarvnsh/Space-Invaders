#include "../Header/PlayerService.h"
#include "../Header/ServiceLocator.h"

// Constructor
PlayerService::PlayerService() {
    game_window = nullptr;
    health = 3;
    position = sf::Vector2f(375.0f, 500.0f);
    movement_speed = 0.5f;
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
void PlayerService::update() {
    processPlayerInput();
    player_sprite.setPosition(getPosition());
}

// Render the player service
void PlayerService::render() {
    game_window->draw(player_sprite);
}

// Private method to initialize player sprite
void PlayerService::initializePlayerSprite() {
    if (!player_texture.loadFromFile(player_texture_path)) {
        std::cerr << "Error loading player ship texture" << std::endl;
        return;
    }
    player_sprite.setTexture(player_texture);
    player_sprite.setScale(0.5f, 0.5f);
}

// Private method to process player input
void PlayerService::processPlayerInput() {
    EventService* event_service = ServiceLocator::getInstance()->getEventService();
    if (event_service->pressedLeftKey()) {
        move(-0.5f);
    }
    if (event_service->pressedRightKey()) {
        move(0.5f);
    }
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

// Method to move the player
void PlayerService::move(float offsetX) {
    position.x += offsetX * movement_speed;
    if (position.x < 25) position.x = 25;
    if (position.x > 725) position.x = 725;
}

// Method to handle shooting bullets
void PlayerService::shootBullets() {
    // Implement shooting logic here
}
