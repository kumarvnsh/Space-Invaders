#pragma once

#include <SFML/Graphics.hpp>

enum class PlayerState {
    ALIVE,
    DEAD
};

class PlayerModel {
public:
    PlayerModel();
    ~PlayerModel();

    void initialize();
    void reset();

    // Getters and Setters
    sf::Vector2f getPosition() const;
    void setPosition(const sf::Vector2f& position);
    float getSpeed() const;
    void setSpeed(float speed);
    PlayerState getState() const;
    void setState(PlayerState state);

    // Constants
    static const float LEFT_BOUNDARY;
    static const float RIGHT_BOUNDARY;

private:
    const sf::Vector2f initial_player_position = sf::Vector2f(500.f, 500.f);
    sf::Vector2f player_position;
    float player_speed;
    PlayerState player_state;
};
