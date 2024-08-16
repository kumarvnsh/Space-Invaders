#include "../../Header/Enemy/Controller/SubzeroController.h"
#include "../../Header/Enemy/EnemyModel.h"
#include "../../Header/Enemy/EnemyConfig.h"
#include "../../Header/ServiceLocator/ServiceLocator.h"

namespace Enemy {
    namespace Controller {
        SubzeroController::SubzeroController() {
            enemy_model = new EnemyModel();
        }

        SubzeroController::~SubzeroController() {
            delete enemy_model;
        }

        void SubzeroController::initialize() {
            EnemyController::initialize();
            enemy_model->setMovementDirection(EnemyConfig::EnemyDirection::DOWN);
        }

        void SubzeroController::move(float deltaTime) {
            if (enemy_model->getMovementDirection() == EnemyConfig::EnemyDirection::DOWN) {
                moveDown();
            }
        }

        void SubzeroController::moveDown() {
            sf::Vector2f currentPosition = enemy_model->getPosition();
            currentPosition.y += vertical_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
            enemy_model->setPosition(currentPosition);
        }
    }
}
