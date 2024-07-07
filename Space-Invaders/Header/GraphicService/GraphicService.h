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
    sf::Color getWindowColor();

private:
    const std::string game_window_title = "My Game";
    const int game_window_width = 1920;
    const int game_window_height = 1080;
    const sf::Color window_color = sf::Color::Blue;
    sf::VideoMode* video_mode;
    sf::RenderWindow* game_window;

    void setVideoMode();
    void onDestroy();
};
