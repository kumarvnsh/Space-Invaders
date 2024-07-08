#include "../../Header/UIService/UIService.h"
#include "../../Header/ServiceLocator/ServiceLocator.h"
#include <iostream>

UIService::UIService() {
    main_menu_ui_controller = nullptr;
}

UIService::~UIService() {
    delete main_menu_ui_controller;
}

void UIService::initialize() {
    main_menu_ui_controller = new UI::MainMenu::MainMenuUIController();
    main_menu_ui_controller->initialize(ServiceLocator::getInstance()->getGraphicService()->getGameWindow());
}

void UIService::update() {
    main_menu_ui_controller->update();
}

void UIService::render() {
    std::cout << "Rendering UIService\n";
    main_menu_ui_controller->render();
}

