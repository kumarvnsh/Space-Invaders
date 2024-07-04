#include "../Header/GameService.h"

// Constructor
GameService::GameService() {
    serviceLocator = ServiceLocator::getInstance();
    initializeVariables();
    initialize();
}

// Destructor
GameService::~GameService() {
    destroy();
}

// Private method to initialize variables
void GameService::initializeVariables() {
    gameWindow = serviceLocator->getGraphicService()->getGameWindow();
}

// Private method to initialize the game
void GameService::initialize() {
    serviceLocator->initialize();
}

// Private method to destroy resources
void GameService::destroy() {
    serviceLocator->clearAllServices();
}

// Public method to start the game
void GameService::Ignite() {
    // Additional startup logic can be added here
}

// Public method to update the game
void GameService::update() {
    serviceLocator->update();
}

// Public method to render the game
void GameService::render() {
    gameWindow->clear(serviceLocator->getGraphicService()->getWindowColor());
    serviceLocator->render();
    gameWindow->display();
}

// Public method to check if the game is running
bool GameService::isRunning() {
    return serviceLocator->getGraphicService()->isGameWindowOpen();
}
