// EnemyController.h
#ifndef ENEMY_CONTROLLER_H
#define ENEMY_CONTROLLER_H

#include "EnemyModel.h"
#include "EnemyView.h"

namespace Enemy {
    class EnemyController {
    public:
        EnemyController();
        ~EnemyController();

        void initialize();
        sf::Vector2f getPosition() const;

        void render(sf::RenderWindow& window); // Add render method here

    private:
        EnemyModel* model;
        EnemyView* view;
    };
}

#endif // ENEMY_CONTROLLER_H
