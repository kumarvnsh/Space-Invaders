#pragma once

#include "GraphicService.h"
#include "EventService.h"
#include "PlayerService.h"
#include "TimeService.h"

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

    // Singleton instance
    static ServiceLocator* instance;
};
