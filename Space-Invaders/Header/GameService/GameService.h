#pragma once

#include <SFML/Graphics.hpp>

enum class GameState {
    BOOT,
    MAIN_MENU,
    GAMEPLAY
};

class GameService {
public:
    GameService();
    ~GameService();

    void Ignite(sf::RenderWindow* window);
    void update();
    void render();
    bool isRunning();

    // Getter and setter for game state
    GameState getCurrentState() const;
    void setCurrentState(GameState state);

private:
    void initialize(sf::RenderWindow* window);
    void destroy();
    bool running;

    GameState current_state; // Current state of the game
};
