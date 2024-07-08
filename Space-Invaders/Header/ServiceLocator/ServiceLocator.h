#pragma once

#include "../GraphicService/GraphicService.h"
#include "../GameService/GameService.h"
#include "../EventService/EventService.h"
#include "../UIService/UIService.h"
#include "../Player/PlayerService.h"
#include "../TimeService/TimeService.h"
#include "../Enemy/EnemyService.h"

class ServiceLocator {
public:
    static ServiceLocator* getInstance();
    static Enemy::EnemyService* getEnemyService();
    void initialize();
    void destroy();
    void render();
    void Ignite();

    GraphicService* getGraphicService();
    GameService* getGameService();
    Event::EventService* getEventService();
    UIService* getUIService();
    PlayerService* getPlayerService();
    TimeService* getTimeService();

private:
    ServiceLocator();
    ~ServiceLocator();
    static ServiceLocator* instance;
    static Enemy::EnemyService* enemyService;

    GraphicService* graphic_service;
    GameService* game_service;
    Event::EventService* event_service;
    UIService* ui_service;
    PlayerService* player_service;
    TimeService* time_service;
};


