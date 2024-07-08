#include "../../Header/EventService/EventService.h"
#include "../../Header/ServiceLocator/ServiceLocator.h"
#include "../../Header/GraphicService/GraphicService.h"
#include <iostream>

EventService::EventService() {
    game_window = nullptr;
}

EventService::~EventService() = default;

void EventService::initialize() {
    game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
}

void EventService::update() {
    // for later
}

void EventService::processEvents() {
    if (isGameWindowOpen()) {
        while (game_window->pollEvent(game_event)) {
            if (gameWindowWasClosed() || hasQuitGame()) {
                game_window->close();
            }
        }
    }
}

bool EventService::hasQuitGame() {
    return (isKeyboardEvent() && pressedEscapeKey());
}

bool EventService::isKeyboardEvent() {
    return game_event.type == sf::Event::KeyPressed;
}

bool EventService::pressedEscapeKey() {
    return game_event.key.code == sf::Keyboard::Escape;
}

bool EventService::isGameWindowOpen() {
    return game_window != nullptr;
}

bool EventService::gameWindowWasClosed() {
    return game_event.type == sf::Event::Closed;
}

bool EventService::pressedLeftKey() {
    return game_event.type == sf::Event::KeyPressed && game_event.key.code == sf::Keyboard::Left;
}

bool EventService::pressedRightKey() {
    return game_event.type == sf::Event::KeyPressed && game_event.key.code == sf::Keyboard::Right;
}

bool EventService::leftMouseClicked() {
    if (game_event.type == sf::Event::MouseButtonPressed && game_event.mouseButton.button == sf::Mouse::Left) {
        std::cout << "Left mouse button clicked at position: (" << game_event.mouseButton.x << ", " << game_event.mouseButton.y << ")\n";
        return true;
    }
    return false;
}

bool EventService::rightMouseClicked() {
    return game_event.type == sf::Event::MouseButtonPressed && game_event.mouseButton.button == sf::Mouse::Right;
}
