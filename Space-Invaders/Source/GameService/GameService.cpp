#include "../../Header/GameService/GameService.h"
#include "../../Header/ServiceLocator/ServiceLocator.h"
#include "../../Header/UIService/UIService.h"
#include "../../Header/Player/PlayerService.h"
#include <iostream>

GameService::GameState GameService::current_state = GameState::MAIN_MENU;

GameService::GameService() : running(false) {}

GameService::~GameService() {}

void GameService::setCurrentState(GameState state) {
    current_state = state;
}

GameService::GameState GameService::getCurrentState() {
    return current_state;
}

void GameService::initialize() {
    running = true;
    showMainMenu();
}

void GameService::update(float deltaTime) {
    if (current_state == GameState::MAIN_MENU) {
        ServiceLocator::getInstance()->getUIService()->update();
    }
    else if (current_state == GameState::GAMEPLAY) {
        ServiceLocator::getInstance()->getPlayerService()->update(deltaTime);
    }
}

void GameService::render() {
    if (current_state == GameState::MAIN_MENU) {
        ServiceLocator::getInstance()->getUIService()->render();
    }
    else if (current_state == GameState::GAMEPLAY) {
        ServiceLocator::getInstance()->getPlayerService()->render();
    }
}

void GameService::Ignite() {
    running = true;
}

bool GameService::isRunning() {
    return running;
}

void GameService::showMainMenu() {
    setCurrentState(GameState::MAIN_MENU);
}
