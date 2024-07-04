#pragma once

#include "GraphicService.h"

class ServiceLocator {
public:
    // Public methods
    static ServiceLocator* getInstance();
    void initialize();
    void update();
    void render();
    GraphicService* getGraphicService();
    void clearAllServices();

private:
    // Private methods
    ServiceLocator(); // Constructor
    ~ServiceLocator(); // Destructor
    void createServices();

    // Private properties
    GraphicService* graphicService;

    // Singleton instance
    static ServiceLocator* instance;
};
