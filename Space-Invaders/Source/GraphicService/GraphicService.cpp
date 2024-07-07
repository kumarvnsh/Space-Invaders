#include "../../Header/GraphicService/GraphicService.h"
#include <SFML/Graphics.hpp>

GraphicService::GraphicService() { game_window = nullptr; }
GraphicService::~GraphicService() { onDestroy(); }

void GraphicService::initialize() {
    setVideoMode();
    game_window = new sf::RenderWindow(*video_mode, game_window_title);
    game_window->setFramerateLimit(frame_rate);
}

void GraphicService::update() {
    // Update logic if any
}

void GraphicService::render() {
    game_window->clear(window_color);
    // Render other objects here
    game_window->display();
}

bool GraphicService::isGameWindowOpen() {
    return game_window && game_window->isOpen();
}

sf::RenderWindow* GraphicService::getGameWindow() {
    return game_window;
}

sf::Color GraphicService::getWindowColor() {
    return window_color;
}

void GraphicService::setVideoMode() {
    video_mode = new sf::VideoMode(game_window_width, game_window_height);
}

void GraphicService::onDestroy() {
    if (game_window) {
        delete game_window;
        game_window = nullptr;
    }
    if (video_mode) {
        delete video_mode;
        video_mode = nullptr;
    }
}
