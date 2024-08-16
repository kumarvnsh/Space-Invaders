#include "../../Header/Enemy/Controller/SubzeroController.h"

namespace Enemy
{
    namespace Controller
    {
        SubzeroController::SubzeroController()
            : vertical_movement_speed(100.f) { }

        SubzeroController::~SubzeroController() { }

        void SubzeroController::initialize()
        {
            EnemyController::initialize();
            // Additional initialization for SubzeroController if needed
        }

        void SubzeroController::move(float deltaTime)
        {
            // Custom movement logic for SubzeroController
            moveDown();
        }

        void SubzeroController::moveDown()
        {
            // Logic for moving down
            sf::Vector2f currentPosition = getEnemyPosition();
            currentPosition.y += vertical_movement_speed * deltaTime;
            setEnemyPosition(currentPosition);
        }
    }
}
