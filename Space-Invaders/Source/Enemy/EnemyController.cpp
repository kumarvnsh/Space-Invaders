#include "../../Header/Enemy/EnemyController.h"
#include "../../Header/Enemy/EnemyModel.h"
#include "../../Header/Enemy/EnemyView.h"
#include "../../Header/ServiceLocator/ServiceLocator.h"

namespace Enemy {
    EnemyController::EnemyController() {
        model = new EnemyModel();
        view = new EnemyView(this);
    }

    EnemyController::~EnemyController() {
        delete model;
        delete view;
    }

    void EnemyController::initialize() {
        model->initialize();
        view->initialize();
    }

    void EnemyController::update() {
        move();
        view->update();
    }

    void EnemyController::render(sf::RenderWindow& window) {
        view->render(window);
    }

    sf::Vector2f EnemyController::getEnemyPosition() const {
        return model->getEnemyPosition();
    }

    void EnemyController::move() {
        switch (model->getMovementDirection()) {
        case MovementDirection::LEFT:
            moveLeft();
            break;
        case MovementDirection::RIGHT:
            moveRight();
            break;
        case MovementDirection::DOWN:
            moveDown();
            break;
        }
    }

    void EnemyController::moveLeft() {
        sf::Vector2f currentPosition = model->getEnemyPosition();
        currentPosition.x -= model->getEnemyMovementSpeed() * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

        if (currentPosition.x <= model->getLeftMostPosition().x) {
            model->setMovementDirection(MovementDirection::DOWN);
            model->setReferencePosition(currentPosition);
        }
        else {
            model->setEnemyPosition(currentPosition);
        }
    }

    void EnemyController::moveRight() {
        sf::Vector2f currentPosition = model->getEnemyPosition();
        currentPosition.x += model->getEnemyMovementSpeed() *ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

        if (currentPosition.x >= model->getRightMostPosition().x) {
            model->setMovementDirection(MovementDirection::DOWN);
            model->setReferencePosition(currentPosition);
        }
        else {
            model->setEnemyPosition(currentPosition);
        }
    }

    void EnemyController::moveDown() {
        sf::Vector2f currentPosition = model->getEnemyPosition();
        currentPosition.y += model->getEnemyMovementSpeed() * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

        if (currentPosition.y >= model->getReferencePosition().y + model->getVerticalTravelDistance()) {
            if (model->getReferencePosition().x <= model->getLeftMostPosition().x) {
                model->setMovementDirection(MovementDirection::RIGHT);
            }
            else {
                model->setMovementDirection(MovementDirection::LEFT);
            }
        }
        else {
            model->setEnemyPosition(currentPosition);
        }
    }
}
