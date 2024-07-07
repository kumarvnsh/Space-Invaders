#include "../../Header/GraphicService/GraphicService.h"


// Constructor
GraphicService::GraphicService() {
    video_mode = new sf::VideoMode(game_window_width, game_window_height);
    game_window = nullptr;
}

// Destructor
GraphicService::~GraphicService() {
    onDestroy();
    delete video_mode;
}

// Private method to set video mode
void GraphicService::setVideoMode() {
    game_window = new sf::RenderWindow(*video_mode, game_window_title);
}

// Private method to destroy resources
void GraphicService::onDestroy() {
    if (game_window) {
        game_window->close();
        delete game_window;
        game_window = nullptr;
    }
}

// Public method to initialize the window
void GraphicService::initialize() {
    setVideoMode();
    game_window->setFramerateLimit(frame_rate);
}

// Public method to update the window (e.g., handle events)
void GraphicService::update() {
    sf::Event event;
    while (game_window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            game_window->close();
        }
    }
}

// Public method to render content
void GraphicService::render() {
    game_window->clear(window_color);
    // Add drawing calls here
    game_window->display();
}

// Public method to check if the game window is open
bool GraphicService::isGameWindowOpen() {
    return game_window->isOpen();
}

// Getter for the game window
sf::RenderWindow* GraphicService::getGameWindow() {
    return game_window;
}

// Getter for the window color
sf::Color GraphicService::getWindowColor() {
    return window_color;
}
