#include "Timer.h"

void Timer::start() { ticks = SDL_GetTicks(); }
size_t Timer::getTicks() { return (size_t)(SDL_GetTicks() - ticks); }