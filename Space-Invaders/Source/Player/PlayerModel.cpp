#include "../../Header/Player/PlayerModel.h"

const sf::Vector2f PlayerModel::initial_player_position = sf::Vector2f(950.f, 950.f);
const sf::Vector2f PlayerModel::left_most_position = sf::Vector2f(50.f, 950.f);
const sf::Vector2f PlayerModel::right_most_position = sf::Vector2f(1800.f, 950.f);
const float PlayerModel::player_movement_speed = 350.0f;

PlayerModel::PlayerModel() {
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
