#pragma once

#include "../ServiceLocator/ServiceLocator.h"

class GameService {
public:
    GameService();
    ~GameService();

    void Ignite(sf::RenderWindow* window);
    void update();
    void render();
    bool isRunning();

private:
    void initialize(sf::RenderWindow* window);
    void destroy();
    bool running;
};
