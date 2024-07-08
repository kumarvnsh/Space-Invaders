#ifndef ENEMY_CONTROLLER_H
#define ENEMY_CONTROLLER_H

#include <SFML/Graphics.hpp>

namespace Enemy {
    class EnemyView;
    class EnemyModel;

    class EnemyController {
    public:
        EnemyController();
        ~EnemyController();

        void initialize();
        void update();
        void render(sf::RenderWindow& window);

        sf::Vector2f getEnemyPosition() const;

    private:
        EnemyModel* model;
        EnemyView* view;

        void move();
        void moveLeft();
        void moveRight();
        void moveDown();
    };
}

#endif // ENEMY_CONTROLLER_H
