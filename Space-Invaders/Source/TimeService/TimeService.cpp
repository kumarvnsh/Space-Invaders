#include "../../Header/TimeService/TimeService.h"

TimeService::TimeService() : delta_time(0.0f) {}

TimeService::~TimeService() {}

void TimeService::initialize() {
    previous_time = std::chrono::steady_clock::now();
}

void TimeService::update() {
    updateDeltaTime();
}

float TimeService::getDeltaTime() const {
    return delta_time;
}

void TimeService::updateDeltaTime() {
    delta_time = calculateDeltaTime();
    updatePreviousTime();
}

float TimeService::calculateDeltaTime() {
    auto current_time = std::chrono::steady_clock::now();
    std::chrono::duration<float> elapsed_time = current_time - previous_time;
    return elapsed_time.count();
}

void TimeService::updatePreviousTime() {
    previous_time = std::chrono::steady_clock::now();
}
