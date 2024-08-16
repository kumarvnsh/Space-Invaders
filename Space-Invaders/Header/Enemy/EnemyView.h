#pragma once

#include <SFML/Graphics.hpp>
#include "EnemyConfig.h"

namespace Enemy {
    class EnemyController;  // Forward declaration of EnemyController

    class EnemyView {
    private:
        EnemyController* enemy_controller;
        sf::RenderWindow* game_window;
        sf::Texture enemy_texture;
        sf::Sprite enemy_sprite;

        const std::string subzero_texture_path = "assets/textures/subzero.png";
        const std::string zapper_texture_path = "assets/textures/zapper.png";
        const float enemy_sprite_width = 60.f;
        const float enemy_sprite_height = 60.f;

        void initializeEnemySprite(EnemyConfig::EnemyType type);
        void scaleEnemySprite();

    public:
        EnemyView(EnemyController* controller);
        ~EnemyView();

        void initialize();
        void update();
        void render();
    };
}
