#ifndef BALL_H
#define BALL_H

#include <SDL2/SDL.h>

class Ball {
 private:
  SDL_Renderer* renderer_;
  SDL_Rect position = {20, 100, 10, 10};
  SDL_Point direction = {1, 0};
  SDL_Point location = {20, 100};
  float velocity = 0.1;
  const SDL_Rect fieldDimensions_;

 public:
  Ball(SDL_Renderer* renderer, SDL_Rect fieldDimensions);
  void update(std::size_t milliseconds_since_last_ball_hit);
  SDL_Rect getBoundingBox();
  void inverse();
  bool isOutside();
};

#endif