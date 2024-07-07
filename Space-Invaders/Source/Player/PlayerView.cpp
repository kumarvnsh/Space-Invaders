#include "../../Header/Player/PlayerView.h"
#include <iostream>

PlayerView::PlayerView() : game_window(nullptr) {}

PlayerView::~PlayerView() = default;

void PlayerView::initialize(sf::RenderWindow* window) {
    game_window = window;
    initializePlayerSprite();
}

void PlayerView::render() {
    if (game_window) {
        game_window->draw(player_sprite);
    }
}

void PlayerView::initializePlayerSprite() {
    if (!player_texture.loadFromFile("assets/textures/player_ship.png")) {
        std::cerr << "Error loading player ship texture" << std::endl;
        return;
    }
    player_sprite.setTexture(player_texture);
    player_sprite.setScale(0.5f, 0.5f);
}
