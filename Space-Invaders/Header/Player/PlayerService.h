#pragma once

#include <SFML/Graphics.hpp>
#include "PlayerModel.h"
#include "PlayerView.h"
#include "PlayerController.h"

class PlayerService {
public:
    PlayerService();
    ~PlayerService();

    void initialize(sf::RenderWindow* window);
    void update(float deltaTime);
    void render();

    sf::Vector2f getPosition() const;

private:
    sf::RenderWindow* game_window;
    PlayerModel* player_model;
    PlayerView* player_view;
    PlayerController* player_controller;

    void initializePlayer();
};
