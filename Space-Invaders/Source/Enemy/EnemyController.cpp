
#include "../../Header/ServiceLocator/ServiceLocator.h"
#include "../../header/Enemy/EnemyController.h"

namespace Enemy {
    EnemyController::EnemyController(EnemyModel* model, EnemyView* view)
        : enemy_model(model ? model : new EnemyModel(EnemyConfig::EnemyType::GRUNT)),
        view(view ? view : new EnemyView(this)) {}

    EnemyController::~EnemyController() {
        delete enemy_model;
        delete view;
    }

    void EnemyController::initialize() {
        enemy_model->setPosition(getRandomInitialPosition());
    }

    void EnemyController::update() {
        move(ServiceLocator::getInstance()->getTimeService()->getDeltaTime());
        view->update();
    }

    void EnemyController::render(sf::RenderWindow& window) {
        view->render();
    }

    sf::Vector2f EnemyController::getEnemyPosition() const {
        return enemy_model->getPosition();
    }

    float EnemyController::getVerticalSpeed() const {
        return enemy_model->getMovementSpeed();
    }

    void EnemyController::setVerticalSpeed(float speed) {
        // Implement setting vertical speed
    }

    float EnemyController::getHorizontalSpeed() const {
        return enemy_model->getMovementSpeed();
    }

    void EnemyController::setHorizontalSpeed(float speed) {
        // Implement setting horizontal speed
    }

    sf::Vector2f EnemyController::getRandomInitialPosition() {
        // Example logic for random position
        return sf::Vector2f(rand() % 800, rand() % 600);
    }

    void EnemyController::handleOutOfBounds() {
        sf::Vector2f position = enemy_model->getPosition();
        if (position.x < 0 || position.x > enemy_model->getScreenDimensions().x ||
            position.y < 0 || position.y > enemy_model->getScreenDimensions().y) {
            enemy_model->setPosition(getRandomInitialPosition());
        }
    }

    EnemyConfig::EnemyType EnemyController::getEnemyType() const {
        return enemy_model->getEnemyType();
    }
}
