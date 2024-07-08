#pragma once

#include <SFML/Graphics.hpp>

class GraphicService {
public:
    GraphicService();
    ~GraphicService();

    void initialize();
    void update();
    void render();
    bool isGameWindowOpen();
    sf::RenderWindow* getGameWindow();

private:
    const std::string game_window_title = "Space Invaders";
    const int game_window_width = 1920;
    const int game_window_height = 1080;
    sf::Color window_color = sf::Color::Black;
    sf::VideoMode* video_mode;
    sf::RenderWindow* game_window;

    void setVideoMode();
    void onDestroy();
};
