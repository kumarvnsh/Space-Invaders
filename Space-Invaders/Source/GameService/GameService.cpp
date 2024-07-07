#include "../../Header/GameService/GameService.h"
#include "../../Header/ServiceLocator/ServiceLocator.h"


// Constructor
GameService::GameService() : running(false) {}

// Destructor
GameService::~GameService() {
    destroy();
}

void GameService::Ignite(sf::RenderWindow* window) {
    initialize(window);
    running = true;
}

void GameService::update() {
    ServiceLocator::getInstance()->update();
}

void GameService::render() {
    ServiceLocator::getInstance()->render();
}

bool GameService::isRunning() {
    return running && ServiceLocator::getInstance()->getGraphicService()->isGameWindowOpen();
}

void GameService::initialize(sf::RenderWindow* window) {
    ServiceLocator::getInstance()->initialize(window);
}

void GameService::destroy() {
    ServiceLocator::getInstance()->clearAllServices();
}
