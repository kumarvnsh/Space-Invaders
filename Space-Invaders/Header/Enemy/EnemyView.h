#ifndef ENEMY_VIEW_H
#define ENEMY_VIEW_H

#include <SFML/Graphics.hpp>

namespace Enemy {
    class EnemyController;

    class EnemyView {
    public:
        EnemyView(EnemyController* controller);
        ~EnemyView();

        void initialize();
        void render(sf::RenderWindow& window);
        void update();

    private:
        EnemyController* controller;
        sf::Texture texture;
        sf::Sprite sprite;
        std::string texturePath;
        float width, height;

        void loadTexture();
        void initializeSprite();
        void scaleSprite();
    };
}

#endif // ENEMY_VIEW_H
