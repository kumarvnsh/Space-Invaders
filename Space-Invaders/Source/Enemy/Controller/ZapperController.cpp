#include "../../Header/Enemy/Controller/ZapperController.h"

namespace Enemy
{

	namespace Controller
	{
		ZapperController::ZapperController() { }

		ZapperController::~ZapperController() { }

		void ZapperController::initialize()
		{
			EnemyController::initialize();;
		}

		void ZapperController::move(float deltaTime) {
			// Your custom move logic
		}


		void ZapperController::moveLeft()
		{
		}

		void ZapperController::moveRight()
		{
		}

		void ZapperController::moveDown()
		{
		}
	}
}