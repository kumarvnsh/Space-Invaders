// EnemyController.cpp
#include "../../Header/Enemy/EnemyController.h"
#include "../../Header/Enemy/EnemyModel.h"
#include "../../Header/Enemy/EnemyView.h"

namespace Enemy {
    EnemyController::EnemyController() : model(new EnemyModel()), view(new EnemyView(this)) {}

    EnemyController::~EnemyController() {
        delete model;
        delete view;
    }

    void EnemyController::initialize() {
        model->initialize();
        view->initialize();
    }

    sf::Vector2f EnemyController::getPosition() const {
        return model->getPosition();
    }

    void EnemyController::render(sf::RenderWindow& window) {
        view->render(window);
    }
}
