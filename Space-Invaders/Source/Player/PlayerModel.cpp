#include "../../Header/Player/PlayerModel.h"

PlayerModel::PlayerModel()
    : player_movement_speed(350.0f) {
    reset();
}

PlayerModel::~PlayerModel() {}

void PlayerModel::reset() {
    player_position = initial_player_position;
    player_state = PlayerState::ALIVE;
}

sf::Vector2f PlayerModel::getPosition() const {
    return player_position;
}

void PlayerModel::setPosition(const sf::Vector2f& position) {
    player_position = position;
}

float PlayerModel::getMovementSpeed() const {
    return player_movement_speed;
}

PlayerModel::PlayerState PlayerModel::getPlayerState() const {
    return player_state;
}

void PlayerModel::setPlayerState(PlayerState state) {
    player_state = state;
}

void PlayerModel::setScreenDimensions(const sf::Vector2u& dimensions) {
    screen_dimensions = dimensions;
    initial_player_position = sf::Vector2f(dimensions.x / 2.0f, dimensions.y - 120.0f); // Adjusted for bottom middle position
}

sf::Vector2u PlayerModel::getScreenDimensions() const {
    return screen_dimensions;
}

void PlayerModel::setInitialPosition(const sf::Vector2f& position) {
    initial_player_position = position;
}
