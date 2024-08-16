#include "../../Header/Enemy/Controller/ZapperController.h"
#include "../../Header/Enemy/EnemyModel.h"
#include "../../Header/Enemy/EnemyConfig.h"
#include "../../Header/ServiceLocator/ServiceLocator.h"

namespace Enemy {
    namespace Controller {
        ZapperController::ZapperController() : vertical_travel_distance(100.f) {
            enemy_model = new EnemyModel();
        }

        ZapperController::~ZapperController() {
            delete enemy_model;
        }

        void ZapperController::initialize() {
            EnemyController::initialize();
        }

        void ZapperController::move(float deltaTime) {
            switch (enemy_model->getMovementDirection()) {
            case EnemyConfig::EnemyDirection::LEFT:
                moveLeft();
                break;
            case EnemyConfig::EnemyDirection::RIGHT:
                moveRight();
                break;
            case EnemyConfig::EnemyDirection::DOWN:
                moveDown();
                break;
            default:
                break;
            }
        }

        void ZapperController::moveLeft() {
            sf::Vector2f currentPosition = enemy_model->getPosition();
            currentPosition.x -= vertical_travel_distance * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

            if (currentPosition.x <= enemy_model->getLeftMostPosition().x) {
                enemy_model->setMovementDirection(EnemyConfig::EnemyDirection::DOWN);
                enemy_model->setReferencePosition(currentPosition);
            }
            else {
                enemy_model->setPosition(currentPosition);
            }
        }

        void ZapperController::moveRight() {
            sf::Vector2f currentPosition = enemy_model->getPosition();
            currentPosition.x += vertical_travel_distance * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

            if (currentPosition.x >= enemy_model->getRightMostPosition().x) {
                enemy_model->setMovementDirection(EnemyConfig::EnemyDirection::DOWN);
                enemy_model->setReferencePosition(currentPosition);
            }
            else {
                enemy_model->setPosition(currentPosition);
            }
        }

        void ZapperController::moveDown() {
            sf::Vector2f currentPosition = enemy_model->getPosition();
            currentPosition.y += vertical_travel_distance * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

            if (currentPosition.y >= enemy_model->getReferencePosition().y + vertical_travel_distance) {
                if (enemy_model->getReferencePosition().x <= enemy_model->getLeftMostPosition().x) {
                    enemy_model->setMovementDirection(EnemyConfig::EnemyDirection::RIGHT);
                }
                else {
                    enemy_model->setMovementDirection(EnemyConfig::EnemyDirection::LEFT);
                }
            }
            else {
                enemy_model->setPosition(currentPosition);
            }
        }
    }
}
