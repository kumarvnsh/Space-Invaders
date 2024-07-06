#include "../Header/ServiceLocator.h"

// Initialize the static member
ServiceLocator* ServiceLocator::instance = nullptr;

// Constructor
ServiceLocator::ServiceLocator() {
    graphicService = new GraphicService();
    eventService = new EventService();
    playerService = new PlayerService();
}

// Destructor
ServiceLocator::~ServiceLocator() {
    delete graphicService;
    delete eventService;
    delete playerService;
}

// Singleton instance getter
ServiceLocator* ServiceLocator::getInstance() {
    if (instance == nullptr) {
        instance = new ServiceLocator();
    }
    return instance;
}

void ServiceLocator::initialize() {
    graphicService->initialize();
    eventService->initialize();
    playerService->initialize();
}

void ServiceLocator::update() {
    graphicService->update();
    eventService->processEvents(); // Ensure event processing is called here
    playerService->update();
}

void ServiceLocator::render() {
    graphicService->render();
    playerService->render();
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

void ServiceLocator::createServices() {
    // Additional services can be created and initialized here
}

void ServiceLocator::clearAllServices() {
    // Clear or deregister services if needed
}
