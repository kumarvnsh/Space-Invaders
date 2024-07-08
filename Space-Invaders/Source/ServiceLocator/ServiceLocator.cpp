#include "../../Header/ServiceLocator/ServiceLocator.h"
#include "../../Header/GraphicService/GraphicService.h"
#include "../../Header/GameService/GameService.h"
#include "../../Header/EventService/EventService.h"
#include "../../Header/UIService/UIService.h"
#include "../../Header/Player/PlayerService.h"

ServiceLocator* ServiceLocator::instance = nullptr;

ServiceLocator::ServiceLocator() {
    graphic_service = nullptr;
    game_service = nullptr;
    event_service = nullptr;
    ui_service = nullptr;
    player_service = nullptr;
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
    player_service = new PlayerService();

    graphic_service->initialize();
    game_service->initialize();
    event_service->initialize();
    ui_service->initialize();
    player_service->initialize(graphic_service->getGameWindow());
}

void ServiceLocator::destroy() {
    delete graphic_service;
    delete game_service;
    delete event_service;
    delete ui_service;
    delete player_service;
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

EventService* ServiceLocator::getEventService() {
    return event_service;
}

UIService* ServiceLocator::getUIService() {
    return ui_service;
}

PlayerService* ServiceLocator::getPlayerService() {
    return player_service;
}

void ServiceLocator::Ignite() {
    game_service->Ignite();
}
