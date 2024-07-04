#include "../Header/ServiceLocator.h"

// Initialize the static member
ServiceLocator* ServiceLocator::instance = nullptr;

// Constructor
ServiceLocator::ServiceLocator() {
    graphicService = new GraphicService();
}

// Destructor
ServiceLocator::~ServiceLocator() {
    delete graphicService;
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
}

void ServiceLocator::update() {
    graphicService->update();
}

void ServiceLocator::render() {
    graphicService->render();
}

GraphicService* ServiceLocator::getGraphicService() {
    return graphicService;
}

void ServiceLocator::createServices() {
    // Additional services can be created and initialized here
}

void ServiceLocator::clearAllServices() {
    // Clear or deregister services if needed
}
