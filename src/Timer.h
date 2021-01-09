#ifndef TIMER_H
#define TIMER_H

#include <SDL2/SDL.h>

class Timer {
 private:
  int ticks = 0;

 public:
  void start();
  size_t getTicks();
};

#endif