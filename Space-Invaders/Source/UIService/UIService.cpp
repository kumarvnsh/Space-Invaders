#include "../../Header/UIService/UIService.h"

UIService::UIService() : mainMenuController(nullptr) {}

UIService::~UIService() {
    destroy();
}

void UIService::initialize(sf::RenderWindow* window) {
    createUIControllers();
    initializeUIControllers(window);
}

void UIService::update() {
    if (mainMenuController != nullptr) {
        mainMenuController->update();
    }
}

void UIService::render() {
    if (mainMenuController != nullptr) {
        mainMenuController->render();
    }
}

void UIService::destroy() {
    destroyUIControllers();
}

void UIService::createUIControllers() {
    mainMenuController = new MainMenuUIController();
}

void UIService::initializeUIControllers(sf::RenderWindow* window) {
    if (mainMenuController != nullptr) {
        mainMenuController->initialize(window);
    }
}

void UIService::destroyUIControllers() {
    if (mainMenuController != nullptr) {
        delete mainMenuController;
        mainMenuController = nullptr;
    }
}
