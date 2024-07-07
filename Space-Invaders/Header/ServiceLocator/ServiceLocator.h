#pragma once

#include "../GraphicService/GraphicService.h"
#include "../EventService/EventService.h"
#include "../Player/PlayerService.h"
#include "../TimeService/TimeService.h"
#include "../GameService/GameService.h"

class ServiceLocator {
public:
    // Public methods
    static ServiceLocator* getInstance();
    void initialize(sf::RenderWindow* window);
    void update();
    void render();
    EventService* getEventService();
    GraphicService* getGraphicService();
    PlayerService* getPlayerService();
    TimeService* getTimeService();
    GameService* getGameService();
    void clearAllServices();

private:
    // Private methods
    ServiceLocator(); // Constructor
    ~ServiceLocator(); // Destructor
    void createServices();

    // Private properties
    GraphicService* graphicService;
    EventService* eventService;
    PlayerService* playerService;
    TimeService* timeService;
    GameService* gameService;

    // Singleton instance
    static ServiceLocator* instance;
};
