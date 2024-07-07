#include "../../Header/ServiceLocator/ServiceLocator.h"
#include "../../Header/GraphicService/GraphicService.h"
#include "../../Header/GameService/GameService.h"
#include "../../Header/EventService/EventService.h"
#include "../../Header/UIService/UIService.h"

ServiceLocator* ServiceLocator::instance = nullptr;

ServiceLocator::ServiceLocator() {
    graphic_service = nullptr;
    game_service = nullptr;
    event_service = nullptr;
    ui_service = nullptr;
}

ServiceLocator::~ServiceLocator() {
    destroy();
}

ServiceLocator* ServiceLocator::getInstance() {
    if (instance == nullptr) {
        instance = new ServiceLocator();
    }
    return instance;
}

void ServiceLocator::initialize() {
    graphic_service = new GraphicService();
    game_service = new GameService();
    event_service = new EventService();
    ui_service = new UIService();

    graphic_service->initialize();
    game_service->initialize();
    event_service->initialize();
    ui_service->initialize();
}

void ServiceLocator::destroy() {
    delete graphic_service;
    delete game_service;
    delete event_service;
    delete ui_service;
}

void ServiceLocator::render() {
    graphic_service->render();
    ui_service->render();
}

GraphicService* ServiceLocator::getGraphicService() {
    return graphic_service;
}

GameService* ServiceLocator::getGameService() {
    return game_service;
}

EventService* ServiceLocator::getEventService() {
    return event_service;
}

UIService* ServiceLocator::getUIService() {
    return ui_service;
}

void ServiceLocator::Ignite() {
    game_service->Ignite();
}
