#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include "MainMenuUIController/MainMenuUIController.h"

class UIService {
public:
    UIService();
    ~UIService();

    void initialize(sf::RenderWindow* window);
    void update();
    void render();
    void destroy();

private:
    MainMenuUIController* mainMenuController;

    void createUIControllers();
    void initializeUIControllers(sf::RenderWindow* window);
    void destroyUIControllers();
};
