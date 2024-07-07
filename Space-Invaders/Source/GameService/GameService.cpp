#include "../../Header/GameService/GameService.h"
#include "../../Header/ServiceLocator/ServiceLocator.h"
#include <SFML/Graphics.hpp>

// Constructor
GameService::GameService() : running(false), current_state(GameState::BOOT) {}

// Destructor
GameService::~GameService() {
    destroy();
}

// Initialize the game service
void GameService::Ignite(sf::RenderWindow* window) {
    initialize(window);
    running = true;
}

// Update the game service
void GameService::update() {
    ServiceLocator::getInstance()->update();
    // Add logic to handle state transitions if needed
}

// Render the game service
void GameService::render() {
    ServiceLocator::getInstance()->render();
}

// Check if the game is running
bool GameService::isRunning() {
    return running && ServiceLocator::getInstance()->getGraphicService()->isGameWindowOpen();
}

// Initialize the services
void GameService::initialize(sf::RenderWindow* window) {
    ServiceLocator::getInstance()->initialize(window);
}

// Destroy the services
void GameService::destroy() {
    ServiceLocator::getInstance()->clearAllServices();
}

// Get the current game state
GameState GameService::getCurrentState() const {
    return current_state;
}

// Set the current game state
void GameService::setCurrentState(GameState state) {
    current_state = state;
}
