// EnemyService.h
#ifndef ENEMY_SERVICE_H
#define ENEMY_SERVICE_H

namespace Enemy {
    class EnemyController; // Forward declaration

    class EnemyService {
    public:
        EnemyService();
        ~EnemyService();

        void initialize();
        void destroy();
        EnemyController* spawnEnemy();

    private:
        EnemyController* enemyController;
    };
}

#endif // ENEMY_SERVICE_H
