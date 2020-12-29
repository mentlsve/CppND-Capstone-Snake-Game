#include "Racket.h"

#include <SDL2/SDL_image.h>
#include <stdio.h>

Racket::Racket(SDL_Renderer* renderer, int screen_width, int screen_height) {
  renderer_ = renderer;
  screen_width_ = screen_width;
  screen_height_ = screen_height;
  min_y_ = 10;
  max_y_ = screen_height - 10;
  printf("%d\n", min_y_);
  printf("%d\n", max_y_);
}

void Racket::update() {
  SDL_Rect fillRect2 = {10, y, 10, 10};
  SDL_SetRenderDrawColor(renderer_, 0xFF, 0x00, 0x00, 0xFF);
  SDL_RenderFillRect(renderer_, &fillRect2);
}

void Racket::up() {
  if (y >= min_y_) y--;
}
void Racket::down() {
  if (y <= max_y_) y++;
}