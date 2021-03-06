#ifndef RACKET_H
#define RACKET_H

#include <SDL2/SDL.h>

#include <string>

enum class State { STANDING, WALKING };

class Racket {
 private:
  SDL_Renderer* renderer_;
  int screen_width_ = 0;
  int screen_height_ = 0;
  int y = 10;
  int min_y_ = 0;
  int max_y_ = 0;
  SDL_Rect boundingBox_;

 public:
  void update();
  Racket(SDL_Renderer* renderer, int screen_width, int screen_height,
         SDL_Rect boundingBox);
  void up();
  void down();
  SDL_Rect getBoundingBox();
};

#endif