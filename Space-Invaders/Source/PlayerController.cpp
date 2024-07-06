#include "../Header/PlayerController.h"

PlayerController::PlayerController() {
    player_model = new PlayerModel();
    player_view = new PlayerView();
}

PlayerController::~PlayerController() {
    delete player_model;
    delete player_view;
}

void PlayerController::initialize(sf::RenderWindow* window) {
    player_model->initialize();
    player_view->initialize(window);
}

void PlayerController::update(float deltaTime) {
    processPlayerInput(deltaTime);
    player_view->setSpritePosition(player_model->getPosition());
}

void PlayerController::render() {
    player_view->render();
}

PlayerModel* PlayerController::getModel() {
    return player_model;
}

PlayerView* PlayerController::getView() {
    return player_view;
}

void PlayerController::processPlayerInput(float deltaTime) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        player_model->setPosition(player_model->getPosition() - sf::Vector2f(player_model->getSpeed() * deltaTime, 0));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        player_model->setPosition(player_model->getPosition() + sf::Vector2f(player_model->getSpeed() * deltaTime, 0));
    }
}
