#include "../Header/PlayerService.h"

PlayerService::PlayerService() {
    player_controller = new PlayerController();
}

PlayerService::~PlayerService() {
    delete player_controller;
}

void PlayerService::initialize(sf::RenderWindow* window) {
    player_controller->initialize(window);
}

void PlayerService::update(float deltaTime) {
    player_controller->update(deltaTime);
}

void PlayerService::render() {
    player_controller->render();
}
