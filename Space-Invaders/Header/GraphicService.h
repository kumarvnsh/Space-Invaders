#pragma once

#include <SFML/Graphics.hpp>
#include <string>

class GraphicService {
public:
    // Constructor and Destructor
    GraphicService();
    ~GraphicService();

    // Public methods
    void initialize();
    void update();
    void render();
    bool isGameWindowOpen();
    sf::RenderWindow* getGameWindow();
    sf::Color getWindowColor();

private:
    // Private properties
    const std::string game_window_title = "SFML Game Window";
    const int game_window_width = 800;
    const int game_window_height = 600;
    const sf::Color window_color = sf::Color::Blue;
    sf::VideoMode* video_mode;
    sf::RenderWindow* game_window;
    const int frame_rate = 60;

    // Private methods
    void setVideoMode();
    void onDestroy();
};
