#pragma once

#include "GraphicService.h"
#include "EventService.h"
#include "PlayerService.h"
#include "TimeService.h"

class GraphicService;  // Forward declaration
class EventService;    // Forward declaration
class PlayerService;   // Forward declaration
class TimeService;     // Forward declaration

class ServiceLocator {
public:
    // Public methods
    static ServiceLocator* getInstance();
    void initialize();
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
