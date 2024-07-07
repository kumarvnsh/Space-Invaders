#pragma once

#include <chrono>

class TimeService {
private:
    std::chrono::time_point<std::chrono::steady_clock> previous_time;
    float delta_time;

    void updateDeltaTime();
    float calculateDeltaTime();
    void updatePreviousTime();

public:
    // Constructor and Destructor
    TimeService() = default;
    ~TimeService() = default;

    // Public methods
    void initialize();
    void update();
    float getDeltaTime();
};
