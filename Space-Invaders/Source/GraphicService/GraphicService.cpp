#include "../../Header/GraphicService/GraphicService.h"
#include "../../Header/ServiceLocator/ServiceLocator.h"
#include <iostream>

GraphicService::GraphicService() : video_mode(game_window_width, game_window_height), game_window(video_mode, game_window_title, sf::Style::Resize | sf::Style::Close) {
    game_window.setFramerateLimit(60);
}

GraphicService::~GraphicService() {
    // No need for onDestroy if using automatic memory management
}

void GraphicService::initialize() {
    // Already initialized in the constructor
    std::cout << "Game window initialized.\n";
}

void GraphicService::update() {
    // Update logic if any
}

void GraphicService::render() {
    if (game_window.isOpen()) {
        // Rendering is handled by the specific game state
    }
}

bool GraphicService::isGameWindowOpen() {
    return game_window.isOpen();
}

sf::RenderWindow* GraphicService::getGameWindow() {
    return &game_window;
}

sf::Color GraphicService::getWindowColor() {
    return window_color;
}

void GraphicService::setVideoMode() {
    // Already set in the constructor
}
