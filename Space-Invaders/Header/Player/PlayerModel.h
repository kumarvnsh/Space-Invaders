#pragma once

#include <SFML/Graphics.hpp>

class PlayerModel {
public:
    enum class PlayerState {
        ALIVE,
        DEAD
    };

    PlayerModel();
    ~PlayerModel();

    void reset();
    sf::Vector2f getPosition() const;
    void setPosition(const sf::Vector2f& position);
    float getMovementSpeed() const;
    PlayerState getPlayerState() const;
    void setPlayerState(PlayerState state);
    void setScreenDimensions(const sf::Vector2u& dimensions);
    sf::Vector2u getScreenDimensions() const;
    void setInitialPosition(const sf::Vector2f& position);

private:
    sf::Vector2f player_position;
    sf::Vector2f initial_player_position;
    const float player_movement_speed;
    PlayerState player_state;
    sf::Vector2u screen_dimensions;
};
