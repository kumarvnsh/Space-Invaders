// EnemyModel.cpp
#include "../../Header/Enemy/EnemyModel.h"

namespace Enemy {
    EnemyModel::EnemyModel() : referencePosition(0, 0), enemyPosition(0, 0) {}

    void EnemyModel::initialize() {
        enemyPosition = referencePosition;
    }

    void EnemyModel::setPosition(const sf::Vector2f& position) {
        enemyPosition = position;
    }

    sf::Vector2f EnemyModel::getPosition() const {
        return enemyPosition;
    }
}
