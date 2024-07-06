#pragma once

#include "ServiceLocator.h"

class GameService {
public:
    // Constructor
    GameService();

    // Destructor
    ~GameService();

    // Public methods
    void Ignite();
    void update();
    void render();
    bool isRunning();

private:
    // Private methods
    void initialize();
    void destroy();
    void initializeVariables();

    // Private properties
    ServiceLocator* serviceLocator;
    sf::RenderWindow* gameWindow;
};
