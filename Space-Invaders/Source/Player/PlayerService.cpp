#include "../../Header/Player/PlayerService.h"
#include "../../Header/ServiceLocator/ServiceLocator.h"

PlayerService::PlayerService() {
    game_window = nullptr;
    player_model = new PlayerModel();
    player_view = new PlayerView();
    player_controller = new PlayerController(player_model, player_view);
}

PlayerService::~PlayerService() {
    delete player_model;
    delete player_view;
    delete player_controller;
}

void PlayerService::initialize(sf::RenderWindow* window) {
    game_window = window;
    initializePlayer();
}

void PlayerService::initializePlayer() {
    player_model->setScreenDimensions(game_window->getSize());
    player_model->reset();
    player_view->initialize(game_window);
    player_controller->initialize(game_window);
}

void PlayerService::update(float deltaTime) {
    if (player_model->getPlayerState() == PlayerModel::PlayerState::ALIVE) {
        player_controller->update(deltaTime);
    }
}

void PlayerService::render() {
    if (player_model->getPlayerState() == PlayerModel::PlayerState::ALIVE) {
        player_view->render();
    }
}

sf::Vector2f PlayerService::getPosition() const {
    return player_model->getPosition();
}
