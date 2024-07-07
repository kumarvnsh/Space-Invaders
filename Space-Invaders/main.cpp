#include "Header/ServiceLocator/ServiceLocator.h"

int main() {
    ServiceLocator::getInstance()->initialize();
    ServiceLocator::getInstance()->Ignite();

    sf::RenderWindow* game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();

    while (game_window->isOpen()) {
        ServiceLocator::getInstance()->getEventService()->processEvents();
        ServiceLocator::getInstance()->getGameService()->update();
        ServiceLocator::getInstance()->render();
    }

    ServiceLocator::getInstance()->destroy();
    return 0;
}
