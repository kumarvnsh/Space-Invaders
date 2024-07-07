#pragma once

#include <SFML/Graphics.hpp>

class PlayerModel {
public:
    PlayerModel();
    ~PlayerModel();

    void reset();
    sf::Vector2f getPosition() const;
    void setPosition(const sf::Vector2f& position);
    float getMovementSpeed() const;

    enum class PlayerState {
        ALIVE,
        DEAD
    };

    PlayerState getPlayerState() const;
    void setPlayerState(PlayerState state);

    const static sf::Vector2f initial_player_position;
    const static sf::Vector2f left_most_position;
    const static sf::Vector2f right_most_position;
    const static float player_movement_speed;

private:
    sf::Vector2f player_position;
    PlayerState player_state;
};
