// EnemyService.cpp
#include "../../Header/Enemy/EnemyService.h"
#include "../../Header/Enemy/EnemyController.h"
#include "../../Header/ServiceLocator/ServiceLocator.h"
#include "../../Header/TimeService/TimeService.h"

namespace Enemy {

    EnemyService::EnemyService() : spawnTimer(0.0f) {}

    EnemyService::~EnemyService() {
        destroy();
    }

    void EnemyService::initialize() {
        spawnTimer = spawnInterval;  // Immediate first spawn
    }

    void EnemyService::update() {
        // Check if the game state is GAMEPLAY before updating
        if (ServiceLocator::getInstance()->getGameService()->getCurrentState() != GameService::GameState::GAMEPLAY) {
            return;
        }

        /*updateSpawnTimer();
        processEnemySpawn();*/

        for (EnemyController* enemy : enemyList) {
            enemy->update();
        }
    }

    void EnemyService::render(sf::RenderWindow& window) {
        for (EnemyController* enemy : enemyList) {
            enemy->render(window);
        }
    }

    //void EnemyService::updateSpawnTimer() {
    //    spawnTimer += ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
    //}

    //void EnemyService::processEnemySpawn() {
    //    if (spawnTimer >= spawnInterval) {
    //        spawnEnemy();
    //        spawnTimer = 0.0f;  // Reset timer
    //    }
    //}

    /*void EnemyService::spawnEnemy() {
        EnemyController* enemyController = new EnemyController();
        enemyController->initialize();
        enemyList.push_back(enemyController);
    }*/

    void EnemyService::destroy() {
        for (EnemyController* enemy : enemyList) {
            delete enemy;
        }
        enemyList.clear();
    }
}
