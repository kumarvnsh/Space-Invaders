#include "Header/ServiceLocator/ServiceLocator.h"
#include "Header/TimeService/TimeService.h"
#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
    ServiceLocator::getInstance()->initialize();
    ServiceLocator::getInstance()->Ignite();

    sf::RenderWindow* game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
    TimeService timeService;
    timeService.initialize();

    while (game_window->isOpen()) {
        ServiceLocator::getInstance()->getEventService()->processEvents();
        timeService.update();

        float deltaTime = timeService.getDeltaTime();
        ServiceLocator::getInstance()->getGameService()->update(deltaTime);

        game_window->clear(); // Clear the window
        ServiceLocator::getInstance()->getGameService()->render(); // Render game state
        game_window->display(); // Display the window
    }

    ServiceLocator::getInstance()->destroy();
    return 0;
}
