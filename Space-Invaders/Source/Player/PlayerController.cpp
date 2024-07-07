#include "../../Header/Player/PlayerController.h"
#include "../../Header/ServiceLocator/ServiceLocator.h"
#include "../../Header/EventService/EventService.h"

PlayerController::PlayerController(PlayerModel* model, PlayerView* view) : model(model), view(view) {}

void PlayerController::initialize(sf::RenderWindow* window) {
    model->reset();
    view->initialize(window);
}

void PlayerController::update(float deltaTime) {
    processInput(deltaTime);
}

void PlayerController::render() {
    view->render();
}

void PlayerController::processInput(float deltaTime) {
    EventService* eventService = ServiceLocator::getInstance()->getEventService();
    if (eventService->pressedLeftKey()) {
        sf::Vector2f newPosition = model->getPosition();
        newPosition.x -= model->getMovementSpeed() * deltaTime;
        model->setPosition(newPosition);
    }
    if (eventService->pressedRightKey()) {
        sf::Vector2f newPosition = model->getPosition();
        newPosition.x += model->getMovementSpeed() * deltaTime;
        model->setPosition(newPosition);
    }
}
