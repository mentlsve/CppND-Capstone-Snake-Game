#ifndef RENDERER_H
#define RENDERER_H

#include <SDL2/SDL.h>

class Renderer {
 private:
  SDL_Window* window_;
  SDL_Surface* surface_;
  SDL_Renderer* renderer_;

 public:
  Renderer();
  ~Renderer();
  SDL_Window* getWindow();
  SDL_Renderer* getRenderer();
  void show(SDL_Texture* image);
  void updateScreen();
  void clearScreen();
};

#endif