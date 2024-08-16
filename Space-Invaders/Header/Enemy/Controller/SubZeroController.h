#pragma once
#include "../../header/Enemy/EnemyController.h"

namespace Enemy
{
    namespace Controller
    {
        class SubzeroController : public EnemyController
        {
        private:
            float vertical_movement_speed = 100.f;  // Default movement speed

            void move(float deltaTime) override;  // Override the base move() method
            void moveDown();  // Method to specify downward movement

        public:
            SubzeroController();
            ~SubzeroController();

            void initialize() override;  // Override the base initialize() method
        };
    }
}
