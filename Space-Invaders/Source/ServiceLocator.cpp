#include "../Header/ServiceLocator.h"

// Initialize the static member
ServiceLocator* ServiceLocator::instance = nullptr;

// Constructor
ServiceLocator::ServiceLocator() {
    graphicService = new GraphicService();
    eventService = new EventService();
}

// Destructor
ServiceLocator::~ServiceLocator() {
    delete graphicService;
    delete eventService;
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
}

void ServiceLocator::update() {
    graphicService->update();
    eventService->processEvents(); // Ensure event processing is called here
}

void ServiceLocator::render() {
    graphicService->render();
}

GraphicService* ServiceLocator::getGraphicService() {
    return graphicService;
}

EventService* ServiceLocator::getEventService() {
    return eventService;
}

void ServiceLocator::createServices() {
    // Additional services can be created and initialized here
}

void ServiceLocator::clearAllServices() {
    // Clear or deregister services if needed
}
