#pragma once

#include "MainMenuUIController/MainMenuUIController.h"  // Include the MainMenuUIController header

class UIService {
private:
    UI::MainMenu::MainMenuUIController* main_menu_ui_controller;  // Use the correct namespace and pointer

public:
    UIService();
    ~UIService();

    void initialize();
    void update();
    void render();
};
