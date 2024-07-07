#include "../../Header/GameService/GameService.h"

GameState GameService::current_state = GameState::MAIN_MENU;

GameService::GameService() : running(false) {}

GameService::~GameService() {}

void GameService::setCurrentState(GameState state) {
    current_state = state;
}

GameState GameService::getCurrentState() {
    return current_state;
}

void GameService::initialize() {
    running = true;
}

void GameService::update() {
    // Update logic based on current state
}

void GameService::render() {
    // Render logic based on current state
}

void GameService::Ignite() {
    running = true;
}

bool GameService::isRunning() {
    return running;
}
