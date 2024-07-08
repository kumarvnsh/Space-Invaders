// EnemyModel.h
#ifndef ENEMY_MODEL_H
#define ENEMY_MODEL_H
#include <SFML/Graphics.hpp>

namespace Enemy {
    class EnemyModel {
    public:
        EnemyModel();

        void initialize();
        void setPosition(const sf::Vector2f& position);
        sf::Vector2f getPosition() const;

    private:
        sf::Vector2f referencePosition;
        sf::Vector2f enemyPosition;
    };
}

#endif // ENEMY_MODEL_H
