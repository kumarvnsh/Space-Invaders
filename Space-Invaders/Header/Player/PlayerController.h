#pragma once

#include <SFML/Graphics/RenderWindow.hpp> // Include the necessary SFML header

class PlayerModel;
class PlayerView;

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
