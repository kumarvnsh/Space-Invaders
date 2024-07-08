#include <SFML/Graphics.hpp>
#include "../../Header/ServiceLocator/ServiceLocator.h"
#include "../../Header/Enemy/EnemyController.h"  // Include the EnemyController header

int main() {
    // Initialize service locator
    ServiceLocator* serviceLocator = ServiceLocator::getInstance();
    serviceLocator->initialize();

    // Get the game window
    sf::RenderWindow* gameWindow = serviceLocator->getGraphicService()->getGameWindow();
    gameWindow->setVerticalSyncEnabled(true);  // Enable VSync

    // Initialize Enemy Service
    serviceLocator->getEnemyService()->initialize();

    while (gameWindow->isOpen()) {
        // Process events
        sf::Event event;
        while (gameWindow->pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                gameWindow->close();
            }
        }

        // Update game state
        serviceLocator->getEventService()->update();
        serviceLocator->getTimeService()->update();  // Update delta time
        float deltaTime = serviceLocator->getTimeService()->getDeltaTime();
        serviceLocator->getGameService()->update(deltaTime);
        serviceLocator->getEnemyService()->update();

        // Clear window
        gameWindow->clear();

        // Render
        serviceLocator->render();
        serviceLocator->getEnemyService()->spawnEnemy()->render(*gameWindow);

        // Display the back buffer
        gameWindow->display();
    }

    serviceLocator->destroy();
    return 0;
}
