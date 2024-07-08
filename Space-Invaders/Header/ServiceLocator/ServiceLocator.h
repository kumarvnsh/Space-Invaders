// ServiceLocator.h

#pragma once

#include "../GraphicService/GraphicService.h"
#include "../GameService/GameService.h"
#include "../EventService/EventService.h"
#include "../UIService/UIService.h"
#include "../Player/PlayerService.h"
#include "../TimeService/TimeService.h"

class ServiceLocator {
public:
    static ServiceLocator* getInstance();
    void initialize();
    void destroy();
    void render();
    void Ignite();

    GraphicService* getGraphicService();
    GameService* getGameService();
    Event::EventService* getEventService();
    UIService* getUIService();
    PlayerService* getPlayerService();
    TimeService* getTimeService(); // Add this line

private:
    ServiceLocator();
    ~ServiceLocator();
    static ServiceLocator* instance;

    GraphicService* graphic_service;
    GameService* game_service;
    Event::EventService* event_service;
    UIService* ui_service;
    PlayerService* player_service;
    TimeService* time_service; // Add this line
};
