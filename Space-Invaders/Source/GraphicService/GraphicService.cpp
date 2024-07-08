#include "../../Header/GraphicService/GraphicService.h"
#include "../../Header/ServiceLocator/ServiceLocator.h"
#include <iostream>

GraphicService::GraphicService() : game_window(nullptr), video_mode(nullptr) {}

GraphicService::~GraphicService() {
    onDestroy();
}

void GraphicService::initialize() {
    setVideoMode();
    game_window = new sf::RenderWindow(*video_mode, game_window_title, sf::Style::Resize | sf::Style::Close);
    game_window->setFramerateLimit(60);
    std::cout << "Game window initialized.\n";
}

void GraphicService::update() {
    // Update logic if any
}

void GraphicService::render() {
    //if (game_window) {
    //    std::cout << "Clearing window\n";
    //    game_window->clear(window_color);  // Clear to the defined window color

    //    std::cout << "Rendering game service\n";
    //    ServiceLocator::getInstance()->getGameService()->render();  // Ensure correct rendering order

    //    std::cout << "Displaying window\n";
    //    game_window->display();
    //}
}


bool GraphicService::isGameWindowOpen() {
    return game_window && game_window->isOpen();
}

sf::RenderWindow* GraphicService::getGameWindow() {
    return game_window;
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
