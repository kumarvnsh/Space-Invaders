#include <SFML/Graphics.hpp>
#include <iostream>

#include "Header/GraphicService.h"
#include "Header/GameService.h"



int main() {
    GameService* game_service = new GameService();
    game_service->Ignite();

    while (game_service->isRunning()) {
        game_service->update();
        game_service->render();
    }

    delete game_service;
    return 0;
}
