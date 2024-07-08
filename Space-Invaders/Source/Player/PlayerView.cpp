#include "../../Header/Player/PlayerView.h"
#include "../../Header/ServiceLocator/ServiceLocator.h"
#include <iostream>

PlayerView::PlayerView() : game_window(nullptr) {}

PlayerView::~PlayerView() = default;

void PlayerView::initialize(sf::RenderWindow* window) {
    game_window = window;
    initializePlayerSprite();
    sf::Vector2u window_size = game_window->getSize();
    float player_width = player_sprite.getGlobalBounds().width;
    float player_height = player_sprite.getGlobalBounds().height;
    player_sprite.setPosition(window_size.x / 2 - player_width / 2, window_size.y - player_height - 10);
}

void PlayerView::initializePlayerSprite() {
    if (!player_texture.loadFromFile("assets/textures/player_ship.png")) {
        std::cerr << "Error loading player ship texture" << std::endl;
        return;
    }
    player_sprite.setTexture(player_texture);
    player_sprite.setScale(1.0f, 1.0f);  // Increase size
}

void PlayerView::render() {
    if (game_window) {
        player_sprite.setPosition(ServiceLocator::getInstance()->getPlayerService()->getPosition());
        game_window->draw(player_sprite);
    }
}

sf::FloatRect PlayerView::getSpriteBounds() const {
    return player_sprite.getGlobalBounds();
}
