#ifndef ENEMY_CONTROLLER_H
#define ENEMY_CONTROLLER_H

#include <SFML/Graphics.hpp>
#include "EnemyModel.h"
#include "EnemyView.h"
#include "EnemyConfig.h"

namespace Enemy {

    class EnemyController {
    public:
        EnemyController(EnemyModel* model = nullptr, EnemyView* view = nullptr);
        virtual ~EnemyController();

        virtual void initialize();
        virtual void move(float deltaTime);
        void update();
        void render(sf::RenderWindow& window);

        sf::Vector2f getEnemyPosition() const;

        float getVerticalSpeed() const;
        void setVerticalSpeed(float speed);

        float getHorizontalSpeed() const;
        void setHorizontalSpeed(float speed);

    protected:
        virtual sf::Vector2f getRandomInitialPosition();
        virtual void handleOutOfBounds();

    private:
        EnemyModel* model;
        EnemyView* view;

        float vertical_speed;
        float horizontal_speed;

        void move();

        void moveLeft();
        void moveRight();
        void moveDown();
    };

} // namespace Enemy

#endif // ENEMY_CONTROLLER_H
