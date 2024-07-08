// ServiceLocator.cpp

#include "../../Header/ServiceLocator/ServiceLocator.h"

ServiceLocator* ServiceLocator::instance = nullptr;

ServiceLocator::ServiceLocator() {
    graphic_service = nullptr;
    game_service = nullptr;
    event_service = nullptr;
    ui_service = nullptr;
    player_service = nullptr;
    time_service = nullptr; // Add this line
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
    if (!graphic_service) {
        graphic_service = new GraphicService();
        graphic_service->initialize();
    }

    if (!game_service) {
        game_service = new GameService();
        game_service->initialize();
    }

    if (!event_service) {
        event_service = new Event::EventService();
        event_service->initialize();
    }

    if (!ui_service) {
        ui_service = new UIService();
        ui_service->initialize();
    }

    if (!player_service) {
        player_service = new PlayerService();
        player_service->initialize(graphic_service->getGameWindow());
    }

    if (!time_service) {
        time_service = new TimeService();
        time_service->initialize();
    }
}


void ServiceLocator::destroy() {
    delete graphic_service;
    delete game_service;
    delete event_service;
    delete ui_service;
    delete player_service;
    delete time_service; // Add this line
}

void ServiceLocator::render() {
    if (game_service->getCurrentState() == GameService::GameState::MAIN_MENU) {
        ui_service->render();
    }
    else if (game_service->getCurrentState() == GameService::GameState::GAMEPLAY) {
        player_service->render();
    }
    graphic_service->render();
}

GraphicService* ServiceLocator::getGraphicService() {
    return graphic_service;
}

GameService* ServiceLocator::getGameService() {
    return game_service;
}

Event::EventService* ServiceLocator::getEventService() {
    return event_service;
}

UIService* ServiceLocator::getUIService() {
    return ui_service;
}

PlayerService* ServiceLocator::getPlayerService() {
    return player_service;
}

TimeService* ServiceLocator::getTimeService() { // Add this function
    return time_service;
}

void ServiceLocator::Ignite() {
    game_service->Ignite();
}
