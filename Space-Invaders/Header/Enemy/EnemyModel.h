#ifndef ENEMY_MODEL_H
#define ENEMY_MODEL_H

#include <SFML/Graphics.hpp>

namespace Enemy {
    enum class MovementDirection {
        LEFT,
        RIGHT,
        DOWN,
    };

    class EnemyModel {
    public:
        EnemyModel();

        void initialize();
        sf::Vector2f getEnemyPosition() const;
        void setEnemyPosition(const sf::Vector2f& position);

        sf::Vector2f getReferencePosition() const;
        void setReferencePosition(const sf::Vector2f& position);

        MovementDirection getMovementDirection() const;
        void setMovementDirection(MovementDirection direction);

        // Provide public getters for private members
        const sf::Vector2f& getLeftMostPosition() const;
        const sf::Vector2f& getRightMostPosition() const;
        float getVerticalTravelDistance() const;
        float getEnemyMovementSpeed() const;

    private:
        sf::Vector2f referencePosition;
        sf::Vector2f enemyPosition;
        MovementDirection movementDirection;

        const sf::Vector2f leftMostPosition = sf::Vector2f(50.f, 950.f);
        const sf::Vector2f rightMostPosition = sf::Vector2f(1800.f, 950.f);
        const float verticalTravelDistance = 100.f;
        const float enemyMovementSpeed = 250.0f;
    };
}

#endif // ENEMY_MODEL_H
