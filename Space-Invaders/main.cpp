#include <SFML/Graphics.hpp>
#include "../../Header/ServiceLocator/ServiceLocator.h"

int main() {
    // Initialize service locator
    ServiceLocator* serviceLocator = ServiceLocator::getInstance();
    serviceLocator->initialize();

    // Get the game window
    sf::RenderWindow* gameWindow = serviceLocator->getGraphicService()->getGameWindow();
    //gameWindow->setFramerateLimit(60);  // Limit frame rate to 60 FPS

    while (gameWindow->isOpen()) {
        // Process events
        serviceLocator->getEventService()->processEvents();

        // Update game state
        serviceLocator->getEventService()->update();
        serviceLocator->getTimeService()->update();  // Update delta time
        float deltaTime = serviceLocator->getTimeService()->getDeltaTime();
        serviceLocator->getGameService()->update(deltaTime);

        // Clear window
        gameWindow->clear();

        // Render
        serviceLocator->render();

        // Display the back buffer
        gameWindow->display();
    }

    serviceLocator->destroy();
    return 0;
}
