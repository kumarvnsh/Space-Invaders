#pragma once

#include "../GraphicService/GraphicService.h"
#include "../GameService/GameService.h"
#include "../EventService/EventService.h"
#include "../UIService/UIService.h"
#include "../Player/PlayerService.h"

class ServiceLocator {
private:
    GraphicService* graphic_service;
    GameService* game_service;
    EventService* event_service;
    UIService* ui_service;
    PlayerService* player_service;

    static ServiceLocator* instance;

public:
    ServiceLocator();
    ~ServiceLocator();

    static ServiceLocator* getInstance();
    void initialize();
    void destroy();
    void render();

    GraphicService* getGraphicService();
    GameService* getGameService();
    EventService* getEventService();
    UIService* getUIService();
    PlayerService* getPlayerService();
    void Ignite();
};
