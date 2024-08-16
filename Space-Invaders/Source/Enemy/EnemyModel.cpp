#include "../../Header/Enemy/EnemyModel.h"
#include "../../Header/Enemy/EnemyConfig.h"


namespace Enemy {

    EnemyModel::EnemyModel() : movementSpeed(200.0f), enemyType(EnemyConfig::EnemyType::GRUNT), movementDirection(EnemyConfig::EnemyDirection::RIGHT) {
        reset();
    }

    EnemyModel::EnemyModel(EnemyConfig::EnemyType type)
        : movementSpeed(200.0f), enemyType(type), movementDirection(EnemyConfig::EnemyDirection::RIGHT) {
        reset();
    }

    void EnemyModel::reset() {
        // Reset logic, e.g., resetting position or state
        enemyPosition = sf::Vector2f(0, 0);
        movementDirection = EnemyConfig::EnemyDirection::RIGHT;
        enemyState = EnemyConfig::EnemyState::PATROLLING;
    }

    void EnemyModel::initialize() {
        movementDirection = EnemyConfig::EnemyDirection::RIGHT;
        enemyPosition = referencePosition;
        enemyState = EnemyConfig::EnemyState::PATROLLING;
    }

    sf::Vector2f EnemyModel::getPosition() const {
        return enemyPosition;
    }

    void EnemyModel::setPosition(const sf::Vector2f& position) {
        enemyPosition = position;
    }

    sf::Vector2f EnemyModel::getReferencePosition() const {
        return referencePosition;
    }

    void EnemyModel::setReferencePosition(const sf::Vector2f& position) {
        referencePosition = position;
    }

    EnemyConfig::EnemyDirection EnemyModel::getMovementDirection() const {
        return movementDirection;
    }

    void EnemyModel::setMovementDirection(EnemyConfig::EnemyDirection direction) {
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

    float EnemyModel::getMovementSpeed() const {
        return movementSpeed;
    }

    EnemyConfig::EnemyState EnemyModel::getEnemyState() const {
        return enemyState;
    }

    void EnemyModel::setEnemyState(EnemyConfig::EnemyState state) {
        enemyState = state;
    }

    EnemyConfig::EnemyType EnemyModel::getEnemyType() const {
        return enemyType;
    }

    void EnemyModel::setEnemyType(EnemyConfig::EnemyType type) {
        enemyType = type;
    }

    void EnemyModel::setScreenDimensions(const sf::Vector2u& dimensions) {
        screenDimensions = dimensions;
    }

    sf::Vector2u EnemyModel::getScreenDimensions() const {
        return screenDimensions;
    }
}