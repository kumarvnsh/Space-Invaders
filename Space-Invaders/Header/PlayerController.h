#pragma once

#include <SFML/Graphics.hpp>
#include "PlayerModel.h"
#include "PlayerView.h"

class PlayerController {
public:
    PlayerController();
    ~PlayerController();

    void initialize(sf::RenderWindow* window);
    void update(float deltaTime);
    void render();

    PlayerModel* getModel();
    PlayerView* getView();

private:
    PlayerModel* player_model;
    PlayerView* player_view;

    void processPlayerInput(float deltaTime);
    void movePlayer(float deltaTime);
};
