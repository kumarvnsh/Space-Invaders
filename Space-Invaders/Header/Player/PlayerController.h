#pragma once

#include "PlayerModel.h"
#include "PlayerView.h"

class PlayerController {
public:
    PlayerController(PlayerModel* model, PlayerView* view);
    void initialize(sf::RenderWindow* window);
    void update(float deltaTime);
    void render();

private:
    PlayerModel* model;
    PlayerView* view;
    void processInput(float deltaTime);
};
