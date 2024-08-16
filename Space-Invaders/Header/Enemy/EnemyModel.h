#ifndef ENEMY_MODEL_H
#define ENEMY_MODEL_H

#include <SFML/Graphics.hpp>
#include "EnemyConfig.h"

namespace Enemy {

    class EnemyModel {
    public:
        EnemyModel();
        EnemyModel(EnemyConfig::EnemyType type);

        void initialize();
        void reset();
        sf::Vector2f getPosition() const;
        void setPosition(const sf::Vector2f& position);

        sf::Vector2f getReferencePosition() const;
        void setReferencePosition(const sf::Vector2f& position);

        EnemyConfig::EnemyDirection getMovementDirection() const;
        void setMovementDirection(EnemyConfig::EnemyDirection direction);

        const sf::Vector2f& getLeftMostPosition() const;
        const sf::Vector2f& getRightMostPosition() const;
        float getVerticalTravelDistance() const;
        float getMovementSpeed() const;

        EnemyConfig::EnemyState getEnemyState() const;
        void setEnemyState(EnemyConfig::EnemyState state);

        EnemyConfig::EnemyType getEnemyType() const;
        void setEnemyType(EnemyConfig::EnemyType type);

        void setScreenDimensions(const sf::Vector2u& dimensions);
        sf::Vector2u getScreenDimensions() const;

    private:
        sf::Vector2f referencePosition;
        sf::Vector2f enemyPosition;
        EnemyConfig::EnemyDirection movementDirection;

        const sf::Vector2f leftMostPosition = sf::Vector2f(50.f, 950.f);
        const sf::Vector2f rightMostPosition = sf::Vector2f(1800.f, 950.f);
        const float verticalTravelDistance = 100.f;
        const float movementSpeed = 250.0f;

        EnemyConfig::EnemyState enemyState;
        EnemyConfig::EnemyType enemyType;
        sf::Vector2u screenDimensions;
    };

}

#endif // ENEMY_MODEL_H
