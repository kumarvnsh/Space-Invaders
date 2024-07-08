#pragma once

#include "MainMenuUIController/MainMenuUIController.h"

class UIService {
private:
    UI::MainMenu::MainMenuUIController* main_menu_ui_controller;

public:
    UIService();
    ~UIService();

    void initialize();
    void update();
    void render();
};
