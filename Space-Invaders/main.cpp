#include <SFML/Graphics.hpp>
#include "Header/GameService/GameService.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Game");

    GameService gameService;
    gameService.Ignite(&window);

    sf::Clock clock;
    while (gameService.isRunning()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        float deltaTime = clock.restart().asSeconds();

        gameService.update();
        window.clear();
        gameService.render();
        window.display();
    }

    return 0;
}
