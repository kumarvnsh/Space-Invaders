#include "../../Header/Enemy/EnemyController.h"
#include "../../Header/Enemy/EnemyModel.h"
#include "../../Header/ServiceLocator/ServiceLocator.h"

namespace Enemy {

    EnemyController::EnemyController(EnemyModel* model, EnemyView* view)
        : model(model ? model : new EnemyModel(EnemyConfig::EnemyType::GRUNT)),
        view(view ? view : new EnemyView(this)) {}


    EnemyController::~EnemyController() {
        delete model;
        delete view;
    }

    void EnemyController::initialize() {
        model->setPosition(getRandomInitialPosition());
    }

    void EnemyController::move(float deltaTime) {
        sf::Vector2f position = model->getPosition();
        position.x += horizontal_speed * deltaTime;
        position.y += vertical_speed * deltaTime;
        model->setPosition(position);
        handleOutOfBounds();
    }

    void EnemyController::update() {
        move(ServiceLocator::getInstance()->getTimeService()->getDeltaTime());
        view->update();
    }

    void EnemyController::render(sf::RenderWindow& window) {
        view->render(window);
    }

    sf::Vector2f EnemyController::getEnemyPosition() const {
        return model->getPosition();
    }

    float EnemyController::getVerticalSpeed() const {
        return vertical_speed;
    }

    void EnemyController::setVerticalSpeed(float speed) {
        vertical_speed = speed;
    }

    float EnemyController::getHorizontalSpeed() const {
        return horizontal_speed;
    }

    void EnemyController::setHorizontalSpeed(float speed) {
        horizontal_speed = speed;
    }

    sf::Vector2f EnemyController::getRandomInitialPosition() {
        // Example logic for random position
        return sf::Vector2f(rand() % 800, rand() % 600);
    }

    void EnemyController::handleOutOfBounds() {
        sf::Vector2f position = model->getPosition();
        if (position.x < 0 || position.x > model->getScreenDimensions().x ||
            position.y < 0 || position.y > model->getScreenDimensions().y) {
            model->setPosition(getRandomInitialPosition());
        }
    }

    void EnemyController::moveLeft() {
        sf::Vector2f currentPosition = model->getPosition();
        currentPosition.x -= model->getMovementSpeed() * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
        model->setPosition(currentPosition);
    }

    void EnemyController::moveRight() {
        sf::Vector2f currentPosition = model->getPosition();
        currentPosition.x += model->getMovementSpeed() * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
        model->setPosition(currentPosition);
    }

    void EnemyController::moveDown() {
        sf::Vector2f currentPosition = model->getPosition();
        currentPosition.y += model->getMovementSpeed() * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
        model->setPosition(currentPosition);
    }
}
