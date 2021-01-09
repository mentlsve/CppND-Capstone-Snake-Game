#include "Ball.h"

#include <SDL2/SDL_image.h>
#include <stdio.h>

Ball::Ball(SDL_Renderer* renderer, SDL_Rect fieldDimensions)
    : fieldDimensions_(fieldDimensions) {
  renderer_ = renderer;
}

void Ball::update(std::size_t t) {
  position.x = location.x + direction.x * velocity * static_cast<int>(t);
  position.y = location.y + direction.y * velocity * static_cast<int>(t);
  SDL_SetRenderDrawColor(renderer_, 0xFF, 0xAB, 0x00, 0xFF);
  SDL_RenderFillRect(renderer_, &position);
}

SDL_Rect Ball::getBoundingBox() { return position; }

void Ball::inverse() {
  location.x = position.x;
  direction.x = -direction.x;
}

bool Ball::isOutside() {
  if (position.x + position.w >= (fieldDimensions_.x + fieldDimensions_.w) &&
      direction.x > 0)
    return true;
  if (position.x <= (fieldDimensions_.x) && direction.x < 0) return true;
  return false;
}