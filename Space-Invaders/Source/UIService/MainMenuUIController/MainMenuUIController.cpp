#include "../../Header/UIService/MainMenuUIController/MainMenuUIController.h"

MainMenuUIController::MainMenuUIController() : game_window(nullptr) {}

MainMenuUIController::~MainMenuUIController() {}

void MainMenuUIController::initialize(sf::RenderWindow* window) {
    game_window = window;
}

void MainMenuUIController::update() {
    // Update UI elements if any
}

void MainMenuUIController::render() {
    if (game_window) {
        // Render UI elements
    }
}
