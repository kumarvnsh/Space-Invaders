#pragma once

#include "PlayerController.h"

class PlayerService {
public:
    PlayerService();
    ~PlayerService();

    void initialize(sf::RenderWindow* window);
    void update(float deltaTime);
    void render();

private:
    PlayerController* player_controller;
};
