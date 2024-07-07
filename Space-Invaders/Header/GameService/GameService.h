#pragma once
#include <SFML/Graphics.hpp>

enum class GameState {
    BOOT,
    MAIN_MENU,
    GAMEPLAY
};

class GameService {
private:
    static GameState current_state;
    bool running;

public:
    GameService();
    ~GameService();

    static void setCurrentState(GameState state);
    static GameState getCurrentState();

    void initialize();
    void update();
    void render();

    void Ignite(); // Ensure this method is declared
    bool isRunning(); // Ensure this method is declared
};
