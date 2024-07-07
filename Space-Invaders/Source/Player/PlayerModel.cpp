#include "../../Header/Player/PlayerModel.h"

const float PlayerModel::LEFT_BOUNDARY = 25.0f;
const float PlayerModel::RIGHT_BOUNDARY = 725.0f;

PlayerModel::PlayerModel() {
    initialize();
}

PlayerModel::~PlayerModel() = default;

void PlayerModel::initialize() {
    reset();
}

void PlayerModel::reset() {
    player_position = initial_player_position;
    player_speed = 350.0f;
    player_state = PlayerState::ALIVE;
}

// Getters and Setters
sf::Vector2f PlayerModel::getPosition() const {
    return player_position;
}

void PlayerModel::setPosition(const sf::Vector2f& position) {
    player_position = position;
}

float PlayerModel::getSpeed() const {
    return player_speed;
}

void PlayerModel::setSpeed(float speed) {
    player_speed = speed;
}

PlayerState PlayerModel::getState() const {
    return player_state;
}

void PlayerModel::setState(PlayerState state) {
    player_state = state;
}
