#include "../../Header/ServiceLocator/ServiceLocator.h"

// Initialize the static member
ServiceLocator* ServiceLocator::instance = nullptr;

// Constructor
ServiceLocator::ServiceLocator() {
    graphicService = new GraphicService();
    eventService = new EventService();
    playerService = new PlayerService();
    timeService = new TimeService();
    gameService = new GameService();
}

// Destructor
ServiceLocator::~ServiceLocator() {
    delete graphicService;
    delete eventService;
    delete playerService;
    delete timeService;
    delete gameService;
}

// Singleton instance getter
ServiceLocator* ServiceLocator::getInstance() {
    if (instance == nullptr) {
        instance = new ServiceLocator();
    }
    return instance;
}

void ServiceLocator::initialize(sf::RenderWindow* window) {
    graphicService->initialize();
    eventService->initialize();
    playerService->initialize(window);
    timeService->initialize();
    gameService->Ignite(window);
}

void ServiceLocator::update() {
    graphicService->update();
    eventService->processEvents(); // Ensure event processing is called here
    timeService->update();
    playerService->update(timeService->getDeltaTime());
    gameService->update();
}

void ServiceLocator::render() {
    graphicService->render();
    playerService->render();
    gameService->render();
}

GraphicService* ServiceLocator::getGraphicService() {
    return graphicService;
}

EventService* ServiceLocator::getEventService() {
    return eventService;
}

PlayerService* ServiceLocator::getPlayerService() {
    return playerService;
}

TimeService* ServiceLocator::getTimeService() {
    return timeService;
}

GameService* ServiceLocator::getGameService() {
    return gameService;
}

void ServiceLocator::createServices() {
    // Additional services can be created and initialized here
}

void ServiceLocator::clearAllServices() {
    // Clear or deregister services if needed
}
