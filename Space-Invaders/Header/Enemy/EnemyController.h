#pragma once

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
        virtual void move(float deltaTime) = 0;  // Abstract method
        void update();
        void render(sf::RenderWindow& window);

        sf::Vector2f getEnemyPosition() const;
        float getVerticalSpeed() const;
        void setVerticalSpeed(float speed);
        float getHorizontalSpeed() const;
        void setHorizontalSpeed(float speed);
        EnemyConfig::EnemyType getEnemyType() const;

    protected:
        EnemyModel* enemy_model;
        EnemyView* view;

        virtual sf::Vector2f getRandomInitialPosition();
        virtual void handleOutOfBounds();
    };
}
