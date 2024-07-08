#pragma once

class GameService {
public:
    enum class GameState {
        MAIN_MENU,
        GAMEPLAY,
        PAUSE,
        GAMEOVER
    };

private:
    static GameState current_state;
    bool running;

public:
    GameService();
    ~GameService();

    static void setCurrentState(GameState state);
    static GameState getCurrentState();

    void initialize();
    void update(float deltaTime);
    void render();

    void Ignite();
    bool isRunning();
    void showMainMenu();
};


