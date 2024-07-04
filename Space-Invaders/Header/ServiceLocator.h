#pragma once

#include "GraphicService.h"
#include "EventService.h"

class ServiceLocator {
public:
    // Public methods
    static ServiceLocator* getInstance();
    void initialize();
    void update();
    void render();
    EventService* getEventService();
    GraphicService* getGraphicService();
    void clearAllServices();

private:
    // Private methods
    ServiceLocator(); // Constructor
    ~ServiceLocator(); // Destructor
    void createServices();

    // Private properties
    GraphicService* graphicService;
    EventService* eventService;

    // Singleton instance
    static ServiceLocator* instance;
};
