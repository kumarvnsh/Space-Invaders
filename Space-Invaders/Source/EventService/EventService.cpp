#include "../../Header/EventService/EventService.h"
#include "../../Header/ServiceLocator/ServiceLocator.h"
#include "../../Header/GraphicService/GraphicService.h"
#include <iostream>

using namespace Event;

EventService::EventService() {
    game_window = nullptr;
    left_mouse_button_state = ButtonState::RELEASED;
    right_mouse_button_state = ButtonState::RELEASED;
    left_arrow_button_state = ButtonState::RELEASED;
    right_arrow_button_state = ButtonState::RELEASED;
    a_button_state = ButtonState::RELEASED;
    d_button_state = ButtonState::RELEASED;
}

EventService::~EventService() = default;

void EventService::initialize() {
    game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
}

void EventService::update() {
    updateMouseButtonsState(left_mouse_button_state, sf::Mouse::Left);
    updateMouseButtonsState(right_mouse_button_state, sf::Mouse::Right);
    updateKeyboardButtonsState(left_arrow_button_state, sf::Keyboard::Left);
    updateKeyboardButtonsState(right_arrow_button_state, sf::Keyboard::Right);
    updateKeyboardButtonsState(a_button_state, sf::Keyboard::A);
    updateKeyboardButtonsState(d_button_state, sf::Keyboard::D);
}

void EventService::processEvents() {
    while (game_window->pollEvent(game_event)) {
        if (game_event.type == sf::Event::Closed) {
            game_window->close();
        }
        else if (game_event.type == sf::Event::KeyPressed && game_event.key.code == sf::Keyboard::Escape) {
            game_window->close();
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
    return left_arrow_button_state == ButtonState::HELD;
}

bool EventService::pressedRightKey() {
    return right_arrow_button_state == ButtonState::HELD;
}

bool EventService::pressedAKey() {
    return a_button_state == ButtonState::HELD;
}

bool EventService::pressedDKey() {
    return d_button_state == ButtonState::HELD;
}

bool EventService::leftMouseClicked() {
    return left_mouse_button_state == ButtonState::PRESSED;
}

bool EventService::rightMouseClicked() {
    return right_mouse_button_state == ButtonState::PRESSED;
}

void EventService::updateMouseButtonsState(ButtonState& current_button_state, sf::Mouse::Button mouse_button) {
    if (sf::Mouse::isButtonPressed(mouse_button)) {
        switch (current_button_state) {
        case ButtonState::RELEASED:
            current_button_state = ButtonState::PRESSED;
            break;
        case ButtonState::PRESSED:
            current_button_state = ButtonState::HELD;
            break;
        default:
            break;
        }
    }
    else {
        current_button_state = ButtonState::RELEASED;
    }
}

void EventService::updateKeyboardButtonsState(ButtonState& current_button_state, sf::Keyboard::Key keyboard_button) {
    if (sf::Keyboard::isKeyPressed(keyboard_button)) {
        switch (current_button_state) {
        case ButtonState::RELEASED:
            current_button_state = ButtonState::PRESSED;
            break;
        case ButtonState::PRESSED:
            current_button_state = ButtonState::HELD;
            break;
        default:
            break;
        }
    }
    else {
        current_button_state = ButtonState::RELEASED;
    }
}
