#include "../../Header/Player/PlayerController.h"
#include "../../Header/ServiceLocator/ServiceLocator.h"
#include "../../Header/EventService/EventService.h"

PlayerController::PlayerController(PlayerModel* model, PlayerView* view) : model(model), view(view) {}

void PlayerController::initialize(sf::RenderWindow* window) {
    model->reset();
    view->initialize(window);
    model->setScreenDimensions(window->getSize());
}

void PlayerController::update(float deltaTime) {
    processInput(deltaTime);
}

void PlayerController::render() {
    view->render();
}

void PlayerController::processInput(float deltaTime) {
    Event::EventService* eventService = ServiceLocator::getInstance()->getEventService();
    sf::Vector2f newPosition = model->getPosition();
    float movementSpeed = model->getMovementSpeed() * deltaTime;

    if (eventService->pressedLeftKey() || eventService->pressedAKey()) {
        newPosition.x -= movementSpeed;
    }
    if (eventService->pressedRightKey() || eventService->pressedDKey()) {
        newPosition.x += movementSpeed;
    }

    // Ensure the player stays within the screen bounds with a margin
    float margin = 10.0f;
    sf::FloatRect playerBounds = view->getSpriteBounds();
    if (newPosition.x < margin) {
        newPosition.x = margin;
    }
    if (newPosition.x > model->getScreenDimensions().x - playerBounds.width - margin) {
        newPosition.x = model->getScreenDimensions().x - playerBounds.width - margin;
    }

    model->setPosition(newPosition);
}
