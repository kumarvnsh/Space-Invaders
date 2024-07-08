// EnemyService.cpp
#include "../../Header/Enemy/EnemyService.h"
#include "../../Header/Enemy/EnemyController.h"

namespace Enemy {
    EnemyService::EnemyService() : enemyController(nullptr) {}

    EnemyService::~EnemyService() {
        destroy();
    }

    void EnemyService::initialize() {
        enemyController = spawnEnemy();
    }

    void EnemyService::destroy() {
        if (enemyController) {
            delete enemyController;
            enemyController = nullptr;
        }
    }

    EnemyController* EnemyService::spawnEnemy() {
        return new EnemyController();
    }
}
