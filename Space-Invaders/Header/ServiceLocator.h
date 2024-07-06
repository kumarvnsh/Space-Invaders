#pragma once

#include "GraphicService.h"
#include "EventService.h"
#include "PlayerService.h"

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

    // Singleton instance
    static ServiceLocator* instance;
};
