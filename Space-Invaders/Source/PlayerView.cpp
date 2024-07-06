#include "../Header/PlayerView.h"
#include <iostream>

PlayerView::PlayerView() : game_window(nullptr) {}

PlayerView::~PlayerView() = default;

void PlayerView::initialize(sf::RenderWindow* window) {
    game_window = window;
    initializePlayerSprite();
}

void PlayerView::render() {
    game_window->draw(player_sprite);
}

void PlayerView::setSpritePosition(const sf::Vector2f& position) {
    player_sprite.setPosition(position);
}

void PlayerView::initializePlayerSprite() {
    if (!player_texture.loadFromFile(player_texture_path)) {
        std::cerr << "Error loading player ship texture" << std::endl;
        return;
    }
    player_sprite.setTexture(player_texture);
    scaleSprite();
}

void PlayerView::scaleSprite() {
    sf::Vector2u textureSize = player_texture.getSize();
    player_sprite.setScale(
        static_cast<float>(width) / textureSize.x,
        static_cast<float>(height) / textureSize.y
    );
}
