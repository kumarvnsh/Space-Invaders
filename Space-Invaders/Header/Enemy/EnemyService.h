#pragma once

#include <vector>
#include <SFML/Graphics.hpp>

namespace Enemy {
    class EnemyController;

    class EnemyService {
    public:
        EnemyService();
        ~EnemyService();

        void initialize();
        void update();
        void render(sf::RenderWindow& window);

        //void spawnEnemy();

    private:
        std::vector<EnemyController*> enemyList;
        const float spawnInterval = 3.0f;
        float spawnTimer;

        //void updateSpawnTimer();
        //void processEnemySpawn();
        void destroy();
    };
}

