#include "../../Header/Enemy/EnemyModel.h"

namespace Enemy {
    EnemyModel::EnemyModel()
        : referencePosition(0, 0), enemyPosition(0, 0), movementDirection(MovementDirection::RIGHT) {}

    void EnemyModel::initialize() {
        movementDirection = MovementDirection::RIGHT;
        enemyPosition = referencePosition;
    }

    sf::Vector2f EnemyModel::getEnemyPosition() const {
        return enemyPosition;
    }

    void EnemyModel::setEnemyPosition(const sf::Vector2f& position) {
        enemyPosition = position;
    }

    sf::Vector2f EnemyModel::getReferencePosition() const {
        return referencePosition;
    }

    void EnemyModel::setReferencePosition(const sf::Vector2f& position) {
        referencePosition = position;
    }

    MovementDirection EnemyModel::getMovementDirection() const {
        return movementDirection;
    }

    void EnemyModel::setMovementDirection(MovementDirection direction) {
        movementDirection = direction;
    }

    const sf::Vector2f& EnemyModel::getLeftMostPosition() const {
        return leftMostPosition;
    }

    const sf::Vector2f& EnemyModel::getRightMostPosition() const {
        return rightMostPosition;
    }

    float EnemyModel::getVerticalTravelDistance() const {
        return verticalTravelDistance;
    }

    float EnemyModel::getEnemyMovementSpeed() const {
        return enemyMovementSpeed;
    }
}
